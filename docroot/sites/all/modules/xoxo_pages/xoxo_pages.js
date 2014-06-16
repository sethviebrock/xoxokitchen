(function ($) { Drupal.behaviors.xoxoPages = {attach: function (context, settings) {
    i = $('<img src="/sites/all/themes/xoxo/images/xoxo_pre.gif" id="the-throbber" />').hide();
    if($('#the-throbber').length < 1) {
	$('.region-content').append(i);
    }
    $(document).bind('flagGlobalBeforeLinkUpdate', function(event, data) {
	viewRefresh('components_for_shopping_list', 'block_1');
	viewRefresh('recipes_components', 'block_3');
	viewRefresh('components', 'block_3');
	viewRefresh('components', 'block_1');
	viewRefresh('components', 'block_4');
    });
}}}) (jQuery);