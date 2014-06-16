<?php
/**
 * @file
 * xoxo_kitchen.quicktabs.inc
 */

/**
 * Implements hook_quicktabs_default_quicktabs().
 */
function xoxo_kitchen_quicktabs_default_quicktabs() {
  $export = array();

  $quicktabs = new stdClass();
  $quicktabs->disabled = FALSE; /* Edit this to true to make a default quicktabs disabled initially */
  $quicktabs->api_version = 1;
  $quicktabs->machine_name = 'components';
  $quicktabs->ajax = 0;
  $quicktabs->hide_empty_tabs = FALSE;
  $quicktabs->default_tab = 0;
  $quicktabs->title = 'Components';
  $quicktabs->tabs = array(
    0 => array(
      'vid' => 'components',
      'display' => 'block_1',
      'args' => '',
      'title' => 'My Recipes',
      'weight' => '-100',
      'type' => 'view',
    ),
    1 => array(
      'vid' => 'components',
      'display' => 'block_3',
      'args' => '',
      'title' => 'Prepared Meals',
      'weight' => '-99',
      'type' => 'view',
    ),
    2 => array(
      'vid' => 'components',
      'display' => 'block_4',
      'args' => '',
      'title' => 'Add Recipe',
      'weight' => '-98',
      'type' => 'view',
    ),
  );
  $quicktabs->renderer = 'quicktabs';
  $quicktabs->style = 'nostyle';
  $quicktabs->options = array();

  // Translatables
  // Included for use with string extractors like potx.
  t('Add Recipe');
  t('Components');
  t('My Recipes');
  t('Prepared Meals');

  $export['components'] = $quicktabs;

  $quicktabs = new stdClass();
  $quicktabs->disabled = FALSE; /* Edit this to true to make a default quicktabs disabled initially */
  $quicktabs->api_version = 1;
  $quicktabs->machine_name = 'kitchen_setup';
  $quicktabs->ajax = 0;
  $quicktabs->hide_empty_tabs = FALSE;
  $quicktabs->default_tab = 0;
  $quicktabs->title = 'Kitchen Setup';
  $quicktabs->tabs = array(
    0 => array(
      'vid' => 'recipes_components',
      'display' => 'block_1',
      'args' => '',
      'title' => 'My Recipes',
      'weight' => '-100',
      'type' => 'view',
    ),
    1 => array(
      'vid' => 'recipes_components',
      'display' => 'block_2',
      'args' => '',
      'title' => 'Prepared Meals',
      'weight' => '-99',
      'type' => 'view',
    ),
    2 => array(
      'vid' => 'kitchen_setup_staples',
      'display' => 'block',
      'args' => '',
      'title' => 'Staples',
      'weight' => '-98',
      'type' => 'view',
    ),
  );
  $quicktabs->renderer = 'quicktabs';
  $quicktabs->style = 'nostyle';
  $quicktabs->options = array();

  // Translatables
  // Included for use with string extractors like potx.
  t('Kitchen Setup');
  t('My Recipes');
  t('Prepared Meals');
  t('Staples');

  $export['kitchen_setup'] = $quicktabs;

  return $export;
}
