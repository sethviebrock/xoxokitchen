<?php
/**
 * @file
 * xoxo_kitchen.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function xoxo_kitchen_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "quicktabs" && $api == "quicktabs") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function xoxo_kitchen_views_api() {
  list($module, $api) = func_get_args();
  if ($module == "views" && $api == "views_default") {
    return array("version" => "3.0");
  }
}

/**
 * Implements hook_flag_default_flags().
 */
function xoxo_kitchen_flag_default_flags() {
  $flags = array();
  // Exported flag: "Added To My Kitchen".
  $flags['added_to_my_kitchen'] = array(
    'content_type' => 'node',
    'title' => 'Added To My Kitchen',
    'global' => '0',
    'types' => array(
      0 => 'brand',
      1 => 'component',
      2 => 'recipe',
    ),
    'flag_short' => 'Add',
    'flag_long' => '',
    'flag_message' => '',
    'unflag_short' => 'Remove',
    'unflag_long' => '',
    'unflag_message' => '',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'roles' => array(
      'flag' => array(
        0 => '2',
      ),
      'unflag' => array(
        0 => '2',
      ),
    ),
    'show_on_page' => 0,
    'show_on_teaser' => 0,
    'show_on_form' => 0,
    'access_author' => '',
    'i18n' => 0,
    'module' => 'xoxo_kitchen',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 2,
  );
  // Exported flag: "Favorite".
  $flags['favorite'] = array(
    'content_type' => 'node',
    'title' => 'Favorite',
    'global' => '0',
    'types' => array(
      0 => 'component',
      1 => 'recipe',
    ),
    'flag_short' => 'Add to Favorites',
    'flag_long' => '',
    'flag_message' => '',
    'unflag_short' => 'Remove from Favorites',
    'unflag_long' => '',
    'unflag_message' => '',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'roles' => array(
      'flag' => array(
        0 => '2',
        1 => '3',
        2 => '5',
        3 => '6',
      ),
      'unflag' => array(
        0 => '2',
        1 => '3',
        2 => '5',
        3 => '6',
      ),
    ),
    'show_on_page' => 0,
    'show_on_teaser' => 0,
    'show_on_form' => 0,
    'access_author' => '',
    'i18n' => 0,
    'module' => 'xoxo_kitchen',
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
function xoxo_kitchen_node_info() {
  $items = array(
    'day_description' => array(
      'name' => t('Day Description'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
