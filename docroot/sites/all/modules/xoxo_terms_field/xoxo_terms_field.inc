<?php
//Callback for single terms input.
function _xoxo_terms_field_autocomplete($field_name, $typed = '') {
  $field = field_info_field($field_name);
  $string = drupal_strtolower(trim(str_replace(
    '""',
    '"',
    preg_replace('/^"(.*)"$/', '\1', $typed)
  ))); 
  $matches = array();
  if ($string != '') {
    $vids = array();
    $vocabularies = taxonomy_vocabulary_get_names();
    foreach ($field['settings']['allowed_values'] as $tree) {
      $vids[] = $vocabularies[$tree['vocabulary']]->vid;
    }
    $query = db_select('taxonomy_term_data', 't');
    $query->addTag('translatable');
    $query->addTag('term_access');
    $tags_return = $query
      ->fields('t', array('tid', 'name'))
      ->condition('t.vid', $vids)
      ->condition('t.name', '%' . db_like($string) . '%', 'LIKE')
      ->range(0, 10)
      ->execute()
      ->fetchAllKeyed();
    $term_matches = array();
    foreach ($tags_return as $tid => $name) {
      $term_matches[$name] = check_plain($name);
    }
  }
  drupal_json_output($term_matches);  
}
//The widget's validate handler.
function _xoxo_terms_field_value($element, &$form_state) {
  $field = field_widget_field($element, $form_state);
  $vocabularies = array_map(
    '_xoxo_terms_field_vocabulary',
    $field['settings']['allowed_values']
  );
  $typed = drupal_array_get_nested_value(
    $form_state['values'],
    $element['#parents']
  );
  $names = array_map('_xoxo_terms_field_tid', $typed);
  $val = array_fill(0, count($typed), array('tid' => FALSE));
  $unames = array_filter(array_unique($names));
  $vids = array_map('_xoxo_terms_field_vocabulary_id', $vocabularies);
  $voc = reset($vocabularies);
  foreach($unames as $key => $name) {
    $terms = taxonomy_term_load_multiple(
      array(),
      array('name' => $name, 'vid' => $vids)
    );
    if (!empty($terms)) {
      $term = (array) array_pop($terms);
    }
    else {
      $term = _xoxo_terms_field_term($name, $voc);
    }
    $val[$key] = $term;
  }
  form_set_value($element, $val, $form_state);
}
//Vocabulary. $tree - term reference field allowed value.
function _xoxo_terms_field_vocabulary($tree) {
  if ($vocabulary = taxonomy_vocabulary_machine_name_load($tree['vocabulary'])) {
    return $vocabulary;
  }
  else {
    return FALSE;
  }
}
//Vocabulary ID. $vocabulary - vocabulary object.
function _xoxo_terms_field_vocabulary_id($vocabulary) {
  if(property_exists($vocabulary, 'vid')) {
    return $vocabulary->vid;
  }
  else {
    return FALSE;
  }
}
//New term. $name - human readable term name.
function _xoxo_terms_field_term($name, $voc) {
  return array(
    'tid' => 'autocreate',
    'vid' => _xoxo_terms_field_vocabulary_id($voc),
    'name' => $name,
    'vocabulary_machine_name' => $voc->machine_name,
    'field_custom_term' => array('und' => array(0 => array('value' => 1)))
  );
}
//Term ID. $term - term array.
function _xoxo_terms_field_tid($term) {
  if(array_key_exists('tid', $term)) {
    return $term['tid'];
  }
}
//"tid" element with default value set.
function _xoxo_terms_field_tid_val($element, $value) {
  $element['tid']['#default_value'] = $value;
  return $element;
}
