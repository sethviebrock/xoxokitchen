<?php
/**
 * @file
 * xoxo_component.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function xoxo_component_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function xoxo_component_node_info() {
  $items = array(
    'component' => array(
      'name' => t('Component'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
