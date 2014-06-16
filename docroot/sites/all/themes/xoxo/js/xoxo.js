// JavaScript Document

// fix carusel pozition after page resizing
(function ($) { Drupal.behaviors.xoxoTheme = {
  attach: function (context, settings) {
							
$(window).resize(function(){
 // alert("Stop it!");
  $('.jcarousel-list').css('left', 0);
});



 
/******************************************************************************
**************************** Add Super Custom Scrollbar ***********************
*******************************************************************************/

/*var api = jQuery("#block-views-ba8b1876d32929ba77f6bf98fbef2d33 .main-scroll .view-content").jScrollPane({verticalGutter: 10}).data("jsp"); 
  jQuery(".view-components-for-shopping-list .jspPane").resize(function() {
    jQuery("#block-views-ba8b1876d32929ba77f6bf98fbef2d33 .main-scroll .view-content").jScrollPane({verticalGutter: 10}).data("jsp").reinitialise();
});

var api = jQuery(".view-recipes-components .view-content").jScrollPane({verticalGutter: 10}).data("jsp"); 
  jQuery(".view-recipes-components .jspPane").resize(function() {
    jQuery(".view-recipes-components .view-content").jScrollPane({verticalGutter: 10}).data("jsp").reinitialise();
});

var api = jQuery(".view-components .view-content").jScrollPane({verticalGutter: 10}).data("jsp"); 
jQuery(".view-components .jspPane").resize(function() {
   jQuery(".view-components .view-content").jScrollPane({verticalGutter: 10}).data("jsp").reinitialise();
});*/


/*---Default Value in Create/Edit Recipe Form (Ingredients Field)---*/
$("#recipe-node-form #edit-field-recipe-ingredients .form-type-select .xoxo-search-unit option:first").text("Unit");
//$(".title#recipe-node-form").text("Unit");

  //Add Required Label on add/edit recipie Form
  $('#recipe-node-form .form-required', context).after('<br><div class="req">(Required)</div>');

		$("form#user-register-form").attr("autocomplete","off");
		/*------------------change style for checkboxes--------------------------*/	
  		$('.form-type-checkbox input.form-checkbox').wrap('<span class="circleCheck" />');	
		jQuery(".circleCheck").each(
		function() {     
			 changeCheckStart(jQuery(this));     
		});	
		function changeCheckStart(el)
		{
		  var el = el,
			input = el.find("input").eq(0);
			if(input.attr("checked")) {
			  el.addClass("box_checked");
			}
		   	return true;
		}		
								
		jQuery(".circleCheck").click(
		  function() {
			 changeCheck(jQuery(this));     
		});		
			
		jQuery(".form-type-checkbox label.option").click(
		  function() {
			var el = jQuery(this).attr("for");  
			el = jQuery("#"+el).parent();
			changeCheck(jQuery(el));    
		  }
		);	
		
		function changeCheck(el)
		{
			 var el = el,
				input = el.find("input").eq(0);
			 if(!input.attr("checked")) {	
				el.addClass("box_checked");				
				input.attr("checked", true)
			} else {
				el.removeClass("box_checked");
				input.attr("checked", false)
			}
			 return true;
		}		
		
		/*------------------change style for radio--------------------------*/			
  		//$('.form-type-radio input#edit-field-recipe-status-und-0').wrap('<span class="my_Radio" />');			
		jQuery(".form-type-radio input").each(
		function() {     
			 changeRadioStart(jQuery(this));     
		}); 
		function changeRadio(el){
			var el = el,
			input = el.find("input").eq(0);
			var nm=input.attr("name");		
			jQuery(".my_Radio input").each(	
				function() {     
					if(jQuery(this).attr("name")==nm){
					jQuery(this).parent().removeClass("radioChecked");
				}	   
			});						
			if(el.attr("class").indexOf("my_RadioDisabled")==-1){	
				el.addClass("radioChecked");
				input.attr("checked", true);
			}	
			return true;
		}
		function changeVisualRadio(input){
			var wrapInput = input.parent();
			var nm=input.attr("name");		
			jQuery(".my_Radio input").each(	
			function() {     
				if(jQuery(this).attr("name")==nm)
				{
					jQuery(this).parent().removeClass("radioChecked");
				}   
			});
			if(input.attr("checked")) 
			{
				wrapInput.addClass("radioChecked");
			}
		}
		function changeRadioStart(el){
			try
			{
			var el = el,
				radioName = el.attr("name"),
				radioId = el.attr("id"),
				radioChecked = el.attr("checked"),
				radioDisabled = el.attr("disabled"),
				radioTab = el.attr("tabindex"),
				radioValue = el.attr("value");
				if(radioChecked)
					el.after("<span class='my_Radio radioChecked'>"+
						"<input type='radio'"+
						"name='"+radioName+"'"+
						"id='"+radioId+"'"+
						"checked='"+radioChecked+"'"+
						"tabindex='"+radioTab+"'"+
						"value='"+radioValue+"' /></span>");
				else
					el.after("<span class='my_Radio'>"+
						"<input type='radio'"+
						"name='"+radioName+"'"+
						"id='"+radioId+"'"+
						"tabindex='"+radioTab+"'"+
						"value='"+radioValue+"' /></span>");	
				if(radioDisabled)
				{
					el.next().addClass("my_RadioDisabled");
					el.next().find("input").eq(0).attr("disabled","disabled");
				}		
					el.next().bind("mousedown", function(e) { changeRadio(jQuery(this)) });
					if(jQuery.browser.msie)	el.next().find("input").eq(0).bind("click", function(e) { changeVisualRadio(jQuery(this)) });	
					else el.next().find("input").eq(0).bind("change", function(e) { changeVisualRadio(jQuery(this)) });
					el.remove();
				}
				catch(e){
				}
				return true;
		}		
		
		
		/*------------------change style for select--------------------------*/	
		var params = {
			changedEl: "select",
			visRows: 10,
			scrollArrows: true
		}
		mySelect(params);
		/*-------------------styles for font for tabs---------------------------------*/
		function font_change_function() {
			//var tab_width2 = $('#block-quicktabs-components .item-list ul li').width();
			//$('#block-quicktabs-components .item-list ul li').css('line-height',tab_width2+"px");
			
			var tab_width = $('#block-quicktabs-components .item-list ul li a').width();
			//$('#block-quicktabs-components .item-list ul li').css('font-size',tab_width+"px");
			
			var font_size = tab_width/5.2;
			$('#block-quicktabs-components .item-list ul li a').css('font-size',font_size+'px');
			var line_height = font_size+4;
			$('#block-quicktabs-components .item-list ul li a').css('line-height',line_height + 'px');		
			
			var tab_width_n = $('#quicktabs-container-components').width();
			$('#edit-submit-components').attr('width',tab_width_n+"px");
			
			var font_size_n = tab_width_n/21.5;
			if (tab_width_n/21.5>=6.5) {
				$('input#edit-submit-components').css('font-size',font_size_n+'px');
			}
			/*if (+tab_width<79 && +tab_width>65) {
				$('#block-quicktabs-components .item-list ul li a').css('font-size','12px');
				$('#block-quicktabs-components .item-list ul li a').css('line-height','16px');
			}
			else if (+tab_width<=65 && +tab_width>55){
				$('#block-quicktabs-components .item-list ul li a').css('font-size','10px');
				$('#block-quicktabs-components .item-list ul li a').css('line-height','14px');
			}
			else if (+tab_width<=55 && +tab_width>50){
				$('#block-quicktabs-components .item-list ul li a').css('font-size','9px');
				$('#block-quicktabs-components .item-list ul li a').css('line-height','13px');
			}
			else if (+tab_width<=50){
				$('#block-quicktabs-components .item-list ul li a').css('font-size','8px');
				$('#block-quicktabs-components .item-list ul li a').css('line-height','12px');
			}
			else {
				$('#block-quicktabs-components .item-list ul li a').css('font-size','14px');	
				$('#block-quicktabs-components .item-list ul li a').css('line-height','18px');			
			}*/
		}
		$(window).resize(function() {
			font_change_function();						  
		});
		font_change_function();
		/*----------------*/
		$('.view-conents-ompfor-shopping-list .item-draggable-wrapper').live("hover", function(){
			var position = $(this).position();
			var height= $(this).outerHeight()-15;
			$(this).find('.item-additional-ops').css('top',position.top+height);
		});
		/*$('.view-id-kitchen table tr td:first-child div.my_td').each(function(){
			var my_td_height = $(this).height();
			$(this).children('.my_cell').css('height',my_td_height+'px');		
		});*/
		/*-------------------change style for upload form----------------------------------*/
  		/*jQuery("input#edit-field-user-photo-und-0-upload").wrap('<span class="container_for_upload" />');
		jQuery("input#edit-field-user-photo-und-0-upload").after('<div class="upload_area"><div class="upload_but">Browse</div><div class="input_area" id="image_upload_area"></div></div>');
		jQuery("input#edit-field-user-photo-und-0-upload").change(
			function() {
				jQuery("#image_upload_area").text(jQuery("input#edit-field-user-photo-und-0-upload").val());
			}
		);*/
		/*---------------------------------------------------------------------*/		
		$("#user-register-form input:text").parent().find('.description').each(function(index) {
			value_attr = $(this).text();					
			$(this).parent().find('input').attr("placeholder", value_attr);
		});
    
    $("#user-login-form input:text").parent().find('.description').each(function(index) {
			value_attr = $(this).text();					
			$(this).parent().find('input').attr("placeholder", value_attr);
		});
    
    /*$("#user-login input:text").parent().find('.description').each(function(index) {
			value_attr = $(this).text();					
			$(this).parent().find('input').attr("placeholder", value_attr);
		});*/

		$("input#edit-mail").attr("placeholder", "E-mail Address");
		$(".form-item-pass-pass1 label").html("Enter Password");
		$(".form-item-pass-pass2 label").html("Confirm Password");
    
    $("#views-exposed-form-components-block-4 input:text").attr("placeholder", "Enter A Search Term");
//    $("#views-exposed-form-components-for-shopping-list-block-1 input:text").css("color","#E9624E").attr("placeholder", "Search (example Hamburger)");	
    $(".view-recipes input:text").attr("placeholder", "Search XOXO Recipes");
    $("#recipe-node-form .form-item-title input").attr("placeholder", "Type Your Recipe Title Here");
    $("#recipe-node-form .field-name-field-recipe-subtitle input").attr("placeholder", "A simplifield family-style version of Louisiana's most famous dish...");
        
		
		jQuery("#user-register-form input:password").each(function(index) {
			if ($(this).val() == "") {
				$(this).parent().find('label').css("display","inline");
			}
		});	
		
		$("#user-register-form input:text").keyup(function () { 			
			if ($('#user-register-form input:password').val() != "") {
				$("#user-register-form div.form-type-password label").css("display","none");
			}
		});
		
		$("#user-register-form input:password").parent().find('label').focus(function () { 
		  $(this).css("display","none");
		});	
		
		$("#user-register-form input:password").focus(function () { 
		 $(this).parent().find('label').css("display","none");
		});	
		$("#user-register-form input:password").focusout(function() {
			if ($(this).val() == "") {
				$(this).parent().find('label').css("display","inline");
			}
		});	
		
		
		
  }
}}) (jQuery);
