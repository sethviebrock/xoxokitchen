<?php
/**
 * @file
 * xoxo_recipe.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function xoxo_recipe_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_recipe_actions|node|recipe|on_fridge';
  $field_group->group_name = 'group_recipe_actions';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'recipe';
  $field_group->mode = 'on_fridge';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Actions',
    'weight' => '5',
    'children' => array(
      0 => 'view',
      1 => 'favorite',
      2 => 'fridge',
      3 => 'calendar',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Actions',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_recipe_actions|node|recipe|on_fridge'] = $field_group;

  return $export;
}
