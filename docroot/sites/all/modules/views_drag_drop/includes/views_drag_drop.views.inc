<?php

/**
 * @file
 *
 * Creates calendar displays of Views results.
 */
/**
 * Implementation of hook_views_plugins
 */
function views_drag_drop_views_plugins() {
  return array(
    'style' => array(
      'draggable' => array(
        'title' => t('Draggable (Drag&Drop)'),
        'help' => t('Adds ability to drag rows.'),
        'handler' => 'views_drag_drop_plugin_style_dragdrop_draggable',
        'uses options' => TRUE,
        'uses row plugin' => TRUE,
        'uses grouping' => TRUE,
        'uses row class' => TRUE,
        'type' => 'normal',
        'path' => drupal_get_path('module', 'views_drag_drop').'/includes',
        'theme' => 'views_draggable_unformatted',
        'theme path' => drupal_get_path('module', 'views_drag_drop') . '/theme',
        'theme file' => 'views_dragdrop.theme.inc',
      ),
      'droppable' => array(
        'title' => t('Droppable (Drag&Drop)'),
        'help' => t('Adds ability to drop on rows.'),
        'handler' => 'views_drag_drop_plugin_style_dragdrop_droppable',
        'uses options' => TRUE,
        'uses row plugin' => TRUE,
        'uses grouping' => TRUE,
        'uses row class' => TRUE,
        'type' => 'normal',
        'path' => drupal_get_path('module', 'views_drag_drop').'/includes',
        'theme' => 'views_droppable_unformatted',
        'theme path' => drupal_get_path('module', 'views_drag_drop') . '/theme',
        'theme file' => 'views_dragdrop.theme.inc',
      ),
    ),
  );
}