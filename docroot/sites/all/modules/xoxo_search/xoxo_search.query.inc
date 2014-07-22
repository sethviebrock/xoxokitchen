<?php
function _xoxo_search_filter_out($query) {
  global $user;
  $query->join('field_data_field_component_category', 'fc1', 'n.nid = fc1.entity_id');
  $query->condition('fc1.field_component_category_tid', XOXO_SEARCH_FBT); 
  $query->join('field_data_field_component_category_2', 'fc2', 'n.nid = fc2.entity_id');
  $query->condition('fc2.field_component_category_2_tid', XOXO_SEARCH_TSA, '<>');
  $query->condition(db_or()->condition('n.status', 1)->condition('n.uid', $user->uid));
  return $query;
}
function _xoxo_search_nids_html($query, $name, $amount = 0, $limit = 20) {
  db_query("SET OPTION SQL_BIG_SELECTS=1");
  $html = '';
  list($n, $b, $d, $tn, $tb, $td) = array(
    'x.value',
    'brand_string.value',
    'description.field_component_description_value',
    'x',
    'brand_string',
    'description'
  );
  $option = '<li nid="%s" bid="%s">%s<span class="ing-name">%s</span></li>';
  $col = 'IFNULL(%s, :s)';
  $exp = 'CONCAT_WS(:s, %s)';
  $cols = array();
  $tbls = $query->getTables();
  if (array_key_exists($tn, $tbls)) {
    $cols[] = sprintf($col, $n);
  }
  if (array_key_exists($tb, $tbls)) {
    $cols[] = sprintf($col, $b);
  }
  if (array_key_exists($td, $tbls)) {
    $cols[] = sprintf($col, $d);
  }
  if (empty($cols)) {
    return $html;
  }
  $exp = sprintf($exp, implode(', ', $cols));
  $query->addExpression($exp, 'ing', array(':s' => ' '));
  // $query->join('field_data_field_component_brand', 'brand', 'brand.entity_id=name.entity_id');
  $query->range($amount, $limit);
  $query->addField('n', 'nid');
  $query->addField('x', 'value');
  $query->addField('brand', 'field_component_brand_value');
  $o = $query->execute()->fetchAll();
  foreach ($o as $array) {
    $html .= sprintf($option, $array->nid, $array->field_component_brand_value, $array->ing, $array->value);
  }
  if (empty($html)) {
    $nid = _xoxo_search_create_component($name);
    $html .= sprintf($option, $nid, 1, $name, $name);
  }
  return $html;
}

/**
 * Creates a new component.
 *
 * @param string $name
 *   The name of the component to create.
 *
 * @return integer
 *   The node ID of the newly created component.
 */
function _xoxo_search_create_component($name) {
  $node = new stdClass();
  $node->type = 'component';
  // Prepare the node object for editing and fill in a few default values.
  node_object_prepare($node);
  $node->language = LANGUAGE_NONE;

  // Set the title and body of the node to the name of the ingredient.
  $node->title = $name;
  $node->body[$node->language][0]['value'] = $name;

  // Save the node.
  node_save($node);
  return $node->nid;
}
