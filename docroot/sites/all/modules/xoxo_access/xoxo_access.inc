<?php
/*
 *
 * Is it allowed to change status in the recipe.
 * @param object|integer $r Recipe.
 * @return boolean
 *
 */
function _xoxo_access_change_status($r) {
  $r = (isset($r->nid) && isset($r->uid) && isset($r->type)) ? $r : (ctype_digit($r) ? node_load($r) : FALSE);
  $r = $r ? ($r->type === 'recipe' ? $r : FALSE) : FALSE;
  if(empty($r)) {
    return user_access('recipe_status');
  }
  elseif($GLOBALS['user']->uid == 1 || (
      user_access('recipe_status')
      && $GLOBALS['user']->uid == $r->uid
    )) {
    return TRUE;
  }
  else {
    return FALSE;
  }
}
/*
 *
 * Is public recipe. Can all users view it.
 * @param object|integer $r Recipe
 * @return boolean
 *
 */
function _xoxo_access_public_recipe($r) {
	$r = (isset($r->nid) && isset($r->uid) && isset($r->type)) ? $r : node_load($r);
	$r = $r->type === 'recipe' ? $r : FALSE;
	$i = field_get_items('node', $r, 'field_recipe_status');
	$s = isset($i[0]['value']) ? $i[0]['value'] : FALSE;
	return !empty($s);
}
function _xoxo_access_node_access($op, $node, $account = NULL) {
  if(isset($node->type)) {
    $ctype = $node->type;
  }
  else {
    $ctype = $node;
  }
  if($ctype === 'recipe') {
    $public = _xoxo_recipe_status($node) == 1;
    $private = !$public;
    $admin = $GLOBALS['user']->uid == 1;
    $owner = $GLOBALS['user']->uid == $node->uid;
    $del = $op == 'delete';
    if ($admin) {
      return TRUE;
    }
    if ($del && $public) {
      return FALSE;
    }
    if(!($public || $owner)) {
      return FALSE;
    } 
  }
  if($ctype != 'page' && $ctype != 'article') {
    global $user;
    switch($op) {
      case 'create': {
        if(user_access('node_'.$ctype.'_create_page')) {
          return TRUE;
        }
        return FALSE;
      } break;
      case 'view': {
        if(user_access('node_'.$ctype.'_view_page')) {
          return TRUE;
        }
        elseif($node->uid == $user->uid && user_access('node_'.$ctype.'_view_own_page')) {
          return TRUE;
        }
        return FALSE;
      } break;
      case 'update': {
        if(user_access('node_'.$ctype.'_edit_page')) {
          return TRUE;
        }
        elseif($node->uid == $user->uid && user_access('node_'.$ctype.'_edit_own_page')) {
          return TRUE;
        }
        return FALSE;
      } break;
      case 'delete': {
        if(user_access('node_'.$ctype.'_delete_page')) {
          return TRUE;
        }
        elseif($node->uid == $user->uid && user_access('node_'.$ctype.'_delete_own_page')) {
          return TRUE;
        }
        return FALSE;
      } break;
    }
  }
  return node_access($op, $node, $account);
}
