<?php
/**
 * @file
 * xoxo_main_menu_sidebar.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function xoxo_main_menu_sidebar_default_fe_block_settings() {
  $export = array();

  // seven
  $theme = array();

  $theme['menu-menu-left-userbar-menu'] = array(
    'module' => 'menu',
    'delta' => 'menu-left-userbar-menu',
    'theme' => 'seven',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '<none>',
    'cache' => -1,
  );

  $export['seven'] = $theme;

  // xoxo
  $theme = array();

  $theme['menu-menu-left-userbar-menu'] = array(
    'module' => 'menu',
    'delta' => 'menu-left-userbar-menu',
    'theme' => 'xoxo',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '<none>',
    'cache' => -1,
  );

  $export['xoxo'] = $theme;

  // xoxo2
  $theme = array();

  $theme['menu-menu-left-userbar-menu'] = array(
    'module' => 'menu',
    'delta' => 'menu-left-userbar-menu',
    'theme' => 'xoxo2',
    'status' => '1',
    'weight' => '-29',
    'region' => 'user_first',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '<none>',
    'cache' => -1,
  );

  $export['xoxo2'] = $theme;

  $theme_default = variable_get('theme_default', 'garland');
  $themes = list_themes();
  foreach ($export as $theme_key => $settings) {
    if ($theme_key != $theme_default && empty($themes[$theme_key]->status)) {
      unset($export[$theme_key]);
    }
  }
  return $export;
}
