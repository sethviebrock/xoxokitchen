<?php
/**
 * @file
 * xoxo_brand.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function xoxo_brand_default_fe_block_settings() {
  $export = array();

  // seven
  $theme = array();

  $theme['xoxo_brands-xoxo_favorite_brands'] = array(
    'module' => 'xoxo_brands',
    'delta' => 'xoxo_favorite_brands',
    'theme' => 'seven',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '1',
  );

  $theme['xoxo_brands-xoxo_index'] = array(
    'module' => 'xoxo_brands',
    'delta' => 'xoxo_index',
    'theme' => 'seven',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '1',
  );

  $export['seven'] = $theme;

  // xoxo
  $theme = array();

  $theme['xoxo_brands-xoxo_favorite_brands'] = array(
    'module' => 'xoxo_brands',
    'delta' => 'xoxo_favorite_brands',
    'theme' => 'xoxo',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '1',
  );

  $theme['xoxo_brands-xoxo_index'] = array(
    'module' => 'xoxo_brands',
    'delta' => 'xoxo_index',
    'theme' => 'xoxo',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '1',
  );

  $export['xoxo'] = $theme;

  // xoxo2
  $theme = array();

  $theme['xoxo_brands-xoxo_favorite_brands'] = array(
    'module' => 'xoxo_brands',
    'delta' => 'xoxo_favorite_brands',
    'theme' => 'xoxo2',
    'status' => '1',
    'weight' => '-27',
    'region' => 'user_first',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '1',
  );

  $theme['xoxo_brands-xoxo_index'] = array(
    'module' => 'xoxo_brands',
    'delta' => 'xoxo_index',
    'theme' => 'xoxo2',
    'status' => '1',
    'weight' => '0',
    'region' => 'menu',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '1',
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
