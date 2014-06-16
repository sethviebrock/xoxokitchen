<?php
function _xoxo_search_tid($unit_name) {
  /*$type = 'taxonomy_term';
  $q = new EntityFieldQuery;
  $q->entityCondition('entity_type', $type);
  $q->propertyCondition('name', $unit_name);
  $q->range(0, 1);
  $res = $q->execute();
  if (!empty($res)) {
    return key($res[$type]);
  }*/
  $vid = 4;
  $q = db_select('taxonomy_term_data', 'terms');
  $q->leftJoin('field_data_field_unit_synonims', 'syns', 'terms.tid=syns.entity_id');
  $or = db_or()
    ->condition('syns.field_unit_synonims_value', $unit_name)
    ->condition('terms.name', $unit_name);
  $q->condition($or);
  $q->condition('terms.vid', $vid);
  $q->range(0, 1);
  $q->addField('terms', 'tid');
  return $q->execute()->fetchField();
}
function _xoxo_search_name_id($name) {
  return db_select('xoxo_names', 'x')
    ->condition('x.value', $name)
    ->fields('x', array('aid'))
    ->range(0, 1)
    ->execute()
    ->fetchField();
}
function _xoxo_search_nids_query($name = FALSE, $brand = FALSE, $description = FALSE) {
  $name = trim($name);
  $brand = trim($brand);
  $description = trim($description);
  $q = db_select('node', 'n');
  $q->join('field_data_field_component_brand', 'brand', 'n.nid=brand.entity_id');
  if ($name) {
    $q->join('field_data_field_component_name', 'name', 'n.nid=name.entity_id');
    $q->join('xoxo_names', 'x', 'x.aid=name.field_component_name_value');
    $q->groupBy('x.value');
    $words = preg_split(XOXO_SEARCH_SEPARATOR, $name);
    foreach ($words as $word) {
      $p = '[[:<:]]' . $word . '[[:>:]]';
      $q->condition('x.value', $p, 'REGEXP');
    }
  }
  if ($brand && $brand != '-') {
    $q->join('xoxo_brands', 'brand_string', 'brand_string.bid=brand.field_component_brand_value');
    $q->groupBy('brand.field_component_brand_value');
    $q->condition('brand.field_component_brand_value', $brand);
  }
  if ($description) {
    $q->join('field_data_field_component_description', 'description', 'n.nid=description.entity_id');
    $q->groupBy('description.field_component_description_value');
    $words = preg_split(XOXO_SEARCH_SEPARATOR, $description);
    foreach ($words as $word) {
      $p = '[[:<:]]' . $word . '[[:>:]]';
      $q->condition('description.field_component_description_value', $p, 'REGEXP');
    }
  }
  $q = _xoxo_search_filter_out($q);
  return $q;
}
function xoxo_search_descriptions($s = '') {
  $b = preg_split(XOXO_SEARCH_SEPARATOR, $s);
  $s = end($b);
  if (!_xoxo_search_long($s)) {
    return array();
  }
  $p = '[[:<:]]' . db_like($s);
  $q = db_select('field_data_field_component_description', 'description');
  $q->addExpression('GROUP_CONCAT(DISTINCT field_component_description_value SEPARATOR :s)', 'grouped_value', array(':s' => ' '));
  $q->where('LOWER(description.field_component_description_value) REGEXP :p', array(':p' => $p));
  $q->join('node', 'n', 'n.nid=description.entity_id');
  $q = _xoxo_search_filter_out($q);
  $nr = $q->execute()->fetchField();
  $w = array_filter(array_unique(explode(' ', $nr)), '_xoxo_search_long');
  array_walk($w, '_xoxo_search_starts', $s);
  $w = array_filter($w);
  usort($w, '_xoxo_search_length');
  array_walk($w, '_xoxo_search_prepend', $b);
  $r = array_combine($w, $w);
  return $r;
}

/**
 * Propositions for components search (by name).
 */
function _xoxo_search_names($s = '') {
  $b = preg_split(XOXO_SEARCH_SEPARATOR, trim($s));
  $s = array_pop($b);
  if (!_xoxo_search_long($s)) {
    return array();
  }
  $p = '[[:<:]]' . db_like($s);
  $q = db_select('xoxo_names', 'x');
  $q->addExpression(
    'GROUP_CONCAT(DISTINCT x.value SEPARATOR :s)',
    'grouped_value',
    array(':s' => ' '));
  $q->condition('x.value', $p, 'REGEXP');
  foreach($b as $word) {
    $reg = '[[:<:]]' . db_like($word) . '[[:>:]]';
    $q->condition('x.value', $reg, 'REGEXP');
  }
  $q->join('field_data_field_component_name', 'name', 'x.aid=name.field_component_name_value');
  $q->join('node', 'n', 'n.nid=name.entity_id');
  $q = _xoxo_search_filter_out($q);
  $nr = $q->execute()->fetchField();
  $w = array_filter(array_unique(explode(' ', $nr)), '_xoxo_search_long');
  array_walk($w, '_xoxo_search_starts', $s);
  $w = array_filter($w);
  usort($w, '_xoxo_search_length');
  array_walk($w, '_xoxo_search_prepend', $b);
  $r = empty($w) ? array() : array_combine($w, $w);
  return $r;
}
function _xoxo_search_long($s = '') {
  return strlen($s) > 2;
}
function _xoxo_search_starts(&$string, $id, $start) {
  $string = strstr(strtolower($string), strtolower($start)) ? $string : FALSE;
}
function _xoxo_search_length($s1, $s2) {
  return strlen($s1) - strlen($s2);
}

/**
 * Prepends prefix to the string & removes commas.
 */
function _xoxo_search_prepend(&$string, $id, $prefix = array()) {
  array_push($prefix, $string);
  $string = implode(' ', $prefix);
  $string = str_replace(',', '', $string);
}
function _xoxo_search_create_custom_component($title) {
  if(!$title) {
    return FALSE;
  }

  global $user;
  $q = "
    SELECT
      n.nid AS nid
    FROM
      node n
    WHERE
      n.uid = :uid
        AND
      n.type = 'component'
        AND
      n.title = :title";
  $nid = db_query(
    $q,
    array(
      ':title' => check_plain($title),
      ':uid' => $user->uid,
    )
  )->fetchField();

  if($nid) {
    return $nid;
  }

  // create component
  $node = new stdClass();
  $node->type = 'component';
  $node->title = check_plain($title);
 //  $node->field_component_status[LANGUAGE_NONE][0]['value'] = 0; // component is not available
  $node->field_component_category[LANGUAGE_NONE][0]['tid'] = 2423; // food category
  $node->field_component_category_2[LANGUAGE_NONE][0]['tid'] = 2653; // not tabacco category
  $node->field_component_category_3[LANGUAGE_NONE][0]['tid'] = 2432; // other category (class)
  $node->field_component_category_4[LANGUAGE_NONE][0]['tid'] = 2432;
  $node->field_component_category_4[LANGUAGE_NONE][0]['tid'] = 2432;
  $node->field_component_name[LANGUAGE_NONE][0]['value'] = $title;
  $node->uid = $user->uid;
  $node->status = 0;
  $node->language = LANGUAGE_NONE;
  node_object_prepare($node);
  $node = node_submit($node);
  node_save($node);

  if(!empty($node->nid)) {
    return $node->nid;
  }
}
