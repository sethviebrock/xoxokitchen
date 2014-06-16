<?php
// info: xoxo_fields.add_to_category.module, v1.0 2012/3/23 Segei Churilo
define('XOXO_FIELDS_ADDCAT_PRESET', 'add_category');
define('XOXO_FIELDS_ADDCAT_MEALTYPE_VID', 11);

function xoxo_fields_flag($action, $flag, $content_id, $account) {
  if (
    $action == 'unflag'
    && (
      $flag->name == 'added_to_my_kitchen'
      || $flag->name == 'added_to_my_staples'
    )
  ) {
    $u = $account->uid;
    $q = db_delete('xoxo_fields_taxonomy')
      ->condition('nid', $content_id)
      ->condition('uid', $u);
    $q->execute();
  }
}

//Hide submitter.
function xoxo_fields_form_alter(&$form, &$form_state, $form_id) {
  if(
    $form['#id'] === 'views-exposed-form-components-for-shopping-list-block-1'
    || $form['#id'] === 'views-exposed-form-recipes-components-block-3'
  ) {
    drupal_add_css(drupal_get_path('module', 'xoxo_fields') . '/css/xoxo_fields.css');
  }
  elseif(isset($form['field_recipe_nutritional'])) {
    unset($form['field_recipe_nutritional']);
  }

  if($form_id == 'recipe_node_form') {
    if(isset($form['field_recipe_status'][LANGUAGE_NONE]['#options']['_none'])) {
      unset($form['field_recipe_status'][LANGUAGE_NONE]['#options']['_none']);
    }
    if(isset($form['field_recipe_status'][LANGUAGE_NONE]['#options'])) {
      krsort($form['field_recipe_status'][LANGUAGE_NONE]['#options']);
    }

    foreach($form['field_recipe_ingredients'][LANGUAGE_NONE] as $delta => $item) {
      if(!is_numeric($delta)) {
        continue;
      }
      $element = &$form['field_recipe_ingredients'][LANGUAGE_NONE][$delta]['nid']['#element_validate'];
      $element = array('_xoxo_fileds_ingredient_reference_validate');
    }
    
    $form['field_recipe_side_dish'][LANGUAGE_NONE][0]['nid']['#maxlength'] = 255;
    $form['field_recipe_side_dish'][LANGUAGE_NONE][1]['nid']['#maxlength'] = 255;
    $form['field_recipe_side_dish'][LANGUAGE_NONE][2]['nid']['#maxlength'] = 255;
  }

  if($form['#form_id'] == 'views_exposed_form') {
    if(isset($form['brand'])) {
      $form['brand']['#autocomplete_path'] = 'xoxo/brand/autocomplete';
    }
    if(isset($form['manufacturer'])) {
      $form['manufacturer']['#autocomplete_path'] = 'xoxo/manufacturer/autocomplete';
    }
    if(isset($form['author_uid']['#default_value'])) {
      array_unshift ($form['#submit'], '_xoxo_fields_validate_uid');
      unset($form['author_uid']);
    }
  }
}

/**
 * Validation callback for a INGREDIENT node_reference autocomplete element.
 */
function _xoxo_fileds_ingredient_reference_validate($element, &$form_state, $form) {
/*  $field = field_widget_field($element, $form_state);
  $instance = field_widget_instance($element, $form_state);

  if(isset($form_state['values']['field_recipe_ingredients'][LANGUAGE_NONE][$element['#delta']]['unit'])) {
    $uom = $form_state['values']['field_recipe_ingredients'][LANGUAGE_NONE][$element['#delta']]['unit'];
  }
  else {
    $uom = FALSE;
  }

  $value = $element['#value'];
  $nid = NULL;

  if (!empty($value)) {
    // Check whether we have an explicit "[nid:n]" input.
    preg_match('/^(?:\s*|(.*) )?\[\s*nid\s*:\s*(\d+)\s*\]$/', $value, $matches);
    if (!empty($matches)) {
      // Explicit nid. Check that the 'title' part matches the actual title for
      // the nid.
      list(, $title, $nid) = $matches;
      if (!empty($title)) {
        $real_title = db_select('node', 'n')
          ->fields('n', array('title'))
          ->condition('n.nid', $nid)
          ->execute()
          ->fetchField();
        if (trim($title) != trim($real_title)) {
          form_error($element, t('%name: title mismatch. Please check your selection.', array('%name' => $instance['label'])));
        }
      }
    }
    else {
      // No explicit nid (the submitted value was not populated by autocomplete
      // selection). Get the nid of a referencable node from the entered title.
      $options = array(
        'string' => $value,
        'match' => 'equals',
        'limit' => 1,
      );

      $references = _xoxo_node_reference_potential_references($field, $options);
      if ($references) {
        $nid = key($references);
      }
      else {
        // autocreate custom component. The author is currently logged in user
        $fields = array('uom' => $uom);
        $nid = _xoxo_fields_create_custom_component($value, $fields);
        if(!$nid) {
          form_error($element, t('%name: can\'t create custom component.', array('%name' => $instance['label'])));
        }
      }
    }
  }

  form_set_value($element, $nid, $form_state);*/
}

function _xoxo_fields_create_custom_component($title, $fields) {
  if(!$title) {
    return FALSE;
  }

  global $user;
  $q = "
    SELECT
      n.nid AS nid
    FROM
      node n
    WHERE
      n.uid = :uid
        AND
      n.type = 'component'
        AND
      n.title = :title";
  $nid = db_query(
    $q,
    array(
      ':title' => check_plain($title),
      ':uid' => $user->uid,
    )
  )->fetchField();

  if($nid) {
    return $nid;
  }

  // create component
  $node = new stdClass();
  $node->type = 'component';
  $node->title = check_plain($title);
  if(isset($fields['uom'])) {
    $node->field_component_uom[LANGUAGE_NONE][0]['tid'] = $fields['uom'];
  }
 //  $node->field_component_status[LANGUAGE_NONE][0]['value'] = 0; // component is not available
  $node->field_component_category[LANGUAGE_NONE][0]['tid'] = 2423; // food category
  $node->field_component_category_2[LANGUAGE_NONE][0]['tid'] = 2653; // not tabacco category
  $node->field_component_category_3[LANGUAGE_NONE][0]['tid'] = 2432; // other category (class)
  $node->field_component_category_4[LANGUAGE_NONE][0]['tid'] = 2432;
  $node->uid = $user->uid;
  $node->status = 0;
  $node->language = LANGUAGE_NONE;
  node_object_prepare($node);
  $node = node_submit($node);
  node_save($node);

  if(!empty($node->nid)) {
    return $node->nid;
  }
}

function _xoxo_fields_validate_uid($form, &$form_state) {
  global $user;
  $form_state['values']['author_uid'] = $user->uid;
}

//Change views fields output to allow "Add To Category" action. And hide component view link from non-admin users. And output component name instead of component ID.
function xoxo_fields_preprocess_views_view_field(&$vars) {
  $v1 = 'recipes_components';
  $v2 = 'components_for_shopping_list';
  $v3 = 'components';
  $v4 = 'kitchen_setup_staples';
  $d1 = 'block_2';
  $d2 = 'block_1';
  $d3 = 'block_3';
  $d4 = 'block';
  $p1 = $p5 = 'shopping_list';
  $p2 = $p3 = $p4 = 'calendar';
  $n1 = 'nothing';
  $n2 = 'ops';
  $n3 = 'view_node';
  $n4 = 'field_component_name_value';
  $n = $vars['field']->real_field;
  $v = $vars['view']->name;
  $d = $vars['view']->current_display;
  if ($v == $v2 && $d == $d2) {
    $p = $p1;
  }
  else if ($v == $v1 && $d == $d3) {
    $p = $p2;
  }
  else if ($v == $v3 && $d == $d3) {
    $p = $p3;
  }
  else if ($v == $v1 && $d == $d1) {
    $p = $p4;
  }
  else if ($v == $v4 && $d == $d4) {
    $p = $p5;
  }
  else {
    $p = FALSE;
  }
  $nid = 0;
  if (array_key_exists('row', $vars)) {
    if (is_object($vars['row'])) {
      $nid = property_exists($vars['row'], 'nid') ? $vars['row']->nid : 0;
    }
  }
  if($p) {
    if($n == $n1 || ($p == $p3 && $n == 'ops')) {
      $s = array();
      $s['content'] = $vars['output'];
      $s['preset'] = $p;
      $s['delta'] = 5;
      $s['args']['preset'] = $p;
      $s['args']['nid'] = $nid;
      $s['event'] = 'click';
      $vars['output'] = theme('views_drag_drop_operations', $s);
    }
  }
  if($p == $p4 || $p == $p3 || ($v === $v3 && $d === $d1)) {
    if($n == $n3 && $GLOBALS['user']->uid != 1) {
      $vars['output'] = '';
    }
  }
  if($n == $n4) {
    if(!empty($vars['output'])) {
      $vars['output'] =  _xoxo_fields_component_name_by_id($vars['output']);
    }
    else{
      $vars['output'] = 'UNKNOWN';
    }
  }
}

function _xoxo_fields_addcat_prepare_actions(&$config, $args) {
  $presets = array(
    'shopping_list' => 20,
    'calendar' => 11
  );
  $a = array(
    'status' => array('callback' => '_xoxo_fields_addcat_status'),
    'custom_trigger_element' => '.views-exposed-widget input',
    'custom_trigger_event' => 'click',
  );
  $uid = $GLOBALS['user']->uid;
  $nid = isset($args['nid']) ? $args['nid'] : 0;
  $tid = _xoxo_fields_tid($nid, $uid);
  foreach($presets as $p => $vid) {
    $v = taxonomy_get_tree($vid);
    foreach($v as $t) {
      $i = $a;
      $i['title'] = $t->name;
      $i['content'] = $t->name;
      $i['delta'] = 5;
      $i['preset'] = $p;
      $i['classes'] = $t->tid == $tid ? 'last-succeded' : '';
      $config['addcat_' . $t->tid] = $i;
    }
  }
/*  $args = (array) $args;
  $v = drupal_array_get_nested_value($args, array('view'));
  $d = drupal_array_get_nested_value($args, array('display'));
  if(!$v) {
    foreach(array_keys($config) as $key) {
      if(strrpos($key, 'addcat_') !== FALSE) {
        unset($config[$key]);
      }
    }
  }
  $nid = isset($args['nid']) ? ($args['nid'] != 'add' ? (int) $args['nid'] : 0) : 0;
  $tid = db_select('xoxo_fields_taxonomy', 't')
    ->fields('t', array('tid'))
    ->condition('t.nid', $nid, '=')
    ->condition('t.uid', $GLOBALS['user']->uid, '=')
    ->execute()
    ->fetchField();
  if(empty($tid)) {
    $node = node_load($nid);
    $i = isset($node->field_recipe_meal_type) ? field_get_items('node', $node, 'field_recipe_meal_type') : FALSE;
    $tid = isset($i[0]['tid']) ? (int) $i[0]['tid'] : 0;
  }
  $vid = (arg(0) == 'shopping-list') || ($v == 'kitchen_setup_staples' && $d == 'block') ? 20 : 11;
  $terms = taxonomy_get_tree($vid);
  $weight = 0;
  $p = FALSE;
  if (arg(0) == 'node') {
    $p = XOXO_FIELDS_ADDCAT_PRESET;
  }
  foreach($terms as $k => $term) {
    $config['addcat_'.$term->tid] = array(
      'title' => $term->name,
      'content' => $term->name,
      'status' => array(
        'callback' => '_xoxo_fields_addcat_status',
      ),
      'custom_trigger_element' => '.views-exposed-widget input',//'#edit-submit-components-for-shopping-list',
      'custom_trigger_event' => 'click',
      'weight' => $weight++,
    );
    // highlight default selection by setting special html class
    if($term->tid == $tid) {
      $config['addcat_'.$term->tid]['classes'] = 'last-succeded';
    }
    if($p) {
      $config['addcat_'.$term->tid]['preset'] = $p;
    }
  }*/
}

function _xoxo_fields_addcat_status($preset, $action, &$args) {
  return TRUE;
}

function _xoxo_fields_addcat_perform_actions($action, &$output, &$new_action, $preset, &$args, &$options) {
  $npreset = $args['preset'];
  $temp = explode('_', $action);
  if(!isset($temp[1], $args['nid']) || $temp[0] != 'addcat') {
    return FALSE;
  }

  $tid = $temp[1];
  $nid = $args['nid'];

  // perform any action on node
  $fields = $key = array(
    'uid' => $GLOBALS['user']->uid,
    'nid' => $nid,
  );
  $fields['tid'] = $tid;
  if (!in_array(FALSE, $fields)) {
    if ($npreset == 'calendar') {
      $f = 'added_to_my_kitchen';
    }
    else if ($npreset == 'shopping_list') {
      _xoxo_component_ks($nid, 1);
      $f = 'added_to_my_staples';
    }
    db_merge('xoxo_fields_taxonomy')->key($key)->fields($fields)->execute();
    flag('flag', $f, $nid);
    $options['custom_trigger_element'] = 'document';
    $options['custom_trigger_event'] = 'flagGlobalBeforeLinkUpdate';
    return TRUE;
  }
  else {
    return FALSE;
  }
}
