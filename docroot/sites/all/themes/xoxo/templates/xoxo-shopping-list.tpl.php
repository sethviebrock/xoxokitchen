<div class="shopping-list-item-content">
	<div class="sh_first">
		<div class="sh_title"><?php print $component_title; ?></div>
		<div class="sh_brand"><?php print $brand; ?></div>
    <div class="sh_descr"><?php print $description; ?></div>
	</div>
	<div class="sh_some sl_line"><?php print $qty; ?></div>
	<div class="sh_uom sl_line"><?php print $uom; ?></div>
	<div class="sh_user sl_line"><?php print $user_name; ?></div>
	<div class="sh_add sl_line"><div class="add_tit"><?php print t('Last Added on'); ?></div><?php print $last_added; ?></div>
	<?php if($status) : ?>
		<?php print t('Purchased'); ?>
	<?php endif; ?>	
</div>
