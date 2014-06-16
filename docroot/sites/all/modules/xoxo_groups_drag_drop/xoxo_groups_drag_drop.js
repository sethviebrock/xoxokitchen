(function ($) {
	Drupal.behaviors.xoxoGroupsDragDrop = Object;
	function drop(event, ui) {
		var w = $(event.target).attr('data-drop');
    var n = $.parseJSON(w).nid;
		var groups = $('.item-droppable-shopping_list .item-category');
		var sep = '/';
		var m = sep;
		groups.each(function (index, el) {
			var t = tid($(el));
			m += t + sep;
		});
		$.get('/xoxo-groups-drag-drop/' + n + m);
	}
	function tid(el) {
		if (el.length == 0) return 0;
		var s = el.attr('class').match(/ item-category-(\d+) /);
		if (s != null) return s[1]
		else return
	}
	Drupal.behaviors.xoxoGroupsDragDrop.attach = function(context, settings) {
		var a = $('.item-droppable-shopping_list', context);
		var b = Object;
		b.placeholder = 'between-groups';
		b.stop = drop;
		b.items = '.item-category';
		a.sortable(b);
		a.disableSelection();
	}
}) (jQuery);