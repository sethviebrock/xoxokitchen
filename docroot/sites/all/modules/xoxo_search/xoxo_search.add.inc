<?php
function _xoxo_search_add_submit($add, &$form_state) {
  $f = 'field_recipe_ingredients';
  $p = array('values', 'language');
  $l = drupal_array_get_nested_value($form_state, $p);
  array_pop($p);
  array_push($p, $f, $l);
  $i = drupal_array_get_nested_value($form_state, $p);
  array_walk($i, '_xoxo_search_add');
  drupal_array_set_nested_value($form_state, $p, $i);
}
function _xoxo_search_add(&$add = array()) {
  if (!is_array($add)) {
    return;
  }
  $t = drupal_array_get_nested_value($add, array('add_name'));
  if(empty($t)) {
    return;
  }
  $nid = drupal_array_get_nested_value($add, array('nid'));
  if ($nid) {
    global $user;
    $node = node_load($nid);
    if ($node->uid == $user->uid || $user->uid == 1) {
      $node->title = $t;
      node_save($node);
      return;
    }
  }
  drupal_array_set_nested_value(
    $add,
    array('nid'),
    _xoxo_fields_create_custom_component($t, array())
  );
}
