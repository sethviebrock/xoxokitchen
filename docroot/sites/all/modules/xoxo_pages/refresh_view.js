/**
 * View refresh (AJAX). Only works for displays with exposed forms.
 */
function viewRefresh(name, display) {
    viewBlock(name, display);
    var f =
	'form#views-exposed-form-'
	+ name.replace(/_/g, '-')
	+ '-'
	+ display.replace(/_/g, '-')
	+ ' input.form-submit';
    jQuery(f).trigger('click');
    jQuery('.ajax-progress-throbber').hide();
    return f;
}
/**
 * Block view user interface.
 */
function viewBlock(name, display) {
    s = '.view-id-' + name + '.view-display-id-' + display;
    // if (name == 'components') {
    // 	s = '#quicktabs-tabpage-components-1';
    // }
    // else if (name == 'recipes_components') {
    // 	s = '#quicktabs-tabpage-kitchen_setup-1';
    // }
    // else if (name == 'components_for_shopping_list') {
    // 	s = '.view-display-id-block_1';
    // }
    jQuery(s).block({
	message: jQuery('#the-throbber'),
	css: { border: 0, backgroundColor: 'transparent', top: '20px' },
	overlayCSS: { backgroundColor: 'white' },
	centerX: 0,
    });
    return s;
}