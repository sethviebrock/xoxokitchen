(function ($) {
  Drupal.behaviors.xoxoSearch = { attach: function (context, settings) {
    var XOXOSEARCH_THROBBER = '<div class="ajax-progress ajax-progress-throbber"><div class="throbber">&nbsp;</div></div>';
    var XOXOSEARCH_POPUP = '<div id="xoxo-search-popup"></div>';
    var ex = '.views-exposed-widget';
    s1 = '#xoxo-search-popup';
    s2 = s1 + ' ul';
    s4 = s2 + ' li';
    s3 = s4 + ':last';
    popup = $(s1);
    if (popup.length < 1) {
      $('body').append(XOXOSEARCH_POPUP);
    }
    popup.bind('dialogclose', xoxoSearchClear);
    $('.xoxo-search-amount, .xoxo-search-add-amount-unit', context).blur(xoxoSearchAmUnit);
    $('.xoxo-search-clear', context).click(xoxoSearchRemove);
    $('.xoxo-search-add-clear', context).click(xoxoSearchRemove);
    $('.ingredients li').click(selectIngredient);
    $('.xoxo-search-amount input', context)
      .bind('change', '', xoxoSearchSelect)
      .change();
    $('.xoxo-search-add-amount input', context)
      .bind('change', 'add-', xoxoSearchSelect)
      .change();
    $('.xoxo-search-name', context).blur(xoxoSearchBrandsThrobber);
    var add = $('.xoxo-search-node-add', context);
    if (!add.hasClass('xoxo-clickable')) {
      add.addClass('xoxo-clickable').click(xoxoSearchCustom);
    }
    popup.scroll(xoxoSearchBottom);
    function xoxoSearchSelect(event) {
      var selected = $(this).val();
      var frac = $(this).closest('.field-item').find('.xoxo-search-' + event.data + 'fraction');
      if (selected < 1) frac.addClass('classDisSelect')
      else frac.removeClass('classDisSelect')
    }
    function xoxoSearchBrandsThrobber(event) {
      var form = $(event.target).closest('.field-item');
      var search = form.find('.xoxo-search-search:visible');
      var throb = form.find('.ajax-progress-throbber');
      if (!throb.length) {
        search.after(XOXOSEARCH_THROBBER);
        //form.find('.ajax-progress-throbber').remove();
      }
    }
    function xoxoSearchAmUnit(event) {
      var amUnit = $(event.target).val();
      $.post('/xoxo-search/json/amount-unit', { 'xoxo-search': amUnit }, function(data) {
        $(event.target).val(data.am_unit);
      });
    }
    function xoxoSearchCustom(event) {
      var form = $(event.target).closest('.field-item');
      if (!form.find('.xoxo-search-add').val()) {
        alert('Please provide the ingredient title.');
        return;
      }
      form.removeClass('xoxo-empty').addClass('xoxo-custom-selected');
      if (!$('.xoxo-empty').length) {
        var field = form.closest('.field-type-ingredients');
        var add = field.find('.field-add-more-submit');
        add.mousedown();
      }
    }
    function xoxoSearchNoNid(event) {
      form = $(event.target).closest('.field-item');
      form.find('.xoxo-search-nid').val(0);
      form.removeClass('xoxo-selected').removeClass('xoxo-custom-selected').addClass('xoxo-empty');
    }
    function xoxoSearchRemove(event) {
      var form = $(event.target).closest('.field-item'); 
      form.find('input[type!="submit"]').val('');
      form.removeClass('xoxo-selected').removeClass('xoxo-custom-selected').addClass('xoxo-empty');
      form.find('.xoxo-search-name').blur();
      form.find('span[val=""]').click();
    }
    function xoxoSearchClear(event) {
      $('.xoxo-search-options-count').val(0);
      $(s1).empty();
    }
    function xoxoSearchBottom(event) {//What happens on scroll.
      bottom = $(s3).position().top + $(s3).innerHeight();
      scroll = $(s1).innerHeight() + 10;
      if (bottom < scroll) {
        name = $(event.target).find('ul').attr('field');
        s = '[name="' + name + '"]';
        field = $(s).closest('.field-item');
        $(s).closest('.field-item').find('.xoxo-search-options-count').val($(s4).length);
        $(s).closest('.field-item').find('.xoxo-search-search').mousedown();
      }
    }
    function xoxoSearchUpdate(e) {
      form = $(e.target).closest(ex); 
      form.block({
  	message: $('#the-throbber'),
  	css: { border: 0, backgroundColor: 'transparent', top: '20px' },
  	overlayCSS: { backgroundColor: 'white' },
  	centerX: 0,
      });
      form.find('.form-submit').click();
      form.find('.ajax-progress').hide();
    }
    function selectIngredient(e) {
      var p = 'Ingredient #';
      var name = $(e.target).closest('ul').attr('field');
      var nid = $(e.target).attr('nid');
      var bid = $(e.target).attr('bid');
      var ing_name = $(e.target).find('.ing-name').text();
      var s = '[name="' + name + '"]';
      var form = $(s).closest('.field-item');
      var brand = form.find('.xoxo-search-brand [val="' + bid + '"]');
      form.find('.xoxo-search-name').val(ing_name);
      brand.click();
      delta = form.attr('delta') * 1 + 1;
      p = p + delta + ': ';
      form.removeClass('xoxo-empty').addClass('xoxo-selected');
      $(s).val(nid);
      if (!$('.xoxo-empty').length) {
        var field = form.closest('.field-type-ingredients');
        var add = field.find('.field-add-more-submit');
        add.mousedown();
      }
      $('.ui-dialog-titlebar-close').click();
      form.find('.search-refresh').click();
    }
    function ingredientId(element) {
      return $(element).attr('nid');
    }
  }
}}) (jQuery);
