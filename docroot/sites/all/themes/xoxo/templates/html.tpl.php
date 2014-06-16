<?php global $base_root; ?>
<?php print $doctype; ?>
<html lang="<?php print $language->language; ?>" dir="<?php print $language->dir; ?>"<?php print $rdf->version . $rdf->namespaces; ?>>
<head<?php print $rdf->profile; ?>>
  <?php print $head; ?>
  <title><?php print $head_title; ?></title>  
  <?php print $styles; ?>
  <!--[if lt IE 9]><link rel="stylesheet" type="text/css" href="<?php echo $base_root; ?>/sites/all/themes/xoxo/css/ie8-and-down.css" /><![endif]-->
  <?php print $scripts; ?>
  <!--[if lt IE 9]><script src="http://html5shiv.googlecode.com/svn/trunk/html5.js"></script><![endif]-->
  <script type="text/javascript">
	/*jQuery(function(){
	jQuery('.view-components-for-shopping-list .view-content').jScrollPane({showArrows:false,scrollbarWidth:24,verticalDragMinHeight:45,horizontalDragMinWidth:24,verticalGutter:10,verticalDragMaxHeight:45});
});*/
   </script>
   
</head>
<body<?php print $attributes;?>>
  <div id="skip-link">
    <a href="#main-content" class="element-invisible element-focusable"><?php print t('Skip to main content'); ?></a>
  </div>
  <?php print $page_top; ?>
  <?php print $page; ?>
  <?php print $page_bottom; ?>
</body>
</html>