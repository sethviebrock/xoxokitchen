<?php
/**
 * @file
 * xoxo_main_menu_sidebar.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function xoxo_main_menu_sidebar_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-left-userbar-menu:<front>
  $menu_links['menu-left-userbar-menu:<front>'] = array(
    'menu_name' => 'menu-left-userbar-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Messages',
    'options' => array(
      'attributes' => array(
        'title' => '',
        'class' => array(
          0 => 'menu_icon',
          1 => 'menu-984',
          2 => 'menu-985',
        ),
      ),
      'menu_icon' => array(
        'enable' => 1,
        'path' => 'sites/all/themes/xoxo2/images/menu/messages_icon.png',
        'image_style' => 'menu_icon',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '1',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '1',
  );
  // Exported menu link: menu-left-userbar-menu:kitchen-setup
  $menu_links['menu-left-userbar-menu:kitchen-setup'] = array(
    'menu_name' => 'menu-left-userbar-menu',
    'link_path' => 'kitchen-setup',
    'router_path' => 'kitchen-setup',
    'link_title' => 'Kitchen Setup',
    'options' => array(
      'attributes' => array(
        'title' => '',
        'class' => array(
          0 => 'menu_icon',
          1 => 'menu-983',
        ),
      ),
      'menu_icon' => array(
        'enable' => 1,
        'path' => 'sites/all/themes/xoxo2/images/menu/kitchen_setup_icon.png',
        'image_style' => 'menu_icon',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Kitchen Setup');
  t('Messages');


  return $menu_links;
}
