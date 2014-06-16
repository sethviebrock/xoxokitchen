<?php
// info: views_drag_drop_plugin_style_dragdrop_draggable.inc, v1.0 2012/2/6 Sergei Churilo

/**
 * Default style plugin to render drag&drop.
 */
class views_drag_drop_plugin_style_dragdrop_draggable extends views_plugin_style_default {
  // Set default options
  function option_definition() {
    $options = parent::option_definition();
    $options['dragdrop'] = array('default' => array());
    return $options;
  }
  
  /**
   * Render the given style.
   */
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    $vdd_settings = _views_drag_drop_settings();
    $presets = array();
    foreach($vdd_settings as $preset => $preset_conf) {
      $presets[$preset] = $preset_conf['#title'];
    }
    $args = $vdd_settings[$this->options['dragdrop']['preset']]['#drag']['#args'];
    
    $form['dragdrop'] = array(
      '#type' => 'fieldset',
      '#title' => t('Draggable (Drag&Drop)'),
      '#weight' => -15,
      '#tree' => TRUE,
    );
    $form['dragdrop']['preset'] = array(
      '#type' => 'select',
      '#title' => t('Preset'),
      '#options' => $presets,
      '#default_value' => $this->options['dragdrop']['preset'],
      '#weight' => -15,
    );
    
    $form['dragdrop']['args'] = array(
      '#type' => 'fieldset',
      '#title' => t('Arguments'),
      '#tree' => TRUE,
    );
    $field_names = $this->display->handler->get_field_labels();
    $fields = array();
    foreach($field_names as $k => $l) {
      if(substr($k, 0, 4) != 'path') {
        $fields['w|'.$k] = $l.t(' (raw)');
      }
      $fields['r|'.$k] = $l.t(' (rendered)');
    }
    $field_nid = array('d|nid' => 'Nid (default)');
    $field_names =array('0' => '') + $field_nid + $fields;
    
    foreach($args as $label => $field) {
      if($field == 'nid') {
        $form['dragdrop']['args'][$field] = array(
          '#title' => $label,
          '#type' => 'select',
          '#options' => $field_nid,
          '#default_value' => 'd|nid',
        );
      }
      else {
        $form['dragdrop']['args'][$field] = array(
          '#title' => $label,
          '#type' => 'select',
          '#options' => $field_names,
          '#default_value' => $this->options['dragdrop']['args'][$field],
        );
      }
    }
  }
}