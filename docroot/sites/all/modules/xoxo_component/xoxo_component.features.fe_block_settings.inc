<?php
/**
 * @file
 * xoxo_component.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function xoxo_component_default_fe_block_settings() {
  $export = array();

  // seven
  $theme = array();

  $theme['xoxo_components-products'] = array(
    'module' => 'xoxo_components',
    'delta' => 'products',
    'theme' => 'seven',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => 'node/*/edit',
    'title' => '',
    'cache' => '1',
  );

  $export['seven'] = $theme;

  // xoxo
  $theme = array();

  $theme['xoxo_components-products'] = array(
    'module' => 'xoxo_components',
    'delta' => 'products',
    'theme' => 'xoxo',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => 'node/*/edit',
    'title' => '',
    'cache' => '1',
  );

  $export['xoxo'] = $theme;

  // xoxo2
  $theme = array();

  $theme['xoxo_components-products'] = array(
    'module' => 'xoxo_components',
    'delta' => 'products',
    'theme' => 'xoxo2',
    'status' => '1',
    'weight' => '-26',
    'region' => 'sidebar_second',
    'custom' => '0',
    'visibility' => '0',
    'pages' => 'node/*/edit',
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
