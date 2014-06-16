<?php
/**
 * @file
 * xoxo_brand.features.inc
 */

/**
 * Implements hook_views_api().
 */
function xoxo_brand_views_api() {
  list($module, $api) = func_get_args();
  if ($module == "views" && $api == "views_default") {
    return array("version" => "3.0");
  }
}

/**
 * Implements hook_flag_default_flags().
 */
function xoxo_brand_flag_default_flags() {
  $flags = array();
  // Exported flag: "Used on a Brand Page".
  $flags['brand_page'] = array(
    'content_type' => 'node',
    'title' => 'Used on a Brand Page',
    'global' => '1',
    'types' => array(
      0 => 'component',
    ),
    'flag_short' => 'Used on a Brand Page',
    'flag_long' => '',
    'flag_message' => '',
    'unflag_short' => 'Don\'t Use on a Brand Page',
    'unflag_long' => '',
    'unflag_message' => '',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'roles' => array(
      'flag' => array(
        0 => '3',
        1 => '6',
      ),
      'unflag' => array(
        0 => '3',
        1 => '6',
      ),
    ),
    'show_on_page' => 0,
    'show_on_teaser' => 0,
    'show_on_form' => 1,
    'access_author' => '',
    'i18n' => 0,
    'module' => 'xoxo_brand',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 2,
  );
  return $flags;
}

/**
 * Implements hook_node_info().
 */
function xoxo_brand_node_info() {
  $items = array(
    'brand' => array(
      'name' => t('Brand'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
