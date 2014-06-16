(function($){
    window.search_input_value = '';
    $(document).data("ajax_processing", false);
 
    // prevent search fields from losing focus (version 2: changes in views/includes/ajax.inc line:72
    jQuery.fn.xoxofocus = function() {
      var value = $(this).val();
      if(window.search_input_value != value) {
        window.search_input_value = value;
        $(this).putCursorAtEnd();
      }
    };
    
    // Puts the cursor at the end of a textbox/ textarea
    jQuery.fn.putCursorAtEnd = function() {
      return this.each(function() {
        $(this).focus();
        if(this.setSelectionRange) {     
          var len = $(this).val().length * 2;
          this.setSelectionRange(len, len);
        }
        else {
          $(this).val($(this).val());
        }
        this.scrollTop = 999999;
      });
    };

    Drupal.behaviors.xoxo_fields = {
	attach: function(context, settings) {
      // set flag when ajax is started
      var mssg1 = 'Are you sure? <span>By clicking yes, you are agree to remove this from My Kitchen</span>';
      var ttl1 = 'My Kitchen Edit';
      var mssg2 = 'Are you sure? <span>By clicking yes, you are agree to remove this item from the Shopping List</span>';
      var ttl2 = 'Shopping List Edit';
      var sl = settings.xoxo_fields.page == 'shopping-list';
      var ttl = sl ? ttl2 : ttl1;
      var mssg = sl ? mssg2 : mssg1;
      $('form').ajaxStart(function(event, xhr) {
        $(document).data("ajax_processing", true);
        $(document).data("custom_select_updated", false);
      });
      // perform somy actions on ajax complete event
      $('form').ajaxComplete(function(event, xhr, settings) {
        // fix custom select if add ingredient
        if(event.target.id == 'recipe-node-form') {
          var params = {
            changedEl: "select",
            visRows: 10,
            scrollArrows: true
          }
          mySelect(params);  
        }
        
        if(event.target.id == 'views-exposed-form-components-block-3' ||
           event.target.id == 'views-exposed-form-recipes-components-block-3' ||
           event.target.id == 'views-exposed-form-components-for-shopping-list-block-1') {
            // emulate click on "search" fieldset
            if(event.target.id == 'views-exposed-form-recipes-components-block-3') {
              $('.view-display-id-block_3 .collapsed:first a').not('.view-display-id-block_2 .collapsed a').trigger('click');
            }
            $(document).data("ajax_processing", false);
        }
      });

	    if(settings.xoxo_fields.dialog_status) {
		// confirm modal for delete calendar/shlist items
		var confirm_delete_element = $('<div class="confirm-delete-window"></div>');
		$(confirm_delete_element).html(mssg);
		$('.confirm-delete-window').remove();
		$('body').append(confirm_delete_element);
		$('.confirm-delete-window').dialog({
		    resizable: false,
		    width: 500,
		    modal: true,
		    autoOpen: false,
		    title: ttl,
		    close: function(event, ui) {
		    },
		    buttons: {
			"Cancel": function() {
			    $(this).dialog('close');
			},
		    "Yes": function() {
			    var op_element = $(this).data('op');
			    $(op_element).trigger('click', true);
			    $(this).dialog('close');
			}
		    }
		});
		$('body').delegate('#op-delete_item, #op-delete_shopping_list_item', 'click', function(event, pass) {
		    if(!pass) {
			event.opstatus = 1;
			$('.confirm-delete-window').data('op', this).dialog('open');
		    }
		});
	    }

	    // handle disappearing of shopping list items and sections
	    $('body').delegate('#op-delete_shopping_list_item', 'click', function(event) {
		if(!event.opstatus) {
		    //var items = $(this).parent().parent().parent().parent().parent().find('.item-wrapper').length;
		    var items = $(this).closest('.fieldset-wrapper').find('.item-wrapper').length;
		    if(items < 2) {
			$(this).closest('.item-category').hide("blind", {}, 400, function() {
			    $(this).remove();
			});
		    }
		    else {
			$(this).parent().parent().parent().hide("blind", {}, 400, function() {
			    $(this).remove();
			});
		    }
		}
	    });

	    // day descriptions
	    $('body').bind('inplaceedit_textarea', function (event, data) {
		if($('.event-day-'+data.args.day+' .description-text').length) {
		    $('.event-day-'+data.args.day+' .description-text').html(data.text);
		}
		else {
		    var day_row = $('.calendar-day-'+data.args.date);
		    var day_cell = $(day_row).find('td').first();
		    $(day_row).after('<tr class="event-day-'+data.args.day+' event-description"><td colspan="5" class="description-text">'+data.text+'</td></tr>');
		}
	    });

	    // shopping list accordeon (version 2)
		$('body').delegate('.fieldset-title-new', 'click', function(event) {
			if(!event.busy) {
				if($(this).parent().parent().parent().find('.fieldset-wrapper').css('display') == 'none') {
					$(this).parent().parent().parent().find('.fieldset-wrapper').slideDown({duration: 'fast',easing: 'linear'});
					$(this).parent().parent().parent().removeClass('collapsed-section');
					event.busy = true;
				}
				else {
					$(this).parent().parent().parent().find('.fieldset-wrapper').slideUp('fast');
					$(this).parent().parent().parent().addClass('collapsed-section');
					event.busy = false;
				}
			}
		});

    // remove event description link
    $('.additional-op-calendar_day_description_remove .remove-button').live('click', function (event, data) {
  		$(this).closest('tr').next('.event-description').remove();
  		$(this).parent().prev().find('.control-value').html('empty');
  		$(this).parent().prev().find('.control-value').addClass('empty-value');
  		$(this).parent().prev().find('.input-type-textarea').val('');
  		$(this).hide();
    });

	    if(settings.xoxo_fields.dialog_status) {
		// modal confirm dialog
		$('.unflag-action').not('.ui-dialog-content').not('.confirm-processed').each(function(i, element) {
		    var index = Math.ceil(Math.random()*1000000); ;
		    if(!$(element).hasClass('confirm-processed')) {
			$(element).addClass('remove-action-'+index);
			$(element).addClass('confirm-processed');
			$(element).attr('indx', index);
			var confirm_element = $(element).clone();
			$(confirm_element).removeAttr('href');
			$(confirm_element).addClass('confirm-action');
			$(confirm_element).removeClass('flag-link-toggle');
			$(element).after(confirm_element);
			$(element).hide();
		    }
		});
		$('body').delegate('.confirm-action:not(.ui-dialog-content)', 'click', function () {
		    var ttl1 = 'My Kitchen Edit';
		    var mssg1 = 'Are you sure? <span>By clicking yes, you are agree to remove this from My Kitchen</span>';
		    var ttl2 = 'Staples List Edit';
		    var mssg2 = 'Are you sure? <span>By clicking yes, you are agreeing to remove this item from your staples list.</span>';
		    var index = $(this).attr('indx');
		    var options = new Object();
		    var stpls = $(this).closest(
		      '#quicktabs-tabpage-kitchen_setup-2, .view-components-for-shopping-list'
		    ).length == 1;
		    var ttl = stpls ? ttl2 : ttl1;
		    var mssg = stpls ? mssg2 : mssg1;
		    options.index = index;
		    Drupal.behaviors.xoxo_fields.run_confirm(ttl, mssg, options);
		});
	 }

	    if(settings.xoxo_fields.calendar_status) {
		var $dp = $("<input type='text' />").hide().datepicker({
		    onSelect: function(dateText, inst) {
			var day = inst.selectedDay;
			var month = inst.selectedMonth+1;
			var year = inst.selectedYear;
			var str_date = day+'/'+month+'/'+year;

			var args = new Object();
			args.date = dateText;
			args.nid = settings.xoxo_fields.arg1;
			var request = $.ajax({
			    type: "POST",
			    url: "/ajax/add-to-calendar",
			    data: args,
			    dataType: 'json',
			    success: function(result){
				if(result.status == true) {
				    $('#recipe-add-to-calendar a').append('<div class="added-event">added to '+dateText+'</div>');
				    // add selected day to exceptions
				    settings.xoxo_fields.exceptions.push(str_date);
				}
			    },
			    error: function (xhr, status) {
				Drupal.behaviors.xoxo_fields.run_modal(settings.xoxo_fields.messages.error_title, settings.xoxo_fields.messages.error_message+' Status: '+status, '');
			    }
			});
		    },
		    defaultDate: settings.xoxo_fields.current_date.full,
		    beforeShowDay: function(date) {
			var status = true;
			var day = date.getDate();
			var month = date.getMonth()+1;
			var year = date.getFullYear();
			if(year < settings.xoxo_fields.current_date.year) {
			    status = false;
			}
			else if(year == settings.xoxo_fields.current_date.year) {
			    if(month < settings.xoxo_fields.current_date.month) {
				status = false;
			    }
			    else if(month == settings.xoxo_fields.current_date.month) {
				if(day < settings.xoxo_fields.current_date.day) {
				    status = false;
				}
			    }
			}

			if(status) {
			    var str_date = day+'/'+month+'/'+year;
			    status = !Drupal.behaviors.xoxo_fields.inarray(str_date, settings.xoxo_fields.exceptions);
			}

			return [status, ''];
		    }
		}).appendTo('#recipe-add-to-calendar');

		$("#recipe-add-to-calendar").click(function(e) {
		    if ($dp.datepicker('widget').is(':hidden')) {
			$dp.datepicker("show");
			var offs = $(this).offset();
			var top = offs.top+$(this).height();
			$dp.datepicker("widget").offset({top:top, left:offs.left});
		    } else {
			$dp.hide();
		    }

		    e.preventDefault();
		});
	    }

	    // prevent submitting form during ajax request
	    //$('#views-exposed-form-components-block-3 #edit-title, #views-exposed-form-recipes-components-block-2 #edit-title, #views-exposed-form-components-for-shopping-list-block-1 #edit-title, .view-display-id-block_3 #edit-title').keypress(function(e){
	    $('#views-exposed-form-components-block-3 #edit-title, #views-exposed-form-recipes-components-block-2 #edit-title, #views-exposed-form-components-for-shopping-list-block-1 #edit-title, .view-display-id-block_3 #edit-title').keypress(function(e){
    		if(e.which == 13) {
    		    e.preventDefault();
    		}
	    });

	    /*
	     * Message modal dialog
	     */
	    Drupal.behaviors.xoxo_fields.run_modal = function(title, message, options) {
		$('#error-dialog').remove();
		var error_message = $('<div id="error-dialog"></div>');
		$(error_message).html(message);
		$('body').after(error_message);
		$('#error-dialog').hide();
		$("#error-dialog").dialog({ modal: true, title: title });
	    };

	    /*
	     * Confirm modal dialog
	     */
	    Drupal.behaviors.xoxo_fields.run_confirm = function(title, message, options) {
		var index = options.index;
		$('#confirm-dialog').remove();
		var error_message = $('<div id="confirm-dialog"></div>');
		$(error_message).html(message);
		$('body').after(error_message);
		$('#confirm-dialog').hide();
		$("#confirm-dialog").dialog({
		    resizable: false,
		    width: 500,
		    modal: true,
		    title: title,
		    close: function(event, ui) {

		    },
		    buttons: {
		    "Cancel": function() {
			    $(this).dialog("close");
			},
			"Yes": function() {
			    $('.remove-action-'+index).removeClass('confirm-processed');
			    $('.remove-action-'+index).removeClass('confirm-action');
			    $('.remove-action-'+index).trigger('click');

			    if(settings.xoxo_fields.page == 'kitchen') {
				var remove_element = $('.remove-action-'+index).not('.ui-dialog-content').closest('.item-draggable-wrapper');
				var section = $(remove_element).closest('.collapsible');
				var items = $(section).find('.item-wrapper').length;
				if(items < 2) {
				    $(section).hide("blind", {}, 400, function() {
					$(this).remove();
				    });
				}
				else {
				    $(remove_element).hide("blind", {}, 400, function() {
					$(this).remove();
				    });
				}
			    }
			    $(this).dialog("close");
			}
			
		    }
		});
	    };

	    /*
	     * searches for needle element in haystack array
	     */
	    Drupal.behaviors.xoxo_fields.inarray = function(needle, haystack) {
		var length = haystack.length;
		for(var i = 0; i < length; i++) {
		    if(haystack[i] == needle) return true;
		}
		return false;
	    }
	}
    };
})(jQuery);

jQuery.expr[':'].focus = function( elem ) {
  return elem === document.activeElement && ( elem.type || elem.href );
};
