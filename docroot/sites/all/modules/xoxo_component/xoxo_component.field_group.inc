<?php
/**
 * @file
 * xoxo_component.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function xoxo_component_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_component_actions|node|component|in_brand_page';
  $field_group->group_name = 'group_component_actions';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'component';
  $field_group->mode = 'in_brand_page';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => '@title',
    'weight' => '1',
    'children' => array(
      0 => 'sl',
      1 => 'cal',
      2 => 'fav',
      3 => 'nutr',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => '@title',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_component_actions|node|component|in_brand_page'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_component_group_pm|node|component|form';
  $field_group->group_name = 'group_component_group_pm';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'component';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Prepared Meal',
    'weight' => '2',
    'children' => array(
      0 => 'field_component_status',
      1 => 'field_componets_meal_type',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_component_group_pm|node|component|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_component_group_staple|node|component|form';
  $field_group->group_name = 'group_component_group_staple';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'component';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Staple',
    'weight' => '1',
    'children' => array(
      0 => 'field_component_ks',
      1 => 'field_component_sc',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_component_group_staple|node|component|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_component_settings|node|component|form';
  $field_group->group_name = 'group_component_settings';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'component';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Settings',
    'weight' => '25',
    'children' => array(
      0 => 'field_component_status',
      1 => 'field_componets_meal_type',
      2 => 'field_component_ks',
      3 => 'field_component_sc',
      4 => 'flag',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_component_settings|node|component|form'] = $field_group;

  return $export;
}
