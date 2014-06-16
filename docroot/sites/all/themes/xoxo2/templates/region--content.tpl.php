<div<?php print $attributes; ?>>
  <div<?php print $content_attributes; ?>>
    <a id="main-content"></a>
    <?php print render($title_prefix); ?>
    <div class="title_with_logo">
		<?php if ($title): ?>
		  <?php if ($title_hidden): ?>
			<div class="element-invisible">
		  <?php endif; ?>    
			<h1 class="title" id="page-title"><?php print $title; ?></h1>
		  <?php if ($title_hidden): ?>
			</div>
		  <?php endif; ?>
		<?php endif; ?>
		<?php $block = module_invoke('views', 'block_view', 'brand_logo-block');
			if (isset($block)){
			print render($block);
			} ?>
	</div>
    <?php print render($title_suffix); ?>
    <?php if ($tabs && !empty($tabs['#primary'])): ?><div class="tabs clearfix"><?php print render($tabs); ?></div><?php endif; ?>   
    <?php if ($action_links ): ?><ul class="action-links"><?php print render($action_links); ?></ul><?php endif; ?>    
    <?php print $content; ?>
    <?php if ($feed_icons): ?><div class="feed-icon clearfix"><?php print $feed_icons; ?></div><?php endif; ?>
  </div>
</div>