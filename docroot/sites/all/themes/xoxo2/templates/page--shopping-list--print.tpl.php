<div class="pr_logo">
  <?php if ($logo): ?>
  <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home" id="logo">
  <img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" />
  </a>
  <?php endif; ?>
</div>
<?php echo '<div class="sh_pr_title">Shopping List</div>';?>
<?php echo render($main_block); ?>





