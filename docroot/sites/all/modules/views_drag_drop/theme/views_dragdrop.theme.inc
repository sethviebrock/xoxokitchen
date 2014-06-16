<?php
// info: views_dragdrop.theme.inc, v1.0 2012/2/7 Segei Churilo

function _views_drag_drop_preprocess_views_draggable_unformatted(&$vars) {
  _views_drag_drop_preprocess_dragdrop_unformatted_view($vars, 'draggable');
}

function _views_drag_drop_preprocess_views_droppable_unformatted(&$vars) {
  _views_drag_drop_preprocess_dragdrop_unformatted_view($vars, 'droppable');
}

function _views_drag_drop_preprocess_dragdrop_unformatted_view(&$vars, $type) {
  $view = $vars['view'];
  $rows = $vars['rows'];
  $result = $vars['view']->result;
  $style_plugin = $view->style_plugin;

  if(user_access('access_drag_and_drop')) {
    $vdd_settings = _views_drag_drop_settings();
    if(
      isset(
        $style_plugin->options['dragdrop']['preset'],
        $vdd_settings[$style_plugin->options['dragdrop']['preset']],
        $style_plugin->options['dragdrop']['args']
      )
    ) {
      $preset = $style_plugin->options['dragdrop']['preset'];
      $complete_arguments =_views_drag_drop_prepare_arguments(
        $view,
        $preset,
        $style_plugin->options['dragdrop']['args']
      );
    }
  }
  $vars['classes_array'] = array();
  $vars['classes'] = array();
  $vars['classes_wrapper'] = 'item-wrapper item-'.$type.'-wrapper';
  $vars['dd_args'] = array();
  $vars['crc'] = array();

  // Set up striping values.
  $count = 0;
  $max = count($rows);
  foreach ($rows as $id => $row) {
    $count++;
    $vars['dd_args'][$id] = '';
    $vars['crc'][$id] = '';
    $vars['classes'][$id][] = 'views-row';
    $vars['classes'][$id][] = 'views-row-' . $count;
    if ($count == 1) {
      $vars['classes'][$id][] = 'views-row-first';
    }
    if ($count == $max) {
      $vars['classes'][$id][] = 'views-row-last';
    }

    if ($row_class = $view->style_plugin->get_row_class($id)) {
      $vars['classes'][$id][] = $row_class;
    }

    if(user_access('access_drag_and_drop') && !empty($complete_arguments[$id])) {
      // add item-draggable class
      $vars['classes'][$id][] = 'item-'.$type;
      $vars['classes'][$id][] = 'item-'.$type.'-'.$preset;

      $disable_dpoppable = FALSE;
      if($type == 'droppable' && !empty($vdd_settings[$style_plugin->options['dragdrop']['preset']]['#options']['#disable_drop_conditions'])) {
        foreach($vdd_settings[$style_plugin->options['dragdrop']['preset']]['#options']['#disable_drop_conditions'] as $field => $max_count) {
          if(isset($result[$id]->_field_data['nid']['entity'])) {
            $node = $result[$id]->_field_data['nid']['entity'];
            if(isset($node->{$field}[$node->language])) {
              $count_items = count($node->{$field}[$node->language]);
              if($count_items >= $max_count) {
                $disable_dpoppable = TRUE;
                $vars['classes'][$id][] = 'item-'.$type.'-'.$preset.'-disabled';
              }
            }
          }
        }
      }

      if($type == 'droppable') {
        // add special classes
        if(!empty($vdd_settings[$style_plugin->options['dragdrop']['preset']]['#drop']['#classes'])) {
          foreach($vdd_settings[$style_plugin->options['dragdrop']['preset']]['#drop']['#classes'] as $add_class) {
            _views_drag_drop_prepare_class($add_class, $complete_arguments[$id]);
            $vars['classes'][$id][] = $add_class;
          }
        }

        if(!$disable_dpoppable) {
          // add droppable arguments
          $vars['dd_args'][$id] = drupal_json_encode($complete_arguments[$id]);
          // calculate simple hash code
          $vars['crc'][$id] = _views_drag_drop_crc_encode($vars['dd_args'][$id]);
        }
        else {
          $vars['dd_args'][$id] = '{}';
          $vars['crc'][$id] = _views_drag_drop_crc_encode($vars['dd_args'][$id]);
        }
      }
      else {
        // add special classes
        if(!empty($vdd_settings[$style_plugin->options['dragdrop']['preset']]['#drag']['#classes'])) {
          foreach($vdd_settings[$style_plugin->options['dragdrop']['preset']]['#drag']['#classes'] as $add_class) {
            _views_drag_drop_prepare_class($add_class, $complete_arguments[$id]);
            $vars['classes'][$id][] = $add_class;
          }
        }

        // add draggable arguments
        $vars['dd_args'][$id] = drupal_json_encode($complete_arguments[$id]);
        // calculate simple hash code
        $vars['crc'][$id] = _views_drag_drop_crc_encode($vars['dd_args'][$id]);
      }
    }

    // Flatten the classes to a string for each row for the template file.
    $vars['classes_array'][$id] = implode(' ', $vars['classes'][$id]);
  }
}

function _views_drag_drop_prepare_arguments($view, $preset, $args) {
  $fields_info = field_info_fields();
  if(!_views_drag_drop_init_dragdrop($preset)) {
    return FALSE;
  }
  $complete_arguments = array();
  $args_copy = $args;
  foreach($view->result as $k => $v) {
    foreach($args as $d_arg => $v_field) {
      if(!empty($v_field)) {
        $view_field = explode('|', $v_field);
        $v_field = $view_field[1];

        if(strpos($d_arg, ':') !== FALSE) {
           list($fkey1, $fkey2) = explode(':', $d_arg);
           $complete_arguments[$k][$fkey1][$fkey2] = NULL;
           $target_arg = &$complete_arguments[$k][$fkey1][$fkey2];
        }
        else {
          $target_arg = &$complete_arguments[$k][$d_arg];
        }


        // check if required value must be rendered
        if($view_field[0] == 'r') {
          // this part needed to fill rendered fields, such fields as "nothing" - global views field
          if(isset($view->style_plugin->rendered_fields[$k][$v_field])) {
            $target_arg = $view->style_plugin->rendered_fields[$k][$v_field];
            unset($args_copy[$d_arg]);
          }
        }
        // fill in raw values
        else {
          switch($v_field) {
            case 'nid': {
              $target_arg = $v->nid;
              unset($args_copy[$d_arg]);
            } break;
            case 'body': {
              if(isset($v->field_body[0]['raw']['value'])) {
                $target_arg = $v->field_body[0]['raw']['value'];
                unset($args_copy[$d_arg]);
              }
            }
            default: {
              if(substr($v_field, 0, 6) == 'field_') {
                $ftype = _views_drag_drop_field_type($v_field, $fields_info);
                $v_field = 'field_'.$v_field;
                switch($ftype) {
                  // cases to gain raw values of specific fields
                  case 'taxonomy_term_reference' : {
                    if(isset($v->{$v_field}[0]['raw']['tid'])) {
                      $target_arg = $v->{$v_field}[0]['raw']['tid'];
                      unset($args_copy[$d_arg]);
                    }
                  } break;
                  case 'node_reference' : {
                    if(isset($v->{$v_field}[0]['raw']['nid'])) {
                      $target_arg = $v->{$v_field}[0]['raw']['nid'];
                      unset($args_copy[$d_arg]);
                    }
                  } break;
                  case 'user_reference' : {
                    if(isset($v->{$v_field}[0]['raw']['uid'])) {
                      $target_arg = $v->{$v_field}[0]['raw']['uid'];
                      unset($args_copy[$d_arg]);
                    }
                  } break;
                  default : {
                    if(isset($v->{$v_field}[0]['raw']['value'])) {
                      $target_arg = htmlspecialchars($v->{$v_field}[0]['raw']['value']);
                      unset($args_copy[$d_arg]);
                    }
                  }
                }
              }
              // node's standard fields and attributes: node_uid, node_sticky etc.
              elseif(isset($v->{'node_'.$v_field})) {
                $target_arg = htmlspecialchars($v->{'node_'.$v_field});
                unset($args_copy[$d_arg]);
              }
            }
          }
        }

        if(is_null($target_arg)) {
          unset($target_arg);
        }

      }
    }
  }

  return $complete_arguments;
}

