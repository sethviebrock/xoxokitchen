(function($){
	Drupal.behaviors.views_drag_drop = {
		attach: function(context, settings) {
			var vdd_settings = Drupal.settings.views_drag_drop;
			if(vdd_settings.options.reusable_draggable_item == "1") {
				var helper = "clone";
			}
			else {
				var helper = "original";
			}
			 
			var draggable_element = $("div .item-draggable-"+vdd_settings.preset).not(".item-draggable-"+vdd_settings.preset+"-disabled");		
			var droppable_element = $('div .item-droppable-'+vdd_settings.preset).not('.item-droppable-'+vdd_settings.preset+'-disabled');
			
			
			$("div .item-draggable-"+vdd_settings.preset+":not(.item-draggable-"+vdd_settings.preset+"-disabled)").live('mouseover',function(){
			    var drag_helper = helper;
				if($(this).hasClass("item-draggable-vibrant")) {
		    	drag_helper = "original";
		    	var closest_droppable = $(this).closest("div .item-droppable-"+vdd_settings.preset);    	
			  }
				
				if($("div .item-droppable-"+vdd_settings.preset+":not(.item-droppable-"+vdd_settings.preset+"-disabled)").length) {
					$(this).draggable({
						appendTo: "body",
						helper: drag_helper,
						opacity: 0.9,
						revert: "invalid",
						start: function(event, ui) {
				    	  // assign all droppables
				    	 	$(droppable_element).trigger('assign_dproppables');
				    		if($(this).hasClass("item-draggable-vibrant")) {
				    			$(closest_droppable).droppable("disable");
				    			$(this).next().addClass('item-op-disabled');
				    			$(this).next().hide();
				    		}
				    		$(this).css('cursor', 'move');//$('body div').css('cursor', 'move')
				    		$(closest_droppable).addClass("item-droppable-active");
					    },
						stop: function(event, ui) {
					    	if($(this).hasClass('item-draggable-vibrant')) {
				    			$(closest_droppable).not('.item-droppable-'+vdd_settings.preset+'-disabled').droppable('enable');
				    			$(this).next().removeClass('item-op-disabled');
				    		}
					    /*	$('body div').css('cursor', 'auto');*/
					    	$(closest_droppable).removeClass("item-droppable-active");
					    },
					    drag: function(event, ui) {
					    }
					});
					$(this).draggable('enable');
				}
				else {
					$(this).draggable('disable');
				}
			});
			
			// Additional operations mechanism
			// ****
			// XOXO specific event handler
			$('.view-kitchen .item-draggable-wrapper').live('mouseenter',function(event){
        if(!$(document.body).data('op_focus')) {
          $('.item-additional-ops').hide();
          $(this).find('.item-additional-ops').not('.item-op-disabled').show();
        }
      });
			$('.view-kitchen .item-draggable-wrapper').live('mouseleave',function(event){
        if(!$(".item-additional-ops (textarea,input):focus").length) {
          $(this).find('.item-additional-ops').hide();
          $.data(document.body, 'op_focus', false);
        }
        else {
          $.data(document.body, 'op_focus', true);
        }
      });
			// ****
			
			$('.item-operations-wrapper.itevent-mouseenter').live('mouseenter',function(event){
				if(!$(document.body).data('op_focus')) {
					$('.item-additional-ops').hide();
					$(this).find('.item-additional-ops').not('.item-op-disabled').show();
				}
			});
			
			$('.item-operations-wrapper.itevent-click').live('click',function(event){
				if(!$(document.body).data('op_focus')) {
			//	commenting fix for IE9 task #18224	
				  var item_add_ops = $(this).find('.item-additional-ops');
				  $('.item-additional-ops').not(item_add_ops).hide();
					$(this).find('.item-additional-ops').not('.item-op-disabled').show();
				}
			});
			//.item-draggable-wrapper, 
			$('.item-operations-wrapper').live('mouseleave',function(event){
				if(!$(".item-additional-ops (textarea,input):focus").length) {
					$(this).find('.item-additional-ops').hide();
					$.data(document.body, 'op_focus', false);
				}
				else {
					$.data(document.body, 'op_focus', true);
				}
			});		
			
			// Highlight active (on hover) element
			$('.item-draggable-wrapper').live('mouseenter',function(event){
				$(this).addClass('vdd-active-item');
			});
			$('.item-draggable-wrapper').live('mouseleave',function(event){
				$(this).removeClass('vdd-active-item');
			});
			
			// assign handlers for all actions
			for(var action_id in vdd_settings.actions) {		
				$('body').delegate('#'+action_id+':not(.additional-op-static)', 'click', function(event) {
					if(!event.opstatus) {
						var op_id = $(this).attr('id');
						var op_link = $(this);
						var draggable_item = $(this).parent().parent().prev();
						var container = $(draggable_item).parent();
						var droppable_item = $(draggable_item).closest('.item-droppable-'+vdd_settings.preset);
	
						$(op_link).parent().parent().hide();
						$(draggable_item).addClass('item-processing');

						var args = new Object();
						args.preset = vdd_settings.preset;
						args.op = vdd_settings.actions[op_id];
						var drag_raw = $(draggable_item).attr('data-drag');
						args.drag_raw = drag_raw;
						var drag_crc = $(draggable_item).data('crc');
						args.drag_crc = drag_crc;
						
						if($(droppable_item).length) {
							var drop_raw = $(droppable_item).attr('data-drop');
							args.drop_raw = drop_raw;
							var drop_crc = $(droppable_item).data('crc');
							args.drop_crc = drop_crc;
						}
						
						var request = $.ajax({
						  type: "POST",
						  url: "/ajax/drag-and-drop",
						  data: args,
						  dataType: 'json',
						  success: function(result){
							if(result.status == true) {
								if(result.options.remove_container) {
									$(container).hide("blind", {}, 400, function() {
										$(this).remove();
									});
								}
								else if(result.options.remove_additional_options) {
									$(op_link).parent().hide("blind", {}, 400, function() {
										$(this).remove();
									});
								}
								else if(result.options.remove_current_link) {
									$(op_link).hide("blind", {}, 400, function() {
										$(this).remove();
									});
								}
								else if(result.html) {
									$(op_link).html(result.html);
									
									if(result.new_action) {
										$(op_link).attr('id', 'op-'+result.new_action);
										$(op_link).removeClass('additional-op-'+vdd_settings.actions[op_id]);
										$(op_link).addClass('additional-op-'+result.new_action);
									}
									else {
										$(op_link).attr('id', 'op-'+vdd_settings.actions[op_id]+'-disabled');
										$(op_link).addClass('additional-op-disabled');
									}
								}
								else {
									$(this).remove();
								}
	
								// apply custom options
								// -> add options
								if(result.options.add) {
									// -> attribute is class
									if(result.options.add.html_class) {
										// -> target is parent
										if(result.options.add.html_class.parent) {
											$(draggable_item).addClass(result.options.add.html_class.parent);
										}
									}
								}
								// -> remove options
								if(result.options.remove) {
									// -> attribute is class
									if(result.options.remove.html_class) {
										// -> target is parent
										if(result.options.remove.html_class.parent) {
											$(draggable_item).removeClass(result.options.remove.html_class.parent);
										}
									}
								}
								// check for args replacement
								if(result.has_new_drag_args) {
									$(draggable_item).attr('data-drag', result.new_drag_args);
									$(draggable_item).attr('data-crc', result.new_drag_crc);
									$(draggable_item).data('crc', result.new_drag_crc);
								}
								
								// check for remove droppable exception
								if(result.options.replace_drop_args) {
									$(droppable_item).attr('data-drop', result.new_drop_args);
									$(droppable_item).attr('data-crc', result.new_drop_crc);
									$(droppable_item).data('crc', result.new_drop_crc);
								}
								
								$(droppable_item).droppable('enable');
								$('.additional-op').removeClass('last-succeded');
								$(op_link).addClass('last-succeded');
								$('.item-additional-ops').hide();
								if(result.options.custom_trigger_element && result.options.custom_trigger_event) {
								  if(result.options.custom_trigger_element == 'document') {
								    $(document).trigger(result.options.custom_trigger_event);
								  }
								  else {
								    $(result.options.custom_trigger_element).trigger(result.options.custom_trigger_event);
								  }
									
								}
							}
							$(draggable_item).removeClass('item-processing');
						  },
						  error: function (xhr, status) {
							  $(draggable_item).removeClass('item-precessing');
						  }
						});
						event.opstatus = true;
					}
				});
			}
			
			$("div .item-droppable-"+vdd_settings.preset+":not(.item-droppable-"+vdd_settings.preset+"-disabled)").live('assign_dproppables', function() {
			  $(this).droppable({
					activeClass: 'droppable-state-default',
					hoverClass: 'droppable-state-hover',
					accept: function(draggable) {
				  		var drop_args_json = $(this).attr('data-drop');
				  		var drop_args = jQuery.parseJSON(drop_args_json);
				  		if(!$(draggable).hasClass('item-draggable-'+vdd_settings.preset)) {
				  			return false;
				  		}
				  		if(typeof drop_args['@exceptions@'] != 'undefined') {
				  			for(var exception in drop_args['@exceptions@']) {	
				  				for(var k in drop_args['@exceptions@'][exception]) {	
						  			if($(draggable).hasClass(exception+drop_args['@exceptions@'][exception][k])) {
						  				return false;
						  			}
					  			}
				  			}
				  		}
				  		return true;
			  		},
					tolerance: 'pointer',
					drop: function(event, ui) {
						// reset cursor
						/*$('body div').css('cursor', 'auto');*/
						
						if($(ui.draggable).hasClass("item-draggable-vibrant")) {
							var draggable_wrapper = $(ui.draggable).parent();
						}
						
						var args = new Object();
						args.preset = vdd_settings.preset;
						
						// perform operations for vibrant draggable
				    	if($(ui.draggable).hasClass("item-draggable-vibrant")) {
				    		// search for nearest droppable parent
				    		var droppable_parent_item = $(ui.draggable).closest('.item-droppable-'+vdd_settings.preset);
							if($(droppable_parent_item).length) {
								var drop_parent_raw = $(droppable_parent_item).attr('data-drop');
								args.drop_parent_raw = drop_parent_raw;
								var drop_parent_crc = $(droppable_parent_item).data('crc');
								args.drop_parent_crc = drop_parent_crc;
								args.droppable_parent = $(droppable_parent_item).attr('id');
							}
							
				    		$(ui.draggable).remove();
				    		$("div .item-droppable-"+vdd_settings.preset).not(".item-droppable-"+vdd_settings.preset+"-disabled").each(function(index) {
				    		    $(this).droppable("enable");
				    		});
				    		$(".item-droppable-active").droppable("enable");
				    		$(".item-droppable-active").removeClass("item-droppable-"+vdd_settings.preset+"-disabled");
				    		$(".item-droppable-active").removeClass("item-droppable-active");
					    }
				    	
						var drag_raw = $(ui.draggable).attr('data-drag');
						args.drag_raw = drag_raw;
						var drag_crc = $(ui.draggable).data('crc');
						args.drag_crc = drag_crc;
						
						var drop_raw =  $(this).attr('data-drop');
						args.drop_raw = drop_raw;
						var drop_crc = $(this).data('crc');
						args.drop_crc = drop_crc;
		
						var droppable_element = this;
		
						var offset = $(droppable_element).offset();
						var d_width = $(droppable_element).css('width');
						var d_height = $(droppable_element).css('height');
						$('body').after('<div id="drag-drop-loader"></div>');
						$('#drag-drop-loader').offset(offset);
						$('#drag-drop-loader').css('width', d_width);
						$('#drag-drop-loader').css('height', d_height);
						if(vdd_settings.output.loader) {
							$('#drag-drop-loader').css('background-image', 'url('+vdd_settings.output.loader+')');
						}
						
						$(droppable_element).droppable('disable');
		
						var request = $.ajax({
						  type: "POST",
						  url: "/ajax/drag-and-drop",
						  data: args,
						  dataType: 'json',
						  success: function(result){
							if(result.status) {
								if(vdd_settings.output.loader) {
									$(droppable_element).css('background-image', 'none');
									$(droppable_element).css('opacity', '1');
								}
								
								var content = result.html;
								
								// dynamic target
								if(result.element != false) {
									if(vdd_settings.output.method == 'add') {
										$(result.element).append(content);
										var new_content = $(result.element).find('.item-wrapper').last();
										$(new_content).show('blind', {} ,400);
									}
									else {
										$(result.element).hide('blind', {} ,400);
										$(result.element).html(content);
										$(result.element).show('blind', {} ,400);
									}
								}
								// default target
								else {
									if(vdd_settings.output.method == 'add') {
										if(vdd_settings.output.element == '@droppable@') {
											$(droppable_element).append(content);
											var new_content = $(droppable_element).find('.item-wrapper').last();
											$(new_content).show('blind', {} ,400);
										}
										else if(vdd_settings.output.element == '@draggable@') {
											$(ui.draggable).append(content);
											var new_content = $(ui.draggable).find('.item-wrapper').last();
											$(new_content).show('blind', {} ,400);
										}
										else {
											// class or id
											$(vdd_settings.output.element).append(content);
											var new_content = $(vdd_settings.output.element).find('.item-wrapper').last();
											$(new_content).show('blind', {} ,400);
										}
									}
									else {
										if(vdd_settings.output.element == '@droppable@') {
											$(droppable_element).hide('blind', {} ,400);
											$(droppable_element).html(content);
											$(droppable_element).show('blind', {} ,400);
										}
										else if(vdd_settings.output.element == '@draggable@') {
											$(ui.draggable).hide('blind', {} ,400);
											$(ui.draggable).html(content);
											$(ui.draggable).show('blind', {} ,400);
										}
										else {
											// id
											$(vdd_settings.output.element).hide('blind', {} ,400);
											$(vdd_settings.output.element).html(content);
											$(vdd_settings.output.element).show('blind', {} ,400);
										}
									}
									
									if(vdd_settings.options.reusable_draggable_item != "1") {
										$(ui.draggable).remove();
									}
								}
								
								// highlight output
								if(vdd_settings.options.highlight_output.html_class != undefined) {
									var hl_delay = 1000;
									if(vdd_settings.options.highlight_output.time != undefined) {
										hl_delay = vdd_settings.options.highlight_output.time;
									}
									$('.'+vdd_settings.options.highlight_output.html_class)
									.delay(hl_delay).queue(function () {$(this).removeClass(vdd_settings.options.highlight_output.html_class);$(this).dequeue();});
								}
								    
								// check for drop args replacement
								if(result.has_new_drop_args) {
									$(droppable_element).attr('data-drop', result.new_drop_args);
									$(droppable_element).data('crc', result.new_drop_crc);
								}
								// check for drag args replacement
								if(result.has_new_drag_args) {
									$(ui.draggable).attr('data-drag', result.new_drag_args);
									$(ui.draggable).data('crc', result.new_drag_crc);
								}
								
								// check for drop parent args replacement
								if(result.droppable_parent) {
									if($("#"+result.droppable_parent.droppable_parent_id).length) {
										$("#"+result.droppable_parent.droppable_parent_id).attr('data-drop', result.droppable_parent.droppable_parent_args_raw);
										$("#"+result.droppable_parent.droppable_parent_id).data('crc', result.droppable_parent.droppable_parent_args_crc);
									}
								}
									
								//trigger custom events/methods
								if(result.custom_triggers) {
							    $.each(result.custom_triggers, function(i, trigger) {
							      var status = true;
                    if(trigger.conditions) {
                      for(var condition in trigger.conditions) {
                        var c = trigger.conditions[condition];
                        var rule = '=';
                        if(c.rule) {
                          rule = c.rule;
                        }
                        if(c.element && c.type && c.attribute && c.value) {
                          switch(rule) {
                            case '=' : {
                              status = ($(c.element)[c.type](c.attribute) == c.value);
                            } break;
                            case '>' : {
                              status = ($(c.element)[c.type](c.attribute) > c.value);
                            } break;
                            case '<' : {
                              status = ($(c.element)[c.type](c.attribute) == c.value);
                            } break;
                          }
                        }
                      }
                    }
                    if(status) {
                      if(trigger.element && trigger.event) {
                        $(trigger.element).trigger(trigger.event);
                      }
                      if(trigger.method) {
                        $(trigger.element)[trigger.method]();
                      }
                    }
							    });  
								}
							}
							
							// check for disabling droppable
							if(result.dis_dp) {
								$(droppable_element).droppable('disable');
								$(droppable_element).addClass("item-droppable-"+vdd_settings.preset+"-disabled");
							}
							else {
								$(droppable_element).droppable('enable');
							}
							
							$('#drag-drop-loader').remove();
						  },
						  error: function (xhr, status) {
							if(vdd_settings.output.loader) {
								$('#drag-drop-loader').remove();
							}
						  }
						});
						
						$(draggable_wrapper).remove();
					}
				});
			});
		}
	};
})(jQuery);

jQuery.expr[':'].focus = function( elem ) {
  return elem === document.activeElement && ( elem.type || elem.href );
};
