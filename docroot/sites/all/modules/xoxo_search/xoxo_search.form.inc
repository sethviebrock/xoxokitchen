<?php
function _xoxo_search_title($form) {
  return array(
    '#tag' => 'div',
    '#type' => 'html_tag',
    '#attributes' => array('class' => array('xoxo-search-title')),
    '#weight' => -1,
    '#value' => t(XOXO_SEARCH_ING_TITLE, array('!delta' => $form['#delta'] + 1))
  );
}
function _xoxo_search_amount($form) {
  return array(
    '#tag' => 'div',
    '#type' => 'html_tag',
    '#attributes' => array('class' => array('xoxo-search-amount-title')),
    '#weight' => 0,
    '#value' => t(XOXO_SEARCH_ING_AMOUNT)
  );
}
function _xoxo_search_refresh_form($form_id) {
  $path = drupal_get_path('module', 'xoxo_search') . '/';
  return array(
    '#type' => 'textfield',
    '#attributes' => array('class' => array('search-refresh')),
    '#attached' => array('css' => array($path . 'xoxo_search.css')),
    '#ajax' => array(
      'callback' => '_xoxo_search_refresh',
      'progress' => array('type' => FALSE),
      'wrapper' => $form_id,
      'event' => 'click'
    )
  );
}
function _xoxo_search_options_count($form = FALSE, $form_state = FALSE) {
  return array(
    '#type' => 'hidden',
    '#attributes' => array('class' => array('xoxo-search-options-count'))
  );
}
function _xoxo_search_clear_form($element) {
  return array(
    '#type' => 'button',
    '#value' => t(XOXO_SEARCH_CLEAR),
    '#limit_validation_errors' => array(),
    '#attributes' => array('class' => array('xoxo-search-clear')),
    '#ajax' => array(
      'callback' => '_xoxo_search_refresh',
      'progress' => array('type' => FALSE),
    )
  );
}
function _xoxo_search_edit_form($element) {
  return array(
    '#type' => 'button',
    '#value' => t(XOXO_SEARCH_EDIT),
    '#limit_validation_errors' => array(),
    '#attributes' => array('class' => array('xoxo-search-edit')),
    '#ajax' => array(
      'callback' => '_xoxo_search_refresh',
      'progress' => array('type' => FALSE),
    )
  );
}
function _xoxo_search_back_form($form = FALSE) {
  $t = 'Back to results';
  $a = drupal_array_get_nested_value($form, array('#parents'));
  return array(
    '#type' => 'button',
    '#value' => t($t),
    '#limit_validation_errors' => array(),
    '#attributes' => array(
      'class' => array('xoxo-search-back')
    ),
    '#ajax' => array(
      'callback' => '_xoxo_search_nids',
      'progress' => array('type' => FALSE)
    )
  );
}
function _xoxo_search_nid_form($form = FALSE, $name = FALSE, $brand = FALSE, $description = FALSE) {
  return array(
    '#type' => 'hidden',
    '#attributes' => array('class' => array('xoxo-search-nid')),
    '#element_validate' => array('_xoxo_search_nid_form_validate')
  );
}
function _xoxo_search_unit_form($form = FALSE, $voc = 'uom') {
  $vocs = taxonomy_vocabulary_get_names();
  $vid = $vocs[$voc]->vid;
  $terms = taxonomy_get_tree($vid);
  $o = array();
  foreach ($terms as $term) {
    $o[$term->tid] = !empty($term) ? taxonomy_term_title($term) : '';
  }
  return array(
    '#type' => 'select',
    '#weight' => 6,
    '#attributes' => array('class' => array('xoxo-search-unit')),
    '#options' => $o
  );
}
function _xoxo_search_amount_form($form = FALSE) {
//  $t = 'Quantity';
  $p = 'Amount';
  return array(
//    '#title' => t($t),
    '#type' => 'textfield',
    '#size' => 6,
    '#weight' => 0,
    '#attributes' => array('placeholder' => $p, 'class' => array('xoxo-search-amount')),
    '#element_validate' => array('_xoxo_search_amount_form_validate')
  );
}
function _xoxo_search_node_add_form($form = FALSE) {
  return array(
    '#type' => 'button',
    '#value' => t(XOXO_SEARCH_ADD),
    '#weight' => 1,
    '#limit_validation_errors' => array(),
    '#attributes' => array(
      'class' => array('xoxo-search-node-add')
    ),
    '#ajax' => array(
      'callback' => '_xoxo_search_node_add',
      'progress' => array('type' => FALSE)
    )
  );
}
function _xoxo_search_add_form($form = FALSE) {
  $d = 'Or type your own ingredient';
  return array(
    '#type' => 'textfield',
    '#attributes' => array(
      'class' => array('xoxo-search-add'),
      'placeholder' => t($d)
    ),
    '#size' =>40 
  );
}
function _xoxo_search_search_form($form = array()) {
  $s = 'Search';
  $a = drupal_array_get_nested_value($form, array('#parents'));
  return array(
    '#type' => 'button',
    '#value' => t($s),
    '#weight' => 1,
    '#limit_validation_errors' => array(),
    '#attributes' => array(
      'class' => array('xoxo-search-search')
    ),
    '#ajax' => array(
      'callback' => '_xoxo_search_nids',
      'progress' => array('type' => FALSE)
    )
  );
}
function _xoxo_search_description_form($form = FALSE, $name = FALSE, $brand = FALSE) {
  return array(
    '#type' => 'textfield',
//    '#value_callback' => '_xoxo_search_valid_description',
    '#autocomplete_path' => 'xoxo-search/descriptions',
    '#attributes' => array(
      'class' => array('xoxo-search-description'),
      'placeholder' => t(XOXO_SEARCH_DESCRIPTION)
    ),
    '#size' => 20 
  );
}
function _xoxo_search_valid_description($form, $input, &$form_state) {
  $p = $form['#parents'];
  array_pop($p);
  $vals = drupal_array_get_nested_value($form_state['values'], $p);
  $name = drupal_array_get_nested_value($vals, array('name'));
  $brand = drupal_array_get_nested_value($vals, array('brand'));
  $q = _xoxo_search_nids_query($name, $brand, $input);
  $r = $q->fields('n', array('nid', 'title'))->execute()->fetchAllKeyed();
  if (empty($r)) {
    return FALSE;
  }
}
function _xoxo_search_name_form($form = FALSE, $form_state = FALSE) {
  return array(
    '#type' => 'textfield',
    '#autocomplete_path' => 'xoxo-search/names',
    '#attributes' => array(
      'class' => array('xoxo-search-name'),
      'placeholder' => t(XOXO_SEARCH_NAME)
    ),
    '#size' => XOXO_SEARCH_NAME_FORM_SIZE,
    '#ajax' => array(
      'callback' => '_xoxo_search_refresh',
      'wrapper' => $form['#id']
    )
  );
}
function _xoxo_search_brand_options($name) {
  $name = trim($name);
  $q = db_select('xoxo_brands', 'a');
  $q->join('field_data_field_component_brand', 'b', 'b.field_component_brand_value = a.bid');
  $q->join('field_data_field_component_name', 'c', 'c.entity_id = b.entity_id');
  $q->join('node', 'n', 'n.nid=c.entity_id');
  $q->join('xoxo_names', 'd', 'd.aid=c.field_component_name_value');
  $words = explode(' ', $name);
  foreach ($words as $word) {
    $p = '[[:<:]]' . db_like($word) . '[[:>:]]';
    $q->condition('d.value', $p, 'REGEXP');
  }
  $q = _xoxo_search_filter_out($q);
  return $q->fields('a', array('bid', 'value'))->execute()->fetchAllKeyed();
}
function _xoxo_search_brand_form($form = FALSE, $name = FALSE, $description = FALSE) {
  $o = _xoxo_search_brand_options($name);
  $o = array('-' => XOXO_SEARCH_BRAND) + $o;
  $r = array(
    '#type' => 'select',
    '#attributes' => array('class' => array('xoxo-search-brand')),
    '#value_callback' => '_xoxo_search_brand_value',
    '#options' => $o
  );
  return $r;
}
function _xoxo_search_parse($element, &$form_state) {
  $par = $element['#parents'];
  $vals = drupal_array_get_nested_value($form_state['values'], $par);
  if (empty($vals['add_name'])) {
    $am = 'amount';
    $fr = 'fraction';
    $key = 'amount_unit';
  }
  else {
    $am = 'add_amount';
    $fr = 'add_fraction';
    $vals['unit'] = $vals['add_unit'];
    $key = 'add_amount_unit';
  }
  $amount = (float) $vals[$am];
  $fraction = (float) $vals[$fr];
  if ($amount < 1) {
    $vals['amount'] = $amount;
  }
  else {
    $vals['amount'] = $amount + $fraction;
  }
  form_set_value($element, $vals, $form_state);
}
function _xoxo_search_validate($element, &$form_state) {
  $par = $element['#parents'];
  $vals = drupal_array_get_nested_value($form_state['values'], $par);
  if (!xoxo_ingredients_field_field_is_empty($vals, FALSE)) {
    if (empty($vals['amount'])) {
      form_error($element['amount'], XOXO_SEARCH_ERR_AM);
    }
    if (empty($vals['unit'])) {
      form_error($element['unit'], XOXO_SEARCH_ERR_UN);
    }
  }
}
function xoxo_search_field_widget_form(&$form, &$form_state, $field, $instance, $langcode, $items, $delta, $element) {
  if ($delta < count($items)) {
    $item = $items[$delta];
  }
  else {
    $item = array();
  }
  $title = array(
    '#tag' => 'div',
    '#type' => 'html_tag',
    '#attributes' => array('class' => array('xoxo-search-title')),
    '#weight' => -1,
    '#value' => t(XOXO_SEARCH_ING_TITLE, array('!delta' => $delta + 1))
  );
  $fractions_range = _xoxo_search_fracs_range();
  $b = range(1, 15);
  $tids = array(3179, 2497, 2801, 2469, 2618, 3039, 2679, 2525, 2458, 2673, 2460, 2668, 2515, 3060, 3053, 3052);
  $ints_range = array_combine($b, $b);
  $terms = taxonomy_term_load_multiple($tids);
  $units = array('' => 'Unit') + array_map('taxonomy_term_title', $terms);
  $amount = array(
    '#type' => 'select',
    '#options' => array('' => 'Amount') + $fractions_range + $ints_range,
    '#attributes' => array('class' => array('xoxo-search-amount'))
    );
  $add_amount = array(
    '#type' => 'select',
    '#options' => $amount['#options'],
    '#attributes' => array('class' => array('xoxo-search-add-amount'))
    );
  $fraction = array(
    '#type' => 'select',
    '#options' => array('' => '--') + $fractions_range,
    '#attributes' => array('class' => array('xoxo-search-fraction'))
    );
  $add_fraction = array(
    '#type' => 'select',
    '#options' => $fraction['#options'],
    '#attributes' => array('class' => array('xoxo-search-add-fraction'))
    );
  $unit = array(
    '#type' => 'select',
    '#options' => $units,
    '#attributes' => array('class' => array('xoxo-search-unit'))
    );
  $add_unit = array(
    '#type' => 'select',
    '#options' => $units,
    '#attributes' => array('class' => array('xoxo-search-add-unit'))
    );
  $brand_id = drupal_html_id('brand');
  $name = array(
    '#type' => 'textfield',
    '#autocomplete_path' => 'xoxo-search/names',
    '#attributes' => array(
      'class' => array('xoxo-search-name'),
      'placeholder' => t(XOXO_SEARCH_NAME)
    ),
    '#size' => XOXO_SEARCH_NAME_FORM_SIZE,
    '#ajax' => array(
      'callback' => '_xoxo_search_brands_refresh',
      'wrapper' => $brand_id,
      'progress' => array('type' => FALSE, 'throbber' => FALSE, 'message' => FALSE)
    )
  );
  $brand = array(
    '#type' => 'select',
    '#prefix' => format_string(XOXO_SEARCH_BRAND_WRAPPER, array('!id' => $brand_id)),
    '#suffix' => XOXO_SEARCH_CLOSE,
    '#attributes' => array('class' => array('xoxo-search-brand')),
    '#options' => array('-' => t(XOXO_SEARCH_BRAND)),
    '#validated' => TRUE
  );
  $nid = array(
    '#type' => 'hidden',
    '#attributes' => array('class' => array('xoxo-search-nid')),
    '#element_validate' => array('_xoxo_search_nid_form_validate')
  );
  $count = array(
    '#type' => 'hidden',
    '#attributes' => array('class' => array('xoxo-search-options-count'))
  );
  $edit = array(
    '#type' => 'button',
    '#value' => t(XOXO_SEARCH_EDIT),
    '#attributes' => array('class' => array('xoxo-search-edit')),
    '#limit_validation_errors' => array(),
    '#name' => 'xoxo_edit_button_' . $element['#delta'],
    '#ajax' => array(
      'callback' => '_xoxo_search_nids',
      'progress' => array('type' => FALSE)
    )
  );
  $remove = array(
    '#type' => 'html_tag',
    '#tag' => 'div',
    '#value' => t(XOXO_SEARCH_CLEAR),
    '#attributes' => array('class' => array('xoxo-search-clear')),
  );
  $search = array(
    '#type' => 'button',
    '#value' => t(XOXO_SEARCH_SEARCH),
    '#attributes' => array('class' => array('xoxo-search-search')),
    '#limit_validation_errors' => array(),
    '#name' => 'xoxo_search_button_' . $element['#delta'],
    '#ajax' => array(
      'callback' => '_xoxo_search_nids',
      'progress' => array('type' => 'throbber', 'message' => NULL)
    )
  );
  $add_name = array(
    '#type' => 'textfield',
    '#attributes' => array(
      'class' => array('xoxo-search-add'),
      'placeholder' => t(XOXO_SEARCH_CUSTOM)
    )
  );
  $add = array(
    '#type' => 'html_tag',
    '#tag' => 'div',
    '#value' => t(XOXO_SEARCH_ADD),
    '#attributes' => array('class' => array('xoxo-search-node-add')),
  );
  $add_amount_unit = array(
    '#type' => 'textfield',
    '#size' => 6,
    '#attributes' => array('placeholder' => XOXO_SEARCH_ING_AMOUNT, 'class' => array('xoxo-search-add-amount-unit')),
  );
  $add_edit = array(
    '#type' => 'html_tag',
    '#tag' => 'div',
    '#value' => t(XOXO_SEARCH_EDIT),
    '#attributes' => array('class' => array('xoxo-search-add-edit'))
  );
  $add_remove = array(
    '#type' => 'html_tag',
    '#tag' => 'div',
    '#value' => t(XOXO_SEARCH_CLEAR),
    '#attributes' => array('class' => array('xoxo-search-add-clear'))
  );
  $element += array(
    'title' => $title,
    'amount' => $amount,
    'fraction' => $fraction,
    'unit' => $unit,
    'name' => $name,
    'brand' => $brand,
    'edit' => $edit,
    'remove' => $remove,
    'search' => $search,
    'add_amount' => $add_amount,
    'add_fraction' => $add_fraction,
    'add_unit' => $add_unit,
    'add_name' => $add_name,
    'add' => $add,
    'add_edit' => $add_edit,
    'add_clear' => $add_remove,
    'nid' => $nid,
    'options' => $count
  );
  if (!xoxo_ingredients_field_field_is_empty($item, $field)) {
    $nid = $item['nid'];
    $name = _xoxo_search_name($nid);
    $brand = _xoxo_search_brand($nid);
    $element['nid']['#default_value'] = $nid;
    $amount = $item['amount'];
    $unit = $item['unit'];
    list($amount, $frac) = $g = _xoxo_search_fraction($amount);
    if (!$name && !$brand) {
      $element['add_amount']['#default_value'] = $amount;
      $element['add_fraction']['#default_value'] = $frac;
      $element['add_unit']['#default_value'] = $unit;
      $element['add_name']['#default_value'] = node_load($nid)->title;
    }
    else {
      $element['amount']['#default_value'] = $amount;
      $element['fraction']['#default_value'] = $frac;
      $element['unit']['#default_value'] = $unit;
      $element['name']['#default_value'] = $name;
      $element['brand']['#options'] += _xoxo_search_brand_options($name);
      $element['brand']['#default_value'] = $brand;
    }
  }
  $element['#process'] = array('_xoxo_search_wrap', '_xoxo_search_set_brand');
  $element['#element_validate'] = array('_xoxo_search_parse', '_xoxo_search_validate');
  $path = drupal_get_path('module', 'xoxo_search') . '/';
  $form['#attached']['js'][] = $path . 'xoxo_search.backspace.js';
  $form['#attached']['css'][] = $path . 'xoxo_search.css';
  $form['#submit'] = array('_xoxo_search_add_submit');
  return $element;
}
function _xoxo_search_set_brand($element, &$form_state) {
  $val = drupal_array_get_nested_value($form_state['values'], $element['#parents']);
  if (isset($val['nid'], $val['brand'])) {
    $element['brand']['#options'] = array('-' => XOXO_SEARCH_BRAND) + _xoxo_search_brand_options($val['name']);
    $element['brand']['#default_value'] = _xoxo_search_brand($val['nid']);
  }
  return $element;
}
function _xoxo_search_ingredient_form($element, &$form_state) {
  $item = $element['#item'];
  $p = $element['#parents'];
  array_push($p, 'name');
  $name = drupal_array_get_nested_value($form_state['values'], $p);
  array_splice($p, -1, 1, 'brand');
  $brand = drupal_array_get_nested_value($form_state['values'], $p);
  $amount_unit = array(
    '#type' => 'textfield',
    '#size' => 6,
    '#weight' => 0,
    '#attributes' => array('placeholder' => XOXO_SEARCH_ING_AMOUNT, 'class' => array('xoxo-search-amount')),
//    '#element_validate' => array('_xoxo_search_amount_form_validate')
  );
  if (xoxo_ingredients_field_field_is_empty($item, array())) {
    $form = array(
      'title' => _xoxo_search_title($element),
      'amount_unit' => $amount_unit,
      'name' => _xoxo_search_name_form($element),
      'brand' => _xoxo_search_brand_form($element, $name),
      'button' => _xoxo_search_search_form($element),
      'add_amount_unit' => $amount_unit,
      'add' => _xoxo_search_add_form($element),
      'node_add' => _xoxo_search_node_add_form($element),
      'nid' => _xoxo_search_nid_form($element),
      '#pre_render' => array('_xoxo_search_layout')
    );
  }
  else {
    $nid = $item['nid'];
    if (!$name) {
      $name = _xoxo_search_name($nid);
    }
    $form = array(
      'title' => _xoxo_search_title($element),
      'amount_unit' => $amount_unit,
      'name' => _xoxo_search_name_form($element),
      'brand' => _xoxo_search_brand_form($element, $name),
      'edit' => _xoxo_search_edit_form($element),
      'clear' => _xoxo_search_clear_form($element),
      'nid' => array('#type' => 'value', '#default_value' => $nid),
      'unit' => array('#type' => 'value', '#default_value' => $item['unit']),
      'amount' => array('#type' => 'value', '#default_value' => $item['amount'])
    );
    $am_data = array(
      '@amount' => $item['amount'],
      '@unit' => taxonomy_term_title(taxonomy_term_load($item['unit']))
    );
    $form['amount_unit']['#default_value'] = format_string(XOXO_SEARCH_AMOUNT, $am_data);
    $form['name']['#default_value'] = $name;
    if (!$brand) {
      $brand = _xoxo_search_brand($nid);
    }
    $form['brand']['#default_value'] = $brand;
  }
  $element = array_merge($element, $form);
  return $element;
}
function _xoxo_search_amount_unit($element, &$form_state) {
  $par = $element['#parents'];
  array_push($par, 'amount_unit');
  $val = drupal_array_get_nested_value($form_state['values'], $par);
  if ($val) {
    $arr = explode(' ', $val, 2);
    if (!empty($arr)) {
      $amount = $arr[0];
      array_splice($par, -1, 1, 'amount');
      drupal_array_set_nested_value($form_state['values'], $par, $amount);
    }
    if(count($arr) > 1) {
      $unit = XOXO_SEARCH_DEF_UNIT;//$arr[1];
      array_splice($par, -1, 1, 'unit');
      drupal_array_set_nested_value($form_state['values'], $par, $unit);
    }
  }
  return $element;
}
function _xoxo_search_amount_form_validate($element, &$form_state) {
//Get values.
  $p = $element['#parents'];
  array_pop($p);
  $vals = drupal_array_get_nested_value($form_state['values'], $p);
  $amount = trim(drupal_array_get_nested_value($vals, array('amount')));
  $nid = drupal_array_get_nested_value($vals, array('nid'));
  $add = drupal_array_get_nested_value($vals, array('add'));
  if (!is_numeric($amount)) {
    $p = array_map('trim', (array) explode('/', $amount));
    if (count($p) == 2 && is_numeric($p[0]) && is_numeric($p[1])) {
      $amount = $p[0] / $p[1];
    }
  }
  $m1 = 'Invalid amount value. Value must be positive only.';
  $m2 = 'Invalid amount value.';
//Get error.
  if (!empty($nid) || !empty($add) || !empty($amount)) {
    if (!is_numeric($amount)) {
      form_error($element, $m2);
    }else if ($amount <= 0) {
      form_error($element, $m1);
    }
  }
}
function _xoxo_search_nid_form_validate($element, &$form_state) {
//Get values.
  $p = $element['#parents'];
  array_pop($p);
  $vals = drupal_array_get_nested_value($form_state['values'], $p);
  $nid = (int) drupal_array_get_nested_value($vals, array('nid'));
  $add = drupal_array_get_nested_value($vals, array('add'));
//  $unit = taxonomy_term_title(taxonomy_term_load(drupal_array_get_nested_value($vals, array('unit'))));
//  $amount = drupal_array_get_nested_value($vals, array('amount'));
  $m = 'Invalid ingredient.';
  $p = implode('][', $p);
//Get error.
  if (empty($add) && !empty($nid)) {
    $q = db_select('node', 'n')->condition('n.nid', $nid);
    $q = _xoxo_search_filter_out($q);
    $q->fields('n', array('nid', 'title'));
    $r = $q->execute()->fetchAllKeyed();
    if (empty($r)) {
      form_set_error($p, t($m));
    }
  }
}
function _xoxo_search_ingredient_form_validate($element, &$form_state) {
//Get values.
  $p = $element['#parents'];
  $vals = drupal_array_get_nested_value($form_state['values'], $element['#parents']);
  $nid = drupal_array_get_nested_value($vals, array('nid'));
  $amount = drupal_array_get_nested_value($vals, array('amount'));
  $add = drupal_array_get_nested_value($vals, array('add'));
  $m = 'Provide both ingredient and amount.';
//Get error.
  if (!empty($nid) || !empty($amount) || !empty($add)) {
    if (empty($amount) || (empty($add) && empty($nid))) {
      form_error($element, t($m));
    }
  }
}
function _xoxo_search_amount_value($element, &$form_state) {
  $a = $element['amount'];
  $p = $a['#parents'];
  $input = drupal_array_get_nested_value($form_state['values'], $p);
}
function _xoxo_search_layout($form) {
  $keys = array('amount_unit', 'name', 'brand', 'search', 'add_amount_unit', 'add_name', 'add', '_weight');
  $cont = array(
    '#type' => 'container',
    '#attributes' => array('class' => array('xoxo-search-container'))
  );
  $form['existing'] = $cont + array(
    '#weight' => 1,
    'amount_unit' => $form['amount_unit'],
    'name' => $form['name'],
    'brand' => $form['brand'],
    'search' => $form['search']
  );
  $form['new'] = $cont + array(
    '#weight' => 2,
    'add_amount_unit' => $form['add_amount_unit'],
    'add_name' => $form['add_name'],
    'add' => $form['add']
  );
  foreach ($keys as $key) {
    unset($form[$key]);
  }
  return $form;
}
function _xoxo_search_wrap($form, $form_state) {
  $par = $form['#parents'];
  array_push($par, 'nid');
  $nid = drupal_array_get_nested_value($form_state['values'], $par);
  $node_exists = isset($form['nid']['#default_value']) && !empty($form['nid']['#default_value']) || $nid;
  array_splice($par, -1, 1, 'add_name');
  $custom = drupal_array_get_nested_value($form_state['values'], $par);
  $custom_exists = isset($form['add_name']['#default_value']) && !empty($form['add_name']['#default_value']) || $custom;
  if ($custom_exists) {
    $class = 'xoxo-custom-selected';
  }
  else if ($node_exists) {
    $class = 'xoxo-selected';
  }
  else {
    $class = 'xoxo-empty';
  }
  $el_data = array(
    '!id' => $form['#id'],
    '!class' => $class,
    '!delta' => $form['#delta']
  );
  $form['#prefix'] = format_string(XOXO_SEARCH_WRAPPER, $el_data);
  $form['#suffix'] = XOXO_SEARCH_CLOSE;
  return $form;
}
function _xoxo_search_nids($form, $form_state) {
  $pop = '<div id="xoxo-search-popup"></div>';
  $s = '#xoxo-search-popup';
  $s1 = $s . ' ul';
  $cont = '<ul class="ingredients" field="%s">%s</ul>';
  $p = $form_state['triggering_element']['#parents'];
  array_splice($p, -1, 1, 'brand');
  $brand = drupal_array_get_nested_value($form_state['values'], $p);
  array_splice($p, -1, 1, 'name');
  $name = drupal_array_get_nested_value($form_state['values'], $p);
  array_splice($p, -1, 1, 'description');
  $description = drupal_array_get_nested_value($form_state['values'], $p);
  array_splice($p, -1, 1, 'options');
  $amount = drupal_array_get_nested_value($form_state['values'], $p);
  array_splice($p, -1, 1, array('nid', '#name'));
  $nid_id = drupal_array_get_nested_value($form, $p);
  $q = _xoxo_search_nids_query($name, $brand, $description);
  $options = _xoxo_search_nids_html($q, $amount);
  if (empty($options) && empty($amount)) {
    $m = variable_get('xoxo_search_empty_message', '');
    $br = db_select('xoxo_brands', 'x')->condition('x.bid', $brand)->fields('x',array( 'value'))->execute()->fetchField();
//    $c = ajax_command_append($s, t($m, array('@name' => $name, '@brand' => $br, '@description' => $description)));
    $c = ajax_command_alert(t($m, array('@name' => $name, '@brand' => $br, '@description' => $description)));
    return array('#type' => 'ajax', '#commands' => array($c));
  }
  else{
    if (empty($amount)) {
      $c = ajax_command_append($s, sprintf($cont, $nid_id, $options));
    }
    else {
      $c = ajax_command_append($s1, $options);
    }
  }
  $set = array('modal' => TRUE, 'height' => 300);
  return array(
    '#type' => 'ajax',
    '#commands' => array(ajax_command_invoke($s, 'dialog', array($set)), $c)
  );
}
function _views_exposed_form_hack(&$element) {
  $element['form_build_id']['#access'] = FALSE;
  $element['form_token']['#access'] = FALSE;
  $element['form_id']['#access'] = FALSE;

  // In order for Ajax to work, we need the form build info. Here we check if
  // #ajax has been added to any form elements, and if so, pass this info as
  // settings via Javascript, which get attached to the submitted form on Ajax
  // form submissions.
  foreach (element_children($element) as $key) {
    if (isset($element[$key]['#ajax'])) {
      $element['#attached']['js'][] = array(
        'type' => 'setting',
        'data' => array(
          'exposed_form_info' => array(
            'form_id' => $element['#form_id'],
            'form_build_id' => $element['#build_id'],
            'form_token' => $element['#token'],
          ),
        ),
      );
      $element['#attached']['js'][] = array(
        'type' => 'inline',
        'weight' => 100,
        'data' => '(function ($) {
            Drupal.behaviors.ViewsExposedFormAjax = {
              attach: function(context, settings) {
                for (ajax_object in Drupal.ajax) {
                  if (Drupal.ajax[ajax_object].options) {
                    jQuery.extend(Drupal.ajax[ajax_object].options.data, Drupal.settings.exposed_form_info);
                  }
                }
              }
            };
          })(jQuery);',
      );
      break;
    }
  }
}
function _xoxo_search_brand_update($form, $form_state) {
  $m = 'Hello.';
  $commands = array(ajax_command_alert($m));
  return array('#type' => 'ajax', '#commands' => $commands);
}
function _xoxo_search_update($form, $form_state) {
  $p = $form_state['triggering_element']['#parents'];
  array_pop($p);
  $form = drupal_array_get_nested_value($form, $p);
  if (isset($form_state['view'])) {
    array_push($p, 'name');
    $name = drupal_array_get_nested_value($form_state['values'], $p);
    $form['name']['#value'] = $name;
    $form['brand'] = array_merge($form['brand'], _xoxo_search_brand_form($form, $name));
    $form['brand']['#attributes']['style'] = 'width: 100px;';
    $form['brand']['#weight'] = -9;
    array_splice($p, -1, 1, 'description');
    $description = drupal_array_get_nested_value($form_state['values'], $p);
    $form['description']['#value'] = $description;
  }
  return $form;
}
function xoxo_search_form_views_exposed_form_alter(&$form, &$form_state) {
  $a = 'field_component_name_value';
  $b = 'field_component_brand_value';
  $c = 'field_component_description_value';
  if (isset($form[$a]) && isset($form[$b]) && isset($form[$c])) {
    $form['#attached']['js'][] =
      drupal_get_path('module', 'xoxo_search')
      . '/xoxo_search.backspace.js';
    $form['#process'][] = '_xoxo_search_filter_form';
  }
}
function _xoxo_search_filter_form($element, &$form_state) {
//Get values.
  $a = 'field_component_name_value';
  $b = 'field_component_brand_value';
  $c = 'field_component_description_value';
  $v =& $form_state['view'];
  $i = $v->get_exposed_input();
  $name = drupal_array_get_nested_value($i, array('name'));
//  $name_id = _xoxo_search_name_id($name);
  $brand = drupal_array_get_nested_value($i, array('brand'));
  $brand_id = _xoxo_search_brand_id($brand);
  $description = drupal_array_get_nested_value($i, array('description'));
//Get form.
  if (isset($element[$a])) {
    $element[$a]['#type'] = 'hidden';
    $element['name'] = _xoxo_search_name_form($element);
    $element['name']['#weight'] = -10;
    $element['name']['#size'] = 30;
    $element['name']['#ajax']['callback'] = '_xoxo_search_update';
    $element['name']['#ajax']['wrapper'] = $element['#id'];
    $element['name']['#ajax']['progress'] = array(
      'message' => NULL,
      'type' => 'throbber'
    );
  }
  if (isset($element[$b])) {
    $element[$b]['#type'] = 'hidden';
    $element['brand'] = _xoxo_search_brand_form($element, $name);
    $element['brand']['#attributes']['style'] = 'width: 100px;';
    $element['brand']['#weight'] = -9;
  }
  if (isset($element[$c])) {
    $element[$c]['#type'] = 'hidden';
    $element['description'] = _xoxo_search_description_form($element, $name, $brand_id);
    $element['description']['#weight'] = -8;
    $element['description']['#size'] = 30;
    $element['description']['#attributes']['style'] = 'margin: 0 !important;';
  }
  _views_exposed_form_hack($element);
//Set values. Oops.
  if (isset($i[$a])) {
    $i[$a] = $name;
    $element[$a]['#value'] = $name;
  }
  if (isset($i[$b])) {
    $i[$b] = $brand_id;
    $element[$b]['#value'] = $brand_id;
  }
  if (isset($i[$c])) {
    $i[$c] = $description;
    $element[$c]['#value'] = $description;
  }
  $v->set_exposed_input($i);
//OK.
  return $element;
}
function _xoxo_search_node_add($form, $form_state) {
  $p = $form_state['triggering_element']['#parents'];
  array_splice($p, -1, 1, 'add');
  $title = drupal_array_get_nested_value($form_state['values'], $p);
  _xoxo_fields_create_custom_component($title, array());
}
function _xoxo_search_refresh($form, $form_state) {
  $p = $form_state['triggering_element']['#parents'];
  array_pop($p);
  $element = drupal_array_get_nested_value($form, $p);
  return $element;
}
function _xoxo_search_brands_refresh($form, $form_state) {
  $par = $form_state['triggering_element']['#parents'];
  array_splice($par, -1, 1, 'brand');
  $brand = drupal_array_get_nested_value($form, $par);
  array_splice($par, -1, 1, 'name');
  // Get the name of the ingredient entered by the user.
  $name = drupal_array_get_nested_value($form_state['values'], $par);
  // Get the list of brand options for the ingredient.
  $brand['#options'] = array('-' => XOXO_SEARCH_BRAND) + _xoxo_search_brand_options($name);
  array_splice($par, -1, 1, '#id');
  // Set the field ID for the brand select list to fill in.
  // This isn't working correctly, as the wrong ID is being selected, and it
  // isn't needed for form elements.
//  $field_id = drupal_array_get_nested_value($form, $par);
//  $brand_sel = "#$field_id .brand-wrapper";
  // Set the field ID for the throbber to remove.
//  $throb_sel = "#$field_id .ajax-progress-throbber";
  $throb_sel = ".ajax-progress-throbber";
  $coms = array(
//    ajax_command_replace($brand_sel, render($brand)),
    ajax_command_replace(NULL, render($brand)),
    ajax_command_remove($throb_sel)
  );
  return array('#type' => 'ajax', '#commands' => $coms);
}
function _xoxo_search_add_node($form, $form_state) {
  $par = $form_state['triggering_element']['#parents'];
  array_splice($par, -1, 1, 'add_name');
  $name = drupal_array_get_nested_value($form_state['values'], $par);
  if (!empty($name)) {
    $nid = _xoxo_fields_create_custom_component($name, array());
    if (!empty($nid)) {
      array_pop($par);
      $element = drupal_array_get_nested_value($form, $par);
      $sel = '#' . $element['#id'];
      $rem = ajax_command_invoke($sel, 'removeClass', array('xoxo-empty'));
      $add = ajax_command_invoke($sel, 'addClass', array('xoxo-selected'));
      $nid_sel = $sel . ' .xoxo-search-nid';
      $set_nid = ajax_command_invoke($nid_sel, 'val', array($nid));
      array_push($par, 'add_amount_unit');
      $amo = drupal_array_get_nested_value($form_state['values'], $par);
      $amo_sel = $sel . ' .xoxo-search-amount';
      $set_amo = ajax_command_invoke($amo_sel, 'val', array($amo));
      return array('#type' => 'ajax', '#commands' => array($rem, $add, $set_nid, $set_amo));
    }
    else {
      return array('#type' => 'ajax', '#commands' => array(ajax_command_alert(XOXO_SEARCH_ADD_ERROR)));
    }
  }
}
function _xoxo_search_fraction($num) {
  $z = '0.';
  $m = 'key';
  list($main, $add) = explode('.', $num);
  if ($add) {
    $frac = $z . $add;
    $dec = array_keys(_xoxo_search_fracs_range());
    $dec += array($m => $frac);
    asort($dec);
    while(key($dec) !== $m) {
      next($dec);
    }
    list($prev, $curr, $next) = array(prev($dec), next($dec), next($dec));
    $a = $curr - $prev;
    $b = $next - $curr;
    $frac = $a > $b ? $next : $prev;
  }
  if (!$main) {
    $main = $frac;
    $frac = 0;
  }
  return array((float) $main, (float) $frac);
}

function _xoxo_search_frac_string($num) {
  $s = ' ';
  list($int, $frac) = _xoxo_search_fraction($num);
  if ($int && $frac) {
    $frac = (string) $frac;
    $r = _xoxo_search_fracs_range();
    $f = $r[$frac];
    $r = $int . $s . $f;
  }
  else if (!$frac && $int < 1) {
    $int = (string) $int;
    $r = _xoxo_search_fracs_range();
    $f = $r[$int];
    $r = $f;
  }
  else {
    $r = $int;
  }
  return $r;
}

function _xoxo_search_fracs_range() {
  return array(
    '0.06'=> '1/16',
    '0.12' => '1/8',
    '0.25' => '1/4',
    '0.33' => '1/3',
    '0.37' => '3/8',
    '0.5' => '1/2',
    '0.62' => '5/8',
    '0.66' => '2/3',
    '0.75' => '3/4',
    '0.87'=> '7/8');
}