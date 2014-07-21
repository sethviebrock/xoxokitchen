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
//watchdog('jasonstest', '$query = <pre>' . print_r($query, TRUE) . '</pre>');
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
//watchdog('jasonstest', '$tbls = <pre>' . print_r($tbls, TRUE) . '</pre>');
  if (array_key_exists($tn, $tbls)) {
    $cols[] = sprintf($col, $n);
  }
  if (array_key_exists($tb, $tbls)) {
    $cols[] = sprintf($col, $b);
  }
  if (array_key_exists($td, $tbls)) {
    $cols[] = sprintf($col, $d);
  }
//watchdog('jasonstest', '$cols = <pre>' . print_r($cols, TRUE) . '</pre>');
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
//watchdog('jasonstest', '$o = <pre>' . print_r($o, TRUE) . '</pre>');
  foreach ($o as $array) {
//watchdog('jasonstest', '$array = <pre>' . print_r($array, TRUE) . '</pre>');
    $html .= sprintf($option, $array->nid, $array->field_component_brand_value, $array->ing, $array->value);
  }
  if (empty($html)) {
    $html .= sprintf($option, 0, 0, $name, $name);
//watchdog('jasonstest', '$html 2 = "@html"', array('@html' => $html));
  }
//watchdog('jasonstest', '$html 3 = "@html"', array('@html' => $html));
  return $html;
}
