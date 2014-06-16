<?php
/**
 * @file
 * xoxo_recipe.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function xoxo_recipe_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_flag_default_flags().
 */
function xoxo_recipe_flag_default_flags() {
  $flags = array();
  // Exported flag: "Fridge".
  $flags['fridge'] = array(
    'content_type' => 'node',
    'title' => 'Fridge',
    'global' => '0',
    'types' => array(
      0 => 'recipe',
    ),
    'flag_short' => 'Add to Fridge/Feed',
    'flag_long' => '',
    'flag_message' => '',
    'unflag_short' => 'Remove from Fridge/Feed',
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
    'show_on_form' => 1,
    'access_author' => '',
    'i18n' => 0,
    'module' => 'xoxo_recipe',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 2,
  );
  return $flags;
}

/**
 * Implements hook_image_default_styles().
 */
function xoxo_recipe_image_default_styles() {
  $styles = array();

  // Exported image style: fridge_recipe_image
  $styles['fridge_recipe_image'] = array(
    'name' => 'fridge_recipe_image',
    'effects' => array(),
  );

  // Exported image style: tiny_photo
  $styles['tiny_photo'] = array(
    'name' => 'tiny_photo',
    'effects' => array(),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function xoxo_recipe_node_info() {
  $items = array(
    'recipe' => array(
      'name' => t('Recipe'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title:'),
      'help' => '',
    ),
  );
  return $items;
}
