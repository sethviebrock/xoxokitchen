(function ($) {
  function xoxoKitchenSelectDate(dateText, inst) {
    link = $(inst.input).parent('a');
    nid = link.data('nid');
    ex = link.data('exceptions');
    ex.push(dateText);
    link.data({ exceptions: ex });
    url = '/add-to-calendar/' + nid + '/' + dateText;
    $.get(url);
  }
  function xoxoKitchenCallCalendar(event) {
    dp = $(event.target).find('.recipe-add-to-calendar-input');
    if (dp.datepicker('widget').is(':hidden')) {
      dp.datepicker('show');
      var offs = $(this).offset();
      var top = offs.top + $(this).height();
      dp.datepicker('widget').offset({ top: top, left: offs.left});
    } else {
      dp.hide();
    }
    event.preventDefault();
  }
  function xoxoKitchenCalendarError(xhr, status) {
    Drupal.behaviors.xoxo_fields.run_modal(
      settings.xoxo_fields.messages.error_title,
      settings.xoxo_fields.messages.error_message + ' Status: ' + status,
      ''
    );
  }
  Drupal.behaviors.xoxoKitchenCalendar = {};
  Drupal.behaviors.xoxoKitchenCalendar.attach = function (context, settings) {
    function xoxoKitchenCalendarDay(date) {
      ex = $(this).parent('a').data('exceptions');
      currentYear = settings.xoxoKitchen.year;
      currentMonth = settings.xoxoKitchen.month;
      currentDay = settings.xoxoKitchen.day;
      var status = true;
      var day = date.getDate();
      var month = date.getMonth() + 1;
      var year = date.getFullYear();
      if(year < currentYear) {
        status = false;
      }
      else if(year == currentYear) {
        if(month < currentMonth) {
          status = false;
        }
        else if(month == currentMonth) {
          if(day < currentDay) {
            status = false;
          }
        }
      }
      if(status) {
        var str_date = month + '/' + day + '/' + year;
        status = !Drupal.behaviors.xoxo_fields.inarray(str_date, ex);
      }
      return [status, ''];
    }
    dps = [];
    links = settings.xoxoKitchen.calLinks;
    picker = {
      onSelect: xoxoKitchenSelectDate,
      beforeShowDay: xoxoKitchenCalendarDay
    };
    for (i in links) {
      link = $('#' + links[i].id, context);
      dps[i] = link.find('.recipe-add-to-calendar-input').datepicker(picker).appendTo(link);
      link.click(xoxoKitchenCallCalendar);
      link.data('nid', links[i].nid);
      link.data('exceptions', links[i].exceptions);
    }
  }
}) (jQuery);
