<?php
//$variables['grid'] contains the data.
$header = array_shift($variables['grid']);
$table = array(
  '#theme' => 'table',
  '#header' => $header,
  '#rows' => $variables['grid']
);
echo drupal_render($table);
