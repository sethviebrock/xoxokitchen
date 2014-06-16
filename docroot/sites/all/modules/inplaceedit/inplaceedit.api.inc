<?php

/**
 * @file
 * Hooks provided by the In Place Edit module.
 */
 
/*
 * Assign controls.
 * It creates permission for each control.
 * 
 * @return
 *   array of controls as machine_name => label
 *   
 */
function hook_inplaceedit_assign_controls() {
  return array(
    'control_machinename' => 'Example control #1',
  );
}

/*
 * Performs any changes on all controls assigned by all modules
 * 
 * @param $control
 *   control id (control machine-name)
 * @param $value
 *   entered value by user
 * @param $arguments
 *   an array of arguments for current control element
 * @param $prev_value
 *   initial value of the control
 *  
 * @return
 *   TRUE in case of success, FALSE otherwise
 */
function hook_inplaceedit_perform_changes($control, &$value, &$args, $prev_value) {
  switch($control) {
    case 'control_machinename': {
      $value = 'New value';
      return TRUE;
    } break;
  }
}

/*
 * Theme content as in-place edit textfield element
 */
theme(
  'inplaceedit_textfield',
  array(
    'control' => 'control_machinename',
    'args' => array(
      'a' => 123,
      'b' => 'test argument',
      'c' => 'test argument 2'
    ), 
    'value' => 'Test',
  )
);
  