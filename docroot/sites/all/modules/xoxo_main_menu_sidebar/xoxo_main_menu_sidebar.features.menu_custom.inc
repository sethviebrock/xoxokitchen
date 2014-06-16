<?php
/**
 * @file
 * xoxo_main_menu_sidebar.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function xoxo_main_menu_sidebar_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-left-userbar-menu
  $menus['menu-left-userbar-menu'] = array(
    'menu_name' => 'menu-left-userbar-menu',
    'title' => 'Left Userbar Menu',
    'description' => '',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Left Userbar Menu');


  return $menus;
}
