(function ($) {
    Drupal.behaviors.xoxoPopup = {
	attach: function (context, settings) {
	    $('a.shadowbox').click(function(event) {
		href = $(this).attr('href');
		ahref = href.split('/');
		var nid = ahref[2];
		if (ahref[1] == 'node' && ahref[2].search(/^-?[0-9]+$/) == 0) {
		    path = '/xoxo-popup/' + ahref[2];
		    $.get(path, function(data) {
			Shadowbox.open({
			    content: data,
			    player: 'html',
			    width: 670,
			    height: 450,
			    options: {
				modal: true,
				onClose: function(element) {
				    $('#sb-wrapper #sb-nav a.flag').remove();
				    $('#sb-wrapper #sb-nav span.flag-wrapper').remove();
				},
				onFinish: function(element) {
				    var f = function(){
					var popupRealHeight = 0;
					$('#sb-wrapper #sb-nav a.flag').remove();
					$('#sb-wrapper #sb-nav span.flag-wrapper').remove();
					flag = $(':not(#sb-wrapper) .flag-added-to-my-kitchen-' + nid).clone(true);
					flag.addClass('sb-nav-flag').appendTo($('#sb-nav'));
          var flag_link = $(flag).find('a.flag');
					if(flag.hasClass('flag-wrapper')) {
              if(flag_link.hasClass('unflag-action')) {
                title = Drupal.t('Remove this recipe from your collection.')
              }
              else {
                title = Drupal.t('Add this recipe to your collection to customize it.');
              }
					}
					else {
					    title = '';
					}
					if($(event.currentTarget).hasClass('with-close')) {
					    $('#sb-nav-close').text('Close');
					}
					else{
					    $('#sb-nav-close').remove();
					}
					$("#sb-title-inner").css('margin-top', 0).text(title);
					if(!$('#sb-nav-close-top').length) {
					    $("#sb-title-inner").after('<a id="sb-nav-close-top" onclick="Shadowbox.close()" title="Close"></a>');
					}
					// var winHeight = document.body.offsetHeight;
					// var popupRealHeightcurrent = $('#sb-wrapper').innerHeight();
					// popupRealHeight = popupRealHeightcurrent + 30;
					// if (popupRealHeight < winHeight){
					//     $('#sb-body #sb-body-inner #sb-player .field-name-body').css('height', popupRealHeight + 'px');
					// }
					// else{
					//     var modulH =  popupRealHeight - winHeight;
					//     $('#sb-body #sb-body-inner #sb-player .field-name-body').css('height', winHeight + 'px');
					// }
				    };
				    f();
				}
			    }
			});
		    });
		    event.preventDefault();
		}
	    });
	}};
} (jQuery));
