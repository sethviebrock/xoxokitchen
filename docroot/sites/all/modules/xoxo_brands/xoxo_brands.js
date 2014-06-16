(function ($) {
  Drupal.behaviors.xoxoBrands = { attach: xoxoBrandsAttach };
  function xoxoBrandsAttach (context, settings) {
    var e1 = 'flagGlobalBeforeLinkUpdate';
    var flag1 = 'added_to_my_kitchen';
    var sel1 = '.brands-refresh';
    function xoxoBrandsRefresh(event, data) {
      if (data.flagName == flag1) $(sel1, context).trigger('click');
    }
    $(document, context).bind(e1, xoxoBrandsRefresh);
  }
}) (jQuery);
