<?php
/*
Ingredients.
*/
class XOXOIngredients {
  function __construct($form = FALSE) {
    $this->q = db_select('node', 'n')
      ->condition('n.type', 'component');
    $this->f = array();
  }
  function name($val = FALSE) {
    if ($val) {
      $this->name = $val;
      $this->join('field_data_field_component_name', 'name_id', 'n.nid=name_id.entity_id');
      $this->join('xoxo_names', 'name', 'name.aid=name_id.field_component_name_value');
      $this->condition('name.value', $val);
    }
    elseif (isset($this->nid)) {
      $nid = $this->nid;
      $q = db_select('xoxo_names', 'name');
      $q->join('field_data_field_component_name', 'name_id', 'name_id.field_component_name_value=name.aid');
      $q->condition('name_id.entity_id', $nid);
      $q->fields('name', array('value'));
      $a = $q->execute();
      $val = $a->fetchField();
    }
    $this->f['name'] = array(
      '#type' => 'textfield',
      '#autocomplete_path' => 'xoxo-search/names',
      '#ajax' => array('callback' => '_xoxo_search_ajax'),
      '#weight' => -1
    );
/*    if ($val) {
      $this->f['name']['#value'] = $val;
    }*/
    return $val;
  }
  function name_id($id = FALSE) {
    if ($id) {
      $this->join('field_data_field_component_name', 'name_id', 'n.nid=name_id.entity_id');
      $this->condition('name_id.field_component_name_value', $id);
    }
    elseif (isset($this->name)) {
      $n = $this->name;
      $q = db_select('xoxo_names', 'x');
      $q->condition('x.value', $n);
      $q->fields('x', array('aid'));
      $a = $q->execute();
      $id = $a->fetchField();
    }
    $this->name_id = $id;
    $this->f['name_id'] = array(
      '#type' => 'hidden',
      '#default_value' => $id
    );
    return $id;
  }
  function brand($id = FALSE) {
    if ($id) {
      $this->join('field_data_field_component_brand', 'brand', 'brand.entity_id=n.nid');
      $this->condition('brand.field_component_brand_value', $id);
    }
    elseif(isset($this->name_id)) {
      $n = $this->name_id;
    }
    $this->brand = $id;
    $this->f['brand'] = _xoxo_search_brand_form($this->name_id());
//    $this->f['brand'] = array(
//      '#type' => 'select',
//      '#value' => $id,
//      '#options' => xoxo_search_only_brands($this->name)
//    );
    return $id;
  }
  function nid($id = FALSE) {
    if ($id) {
      $this->condition('n.nid', $id);
    }
    elseif(isset($this->name)){
      $this->uncondition('n.nid');
      $q = clone $this->q;
      $id = (int) $q->fields('n', array('nid'))->range(0, 1)->execute()->fetchField();
    }
    $this->nid = $id;
    $this->f['nid'] = array(
      '#type' => 'value',
      '#size' => 3
    );
    if ($id) {
      $this->f['nid']['#value'] = $id;
    }
    return $id;
  }
  function amount($amount = FALSE, $unit = FALSE) {
    $this->f['amount'] = array(
      '#default_value' => $amount,
      '#type' => 'textfield',
      '#weight' => 5,
      '#size' => 3
    );
    $this->f['unit'] = array(
      '#type' => 'select',
      '#weight' => 6
    );
    $vocabularies = taxonomy_vocabulary_get_names();
    $vid = $vocabularies['uom']->vid;
    $terms = taxonomy_get_tree($vid);
    foreach ($terms as $term) {
      $this->f['unit']['#options'][$term->tid] = !empty($term) ? taxonomy_term_title($term) : '';
    }
    return $this;
  }
  function form($id = FALSE) {
    foreach (array_keys($this->f) as $k) {
      $this->ajax($k, $id);
    }
    return $this->f;
  }
  function nodes() {
    $q = clone $this->q;
    $q->fields('n', array('nid', 'title'));
    $q->range(0, 10);
    $a = $q->execute();
    return $a->fetchAllKeyed();
  }
  private function join($table, $alias, $condition) {
    $this->unjoin($table);
    $this->q->join($table, $alias, $condition);
  }
  private function unjoin($table) {
    $t =& $this->q->getTables();
    foreach(array_keys($t) as $k) {
      if ($t[$k]['table'] == $table) { unset($t[$k]); }
    }
  }
  private function condition($col, $val) {
    $this->uncondition($col);
    $this->q->condition($col, $val);
  }
  private function uncondition($col) {
    $c =& $this->q->conditions();
    foreach (array_keys($c) as $k) {
      if ($c[$k]['field'] == $col) { unset($c[$k]); }
    }
  }
  private function ajax($key, $id) {
    if(isset($this->f[$key]['#ajax'])) {
      $this->f[$key]['#ajax']['wrapper'] = $id;
    }
  }
}
/*
func property(val):
if val:
	filter
else if args:
	set val get
set property val
alter form
return val
*/
