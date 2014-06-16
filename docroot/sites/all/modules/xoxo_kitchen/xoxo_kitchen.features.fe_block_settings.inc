<?php
/**
 * @file
 * xoxo_kitchen.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function xoxo_kitchen_default_fe_block_settings() {
  $export = array();

  // seven
  $theme = array();

  $theme['quicktabs-components'] = array(
    'module' => 'quicktabs',
    'delta' => 'components',
    'theme' => 'seven',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'kitchen
kitchen/*
kitchen-dev',
    'title' => '<none>',
    'cache' => '1',
  );

  $theme['quicktabs-kitchen_setup'] = array(
    'module' => 'quicktabs',
    'delta' => 'kitchen_setup',
    'theme' => 'seven',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'kitchen-setup',
    'title' => '<none>',
    'cache' => '1',
  );

  $theme['views-components-block'] = array(
    'module' => 'views',
    'delta' => 'components-block',
    'theme' => 'seven',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'kitchen
calendar',
    'title' => '',
    'cache' => -1,
  );

  $theme['views-components-block_1'] = array(
    'module' => 'views',
    'delta' => 'components-block_1',
    'theme' => 'seven',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => -1,
  );

  $theme['views-components-block_2'] = array(
    'module' => 'views',
    'delta' => 'components-block_2',
    'theme' => 'seven',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => -1,
  );

  $theme['views-components-block_3'] = array(
    'module' => 'views',
    'delta' => 'components-block_3',
    'theme' => 'seven',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => -1,
  );

  $theme['views-components-block_4'] = array(
    'module' => 'views',
    'delta' => 'components-block_4',
    'theme' => 'seven',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => -1,
  );

  $theme['views-kitchen_setup_staples-block'] = array(
    'module' => 'views',
    'delta' => 'kitchen_setup_staples-block',
    'theme' => 'seven',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => -1,
  );

  $theme['xoxo_pages-kitchen_link'] = array(
    'module' => 'xoxo_pages',
    'delta' => 'kitchen_link',
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

  $theme['quicktabs-components'] = array(
    'module' => 'quicktabs',
    'delta' => 'components',
    'theme' => 'xoxo',
    'status' => '1',
    'weight' => '-23',
    'region' => 'content',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'kitchen
kitchen/*
kitchen-dev',
    'title' => '<none>',
    'cache' => '1',
  );

  $theme['quicktabs-kitchen_setup'] = array(
    'module' => 'quicktabs',
    'delta' => 'kitchen_setup',
    'theme' => 'xoxo',
    'status' => '1',
    'weight' => '-27',
    'region' => 'content',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'kitchen-setup',
    'title' => '<none>',
    'cache' => '1',
  );

  $theme['views-components-block'] = array(
    'module' => 'views',
    'delta' => 'components-block',
    'theme' => 'xoxo',
    'status' => 0,
    'weight' => '-3',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'kitchen
calendar',
    'title' => '',
    'cache' => -1,
  );

  $theme['views-components-block_1'] = array(
    'module' => 'views',
    'delta' => 'components-block_1',
    'theme' => 'xoxo',
    'status' => 0,
    'weight' => '-11',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => -1,
  );

  $theme['views-components-block_2'] = array(
    'module' => 'views',
    'delta' => 'components-block_2',
    'theme' => 'xoxo',
    'status' => 0,
    'weight' => '-1',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => -1,
  );

  $theme['views-components-block_3'] = array(
    'module' => 'views',
    'delta' => 'components-block_3',
    'theme' => 'xoxo',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => -1,
  );

  $theme['views-components-block_4'] = array(
    'module' => 'views',
    'delta' => 'components-block_4',
    'theme' => 'xoxo',
    'status' => 0,
    'weight' => '-2',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => -1,
  );

  $theme['views-kitchen_setup_staples-block'] = array(
    'module' => 'views',
    'delta' => 'kitchen_setup_staples-block',
    'theme' => 'xoxo',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => -1,
  );

  $theme['xoxo_pages-kitchen_link'] = array(
    'module' => 'xoxo_pages',
    'delta' => 'kitchen_link',
    'theme' => 'xoxo',
    'status' => '1',
    'weight' => '-24',
    'region' => 'content',
    'custom' => '0',
    'visibility' => '0',
    'pages' => 'node/*/edit',
    'title' => '',
    'cache' => '1',
  );

  $export['xoxo'] = $theme;

  // xoxo2
  $theme = array();

  $theme['quicktabs-components'] = array(
    'module' => 'quicktabs',
    'delta' => 'components',
    'theme' => 'xoxo2',
    'status' => '1',
    'weight' => '-25',
    'region' => 'content',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'kitchen
kitchen/*
kitchen-dev',
    'title' => '<none>',
    'cache' => '1',
  );

  $theme['quicktabs-kitchen_setup'] = array(
    'module' => 'quicktabs',
    'delta' => 'kitchen_setup',
    'theme' => 'xoxo2',
    'status' => '1',
    'weight' => '-29',
    'region' => 'content',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'kitchen-setup',
    'title' => '<none>',
    'cache' => '1',
  );

  $theme['views-components-block'] = array(
    'module' => 'views',
    'delta' => 'components-block',
    'theme' => 'xoxo2',
    'status' => 0,
    'weight' => '-4',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'kitchen
calendar',
    'title' => '',
    'cache' => -1,
  );

  $theme['views-components-block_1'] = array(
    'module' => 'views',
    'delta' => 'components-block_1',
    'theme' => 'xoxo2',
    'status' => 0,
    'weight' => '-14',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => -1,
  );

  $theme['views-components-block_2'] = array(
    'module' => 'views',
    'delta' => 'components-block_2',
    'theme' => 'xoxo2',
    'status' => 0,
    'weight' => '-1',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => -1,
  );

  $theme['views-components-block_3'] = array(
    'module' => 'views',
    'delta' => 'components-block_3',
    'theme' => 'xoxo2',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => -1,
  );

  $theme['views-components-block_4'] = array(
    'module' => 'views',
    'delta' => 'components-block_4',
    'theme' => 'xoxo2',
    'status' => 0,
    'weight' => '-2',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => -1,
  );

  $theme['views-kitchen_setup_staples-block'] = array(
    'module' => 'views',
    'delta' => 'kitchen_setup_staples-block',
    'theme' => 'xoxo2',
    'status' => 0,
    'weight' => '-10',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => -1,
  );

  $theme['xoxo_pages-kitchen_link'] = array(
    'module' => 'xoxo_pages',
    'delta' => 'kitchen_link',
    'theme' => 'xoxo2',
    'status' => '1',
    'weight' => '-20',
    'region' => 'content',
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
