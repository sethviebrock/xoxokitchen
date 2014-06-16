<?php
function _xoxo_search_brand_value($brand, $input, $form_state) {
  $o = $brand['#options'];
  $s = 0;
  if ($input) {
    $s = $input;
  }
  else if (isset($brand['#default_value'])){
    $s = $brand['#default_value'];
  }
  $s = is_array($s) ? reset($s) : $s;
  if (!array_key_exists((int) $s, $o)) {
    return key($o);
  }
  return $s;
}
function _xoxo_search_brand_id($brand) {
  return $brand != '-' ? $brand : '';
}
function _xoxo_search_hacked_brand($brand) {
  $brand['#theme'] = 'select';
  $brand['#options'] = $brand['#hacked_options'];
  unset($brand['#hacked_options']);
  return $brand;
}
