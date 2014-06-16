<?php
/**
 * @file views-draggable-unformatted.tpl.php
 */
?>
<?php if (!empty($title)): ?>
  <h3><?php print $title; ?></h3>
<?php endif; ?>
<?php foreach ($rows as $id => $row): ?>
  <div class="<?php print $classes_wrapper; ?>">
    <div class="<?php print $classes_array[$id]; ?>" data-drag='<?php print $dd_args[$id]; ?>' data-crc='<?php print $crc[$id]; ?>'>
      <?php print $row; ?>
    </div>
  </div>
<?php endforeach; ?>
