<?php

/**
 * @file
 * Hooks provided by the Views Drag and Drop module.
 */
 
/*
 * Acts on successful create operation
 * 
 * @param $node
 *   a node object to be saved
 * @param $response
 *   an array of response with next keys: 
 *    'status' - TRUE if success
 *    'has_new_args' - TRUE if response has new args
 *    'op' - performed operation
 *    'dis_dp' - TRUE if need to disable droppable
 *    'element' - target DOM element: .class/#id/@draggable@/@droppable
 *    'html' - response content that will be attached to 'element' or replaced 'element'
 * @param $drag_args
 *   draggable arguments
 * @param $drop_args
 *   droppable arguments
 * @param $preset
 *   preset machine name
 * @param $settings
 *   all settings available for current preset
 *   
 */
function hook_views_drag_drop_node_presave(&$node, &$response, &$drag_args, &$drop_args, $preset, $settings) {

}
 
/*
 * Acts on successful edit operation
 * 
 * @param $node
 *   a node object to be saved
 * @param $response
 *   an array of response with next keys: 
 *    'status' - TRUE if success
 *    'has_new_args' - TRUE if response has new args
 *    'op' - performed operation
 *    'dis_dp' - TRUE if need to disable droppable
 *    'element' - target DOM element: .class/#id/@draggable@/@droppable
 *    'html' - response content that will be attached to 'element' or replaced 'element'
 * @param $drag_args
 *   draggable arguments
 * @param $drop_args
 *   droppable arguments
 * @param $preset
 *   preset machine name
 * @param $settings
 *   all settings available for current preset
 *   
 */
function hook_views_drag_drop_node_alter(&$node, &$response, &$drag_args, &$drop_args, $preset, $settings) {
  /*
  // custom triggering of event/method with condition check support
  $response['custom_triggers']['expand_section'] = array(
    'element' => '.item-category .fieldset-title',
    'event' => 'click',
    'conditions' => array(
      array(
        'element' => '.item-category .fieldset-wrapper',
        'type' => 'css',
        'attribute' => 'display',
        'value' => 'none',
        'rule' => '=',
      ),
    ),
  );
  */
}

/*
 * Acts on successful delete field item operation
 * @param $args
 *   array of all arguments
 * @param $params
 *   array of delete arguments like:
 *   $params = arry(
 *     'nid' => 123,
 *     'field_name' => 'field_value'
 *   )
 * @param $preset
 *   preset machine name
 * @param $settings
 *   all settings available for current preset
 */
function hook_views_drag_drop_delete_field_item($params, $args, $preset, $settings) {

}

/*
 * Assign own custom actions
 * 
 * @param $args
 *   array of all arguments - available if args is provided, otherwise NULL
 */
function hook_views_drag_drop_assign_actions(&$config, $args) {
  $config['action_1'] = array(
    'title' => 'Do Action #1', // used in permissions section
    'preset' => 'preset_id', // if action for particular preset only
    'content' => 'Do action #1',
    // visible by default: 
    //    'status' => 1, - visible
    //    'status' => 0, - invisible 
    //    or custom callback to define visibility based on arguments
    //    'status' => array(
    //      'callback' => '_mymodule_action_1_status',
    //    ),
    'status' => 1,
    // by default delta is 0. You can create separate action menus under one preset on single page using this option
    'delta' => 0, 
    // set static to 1 if there is no need to call ajax for server side calculations ie. just if need to show some text
    'static' => 0,
    'weight' => 1,
    'classes' => 'custom-htmlclass class-abc',
    'new_action' => 'action_2',
    'remove_container' => FALSE, // removes whole rendered element if set to TRUE
    'remove_additional_options' => FALSE, // removes additional options menu if set to TRUE
    'remove_current_link' => FALSE, // removes current presset link if set to TRUE
    'custom_trigger_element' => 'div.my-class',
    'custom_trigger_event' => 'click',
  );
  $config['action_2'] = array(
    'title' => 'Do Action #2',
    'content' => 'Do action #2',
    'weight' => 2,
    'new_action' => 'action_3',
    'remove_container' => FALSE,
    'remove_additional_options' => FALSE,
    'remove_current_link' => FALSE,
  );
  $config['action_3'] = array(
    'title' => 'Do Action #3',
    'content' => 'Do action #3',
    'status' => 0,
    'weight' => 3,
    'remove_container' => FALSE,
    'remove_additional_options' => FALSE,
    'remove_current_link' => FALSE,
  );
}

function _mymodule_action_1_status($preset, $action, &$args) {
  // you can alter arguments on this pre-render stage
  return TRUE;
}

/*
 * Perform own actions
 * 
 * @param $options
 *   an array of additional js options, for example: 
 *   
 *   $optons['add']['class']['parent'] = 'custom-class';
 *   this means: add class 'custom-class' to parent html element ie. whole themed element
 *   
 *   $optons['remove']['class']['parent'] = 'custom-class';
 *   this means: remove class 'custom-class' to parent html element ie. whole themed element
 */
function hook_views_drag_drop_perform_actions($action, &$output, &$new_action, $preset, &$args, &$options) {
  if($action == 'action_1') {
    // perform operation based on $args here

    return TRUE;
  }
  elseif($action == 'action_2') {
    // perform operation based on $args here
    

    return TRUE;
  }
  elseif($action == 'action_3') {
    // perform operation based on $args here
    
    // to disable action link
    // $new_action = FALSE; 
    // or you can specify particular action like 'action_1' or 'action_2'
    
    
    $output = 'The end. Nothing to do more. But lets do action #1 and automatically prepare link for doing #2';
    $new_action = 'action_1';
    
    return TRUE;
  }
  
  return FALSE;
}

/*
 * Returns draggable arguments for appropriate preset
 * 
 * @param $preset
 *   preset machine name
 *   
 * @return
 *   array of args as LABEL => FIELD
 */
_views_drag_drop_draggable_args($preset);

/*
 * Returns droppable arguments for appropriate preset
 * 
 * @param $preset
 *   preset machine name
 *   
 * @return
 *   array of args as LABEL => FIELD
 */
_views_drag_drop_droppable_args($preset);


/*********************************************************************************************************
 *  How to use theme function for draggable/droppable elements
 *********************************************************************************************************/
/*
 *  1) defene arguments
 *  you can use 
 *  _views_drag_drop_draggable_args($preset) 
 *  or
 *  _views_drag_drop_droppable_args($preset) 
 *  function to get available arguments as LABLE => FIELD
 */
$args = array(
  'title' => 'new node\'s title', // field/attribute name => data
  'field_1' => 'text...', 
  'field_2' => 'text2...',
  'uid' => 1,
  '@custom' => t('New element!'),
  // you can specify exceptions for droppables in next manner where draggables with classes "class-prefix-nid_1", "class-prefix-nid_2", "class-prefix-nid_n" 
  // will be ommited by current droppable element
  //'@exceptions@' => array(
  //  'class-prefix-' => array('nid_1', 'nid_2', 'nid_n')
  //)
);

/*
 * 2) print themed content
 */
$content = theme(
  'views_drag_drop_draggable', // or 'views_drag_drop_droppable' in case of droppable
  array(
    'preset' => 'preset_1', // preset machine name
    'args' => $args, // arguments
    'content' => 'Hello World!', // content of the draggable
    'status' => TRUE, // set element as disabled (not required)
  )
);

print $content;
/*********************************************************************************************************
 *  How to use theme function for additional operations
 *********************************************************************************************************/
/*
 *  Use this theming together with hook_views_drag_drop_assign_actions and hook_views_drag_drop_perform_actions hooks
 *  defene custom arguments
 */
$args = array(
  'arg1' => 123,
  'arg2' => 'hehe...',
  'arg3' => TRUE,
  'arg4' => '',
);

/*
 * print themed content
 */
$content = theme(
  'views_drag_drop_operations',
  array(
    'preset' => 'generic', // not required
    'delta' => 0, // by default delta is 0. You can create separate action menus under one preset on single page using this option
    'content' => 'test block with hover operations',
    'args' => $args
  )
);

print $content;
/*********************************************************************************************************/ 
   