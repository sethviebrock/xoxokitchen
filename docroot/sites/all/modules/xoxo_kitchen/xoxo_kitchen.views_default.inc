<?php
/**
 * @file
 * xoxo_kitchen.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function xoxo_kitchen_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'calendar';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Calendar';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Kitchen';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'kitchen_page';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '28';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'week';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_event_date' => 'field_event_date',
    'title' => 'title',
    'field_event_recipes' => 'field_event_recipes',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_event_date' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_event_recipes' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  $handler->display->display_options['style_options']['empty_table'] = 1;
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_event_date']['id'] = 'field_event_date';
  $handler->display->display_options['fields']['field_event_date']['table'] = 'field_data_field_event_date';
  $handler->display->display_options['fields']['field_event_date']['field'] = 'field_event_date';
  $handler->display->display_options['fields']['field_event_date']['label'] = '';
  $handler->display->display_options['fields']['field_event_date']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_event_date']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_event_date']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_event_date']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_event_date']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_event_date']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_event_date']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_event_date']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_event_date']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_event_date']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_event_date']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_event_date']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_event_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_event_date']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_event_date']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_event_date']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_event_date']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_event_date']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  $handler->display->display_options['fields']['field_event_date']['field_api_classes'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Content: Recipes */
  $handler->display->display_options['fields']['field_event_recipes']['id'] = 'field_event_recipes';
  $handler->display->display_options['fields']['field_event_recipes']['table'] = 'field_data_field_event_recipes';
  $handler->display->display_options['fields']['field_event_recipes']['field'] = 'field_event_recipes';
  $handler->display->display_options['fields']['field_event_recipes']['label'] = '';
  $handler->display->display_options['fields']['field_event_recipes']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_event_recipes']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_event_recipes']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_event_recipes']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_event_recipes']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_event_recipes']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_event_recipes']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_event_recipes']['alter']['max_length'] = '15';
  $handler->display->display_options['fields']['field_event_recipes']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['field_event_recipes']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_event_recipes']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_event_recipes']['alter']['trim'] = 1;
  $handler->display->display_options['fields']['field_event_recipes']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_event_recipes']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_event_recipes']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_event_recipes']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_event_recipes']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_event_recipes']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_event_recipes']['type'] = 'node_reference_plain';
  $handler->display->display_options['fields']['field_event_recipes']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_event_recipes']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_event_recipes']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_event_recipes']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['field_event_recipes']['multi_type'] = 'ol';
  $handler->display->display_options['fields']['field_event_recipes']['field_api_classes'] = 0;
  /* Contextual filter: Content: Date (field_event_date) */
  $handler->display->display_options['arguments']['field_event_date_value']['id'] = 'field_event_date_value';
  $handler->display->display_options['arguments']['field_event_date_value']['table'] = 'field_data_field_event_date';
  $handler->display->display_options['arguments']['field_event_date_value']['field'] = 'field_event_date_value';
  $handler->display->display_options['arguments']['field_event_date_value']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_event_date_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_event_date_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_event_date_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_event_date_value']['granularity'] = 'day';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'event' => 'event',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'kitchen';
  $export['calendar'] = $view;

  $view = new view;
  $view->name = 'components';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Components';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Components for shopping list';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    5 => '5',
    6 => '6',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '100';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['style_plugin'] = 'draggable';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'type',
      'rendered' => 0,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['dragdrop'] = array(
    'preset' => 'calendar',
    'args' => array(
      'field_event_recipes' => 'w|nid',
      '@recipe_title' => 'r|title',
      '@qty' => 'w|field_component_size',
      '@uom' => 'w|field_component_uom',
      '@type' => 'w|type',
      '@new' => 'r|status',
      '@date2' => '0',
    ),
  );
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Flags: added_to_my_kitchen */
  $handler->display->display_options['relationships']['flag_content_rel']['id'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['flag_content_rel']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['flag'] = 'added_to_my_kitchen';
  /* Relationship: Content: Meal type (field_componets_meal_type) */
  $handler->display->display_options['relationships']['field_componets_meal_type_tid']['id'] = 'field_componets_meal_type_tid';
  $handler->display->display_options['relationships']['field_componets_meal_type_tid']['table'] = 'field_data_field_componets_meal_type';
  $handler->display->display_options['relationships']['field_componets_meal_type_tid']['field'] = 'field_componets_meal_type_tid';
  $handler->display->display_options['relationships']['field_componets_meal_type_tid']['required'] = 0;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nid']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['nid']['link_to_node'] = 0;
  /* Field: Content: Name */
  $handler->display->display_options['fields']['field_component_name']['id'] = 'field_component_name';
  $handler->display->display_options['fields']['field_component_name']['table'] = 'field_data_field_component_name';
  $handler->display->display_options['fields']['field_component_name']['field'] = 'field_component_name';
  $handler->display->display_options['fields']['field_component_name']['label'] = '';
  $handler->display->display_options['fields']['field_component_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_component_name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_component_name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_component_name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_component_name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_component_name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_component_name']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_component_name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_component_name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_component_name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_component_name']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_component_name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_component_name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_component_name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_component_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_component_name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_component_name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_component_name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_component_name']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_component_name']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 0,
  );
  $handler->display->display_options['fields']['field_component_name']['field_api_classes'] = 0;
  /* Field: Content: UOM */
  $handler->display->display_options['fields']['field_component_uom']['id'] = 'field_component_uom';
  $handler->display->display_options['fields']['field_component_uom']['table'] = 'field_data_field_component_uom';
  $handler->display->display_options['fields']['field_component_uom']['field'] = 'field_component_uom';
  $handler->display->display_options['fields']['field_component_uom']['label'] = '';
  $handler->display->display_options['fields']['field_component_uom']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_component_uom']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_component_uom']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_component_uom']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_component_uom']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_component_uom']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_component_uom']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_component_uom']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_component_uom']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_component_uom']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_component_uom']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_component_uom']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_component_uom']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_component_uom']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_component_uom']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_component_uom']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_component_uom']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_component_uom']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_component_uom']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_component_uom']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_component_uom']['field_api_classes'] = 0;
  /* Field: Content: Size */
  $handler->display->display_options['fields']['field_component_size']['id'] = 'field_component_size';
  $handler->display->display_options['fields']['field_component_size']['table'] = 'field_data_field_component_size';
  $handler->display->display_options['fields']['field_component_size']['field'] = 'field_component_size';
  $handler->display->display_options['fields']['field_component_size']['label'] = '';
  $handler->display->display_options['fields']['field_component_size']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_component_size']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_component_size']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_component_size']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_component_size']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_component_size']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_component_size']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_component_size']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_component_size']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_component_size']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_component_size']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_component_size']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_component_size']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_component_size']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_component_size']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_component_size']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_component_size']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_component_size']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_component_size']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_component_size']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 0,
  );
  $handler->display->display_options['fields']['field_component_size']['field_api_classes'] = 0;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['type']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['type']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['type']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['type']['alter']['external'] = 0;
  $handler->display->display_options['fields']['type']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['type']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['type']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['type']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['type']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['type']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['type']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['type']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['type']['alter']['html'] = 0;
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['type']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['type']['hide_empty'] = 0;
  $handler->display->display_options['fields']['type']['empty_zero'] = 0;
  $handler->display->display_options['fields']['type']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['type']['link_to_node'] = 0;
  $handler->display->display_options['fields']['type']['machine_name'] = 0;
  /* Field: Content: Published */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'node';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['exclude'] = TRUE;
  $handler->display->display_options['fields']['status']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['status']['alter']['text'] = '1';
  $handler->display->display_options['fields']['status']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['status']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['status']['alter']['external'] = 0;
  $handler->display->display_options['fields']['status']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['status']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['status']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['status']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['status']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['status']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['status']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['status']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['status']['alter']['html'] = 0;
  $handler->display->display_options['fields']['status']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['status']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['status']['hide_empty'] = 0;
  $handler->display->display_options['fields']['status']['empty_zero'] = 0;
  $handler->display->display_options['fields']['status']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['status']['type'] = 'true-false';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['view_node']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['view_node']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['html'] = 0;
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_node']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['view_node']['hide_empty'] = 0;
  $handler->display->display_options['fields']['view_node']['empty_zero'] = 0;
  $handler->display->display_options['fields']['view_node']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['view_node']['text'] = 'View';
  /* Field: Flags: Flag link */
  $handler->display->display_options['fields']['ops']['id'] = 'ops';
  $handler->display->display_options['fields']['ops']['table'] = 'flag_content';
  $handler->display->display_options['fields']['ops']['field'] = 'ops';
  $handler->display->display_options['fields']['ops']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['fields']['ops']['label'] = '';
  $handler->display->display_options['fields']['ops']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['ops']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['ops']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['ops']['alter']['external'] = 0;
  $handler->display->display_options['fields']['ops']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['ops']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['ops']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['ops']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['ops']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['ops']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['ops']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['ops']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['ops']['alter']['html'] = 0;
  $handler->display->display_options['fields']['ops']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['ops']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['ops']['hide_empty'] = 0;
  $handler->display->display_options['fields']['ops']['empty_zero'] = 0;
  $handler->display->display_options['fields']['ops']['hide_alter_empty'] = 1;
  /* Sort criterion: Taxonomy term: Weight */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  $handler->display->display_options['sorts']['weight']['relationship'] = 'field_componets_meal_type_tid';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'OR',
  );
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'component' => 'component',
    'recipe' => 'recipe',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Components for calendar';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '40';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'draggable';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'type',
      'rendered' => 0,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['dragdrop'] = array(
    'preset' => 'calendar',
    'args' => array(
      'field_event_recipes' => 'w|nid',
      '@recipe_title' => 'w|title',
      '@qty' => 'w|field_component_size',
      '@uom' => 'w|field_component_uom',
      '@type' => 'w|type',
      '@new' => 'r|status',
      '@date2' => '0',
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Name (field_component_name) */
  $handler->display->display_options['sorts']['field_component_name_value']['id'] = 'field_component_name_value';
  $handler->display->display_options['sorts']['field_component_name_value']['table'] = 'field_data_field_component_name';
  $handler->display->display_options['sorts']['field_component_name_value']['field'] = 'field_component_name_value';

  /* Display: Recipes */
  $handler = $view->new_display('block', 'Recipes', 'block_1');
  $handler->display->display_options['display_description'] = 'Selected recipes.';
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = 0;
  $handler->display->display_options['exposed_form']['options']['autosubmit_hide'] = 1;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'draggable';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'php',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['dragdrop'] = array(
    'preset' => 'calendar',
    'args' => array(
      'field_event_recipes' => 'w|nid',
      '@recipe_title' => 'w|title',
      '@qty' => '0',
      '@uom' => '0',
      '@type' => 'w|type',
      '@new' => 'r|status',
      '@date2' => '0',
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = 'No recipes.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  $handler->display->display_options['empty']['area']['tokenize'] = 0;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Flags: added_to_my_kitchen */
  $handler->display->display_options['relationships']['flag_content_rel']['id'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['flag_content_rel']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['flag'] = 'added_to_my_kitchen';
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['required'] = 0;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nid']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['nid']['link_to_node'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['max_length'] = '25';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['title']['link_to_node'] = 0;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['type']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['type']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['type']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['type']['alter']['external'] = 0;
  $handler->display->display_options['fields']['type']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['type']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['type']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['type']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['type']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['type']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['type']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['type']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['type']['alter']['html'] = 0;
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['type']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['type']['hide_empty'] = 0;
  $handler->display->display_options['fields']['type']['empty_zero'] = 0;
  $handler->display->display_options['fields']['type']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['type']['link_to_node'] = 0;
  $handler->display->display_options['fields']['type']['machine_name'] = 0;
  /* Field: Content: Published */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'node';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['exclude'] = TRUE;
  $handler->display->display_options['fields']['status']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['status']['alter']['text'] = '1';
  $handler->display->display_options['fields']['status']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['status']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['status']['alter']['external'] = 0;
  $handler->display->display_options['fields']['status']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['status']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['status']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['status']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['status']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['status']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['status']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['status']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['status']['alter']['html'] = 0;
  $handler->display->display_options['fields']['status']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['status']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['status']['hide_empty'] = 0;
  $handler->display->display_options['fields']['status']['empty_zero'] = 0;
  $handler->display->display_options['fields']['status']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['status']['type'] = 'true-false';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['view_node']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['view_node']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['view_node']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['html'] = 0;
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_node']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['view_node']['hide_empty'] = 0;
  $handler->display->display_options['fields']['view_node']['empty_zero'] = 0;
  $handler->display->display_options['fields']['view_node']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['view_node']['text'] = 'View';
  /* Field: Flags: Flag link */
  $handler->display->display_options['fields']['ops']['id'] = 'ops';
  $handler->display->display_options['fields']['ops']['table'] = 'flag_content';
  $handler->display->display_options['fields']['ops']['field'] = 'ops';
  $handler->display->display_options['fields']['ops']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['fields']['ops']['label'] = '';
  $handler->display->display_options['fields']['ops']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['ops']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['ops']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['ops']['alter']['external'] = 0;
  $handler->display->display_options['fields']['ops']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['ops']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['ops']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['ops']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['ops']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['ops']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['ops']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['ops']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['ops']['alter']['html'] = 0;
  $handler->display->display_options['fields']['ops']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['ops']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['ops']['hide_empty'] = 0;
  $handler->display->display_options['fields']['ops']['empty_zero'] = 0;
  $handler->display->display_options['fields']['ops']['hide_alter_empty'] = 1;
  /* Field: Content: Meal Type: */
  $handler->display->display_options['fields']['field_recipe_meal_type']['id'] = 'field_recipe_meal_type';
  $handler->display->display_options['fields']['field_recipe_meal_type']['table'] = 'field_data_field_recipe_meal_type';
  $handler->display->display_options['fields']['field_recipe_meal_type']['field'] = 'field_recipe_meal_type';
  $handler->display->display_options['fields']['field_recipe_meal_type']['label'] = '';
  $handler->display->display_options['fields']['field_recipe_meal_type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_recipe_meal_type']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_recipe_meal_type']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_recipe_meal_type']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_recipe_meal_type']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_recipe_meal_type']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_recipe_meal_type']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_recipe_meal_type']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_recipe_meal_type']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_recipe_meal_type']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_recipe_meal_type']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_recipe_meal_type']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_recipe_meal_type']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_recipe_meal_type']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_recipe_meal_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_recipe_meal_type']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_recipe_meal_type']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_recipe_meal_type']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_recipe_meal_type']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_recipe_meal_type']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_recipe_meal_type']['field_api_classes'] = 0;
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = '';
  $handler->display->display_options['fields']['php']['exclude'] = TRUE;
  $handler->display->display_options['fields']['php']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['php']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['php']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['php']['alter']['external'] = 0;
  $handler->display->display_options['fields']['php']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['php']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['php']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['php']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['php']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['php']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['php']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['php']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['php']['alter']['html'] = 0;
  $handler->display->display_options['fields']['php']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['php']['hide_empty'] = 0;
  $handler->display->display_options['fields']['php']['empty_zero'] = 0;
  $handler->display->display_options['fields']['php']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_value'] = '$id = db_select(\'xoxo_fields_taxonomy\', \'t\')
  ->fields(\'t\', array(\'tid\'))
  ->condition(\'t.nid\', $row->nid, \'=\')
  ->condition(\'t.uid\', $GLOBALS[\'user\']->uid, \'=\')
  ->execute()
  ->fetchField();
if (empty($id)) {
  $n = node_load($row->nid);
  $i = field_get_items(\'node\', $n, \'field_recipe_meal_type\');
  $id = isset($i[0][\'tid\']) ? $i[0][\'tid\'] : 0;
}
return $id;';
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
$t = taxonomy_term_load((int)$value);
echo (!empty($t) ? taxonomy_term_title($t) : t(\'No Type\'));
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Global: PHP */
  $handler->display->display_options['sorts']['php']['id'] = 'php';
  $handler->display->display_options['sorts']['php']['table'] = 'views';
  $handler->display->display_options['sorts']['php']['field'] = 'php';
  $handler->display->display_options['sorts']['php']['use_php_setup'] = 0;
  $handler->display->display_options['sorts']['php']['php_sort'] = 'return _xoxo_fields_custom_term_sort_perform($row1->nid, $row2->nid, TRUE);';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'recipe' => 'recipe',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Preferences: (field_recipe_status) */
  $handler->display->display_options['filters']['field_recipe_status_value']['id'] = 'field_recipe_status_value';
  $handler->display->display_options['filters']['field_recipe_status_value']['table'] = 'field_data_field_recipe_status';
  $handler->display->display_options['filters']['field_recipe_status_value']['field'] = 'field_recipe_status_value';
  $handler->display->display_options['filters']['field_recipe_status_value']['operator'] = 'not empty';
  $handler->display->display_options['filters']['field_recipe_status_value']['value'] = array(
    0 => '0',
  );
  $handler->display->display_options['filters']['field_recipe_status_value']['group'] = 1;
  /* Filter criterion: User: Current */
  $handler->display->display_options['filters']['uid_current']['id'] = 'uid_current';
  $handler->display->display_options['filters']['uid_current']['table'] = 'users';
  $handler->display->display_options['filters']['uid_current']['field'] = 'uid_current';
  $handler->display->display_options['filters']['uid_current']['relationship'] = 'uid';
  $handler->display->display_options['filters']['uid_current']['value'] = '1';
  $handler->display->display_options['filters']['uid_current']['group'] = 2;
  /* Filter criterion: Content: Preferences: (field_recipe_status) */
  $handler->display->display_options['filters']['field_recipe_status_value_1']['id'] = 'field_recipe_status_value_1';
  $handler->display->display_options['filters']['field_recipe_status_value_1']['table'] = 'field_data_field_recipe_status';
  $handler->display->display_options['filters']['field_recipe_status_value_1']['field'] = 'field_recipe_status_value';
  $handler->display->display_options['filters']['field_recipe_status_value_1']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_recipe_status_value_1']['group'] = 2;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = '!=';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['required'] = 0;
  $handler->display->display_options['filters']['title']['expose']['multiple'] = FALSE;
  $handler->display->display_options['block_description'] = 'Selected Recipes';

  /* Display: Prepared Meals */
  $handler = $view->new_display('block', 'Prepared Meals', 'block_2');
  $handler->display->display_options['display_description'] = 'Selected components.';
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'input_required';
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = 0;
  $handler->display->display_options['exposed_form']['options']['autosubmit_hide'] = 1;
  $handler->display->display_options['exposed_form']['options']['text_input_required_format'] = 'filtered_html';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'draggable';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'php_1',
      'rendered' => 0,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['dragdrop'] = array(
    'preset' => 'calendar',
    'args' => array(
      'field_event_recipes' => 'w|nid',
      '@recipe_title' => 'r|field_component_name',
      '@qty' => 'w|field_component_size',
      '@uom' => 'w|field_component_uom',
      '@type' => 'w|type',
      '@new' => 'r|status',
      '@date2' => '0',
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Flags: added_to_my_kitchen */
  $handler->display->display_options['relationships']['flag_content_rel']['id'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['flag_content_rel']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['flag'] = 'added_to_my_kitchen';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nid']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['nid']['link_to_node'] = 0;
  /* Field: Content: Name */
  $handler->display->display_options['fields']['field_component_name']['id'] = 'field_component_name';
  $handler->display->display_options['fields']['field_component_name']['table'] = 'field_data_field_component_name';
  $handler->display->display_options['fields']['field_component_name']['field'] = 'field_component_name';
  $handler->display->display_options['fields']['field_component_name']['label'] = '';
  $handler->display->display_options['fields']['field_component_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_component_name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_component_name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_component_name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_component_name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_component_name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_component_name']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_component_name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_component_name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_component_name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_component_name']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_component_name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_component_name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_component_name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_component_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_component_name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_component_name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_component_name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_component_name']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_component_name']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 0,
  );
  $handler->display->display_options['fields']['field_component_name']['field_api_classes'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['title']['link_to_node'] = 0;
  /* Field: PHP category */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['ui_name'] = 'PHP category';
  $handler->display->display_options['fields']['php']['label'] = '';
  $handler->display->display_options['fields']['php']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['php']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['php']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['php']['alter']['external'] = 0;
  $handler->display->display_options['fields']['php']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['php']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['php']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['php']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['php']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['php']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['php']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['php']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['php']['alter']['html'] = 0;
  $handler->display->display_options['fields']['php']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['php']['hide_empty'] = 0;
  $handler->display->display_options['fields']['php']['empty_zero'] = 0;
  $handler->display->display_options['fields']['php']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
print $row->title;
/*
if(!empty($data->field_field_component_name[0][\'raw\'][\'value\'])){
  print _xoxo_fields_component_name_by_id($data->field_field_component_name[0][\'raw\'][\'value\']);
}
else {
 print \'UNKNOWN\';
}*/
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Field: Content: UOM */
  $handler->display->display_options['fields']['field_component_uom']['id'] = 'field_component_uom';
  $handler->display->display_options['fields']['field_component_uom']['table'] = 'field_data_field_component_uom';
  $handler->display->display_options['fields']['field_component_uom']['field'] = 'field_component_uom';
  $handler->display->display_options['fields']['field_component_uom']['label'] = '';
  $handler->display->display_options['fields']['field_component_uom']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_component_uom']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_component_uom']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_component_uom']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_component_uom']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_component_uom']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_component_uom']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_component_uom']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_component_uom']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_component_uom']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_component_uom']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_component_uom']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_component_uom']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_component_uom']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_component_uom']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_component_uom']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_component_uom']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_component_uom']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_component_uom']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_component_uom']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_component_uom']['field_api_classes'] = 0;
  /* Field: Content: Size */
  $handler->display->display_options['fields']['field_component_size']['id'] = 'field_component_size';
  $handler->display->display_options['fields']['field_component_size']['table'] = 'field_data_field_component_size';
  $handler->display->display_options['fields']['field_component_size']['field'] = 'field_component_size';
  $handler->display->display_options['fields']['field_component_size']['label'] = '';
  $handler->display->display_options['fields']['field_component_size']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_component_size']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_component_size']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_component_size']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_component_size']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_component_size']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_component_size']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_component_size']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_component_size']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_component_size']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_component_size']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_component_size']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_component_size']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_component_size']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_component_size']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_component_size']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_component_size']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_component_size']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_component_size']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_component_size']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 0,
  );
  $handler->display->display_options['fields']['field_component_size']['field_api_classes'] = 0;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['type']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['type']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['type']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['type']['alter']['external'] = 0;
  $handler->display->display_options['fields']['type']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['type']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['type']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['type']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['type']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['type']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['type']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['type']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['type']['alter']['html'] = 0;
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['type']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['type']['hide_empty'] = 0;
  $handler->display->display_options['fields']['type']['empty_zero'] = 0;
  $handler->display->display_options['fields']['type']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['type']['link_to_node'] = 0;
  $handler->display->display_options['fields']['type']['machine_name'] = 0;
  /* Field: Content: Published */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'node';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['exclude'] = TRUE;
  $handler->display->display_options['fields']['status']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['status']['alter']['text'] = '1';
  $handler->display->display_options['fields']['status']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['status']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['status']['alter']['external'] = 0;
  $handler->display->display_options['fields']['status']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['status']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['status']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['status']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['status']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['status']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['status']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['status']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['status']['alter']['html'] = 0;
  $handler->display->display_options['fields']['status']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['status']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['status']['hide_empty'] = 0;
  $handler->display->display_options['fields']['status']['empty_zero'] = 0;
  $handler->display->display_options['fields']['status']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['status']['type'] = 'true-false';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['view_node']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['view_node']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['html'] = 0;
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_node']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['view_node']['hide_empty'] = 0;
  $handler->display->display_options['fields']['view_node']['empty_zero'] = 0;
  $handler->display->display_options['fields']['view_node']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['view_node']['text'] = 'View';
  /* Field: Flags: Flag link */
  $handler->display->display_options['fields']['ops']['id'] = 'ops';
  $handler->display->display_options['fields']['ops']['table'] = 'flag_content';
  $handler->display->display_options['fields']['ops']['field'] = 'ops';
  $handler->display->display_options['fields']['ops']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['fields']['ops']['label'] = '';
  $handler->display->display_options['fields']['ops']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['ops']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['ops']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['ops']['alter']['external'] = 0;
  $handler->display->display_options['fields']['ops']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['ops']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['ops']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['ops']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['ops']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['ops']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['ops']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['ops']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['ops']['alter']['html'] = 0;
  $handler->display->display_options['fields']['ops']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['ops']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['ops']['hide_empty'] = 0;
  $handler->display->display_options['fields']['ops']['empty_zero'] = 0;
  $handler->display->display_options['fields']['ops']['hide_alter_empty'] = 1;
  /* Field: Content: Category (level 1) */
  $handler->display->display_options['fields']['field_component_category']['id'] = 'field_component_category';
  $handler->display->display_options['fields']['field_component_category']['table'] = 'field_data_field_component_category';
  $handler->display->display_options['fields']['field_component_category']['field'] = 'field_component_category';
  $handler->display->display_options['fields']['field_component_category']['label'] = '';
  $handler->display->display_options['fields']['field_component_category']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_component_category']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_component_category']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_component_category']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_component_category']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_component_category']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_component_category']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_component_category']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_component_category']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_component_category']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_component_category']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_component_category']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_component_category']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_component_category']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_component_category']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_component_category']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_component_category']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_component_category']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_component_category']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_component_category']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_component_category']['field_api_classes'] = 0;
  /* Field: Content: Category (level 4) */
  $handler->display->display_options['fields']['field_component_category_4']['id'] = 'field_component_category_4';
  $handler->display->display_options['fields']['field_component_category_4']['table'] = 'field_data_field_component_category_4';
  $handler->display->display_options['fields']['field_component_category_4']['field'] = 'field_component_category_4';
  $handler->display->display_options['fields']['field_component_category_4']['label'] = '';
  $handler->display->display_options['fields']['field_component_category_4']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_component_category_4']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_component_category_4']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_component_category_4']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_component_category_4']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_component_category_4']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_component_category_4']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_component_category_4']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_component_category_4']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_component_category_4']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_component_category_4']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_component_category_4']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_component_category_4']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_component_category_4']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_component_category_4']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_component_category_4']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_component_category_4']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_component_category_4']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_component_category_4']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_component_category_4']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_component_category_4']['field_api_classes'] = 0;
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_1']['id'] = 'php_1';
  $handler->display->display_options['fields']['php_1']['table'] = 'views';
  $handler->display->display_options['fields']['php_1']['field'] = 'php';
  $handler->display->display_options['fields']['php_1']['label'] = '';
  $handler->display->display_options['fields']['php_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['php_1']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['php_1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['php_1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['php_1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['php_1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['php_1']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['php_1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['php_1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['php_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['php_1']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['php_1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['php_1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['php_1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['php_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php_1']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['php_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['php_1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['php_1']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['php_1']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_1']['php_value'] = 'global $user;
return _xoxo_fields_tid($row->nid, $user->uid, 11); /*db_select(\'xoxo_fields_taxonomy\', \'t\')
  ->fields(\'t\', array(\'tid\'))
  ->condition(\'t.nid\', $row->nid, \'=\')
  ->condition(\'t.uid\', $GLOBALS[\'user\']->uid, \'=\')
  ->execute()
  ->fetchField();*/';
  $handler->display->display_options['fields']['php_1']['php_output'] = '<?php echo (!empty($value) ? taxonomy_term_title(taxonomy_term_load($value)) : t(\'No Type\')); ?>';
  $handler->display->display_options['fields']['php_1']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_1']['php_click_sortable'] = '';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Global: PHP */
  $handler->display->display_options['sorts']['php']['id'] = 'php';
  $handler->display->display_options['sorts']['php']['table'] = 'views';
  $handler->display->display_options['sorts']['php']['field'] = 'php';
  $handler->display->display_options['sorts']['php']['use_php_setup'] = 0;
  $handler->display->display_options['sorts']['php']['php_sort'] = 'return _xoxo_fields_custom_term_sort_perform($row1->nid, $row2->nid);';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'component' => 'component',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;

  /* Display: Search Prepared Meals */
  $handler = $view->new_display('block', 'Search Prepared Meals', 'block_3');
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'input_required';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = 0;
  $handler->display->display_options['exposed_form']['options']['autosubmit_hide'] = 1;
  $handler->display->display_options['exposed_form']['options']['text_input_required'] = '';
  $handler->display->display_options['exposed_form']['options']['text_input_required_format'] = '';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '30';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'draggable';
  $handler->display->display_options['style_options']['dragdrop'] = array(
    'preset' => 'calendar',
    'args' => array(
      'field_event_recipes' => 'w|nid',
      '@recipe_title' => 'r|field_component_name',
      '@qty' => 'w|field_component_size',
      '@uom' => 'w|field_component_uom',
      '@type' => 'w|type',
      '@new' => 'r|status',
      '@date2' => '0',
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: View area */
  $handler->display->display_options['footer']['view']['id'] = 'view';
  $handler->display->display_options['footer']['view']['table'] = 'views';
  $handler->display->display_options['footer']['view']['field'] = 'view';
  $handler->display->display_options['footer']['view']['empty'] = TRUE;
  $handler->display->display_options['footer']['view']['view_to_insert'] = 'components:block_2';
  $handler->display->display_options['footer']['view']['inherit_arguments'] = 0;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = 'No results.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  $handler->display->display_options['empty']['area']['tokenize'] = 0;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Flags: added_to_my_kitchen */
  $handler->display->display_options['relationships']['flag_content_rel']['id'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['flag_content_rel']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['required'] = 0;
  $handler->display->display_options['relationships']['flag_content_rel']['flag'] = 'added_to_my_kitchen';
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['required'] = 0;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nid']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['nid']['link_to_node'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['title']['link_to_node'] = 0;
  /* Field: Content: Name */
  $handler->display->display_options['fields']['field_component_name']['id'] = 'field_component_name';
  $handler->display->display_options['fields']['field_component_name']['table'] = 'field_data_field_component_name';
  $handler->display->display_options['fields']['field_component_name']['field'] = 'field_component_name';
  $handler->display->display_options['fields']['field_component_name']['label'] = '';
  $handler->display->display_options['fields']['field_component_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_component_name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_component_name']['alter']['text'] = '[title]';
  $handler->display->display_options['fields']['field_component_name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_component_name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_component_name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_component_name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_component_name']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_component_name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_component_name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_component_name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_component_name']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_component_name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_component_name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_component_name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_component_name']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_component_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_component_name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_component_name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_component_name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_component_name']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_component_name']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 0,
  );
  $handler->display->display_options['fields']['field_component_name']['field_api_classes'] = 0;
  /* Field: Content: UOM */
  $handler->display->display_options['fields']['field_component_uom']['id'] = 'field_component_uom';
  $handler->display->display_options['fields']['field_component_uom']['table'] = 'field_data_field_component_uom';
  $handler->display->display_options['fields']['field_component_uom']['field'] = 'field_component_uom';
  $handler->display->display_options['fields']['field_component_uom']['label'] = '';
  $handler->display->display_options['fields']['field_component_uom']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_component_uom']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_component_uom']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_component_uom']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_component_uom']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_component_uom']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_component_uom']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_component_uom']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_component_uom']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_component_uom']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_component_uom']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_component_uom']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_component_uom']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_component_uom']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_component_uom']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_component_uom']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_component_uom']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_component_uom']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_component_uom']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_component_uom']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_component_uom']['field_api_classes'] = 0;
  /* Field: Content: Size */
  $handler->display->display_options['fields']['field_component_size']['id'] = 'field_component_size';
  $handler->display->display_options['fields']['field_component_size']['table'] = 'field_data_field_component_size';
  $handler->display->display_options['fields']['field_component_size']['field'] = 'field_component_size';
  $handler->display->display_options['fields']['field_component_size']['label'] = '';
  $handler->display->display_options['fields']['field_component_size']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_component_size']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_component_size']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_component_size']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_component_size']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_component_size']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_component_size']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_component_size']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_component_size']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_component_size']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_component_size']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_component_size']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_component_size']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_component_size']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_component_size']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_component_size']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_component_size']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_component_size']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_component_size']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_component_size']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 0,
  );
  $handler->display->display_options['fields']['field_component_size']['field_api_classes'] = 0;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['type']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['type']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['type']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['type']['alter']['external'] = 0;
  $handler->display->display_options['fields']['type']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['type']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['type']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['type']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['type']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['type']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['type']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['type']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['type']['alter']['html'] = 0;
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['type']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['type']['hide_empty'] = 0;
  $handler->display->display_options['fields']['type']['empty_zero'] = 0;
  $handler->display->display_options['fields']['type']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['type']['link_to_node'] = 0;
  $handler->display->display_options['fields']['type']['machine_name'] = 0;
  /* Field: Content: Published */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'node';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['exclude'] = TRUE;
  $handler->display->display_options['fields']['status']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['status']['alter']['text'] = '1';
  $handler->display->display_options['fields']['status']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['status']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['status']['alter']['external'] = 0;
  $handler->display->display_options['fields']['status']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['status']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['status']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['status']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['status']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['status']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['status']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['status']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['status']['alter']['html'] = 0;
  $handler->display->display_options['fields']['status']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['status']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['status']['hide_empty'] = 0;
  $handler->display->display_options['fields']['status']['empty_zero'] = 0;
  $handler->display->display_options['fields']['status']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['status']['type'] = 'true-false';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['view_node']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['view_node']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['html'] = 0;
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_node']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['view_node']['hide_empty'] = 0;
  $handler->display->display_options['fields']['view_node']['empty_zero'] = 0;
  $handler->display->display_options['fields']['view_node']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['view_node']['text'] = 'View';
  /* Field: Flags: Flag link */
  $handler->display->display_options['fields']['ops']['id'] = 'ops';
  $handler->display->display_options['fields']['ops']['table'] = 'flag_content';
  $handler->display->display_options['fields']['ops']['field'] = 'ops';
  $handler->display->display_options['fields']['ops']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['fields']['ops']['label'] = '';
  $handler->display->display_options['fields']['ops']['exclude'] = TRUE;
  $handler->display->display_options['fields']['ops']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['ops']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['ops']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['ops']['alter']['external'] = 0;
  $handler->display->display_options['fields']['ops']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['ops']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['ops']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['ops']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['ops']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['ops']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['ops']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['ops']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['ops']['alter']['html'] = 0;
  $handler->display->display_options['fields']['ops']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['ops']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['ops']['hide_empty'] = 0;
  $handler->display->display_options['fields']['ops']['empty_zero'] = 0;
  $handler->display->display_options['fields']['ops']['hide_alter_empty'] = 1;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<span>Add</span>';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nothing']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nothing']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nothing']['element_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_class'] = 'flag';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nothing']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nothing']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nothing']['hide_alter_empty'] = 0;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'component' => 'component',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Category (level 1) (field_component_category) */
  $handler->display->display_options['filters']['field_component_category_tid']['id'] = 'field_component_category_tid';
  $handler->display->display_options['filters']['field_component_category_tid']['table'] = 'field_data_field_component_category';
  $handler->display->display_options['filters']['field_component_category_tid']['field'] = 'field_component_category_tid';
  $handler->display->display_options['filters']['field_component_category_tid']['value'] = array(
    2423 => '2423',
  );
  $handler->display->display_options['filters']['field_component_category_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_component_category_tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['field_component_category_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_component_category_tid']['vocabulary'] = 'product_category';
  /* Filter criterion: Content: Category (level 2) (field_component_category_2) */
  $handler->display->display_options['filters']['field_component_category_2_tid']['id'] = 'field_component_category_2_tid';
  $handler->display->display_options['filters']['field_component_category_2_tid']['table'] = 'field_data_field_component_category_2';
  $handler->display->display_options['filters']['field_component_category_2_tid']['field'] = 'field_component_category_2_tid';
  $handler->display->display_options['filters']['field_component_category_2_tid']['operator'] = 'not';
  $handler->display->display_options['filters']['field_component_category_2_tid']['value'] = array(
    2792 => '2792',
  );
  $handler->display->display_options['filters']['field_component_category_2_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_component_category_2_tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['field_component_category_2_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_component_category_2_tid']['vocabulary'] = 'product_category_level_2_';
  /* Filter criterion: Flags: Flagged */
  $handler->display->display_options['filters']['flagged']['id'] = 'flagged';
  $handler->display->display_options['filters']['flagged']['table'] = 'flag_content';
  $handler->display->display_options['filters']['flagged']['field'] = 'flagged';
  $handler->display->display_options['filters']['flagged']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['filters']['flagged']['value'] = '0';
  $handler->display->display_options['filters']['flagged']['group'] = 1;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 2;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: User: Current */
  $handler->display->display_options['filters']['uid_current']['id'] = 'uid_current';
  $handler->display->display_options['filters']['uid_current']['table'] = 'users';
  $handler->display->display_options['filters']['uid_current']['field'] = 'uid_current';
  $handler->display->display_options['filters']['uid_current']['relationship'] = 'uid';
  $handler->display->display_options['filters']['uid_current']['value'] = '1';
  $handler->display->display_options['filters']['uid_current']['group'] = 2;
  /* Filter criterion: Content: Brand (field_component_brand) */
  $handler->display->display_options['filters']['field_component_brand_value']['id'] = 'field_component_brand_value';
  $handler->display->display_options['filters']['field_component_brand_value']['table'] = 'field_data_field_component_brand';
  $handler->display->display_options['filters']['field_component_brand_value']['field'] = 'field_component_brand_value';
  $handler->display->display_options['filters']['field_component_brand_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_component_brand_value']['expose']['operator_id'] = 'field_component_brand_value_op';
  $handler->display->display_options['filters']['field_component_brand_value']['expose']['operator'] = 'field_component_brand_value_op';
  $handler->display->display_options['filters']['field_component_brand_value']['expose']['identifier'] = 'field_component_brand_value';
  $handler->display->display_options['filters']['field_component_brand_value']['expose']['multiple'] = FALSE;
  /* Filter criterion: Content: Description (field_component_description) */
  $handler->display->display_options['filters']['field_component_description_value']['id'] = 'field_component_description_value';
  $handler->display->display_options['filters']['field_component_description_value']['table'] = 'field_data_field_component_description';
  $handler->display->display_options['filters']['field_component_description_value']['field'] = 'field_component_description_value';
  $handler->display->display_options['filters']['field_component_description_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_component_description_value']['expose']['operator_id'] = 'field_component_description_value_op';
  $handler->display->display_options['filters']['field_component_description_value']['expose']['operator'] = 'field_component_description_value_op';
  $handler->display->display_options['filters']['field_component_description_value']['expose']['identifier'] = 'field_component_description_value';
  $handler->display->display_options['filters']['field_component_description_value']['expose']['required'] = 0;
  $handler->display->display_options['filters']['field_component_description_value']['expose']['multiple'] = FALSE;
  /* Filter criterion: XOXO Kitchen: Name */
  $handler->display->display_options['filters']['value']['id'] = 'value';
  $handler->display->display_options['filters']['value']['table'] = 'xoxo_names';
  $handler->display->display_options['filters']['value']['field'] = 'value';
  $handler->display->display_options['filters']['value']['operator'] = 'allwords';
  $handler->display->display_options['filters']['value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['value']['expose']['operator_id'] = 'value_op';
  $handler->display->display_options['filters']['value']['expose']['operator'] = 'value_op';
  $handler->display->display_options['filters']['value']['expose']['identifier'] = 'field_component_name_value';
  $handler->display->display_options['filters']['value']['expose']['required'] = 0;
  $handler->display->display_options['filters']['value']['expose']['multiple'] = FALSE;

  /* Display: Add Recipes */
  $handler = $view->new_display('block', 'Add Recipes', 'block_4');
  $handler->display->display_options['display_description'] = 'Select or create recipes for current kitchen.';
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'input_required';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search The XOXO Recipe Collection';
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = 0;
  $handler->display->display_options['exposed_form']['options']['autosubmit_hide'] = 1;
  $handler->display->display_options['exposed_form']['options']['text_input_required'] = '';
  $handler->display->display_options['exposed_form']['options']['text_input_required_format'] = 'filtered_html';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '15';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'draggable';
  $handler->display->display_options['style_options']['dragdrop'] = array(
    'preset' => 'calendar',
    'args' => array(
      'field_event_recipes' => 'w|nid',
      '@recipe_title' => 'w|title',
      '@qty' => '0',
      '@uom' => '0',
      '@type' => 'w|type',
      '@new' => 'r|status',
      '@date2' => '0',
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = '<a href="/node/add/recipe" class="add-recipe">Create New Recipe</a>';
  $handler->display->display_options['header']['area']['format'] = 'filtered_html';
  $handler->display->display_options['header']['area']['tokenize'] = 0;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = ' ';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  $handler->display->display_options['empty']['area']['tokenize'] = 0;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Flags: added_to_my_kitchen */
  $handler->display->display_options['relationships']['flag_content_rel']['id'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['flag_content_rel']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['required'] = 0;
  $handler->display->display_options['relationships']['flag_content_rel']['flag'] = 'added_to_my_kitchen';
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['required'] = 0;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nid']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['nid']['link_to_node'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['title']['link_to_node'] = 0;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['type']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['type']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['type']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['type']['alter']['external'] = 0;
  $handler->display->display_options['fields']['type']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['type']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['type']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['type']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['type']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['type']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['type']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['type']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['type']['alter']['html'] = 0;
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['type']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['type']['hide_empty'] = 0;
  $handler->display->display_options['fields']['type']['empty_zero'] = 0;
  $handler->display->display_options['fields']['type']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['type']['link_to_node'] = 0;
  $handler->display->display_options['fields']['type']['machine_name'] = 0;
  /* Field: Content: Published */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'node';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['exclude'] = TRUE;
  $handler->display->display_options['fields']['status']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['status']['alter']['text'] = '1';
  $handler->display->display_options['fields']['status']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['status']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['status']['alter']['external'] = 0;
  $handler->display->display_options['fields']['status']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['status']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['status']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['status']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['status']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['status']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['status']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['status']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['status']['alter']['html'] = 0;
  $handler->display->display_options['fields']['status']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['status']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['status']['hide_empty'] = 0;
  $handler->display->display_options['fields']['status']['empty_zero'] = 0;
  $handler->display->display_options['fields']['status']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['status']['type'] = 'true-false';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['view_node']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['view_node']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['view_node']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['html'] = 0;
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_node']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['view_node']['hide_empty'] = 0;
  $handler->display->display_options['fields']['view_node']['empty_zero'] = 0;
  $handler->display->display_options['fields']['view_node']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['view_node']['text'] = 'View';
  /* Field: Flags: Flag link */
  $handler->display->display_options['fields']['ops']['id'] = 'ops';
  $handler->display->display_options['fields']['ops']['table'] = 'flag_content';
  $handler->display->display_options['fields']['ops']['field'] = 'ops';
  $handler->display->display_options['fields']['ops']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['fields']['ops']['label'] = '';
  $handler->display->display_options['fields']['ops']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['ops']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['ops']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['ops']['alter']['external'] = 0;
  $handler->display->display_options['fields']['ops']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['ops']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['ops']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['ops']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['ops']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['ops']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['ops']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['ops']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['ops']['alter']['html'] = 0;
  $handler->display->display_options['fields']['ops']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['ops']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['ops']['hide_empty'] = 0;
  $handler->display->display_options['fields']['ops']['empty_zero'] = 0;
  $handler->display->display_options['fields']['ops']['hide_alter_empty'] = 1;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'recipe' => 'recipe',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Search';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['required'] = 1;
  $handler->display->display_options['filters']['title']['expose']['multiple'] = FALSE;
  /* Filter criterion: Flags: Flagged */
  $handler->display->display_options['filters']['flagged']['id'] = 'flagged';
  $handler->display->display_options['filters']['flagged']['table'] = 'flag_content';
  $handler->display->display_options['filters']['flagged']['field'] = 'flagged';
  $handler->display->display_options['filters']['flagged']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['filters']['flagged']['value'] = '0';
  $handler->display->display_options['filters']['flagged']['group'] = 1;
  /* Filter criterion: User: Current */
  $handler->display->display_options['filters']['uid_current']['id'] = 'uid_current';
  $handler->display->display_options['filters']['uid_current']['table'] = 'users';
  $handler->display->display_options['filters']['uid_current']['field'] = 'uid_current';
  $handler->display->display_options['filters']['uid_current']['relationship'] = 'uid';
  $handler->display->display_options['filters']['uid_current']['value'] = '1';
  $handler->display->display_options['filters']['uid_current']['group'] = 2;
  /* Filter criterion: Content: Preferences: (field_recipe_status) */
  $handler->display->display_options['filters']['field_recipe_status_value']['id'] = 'field_recipe_status_value';
  $handler->display->display_options['filters']['field_recipe_status_value']['table'] = 'field_data_field_recipe_status';
  $handler->display->display_options['filters']['field_recipe_status_value']['field'] = 'field_recipe_status_value';
  $handler->display->display_options['filters']['field_recipe_status_value']['operator'] = 'not empty';
  $handler->display->display_options['filters']['field_recipe_status_value']['group'] = 2;
  $export['components'] = $view;

  $view = new view;
  $view->name = 'kitchen_setup_staples';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Kitchen Setup Staples';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Add a Staple';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    5 => '5',
    6 => '6',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '100';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'draggable';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_component_category',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['dragdrop'] = array(
    'preset' => 'shopping_list',
    'args' => array(
      'field_shopping_list_items:reference_nid' => 'w|nid',
      'field_shopping_list_items:qty' => 'r|field_component_size',
      'field_shopping_list_items:uom' => 'r|tid',
      '@cat_id' => 'r|tid_1',
      '@uom' => 'r|field_component_uom',
      '@cname_id' => 'w|field_component_name',
      '@component_nid' => 'w|nid',
      '@brand' => 'r|field_component_brand',
    ),
  );
  $handler->display->display_options['row_plugin'] = 'fields';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  /* Relationship: Content: UOM (field_component_uom) */
  $handler->display->display_options['relationships']['field_component_uom_tid']['id'] = 'field_component_uom_tid';
  $handler->display->display_options['relationships']['field_component_uom_tid']['table'] = 'field_data_field_component_uom';
  $handler->display->display_options['relationships']['field_component_uom_tid']['field'] = 'field_component_uom_tid';
  $handler->display->display_options['relationships']['field_component_uom_tid']['required'] = 0;
  /* Relationship: Content: Category (level 1) (field_component_category) */
  $handler->display->display_options['relationships']['field_component_category_tid']['id'] = 'field_component_category_tid';
  $handler->display->display_options['relationships']['field_component_category_tid']['table'] = 'field_data_field_component_category';
  $handler->display->display_options['relationships']['field_component_category_tid']['field'] = 'field_component_category_tid';
  $handler->display->display_options['relationships']['field_component_category_tid']['required'] = 0;
  /* Relationship: Flags: added_to_my_kitchen */
  $handler->display->display_options['relationships']['flag_content_rel']['id'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['flag_content_rel']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['flag'] = 'added_to_my_kitchen';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['max_length'] = '24';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 1;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['title']['link_to_node'] = 0;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['nid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nid']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['nid']['link_to_node'] = 0;
  /* Field: Taxonomy term: Term ID */
  $handler->display->display_options['fields']['tid']['id'] = 'tid';
  $handler->display->display_options['fields']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['tid']['field'] = 'tid';
  $handler->display->display_options['fields']['tid']['relationship'] = 'field_component_uom_tid';
  $handler->display->display_options['fields']['tid']['label'] = 'UOM term id';
  $handler->display->display_options['fields']['tid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['tid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['tid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['tid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['tid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['tid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['tid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['tid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['tid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['tid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['tid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['tid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['tid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['tid']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['tid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['tid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['tid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['tid']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['tid']['separator'] = '';
  $handler->display->display_options['fields']['tid']['format_plural'] = 0;
  /* Field: Content: Size */
  $handler->display->display_options['fields']['field_component_size']['id'] = 'field_component_size';
  $handler->display->display_options['fields']['field_component_size']['table'] = 'field_data_field_component_size';
  $handler->display->display_options['fields']['field_component_size']['field'] = 'field_component_size';
  $handler->display->display_options['fields']['field_component_size']['label'] = '';
  $handler->display->display_options['fields']['field_component_size']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_component_size']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_component_size']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_component_size']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_component_size']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_component_size']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_component_size']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_component_size']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_component_size']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_component_size']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_component_size']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_component_size']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_component_size']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_component_size']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_component_size']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_component_size']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_component_size']['empty'] = '0';
  $handler->display->display_options['fields']['field_component_size']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_component_size']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_component_size']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_component_size']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['fields']['field_component_size']['field_api_classes'] = 0;
  /* Field: Content: UOM */
  $handler->display->display_options['fields']['field_component_uom']['id'] = 'field_component_uom';
  $handler->display->display_options['fields']['field_component_uom']['table'] = 'field_data_field_component_uom';
  $handler->display->display_options['fields']['field_component_uom']['field'] = 'field_component_uom';
  $handler->display->display_options['fields']['field_component_uom']['label'] = '';
  $handler->display->display_options['fields']['field_component_uom']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_component_uom']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_component_uom']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_component_uom']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_component_uom']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_component_uom']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_component_uom']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_component_uom']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_component_uom']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_component_uom']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_component_uom']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_component_uom']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_component_uom']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_component_uom']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_component_uom']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_component_uom']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_component_uom']['empty'] = '0';
  $handler->display->display_options['fields']['field_component_uom']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_component_uom']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_component_uom']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_component_uom']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_component_uom']['field_api_classes'] = 0;
  /* Field: Taxonomy term: Term ID */
  $handler->display->display_options['fields']['tid_1']['id'] = 'tid_1';
  $handler->display->display_options['fields']['tid_1']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['tid_1']['field'] = 'tid';
  $handler->display->display_options['fields']['tid_1']['relationship'] = 'field_component_category_tid';
  $handler->display->display_options['fields']['tid_1']['label'] = '';
  $handler->display->display_options['fields']['tid_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['tid_1']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['tid_1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['tid_1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['tid_1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['tid_1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['tid_1']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['tid_1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['tid_1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['tid_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['tid_1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['tid_1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['tid_1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['tid_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['tid_1']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['tid_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['tid_1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['tid_1']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['tid_1']['separator'] = '';
  $handler->display->display_options['fields']['tid_1']['format_plural'] = 0;
  /* Field: Content: Category (level 1) */
  $handler->display->display_options['fields']['field_component_category']['id'] = 'field_component_category';
  $handler->display->display_options['fields']['field_component_category']['table'] = 'field_data_field_component_category';
  $handler->display->display_options['fields']['field_component_category']['field'] = 'field_component_category';
  $handler->display->display_options['fields']['field_component_category']['label'] = '';
  $handler->display->display_options['fields']['field_component_category']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_component_category']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_component_category']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_component_category']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_component_category']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_component_category']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_component_category']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_component_category']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_component_category']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_component_category']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_component_category']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_component_category']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_component_category']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_component_category']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_component_category']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_component_category']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_component_category']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_component_category']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_component_category']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_component_category']['field_api_classes'] = 0;
  /* Field: Content: Brand */
  $handler->display->display_options['fields']['field_component_brand']['id'] = 'field_component_brand';
  $handler->display->display_options['fields']['field_component_brand']['table'] = 'field_data_field_component_brand';
  $handler->display->display_options['fields']['field_component_brand']['field'] = 'field_component_brand';
  $handler->display->display_options['fields']['field_component_brand']['label'] = '';
  $handler->display->display_options['fields']['field_component_brand']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_component_brand']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_component_brand']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_component_brand']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_component_brand']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_component_brand']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_component_brand']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_component_brand']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_component_brand']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_component_brand']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_component_brand']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_component_brand']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_component_brand']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_component_brand']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_component_brand']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_component_brand']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_component_brand']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_component_brand']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_component_brand']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 0,
  );
  $handler->display->display_options['fields']['field_component_brand']['field_api_classes'] = 0;
  /* Field: Content: Name */
  $handler->display->display_options['fields']['field_component_name']['id'] = 'field_component_name';
  $handler->display->display_options['fields']['field_component_name']['table'] = 'field_data_field_component_name';
  $handler->display->display_options['fields']['field_component_name']['field'] = 'field_component_name';
  $handler->display->display_options['fields']['field_component_name']['label'] = '';
  $handler->display->display_options['fields']['field_component_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_component_name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_component_name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_component_name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_component_name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_component_name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_component_name']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_component_name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_component_name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_component_name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_component_name']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_component_name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_component_name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_component_name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_component_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_component_name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_component_name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_component_name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_component_name']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_component_name']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 0,
  );
  $handler->display->display_options['fields']['field_component_name']['field_api_classes'] = 0;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'OR',
  );
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'component' => 'component',
  );
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['title']['expose']['use_operator'] = FALSE;
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember'] = FALSE;
  $handler->display->display_options['filters']['title']['expose']['multiple'] = FALSE;

  /* Display: Staples */
  $handler = $view->new_display('block', 'Staples', 'block');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Staples';
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'main_scroll';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'draggable';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_component_sc',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['dragdrop'] = array(
    'preset' => 'vocabulary',
    'args' => array(
      'field_shopping_list_items:reference_nid' => 'd|nid',
      'field_shopping_list_items:qty' => '0',
      'field_shopping_list_items:uom' => '0',
      '@cat_id' => '0',
      '@uom' => '0',
      '@cname_id' => '0',
      '@component_nid' => 'd|nid',
      '@brand' => '0',
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['required'] = 0;
  /* Relationship: Flags: added_to_my_staples */
  $handler->display->display_options['relationships']['flag_content_rel']['id'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['flag_content_rel']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['required'] = 0;
  $handler->display->display_options['relationships']['flag_content_rel']['flag'] = 'added_to_my_staples';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['max_length'] = '24';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['title']['link_to_node'] = 0;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['nid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nid']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['nid']['link_to_node'] = 0;
  /* Field: Content: Staple Category */
  $handler->display->display_options['fields']['field_component_sc']['id'] = 'field_component_sc';
  $handler->display->display_options['fields']['field_component_sc']['table'] = 'field_data_field_component_sc';
  $handler->display->display_options['fields']['field_component_sc']['field'] = 'field_component_sc';
  $handler->display->display_options['fields']['field_component_sc']['label'] = '';
  $handler->display->display_options['fields']['field_component_sc']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_component_sc']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_component_sc']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_component_sc']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_component_sc']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_component_sc']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_component_sc']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_component_sc']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_component_sc']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_component_sc']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_component_sc']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_component_sc']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_component_sc']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_component_sc']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_component_sc']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_component_sc']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_component_sc']['empty'] = 'No Category';
  $handler->display->display_options['fields']['field_component_sc']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_component_sc']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_component_sc']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_component_sc']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_component_sc']['field_api_classes'] = 0;
  /* Field: Categorize (PHP) */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['ui_name'] = 'Categorize (PHP)';
  $handler->display->display_options['fields']['php']['label'] = '';
  $handler->display->display_options['fields']['php']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['php']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['php']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['php']['alter']['external'] = 0;
  $handler->display->display_options['fields']['php']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['php']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['php']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['php']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['php']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['php']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['php']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['php']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['php']['alter']['html'] = 0;
  $handler->display->display_options['fields']['php']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['php']['hide_empty'] = 0;
  $handler->display->display_options['fields']['php']['empty_zero'] = 0;
  $handler->display->display_options['fields']['php']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_value'] = 'return array(
  \'#type\' => \'cat\',
  \'#nid\' => $data->nid,
  \'#vid\' => 20
);';
  $handler->display->display_options['fields']['php']['php_output'] = '<?php echo render($value); ?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Staple Category (field_component_sc) */
  $handler->display->display_options['sorts']['field_component_sc_tid']['id'] = 'field_component_sc_tid';
  $handler->display->display_options['sorts']['field_component_sc_tid']['table'] = 'field_data_field_component_sc';
  $handler->display->display_options['sorts']['field_component_sc_tid']['field'] = 'field_component_sc_tid';
  $handler->display->display_options['sorts']['field_component_sc_tid']['order'] = 'DESC';
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'component' => 'component',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 2;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: User: Current */
  $handler->display->display_options['filters']['uid_current']['id'] = 'uid_current';
  $handler->display->display_options['filters']['uid_current']['table'] = 'users';
  $handler->display->display_options['filters']['uid_current']['field'] = 'uid_current';
  $handler->display->display_options['filters']['uid_current']['relationship'] = 'uid';
  $handler->display->display_options['filters']['uid_current']['value'] = '1';
  $handler->display->display_options['filters']['uid_current']['group'] = 2;
  /* Filter criterion: Content: Staple on Kitchen-Setup (field_component_ks) */
  $handler->display->display_options['filters']['field_component_ks_value']['id'] = 'field_component_ks_value';
  $handler->display->display_options['filters']['field_component_ks_value']['table'] = 'field_data_field_component_ks';
  $handler->display->display_options['filters']['field_component_ks_value']['field'] = 'field_component_ks_value';
  $handler->display->display_options['filters']['field_component_ks_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_component_ks_value']['expose']['operator_id'] = 'field_component_ks_value_op';
  $handler->display->display_options['filters']['field_component_ks_value']['expose']['label'] = 'Staple on Kitchen-Setup (field_component_ks)';
  $handler->display->display_options['filters']['field_component_ks_value']['expose']['use_operator'] = FALSE;
  $handler->display->display_options['filters']['field_component_ks_value']['expose']['operator'] = 'field_component_ks_value_op';
  $handler->display->display_options['filters']['field_component_ks_value']['expose']['identifier'] = 'field_component_ks_value';
  $handler->display->display_options['filters']['field_component_ks_value']['expose']['required'] = FALSE;
  $handler->display->display_options['filters']['field_component_ks_value']['expose']['remember'] = FALSE;
  $handler->display->display_options['filters']['field_component_ks_value']['expose']['multiple'] = FALSE;
  $handler->display->display_options['block_description'] = 'Staples';
  $export['kitchen_setup_staples'] = $view;

  $view = new view;
  $view->name = 'recipes_components';
  $view->description = 'List of recipes and components a user can add to his (her) kitchen.';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Kitchen Setup';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Prepared Meals';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = 1;
  $handler->display->display_options['exposed_form']['options']['autosubmit_hide'] = 1;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'type',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
    1 => array(
      'field' => 'field_component_category',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_component_category' => 'field_component_category',
    'view_node' => 'view_node',
    'ops' => 'ops',
    'type' => 'type',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_component_category' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'view_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'ops' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'type' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  $handler->display->display_options['style_options']['empty_table'] = 0;
  /* Relationship: Flags: added_to_my_kitchen */
  $handler->display->display_options['relationships']['flag_content_rel']['id'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['flag_content_rel']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['required'] = 0;
  $handler->display->display_options['relationships']['flag_content_rel']['flag'] = 'added_to_my_kitchen';
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['required'] = 0;
  /* Relationship: Content: Meal type (field_componets_meal_type) */
  $handler->display->display_options['relationships']['field_componets_meal_type_tid']['id'] = 'field_componets_meal_type_tid';
  $handler->display->display_options['relationships']['field_componets_meal_type_tid']['table'] = 'field_data_field_componets_meal_type';
  $handler->display->display_options['relationships']['field_componets_meal_type_tid']['field'] = 'field_componets_meal_type_tid';
  $handler->display->display_options['relationships']['field_componets_meal_type_tid']['label'] = 'Meal type';
  $handler->display->display_options['relationships']['field_componets_meal_type_tid']['required'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Content: Category (level 1) */
  $handler->display->display_options['fields']['field_component_category']['id'] = 'field_component_category';
  $handler->display->display_options['fields']['field_component_category']['table'] = 'field_data_field_component_category';
  $handler->display->display_options['fields']['field_component_category']['field'] = 'field_component_category';
  $handler->display->display_options['fields']['field_component_category']['label'] = '';
  $handler->display->display_options['fields']['field_component_category']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_component_category']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_component_category']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_component_category']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_component_category']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_component_category']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_component_category']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_component_category']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_component_category']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_component_category']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_component_category']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_component_category']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_component_category']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_component_category']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_component_category']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_component_category']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_component_category']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_component_category']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_component_category']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_component_category']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_component_category']['field_api_classes'] = 0;
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['view_node']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['view_node']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['html'] = 0;
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_node']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['view_node']['hide_empty'] = 0;
  $handler->display->display_options['fields']['view_node']['empty_zero'] = 0;
  $handler->display->display_options['fields']['view_node']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['view_node']['text'] = 'View';
  /* Field: Flags: Flag link */
  $handler->display->display_options['fields']['ops']['id'] = 'ops';
  $handler->display->display_options['fields']['ops']['table'] = 'flag_content';
  $handler->display->display_options['fields']['ops']['field'] = 'ops';
  $handler->display->display_options['fields']['ops']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['fields']['ops']['label'] = '';
  $handler->display->display_options['fields']['ops']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['ops']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['ops']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['ops']['alter']['external'] = 0;
  $handler->display->display_options['fields']['ops']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['ops']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['ops']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['ops']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['ops']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['ops']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['ops']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['ops']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['ops']['alter']['html'] = 0;
  $handler->display->display_options['fields']['ops']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['ops']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['ops']['hide_empty'] = 0;
  $handler->display->display_options['fields']['ops']['empty_zero'] = 0;
  $handler->display->display_options['fields']['ops']['hide_alter_empty'] = 1;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Sort criterion: Content: Section id (field_component_section_id) */
  $handler->display->display_options['sorts']['field_component_section_id_value']['id'] = 'field_component_section_id_value';
  $handler->display->display_options['sorts']['field_component_section_id_value']['table'] = 'field_data_field_component_section_id';
  $handler->display->display_options['sorts']['field_component_section_id_value']['field'] = 'field_component_section_id_value';
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'OR',
  );
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'component' => 'component',
    'recipe' => 'recipe',
  );

  /* Display: Recipes */
  $handler = $view->new_display('block', 'Recipes', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Recipes';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_recipe_meal_type',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'view_node' => 'view_node',
    'ops' => 'ops',
    'field_recipe_meal_type' => 'field_recipe_meal_type',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'view_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'ops' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_recipe_meal_type' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  $handler->display->display_options['style_options']['empty_table'] = 0;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Flags: added_to_my_kitchen */
  $handler->display->display_options['relationships']['flag_content_rel']['id'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['flag_content_rel']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['required'] = 0;
  $handler->display->display_options['relationships']['flag_content_rel']['flag'] = 'added_to_my_kitchen';
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['required'] = 0;
  /* Relationship: Meal Type */
  $handler->display->display_options['relationships']['field_recipe_meal_type_tid']['id'] = 'field_recipe_meal_type_tid';
  $handler->display->display_options['relationships']['field_recipe_meal_type_tid']['table'] = 'field_data_field_recipe_meal_type';
  $handler->display->display_options['relationships']['field_recipe_meal_type_tid']['field'] = 'field_recipe_meal_type_tid';
  $handler->display->display_options['relationships']['field_recipe_meal_type_tid']['ui_name'] = 'Meal Type';
  $handler->display->display_options['relationships']['field_recipe_meal_type_tid']['label'] = 'Meal Type';
  $handler->display->display_options['relationships']['field_recipe_meal_type_tid']['required'] = 0;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['title']['link_to_node'] = 0;
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['view_node']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['view_node']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['view_node']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['html'] = 0;
  $handler->display->display_options['fields']['view_node']['element_type'] = 'div';
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_node']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['view_node']['hide_empty'] = 0;
  $handler->display->display_options['fields']['view_node']['empty_zero'] = 0;
  $handler->display->display_options['fields']['view_node']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['view_node']['text'] = 'View';
  /* Field: Flags: Flag link */
  $handler->display->display_options['fields']['ops']['id'] = 'ops';
  $handler->display->display_options['fields']['ops']['table'] = 'flag_content';
  $handler->display->display_options['fields']['ops']['field'] = 'ops';
  $handler->display->display_options['fields']['ops']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['fields']['ops']['label'] = '';
  $handler->display->display_options['fields']['ops']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['ops']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['ops']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['ops']['alter']['external'] = 0;
  $handler->display->display_options['fields']['ops']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['ops']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['ops']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['ops']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['ops']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['ops']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['ops']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['ops']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['ops']['alter']['html'] = 0;
  $handler->display->display_options['fields']['ops']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['ops']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['ops']['hide_empty'] = 0;
  $handler->display->display_options['fields']['ops']['empty_zero'] = 0;
  $handler->display->display_options['fields']['ops']['hide_alter_empty'] = 1;
  /* Field: Content: Meal Type: */
  $handler->display->display_options['fields']['field_recipe_meal_type']['id'] = 'field_recipe_meal_type';
  $handler->display->display_options['fields']['field_recipe_meal_type']['table'] = 'field_data_field_recipe_meal_type';
  $handler->display->display_options['fields']['field_recipe_meal_type']['field'] = 'field_recipe_meal_type';
  $handler->display->display_options['fields']['field_recipe_meal_type']['label'] = '';
  $handler->display->display_options['fields']['field_recipe_meal_type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_recipe_meal_type']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_recipe_meal_type']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_recipe_meal_type']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_recipe_meal_type']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_recipe_meal_type']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_recipe_meal_type']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_recipe_meal_type']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_recipe_meal_type']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_recipe_meal_type']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_recipe_meal_type']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_recipe_meal_type']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_recipe_meal_type']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_recipe_meal_type']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_recipe_meal_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_recipe_meal_type']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_recipe_meal_type']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_recipe_meal_type']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_recipe_meal_type']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_recipe_meal_type']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_recipe_meal_type']['field_api_classes'] = 0;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Taxonomy term: Weight */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  $handler->display->display_options['sorts']['weight']['relationship'] = 'field_recipe_meal_type_tid';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'recipe' => 'recipe',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Preferences: (field_recipe_status) */
  $handler->display->display_options['filters']['field_recipe_status_value']['id'] = 'field_recipe_status_value';
  $handler->display->display_options['filters']['field_recipe_status_value']['table'] = 'field_data_field_recipe_status';
  $handler->display->display_options['filters']['field_recipe_status_value']['field'] = 'field_recipe_status_value';
  $handler->display->display_options['filters']['field_recipe_status_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_recipe_status_value']['group'] = 2;
  /* Filter criterion: User: Current */
  $handler->display->display_options['filters']['uid_current']['id'] = 'uid_current';
  $handler->display->display_options['filters']['uid_current']['table'] = 'users';
  $handler->display->display_options['filters']['uid_current']['field'] = 'uid_current';
  $handler->display->display_options['filters']['uid_current']['relationship'] = 'uid';
  $handler->display->display_options['filters']['uid_current']['value'] = '1';
  $handler->display->display_options['filters']['uid_current']['group'] = 2;
  $handler->display->display_options['filters']['uid_current']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['uid_current']['expose']['label'] = 'Is the logged in user';
  $handler->display->display_options['filters']['uid_current']['expose']['use_operator'] = FALSE;
  $handler->display->display_options['filters']['uid_current']['expose']['operator'] = 'uid_current_op';
  $handler->display->display_options['filters']['uid_current']['expose']['identifier'] = 'uid_current';
  $handler->display->display_options['filters']['uid_current']['expose']['required'] = TRUE;
  $handler->display->display_options['filters']['uid_current']['expose']['remember'] = FALSE;
  $handler->display->display_options['filters']['uid_current']['expose']['multiple'] = FALSE;
  /* Filter criterion: Content: Promoted to front page */
  $handler->display->display_options['filters']['promote']['id'] = 'promote';
  $handler->display->display_options['filters']['promote']['table'] = 'node';
  $handler->display->display_options['filters']['promote']['field'] = 'promote';
  $handler->display->display_options['filters']['promote']['value'] = '1';
  $handler->display->display_options['filters']['promote']['group'] = 1;
  $handler->display->display_options['block_description'] = 'Recipes';

  /* Display: Prepared Meals */
  $handler = $view->new_display('block', 'Prepared Meals', 'block_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Prepared Meals';
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = 0;
  $handler->display->display_options['exposed_form']['options']['autosubmit_hide'] = 1;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '100';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'php',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_componets_meal_type' => 'field_componets_meal_type',
    'view_node' => 'view_node',
    'ops' => 'ops',
    'field_component_category_2' => 'field_component_category_2',
    'nid' => 'nid',
    'field_component_category_4' => 'field_component_category_4',
    'php' => 'php',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_componets_meal_type' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'view_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'ops' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_component_category_2' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_component_category_4' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'php' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  $handler->display->display_options['style_options']['empty_table'] = 0;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['title']['link_to_node'] = 0;
  /* Field: Content: Meal type */
  $handler->display->display_options['fields']['field_componets_meal_type']['id'] = 'field_componets_meal_type';
  $handler->display->display_options['fields']['field_componets_meal_type']['table'] = 'field_data_field_componets_meal_type';
  $handler->display->display_options['fields']['field_componets_meal_type']['field'] = 'field_componets_meal_type';
  $handler->display->display_options['fields']['field_componets_meal_type']['label'] = '';
  $handler->display->display_options['fields']['field_componets_meal_type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_componets_meal_type']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_componets_meal_type']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_componets_meal_type']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_componets_meal_type']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_componets_meal_type']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_componets_meal_type']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_componets_meal_type']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_componets_meal_type']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_componets_meal_type']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_componets_meal_type']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_componets_meal_type']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_componets_meal_type']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_componets_meal_type']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_componets_meal_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_componets_meal_type']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_componets_meal_type']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_componets_meal_type']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_componets_meal_type']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_componets_meal_type']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_componets_meal_type']['field_api_classes'] = 0;
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['view_node']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['view_node']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['html'] = 0;
  $handler->display->display_options['fields']['view_node']['element_type'] = 'div';
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_node']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['view_node']['hide_empty'] = 0;
  $handler->display->display_options['fields']['view_node']['empty_zero'] = 0;
  $handler->display->display_options['fields']['view_node']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['view_node']['text'] = 'View';
  /* Field: Flags: Flag link */
  $handler->display->display_options['fields']['ops']['id'] = 'ops';
  $handler->display->display_options['fields']['ops']['table'] = 'flag_content';
  $handler->display->display_options['fields']['ops']['field'] = 'ops';
  $handler->display->display_options['fields']['ops']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['fields']['ops']['label'] = '';
  $handler->display->display_options['fields']['ops']['exclude'] = TRUE;
  $handler->display->display_options['fields']['ops']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['ops']['alter']['text'] = 'Add';
  $handler->display->display_options['fields']['ops']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['ops']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['ops']['alter']['external'] = 0;
  $handler->display->display_options['fields']['ops']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['ops']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['ops']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['ops']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['ops']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['ops']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['ops']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['ops']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['ops']['alter']['html'] = 0;
  $handler->display->display_options['fields']['ops']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['ops']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['ops']['hide_empty'] = 0;
  $handler->display->display_options['fields']['ops']['empty_zero'] = 0;
  $handler->display->display_options['fields']['ops']['hide_alter_empty'] = 1;
  /* Field: Content: Category (level 2) */
  $handler->display->display_options['fields']['field_component_category_2']['id'] = 'field_component_category_2';
  $handler->display->display_options['fields']['field_component_category_2']['table'] = 'field_data_field_component_category_2';
  $handler->display->display_options['fields']['field_component_category_2']['field'] = 'field_component_category_2';
  $handler->display->display_options['fields']['field_component_category_2']['label'] = '';
  $handler->display->display_options['fields']['field_component_category_2']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_component_category_2']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_component_category_2']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_component_category_2']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_component_category_2']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_component_category_2']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_component_category_2']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_component_category_2']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_component_category_2']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_component_category_2']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_component_category_2']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_component_category_2']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_component_category_2']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_component_category_2']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_component_category_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_component_category_2']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_component_category_2']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_component_category_2']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_component_category_2']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_component_category_2']['field_api_classes'] = 0;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nid']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['nid']['link_to_node'] = 0;
  /* Field: Content: Category (level 4) */
  $handler->display->display_options['fields']['field_component_category_4']['id'] = 'field_component_category_4';
  $handler->display->display_options['fields']['field_component_category_4']['table'] = 'field_data_field_component_category_4';
  $handler->display->display_options['fields']['field_component_category_4']['field'] = 'field_component_category_4';
  $handler->display->display_options['fields']['field_component_category_4']['label'] = '';
  $handler->display->display_options['fields']['field_component_category_4']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_component_category_4']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_component_category_4']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_component_category_4']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_component_category_4']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_component_category_4']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_component_category_4']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_component_category_4']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_component_category_4']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_component_category_4']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_component_category_4']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_component_category_4']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_component_category_4']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_component_category_4']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_component_category_4']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_component_category_4']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_component_category_4']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_component_category_4']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_component_category_4']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_component_category_4']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_component_category_4']['field_api_classes'] = 0;
  /* Field: Category (PHP) */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['ui_name'] = 'Category (PHP)';
  $handler->display->display_options['fields']['php']['label'] = '';
  $handler->display->display_options['fields']['php']['exclude'] = TRUE;
  $handler->display->display_options['fields']['php']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['php']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['php']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['php']['alter']['external'] = 0;
  $handler->display->display_options['fields']['php']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['php']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['php']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['php']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['php']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['php']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['php']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['php']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['php']['alter']['html'] = 0;
  $handler->display->display_options['fields']['php']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['php']['hide_empty'] = 0;
  $handler->display->display_options['fields']['php']['empty_zero'] = 0;
  $handler->display->display_options['fields']['php']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_value'] = 'return (!empty($data->field_field_componets_meal_type[0][\'raw\'][\'tid\'])) ? $data->field_field_componets_meal_type[0][\'raw\'][\'tid\'] : 0;
/*return db_select(\'xoxo_fields_taxonomy\', \'t\')
  ->fields(\'t\', array(\'tid\'))
  ->condition(\'t.nid\', $row->nid, \'=\')
  ->condition(\'t.uid\', $GLOBALS[\'user\']->uid, \'=\')
  ->execute()
  ->fetchField();*/';
  $handler->display->display_options['fields']['php']['php_output'] = '<?php echo (!empty($data->field_field_componets_meal_type[0][\'rendered\'][\'#markup\'])) ? $data->field_field_componets_meal_type[0][\'rendered\'][\'#markup\'] : t(\'Unknown\'); //(!empty($value) ? taxonomy_term_title(taxonomy_term_load($value)) : t(\'No Type\')); 
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Field: Categorize (PHP) */
  $handler->display->display_options['fields']['php_1']['id'] = 'php_1';
  $handler->display->display_options['fields']['php_1']['table'] = 'views';
  $handler->display->display_options['fields']['php_1']['field'] = 'php';
  $handler->display->display_options['fields']['php_1']['ui_name'] = 'Categorize (PHP)';
  $handler->display->display_options['fields']['php_1']['label'] = '';
  $handler->display->display_options['fields']['php_1']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['php_1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['php_1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['php_1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['php_1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['php_1']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['php_1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['php_1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['php_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['php_1']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['php_1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['php_1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['php_1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['php_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php_1']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['php_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['php_1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['php_1']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['php_1']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_1']['php_value'] = 'return array(
  \'#type\' => \'cat\',
  \'#nid\' => $data->nid,
  \'#vid\' => 11
);';
  $handler->display->display_options['fields']['php_1']['php_output'] = '<?php echo render($value); ?>';
  $handler->display->display_options['fields']['php_1']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_1']['php_click_sortable'] = '';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Taxonomy term: Weight */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  $handler->display->display_options['sorts']['weight']['relationship'] = 'field_componets_meal_type_tid';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'component' => 'component',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Category (level 1) (field_component_category) */
  $handler->display->display_options['filters']['field_component_category_tid']['id'] = 'field_component_category_tid';
  $handler->display->display_options['filters']['field_component_category_tid']['table'] = 'field_data_field_component_category';
  $handler->display->display_options['filters']['field_component_category_tid']['field'] = 'field_component_category_tid';
  $handler->display->display_options['filters']['field_component_category_tid']['value'] = array(
    2423 => '2423',
  );
  $handler->display->display_options['filters']['field_component_category_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_component_category_tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['field_component_category_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_component_category_tid']['vocabulary'] = 'product_category';
  /* Filter criterion: Content: Available as prepared meal (field_component_status) */
  $handler->display->display_options['filters']['field_component_status_value']['id'] = 'field_component_status_value';
  $handler->display->display_options['filters']['field_component_status_value']['table'] = 'field_data_field_component_status';
  $handler->display->display_options['filters']['field_component_status_value']['field'] = 'field_component_status_value';
  $handler->display->display_options['filters']['field_component_status_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['block_description'] = 'Prepared Meals';

  /* Display: Search Prepared Meals */
  $handler = $view->new_display('block', 'Search Prepared Meals', 'block_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Search Prepared Meals';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'php',
      'rendered' => 0,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'view_node' => 'view_node',
    'ops' => 'ops',
    'field_component_category_2' => 'field_component_category_2',
    'field_component_category_4' => 'field_component_category_4',
    'nothing' => 'nothing',
    'php' => 'php',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'view_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'ops' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_component_category_2' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_component_category_4' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nothing' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'php' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  $handler->display->display_options['style_options']['empty_table'] = 0;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: View area */
  $handler->display->display_options['footer']['view']['id'] = 'view';
  $handler->display->display_options['footer']['view']['table'] = 'views';
  $handler->display->display_options['footer']['view']['field'] = 'view';
  $handler->display->display_options['footer']['view']['empty'] = TRUE;
  $handler->display->display_options['footer']['view']['view_to_insert'] = 'recipes_components:block_2';
  $handler->display->display_options['footer']['view']['inherit_arguments'] = 0;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = 'No result';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  $handler->display->display_options['empty']['area']['tokenize'] = 0;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['title']['link_to_node'] = 0;
  /* Field: Flags: Flag link */
  $handler->display->display_options['fields']['ops']['id'] = 'ops';
  $handler->display->display_options['fields']['ops']['table'] = 'flag_content';
  $handler->display->display_options['fields']['ops']['field'] = 'ops';
  $handler->display->display_options['fields']['ops']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['fields']['ops']['label'] = '';
  $handler->display->display_options['fields']['ops']['exclude'] = TRUE;
  $handler->display->display_options['fields']['ops']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['ops']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['ops']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['ops']['alter']['external'] = 0;
  $handler->display->display_options['fields']['ops']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['ops']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['ops']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['ops']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['ops']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['ops']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['ops']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['ops']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['ops']['alter']['html'] = 0;
  $handler->display->display_options['fields']['ops']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['ops']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['ops']['hide_empty'] = 0;
  $handler->display->display_options['fields']['ops']['empty_zero'] = 0;
  $handler->display->display_options['fields']['ops']['hide_alter_empty'] = 1;
  /* Field: Content: Category (level 2) */
  $handler->display->display_options['fields']['field_component_category_2']['id'] = 'field_component_category_2';
  $handler->display->display_options['fields']['field_component_category_2']['table'] = 'field_data_field_component_category_2';
  $handler->display->display_options['fields']['field_component_category_2']['field'] = 'field_component_category_2';
  $handler->display->display_options['fields']['field_component_category_2']['label'] = '';
  $handler->display->display_options['fields']['field_component_category_2']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_component_category_2']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_component_category_2']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_component_category_2']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_component_category_2']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_component_category_2']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_component_category_2']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_component_category_2']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_component_category_2']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_component_category_2']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_component_category_2']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_component_category_2']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_component_category_2']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_component_category_2']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_component_category_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_component_category_2']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_component_category_2']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_component_category_2']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_component_category_2']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_component_category_2']['field_api_classes'] = 0;
  /* Field: Content: Category (level 4) */
  $handler->display->display_options['fields']['field_component_category_4']['id'] = 'field_component_category_4';
  $handler->display->display_options['fields']['field_component_category_4']['table'] = 'field_data_field_component_category_4';
  $handler->display->display_options['fields']['field_component_category_4']['field'] = 'field_component_category_4';
  $handler->display->display_options['fields']['field_component_category_4']['label'] = '';
  $handler->display->display_options['fields']['field_component_category_4']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_component_category_4']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_component_category_4']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_component_category_4']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_component_category_4']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_component_category_4']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_component_category_4']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_component_category_4']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_component_category_4']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_component_category_4']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_component_category_4']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_component_category_4']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_component_category_4']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_component_category_4']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_component_category_4']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_component_category_4']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_component_category_4']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_component_category_4']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_component_category_4']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_component_category_4']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_component_category_4']['field_api_classes'] = 0;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'Add';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nothing']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nothing']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nothing']['element_class'] = 'flag';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nothing']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nothing']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nothing']['hide_alter_empty'] = 0;
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = '';
  $handler->display->display_options['fields']['php']['exclude'] = TRUE;
  $handler->display->display_options['fields']['php']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['php']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['php']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['php']['alter']['external'] = 0;
  $handler->display->display_options['fields']['php']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['php']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['php']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['php']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['php']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['php']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['php']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['php']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['php']['alter']['html'] = 0;
  $handler->display->display_options['fields']['php']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['php']['hide_empty'] = 0;
  $handler->display->display_options['fields']['php']['empty_zero'] = 0;
  $handler->display->display_options['fields']['php']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_value'] = 'return 1;';
  $handler->display->display_options['fields']['php']['php_output'] = '<?php echo \'Search Result\'; ?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'component' => 'component',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Category (level 1) (field_component_category) */
  $handler->display->display_options['filters']['field_component_category_tid']['id'] = 'field_component_category_tid';
  $handler->display->display_options['filters']['field_component_category_tid']['table'] = 'field_data_field_component_category';
  $handler->display->display_options['filters']['field_component_category_tid']['field'] = 'field_component_category_tid';
  $handler->display->display_options['filters']['field_component_category_tid']['value'] = array(
    2423 => '2423',
  );
  $handler->display->display_options['filters']['field_component_category_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_component_category_tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['field_component_category_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_component_category_tid']['vocabulary'] = 'product_category';
  /* Filter criterion: Content: Category (level 2) (field_component_category_2) */
  $handler->display->display_options['filters']['field_component_category_2_tid']['id'] = 'field_component_category_2_tid';
  $handler->display->display_options['filters']['field_component_category_2_tid']['table'] = 'field_data_field_component_category_2';
  $handler->display->display_options['filters']['field_component_category_2_tid']['field'] = 'field_component_category_2_tid';
  $handler->display->display_options['filters']['field_component_category_2_tid']['operator'] = 'not';
  $handler->display->display_options['filters']['field_component_category_2_tid']['value'] = array(
    2792 => '2792',
  );
  $handler->display->display_options['filters']['field_component_category_2_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_component_category_2_tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['field_component_category_2_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_component_category_2_tid']['vocabulary'] = 'product_category_level_2_';
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'allwords';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['required'] = 1;
  $handler->display->display_options['filters']['title']['expose']['remember'] = 1;
  $handler->display->display_options['filters']['title']['expose']['multiple'] = FALSE;
  /* Filter criterion: Flags: Flagged */
  $handler->display->display_options['filters']['flagged']['id'] = 'flagged';
  $handler->display->display_options['filters']['flagged']['table'] = 'flag_content';
  $handler->display->display_options['filters']['flagged']['field'] = 'flagged';
  $handler->display->display_options['filters']['flagged']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['filters']['flagged']['value'] = '0';
  $handler->display->display_options['filters']['flagged']['group'] = 1;
  /* Filter criterion: Content: Name (field_component_name) */
  $handler->display->display_options['filters']['field_component_name_value']['id'] = 'field_component_name_value';
  $handler->display->display_options['filters']['field_component_name_value']['table'] = 'field_data_field_component_name';
  $handler->display->display_options['filters']['field_component_name_value']['field'] = 'field_component_name_value';
  $handler->display->display_options['filters']['field_component_name_value']['operator'] = '!=';
  $handler->display->display_options['filters']['field_component_name_value']['group'] = 1;
  /* Filter criterion: Content: Available as prepared meal (field_component_status) */
  $handler->display->display_options['filters']['field_component_status_value']['id'] = 'field_component_status_value';
  $handler->display->display_options['filters']['field_component_status_value']['table'] = 'field_data_field_component_status';
  $handler->display->display_options['filters']['field_component_status_value']['field'] = 'field_component_status_value';
  $handler->display->display_options['filters']['field_component_status_value']['value'] = array(
    0 => '0',
  );
  $handler->display->display_options['filters']['field_component_status_value']['group'] = 2;
  /* Filter criterion: Content: Available as prepared meal (field_component_status) */
  $handler->display->display_options['filters']['field_component_status_value_1']['id'] = 'field_component_status_value_1';
  $handler->display->display_options['filters']['field_component_status_value_1']['table'] = 'field_data_field_component_status';
  $handler->display->display_options['filters']['field_component_status_value_1']['field'] = 'field_component_status_value';
  $handler->display->display_options['filters']['field_component_status_value_1']['operator'] = 'empty';
  $handler->display->display_options['filters']['field_component_status_value_1']['group'] = 2;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 3;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: User: Current */
  $handler->display->display_options['filters']['uid_current']['id'] = 'uid_current';
  $handler->display->display_options['filters']['uid_current']['table'] = 'users';
  $handler->display->display_options['filters']['uid_current']['field'] = 'uid_current';
  $handler->display->display_options['filters']['uid_current']['relationship'] = 'uid';
  $handler->display->display_options['filters']['uid_current']['value'] = '1';
  $handler->display->display_options['filters']['uid_current']['group'] = 3;
  $handler->display->display_options['block_description'] = 'Prepared Meals';
  $export['recipes_components'] = $view;

  return $export;
}
