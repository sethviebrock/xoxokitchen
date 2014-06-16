(function($){
	Drupal.behaviors.inplaceedit = {
		attach: function(context, settings) {
			$('body').delegate('.inplaceedit-control:not(.inplaceedit-active, .inplaceedit-focused, .inplaceedit-disabled) span', 'mouseenter', function(event) {
				if(!event.opstatus) {
					if(!$(document.body).data('inplace_focused')) {
						Drupal.behaviors.inplaceedit.edit_mode(this);
					}
				}
				event.opstatus = true;
			});
			
			/*
			window.browser_msie = false;
			 jQuery.each(jQuery.browser, function(i, val) {
		      if(i == 'msie') {
		        window.browser_msie = true;
		      }
		   });*/

			$('body').delegate('.inplaceedit-control .focused', 'mouseleave', function(event) {
				$(this).removeClass('inplaceedit-active');
				$(this).removeClass('focused-control');
			});

			
			$('body').delegate('.inplaceedit-control .active-control', 'click', function(event) {
				$(this).addClass('focused-control');
				$.data(document.body, 'inplace_focused', true);
			});

			
			$('body').delegate('.inplaceedit-focused span', 'mouseleave', function(event) {
				$(this).parent().removeClass('inplaceedit-focused');
			});

			$('body').delegate('.inplaceedit-control:not(.reset) .active-control', 'blur', function(event) {
				if(!event.opstatus) {
					$(this).parent().addClass('inplaceedit-active');
					Drupal.behaviors.inplaceedit.apply();
					$(this).parent().removeClass('inplaceedit-active');
					$('.active-control').hide();
					$.data(document.body, 'inplace_focused', false);

					// custom code for event descriptions
					$(this).closest('.item-additional-ops').find('.remove-button').show();

				}
				event.opstatus = true;
			});
	
			
			$('body').delegate('.inplaceedit-control .active-control:not(.focused-control)', 'mouseleave', function(event) {
				$('.control-value').show();
				$('.active-control').hide();
				$('.control-save').hide();
				$('.inplaceedit-control').removeClass('inplaceedit-active');
			});
			$('body').delegate('.inplaceedit-control .focused-control', 'keypress', function(event) {
				if(event.keyCode == 13) {
					if(!event.opstatus) {
						if(!$(this).hasClass('input-type-textarea')) {
							Drupal.behaviors.inplaceedit.apply();
							if($(this).parent().data('hover')) {
								$(this).parent().addClass('inplaceedit-focused');
							}
							$(this).parent().removeClass('inplaceedit-active');
							$('.active-control').hide();
							$('.inplaceedit-control').addClass('reset');
							$('.inplaceedit-control input, .inplaceedit-control select').blur();
							$('.inplaceedit-control').removeClass('reset');
							$.data(document.body, 'inplace_focused', false);
					 	}
					}
					event.opstatus = true;
				}
			});
			$('.inplaceedit-control').live({
		        mouseenter:
		           function() {
					  $.data(this, 'hover', true);
		           },
		        mouseleave:
		           function() {
		        	  $.data(this, 'hover', false);
		           }
		       }
		    );
		}
	};

	/*
	 * Enter edit mode
	 */
	Drupal.behaviors.inplaceedit.edit_mode = function(element) {
		Drupal.behaviors.inplaceedit.apply();
		$('.control-value').show();
		$('.active-control').hide();
		$('.inplaceedit-control .active-control').removeClass('focused-control');
		$('.inplaceedit-control').removeClass('inplaceedit-active');
		var value = $(element).parent().children('.control-value').html();
		$(element).hide();
		$(element).parent().addClass('inplaceedit-active');
		Drupal.behaviors.inplaceedit.input($(element).parent(), value);
	};

	/*
	 * Determine type of input and create it
	 */
	Drupal.behaviors.inplaceedit.input = function(control, value) {
		// textfield input
		if($(control).hasClass('control-type-textfield')) {
			$(control).children('.input-type-text').show();
		}
		// textarea input
		if($(control).hasClass('control-type-textarea')) {
			$(control).children('.input-type-textarea').show();
			$(control).children('.control-save').show();
		}
		// select input
		else if($(control).hasClass('control-type-select')) {
			$(control).children('.input-type-select').show();
		}
	};

	/*
	 * Apply value for control
	 */
	Drupal.behaviors.inplaceedit.apply = function() {
		var control_input = $('.inplaceedit-active .active-control');
		var control = $(control_input).parent();

		// textfield input
		if($(control).hasClass('control-type-textfield')) {
			var prev_value = $(control).children('.control-value').html();
			var value = $(control_input).attr('value');
		}
		// textarea input
		if($(control).hasClass('control-type-textarea')) {
			var prev_value = $(control).children('.control-value').html();
			var value = $(control_input).attr('value');
		}
		// select input
		else if($(control).hasClass('control-type-select')) {
			var prev_value = $(control).children('.control-value').attr('key');
			var value = $(control).find('select option:selected').val();
		}

		if(value != '' && prev_value != value) {
			$(control).children('.control-value').html('');
			Drupal.behaviors.inplaceedit.send(control, prev_value, value);
	    }
		else {
			$(control).children('.control-save').hide();
		}
		$(control).children('.control-value').show();
	};

	/*
	 * Send value to server
	 */
	Drupal.behaviors.inplaceedit.send = function(control, prev_value, value) {
		var args = new Object();
		var args_raw = $(control).attr('data-args');
		args.args_raw = args_raw;
		var args_crc = $(control).data('crc');
		args.args_crc = args_crc;
		args.value = value;
		args.prev_value = prev_value;
		$('.inplaceedit-control').addClass('inplaceedit-disabled');
		$(control).children('.inplaceedit-control-intput').hide();
		$(control).children('.control-save').hide();
		$(control).addClass('control-processing');
		$(control).removeClass('control-error');
		var request = $.ajax({
		  type: "POST",
		  url: "/ajax/inplaceedit",
		  data: args,
		  dataType: 'json',
		  success: function(result){
			if(result.status == true) {
				var input_element = $(control).children('.inplaceedit-control-intput');
				var display_element = $(control).children('.control-value');

				// textfield input
				if($(control).hasClass('control-type-textfield')) {
					$(display_element).html(result.new_value);
					$(input_element).attr('value', result.new_value);
				}
				// textarea input
				if($(control).hasClass('control-type-textarea')) {
					$(display_element).html(result.new_value);
		//			$(input_element).text(result.new_value);
					$(display_element).removeClass('empty-value');
				}
				// select input
				else if($(control).hasClass('control-type-select')) {
					$(input_element).attr('value', result.new_value);
					var label = $(control).find('select option:selected').text();
					$(display_element).html(label);
					$(display_element).attr('key', result.new_value);
				}

				$(control).attr('data-args', result.new_args);
				$(control).attr('data-crc', result.new_crc);
				$(control).data('crc', result.new_crc);
				$(control).addClass('control-success');

				// trigger custom handler
				var trigger_data = new Object();
				trigger_data.text = result.new_value;
				trigger_data.args = jQuery.parseJSON(result.new_args);
				$('body').trigger('inplaceedit_textarea', trigger_data);

				$(control)
				.delay(1000)
				.queue(function () {
					$(this).removeClass('control-success');
					$(this).dequeue();
				});
			}
			else {
				$(control).children('.control-value').html(prev_value);
		//		$(control).children('.inplaceedit-control-intput').attr('value', prev_value);
				$(control).addClass('control-error');
				$(control)
				.delay(1000)
				.queue(function () {
					$(this).removeClass('control-error');
					$(this).dequeue();
				});
			}
			$(control).removeClass('control-processing');
			$('.inplaceedit-control').removeClass('inplaceedit-disabled');
		  },
		  error: function (xhr, status) {
			$(control).children('.control-value').html(prev_value);
			$(control).children('.inplaceedit-control-intput').attr('value', prev_value);
			$(control).removeClass('control-processing');
			$('.inplaceedit-control').removeClass('inplaceedit-disabled');
			$(control).addClass('control-error');
			$(control)
			.delay(1000)
			.queue(function () {
				$(this).removeClass('control-error');
				$(this).dequeue();
			});
		  }
		});
	};
})(jQuery);
