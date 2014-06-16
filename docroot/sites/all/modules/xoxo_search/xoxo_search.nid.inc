<?php
function _xoxo_search_brand($nid = FALSE) {
  return db_select('field_data_field_component_brand', 'f')
    ->condition('f.entity_id', $nid)
    ->fields('f', array('field_component_brand_value'))
    ->execute()
    ->fetchField();
}
function _xoxo_search_name($nid = FALSE) {
  $q = db_select('field_data_field_component_name', 'f');
  $q->join('xoxo_names', 'x', 'x.aid=f.field_component_name_value');
  return $q->condition('f.entity_id', $nid)
    ->fields('x', array('value'))
    ->range(0, 1)
    ->execute()
    ->fetchField();
}
function _xoxo_search_description($nid = FALSE) {
  return db_select('field_data_field_component_description', 'f')
    ->condition('f.entity_id', $nid)
    ->fields('f', array('field_component_description_value'))
    ->execute()
    ->fetchField();
}
