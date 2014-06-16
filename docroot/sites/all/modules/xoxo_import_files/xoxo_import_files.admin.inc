<?php
function _xoxo_import_files_form_settings($form, &$form_state) {
  $result = _xoxo_import_files_get_files();
  $form['#submit'] = array('system_settings_form_submit','_xoxo_import_files_form_settings_submit');
  $form_settings = array(
    '#type' => 'fieldset',
    '#title' => t('Module settings'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  $form_settings['xoxo_import_files_import_path'] = array(
    '#type' => 'textfield', 
    '#title' => t('Мanufacturers file system path'), 
    '#default_value' => variable_get('xoxo_import_files_import_path', ''), 
    '#maxlength' => 255, 
    '#description' => t('An existing local file system path for storing private files. It should be writable by Drupal and not accessible over the web. See the online handbook for <a href="@handbook">more information about securing private files</a>.', array('@handbook' => 'http://drupal.org/documentation/modules/file')), 
    '#after_build' => array('system_check_directory'),
  );
  $form_settings['xoxo_import_import_path'] = array(
    '#type' => 'textfield',
    '#title' => t('Path import dir'),
    '#default_value' => variable_get('xoxo_import_import_path', ''),
    '#description' => t('Drupal stream wrapper (<em>private://path</em>)'),
  );
  $form['form_settings'] = system_settings_form($form_settings);

  if ($result) {
    $form['files_list'] = array(
      '#type' => 'fieldset',
      '#title' => t('Мanufacturers Files'),
      '#collapsible' => TRUE, 
      '#collapsed' => FALSE,
    );
    $header = array(
      array(
      'data'=> t('files'),
       ),
      array(
      'data'=> t('size'),
       ),
    );
    foreach ( $result as $manufacturer => $files ) {
      if ($manufacturer && is_array($files)) {
        $form['files_list'][$manufacturer] = array(
          '#type' => 'fieldset',
          '#title' => $manufacturer,
          '#collapsible' => TRUE,
          '#collapsed' => TRUE,
        );
        $rows = array();
        foreach ($files as $file) {
          $size = format_size($file->filesize);
          $link = l($file->filename, file_create_url($file->uri));
          $rows[] = array(
            'data' => array($link, $size),
          );
        }
        if (empty($rows)) {
          $rows[] = array(
            'data' => array(t('Empty dir')),
          );
        }
        $form['files_list'][$manufacturer]['table'] = array(
          '#markup' => theme('table', array('header'=> $header, 'rows' => $rows)),
        );
      }
    }
    $form['files_list']['submit'] = array(
      '#type' => 'submit',
      '#value' => t('Import files'),
    );
  } 
  return $form;
}
function _xoxo_import_files_form_settings_submit($form, &$form_state) {
  if ($form_state['input']['op'] == t('Import files')) {
    $files = _xoxo_import_files_get_files();
    if (!empty($files)) {
      $move = array();
      foreach ($files as $manufacturer) {
        if (is_array($manufacturer)){
          foreach ($manufacturer as $file) {
            $move[] = $file;
          }       
        }
      }
      if (!empty($move)) {
        _xoxo_import_files_move_files($move);
      }
    }
  }
}
function _xoxo_import_files_move_files(array $files) {
  $xoxo_import_uri = variable_get('xoxo_import_import_path', FALSE);
  if (is_dir(drupal_realpath($xoxo_import_uri))) {
    foreach ($files as $file) {
      $replace_uri = file_unmanaged_move($file->uri, 'xoxoimport://');
      if ($replace_uri) {
        $file->uri = $replace_uri;
        $file = file_save($file, $xoxo_import_uri);
        file_usage_add($file, 'xoxo_import', 'kwikee', 0);
      }
    }
  }
}
function _xoxo_import_files_get_files($dir = NULL, $tree = TRUE ) {
  if ($dir == NULL) {
    $dir = drupal_realpath(variable_get('xoxo_import_files_import_path', FALSE));
    if ($dir) {
      $files = _xoxo_import_files_get_files($dir);
      if (empty($files)) {
        return FALSE;
      }
      return $files;
    } else {
      return FALSE;
    }
  } else {
    if (is_dir($dir) && $handle = opendir($dir)) {
      $files = array();
      while (FALSE !== ($filename = readdir($handle))) {
        $fullpath = $dir
              . '/'
              . $filename;
        if (is_dir($fullpath) && ($filename != '.' && $filename != '..')) {
          if ($tree) {
            $files[$filename] =  _xoxo_import_files_get_files($fullpath, FALSE);
          } else {
            $files = array_merge($files, _xoxo_import_files_get_files($fullpath, FALSE));
          }
        }
        if (is_file($fullpath) && _xoxox_import_check_file_format($filename)) {
          $file = new stdClass();
          $file->filename = $filename;
          $file->name = pathinfo($filename, PATHINFO_FILENAME);
          $file->uri = str_replace(
                drupal_realpath(variable_get('xoxo_import_files_import_path', '')) . '/', 
                'manufacturers://',
                $fullpath
              );
          $file->filemime = file_get_mimetype($fullpath);
          $file->filesize = filesize($fullpath);
          
          $file->fullpath = $fullpath;
          
          $files[] = $file;
        }
      }
      closedir($handle);
      return $files;
    }
  }
}
function _xoxox_import_check_file_format($filename) {
  return TRUE;
}