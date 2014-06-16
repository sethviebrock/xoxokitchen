<?php
/**
 * @file
 * xoxo_kitchen.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function xoxo_kitchen_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_user_profile|user|user|form';
  $field_group->group_name = 'group_user_profile';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Step 1: Create Your Profile',
    'weight' => '0',
    'children' => array(
      0 => 'field_user_name',
      1 => 'field_user_zip',
      2 => 'mail',
      3 => 'password',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Step 1: Create Your Profile',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '(Required)',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_user_profile|user|user|form'] = $field_group;

  return $export;
}
