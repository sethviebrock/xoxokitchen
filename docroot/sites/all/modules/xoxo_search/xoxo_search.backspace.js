(function ($) {
  Drupal.behaviors.xoxoKitchenBackspace = {};
  Drupal.behaviors.xoxoKitchenBackspace.attach = function (context, settings) {
    function xoxoKitchenDisableBackspace(event) {
      var bksp = 8;
      var pressed = event.which;
      var el = event.target.nodeName.toLowerCase();
      var tp = event.target.type;
      var isInput = (el === 'input' && tp === 'text') || el === 'textarea';
      if (!isInput && pressed === bksp) event.preventDefault();
    }
    $(document, context).keydown(xoxoKitchenDisableBackspace);
  }
}) (jQuery);
