<?php
/**
 * @file
 * xoxo_feat_site_menus.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function xoxo_feat_site_menus_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu:<front>
  $menu_links['main-menu:<front>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Home',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '1',
    'external' => '1',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
  );
  // Exported menu link: main-menu:node/488
  $menu_links['main-menu:node/488'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/488',
    'router_path' => 'node/%',
    'link_title' => 'My kitchen',
    'options' => array(),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
  );
  // Exported menu link: main-menu:node/489
  $menu_links['main-menu:node/489'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/489',
    'router_path' => 'node/%',
    'link_title' => 'Shopping List',
    'options' => array(),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '1',
  );
  // Exported menu link: main-menu:node/490
  $menu_links['main-menu:node/490'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/490',
    'router_path' => 'node/%',
    'link_title' => 'Recipes',
    'options' => array(),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '2',
  );
  // Exported menu link: main-menu:node/491
  $menu_links['main-menu:node/491'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/491',
    'router_path' => 'node/%',
    'link_title' => 'Healthy Eating',
    'options' => array(),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '3',
  );
  // Exported menu link: main-menu:node/492
  $menu_links['main-menu:node/492'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/492',
    'router_path' => 'node/%',
    'link_title' => 'Kids Cooking',
    'options' => array(),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '4',
  );
  // Exported menu link: main-menu:node/493
  $menu_links['main-menu:node/493'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/493',
    'router_path' => 'node/%',
    'link_title' => 'Guest Savings',
    'options' => array(),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '5',
  );
  // Exported menu link: menu-footer-menu:<front>
  $menu_links['menu-footer-menu:<front>'] = array(
    'menu_name' => 'menu-footer-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Site Map',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '1',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
  );
  // Exported menu link: menu-join-for-free:node/497
  $menu_links['menu-join-for-free:node/497'] = array(
    'menu_name' => 'menu-join-for-free',
    'link_path' => 'node/497',
    'router_path' => 'node/%',
    'link_title' => 'Free tour',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '1',
  );
  // Exported menu link: menu-join-for-free:user/register
  $menu_links['menu-join-for-free:user/register'] = array(
    'menu_name' => 'menu-join-for-free',
    'link_path' => 'user/register',
    'router_path' => 'user/register',
    'link_title' => 'Register here',
    'options' => array(
      'attributes' => array(
        'title' => '',
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
  t('Free tour');
  t('Guest Savings');
  t('Healthy Eating');
  t('Home');
  t('Kids Cooking');
  t('My kitchen');
  t('Recipes');
  t('Register here');
  t('Shopping List');
  t('Site Map');


  return $menu_links;
}
