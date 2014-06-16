(function ($) {
  Drupal.behaviors.xoxoKitchenCategorize = {};
  Drupal.behaviors.xoxoKitchenCategorize.attach = function (context, settings) {
    var elClass = 'categorize';
    var elSep = '-';
    var e1 = 'xoxoKitchenCategorizeAdded';
    var e3 = 'flagGlobalBeforeLinkUpdate';
    function xoxoKitchenCategorizeRemove(event, data) {
      if (data.flagStatus == 'unflagged') {
        var theEl = $('.' + elClass + elSep + data.contentId, context);
        theEl.removeClass(elClass + elSep + 'added').addClass(elClass + elSep + 'removed');
      }
    }
    function xoxoKitchenCategorizeAdd(event) {
      $(this).find('.flag-action').click();
      $(this).removeClass(elClass + elSep + 'removed').addClass(elClass + elSep + 'added');
    }
    $('.' + elClass, context).bind(e1, xoxoKitchenCategorizeAdd);
    $(document, context).bind(e3, xoxoKitchenCategorizeRemove);
  }
}) (jQuery);
