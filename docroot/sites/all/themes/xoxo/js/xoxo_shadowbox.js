// JavaScript Document
(function($){
 $(document).ready(function(){
							
							
		$(".video_icon").one("click", function(){	
												
		  $('#sb-nav a').each(function(index) {
			  var text = $("#sb-nav-close").attr("title");
			  $("#sb-nav-close").text(text);
		  });
		  
			$("#sb-title-inner").after('<a id="sb-nav-close-top" onclick="Shadowbox.close()" title="Close"></a>');	
		});		
		
		
	}); 
})(jQuery);
