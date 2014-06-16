(function (jQuery) {
  Drupal.behaviors.xoxoWeek = {attach: function(context, settings) {
    domNode = '.view-id-' + settings.xoxoWeek.view_name;
    ajax_data = {
      url: '/xoxo-week/ajax',
      dataType: 'json',
      data: {_xoxo_week_ajax_args: {
        view_name: settings.xoxoWeek.view_name,
        view_display: settings.xoxoWeek.display_id,
      }},
      success: function(returned) {
        jQuery(domNode, context).replaceWith(returned.view);
        settings.xoxoWeek.prev_week = returned.new_sets.prev_week;
        settings.xoxoWeek.next_week = returned.new_sets.next_week;
      },
      error: function(xhr, status){
        console.debug(xhr);
      },
    };
    jQuery(domNode + ' .previous-date', context).live('click', function (element) {
      ajax_data.data._xoxo_week_ajax_args.view_arg = settings.xoxoWeek.prev_week;
      res = jQuery.ajax(ajax_data);
      element.preventDefault();
    });
    jQuery(domNode + ' .next-date', context).live('click', function (element) {
      ajax_data.data._xoxo_week_ajax_args.view_arg = settings.xoxoWeek.next_week;
      res = jQuery.ajax(ajax_data);
      element.preventDefault();
    });
  }};
})(jQuery);
