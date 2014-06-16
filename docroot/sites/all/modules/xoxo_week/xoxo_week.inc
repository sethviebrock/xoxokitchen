<?php
//Current week (HTML string).
//Value from first node field item.
function _xoxo_first_field_value($node, $field_name, $key = 'value') {
  if (!is_object($node)) {
    $node = node_load($node);
  }
  else if (!property_exists($node, $field_name) && property_exists($node, 'nid')) {
    $node = node_load($node->nid);
  }
  if (is_object($node) && property_exists($node, $field_name)) {
    $items = (array) field_get_items('node', $node, $field_name);
    $item = (array) reset($items);
    return array_key_exists($key, $item) ? $item[$key] : FALSE;
  }
}
//Value for grid cell.
function _xoxo_week_event_value($tid, $time, $nid = FALSE) {
  $content = '';
  $term = taxonomy_term_load($tid);
  $t = $term ? taxonomy_term_title($term) : '';
  $args = array(
    'field_event_date' => $time,
    'field_event_category' => $tid,
    '@date' => date('d/m/Y', $time),
    '@category' => $t
  );
  if($nid) {
    $node = node_load($nid);
    $items = field_get_items('node', $node, 'field_event_recipes');
    $status = (count($items) < 5) && _xoxo_week_is_actual($time);
    $exceptions = array(
      'item-id-' => array(),
    );
    foreach(($items ? $items : array()) as $item) {
      $content .= _xoxo_week_recipe_value($nid, $item['nid'], $status, $time);
      $exceptions['item-id-'][] = $item['nid'];
    }
    $args['nid'] = $nid;
    if(!empty($exceptions['item-id-'])) {
      $args['@exceptions@'] = $exceptions;
    }
  }
  else {
    $status = _xoxo_week_is_actual($time);
  }
  return theme(
    'views_drag_drop_droppable',
    array(
      'preset' => 'calendar',
      'args' => $args,
      'content' => $content,
      'status' => $status,
    )
  );
}
/*function _xoxo_week_time($view, $property, $field_name) {
  $time =
    isset($view->argument[$field_name . '_value']->{$property})
    ? $view->argument[$field_name . '_value']->{$property}
    : FALSE;
  if($time) {
    return strtotime(date_format(
      $time,
      'Y-m-d'
    ));
  }
}*/
function _xoxo_week_recipe_value($event_id, $recipe_id, $event_status, $time) {
  $recipe = node_load($recipe_id);
  $title = _xoxo_fields_get_item_title($recipe);
  $status = _xoxo_week_is_actual($time) ? 1 : 0;
  return theme('views_drag_drop_draggable', array(
    'preset' => 'calendar',
    'args' => array(
      'field_event_recipes' => $recipe_id,
      '@recipe_title' => $title,
      '@date2' => $time,
      '@type' => $recipe->type,
    ),
    'content' => $title,
    'status' => $status,
    'vibrant' => TRUE,
    'options' => array('nid' => $event_id, 'field' => 'field_event_recipes', 'value' => $recipe_id)
  ));
}
function _xoxo_week_ajax($date = FALSE, $ajax = FALSE) {
/*  $args = $_REQUEST['_xoxo_week_ajax_args'];
  $day = 60 * 60 * 24;
  $next = _xoxo_week_sun_sat(_xoxo_week_timestamp($args['view_arg']) + 7 * $day);
  $prev = _xoxo_week_sun_sat(_xoxo_week_timestamp($args['view_arg']) - 7 * $day);
  $new_sets = array('next_week' => $next, 'prev_week' => $prev);
  drupal_json_output(array('view' => $view, 'new_view_args' => $args, 'new_sets' => $new_sets));*/
  $view = views_embed_view('kitchen', 'page', $date);
  if ($ajax == 'ajax') {
    $commands = array();
    $commands[] = ajax_command_replace('.view-kitchen', $view);
    ajax_deliver(array('#type' => 'ajax', '#commands' => $commands));
  }
  else {
    return $view;
  }
}
//Week as interval between sunday and saturday (string). $time - any second (timestamp) in required week.
function _xoxo_week_sun_sat($timestamp) {
  return implode('--', array(
    _xoxo_week_sun('Y-m-d', $timestamp),
    _xoxo_week_sat('Y-m-d', $timestamp)
  ));
}
//A timestamp in provided interval ($string).
function _xoxo_week_timestamp($string) {
  $handler = new date_sql_handler();
  $array = $handler->arg_range($string);
  return strtotime($array[0]->format('Y-m-d'));
}
//Sunday timestamp. $timestamp - any second in corresponding week.
function _xoxo_week_sun($format = 'Y-m-d', $timestamp = FALSE) {
  $timestamp = !$timestamp ? time() : $timestamp;
  if (date('w', $timestamp) == 0) {
    $stamp = strtotime('today', $timestamp);
  }
  else {
    $stamp = strtotime('last Sunday', $timestamp);
  }
  return $format ? date($format, $stamp) : $stamp;
}
//Saturday timestamp. $timestamp - any second in corresponding week.
function _xoxo_week_sat($format = 'Y-m-d', $timestamp = FALSE) {
  $week = 60 * 60 * 24 * 6;
  $stamp = _xoxo_week_sun(FALSE, $timestamp) + $week;
  return $format ? date($format, $stamp) : $stamp;
}
//Does the time (timestamp) belons to week prior to current week.
function _xoxo_week_is_actual($time) {
  if (ctype_digit($time)) {
    return 
      _xoxo_week_sun(FALSE, $time) < _xoxo_week_sun(FALSE, FALSE)
      ? FALSE
      : TRUE;
  }
  else {
    return FALSE;
  }
}
