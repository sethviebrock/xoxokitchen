<?php

/**
 * @file
 * This file is empty by default because the base theme chain (Alpha & Omega) provides
 * all the basic functionality. However, in case you wish to customize the output that Drupal
 * generates through Alpha & Omega this file is a good place to do so.
 *
 * Alpha comes with a neat solution for keeping this file as clean as possible while the code
 * for your subtheme grows. Please read the README.txt in the /preprocess and /process subfolders
 * for more information on this topic.
 */

 /**
 * XOXO: Override of the default form item generation
 * Returns HTML for a form element.
 *
 * Each form element is wrapped in a DIV container having the following CSS
 * classes:
 * - form-item: Generic for all form elements.
 * - form-type-#type: The internal element #type.
 * - form-item-#name: The internal form element #name (usually derived from the
 *   $form structure and set via form_builder()).
 * - form-disabled: Only set if the form element is #disabled.
 *
 * In addition to the element itself, the DIV contains a label for the element
 * based on the optional #title_display property, and an optional #description.
 *
 * The optional #title_display property can have these values:
 * - before: The label is output before the element. This is the default.
 *   The label includes the #title and the required marker, if #required.
 * - after: The label is output after the element. For example, this is used
 *   for radio and checkbox #type elements as set in system_element_info().
 *   If the #title is empty but the field is #required, the label will
 *   contain only the required marker.
 * - invisible: Labels are critical for screen readers to enable them to
 *   properly navigate through forms but can be visually distracting. This
 *   property hides the label for everyone except screen readers.
 * - attribute: Set the title attribute on the element to create a tooltip
 *   but output no label element. This is supported only for checkboxes
 *   and radios in form_pre_render_conditional_form_element(). It is used
 *   where a visual label is not needed, such as a table of checkboxes where
 *   the row and column provide the context. The tooltip will include the
 *   title and required marker.
 *
 * If the #title property is not set, then the label and any required marker
 * will not be output, regardless of the #title_display or #required values.
 * This can be useful in cases such as the password_confirm element, which
 * creates children elements that have their own labels and required markers,
 * but the parent element should have neither. Use this carefully because a
 * field without an associated label can cause accessibility challenges.
 *
 * @param $variables
 *   An associative array containing:
 *   - element: An associative array containing the properties of the element.
 *     Properties used: #title, #title_display, #description, #id, #required,
 *     #children, #type, #name.
 *
 * @ingroup themeable
 */
function xoxo_form_element($variables) {
  $element = &$variables['element'];
  // This is also used in the installer, pre-database setup.
  $t = get_t();

  // This function is invoked as theme wrapper, but the rendered form element
  // may not necessarily have been processed by form_builder().
  $element += array(
    '#title_display' => 'before',
  );

  // Add element #id for #type 'item'.
  if (isset($element['#markup']) && !empty($element['#id'])) {
    $attributes['id'] = $element['#id'];
  }
  // Add element's #type and #name as class to aid with JS/CSS selectors.
  $attributes['class'] = array('form-item');
  if (!empty($element['#type'])) {
    $attributes['class'][] = 'form-type-' . strtr($element['#type'], '_', '-');
  }
  if (!empty($element['#name'])) {
    $attributes['class'][] = 'form-item-' . strtr($element['#name'], array(' ' => '-', '_' => '-', '[' => '-', ']' => ''));
  }
  // Add a class for disabled elements to facilitate cross-browser styling.
  if (!empty($element['#attributes']['disabled'])) {
    $attributes['class'][] = 'form-disabled';
  }
  $output = '<div' . drupal_attributes($attributes) . '>' . "\n";


  // If #title is not set, we don't display any label or required marker.
  if (!isset($element['#title'])) {
    $element['#title_display'] = 'none';
  }
  $prefix = isset($element['#field_prefix']) ? '<span class="field-prefix">' . $element['#field_prefix'] . '</span> ' : '';
  $suffix = isset($element['#field_suffix']) ? ' <span class="field-suffix">' . $element['#field_suffix'] . '</span>' : '';

  switch ($element['#title_display']) {
    case 'before':
    case 'invisible':
      $output .= ' ' . theme('form_element_label', $variables);
      $output .= ' ' . $prefix . $element['#children'] . $suffix . "\n";
      break;

    case 'after':
      $output .= ' ' . $prefix . $element['#children'] . $suffix;
      $output .= ' ' . theme('form_element_label', $variables) . "\n";
      break;

    case 'none':
    case 'attribute':
      // Output no label and no required marker, only the children.
      $output .= ' ' . $prefix . $element['#children'] . $suffix . "\n";
      break;
  }

    if (!empty($element['#description'])) {
	  $output .= '<div class="description">' . $element['#description'] . "</div>\n";
  }

  $output .= "</div>\n";

  return $output;
}

/**
 * XOXO: Override of the checkboxes field output
 * Returns HTML for a set of checkbox form elements.
 *
 * @param $variables
 *   An associative array containing:
 *   - element: An associative array containing the properties of the element.
 *     Properties used: #children, #attributes.
 *
 * @ingroup themeable
 */
function xoxo_checkboxes($variables) {
  $element = $variables['element'];

  //dpm($element);

  $attributes = array();
  if (isset($element['#id'])) {
    $attributes['id'] = $element['#id'];
  }
  $attributes['class'][] = 'form-checkboxes';
  if (!empty($element['#attributes']['class'])) {
    $attributes['class'] = array_merge($attributes['class'], $element['#attributes']['class']);
  }

  // Field specific overrides
  if($element['#field_name'] == 'field_user_health' || $element['#field_name'] == 'field_health_cond'){

    $field_tids = array_fill_keys(array_keys($element['#options']), array());

    $r = db_select('taxonomy_term_hierarchy', 'tth')
      ->fields('tth')
      ->condition('tid', array_keys($element['#options']), 'IN') //->condition('parent', array_keys($element['#options']), 'IN')
      ->execute();

    $grouped_tids = array();

    foreach($r as $record){
      if($record->parent == "0") {
        $grouped_tids[$record->tid] = array();
        continue;
      }
      $grouped_tids[$record->parent][] = $record->tid;
    }
    krsort($grouped_tids);

    /*dpm($grouped_tids);
      dpm($field_tids);
      dpm($element['#options']);*/


    $output = '';
    foreach($grouped_tids as $p_tid => $c_tids){

      $output .= '<div class="term-wrapper">';
      $output .= '<div class="term-parent">'. $element[$p_tid]['#children']. '</div>';
      $output .= '<div class="term-children">';
      foreach($c_tids as $c_tid){
	$output .= $element[$c_tid]['#children'];
      }
      $output .= '</div>';
      $output .= '</div><!-- //.term-wrapper -->';

    }

    return '<div' . drupal_attributes($attributes) . '>'. $output. '</div>';
  }

  return '<div' . drupal_attributes($attributes) . '>' . (!empty($element['#children']) ? $element['#children'] : '') . '</div>';
}


function xoxo_table_cell($cell, $header = FALSE) {
  $attributes = '';

  if (is_array($cell)) {
    $data = isset($cell['data']) ? $cell['data'] : '';
    $header |= isset($cell['header']);
    unset($cell['data']);
    unset($cell['header']);
    $attributes = drupal_attributes($cell);
  }
  else {
    $data = $cell;
  }
  if ($header) {
    $output = "<th$attributes>$data</th>";
  }
  else {
    $output = "<td$attributes><div class='my_td'><div class='my_cell'>$data</div></div></td>";
  }
  return $output;
}

function xoxo_table($variables) {
  $header = $variables['header'];
  $rows = $variables['rows'];
  $attributes = $variables['attributes'];
  $caption = $variables['caption'];
  $colgroups = $variables['colgroups'];
  $sticky = $variables['sticky'];
  $empty = $variables['empty'];

  // Add sticky headers, if applicable.
  if (count($header) && $sticky) {
    drupal_add_js('misc/tableheader.js');
    // Add 'sticky-enabled' class to the table to identify it for JS.
    // This is needed to target tables constructed by this function.
    $attributes['class'][] = 'sticky-enabled';
  }

  $output = '<table' . drupal_attributes($attributes) . ">\n";

  if (isset($caption)) {
    $output .= '<caption>' . $caption . "</caption>\n";
  }

  // Format the table columns:
  if (count($colgroups)) {
    foreach ($colgroups as $number => $colgroup) {
      $attributes = array();

      // Check if we're dealing with a simple or complex column
      if (isset($colgroup['data'])) {
        foreach ($colgroup as $key => $value) {
          if ($key == 'data') {
            $cols = $value;
          }
          else {
            $attributes[$key] = $value;
          }
        }
      }
      else {
        $cols = $colgroup;
      }

      // Build colgroup
      if (is_array($cols) && count($cols)) {
        $output .= ' <colgroup' . drupal_attributes($attributes) . '>';
        $i = 0;
        foreach ($cols as $col) {
          $output .= ' <col' . drupal_attributes($col) . ' />';
        }
        $output .= " </colgroup>\n";
      }
      else {
        $output .= ' <colgroup' . drupal_attributes($attributes) . " />\n";
      }
    }
  }

  // Add the 'empty' row message if available.
  if (!count($rows) && $empty) {
    $header_count = 0;
    foreach ($header as $header_cell) {
      if (is_array($header_cell)) {
        $header_count += isset($header_cell['colspan']) ? $header_cell['colspan'] : 1;
      }
      else {
        $header_count++;
      }
    }
    $rows[] = array(array('data' => $empty, 'colspan' => $header_count, 'class' => array('empty', 'message')));
  }

  // Format the table header:
  if (count($header)) {
    $ts = tablesort_init($header);
    // HTML requires that the thead tag has tr tags in it followed by tbody
    // tags. Using ternary operator to check and see if we have any rows.
    $output .= (count($rows) ? ' <thead><tr>' : ' <tr>');
    foreach ($header as $cell) {
      $cell = tablesort_header($cell, $header, $ts);
      $output .= _theme_table_cell($cell, TRUE);
    }
    // Using ternary operator to close the tags based on whether or not there are rows
    $output .= (count($rows) ? " </tr></thead>\n" : "</tr>\n");
  }
  else {
    $ts = array();
  }

  // Format the table rows:
  if (count($rows)) {
    $output .= "<tbody>\n";
    $flip = array('even' => 'odd', 'odd' => 'even');
    $class = 'even';
    foreach ($rows as $number => $row) {
      $attributes = array();

      // Check if we're dealing with a simple or complex row
      if (isset($row['data'])) {
        foreach ($row as $key => $value) {
          if ($key == 'data') {
            $cells = $value;
          }
          else {
            $attributes[$key] = $value;
          }
        }
      }
      else {
        $cells = $row;
      }
      if (count($cells)) {
        // Add odd/even class
        if (empty($row['no_striping'])) {
          $class = $flip[$class];
          $attributes['class'][] = $class;
        }

        // Build row
        $output .= ' <tr' . drupal_attributes($attributes) . '>';
        $i = 0;
        foreach ($cells as $cell) {
          $cell = tablesort_cell($cell, $header, $ts, $i++);
          $output .= xoxo_table_cell($cell);
        }
        $output .= " </tr>\n";
      }
    }
    $output .= "</tbody>\n";
  }

  $output .= "</table>\n";
  return $output;
}


/*function xoxo_image_widget($variables) {
  $element = $variables['element'];
  if($element['#field_name'] == 'field_user_photo'){
    $element = $variables['element'];
    $output = '';
    $output .= '<div class="image-widget1 form-managed-file clearfix">';

    $output .= '<div class="image-widget-data1">';

    $output .= drupal_render($element['upload_button']);
    $output .= drupal_render($element['remove_button']);
    $output .= drupal_render_children($element);

    $output .= drupal_render($element['filename']['#markup']);
    if(isset($element['preview'])){
      $output .= drupal_render($element['preview']);
    }
    else{
      $output .= '<div class="nophoto"></div>';
    }
    $output .= '</div>';
    $output .= '</div>';
    return $output;
  }
}*/




function xoxo_preprocess_views_exposed_form(&$vars, $hook) {
  $form = &$vars['form'];
  if ($form['#id'] == 'views-exposed-form-recipes-andrei-page') {
    // Change the text on the submit button
    $vars['form']['submit']['#value'] = t('Go');

    // Rebuild the rendered version (submit button, rest remains unchanged)
    unset($vars['form']['submit']['#printed']);
    $vars['button'] = drupal_render($vars['form']['submit']);
  }
}

function xoxo_form_alter(&$form, &$form_state, $form_id) {
  if($form_id == 'views_exposed_form_components_block_4') {
    $form['title']['#attributes']['placeholder'] = 'Enter A Search Term';
    $form['title']['title'] = '';
    /*kpr($form);*/
  }
  if ($form_id == 'user_login') {
    $form['actions']['submit']['#value'] = t('Log In');
  }
  if ($form_id == 'user_register_form') {
    $form['actions']['submit']['#value'] = t('Create My Account');
    $form['edit-pass-pass2']['#attributes']['placeholder'] = '';
  }
  if ($form_id == 'user_login_block') {
    $form['actions']['submit']['#value'] = t('Log In');
    $form['name']['#attributes']['placeholder'] = 'E-mail';
    $form['name']['title'] = '';
	$form['pass']['#attributes']['placeholder'] = 'Password';
  }
  if ($form_id == 'recipe_node_form') {
    drupal_set_title('Create A Recipe');

    $form['title']['#size'] = 88;
    $form['title']['#title'] = t('Title:');
    $form['title']['#placeholder'] = 'Title';

    $form['title']['#title'] = t('Title:');

    $form['field_recipe_servings'][LANGUAGE_NONE]['0']['value']['#size'] = 8;

    $form['field_recipe_quantity'][LANGUAGE_NONE]['0']['value']['#size'] = 8;

    $form['field_recipe_time'][LANGUAGE_NONE]['0']['value']['#size'] = 8;

    $form['field_recipe_image'][LANGUAGE_NONE]['0']['#description'] = '';

    $form['body'][LANGUAGE_NONE]['0']['value']['#resizable'] = FALSE;
    $form['body'][LANGUAGE_NONE]['0']['value']['#cols'] = 85;
    $form['body'][LANGUAGE_NONE]['0']['#rows'] = 10;
    $form['body'][LANGUAGE_NONE]['0']['#attributes']['placeholder'] = 'Start Here...';
    foreach ($form['field_recipe_ingredients'][LANGUAGE_NONE] as $delta => $item) {
      if(is_numeric($delta)) {

	$form['field_recipe_ingredients'][LANGUAGE_NONE][$delta]['nid']['#title'] = 'Ingredient '.($delta + 1).':';
	$form['field_recipe_ingredients'][LANGUAGE_NONE][$delta]['nid']['#description'] = t('Example:Peanut Butter');
	$form['field_recipe_ingredients'][LANGUAGE_NONE][$delta]['nid']['#attributes']['placeholder'] = 'Type ingredient';

	$form['field_recipe_ingredients'][LANGUAGE_NONE][$delta]['amount']['#title_display'] = 'invisible';
	$form['field_recipe_ingredients'][LANGUAGE_NONE][$delta]['amount']['#description'] = t('Example:How Much');
	$form['field_recipe_ingredients'][LANGUAGE_NONE][$delta]['amount']['#attributes']['placeholder'] = '1/4';

	$form['field_recipe_ingredients'][LANGUAGE_NONE][$delta]['unit']['#title_display'] = 'invisible';

      }
    }

    $form['field_recipe_ingredients'][LANGUAGE_NONE]['0']['unit']['#title_display'] = 'invisible';
    $form['field_recipe_ingredients'][LANGUAGE_NONE]['add_more']['#value']= t('Add Another Ingredient');

    //dsm($form);
    //print_r($form);

  }
}

function xoxo_file_upload_help($variables) {
/*if ($form_id == 'user_register_form') {*/
  $description = $variables['description'];
  $upload_validators = $variables['upload_validators'];

  $descriptions = array();

  if (strlen($description)) {
    $descriptions[] = $description;
  }
  if (isset($upload_validators['file_validate_size'])) {
    $descriptions[] = t('Files must be less than !size.', array('!size' => '<strong>' . format_size($upload_validators['file_validate_size'][0]) . '</strong>'));
  }
  if (isset($upload_validators['file_validate_extensions'])) {
    $descriptions[] = t('Allowed file types: !extensions.', array('!extensions' => '<strong>' . check_plain($upload_validators['file_validate_extensions'][0]) . '</strong>'));
  }
  if (isset($upload_validators['file_validate_image_resolution'])) {
    $max = $upload_validators['file_validate_image_resolution'][0];
    $min = $upload_validators['file_validate_image_resolution'][1];
    if ($min && $max && $min == $max) {
      $descriptions[] = t('Images must be exactly !size pixels.', array('!size' => '<strong>' . $max . '</strong>'));
    }
    elseif ($min && $max) {
      $descriptions[] = t('Images must be between !min and !max pixels.', array('!min' => '<strong>' . $min . '</strong>', '!max' => '<strong>' . $max . '</strong>'));
    }
    elseif ($min) {
      $descriptions[] = t('Images must be larger than !min pixels.', array('!min' => '<strong>' . $min . '</strong>'));
    }
    elseif ($max) {
      $descriptions[] = t('Images must be smaller than !max pixels.', array('!max' => '<strong>' . $max . '</strong>'));
    }
  }

  return implode($descriptions);
}

function xoxo_preprocess_views_view_table(&$variables) {
  $table = array(
    '#theme' => 'table',
    '#theme_wrappers' => array('fieldset'),
    '#rows' => $variables['rows']
  );
  $variables['table'] = render($table);
  $group = array(
    '#theme' => 'fieldset',
    '#title' => $variables['title'],
    '#value' => $variables['table'],
    '#collapsible' => TRUE,
    '#attributes' => array('class' => array('collapsible', 'collapsed')),
    '#attached' => array('js' => array('misc/form.js', 'misc/collapse.js'))
  );
  $variables['group'] = render($group);
}

function xoxo_preprocess_week_pager(&$vars) {
  if($vars['mail']) {
    $vars['theme_hook_suggestions'][] = 'week_pager__mail';
  }
}

function xoxo_preprocess_views_draggable_unformatted(&$vars) {
  $a = array();
  $b = '';
  $t = !empty($vars['title']);
  $vars['title'] = $t ? $vars['title'] : t('Search Results');
  foreach ((isset($vars['rows']) ? $vars['rows'] : array()) as $id => $row) {
    $a = array();
    $a['item'] = array(
      '#theme' => 'html_tag',
      '#tag' => 'div',
      '#value' => $row
    );
    $a['item']['#attributes'] = array(
      'class' => array($vars['classes_array'][$id]),
      'data-drag' => array($vars['dd_args'][$id]),
      'data-crc' => array($vars['crc'][$id])
    );
    $w = $vars['classes_wrapper'];
    $b .= '<div class="' . $w . '">' . render($a) . '</div>';
  }
  $group = array(
    '#theme' => 'fieldset',
    '#title' => $vars['title'],
    '#value' => $b,
    '#collapsible' => TRUE,
    '#collapsed' => $t,
    '#attributes' => array('class' => array('collapsible', $t ? 'collapsed' : '')),
    '#attached' => array('js' => array('misc/form.js', 'misc/collapse.js'))
  );
  $vars['group'] = render($group);
}

function xoxo_preprocess_field(&$variables, $hook) {
  $e = array_key_exists('element', $variables) ? $variables['element'] : FALSE;
  $f = array_key_exists('#formatter', $e) ? $e['#formatter'] : FALSE;
  $t = array_key_exists('terms', $e) ? $e['terms'] : FALSE;
  $d = array_key_exists('data', $e) ? $e['data'] : FALSE;
  if (($f == 'field_xoxo_shopping_list_item_formatter' || $f == 'field_xoxo_shopping_list_item_mail_formatter') && is_array($t) && is_array($d)) {
    drupal_add_library('system', 'drupal.collapse');
    $empty_groups = array_fill_keys(array_keys($d), array(
      '#theme' => 'fieldset',
      '#collapsible' => TRUE,
      '#collpsed' => TRUE,
      '#attached' => array('js' => array('misc/form.js', 'misc/collapse.js')),
      '#attributes' => array('class' => array('item-category', 'collapsible', 'collapsed')),
      '#mail' => ($f == 'field_xoxo_shopping_list_item_mail_formatter'),
      '#print' => ($variables['element']['#view_mode'] == 'print_view')
    ));
    foreach ($d as $id => $group) {
      $empty_groups[$id]['#title'] = $t[$id];
      $empty_groups[$id]['#value'] = implode('', array_map('drupal_render', $e['data'][$id]));
      $empty_groups[$id]['#attributes']['class'][] = 'item-category-' . $id;
    }
    $variables['groups'] = implode('', array_map('drupal_render', $empty_groups));
    if($f == 'field_xoxo_shopping_list_item_mail_formatter') {
      $variables['theme_hook_suggestions'][] = 'field__field_shopping_list_items__mail';
    }
    if($variables['element']['#view_mode'] == 'print_view') {
      $variables['theme_hook_suggestions'][] = 'field__field_shopping_list_items__print';
    }
  }
}

function xoxo_preprocess_fieldset(&$vars) {
  if(isset($vars['element']['#mail']) && $vars['element']['#mail']) {
    $vars['theme_hook_suggestions'][] = 'fieldset__shopping_list__mail';
  }
  elseif(isset($vars['element']['#print']) && $vars['element']['#print']) {
    $vars['theme_hook_suggestions'][] = 'fieldset__shopping_list__print';
  }
}
function xoxo_preprocess_page(&$vars) {
  /* if(empty($GLOBALS['user']->uid)) { */
  /*   //    array_unshift($vars['main_menu'], array('href' => 'user/register', 'title' => 'Shopping List')); */
  /*   $vars['main_menu']['menu-564']['href'] = 'user/register'; */
  /*   $vars['main_menu']['menu-820']['href'] = 'user/register'; */
  /*   //    array_unshift($vars['main_menu'], array('href' => 'user/register', 'title' => 'My Kitchen')); */
  /* } */
  if(arg(0) == 'xoxo-popup') {
    unset($vars['page']['content']['content']['user_first']);
    unset($vars['page']['content']['content']['sidebar_first']);
    unset($vars['page']['content']['content']['sidebar_second']);
  }
  if(arg(0) == 'shopping-list' && (arg(2) == 'print' || arg(1) == 'print')) {
    $vars['main_block'] =
      isset($vars['page']['content']['content']['content']['system_main'])
      ? $vars['page']['content']['content']['content']['system_main']
      : '';
    $vars['theme_hook_suggestions'][] = 'page__shopping_list__print';
  }
  switch(request_path()){
  case 'user/register': drupal_set_title('Join For Free!'); break;
  case 'kitchen': $vars['title'] = ''; break;
  case 'shopping-list': $vars['title'] = ''; break;
  case 'kitchen-setup': $vars['title'] = ''; break;
  case 'node/add/recipe': $vars['title'] = '<div class="cr_m">Create</div><div class="cr_sb">A Recipe</div>'; break;
  }

  if(arg(0) == 'node' && is_numeric(arg(1))) {
    global $user;
    if(!empty($user->roles[5]) && count($user->roles) == 2) {
      $node = node_load(arg(1));
      if($node->type == 'recipe') {
        $vars['tabs'] = '';
      }
    }
  }
}

/*-----Remove Action Link on Recipe Page-----*/
function xoxo_menu_local_action($variables) {
  $link = $variables['element']['#link'];
  $output = '<li>';
  if (isset($link['href'])) {
    $output .= l($link['title'], $link['href'], isset($link['localized_options']) ? $link['localized_options'] : array());
  }
  elseif (!empty($link['localized_options']['html'])) {
    $output .= $link['title'];
  }
  else {
    $output .= check_plain($link['title']);
  }
  $output .= "</li>\n";
  if (isset($variables['node'])) {
    if ($variables['node']->type == 'recipe') {
      return false;
    }
    else{
      return $output;
    }
  }
}

function xoxo_preprocess_node(&$vars) {
  if(arg(0) == 'xoxo-popup') {
    $vars['theme_hook_suggestions'][] = 'node__xoxo_popup';
  }
  //dsm($vars);
}
/*


function xoxo_recipe_node_form($form) {
  $form['title']['#attributes']['placeholder'] = 'Member Name or E-mail';                 // ???????? ???? "????????? ????"
  /*$form['author']['#access'] = false;               // ???????? ???? "?????????? ?? ??????"
  $form['revision_information']['#access'] = false; // ???????? ???? "?????????? ? ????????"
  $form['path']['#access'] = false;                 // ???????? ???? "????????? ??????"
  $form['options']['#access'] = false;              // ???????? ???? "????????? ??????????"

  return drupal_render($form);

  $variables['subtitle'] = $user->name;

}*/

/*function xoxo_file($variables) {
  $element = $variables['element'];
    $element['#attributes']['type'] = 'file';
    element_set_attributes($element, array('id', 'name', 'size'));
    _form_set_class($element, array('form-file'));

    return '<input' . drupal_attributes($element['#attributes']) . ' /><div class="666"></div>';
}*/

function xoxo_pager($variables) {
  $tags = $variables['tags'];
  $element = $variables['element'];
  $parameters = $variables['parameters'];
  $quantity = $variables['quantity'];
  global $pager_page_array, $pager_total;

  // Calculate various markers within this pager piece:
  // Middle is used to "center" pages around the current page.
  $pager_middle = ceil($quantity / 2);
  // current is the page we are currently paged to
  $pager_current = $pager_page_array[$element] + 1;
  // first is the first page listed by this pager piece (re quantity)
  $pager_first = $pager_current - $pager_middle + 1;
  // last is the last page listed by this pager piece (re quantity)
  $pager_last = $pager_current + $quantity - $pager_middle;
  // max is the maximum page number
  $pager_max = $pager_total[$element];
  // End of marker calculations.

  // Prepare for generation loop.
  $i = $pager_first;
  if ($pager_last > $pager_max) {
    // Adjust "center" if at end of query.
    $i = $i + ($pager_max - $pager_last);
    $pager_last = $pager_max;
  }
  if ($i <= 0) {
    // Adjust "center" if at start of query.
    $pager_last = $pager_last + (1 - $i);
    $i = 1;
  }
  // End of generation loop preparation.

  $li_first = theme('pager_first', array('text' => (isset($tags[0]) ? $tags[0] : t('First Page')), 'element' => $element, 'parameters' => $parameters));
  $li_previous = theme('pager_previous', array('text' => (isset($tags[1]) ? $tags[1] : t('Previous Page')), 'element' => $element, 'interval' => 1, 'parameters' => $parameters));
  $li_next = theme('pager_next', array('text' => (isset($tags[3]) ? $tags[3] : t('Next Page')), 'element' => $element, 'interval' => 1, 'parameters' => $parameters));
  $li_last = theme('pager_last', array('text' => (isset($tags[4]) ? $tags[4] : t('Last Page')), 'element' => $element, 'parameters' => $parameters));

  if ($pager_total[$element] > 1) {
    if ($li_first) {
      $items[] = array(
        'class' => array('pager-first'),
        'data' => $li_first,
      );
    }
    if ($li_previous) {
      $items[] = array(
        'class' => array('pager-previous'),
        'data' => $li_previous,
      );
    }

    // When there is more than one page, create the pager list.
    if ($i != $pager_max) {
      if ($i > 1) {
        $items[] = array(
          'class' => array('pager-ellipsis'),
          'data' => '�',
        );
      }
      // Now generate the actual pager piece.
      for (; $i <= $pager_last && $i <= $pager_max; $i++) {
        if ($i < $pager_current) {
          $items[] = array(
            'class' => array('pager-item'),
            'data' => theme('pager_previous', array('text' => $i, 'element' => $element, 'interval' => ($pager_current - $i), 'parameters' => $parameters)),
          );
        }
        if ($i == $pager_current) {
          $items[] = array(
            'class' => array('pager-current'),
            'data' => $i,
          );
        }
        if ($i > $pager_current) {
          $items[] = array(
            'class' => array('pager-item'),
            'data' => theme('pager_next', array('text' => $i, 'element' => $element, 'interval' => ($i - $pager_current), 'parameters' => $parameters)),
          );
        }
      }
      if ($i < $pager_max) {
        $items[] = array(
          'class' => array('pager-ellipsis'),
          'data' => '�',
        );
      }
    }
    // End generation.
    if ($li_next) {
      $items[] = array(
        'class' => array('pager-next'),
        'data' => $li_next,
      );
    }
    if ($li_last) {
      $items[] = array(
        'class' => array('pager-last'),
        'data' => $li_last,
      );
    }
    return '<h2 class="element-invisible">' . t('Pages') . '</h2>' . theme('item_list', array(
      'items' => $items,
      'attributes' => array('class' => array('pager')),
    ));
  }
}

function xoxo_js_alter(&$javascript) {
  $file = drupal_get_path('theme', 'xoxo') . '/js/autocomplete.js';
  $javascript['misc/autocomplete.js'] = drupal_js_defaults($file);

  $file_1 = drupal_get_path('theme', 'xoxo') . '/js/file.js';
  $javascript['modules/file/file.js'] = drupal_js_defaults($file_1);
}

function xoxo_preprocess_html(&$variables) {
  if(arg(0) === 'shopping-list' && arg(2) === 'print') {
    $variables['theme_hook_suggestions'][] = 'html__shopping_list__print';
  }
}

function xoxo_preprocess_block(&$vars) {
  if ($vars['block_html_id'] == 'block-user-login') {
    switch(request_path()){
      case 'user/register': $vars['elements']['#block']->subject = 'Already A Member!'; break;
      case '': $vars['elements']['#block']->subject = 'Start Sharing Your Recipes today!'; break;
    }
  }
}

function xoxo_menu_alter(&$items)
{
  if (isset($items['user/login'])) {
    $items['user/login']['title'] = 'Log In';
  }
}