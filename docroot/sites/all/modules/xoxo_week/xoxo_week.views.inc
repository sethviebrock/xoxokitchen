<?php
function xoxo_week_views_plugins() {
  return array('style' => array('week' => array(
    'title' => t('Week'),
    'help' => t('Greed organized by date and event type.'),
    'handler' => 'xoxo_week_plugin_style_week',
    'theme' => 'xoxo_week_view_week',
    'uses row plugin' => TRUE,
    'uses row class' => TRUE,
    'uses grouping' => TRUE,
    'uses options' => TRUE,
    'type' => 'normal',
  )));
}
