(function ($) {
  Drupal.behaviors.xoxoComponent = {};
  Drupal.behaviors.xoxoComponent.attach = function (context, settings) {
    var contentSel = '.content';
    var bubbleSel = '.group-component-actions, .group-recipe-actions, .bubble-tail';
    var calSel = '#ui-datepicker-div';
    var calendar = $(calSel);
    var contents = $(contentSel, context);
    var bubbles = $(bubbleSel, context);
    contents.mouseenter(xoxoComponentBubble);
    contents.mouseleave(xoxoComponentUnBubble);
    function xoxoComponentBubble(event) {
      if (!$(calSel).is(':hidden')) return false;
      bubbles.not(event.target).hide();
      var bubble = $(event.target).closest(contentSel, context).find(bubbleSel, context);
      calendar.hide();
      bubble.show();
    }
    function xoxoComponentUnBubble(event) {
      if ($(calSel).is(':hidden')) bubbles.hide();
    }
  }
}) (jQuery);
