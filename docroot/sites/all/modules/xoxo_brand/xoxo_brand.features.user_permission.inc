<?php
/**
 * @file
 * xoxo_brand.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function xoxo_brand_user_default_permissions() {
  $permissions = array();

  // Exported permission: create brand content
  $permissions['create brand content'] = array(
    'name' => 'create brand content',
    'roles' => array(),
  );

  // Exported permission: delete any brand content
  $permissions['delete any brand content'] = array(
    'name' => 'delete any brand content',
    'roles' => array(),
  );

  // Exported permission: delete own brand content
  $permissions['delete own brand content'] = array(
    'name' => 'delete own brand content',
    'roles' => array(),
  );

  // Exported permission: edit any brand content
  $permissions['edit any brand content'] = array(
    'name' => 'edit any brand content',
    'roles' => array(),
  );

  // Exported permission: edit own brand content
  $permissions['edit own brand content'] = array(
    'name' => 'edit own brand content',
    'roles' => array(),
  );

  // Exported permission: node_brand_create_page
  $permissions['node_brand_create_page'] = array(
    'name' => 'node_brand_create_page',
    'roles' => array(),
  );

  // Exported permission: node_brand_delete_own_page
  $permissions['node_brand_delete_own_page'] = array(
    'name' => 'node_brand_delete_own_page',
    'roles' => array(),
  );

  // Exported permission: node_brand_delete_page
  $permissions['node_brand_delete_page'] = array(
    'name' => 'node_brand_delete_page',
    'roles' => array(),
  );

  // Exported permission: node_brand_edit_own_page
  $permissions['node_brand_edit_own_page'] = array(
    'name' => 'node_brand_edit_own_page',
    'roles' => array(),
  );

  // Exported permission: node_brand_edit_page
  $permissions['node_brand_edit_page'] = array(
    'name' => 'node_brand_edit_page',
    'roles' => array(),
  );

  // Exported permission: node_brand_view_own_page
  $permissions['node_brand_view_own_page'] = array(
    'name' => 'node_brand_view_own_page',
    'roles' => array(),
  );

  // Exported permission: node_brand_view_page
  $permissions['node_brand_view_page'] = array(
    'name' => 'node_brand_view_page',
    'roles' => array(
      0 => 'anonymous user',
      1 => 'authenticated user',
    ),
    'module' => 'xoxo_access',
  );

  return $permissions;
}
