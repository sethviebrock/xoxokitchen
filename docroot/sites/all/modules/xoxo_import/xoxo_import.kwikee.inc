<?php
// info: xoxo_import.kwikee.module, v1.0 2012/3/26 Segei Churilo
//define('KWIKEE_URL', 'http://dev.kwikeesystems.com/KLS/sync_server?func=');
define('KWIKEE_URL', 'http://www.kwikeesystems.com/KLS/sync_server?func=');
define('KWIKEE_FUNC_GET_INSTRUCTIONS', 'get_instructions');
define('KWIKEE_FUNC_WAIT', 'wait');
define('KWIKEE_FUNC_SUCCESS', 'datafile_download_ok&file=');

define('KWIKEE_UPDATE_ACTION', 'UPDATE');
define('KWIKEE_DELETE_ACTION', 'DELETE');
define('KWIKEE_INSERT_ACTION', 'INSERT');

define('KWIKEE_MANUFACTURERS_TABLE', 'xoxo_manufacturers');
define('KWIKEE_BRANDS_TABLE', 'xoxo_brands');
define('KWIKEE_CATEGORY_TABLE', 'xoxo_category');

define('KWIKEE_BATCH_SIZE', 120);

define('KWIKEE_ENTITY_M', 'manufacturer');
define('KWIKEE_ENTITY_B', 'brand');
define('KWIKEE_ENTITY_P', 'product');
define('KWIKEE_ENTITY_I', 'image');

define('KWIKEE_CATEGORY_OTHER', 'Other');

function _xoxo_import_callback_admin_kwikee_settings() {
  if(isset($_SESSION['massive_import_fids'])) {
    unset($_SESSION['massive_import_fids']);
  }
  $form = array();
  $form['kwikee_form_setting'] = array(
    '#type' => 'fieldset',
    '#title' => t('Module settings'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  $form['kwikee_form_setting']['xoxo_import_path'] = array(
    '#type' => 'textfield', 
    '#title' => t('Import file system path'), 
    '#default_value' => variable_get('xoxo_import_path', ''), 
    '#maxlength' => 255, 
    '#description' => t('An existing local file system path for storing private files. It should be writable by Drupal and not accessible over the web. See the online handbook for <a href="@handbook">more information about securing private files</a>.', array('@handbook' => 'http://drupal.org/documentation/modules/file')), 
    '#after_build' => array('system_check_directory'),
    '#required' => TRUE,
  );
  $files = _xoxo_import_kwikee_uploaded_files();
  $archived = 0;
  $archived_files = array();
  $queue = 0;
  $queue_files = array();
  foreach($files as $i => $file) {
    if($file->status) {
      $archived++;
      $archived_files[] = $file;
    }
    else {
      $queue++;
      $queue_files[] = $file;
    }
  }
  if(!empty($files)) {
    $form['kwikee_uploaded_files'] = array(
      '#title' => t('Kwikee data files'),
      '#type' => 'fieldset',
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
    );
    $form['kwikee_uploaded_files']['data_table_queue'] = array(
      '#title' => t('Queue'),
      '#type' => 'fieldset',
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
    );
    $form['kwikee_uploaded_files']['data_table_queue']['table'] = array(
      '#markup' => theme('xoxo_import_kwikee_files', array('data' => $queue_files, 'offset' => $archived)),
    );
    
    $form['kwikee_uploaded_files']['data_table'] = array(
      '#title' => t('Archive'),
      '#type' => 'fieldset',
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
    );
    $form['kwikee_uploaded_files']['data_table']['table'] = array(
      '#markup' => theme('xoxo_import_kwikee_files', array('data' => $archived_files)),
    );
    
    $form['kwikee_uploaded_files']['massive_import'] = array(
      '#title' => t('Massive import'),
      '#type' => 'fieldset',
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
    );
    $scope = _xoxo_kwikee_get_scope($files);
    $form['kwikee_uploaded_files']['massive_import']['xoxo_kwikee_scope'] = array(
      '#type' => 'textfield',
      '#title' => t('Massive import(reimport) scope'),
      '#default_value' => $scope,
      '#description' => t('To import files from #a to #b enter "#a:#b". For example, if need to import files from id 4 to id 19 - "4:19".'),
    ); 
    $mapper_options = array();
    foreach(_xoxo_import_kwikee_mappers(TRUE) as $mname => $mapper) {
      $mapper_options[$mname] = $mapper['label'];
    }
    $form['kwikee_uploaded_files']['massive_import']['xoxo_kwikee_import_mappers'] = array(
      '#type' => 'checkboxes',
      '#title' => t('Fields'),
      '#default_value' => variable_get('xoxo_kwikee_import_mappers', array()),
      '#description' => t('Select fields for import(reimport).'),
      '#options' => $mapper_options,
    ); 
    $form['kwikee_uploaded_files']['massive_import']['massive_import_run'] = array(
      '#type' => 'submit',
      '#value' => t('Run massive import'),
    );
  }

  $form['kwikee_field_mapping'] = array(
    '#title' => t('Kwikee product field mapping'),
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $kwikee_fields = _xoxo_import_kwikee_fields();
  $tokens = implode('%<br/>%', _xoxo_import_kwikee_additional_tokens()+$kwikee_fields).'%';
  $tokens = '%'.$tokens;
  $form['kwikee_field_mapping']['tokens'] = array(
    '#title' => t('Tokens'),
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['kwikee_field_mapping']['tokens']['list'] = array(
    '#markup' => $tokens,
  );

  foreach(_xoxo_import_kwikee_mappers(TRUE) as $mname => $mapper) {
    if(isset($mapper['type']) && $mapper['type'] == 'complex') {
      $form['kwikee_field_mapping'][$mname] = array(
        '#type' => 'textfield',
        '#title' => $mapper['label'],
        '#default_value' => variable_get($mname, 0),
        '#description' => t('You can use tokens to combine several values.'),
        '#required' => TRUE,
        '#disabled' => !$mapper['status'],
      );
    }
    else {
      $form['kwikee_field_mapping'][$mname] = array(
        '#type' => 'select',
        '#title' => $mapper['label'],
        '#default_value' => variable_get($mname, 0),
        '#options' => $kwikee_fields,
        '#multiple' => (!empty($mapper['multiple'])) ? TRUE : FALSE,
        '#disabled' => !$mapper['status'],
        '#description' => (!empty($mapper['description'])) ? $mapper['description'] : '',
      );
      if(!empty($mapper['multiple'])) {
        $form['kwikee_field_mapping'][$mname]['#attributes'] = array(
          'style' => 'height: 500px;',
        );
      }
    }
  }

  $form['kwikee_upload'] = array(
    '#title' => t('Upload XML file'),
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['kwikee_upload']['xoxo_kwikee_import_upload'] = array(
    '#title' => t('XML file'),
    '#type' => 'managed_file',
    '#description' => t('Upload XML-file with XOXO components compatible with Kwikee service.'),
    '#default_value' => '',
    '#upload_location' => 'xoxoimport://',
    '#progress_indicator' => 'throbber',
    '#upload_validators' => array(
      'file_validate_extensions' => array('xml'),
    ),
  );
  $files_additional = _xoxo_import_kwikee_uploaded_files(NULL, 'kwikee_third_party');
  $form['kwikee_upload']['table'] = array(
    '#markup' => theme('xoxo_import_kwikee_files', array('data' => $files_additional)),
  );
  
/*  $form['kwikee_clear'] = array(
    '#title' => t('Delete Components'),
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['kwikee_clear']['warning'] = array(
    '#title' => t('Warning! Operation cannot be undone!'),
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['kwikee_clear']['warning']['delete_components'] = array(
    '#type' => 'submit',
    '#value' => t('Delete All Components!'),
  );*/

  $form['kwikee_access'] = array(
    '#title' => t('Access credentials to Kwikee'),
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['kwikee_access']['kwikee_user'] = array(
    '#type' => 'textfield',
    '#title' => t('User name'),
    '#default_value' => variable_get('kwikee_user', ''),
  );
  $form['kwikee_access']['kwikee_password'] = array(
    '#type' => 'textfield',
    '#title' => t('Password'),
    '#default_value' => variable_get('kwikee_password', ''),
  );

  $form['kwikee_cron'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable updates on cron'),
    '#description' => t('Use cron runs to get new updates and import new items.'),
    '#default_value' => variable_get('kwikee_cron', 0),
  );

  $form['check_remote'] = array(
    '#type' => 'submit',
    '#value' => t('Check for updates'),
  );

  $form['#submit'][] = '_xoxo_import_callback_admin_kwikee_settings_submit';

  return system_settings_form($form);
}

function _xoxo_kwikee_get_scope($files, $scope = NULL) {
  $status = (bool) is_null($scope);
  if(is_null($scope) && variable_get('xoxo_kwikee_scope', FALSE)) {
    $scope = variable_get('xoxo_kwikee_scope', FALSE);
  }
  
  $scope = explode(':', $scope);
  if(count($scope) == 2 && is_numeric($scope[0]) && is_numeric($scope[1]) && $scope[0] <= $scope[1] && $scope[0] <= count($files)) {
    if($scope[1] > count($files)) {
      $scope[1] = count($files);
    }
    $scope = $scope[0].':'.$scope[1];
    return $scope;
  }
  elseif($status) {
    $scope = '1:'.count($files);
     return $scope;
  }
  
  return FALSE;
}

    
function _xoxo_import_kwikee_mappers($all = FALSE) {
  $mappers = array(
    'xik_node_title' => array(
      'label' => t('Node title'),
      'multiple' => 0,
      'type' => 'complex',
      'callback' => '_xoxo_import_kwikee_set_title',
      'base' => TRUE,
    ),
    'xik_component_id' => array(
      'label' => t('Component id'),
      'multiple' => 0,
      'callback' => '_xoxo_import_kwikee_set_component_id',
      'description' => t('For normal Kwikee components ids are lays between 0 and 2000000000. For USDA (format: [usdaxxxxx]) - upper than 2000000000.')
    ),

    'xik_category_level_1' => array(
      'label' => t('Category level #1'),
      'multiple' => 0,
    ),
    'xik_category_level_2' => array(
      'label' => t('Category level #2'),
      'multiple' => 0,
    ),
    'xik_category_level_3' => array(
      'label' => t('Category level #3'),
      'multiple' => 0,
    ),
    'xik_category_level_4' => array(
      'label' => t('Category level #4'),
      'multiple' => 0,
      'callback' => '_xoxo_import_kwikee_set_category',
      'allow_empty' => 1,
    ),

    'xik_category_id' => array(
      'label' => t('Section id'),
      'multiple' => 0,
      'callback' => '_xoxo_import_kwikee_set_section_id',
    ),
    'xik_category' => array(
      'label' => t('Section name'),
      'multiple' => 0,
    ),
    'xik_upc' => array(
      'label' => t('UPC'),
      'multiple' => 0,
      'callback' => '_xoxo_import_kwikee_set_upc',
    ),
    'xik_manufacturer' => array(
      'label' => t('Manufacturer'),
      'multiple' => 0,
      'callback' => '_xoxo_import_kwikee_set_manufacturer',
    ),
    'xik_brand' => array(
      'label' =>  t('Brand'),
      'multiple' => 0,
      'callback' => '_xoxo_import_kwikee_set_brand',
    ),
    'xik_name' => array(
      'label' => t('Name'),
      'multiple' => 0,
      'callback' => '_xoxo_import_kwikee_set_name',
    ),
    'xik_description' => array(
      'label' => t('Description'),
      'multiple' => 0,
      'callback' => '_xoxo_import_kwikee_set_description',
    ),
    'xik_size' => array(
      'label' => t('Size'),
      'multiple' => 0,
      'callback' => '_xoxo_import_kwikee_set_size',
    ),
    'xik_uom' => array(
      'label' => t('UOM'),
      'multiple' => 0,
      'callback' => '_xoxo_import_kwikee_set_uom',
    ),
  /*  'xik_i_size' => array(
      'label' => t('I Size'),
      'multiple' => 0,
      'callback' => '_xoxo_import_kwikee_set_i_size',
    ),
    'xik_i_uom' => array(
      'label' => t('I UOM'),
      'multiple' => 0,
      'callback' => '_xoxo_import_kwikee_set_i_uom',
    ),*/
    'xik_serving_size' => array(
      'label' => t('Serving size'),
      'multiple' => 0,
      'callback' => '_xoxo_import_kwikee_set_serving_size',
    ),
    'xik_serving_size_uom' => array(
      'label' => t('Serving size UOM'),
      'multiple' => 0,
      'callback' => '_xoxo_import_kwikee_set_serving_uom',
    ),
    'xik_i_serving_size' => array(
      'label' => t('I Serving size'),
      'multiple' => 0,
      'callback' => '_xoxo_import_kwikee_set_serving_i_size',
    ),
    'xik_i_serving_size_uom' => array(
      'label' => t('I Serving size UOM'),
      'multiple' => 0,
      'callback' => '_xoxo_import_kwikee_set_serving_i_uom',
    ),
    'xik_package' => array(
      'label' => t('Package'),
      'multiple' => 1,
      'callback' => '_xoxo_import_kwikee_set_package',
    ),
    'xik_nutritional' => array(
      'label' => t('Nutritional data'),
      'multiple' => 1,
      'callback' => '_xoxo_import_kwikee_set_nutritional',
    ),
    'xik_other' => array(
      'label' => t('Other'),
      'multiple' => 1,
      'callback' => '_xoxo_import_kwikee_set_other',
    ),
  );

  $mappers_selected = variable_get('xoxo_kwikee_import_mappers', array());
  $mappers_selected = array_filter($mappers_selected, '_xoxo_kwikee_selected_items');
  foreach($mappers as $mapper_name => $mapper) {
    $mappers[$mapper_name]['status'] = TRUE;
    if(!in_array($mapper_name, $mappers_selected)) {
      if(!$all) {
        unset($mappers[$mapper_name]);
      }
      else {
        $mappers[$mapper_name]['status'] = FALSE;
      }
    }
  }

  return $mappers;
}

function _xoxo_import_callback_admin_kwikee_settings_submit($form, &$form_state) {
  if($form_state['values']['xoxo_kwikee_import_upload']) {
    $file = file_load($form_state['values']['xoxo_kwikee_import_upload']);
    if($file) {
      $file->status = FILE_STATUS_PERMANENT;
      file_save($file);
      file_usage_add($file, 'xoxo_import', 'kwikee_third_party', 0);
      unset($form_state['values']['xoxo_kwikee_import_upload']);
    }
  }

  if($form_state['clicked_button']['#id'] == 'edit-check-remote' && !empty($form_state['values']['check_remote']) && !empty($form_state['values']['kwikee_user']) && !empty($form_state['values']['kwikee_password'])) {
    _xoxo_import_kwikee_check_remote($form_state);
  }
  elseif ($form_state['clicked_button']['#id'] == 'edit-delete-components') {
/*  $files = _xoxo_import_kwikee_uploaded_files();
    $q = "UPDATE {file_usage} SET id = :processed WHERE fid = :fid";
    foreach($files as $obj) {
      variable_del('xoxo_import_kwikee_fid_'.$obj->fid);
      db_query($q, array(':processed' => 0,':fid' => $obj->fid));
    }

    $q = "
      DELETE `node_revision`
      FROM `node_revision`
      INNER JOIN `node` ON node.nid = node_revision.nid
      WHERE node.type = '".XOXO_IMPORT_CTYPE."';

      DELETE `taxonomy_index`
      FROM `taxonomy_index`
      INNER JOIN `node` ON node.nid = taxonomy_index.nid
      WHERE node.type = '".XOXO_IMPORT_CTYPE."';

      DELETE FROM `node` WHERE `type` = '".XOXO_IMPORT_CTYPE."';

      DELETE `taxonomy_term_hierarchy`
      FROM `taxonomy_term_hierarchy`
      INNER JOIN `taxonomy_term_data` ON taxonomy_term_data.tid = taxonomy_term_hierarchy.tid
      WHERE taxonomy_term_data.vid IN (".XOXO_IMPORT_CAT_VID.",".XOXO_IMPORT_CAT_ITEM_NAME_VID.",". XOXO_IMPORT_UOM_VID.");

      DELETE FROM `taxonomy_term_data` WHERE vid IN (".XOXO_IMPORT_CAT_VID.",".XOXO_IMPORT_CAT_ITEM_NAME_VID.",". XOXO_IMPORT_UOM_VID.",16,17,18);

      TRUNCATE TABLE `field_data_field_component_id`;
      TRUNCATE TABLE `field_revision_field_component_id`;

      TRUNCATE TABLE `field_data_field_component_category`;
      TRUNCATE TABLE `field_revision_field_component_category`;

      TRUNCATE TABLE `field_data_field_component_category_2`;
      TRUNCATE TABLE `field_revision_field_component_category_2`;

      TRUNCATE TABLE `field_data_field_component_category_3`;
      TRUNCATE TABLE `field_revision_field_component_category_3`;

      TRUNCATE TABLE `field_data_field_component_category_4`;
      TRUNCATE TABLE `field_revision_field_component_category_4`;

      TRUNCATE TABLE `field_data_field_component_upc_a`;
      TRUNCATE TABLE `field_revision_field_component_upc_a`;

      TRUNCATE TABLE `field_data_field_component_description`;
      TRUNCATE TABLE `field_revision_field_component_description`;

      TRUNCATE TABLE `field_data_field_component_size`;
      TRUNCATE TABLE `field_revision_field_component_size`;

      TRUNCATE TABLE `field_data_field_component_section_id`;
      TRUNCATE TABLE `field_revision_field_component_section_id`;

      TRUNCATE TABLE `field_data_field_component_uom`;
      TRUNCATE TABLE `field_revision_field_component_uom`;

      TRUNCATE TABLE `field_data_field_component_serving_size`;
      TRUNCATE TABLE `field_revision_field_component_serving_size`;

      TRUNCATE TABLE `field_data_field_component_serving_size_uom`;
      TRUNCATE TABLE `field_revision_field_component_serving_size_uom`;

      TRUNCATE TABLE `field_data_field_component_l_serving_size`;
      TRUNCATE TABLE `field_revision_field_component_l_serving_size`;


      TRUNCATE TABLE `field_data_field_component_l_serving_size_u`;
      TRUNCATE TABLE `field_revision_field_component_l_serving_size_u`;

      TRUNCATE TABLE `field_data_field_component_package`;
      TRUNCATE TABLE `field_revision_field_component_package`;

      TRUNCATE TABLE `field_data_field_component_nutritional`;
      TRUNCATE TABLE `field_revision_field_component_nutritional`;

      TRUNCATE TABLE `field_data_field_component_manufacturer`;
      TRUNCATE TABLE `field_revision_field_component_manufacturer`;

      TRUNCATE TABLE `field_data_field_component_brand`;
      TRUNCATE TABLE `field_revision_field_component_brand`;

      TRUNCATE TABLE `field_data_field_component_name`;
      TRUNCATE TABLE `field_revision_field_component_name`;

      TRUNCATE TABLE `field_data_field_component_other`;
      TRUNCATE TABLE `field_revision_field_component_other`;


      TRUNCATE TABLE `xoxo_category`;
      TRUNCATE TABLE `xoxo_manufacturers`;
      TRUNCATE TABLE `xoxo_containers`;
      TRUNCATE TABLE `xoxo_brands`;
      TRUNCATE TABLE `xoxo_names`;";

    db_query($q);
    drupal_set_message(t('All components have been deleted.'));*/
  }
  elseif($form_state['clicked_button']['#id'] == 'edit-massive-import-run') {
    _xoxo_kwikee_massive_import($form_state['values']['xoxo_kwikee_import_mappers'], $form_state['values']['xoxo_kwikee_scope']);
  }
}

function _xoxo_kwikee_massive_import($mappers, $scope) {
  $mappers = array_filter($mappers, '_xoxo_kwikee_selected_items');
  $files = _xoxo_import_kwikee_uploaded_files();
  $scope = _xoxo_kwikee_get_scope($files, $scope);
  
  if(!$scope) {
    drupal_set_message('Invalid scope!');
    return FALSE;
  }
  
  $scope = explode(':', $scope);
  $scope[0]--;
  $scope[1]--;
  $fids = array();
  while($scope[0] <= $scope[1]) {
    $fids[] = $files[$scope[0]]->fid;
    $scope[0]++;
  }

  $fid = array_shift($fids);
  $_SESSION['massive_import_fids'] = $fids;
  drupal_goto('xoxo-import-kwikee/import/'.$fid);
}

function _xoxo_kwikee_selected_items($v) {
  return (bool) $v;
}

function _xoxo_import_kwikee_check_remote($form_state, $cron = FALSE) {
  $response = array(
    'message' => '',
    'status' => FALSE
  );

  // check if kwikee server is ready
  $result = _xoxo_import_kwikee_process_request(KWIKEE_FUNC_WAIT);
  if(!$result['status']) {
    $response['message'] = $result['message'];
    return $response;
  }
  if((int)$result['result'] > 0) {
    $response['message'] = t('Kwikee is busy. Need to wait :time seconds to next update.', array(':time' => (int)$result['result']));
    if(!$cron) {
      drupal_set_message($response['message']);
    }
    return $response;
  }

  // check for updates
  $result = _xoxo_import_kwikee_process_request(KWIKEE_FUNC_GET_INSTRUCTIONS);
  if(!$result['status']) {
    $response['message'] = $result['message'];
    return $response;
  }
  if(empty($result['result']['datafile']['URL'])) {
    $response['message'] = t('URL for downloading file is not provided.');
    return $result;
  }
  if(is_array($result['result']['datafile']['URL'])) {
    foreach($result['result']['datafile']['URL'] as $k => $u) {
      if(substr($u, -3) != 'zip') {
        unset($result['result']['datafile']['URL'][$k]);
      }
    }
    $u = $result['result']['datafile']['URL'];
  }
  elseif(substr($result['result']['datafile']['URL'], -3) == 'zip') {
    $u = array($result['result']['datafile']['URL']);
  }
  if(empty($u)){
    $response['message'] = t('Remote file is not in ZIP format.');
    return $result;
  }
  $count = 0;
  // download remote file to "files" directory
  foreach($u as $file_url) {
    $count = $count + (int)_xoxo_import_kwikee_save_file($file_url);
  }

  if(!$cron) {
    if($count) {
      drupal_set_message(t(':count file(s) uploaded successfully.', array(':count' => $count)));
    }
    else {
      drupal_set_message(t('No new files found.', array()));
    }
  }
  else {
    $response['count'] = $count;
  }

  $response['status'] = TRUE;

  return $response;
}

function _xoxo_import_kwikee_update_success($filename) {
  $result = _xoxo_import_kwikee_process_request(KWIKEE_FUNC_SUCCESS.$filename);
  if($result['status'] && !$result['result']) {
    return TRUE;
  }

  return FALSE;
}

/*
 * Download remote file to "files" directory
 */
function _xoxo_import_kwikee_save_file($file_url) {
  $info = pathinfo($file_url);
  $zip_file_name =  basename($file_url,'.'.$info['extension']);

  $uploaded_files = _xoxo_import_kwikee_uploaded_files();
  foreach($uploaded_files as $delta => $fobj) {
    if(strpos($fobj->name, '__'.$zip_file_name.'__') !== FALSE) {
      return FALSE;
    }
  }

  $time_mark = date('Y_m_d_H_i_s');
  $files_dir = drupal_realpath('xoxoimport://').'/';
  $temp_dir = drupal_realpath('xoxoimport://').'/';
  $file_path = $files_dir.'temp_'.$time_mark.'.zip';

  $curl = curl_init($file_url);
  $fp = @fopen($file_path, "w");
  curl_setopt($curl, CURLOPT_HTTPAUTH, CURLAUTH_BASIC);
  curl_setopt($curl, CURLOPT_USERPWD, "xoxo_kitchen:sync_xml");
  curl_setopt($curl, CURLOPT_TIMEOUT, '3');
  curl_setopt($curl, CURLOPT_USERAGENT, 'XOXO Kitchen');
  
  
 // curl_setopt($curl, CURLOPT_SSLVERSION,3);
 // curl_setopt($curl, CURLOPT_SSL_VERIFYPEER, FALSE);
 // curl_setopt($curl, CURLOPT_SSL_VERIFYHOST, 2);
  curl_setopt($curl, CURLOPT_FILE, $fp);
  curl_setopt($curl, CURLOPT_HEADER, 0);
  curl_exec($curl);
  curl_close($curl);
  fclose($fp);
  
  chmod($file_path, 0664);

  // delete file if it is empty
  if(!filesize($file_path)) {
    unlink($file_path);
    return FALSE;
  }

  // unzip data file
  $zip = new ZipArchive;
  if($zip->open($file_path) === TRUE) {
    $files = array();
    for($i = 0; $i < $zip->numFiles; $i++) {
      $files[] = $zip->getNameIndex($i);
    }
    if(!empty($files)) {
      $zip->extractTo($temp_dir);
    }

    $zip->close();
    unlink($file_path);

    // create drupal native files
    $successful_files = 0;
    foreach($files as $file_name){
      $f_part = explode('.', $file_name);
      $f_part = (!empty($f_part[0])) ? $f_part[0] : $file_name;
      $f_name = 'kwikee__'.$zip_file_name.'__'.$f_part.'.xml';
      $f_path = $temp_dir.$f_name;
      
      rename($temp_dir.$file_name, $f_path);
      
      // check for emptyness of the file
      if(filesize($f_path) < 200) {
        watchdog('xoxo_import', 'Empty update file @file found.', array('@file' => $file_name), WATCHDOG_NOTICE);
      }
      else {
        // Create managed File object
        $file = (object) array(
          'uid' => 1,
          'filename' => $f_name,
          'uri' => 'xoxoimport://' . $f_name,
          'filemime' => file_get_mimetype($f_path),
          'status' => 1,
        );
  
        // save file to "xoxo_import" dir
        $file = file_save($file, 'xoxoimport://', FILE_EXISTS_REPLACE);
        file_usage_add($file, 'xoxo_import', 'kwikee', 0);
        $successful_files++;
      }
    }
    
    return (bool)$successful_files;
  }

  return FALSE;
}

function _xoxo_import_kwikee_process_request($func) {
  $response = array(
    'status' => FALSE,
    'message' => '',
    'result' => NULL,
  );

  $user = variable_get('kwikee_user', '');
  $password = variable_get('kwikee_password', '');

  if(!function_exists('curl_init')) {
    $response['message'] = t('CURL not enabled.');
    return $response;
  }
  if(!function_exists('xmlrpc_decode')) {
    $response['message'] = t('XMLRPC not enabled.');
    return $response;
  }

  $url = KWIKEE_URL.$func;
  $response['url'] = $url;
  $curl = curl_init();
  curl_setopt($curl, CURLOPT_HTTPAUTH, CURLAUTH_BASIC);
  curl_setopt($curl, CURLOPT_USERPWD, "{$user}:{$password}");
  curl_setopt($curl, CURLOPT_TIMEOUT, '3');
  curl_setopt($curl, CURLOPT_USERAGENT, 'XOXO Kitchen');
 // curl_setopt($curl, CURLOPT_SSLVERSION, 3);
 // curl_setopt($curl, CURLOPT_SSL_VERIFYPEER, FALSE);
 // curl_setopt($curl, CURLOPT_SSL_VERIFYHOST, 2);


  //curl_setopt($curl, CURLOPT_POST, TRUE);
  //curl_setopt($curl, CURLOPT_POSTFIELDS, $params);
  curl_setopt($curl, CURLOPT_RETURNTRANSFER, TRUE);
  curl_setopt($curl, CURLOPT_URL, $url);

  if(curl_errno($curl)) {
    $response['message'] = t('CURL error code :code.', array(':code' => curl_errno($curl)));
    return $response;
  }

  $result = curl_exec($curl);
  
  if (strpos($result, 'html')) {
    $response['message'] = $result;
    return $response;
  }
  switch($func) {
    case KWIKEE_FUNC_GET_INSTRUCTIONS: {
      $response['result'] = _xoxo_import_kwikee_parse_xml($result);
      $response['status'] = TRUE;
    } break;
    case KWIKEE_FUNC_WAIT: {
      $response['result'] = $result;
      $response['status'] = TRUE;
    } break;
    default : {
      $response['result'] = $result;
      $response['status'] = TRUE;
    }
  }
  curl_close($curl);

  return $response;
}

/*
 * Convert simpleXml object to associative array recursively
 */
function _xoxo_import_kwikee_parse_xml($xml, $part = NULL, $options = array(), $level = 0) {
  static $i = 0;
  if($xml && is_null($part)) {
    $i = 0;
    $content = new SimpleXMLElement($xml);
    $result = _xoxo_import_kwikee_parse_xml('', $content, $options, $level);
    if(!empty($options['return_size'])) {
      return $i;
    }
    return $result;
  }
  else {
    foreach($part->children() as $child) {
      $index = trim((string)$child->getName());

      $flag = TRUE;

      if(!empty($options)) {
        if($options['level'] < $level || ($level < $options['level'] && in_array($index, $options['element']))) {
          $flag = TRUE;
        }
        elseif($level == $options['level']) {
          if(!empty($options['return_size'])) {
            $flag = FALSE;
          }
          elseif($i >= $options['min'] && $i <= $options['max']) {
            $flag = TRUE;
          }
          else {
            $flag = FALSE;
          }
          $i++;
        }
        else {
          $flag = FALSE;
        }
      }

      if($flag) {
        $value = trim((string)$child);

        if(!$value) {
          $item = _xoxo_import_kwikee_parse_xml('', $child, $options, $level+1);
        }
        else {
          $item = $value;
        }

        if(isset($temp[$index])) {
          if(is_array($temp[$index]) && isset($temp[$index][0])) {
            $temp[$index][] = $item;
          }
          else {
            $temp[$index] = array($temp[$index], $item);
          }
        }
        elseif(!empty($options['level']) && $level == $options['level']) {
          $temp[$index] = array(0 => $item);
        }
        else {
          $temp[$index] = $item;
        }
      }
    }
    if(isset($temp)) {
      return $temp;
    }
  }
}

function theme_xoxo_import_kwikee_files($vars) {
  $header = array(t('Id'), t('File'), t('Size'), t('Date'), t('Status'), t('Operations'));
  $rows = array();
  $r = 0;

  $status_message =
    'IMPORT DATE: @date<br/>
    PROCESSED: @processed items<br/>
    TIME SPENT: @elapsed<br/>
    CRON RUNS: @cron_runs<br/>
    BATCH RUNS: @batch_runs<br/>
    ********** Manufacturers ***********<br/>
    inserted/updated/deleted: @m_insert/@m_update/@m_delete<br/>
    processed/all: @m_all(@m_all_fixed)<br/>
    ********** Brands *******************<br/>
    inserted/updated/deleted: @b_insert/@b_update/@b_delete<br/>
    processed/all: @b_all(@b_all_fixed)<br/>
    ********** Components *************<br/>
    inserted/updated/deleted: @p_insert/@p_update/@p_delete<br/>
    processed/all: @p_all(@p_all_fixed)<br/>';
  
  $status_message_queue =
    'CRON RUNS: @cron<br/>
    BATCH RUNS: @run<br/>
    LAST RUN DATE: @date<br/>
    TIME ELAPSED: @elapsed<br/>
    PROGRESS: processed @processed out of @all (@percent%)<br/>
    ********** Manufacturers ***********<br/>
    inserted/updated/deleted: @m_insert/@m_update/@m_delete<br/>
    processed/all: @m_all(@m_all_fixed)<br/>
    ********** Brands *******************<br/>
    inserted/updated/deleted: @b_insert/@b_update/@b_delete<br/>
    processed/all: @b_all(@b_all_fixed)<br/>
    ********** Components *************<br/>
    inserted/updated/deleted: @p_insert/@p_update/@p_delete<br/>
    processed/all: @p_all(@p_all_fixed)<br/>';
  
  if(isset($vars['offset'])) {
    $i = $vars['offset'];
  }
  else {
    $i = 0;
  }
  
  // queue variables
  $queue_fid = variable_get('xoxo_import_queue_fid', FALSE);
  $queue_context = variable_get('xoxo_import_context', NULL);
  $error_fids = variable_get('xoxo_import_error_fids', array());
  $pending_fid = NULL;
  foreach($vars['data'] as $key => $obj) {
    if(!$obj->status && !$pending_fid && !in_array($obj->fid, $error_fids) && $obj->type != 'kwikee_third_party') {
      $pending_fid = $obj->fid;
    }
    $style = ($pending_fid == $obj->fid) ? 'background-color:#7f7' : '';
    $not_imported = ($pending_fid == $obj->fid) ? t('pending') : t('not imported');
    $ops = array();
    $ops['import'] = l((!$obj->status) ? t('import') : t('repeat import'), 'xoxo-import-kwikee/import/'.$obj->fid);
    $ops['delete'] = l(t('delete'), 'xoxo-import-kwikee/delete/'.$obj->fid);
     
    
    if($queue_fid == $obj->fid) {
      $sb = $queue_context['sandbox'];
      $not_imported = t(
        $status_message_queue, 
        array(
          '@cron' => $sb['crons'],
          '@run' => $sb['run'],
          '@elapsed' => gmdate('z:H:i:s', $sb['elapsed']),
          '@date' => format_date($sb['endtime'], 'medium'),
          '@processed' => $sb['progress'],
          '@all' => $sb['max'],
          '@percent' => ($sb['max'] > 0) ? round($sb['progress']*100/$sb['max'], 1) : 100,
          '@m_insert' => $sb['m_INSERT'],
          '@m_update' => $sb['m_UPDATE'],
          '@m_delete' => $sb['m_DELETE'],
          '@m_all' => $sb['m_INSERT'] + $sb['m_UPDATE'] + $sb['m_DELETE'],
          '@m_all_fixed' => $sb['m_size'],
          '@b_insert' => $sb['b_INSERT'],
          '@b_update' => $sb['b_UPDATE'],
          '@b_delete' => $sb['b_DELETE'],
          '@b_all' => $sb['b_INSERT'] + $sb['b_UPDATE'] + $sb['b_DELETE'],
          '@b_all_fixed' => $sb['b_size'],
          '@p_insert' => $sb['p_INSERT'],
          '@p_update' => $sb['p_UPDATE'],
          '@p_delete' => $sb['p_DELETE'],
          '@p_all' => $sb['p_INSERT'] + $sb['p_UPDATE'] + $sb['p_DELETE'],
          '@p_all_fixed' => $sb['p_size'],
        ) 
      );
      $style = 'background-color:#fea';
    }
    if(in_array($obj->fid, $error_fids)) {
      $style = 'background-color:#f77';
    }
    
    
    $statistics = variable_get('xoxo_import_kwikee_fid_'.$obj->fid, array());
    if(!empty($statistics['@batch_runs'])) {
      $statistics['@batch_runs']++;
    }
    else {
      $statistics['@batch_runs'] = 'N/A';
    }
    if(is_numeric($statistics['@batch_runs'])) {
      $statistics['@cron_runs']++;
    }
    else {
      $statistics['@cron_runs'] = 'N/A';
    }
    
    $status = ($obj->status) ? t($status_message, $statistics) : $not_imported;
    if(in_array($obj->fid, $error_fids) && $queue_fid != $obj->fid) {
      $status = t('error');
    }
    $rows[$r] = array(
      'data' => array(
        'id' => ++$i,
        'name' => l($obj->name, file_create_url($obj->uri)),
        'size' => format_size($obj->size),
        'date' => format_date($obj->date, 'medium'),
        'status' => $status,
        'ops' => theme(
          'item_list',
          array(
            'items' => $ops,
          )
        ),
      ),
    );
    if($style) {
      $rows[$r]['style'] = $style;
    }
    $r++;
  }

  return theme('table', array(
    'header' => $header,
    'rows' => $rows,
  ));
}

function _xoxo_import_kwikee_uploaded_files($not_processed = NULL, $type = 'kwikee') {
  $s = "";
  if(!is_null($not_processed)) {
    $s = "AND {file_usage}.id = 0";
  }
  $q = "
    SELECT
      {file_managed}.fid        AS fid,
      {file_managed}.filename   AS name,
      {file_managed}.uri        AS uri,
      {file_managed}.timestamp  AS date,
      {file_managed}.filesize   AS size,
      {file_usage}.type         AS type,
      {file_usage}.id           AS status
    FROM
      {file_managed}
    LEFT JOIN
      {file_usage} ON {file_managed}.fid = {file_usage}.fid
    WHERE
      {file_usage}.module = 'xoxo_import'
      AND
      {file_usage}.type = :type
      {$s}
    ORDER BY
      {file_managed}.timestamp ASC,
      {file_managed}.filename ASC";
  $result = db_query($q, array(':type' => $type))->fetchAll();

  return $result;
}

function _xoxo_import_kwikee_delete_file_form($form, $args) {
  $fid = $args['build_info']['args'][0];
  $confirm_form = array();
  $confirm_form['fid'] = array(
    '#type' => 'value',
    '#value' => $fid,
  );
  $confirm_form['#redirect'] = 'admin/config/development/xoxo-import-kwikee';
  $q = "
    SELECT
      {file_managed}.filename AS name
    FROM
      {file_managed}
    WHERE
      {file_managed}.fid = :fid";
  $filename = db_query($q, array(':fid' => $fid))->fetchField();

  return confirm_form(
    $confirm_form,
    t('Delete file @fname', array('@fname' => $filename)),
    'admin/config/development/xoxo-import-kwikeet',
    t('Are You sure want to delete file <em>@fname</em>?',
    array('@fname' => $filename)),
    t('Delete'),
    t('Cancel')
  );
}

function _xoxo_import_kwikee_delete_file_form_submit($form, &$form_state) {
  if(isset($form_state['values']['fid'])) {
    $file = file_load($form_state['values']['fid']);
    file_delete($file, TRUE);
    $form_state['redirect'] = array(
      'admin/config/development/xoxo-import-kwikee',
    );
  }
}

function _xoxo_import_kwikee($fid) {
  _xoxo_import_kwikee_batch($fid);
  drupal_flush_all_caches();
  /*
   * successful import

   *
   *
   * run clear cache operation
   */
}

/*
 * Update products
 */
function _xoxo_import_kwikee_update_products($c) {
  $status = array();

  foreach($c as $i => $component) {
    if(!isset($component['product_id'])) {
      continue;
    }
    $cid = strtolower($component['product_id']);
    if(substr($cid, 0, 4) == 'usda') {
      $temp_cid = str_replace('usda', '', $cid);
      $cid = (int)$temp_cid + 2000000000;
      
      // prepare correct product name
      if(!empty($component['name'])) {
        $component['name'] = str_replace(',', ', ', $component['name']);
        $component['name'] = str_replace('  ', ' ', $component['name']);
        $component['name'] = ucwords(strtolower($component['name']));
      }
    }
    $cid = (int)$cid;
    $component['product_id'] = $cid;
    
    
    switch($component['action']) {
      case KWIKEE_INSERT_ACTION: {
        $nid = _xoxo_import_kwikee_check_existens(
          'field_data_field_component_id',
          'field_component_id_value',
          $cid,
          'entity_id'
        );

        if(!$nid) {
          _xoxo_import_kwikee_process_component(KWIKEE_INSERT_ACTION, $component);
          $status[KWIKEE_INSERT_ACTION] = (!empty($status[KWIKEE_INSERT_ACTION])) ? $status[KWIKEE_INSERT_ACTION]+1 : 1;
        }
        else {
          _xoxo_import_kwikee_process_component(KWIKEE_UPDATE_ACTION, $component, $nid);
          $status[KWIKEE_UPDATE_ACTION] = (!empty($status[KWIKEE_UPDATE_ACTION])) ? $status[KWIKEE_UPDATE_ACTION]+1 : 1;
        }
      } break;
      case KWIKEE_UPDATE_ACTION: {
        $nid = _xoxo_import_kwikee_check_existens(
          'field_data_field_component_id',
          'field_component_id_value',
          $cid,
          'entity_id'
        );

        if(!$nid) {
          _xoxo_import_kwikee_process_component(KWIKEE_INSERT_ACTION, $component);
          $status[KWIKEE_INSERT_ACTION] = (!empty($status[KWIKEE_INSERT_ACTION])) ? $status[KWIKEE_INSERT_ACTION]+1 : 1;
        }
        else {
          _xoxo_import_kwikee_process_component(KWIKEE_UPDATE_ACTION, $component, $nid);
          $status[KWIKEE_UPDATE_ACTION] = (!empty($status[KWIKEE_UPDATE_ACTION])) ? $status[KWIKEE_UPDATE_ACTION]+1 : 1;
        }
      } break;
      case KWIKEE_DELETE_ACTION: {
        $delete_status = _xoxo_import_kwikee_delete_component($cid);
        $status[KWIKEE_DELETE_ACTION] = (!empty($status[KWIKEE_DELETE_ACTION])) ? $status[KWIKEE_DELETE_ACTION]+$delete_status : $delete_status;
      } break;
    }
  }

  return $status;
}

/*
 * Process component
 */
function _xoxo_import_kwikee_process_component($op, $component, $nid = NULL) {
  static $fields = array();
  foreach(_xoxo_import_kwikee_mappers() as $var_name => $config) {
    if(!empty($config['callback']) && function_exists($config['callback'])) {
      if(!isset($fields[$var_name])) {
        $fields[$var_name] = variable_get($var_name, NULL);
      }

      if(!empty($config['type']) && $config['type'] == 'complex') {
        $value = trim($fields[$var_name]);
      }
      elseif(!empty($config['multiple'])) {
        $value = array();
        foreach($fields[$var_name] as $key) {
          if(isset($component[$key])) {
            $value[$key] = $component[$key];
          }
        }
        if(empty($value)) {
          continue;
        }
      }
      elseif(isset($component[$fields[$var_name]])) {
        $value = trim($component[$fields[$var_name]]);
      }
      elseif(!empty($config['allow_empty'])) {
        $value = NULL;
      }
      else {
        continue;
      }

      if($op == KWIKEE_INSERT_ACTION && !empty($config['base'])) {
        $nid = call_user_func($config['callback'], $nid, $component, $value, $op);
      }
      else {
        call_user_func($config['callback'], $nid, $component, $value, $op);
      }
    }
  }
}

/*
 * Delete component node
 */
function _xoxo_import_kwikee_delete_component($cid) {  
// First Version
  $query = db_select('field_data_field_component_id', 'c');
  $query->addField('c', 'entity_id', 'component_nid');
  $query->addExpression('COUNT(r.entity_id)', 'recipe_count');
  $query->leftJoin('field_data_field_recipe_ingredients', 'r', 'c.entity_id = r.field_recipe_ingredients_nid');
  $query->condition('c.field_component_id_value', $cid);
  $result = $query->execute();
  $record = $result->fetchAssoc();
  $component_nid = $record['component_nid'];
  if ($component_nid) {
    if ($record['recipe_count'] > 0) {
      $message = '';
      $q = db_select('field_data_field_recipe_ingredients', 'r');
      $q->fields('r', array('entity_id'))
          ->fields('nr', array('title'))
          ->fields('ni', array('title'))
          ->leftJoin('node', 'nr', 'r.entity_id = nr.nid');
      $q->leftJoin('node', 'ni', 'r.field_recipe_ingredients_nid = ni.nid');
      $q->condition('r.field_recipe_ingredients_nid', $component_nid);
      $recipes = $q->execute();
      foreach ($recipes as $recipe) {
        $message .= ' ,"' . $recipe->title . '" (id ' . $recipe->entity_id . ')';
        $title_component = $recipe->ni_title;
      }
      if (!empty($message)) {
        $message = 'Component "' . $title_component . '" (id ' . $component_nid . ') was not removed during the upgrade, as it is used in recipes' . $message . '.';
        watchdog('xoxo_import', $message, $variables = array(), $severity = WATCHDOG_NOTICE);
      }
      return 0;
    }
    node_delete($component_nid);
    return 1;
  }
  return 0;
  
// Second Version
  /*
  SELECT c.entity_id, nc.title, r.entity_id, nr.title 
  FROM field_data_field_component_id c 
  LEFT OUTER JOIN node nc ON c.entity_id = nc.nid
  LEFT OUTER JOIN field_data_field_recipe_ingredients r ON c.entity_id = r.field_recipe_ingredients_nid
  LEFT OUTER JOIN node nr ON r.entity_id = nr.nid
  WHERE c.field_component_id_value = 2000001133;
  */
  
//  $query = db_select('field_data_field_component_id', 'c');
//  $query->addField('c', 'entity_id', 'component_nid');
//  $query->addField('nc', 'title', 'component_title');
//  $query->addField('r', 'entity_id', 'recipe_nid');
//  $query->addField('nr', 'title', 'recipe_title');
//  $query->leftJoin('node', 'nc', 'c.entity_id = nc.nid');
//  $query->leftJoin('field_data_field_recipe_ingredients', 'r', 'c.entity_id = r.field_recipe_ingredients_nid');
//  $query->leftJoin('node', 'nr', 'r.entity_id = nr.nid');
//  $query->condition('c.field_component_id_value', $cid);
//  $result = $query->execute();
//  $record = $result->fetchAssoc();
//  $component_nid = $record['component_nid'];
//  if ($component_nid) {
//    $recipe_nid = $record['recipe_nid'];
//    if ($recipe_nid) {
//      $component_title = $record['component_title'];
//      $message = '"' . $record['recipe_title'] . '" (id ' . $recipe_nid . '), ';
//      foreach ($result as $recipe) {
//        $message .= '"' . $recipe->recipe_title . '" (id ' . $recipe->recipe_nid . '), ';
//      }
//      $message = 'Component "' . $component_title . '" (id ' . $component_nid . ') which is used in recipes ' . $message . 'was not removed during the upgrade.';
//      watchdog('xoxo_import', $message, $variables = array(), $severity = WATCHDOG_NOTICE);
//      return 0;
//    }
//    node_delete($component_nid);
//    return 1;
//  }
//  return 0;
}

/*
 * Set component title (node title)
 */
function _xoxo_import_kwikee_set_title($nid, $component, $title, $op) {
  _xoxo_import_kwikee_prepare_add_token_values($component);
  $fields = _xoxo_import_kwikee_additional_tokens() + _xoxo_import_kwikee_fields();
  foreach($fields as $field) {
    if(isset($component[$field]) && strpos($title, '%'.$field.'%') !== FALSE) {
      $title = str_replace('%'.$field.'%', $component[$field], $title);
    }
    elseif(strpos($title, '%'.$field.'%') !== FALSE) {
      $title = str_replace('%'.$field.'%', '', $title);
    }
  }
  $title = trim($title);
  return _xoxo_import_kwikee_init_component($nid, $title);
}

/*
 * Set category
 */
function _xoxo_import_kwikee_set_category($nid, $component, $category_4, $op) {
  $category_1 = variable_get('xik_category_level_1', FALSE);
  $category_2 = variable_get('xik_category_level_2', FALSE);
  $category_3 = variable_get('xik_category_level_3', FALSE);

  $category_1 = (isset($component[$category_1])) ? $component[$category_1] : KWIKEE_CATEGORY_OTHER;
  $category_2 = (isset($component[$category_2])) ? $component[$category_2] : KWIKEE_CATEGORY_OTHER;
  $category_3 = (isset($component[$category_3])) ? $component[$category_3] : KWIKEE_CATEGORY_OTHER;

  $category_4 = (is_null($category_4)) ? KWIKEE_CATEGORY_OTHER : $category_4;

  $term1 = _xoxo_import_kwikee_get_term_info($category_1, 1);

  if(isset($term1['tid'])) {
    $tid1 = $term1['tid'];
  }
  else {
    $tid1 = _xoxo_import_create_term($category_1, XOXO_IMPORT_CAT_VID);
  }

  $term2 = _xoxo_import_kwikee_get_term_info($category_2, 2);
  if(isset($term2['tid'])) {
    $tid2 = $term2['tid'];
  }
  else {
    $tid2 = _xoxo_import_create_term($category_2, 16);
  }

  $term3 = _xoxo_import_kwikee_get_term_info($category_3, 3);
  if(isset($term3['tid'])) {
    $tid3 = $term3['tid'];
  }
  else {
    $tid3 = _xoxo_import_create_term($category_3, 17, 0, 999);
  }

  $term4 = _xoxo_import_kwikee_get_term_info($category_4, 4);
  if(isset($term4['tid'])) {
    $tid4 = $term4['tid'];
  }
  else {
    $tid4 = _xoxo_import_create_term($category_4, 18);
  }

  if($op == KWIKEE_UPDATE_ACTION) {
    $s1 = _xoxo_import_kwikee_update_simple_record(
      'field_data_field_component_category',
      array(
        'field_component_category_tid' => $tid1,
      ),
      array('entity_id' => $nid)
    );
    $s2 = _xoxo_import_kwikee_update_simple_record(
      'field_data_field_component_category_2',
      array(
        'field_component_category_2_tid' => $tid2,
      ),
      array('entity_id' => $nid)
    );
    $s3 = _xoxo_import_kwikee_update_simple_record(
      'field_data_field_component_category_3',
      array(
        'field_component_category_3_tid' => $tid3,
      ),
      array('entity_id' => $nid)
    );
    $s4 = _xoxo_import_kwikee_update_simple_record(
      'field_data_field_component_category_4',
      array(
        'field_component_category_4_tid' => $tid4,
      ),
      array('entity_id' => $nid)
    );
    
    if($s1 && $s2 && $s3 && $s4) {
      return TRUE;
    }
  }
  else {
    _xoxo_import_insert_value(
      'field_data_field_component_category',
      'field_component_category_tid',
      $tid1,
      $nid
    );
    _xoxo_import_insert_value(
      'field_data_field_component_category_2',
      'field_component_category_2_tid',
      $tid2,
      $nid
    );
    _xoxo_import_insert_value(
      'field_data_field_component_category_3',
      'field_component_category_3_tid',
      $tid3,
      $nid
    );
    _xoxo_import_insert_value(
      'field_data_field_component_category_4',
      'field_component_category_4_tid',
      $tid4,
      $nid
    );
  }
  /*_xoxo_import_kwikee_insert_simple_record(
    'taxonomy_index',
    array(
      'nid' => $nid,
      'tid' => $tid,
      'created' => time(),
    )
  );*/
  return TRUE;
}

function _xoxo_import_kwikee_get_term_info($name, $level = 0) {
/*  $q = "
    SELECT
      t.tid AS tid,
      h.parent AS parent
    FROM
      taxonomy_term_data t
    LEFT JOIN
      taxonomy_term_hierarchy h ON h.tid = t.tid
    WHERE
        t.name LIKE :value
      AND
        h.parent = :parent
    LIMIT 1";*/
  $levels = array(//Level-vocabulary map.
    1 => 2,
    2 => 16,
    3 => 17,
    4 => 18
    );
  $q = "
    SELECT
      t.tid AS tid
    FROM
      taxonomy_term_data t
    WHERE
        t.name LIKE :value AND t.vid = :level
    LIMIT 1";
  $result = db_query($q, array(':value' => $name, ':level' => $levels[$level]/*':parent' => $level,*/))->fetchAssoc();
  return $result;
}

/*
 * Set section
 */
function _xoxo_import_kwikee_set_section_id($nid, $component, $category_id, $op) {
  $category_name_mapper = variable_get('xik_category', NULL);

  if(!$category_name_mapper || !isset($component[$category_name_mapper])) {
    return FALSE;
  }

  $cid = _xoxo_import_kwikee_check_existens(KWIKEE_CATEGORY_TABLE, 'cid', $category_id, 'cid');

  if(empty($cid)) {
  //  $tid = _xoxo_import_create_term($component[$category_name_mapper], XOXO_IMPORT_CAT_VID);
    _xoxo_import_kwikee_insert_simple_record(
      KWIKEE_CATEGORY_TABLE,
      array(
        'cid' => $category_id,
        'value' => $component[$category_name_mapper],
      )
    );
  }

  if($op == KWIKEE_UPDATE_ACTION) {
 /*   _xoxo_import_kwikee_update_simple_record(
      'taxonomy_term_data',
      array(
        'name' => $component[$category_name_mapper],
      ),
      array('tid' => $tid)
    );
*/
    if(_xoxo_import_kwikee_update_simple_record(
          'field_data_field_component_section_id',
          array(
            'field_component_section_id_value' => $category_id,
          ),
          array('entity_id' => $nid)
        )
      ) {
        return TRUE;
    }
  }
  _xoxo_import_insert_value(
    'field_data_field_component_section_id',
    'field_component_section_id_value',
    $category_id,
    $nid
  );
  /*_xoxo_import_kwikee_insert_simple_record(
    'taxonomy_index',
    array(
      'nid' => $nid,
      'tid' => $tid,
      'created' => time(),
    )
  );*/
  return TRUE;
}

/*
 * Set component id
 */
function _xoxo_import_kwikee_set_component_id($nid, $component, $id, $op) {
  if($op == KWIKEE_UPDATE_ACTION) {
 /*   $id = strtolower($id);
    if(substr($id, 0, 4) == 'usda') {
      $temp_id = str_replace('usda', '', $id);
      $id = (int)$temp_id + 2000000000;
    }*/
    if(_xoxo_import_kwikee_update_simple_record(
        'field_data_field_component_id',
        array(
          'field_component_id_value' => (int)$id,
        ),
        array('entity_id' => $nid)
      )
    ) {
      return TRUE;
    }
  }
  _xoxo_import_insert_value(
    'field_data_field_component_id',
    'field_component_id_value',
    (int)$id,
    $nid
  );

  return TRUE;
}

/*
 * Set UPC
 */
function _xoxo_import_kwikee_set_upc($nid, $component, $upc, $op) {
  if($op == KWIKEE_UPDATE_ACTION) {
    if(_xoxo_import_kwikee_update_simple_record(
        'field_data_field_component_upc_a',
        array(
          'field_component_upc_a_value' => $upc,
        ),
        array('entity_id' => $nid)
      )
    ) {
      return TRUE;
    }
  }
  _xoxo_import_insert_value(
    'field_data_field_component_upc_a',
    'field_component_upc_a_value',
    $upc,
    $nid
  );

  return TRUE;
}

/*
 * Set Manufacturer id
 */
function _xoxo_import_kwikee_set_manufacturer($nid, $component, $m, $op) {
  if($op == KWIKEE_UPDATE_ACTION) {
    if(_xoxo_import_kwikee_update_simple_record(
        'field_data_field_component_manufacturer',
        array(
          'field_component_manufacturer_value' => (int)$m,
        ),
        array('entity_id' => $nid)
      )
    ) {
      return TRUE;
    }
  }
  _xoxo_import_insert_value(
    'field_data_field_component_manufacturer',
    'field_component_manufacturer_value',
    (int)$m,
    $nid
  );

  return TRUE;
}

/*
 * Set Brand id
 */
function _xoxo_import_kwikee_set_brand($nid, $component, $b, $op) {
  if($op == KWIKEE_UPDATE_ACTION) {
    if(_xoxo_import_kwikee_update_simple_record(
        'field_data_field_component_brand',
        array(
          'field_component_brand_value' => (int)$b,
        ),
        array('entity_id' => $nid)
      )
    ) {
      return TRUE;
    }
  }
  _xoxo_import_insert_value(
    'field_data_field_component_brand',
    'field_component_brand_value',
    (int)$b,
    $nid
  );

  return TRUE;
}

/*
 * Set name
 */
function _xoxo_import_kwikee_set_name($nid, $component, $name, $op) {
  if($name > 255) {
    $name = substr($name, 0, 255);
    watchdog('xoxo_import', 'Not enough chars for component name for node %nid', array('%nid' => $nid), WATCHDOG_WARNING);
  }

  // check if name already exists in {xoxo_names} table
  $q = "
    SELECT
      xoxo_n.aid AS aid
    FROM
      {xoxo_names} xoxo_n
    WHERE
        xoxo_n.value LIKE :value";
  $aid = db_query(
    $q,
    array(
      ':value' => $name
    )
  )->fetchField();

  if(!$aid) {
    // write record in {xoxo_brands} table
    $q = "
      INSERT INTO
        {xoxo_names} (value)
      VALUES (:value);";
    db_query(
      $q,
      array(
        ':value' => $name,
      )
    );

    // get latest aid
    $q = "
      SELECT
        xoxo_n.aid AS aid
      FROM
        {xoxo_names} xoxo_n
      ORDER BY
        aid
      DESC
      LIMIT 1;";
    $aid = db_query($q)->fetchField();
  }

  if($op == KWIKEE_UPDATE_ACTION) {
    if(_xoxo_import_kwikee_update_simple_record(
        'field_data_field_component_name',
        array(
          'field_component_name_value' => $aid,
        ),
        array('entity_id' => $nid)
      )
    ) {
      return TRUE;
    }
  }
  _xoxo_import_insert_value(
    'field_data_field_component_name',
    'field_component_name_value',
    $aid,
    $nid
  );

  return TRUE;
}

/*
 * Set description
 */
function _xoxo_import_kwikee_set_description($nid, $component, $description, $op) {
  if($op == KWIKEE_UPDATE_ACTION) {
    if(_xoxo_import_kwikee_update_simple_record(
        'field_data_field_component_description',
        array(
          'field_component_description_value' => $description,
        ),
        array('entity_id' => $nid)
      )
    ) {
      return TRUE;
    }
  }
  _xoxo_import_insert_value(
    'field_data_field_component_description',
    'field_component_description_value',
    $description,
    $nid
  );

  return TRUE;
}

/*
 * Set size
 */
function _xoxo_import_kwikee_set_size($nid, $component, $size, $op) {
  _xoxo_import_prepare_float_value($size, $nid);
  if($op == KWIKEE_UPDATE_ACTION) {
    if(_xoxo_import_kwikee_update_simple_record(
        'field_data_field_component_size',
        array(
          'field_component_size_value' => $size,
        ),
        array('entity_id' => $nid)
      )
    ) {
      return TRUE;
    }
  }
  _xoxo_import_insert_value(
    'field_data_field_component_size',
    'field_component_size_value',
    $size,
    $nid
  );

  return TRUE;
}

/*
 * Set UOM
 */
function _xoxo_import_kwikee_set_uom($nid, $component, $uom, $op) {
  $tid = _xoxo_import_get_term_id(XOXO_IMPORT_UOM_VID, $uom);
  if($op == KWIKEE_UPDATE_ACTION) {
    if(_xoxo_import_kwikee_update_simple_record(
        'field_data_field_component_uom',
        array(
          'field_component_uom_tid' => $tid,
        ),
        array('entity_id' => $nid)
      )
    ) {
      return TRUE;
    }
  }
  _xoxo_import_insert_value(
    'field_data_field_component_uom',
    'field_component_uom_tid',
    $tid,
    $nid
  );
  /*
  _xoxo_import_kwikee_insert_simple_record(
    'taxonomy_index',
    array(
      'nid' => $nid,
      'tid' => $tid,
      'created' => time(),
    )
  );*/
  return TRUE;
}

/*
 * Set size i
 */
function _xoxo_import_kwikee_set_i_size($nid, $component, $size, $op) {
  _xoxo_import_prepare_float_value($size, $nid);
  if($op == KWIKEE_UPDATE_ACTION) {
    if(_xoxo_import_kwikee_update_simple_record(
        'field_data_field_component_l_size',
        array(
          'field_component_l_size_value' => $size,
        ),
        array('entity_id' => $nid)
      )
    ) {
      return TRUE;
    }
  }
  _xoxo_import_insert_value(
    'field_data_field_component_l_size',
    'field_component_l_size_value',
    $size,
    $nid
  );

  return TRUE;
}

/*
 * Set UOM i
 */
function _xoxo_import_kwikee_set_i_uom($nid, $component, $uom, $op) {
  $tid = _xoxo_import_get_term_id(XOXO_IMPORT_UOM_VID, $uom);
  if($op == KWIKEE_UPDATE_ACTION) {
    if(_xoxo_import_kwikee_update_simple_record(
        'field_data_field_component_l_uom',
        array(
          'field_component_l_uom_tid' => $tid,
        ),
        array('entity_id' => $nid)
      )
    ) {
      return TRUE;
    }
  }
  _xoxo_import_insert_value(
    'field_data_field_component_l_uom',
    'field_component_l_uom_tid',
    $tid,
    $nid
  );

  return TRUE;
}


/*
 * Set serving size
 */
function _xoxo_import_kwikee_set_serving_size($nid, $component, $size, $op) {
  _xoxo_import_prepare_float_value($size, $nid);
  if($op == KWIKEE_UPDATE_ACTION) {
    if(_xoxo_import_kwikee_update_simple_record(
        'field_data_field_component_serving_size',
        array(
          'field_component_serving_size_value' => $size,
        ),
        array('entity_id' => $nid)
      )
    ) {
      return TRUE;
    }
  }
  _xoxo_import_insert_value(
    'field_data_field_component_serving_size',
    'field_component_serving_size_value',
    $size,
    $nid
  );

  return TRUE;
}

/*
 * Set serving UOM
 */
function _xoxo_import_kwikee_set_serving_uom($nid, $component, $uom, $op) {
  $tid = _xoxo_import_get_term_id(XOXO_IMPORT_UOM_VID, $uom);
  if($op == KWIKEE_UPDATE_ACTION) {
    if(_xoxo_import_kwikee_update_simple_record(
        'field_data_field_component_serving_size_uom',
        array(
          'field_component_serving_size_uom_tid' => $tid,
        ),
        array('entity_id' => $nid)
      )
    ) {
      return TRUE;
    }
  }
  _xoxo_import_insert_value(
    'field_data_field_component_serving_size_uom',
    'field_component_serving_size_uom_tid',
    $tid,
    $nid
  );

  return TRUE;
}

/*
 * Set serving i size
 */
function _xoxo_import_kwikee_set_serving_i_size($nid, $component, $size, $op) {
  _xoxo_import_prepare_float_value($size, $nid);
  if($op == KWIKEE_UPDATE_ACTION) {
    if(_xoxo_import_kwikee_update_simple_record(
        'field_data_field_component_l_serving_size',
        array(
          'field_component_l_serving_size_value' => $size,
        ),
        array('entity_id' => $nid)
      )
    ) {
      return TRUE;
    }
  }
  _xoxo_import_insert_value(
    'field_data_field_component_l_serving_size',
    'field_component_l_serving_size_value',
    $size,
    $nid
  );

  return TRUE;
}

/*
 * Set serving i UOM
 */
function _xoxo_import_kwikee_set_serving_i_uom($nid, $component, $uom, $op) {
  $tid = _xoxo_import_get_term_id(XOXO_IMPORT_UOM_VID, $uom);
  if($op == KWIKEE_UPDATE_ACTION) {
    if(_xoxo_import_kwikee_update_simple_record(
        'field_data_field_component_l_serving_size_u',
        array(
          'field_component_l_serving_size_u_tid' => $tid,
        ),
        array('entity_id' => $nid)
      )
    ) {
      return TRUE;
    }
  }

  _xoxo_import_insert_value(
    'field_data_field_component_l_serving_size_u',
    'field_component_l_serving_size_u_tid',
    $tid,
    $nid
  );

  return TRUE;
}


/*
 * Set package
 */
function _xoxo_import_kwikee_set_package($nid, $component, $package, $op) {
  if($op == KWIKEE_UPDATE_ACTION) {
    if(_xoxo_import_kwikee_update_simple_record(
        'field_data_field_component_package',
        array(
          'field_component_package_value' => serialize($package),
        ),
        array('entity_id' => $nid)
      )
    ) {
      return TRUE;
    }
  }

  _xoxo_import_insert_value(
    'field_data_field_component_package',
    'field_component_package_value',
    serialize($package),
    $nid
  );

  return TRUE;
}

/*
 * Set nutritional data
 */
function _xoxo_import_kwikee_set_nutritional($nid, $component, $nutritional, $op) {
  if($op == KWIKEE_UPDATE_ACTION) {
    if(_xoxo_import_kwikee_update_simple_record(
        'field_data_field_component_nutritional',
        array(
          'field_component_nutritional_value' => serialize($nutritional),
        ),
        array('entity_id' => $nid)
      )
    ) {
      return TRUE;
    }
  }

  _xoxo_import_insert_value(
    'field_data_field_component_nutritional',
    'field_component_nutritional_value',
    serialize($nutritional),
    $nid
  );

  return TRUE;
}

/*
 * Set other data
 */
function _xoxo_import_kwikee_set_other($nid, $component, $other, $op) {
  if($op == KWIKEE_UPDATE_ACTION) {
    if(_xoxo_import_kwikee_update_simple_record(
        'field_data_field_component_other',
        array(
          'field_component_other_value' => serialize($other),
        ),
        array('entity_id' => $nid)
      )
    ) {
      return TRUE;
    }
  }

  _xoxo_import_insert_value(
    'field_data_field_component_other',
    'field_component_other_value',
    serialize($other),
    $nid
  );

  return TRUE;
}

/*
 * Initial creation of component node
 */
function _xoxo_import_kwikee_init_component($nid, $title) {
  $timestamp = time();

  if(!empty($nid)) {
    $values = array(
      'title' => $title,
      'created' => $timestamp,
      'changed' => $timestamp,
    );
    $conditions = array(
      'nid' => $nid,
    );
    _xoxo_import_kwikee_update_simple_record('node', $values, $conditions);

    $values = array(
      'title' => $title,
      'timestamp' => $timestamp,
    );
    _xoxo_import_kwikee_update_simple_record('node_revision', $values, $conditions);
    return $nid;
  }

  // write record in {node} table
  $q = "
    INSERT INTO
      {node}
      (
        type,
        language,
        title,
        uid,
        created,
        changed
       )
    VALUES
      (
        '".XOXO_IMPORT_CTYPE."',
        'und',
        :title,
        1,
        :created,
        :changed
      );";
  db_query(
    $q,
    array(
      ':title' => $title,
      ':created' => $timestamp,
      ':changed' => $timestamp,
    )
  );

  // get nid
  $q = "
    SELECT
      n.nid AS nid
    FROM
      {node} n
    ORDER BY
      nid
    DESC
    LIMIT 1;";
  $nid = db_query($q)->fetchField();

  // write record in {node_revision} table
  $q = "
    INSERT INTO
      {node_revision}
      (
        nid,
        uid,
        title,
        log,
        timestamp
      )
    VALUES
      (
        :nid,
        1,
        :title,
        '',
        :timestamp
      );";
  db_query(
    $q,
    array(
      ':nid' => $nid,
      ':title' => $title,
      ':timestamp' => $timestamp,
    )
  );

  // update vid value in {node} table
  $q = "
    UPDATE
      {node}
    SET
      vid = (
        SELECT
          nv.vid AS vid
        FROM
          {node_revision} nv
        ORDER BY
          vid
        DESC
        LIMIT 1)
    WHERE
      nid = :nid;";
  db_query(
    $q,
    array(
      ':nid' => $nid,
    )
  );

  return $nid;
}

/*
 * Update Brands
 */
function _xoxo_import_kwikee_update_brands($b) {
  $status = array();
  foreach($b as $i => $brand) {
    if(!isset($brand['brand_id'])) {
      continue;
    }

    switch($brand['action']) {
      case KWIKEE_INSERT_ACTION: {
        if(!isset($brand['name'], $brand['mfr_id'])) {
          continue;
        }
        $bid = _xoxo_import_kwikee_check_existens(KWIKEE_BRANDS_TABLE, 'bid', (int)$brand['brand_id'], 'bid');
        if(!$bid) {
          $values = array(
            'bid' => (int)$brand['brand_id'],
            'mid' => (int)$brand['mfr_id'],
            'value' => (string)$brand['name'],
          );
          _xoxo_import_kwikee_insert_simple_record(KWIKEE_BRANDS_TABLE, $values);
          $status[KWIKEE_INSERT_ACTION] = (!empty($status[KWIKEE_INSERT_ACTION])) ? $status[KWIKEE_INSERT_ACTION]+1 : 1;
        }
        else {
          $values = array(
            'mid' => (int)$brand['mfr_id'],
            'value' => (string)$brand['name'],
          );
          $conditions = array(
            'bid' => (int)$brand['mfr_id'],
          );
          _xoxo_import_kwikee_update_simple_record(KWIKEE_BRANDS_TABLE, $values, $conditions);
          $status[KWIKEE_UPDATE_ACTION] = (!empty($status[KWIKEE_UPDATE_ACTION])) ? $status[KWIKEE_UPDATE_ACTION]+1 : 1;
        }
      } break;
      case KWIKEE_UPDATE_ACTION: {
        if(!isset($brand['name'], $brand['mfr_id'])) {
          continue;
        }
        $bid = _xoxo_import_kwikee_check_existens(KWIKEE_BRANDS_TABLE, 'bid', (int)$brand['brand_id'], 'bid');
        if(!$bid) {
          $values = array(
            'bid' => (int)$brand['brand_id'],
            'mid' => (int)$brand['mfr_id'],
            'value' => (string)$brand['name'],
          );
          _xoxo_import_kwikee_insert_simple_record(KWIKEE_BRANDS_TABLE, $values);
          $status[KWIKEE_INSERT_ACTION] = (!empty($status[KWIKEE_INSERT_ACTION])) ? $status[KWIKEE_INSERT_ACTION]+1 : 1;
        }
        else {
          $values = array(
            'mid' => (int)$brand['mfr_id'],
            'value' => (string)$brand['name'],
          );
          $conditions = array(
            'bid' => (int)$brand['mfr_id'],
          );
          _xoxo_import_kwikee_update_simple_record(KWIKEE_BRANDS_TABLE, $values, $conditions);
          $status[KWIKEE_UPDATE_ACTION] = (!empty($status[KWIKEE_UPDATE_ACTION])) ? $status[KWIKEE_UPDATE_ACTION]+1 : 1;
        }

      } break;
      case KWIKEE_DELETE_ACTION: {
        $delete_status = _xoxo_import_kwikee_delete_item(KWIKEE_BRANDS_TABLE, 'bid', (int)$brand['brand_id']);
        $status[KWIKEE_DELETE_ACTION] = (!empty($status[KWIKEE_DELETE_ACTION])) ? $status[KWIKEE_DELETE_ACTION]+$delete_status : $delete_status;
      } break;
    }
  }

  return $status;
}

/*
 * Update Manufacturers
 */
function _xoxo_import_kwikee_update_maunfacturers($m) {
  $status = array();
  foreach($m as $i => $manufacturer) {
    if(!isset($manufacturer['mfr_id'])) {
      continue;
    }

    switch($manufacturer['action']) {
      case KWIKEE_INSERT_ACTION: {
        /*$values = array(
          'mid' => (int)$manufacturer['mfr_id'],
          'value' => (string)$manufacturer['name'],
        );
        _xoxo_import_kwikee_insert_simple_record(KWIKEE_MANUFACTURERS_TABLE, $values);
        $status[KWIKEE_INSERT_ACTION] = (!empty($status[KWIKEE_INSERT_ACTION])) ? $status[KWIKEE_INSERT_ACTION]+1 : 1;*/
        if(!isset($manufacturer['name'])) {
          continue;
        }
        $mid = _xoxo_import_kwikee_check_existens(KWIKEE_MANUFACTURERS_TABLE, 'mid', (int)$manufacturer['mfr_id'], 'mid');
        if(!$mid) {
          $values = array(
            'mid' => (int)$manufacturer['mfr_id'],
            'value' => (string)$manufacturer['name'],
          );
          _xoxo_import_kwikee_insert_simple_record(KWIKEE_MANUFACTURERS_TABLE, $values);
          $status[KWIKEE_INSERT_ACTION] = (!empty($status[KWIKEE_INSERT_ACTION])) ? $status[KWIKEE_INSERT_ACTION]+1 : 1;
        }
        else {
          $values = array(
            'value' => (string)$manufacturer['name'],
          );
          $conditions = array(
            'mid' => (int)$manufacturer['mfr_id'],
          );
          _xoxo_import_kwikee_update_simple_record(KWIKEE_MANUFACTURERS_TABLE, $values, $conditions);
          $status[KWIKEE_UPDATE_ACTION] = (!empty($status[KWIKEE_UPDATE_ACTION])) ? $status[KWIKEE_UPDATE_ACTION]+1 : 1;
        }
      } break;
      case KWIKEE_UPDATE_ACTION: {
        if(!isset($manufacturer['name'])) {
          continue;
        }
        $mid = _xoxo_import_kwikee_check_existens(KWIKEE_MANUFACTURERS_TABLE, 'mid', (int)$manufacturer['mfr_id'], 'mid');
        if(!$mid) {
          $values = array(
            'mid' => (int)$manufacturer['mfr_id'],
            'value' => (string)$manufacturer['name'],
          );
          _xoxo_import_kwikee_insert_simple_record(KWIKEE_MANUFACTURERS_TABLE, $values);
          $status[KWIKEE_INSERT_ACTION] = (!empty($status[KWIKEE_INSERT_ACTION])) ? $status[KWIKEE_INSERT_ACTION]+1 : 1;
        }
        else {
          $values = array(
            'value' => (string)$manufacturer['name'],
          );
          $conditions = array(
            'mid' => (int)$manufacturer['mfr_id'],
          );
          _xoxo_import_kwikee_update_simple_record(KWIKEE_MANUFACTURERS_TABLE, $values, $conditions);
          $status[KWIKEE_UPDATE_ACTION] = (!empty($status[KWIKEE_UPDATE_ACTION])) ? $status[KWIKEE_UPDATE_ACTION]+1 : 1;
        }
      } break;
      case KWIKEE_DELETE_ACTION: {
        $delete_status = _xoxo_import_kwikee_delete_item(KWIKEE_MANUFACTURERS_TABLE, 'mid', (int)$manufacturer['mfr_id']);
        $status[KWIKEE_DELETE_ACTION] = (!empty($status[KWIKEE_DELETE_ACTION])) ? $status[KWIKEE_DELETE_ACTION]+$delete_status : $delete_status;
      } break;
    }
  }

  return $status;
}

/*
 * Delete item directly using SQL
 */
function _xoxo_import_kwikee_delete_item($table, $column, $value) {
  return 0;
  // we keep all m/b/c on the site no matter if they must be removed regardingo to kwinkee request
  /*
  $q = 'DELETE FROM '.$table.' WHERE '.$column.' = :value';
  return db_query($q, array(':value' => $value))->rowCount();*/
}
function _xoxo_import_kwikee_check_existens($table, $column, $value, $column_out) {
  $q = "
    SELECT
      tname.".$column_out." AS cname
    FROM
      ".$table." tname
    WHERE
        tname.".$column." LIKE :value
    LIMIT 1";
  $result = db_query(
    $q,
    array(
      ':value' => $value
    )
  )->fetchField();

  return $result;
}
function _xoxo_import_kwikee_insert_simple_record($table, $values, $latest = NULL) {
  db_insert($table)->fields($values)->execute();

  if(!is_null($latest)) {
    $q = "
      SELECT
        {$table}.{$latest} AS cname
      FROM
        {$table} tname
      ORDER BY
        cname
      DESC
      LIMIT 1;";
    return db_query($q)->fetchField();
  }
}

function _xoxo_import_kwikee_update_simple_record($table, $values, $conditions) {
  $result = db_select($table, 't')->fields('t');
  foreach($conditions as $field => $value) {
    $result = $result->condition($field, $value);
  }

  if(!$result->execute()->rowCount()) {
    return FALSE;
  }

  $r = db_update($table);
  foreach($conditions as $field => $value) {
    $r = $r->condition($field, $value);
  }
  $r->fields($values)->execute();

  return TRUE;
}

function _xoxo_import_kwikee_fields() {
  $kwikee_fields = array(
    0 => '',
    'action' => 'action',
    'product_id' => 'product_id',
    'product_attribute_1' => 'product_attribute_1',
    'product_attribute_2' => 'product_attribute_2',
    'product_attribute_3' => 'product_attribute_3',
    'segment_name' => 'segment_name',
    'family_name' => 'family_name',
    'class_name' => 'class_name',
    'brick_name' => 'brick_name',
    'mfr_id' => 'mfr_id',
    'brand_id' => 'brand_id',
    'local_content' => 'local_content',
    'advertising_flag' => 'advertising_flag',
    'calories_per_serving' => 'calories_per_serving',
    'calories_per_serving_2' => 'calories_per_serving_2',
    'capture_date' => 'capture_date',
    'carbo_per_serving' => 'carbo_per_serving',
    'carbo_per_serving_2' => 'carbo_per_serving_2',
    'carbo_uom' => 'carbo_uom',
    'carbo_uom_2' => 'carbo_uom_2',
    'case_count' => 'case_count',
    'case_depth' => 'case_depth',
    'case_height' => 'case_height',
    'case_width' => 'case_width',
    'cholesterol_per_serving' => 'cholesterol_per_serving',
    'cholesterol_per_serving_2' => 'cholesterol_per_serving_2',
    'cholesterol_uom' => 'cholesterol_uom',
    'cholesterol_uom_2' => 'cholesterol_uom_2',
    'container_desc' => 'container_desc',
    'costco_flag' => 'costco_flag',
    'depth' => 'depth',
    'depth_count' => 'depth_count',
    'depth_nesting' => 'depth_nesting',
    'description' => 'description',
    'display_depth' => 'display_depth',
    'display_height' => 'display_height',
    'display_width' => 'display_width',
    'division_name' => 'division_name',
    'dual_nesting' => 'dual_nesting',
    'dvp_calcium' => 'dvp_calcium',
    'dvp_calcium_2' => 'dvp_calcium_2',
    'dvp_carbo' => 'dvp_carbo',
    'dvp_carbo_2' => 'dvp_carbo_2',
    'dvp_cholesterol' => 'dvp_cholesterol',
    'dvp_cholesterol_2' => 'dvp_cholesterol_2',
    'dvp_copper' => 'dvp_copper',
    'dvp_copper_2' => 'dvp_copper_2',
    'dvp_dietary_fiber_2' => 'dvp_dietary_fiber_2',
    'dvp_fiber' => 'dvp_fiber',
    'dvp_folic_acid' => 'dvp_folic_acid',
    'dvp_folic_acid_2' => 'dvp_folic_acid_2',
    'dvp_iodine' => 'dvp_iodine',
    'dvp_iodine_2' => 'dvp_iodine_2',
    'dvp_iron' => 'dvp_iron',
    'dvp_iron_2' => 'dvp_iron_2',
    'dvp_magnesium' => 'dvp_magnesium',
    'dvp_magnesium_2' => 'dvp_magnesium_2',
    'dvp_niacin' => 'dvp_niacin',
    'dvp_niacin_2' => 'dvp_niacin_2',
    'dvp_phosphorus' => 'dvp_phosphorus',
    'dvp_phosphorus_2' => 'dvp_phosphorus_2',
    'dvp_potassium' => 'dvp_potassium',
    'dvp_potassium_2' => 'dvp_potassium_2',
    'dvp_protein' => 'dvp_protein',
    'dvp_protein_2' => 'dvp_protein_2',
    'dvp_riboflavin' => 'dvp_riboflavin',
    'dvp_riboflavin_2' => 'dvp_riboflavin_2',
    'dvp_saturated_fat' => 'dvp_saturated_fat',
    'dvp_saturated_fat_2' => 'dvp_saturated_fat_2',
    'dvp_sodium' => 'dvp_sodium',
    'dvp_sodium_2' => 'dvp_sodium_2',
    'dvp_sugar' => 'dvp_sugar',
    'dvp_sugars_2' => 'dvp_sugars_2',
    'dvp_thiamin' => 'dvp_thiamin',
    'dvp_thiamin_2' => 'dvp_thiamin_2',
    'dvp_total_fat' => 'dvp_total_fat',
    'dvp_total_fat_2' => 'dvp_total_fat_2',
    'dvp_vitamin_a' => 'dvp_vitamin_a',
    'dvp_vitamin_a_2' => 'dvp_vitamin_a_2',
    'dvp_vitamin_b12' => 'dvp_vitamin_b12',
    'dvp_vitamin_b12_2' => 'dvp_vitamin_b12_2',
    'dvp_vitamin_b6' => 'dvp_vitamin_b6',
    'dvp_vitamin_b6_2' => 'dvp_vitamin_b6_2',
    'dvp_vitamin_c' => 'dvp_vitamin_c',
    'dvp_vitamin_c_2' => 'dvp_vitamin_c_2',
    'dvp_vitamin_d' => 'dvp_vitamin_d',
    'dvp_vitamin_d_2' => 'dvp_vitamin_d_2',
    'dvp_vitamin_e' => 'dvp_vitamin_e',
    'dvp_vitamin_e_2' => 'dvp_vitamin_e_2',
    'dvp_zinc' => 'dvp_zinc',
    'dvp_zinc_2' => 'dvp_zinc_2',
    'ethnic_copy' => 'ethnic_copy',
    'extra_text_2' => 'extra_text_2',
    'extra_text_3' => 'extra_text_3',
    'extra_text_4' => 'extra_text_4',
    'fat_cal_per_serving_2' => 'fat_cal_per_serving_2',
    'fat_calories_per_serving' => 'fat_calories_per_serving',
    'fiber_per_serving' => 'fiber_per_serving',
    'fiber_per_serving_2' => 'fiber_per_serving_2',
    'fiber_uom' => 'fiber_uom',
    'fiber_uom_2' => 'fiber_uom_2',
    'gtin' => 'gtin',
    'height' => 'height',
    'height_count' => 'height_count',
    'identifier_1' => 'identifier_1',
    'identifier_2' => 'identifier_2',
    'image_indicator' => 'image_indicator',
    'indications_copy' => 'indications_copy',
    'ingredients' => 'ingredients',
    'instructions_copy_1' => 'instructions_copy_1',
    'instructions_copy_2' => 'instructions_copy_2',
    'instructions_copy_3' => 'instructions_copy_3',
    'instructions_copy_4' => 'instructions_copy_4',
    'instructions_copy_5' => 'instructions_copy_5',
    'interactions_copy' => 'interactions_copy',
    'knsl_flag' => 'knsl_flag',
    'kpl_flag' => 'kpl_flag',
    'midn_flag' => 'midn_flag',
    'model' => 'model',
    'multiple_shelf_facings' => 'multiple_shelf_facings',
    'name' => 'name',
    'no_data_flag' => 'no_data_flag',
    'nutrition_label' => 'nutrition_label',
    'nutrition_label_2' => 'nutrition_label_2',
    'peg_down' => 'peg_down',
    'peg_right' => 'peg_right',
    'physical_weight_lb' => 'physical_weight_lb',
    'physical_weight_oz' => 'physical_weight_oz',
    'potassium_per_serving' => 'potassium_per_serving',
    'potassium_uom' => 'potassium_uom',
    'potassium_uom_2' => 'potassium_uom_2',
    'potassuim_per_serving_2' => 'potassuim_per_serving_2',
    'product_size' => 'product_size',
    'protein_per_serving' => 'protein_per_serving',
    'protein_per_serving_2' => 'protein_per_serving_2',
    'protein_uom' => 'protein_uom',
    'protein_uom_2' => 'protein_uom_2',
    'romance_copy' => 'romance_copy',
    'romance_copy_2' => 'romance_copy_2',
    'romance_copy_3' => 'romance_copy_3',
    'sat_fat_per_serving' => 'sat_fat_per_serving',
    'sat_fat_per_serving_2' => 'sat_fat_per_serving_2',
    'sat_fat_uom' => 'sat_fat_uom',
    'sat_fat_uom_2' => 'sat_fat_uom_2',
    'seasonal_flag' => 'seasonal_flag',
    'section_id' => 'section_id',
    'section_name' => 'section_name',
    'serving_size' => 'serving_size',
    'serving_size_2' => 'serving_size_2',
    'serving_size_uom' => 'serving_size_uom',
    'serving_size_uom_2' => 'serving_size_uom_2',
    'servings_per_container' => 'servings_per_container',
    'servings_per_container_2' => 'servings_per_container_2',
    'shelfman_flag' => 'shelfman_flag',
    'shipment_id' => 'shipment_id',
    'sodium_per_serving' => 'sodium_per_serving',
    'sodium_per_serving_2' => 'sodium_per_serving_2',
    'sodium_uom' => 'sodium_uom',
    'sodium_uom_2' => 'sodium_uom_2',
    'sugar_per_serving' => 'sugar_per_serving',
    'sugar_uom' => 'sugar_uom',
    'sugars_per_serving_2' => 'sugars_per_serving_2',
    'sugars_uom_2' => 'sugars_uom_2',
    'total_cal_per_serving_2' => 'total_cal_per_serving_2',
    'total_calories_per_serving' => 'total_calories_per_serving',
    'total_fat_per_serving' => 'total_fat_per_serving',
    'total_fat_per_serving_2' => 'total_fat_per_serving_2',
    'total_fat_uom' => 'total_fat_uom',
    'total_fat_uom_2' => 'total_fat_uom_2',
    'trans_fat_per_serving' => 'trans_fat_per_serving',
    'trans_fat_per_serving_2' => 'trans_fat_per_serving_2',
    'trans_fat_uom' => 'trans_fat_uom',
    'trans_fat_uom_2' => 'trans_fat_uom_2',
    'tray_count' => 'tray_count',
    'tray_depth' => 'tray_depth',
    'tray_height' => 'tray_height',
    'tray_width' => 'tray_width',
    'uom' => 'uom',
    'upc' => 'upc',
    'vertical_nesting' => 'vertical_nesting',
    'warnings_copy' => 'warnings_copy',
    'whole_upc' => 'whole_upc',
    'why_buy_1' => 'why_buy_1',
    'why_buy_2' => 'why_buy_2',
    'why_buy_3' => 'why_buy_3',
    'why_buy_4' => 'why_buy_4',
    'why_buy_5' => 'why_buy_5',
    'why_buy_6' => 'why_buy_6',
    'why_buy_7' => 'why_buy_7',
    'width' => 'width',
    'width_count' => 'width_count',
  );
  return $kwikee_fields;
}

function _xoxo_import_kwikee_additional_tokens($list = TRUE) {
  $add_tokens = array(
    'brand_name' => array(
      'callback' => '_xoxo_import_kwikee_get_brand_name',
    ),
    'manufacturer_name' => array(
      'callback' => '_xoxo_import_kwikee_get_manufacturer_name',
    ),
  );

  if($list) {
    return array_keys($add_tokens);
  }

  return $add_tokens;
}
function _xoxo_import_kwikee_prepare_add_token_values(&$data) {
  foreach(_xoxo_import_kwikee_additional_tokens(FALSE) as $token => $config) {
    if(!empty($config['callback']) && function_exists($config['callback'])) {
      $data[$token] = call_user_func($config['callback'], $data);
    }
  }
}
function _xoxo_import_kwikee_get_brand_name($data) {
  if(isset($data['brand_id'])) {
    return _xoxo_import_kwikee_check_existens(KWIKEE_BRANDS_TABLE, 'bid', $data['brand_id'], 'value');
  }

  return '';
}
function _xoxo_import_kwikee_get_manufacturer_name($data) {
  if(isset($data['brand_id'])) {
    return _xoxo_import_kwikee_check_existens(KWIKEE_MANUFACTURERS_TABLE, 'mid', $data['mfr_id'], 'value');
  }

  return '';
}


/*
 * Batch
 */

function _xoxo_import_kwikee_batch($fid) {
  $function = '_xoxo_import_kwikee_batch_set';
  $batch = $function($fid);
  batch_set($batch);
  batch_process();
}

function _xoxo_import_kwikee_batch_set($fid) {
  $operations = array(
    array(
      '_xoxo_import_kwikee_import_file_process',
      array($fid),
    )
  );
  $batch = array(
    'operations' => $operations,
    'finished' => '_xoxo_import_kwikee_import_file_finished',
    'title' => t('Processing import'),
    'init_message' => t('Import is starting.'),
    'progress_message' => '',
    'error_message' => t('Import has encountered an error.'),
    'file' => drupal_get_path('module', 'xoxo_import') . '/xoxo_import.kwikee.inc',
  );
  return $batch;
}
//Process file. Start it if the $context is empty. Continue otherwise.
function _xoxo_import_kwikee_import_file_process($fid, &$context, $cron = FALSE, $packet = NULL) {
  $file = file_load($fid);
  $packet = (is_null($packet)) ? KWIKEE_BATCH_SIZE : $packet;
  //No file error.
  if(!$file) {
    watchdog('xoxo_import', 'Can\'t find file with fid = @fid', array('@fid' => $fid), WATCHDOG_ERROR);
    if(!$cron) {
      drupal_set_message(t('Can\'t find file with fid = @fid', array('@fid' => $fid)), 'error');
      drupal_goto('admin/config/development/xoxo-import-kwikee');
    }
    else {
      return FALSE;
    }
  }

  $file_path  = drupal_realpath($file->uri);
  // load file content
  $content = file_get_contents($file_path);
  //The file is empty error.
  if(!$content) {
    watchdog('xoxo_import', 'Empty file @path', array('@path' => $file_path), WATCHDOG_ERROR);
    if(!$cron) {
      drupal_set_message(t('Empty file @path', array('@path' => $file_path)), 'error');
      drupal_goto('admin/config/development/xoxo-import-kwikee');
    }
    else {
      return FALSE;
    }

  }
  //Start.
  if(empty($context['sandbox'])) {
    $context['sandbox'] = array();
    $context['sandbox']['progress'] = 0;
    $context['sandbox']['current_position'] = 0;
    $context['sandbox']['elapsed'] = 0;
    $context['sandbox']['run'] = 0;
    $context['sandbox']['crons'] = 0;
    
    $m_size = _xoxo_import_kwikee_parse_xml(
      $content,
      NULL,
      array(
        'element' => array(
          0 => 'manufacturers',
          1 => 'manufacturer_data',
        ),
        'level' => 1,
        'return_size' => TRUE,
      )
    );
    $b_size = _xoxo_import_kwikee_parse_xml(
      $content,
      NULL,
      array(
        'element' => array(
          0 => 'brands',
          1 => 'brand_data',
        ),
        'level' => 1,
        'return_size' => TRUE,
      )
    );
    $p_size = _xoxo_import_kwikee_parse_xml(
      $content,
      NULL,
      array(
        'element' => array(
          0 => 'products',
          1 => 'product_data',
        ),
        'level' => 1,
        'return_size' => TRUE,
      )
    );

    $context['sandbox']['m_size'] = $m_size;
    $context['sandbox']['b_size'] = $b_size;
    $context['sandbox']['p_size'] = $p_size;
    $context['sandbox']['m_'.KWIKEE_INSERT_ACTION] = 0;
    $context['sandbox']['m_'.KWIKEE_UPDATE_ACTION] = 0;
    $context['sandbox']['m_'.KWIKEE_DELETE_ACTION] = 0;
    $context['sandbox']['b_'.KWIKEE_INSERT_ACTION] = 0;
    $context['sandbox']['b_'.KWIKEE_UPDATE_ACTION] = 0;
    $context['sandbox']['b_'.KWIKEE_DELETE_ACTION] = 0;
    $context['sandbox']['p_'.KWIKEE_INSERT_ACTION] = 0;
    $context['sandbox']['p_'.KWIKEE_UPDATE_ACTION] = 0;
    $context['sandbox']['p_'.KWIKEE_DELETE_ACTION] = 0;
    $context['sandbox']['current_item'] = 0;
    $context['sandbox']['current_entity'] = KWIKEE_ENTITY_M;
    $context['sandbox']['max'] = $p_size + $b_size + $m_size;
    $context['sandbox']['starttime'] = time();
    
    if(!$context['sandbox']['max']) {
      $context['finished'] = 1;
      return;
    }
  }
  //Continue.
  else {
    switch($context['sandbox']['current_entity']) {
      //Manufacturers.
      case KWIKEE_ENTITY_M: {
        $result = _xoxo_import_kwikee_parse_xml(
          $content,
          NULL,
          array(
            'element' => array(
              0 => 'manufacturers',
              1 => 'manufacturer_data',
            ),
            'level' => 1,
            'min' => $context['sandbox']['current_item'],
            'max' => $context['sandbox']['current_item'] + $packet - 1,
          )
        );
        // import manufacturers
        if(isset($result['manufacturers']['manufacturer_data'])) {
          $status = _xoxo_import_kwikee_update_maunfacturers($result['manufacturers']['manufacturer_data']);
          foreach($status as $op => $size) {
            $context['sandbox']['m_'.$op] = $context['sandbox']['m_'.$op] + $size;
          }
        }
        $processed = count($result['manufacturers']['manufacturer_data']);
        $context['sandbox']['progress'] = $context['sandbox']['progress'] + $processed;
        $context['sandbox']['current_item'] = $context['sandbox']['current_item'] + $processed;
        if($processed < $packet) {
          $context['sandbox']['current_item'] = 0;
          $context['sandbox']['current_entity'] = KWIKEE_ENTITY_B;
        }
      } break;
        //Brands.
      case KWIKEE_ENTITY_B: {
        $result = _xoxo_import_kwikee_parse_xml(
          $content,
          NULL,
          array(
            'element' => array(
              0 => 'brands',
              1 => 'brand_data',
            ),
            'level' => 1,
            'min' => $context['sandbox']['current_item'],
            'max' => $context['sandbox']['current_item'] + $packet - 1,
          )
        );
        // import brands
        if(isset($result['brands']['brand_data'])) {
          $status = _xoxo_import_kwikee_update_brands($result['brands']['brand_data']);
          foreach($status as $op => $size) {
            $context['sandbox']['b_'.$op] = $context['sandbox']['b_'.$op] + $size;
          }
        }
        $processed = count($result['brands']['brand_data']);
        $context['sandbox']['progress'] = $context['sandbox']['progress'] + $processed;
        $context['sandbox']['current_item'] = $context['sandbox']['current_item'] + $processed;
        if($processed < $packet) {
          $context['sandbox']['current_item'] = 0;
          $context['sandbox']['current_entity'] = KWIKEE_ENTITY_P;
        }
      } break;
        //Components.
      case KWIKEE_ENTITY_P: {
        $result = _xoxo_import_kwikee_parse_xml(
          $content,
          NULL,
          array(
            'element' => array(
              0 => 'products',
              1 => 'product_data',
            ),
            'level' => 1,
            'min' => $context['sandbox']['current_item'],
            'max' => $context['sandbox']['current_item'] + $packet - 1,
          )
        );
        // import components
        if(isset($result['products']['product_data'])) {
          $status = _xoxo_import_kwikee_update_products($result['products']['product_data']);
          foreach($status as $op => $size) {
            $context['sandbox']['p_'.$op] = $context['sandbox']['p_'.$op] + $size;
          }
        }
        $processed = count($result['products']['product_data']);
        $context['sandbox']['progress'] = $context['sandbox']['progress'] + $processed;
        $context['sandbox']['current_item'] = $context['sandbox']['current_item'] + $processed;
        if($processed < $packet) {
          /*
          $context['sandbox']['current_item'] = 0;
          $context['sandbox']['current_entity'] = FALSE;*/
        }
      } break;
        //Image.
      case KWIKEE_ENTITY_I: {

      } break;
    }

    $time_track = time()-$context['sandbox']['starttime'];
    $context['sandbox']['endtime'] = time();
    $time_per_item_avg = ($context['sandbox']['progress']) ? $time_track/$context['sandbox']['progress'] : 10;// default speed is set to 10 items per sec - prevent devision by zero
    $time_left = round(($context['sandbox']['max']-$context['sandbox']['progress']) * $time_per_item_avg);

    $stat = array(
      '@processed' => $context['sandbox']['progress'],
      '@all' => $context['sandbox']['max'],
      '@elapsed' => (!$cron) ? gmdate('z:H:i:s', $time_track) : gmdate('z:H:i:s', $time_track + $context['sandbox']['elapsed']),
      '@left' => gmdate('z:H:i:s', $time_left),
      '@m_insert' => $context['sandbox']['m_'.KWIKEE_INSERT_ACTION],
      '@m_update' => $context['sandbox']['m_'.KWIKEE_UPDATE_ACTION],
      '@m_delete' => $context['sandbox']['m_'.KWIKEE_DELETE_ACTION],
      '@m_all' => $context['sandbox']['m_'.KWIKEE_INSERT_ACTION] + $context['sandbox']['m_'.KWIKEE_UPDATE_ACTION] + $context['sandbox']['m_'.KWIKEE_DELETE_ACTION],
      '@m_all_fixed' => $context['sandbox']['m_size'],

      '@b_insert' => $context['sandbox']['b_'.KWIKEE_INSERT_ACTION],
      '@b_update' => $context['sandbox']['b_'.KWIKEE_UPDATE_ACTION],
      '@b_delete' => $context['sandbox']['b_'.KWIKEE_DELETE_ACTION],
      '@b_all' => $context['sandbox']['b_'.KWIKEE_INSERT_ACTION] + $context['sandbox']['b_'.KWIKEE_UPDATE_ACTION] + $context['sandbox']['b_'.KWIKEE_DELETE_ACTION],
      '@b_all_fixed' => $context['sandbox']['b_size'],

      '@p_insert' => $context['sandbox']['p_'.KWIKEE_INSERT_ACTION],
      '@p_update' => $context['sandbox']['p_'.KWIKEE_UPDATE_ACTION],
      '@p_delete' => $context['sandbox']['p_'.KWIKEE_DELETE_ACTION],
      '@p_all' => $context['sandbox']['p_'.KWIKEE_INSERT_ACTION] + $context['sandbox']['p_'.KWIKEE_UPDATE_ACTION] + $context['sandbox']['p_'.KWIKEE_DELETE_ACTION],
      '@p_all_fixed' => $context['sandbox']['p_size'],
      '@batch_runs' => $context['sandbox']['run'],
      '@cron_runs' => $context['sandbox']['crons'],
    );
    $context['message'] = t(
      'Processed @processed out of @all items<br/>Time elapsed: @elapsed<br/>Time left: @left<br/>
      ********** Manufacturers **********<br/>
      inserted: @m_insert<br/>
      updated: @m_update<br/>
      deleted: @m_delete<br/>
      all: @m_all(@m_all_fixed)<br/>
      ********** Brands *****************<br/>
      inserted: @b_insert<br/>
      updated: @b_update<br/>
      deleted: @b_delete<br/>
      all: @b_all(@b_all_fixed)<br/>
      ********** Components *************<br/>
      inserted: @p_insert<br/>
      updated: @p_update<br/>
      deleted: @p_delete<br/>
      all: @p_all(@p_all_fixed)<br/>',
      $stat
    );
  }

  $context['finished'] = $context['sandbox']['progress'] / $context['sandbox']['max'];

  if($context['sandbox']['progress'] >= $context['sandbox']['max']) {
    $context['results'] = array(
      '@processed' => $context['sandbox']['progress'],
      '@elapsed' => gmdate('z:H:i:s', $time_track),
      'fid' => $fid,
      'statistic' => $stat,
    );
  }

  return TRUE;
}

function _xoxo_import_kwikee_import_file_finished($success, $results, $operations) {
  if($success) {
    variable_set('xoxo_import_kwikee_fid_'.$results['fid'], $results['statistic']+array('@date' => format_date(time(), 'medium')));
    unset($results['statistic']);
    $message = t(
      'Import completed successfully!<br/>@processed items processed.<br/>Time spent: @elapsed.',
      $results
    );
    // set status for file as imported
    $q = "UPDATE {file_usage} SET id = :processed WHERE fid = :fid";
    db_query($q, array(':processed' => $results['@processed'],':fid' => $results['fid']));

    // tell Kwikee that file successfully imported
    $file = file_load($results['fid']);
    $parts = explode('__', $file->filename);
    if(isset($parts[1])) {
      _xoxo_import_kwikee_update_success($parts[1].'.zip');
    }
    cache_clear_all();
  }
  else {
    if(empty($results['cron'])) {
      $message = t('Import has finished with an error.');
    }
    watchdog('xoxo_import', 'Import has finished with an error.', array(), WATCHDOG_ERROR);
  }

  if(empty($results['cron'])) {
    drupal_set_message($message);
    if(!empty($_SESSION['massive_import_fids'])) {
      $fid = array_shift($_SESSION['massive_import_fids']);
      drupal_goto('xoxo-import-kwikee/import/'.$fid);
    }
    else {
      drupal_goto('admin/config/development/xoxo-import-kwikee');
    }
  }
}

/*
 * Part of implementation of hook_cron
 */
function _xoxo_import_kwikee_cron() {
  if(!variable_get('kwikee_cron', 0)) {
    return;
  }
  set_time_limit(60);
  
  $files = _xoxo_import_kwikee_uploaded_files(TRUE);
  $error_fids = variable_get('xoxo_import_error_fids', array());
  if(empty($files)) {
    _xoxo_import_kwikee_check_updates();
    return;
  }
  else {
    $queue_fid = variable_get('xoxo_import_queue_fid', FALSE);
    $runs = 1;
    $status = TRUE;
    
    // check if file is pending in a queue
    if(!$queue_fid) {
      $file = array_shift($files);
      // get first not "corrupted" file from queue
      while(!empty($files) && in_array($file->fid, $error_fids)) {
        $file = array_shift($files);
      }

      // "normal" file not found, so check for updates
      if(in_array($file->fid, $error_fids)) {
        _xoxo_import_kwikee_check_updates();
        return;
      }
    
      // check file size
      if((int) $file->size < 200) {      
        watchdog('xoxo_import', 'Can\'t start update: empty file - @file.', array('@file' => $file->name), WATCHDOG_NOTICE);
        $error_fids[] = $file->fid;
        variable_set('xoxo_import_error_fids', $error_fids);
        variable_set('xoxo_import_queue_fid', FALSE);
        variable_set('xoxo_import_context', NULL);
        $status = _xoxo_import_kwikee_cron();
        return $status;
      }

      $queue_fid = $file->fid;
      $context = NULL;
      $runs++;
    }
    else {
      foreach($files as $f => $item) {
        if($item->fid == $queue_fid) {
          $file = $item;
          break;
        }
      }
      $context = variable_get('xoxo_import_context', NULL);
      $context['sandbox']['starttime'] = time();
    }
    
    if($queue_fid) {     
      $status = _xoxo_import_kwikee_upate_run($status, $runs, $context, $queue_fid, $file, $error_fids);
      if($status) {
        if(empty($context['sandbox']['crons'])) {
          $context['sandbox']['crons'] = 1;
        }
        else {
          $context['sandbox']['crons']++;
        }
        variable_set('xoxo_import_context', $context);
        watchdog('xoxo_import', 'File @file: regular import iteration has been performed on cron run.', array('@file' => $file->name), WATCHDOG_INFO);
        return TRUE;
      }
    }
  }
}

function _xoxo_import_kwikee_upate_run($status, $runs, &$context, $queue_fid, $file, $error_fids) {
  while($status && $runs > 0) {
    $status = _xoxo_import_kwikee_import_file_process($queue_fid, $context, TRUE);
    $runs--;
  }
  
  if($status) {
    if($context['finished'] < 1) {
      // update is not finished
      if(empty($context['sandbox']['run'])) {
        $context['sandbox']['run'] = 2;
      }
      else {
        $context['sandbox']['run']++;
      }
      
      $time_spent_on_run = $context['sandbox']['endtime'] - $context['sandbox']['starttime'];
      $context['sandbox']['elapsed'] += $time_spent_on_run;
      
      if($time_spent_on_run < 3) { // if run is less than 3 sec
        $runs = 1;
        $status = _xoxo_import_kwikee_upate_run($status, $runs, $context, $queue_fid, $file, $error_fids);
      }
      else {
        variable_set('xoxo_import_queue_fid', $queue_fid);
        variable_set('xoxo_import_context', $context);
      }
    }
    else {
      // update is finished
      $context['results']['cron'] = 1;
      _xoxo_import_kwikee_import_file_finished($status, $context['results'], '');// '', TRUE
      watchdog('xoxo_import', 'File @file: import completed.', array('@file' => $file->name), WATCHDOG_INFO);
      // reset queue variables
      variable_set('xoxo_import_queue_fid', FALSE);
      variable_set('xoxo_import_context', NULL);
    }
  }
  else {
    // error has occured during import
    // skip this update file to prevent recursion
    $error_fids[] = $queue_fid;
    variable_set('xoxo_import_error_fids', $error_fids);
    variable_set('xoxo_import_queue_fid', FALSE);
    variable_set('xoxo_import_context', NULL);
  }
  
  return $status;
}

function _xoxo_import_kwikee_check_updates() {
  // check for updates if there were no files found in queue
  $response = _xoxo_import_kwikee_check_remote(NULL, TRUE);
  if($response['status'] && $response['count']) {
    watchdog('xoxo_import', 'New @count file(s) uploaded.', array('@count' => $response['count']), WATCHDOG_INFO);
  }
  else {
    watchdog('xoxo_import', 'There are no new files found.', array(), WATCHDOG_INFO);
  }
}

//Use to import manufacturers.
//All manufacturer IDs and names.
/* $m = 'manufacturer_data'; */
/* $r = new XMLReader; */
/* $d = new DOMDocument; */
/* $r->open(DRUPAL_ROOT . '/sites/default/files/xoxo_import/brands_n_mans.xml'); */
/* while ($r->read() && $r->name !== $m); */
/* while($r->name === $m) { */
/*   $x = simplexml_import_dom($d->importNode($r->expand(), TRUE)); */
/*   $id = $x->mfr_id->__toString(); */
/*   $n = $x->name->__toString(); */
/*   $q = db_merge('xoxo_manufacturers')->key(array('mid' => $id))->fields(array('mid' => $id, 'value' => $n))->execute(); */
/*   $r->next($m); */
/* } */
