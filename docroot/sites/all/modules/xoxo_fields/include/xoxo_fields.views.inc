<?php
// info: xoxo_fields.views.inc, v1.0 2012/5/22 Segei Churilo

function xoxo_fields_views_data() {
  //Name
  $data['xoxo_names']['table']['group'] = t('XOXO Kitchen');
  $data['xoxo_names']['table']['join'] = array(
    'node' => array(
      'left_table' => 'field_data_field_component_name',
      'left_field' => 'field_component_name_value',
      'field' => 'aid',
    ),
  );
  $data['xoxo_names']['value'] = array(
    'title' => t('Name'),
    'help' => t('Name as a string.'), 
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  // Brand
  $data['xoxo_brands']['table']['group'] = t('XOXO Kitchen');
  $data['xoxo_brands']['table']['join'] = array(
    'node' => array(
      'left_table' => 'field_data_field_component_brand',
      'left_field' => 'field_component_brand_value',
      'field' => 'bid',
    ),
  );
  $data['xoxo_brands']['value'] = array(
    'title' => t('Brand'),
    'help' => t('Brand name.'), 
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  
  // Manufacrurer
  $data['xoxo_manufacturers']['table']['group'] = t('XOXO Kitchen');
  $data['xoxo_manufacturers']['table']['join'] = array(
    'node' => array(
      'left_table' => 'field_data_field_component_manufacturer',
      'left_field' => 'field_component_manufacturer_value',
      'field' => 'mid',
    ),
  );
  $data['xoxo_manufacturers']['value'] = array(
    'title' => t('Manufacturer'),
    'help' => t('Manufacturer name.'), 
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  return $data;
}
