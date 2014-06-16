<?php foreach ($fields as $id => $field): ?>
<?php 
//dsm($field);
if($id=='title'){$title=$field->content;}
if($id=='body_1'){$body=$field->content;}
if($id=='field_recipe_image'){$img=$field->content;}
if($id=='name'){$un=$field->content;}
?>
<?php endforeach; ?>

<div class="res">
  <div class="res_img"><?php print $img; ?></div>
  <div class="res_title"><?php print $title; ?></div>
  <div class="res_body"><?php print $body; ?></div>
  <div class="res_us"><div class="uid_title">Created by:&nbsp;</div><?php print $un; ?></div>
</div>