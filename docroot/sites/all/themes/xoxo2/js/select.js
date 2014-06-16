function mySelect(params) {
							
	jQuery(params.changedEl).each(
	function(num)
	{
	var chEl = jQuery(this),
		chElWid = chEl.outerWidth(), // ширина селекта
		chElClass = chEl.attr("class"), // класс селекта
		chElId = chEl.attr("id"), // id
		chElName = chEl.attr("name"), // имя
		defaultVal = chEl.val(), // начальное значение
		activeOpt = chEl.find("option[value='"+defaultVal+"']").eq(0),
		defaultText = activeOpt.text(), // начальный текст
		disabledSel = chEl.attr("disabled"), // заблокирован ли селект
		scrollArrows = params.scrollArrows,
		chElOnChange = chEl.attr("onchange"),
		chElTab = chEl.attr("tabindex"),
		chElMultiple = chEl.attr("multiple");
		
		if(!chElId || chElMultiple)	return false; // не стилизируем селект если не задан id
		
		classDisSelectText = disabledSel ? 'classDisSelectLabel' : '';
		classDisSelect = disabledSel ? 'classDisSelect' : '';

/*		if(!disabledSel)
		{
			classDisSelectText = "", // для отслеживания клика по задизайбленному селекту
			classDisSelect=""; // для оформления задизейбленного селекта
		}
		else
		{
			classDisSelectText = "classDisSelectLabel";
			classDisSelect="classDisSelect";
		}*/
		
		/*if(scrollArrows)
		{
			classDisSelect+=" selectScrollArrows";
		}*/
			
		activeOpt.addClass("selectActive");  // активному оптиону сразу добавляем класс для подсветки
	
	var optionStr = chEl.html(), // список оптионов

		
	/* 
		делаем замену тегов option на span, полностью сохраняя начальную конструкцию
	*/
	
	spanStr = optionStr.replace(/option/ig,"span").replace(/value=/ig,"val="); // value меняем на val, т.к. jquery отказывается воспринимать value у span
	
	/* 
		для IE проставляем кавычки для значений, т.к. html() возращает код без кавычек
		что произошла корректная обработка value должно быть последний атрибутом option,
		например <option class="country" id="ukraine" value="/ukrane/">Украина</option>
	*/
	if(jQuery.browser.msie && parseInt(jQuery.browser.version) < 9)
	{
		var pattern = /(val=)(.*?)(>)/g;
		spanStr = spanStr.replace(pattern, "$1'$2'$3");
	}

	
	/* каркас стильного селекта	*/
	var selectFrame = '<div class="select '+chElClass+' '+classDisSelect+'"'+
					' id=selectFrame-'+chElId+
					' style="width:'+chElWid+'px"'+
					' tabindex="'+chElTab+'"'+
					'>'+
					'<div class="selectFrameRight"></div>'+
					'<div class="selectText">'+defaultText+'</div>'+
					'<div class="select-scroll-wrap" style="width:'+(chElWid-2)+'px"><div class="select-scroll-pane" id="select-scroll-'+chElId+'">'+
					spanStr+
					'</div></div>'+
					'<input type="hidden" id="'+chElId+'" name="'+chElName+'" value="'+defaultVal+'" />'+
					'</div>';
					
					
	/* удаляем обычный селект, на его место вставляем стильный */
	chEl.replaceWith(selectFrame);
	
	/* если был подцеплен onchange - цепляем его полю */
	if(chElOnChange) jQuery("#"+chElId).bind('change',chElOnChange);

	
	/*
		устаналиваем высоту выпадающих списков основываясь на числе видимых позиций и высоты одной позиции
		при чем только тем, у которых число оптионов больше числа заданного числа видимых
	*/
	var newSel = jQuery("#selectFrame-" + chElId),
		arrSpan = newSel.find("span"),
		defaultHeight;
		
		if(!arrSpan.eq(0).text())
		{
			defaultHeight = arrSpan.eq(1).innerHeight();
			arrSpan.eq(0).css("height", arrSpan.eq(1).height());
		} 
		else
		{
			defaultHeight = arrSpan.eq(0).innerHeight();
		}
		
	
	if(arrSpan.length>params.visRows)
	{
		newSel.find(".select-scroll-wrap").eq(0)
			.css({height: defaultHeight*params.visRows+"px", display : "none", visibility: "visible" })
			.children(".select-scroll-pane").css("height",defaultHeight*params.visRows+"px");
	}
	else
	{
		newSel.find(".select-scroll-wrap").eq(0)
			.css({display : "none", visibility: "visible" });
	}
	
	/* вставляем в оптионы дополнительные теги */
	
	var arrAddTags = jQuery("#select-scroll-"+chElId).find("span[addTags]"),
		lenAddTags = arrAddTags.length;
		
		for(i=0;i<lenAddTags;i++) arrAddTags.eq(i)
										.append(arrAddTags.eq(i).attr("addTags"))
										.removeAttr("addTags");
										
	selectEvents();
	
	});

/* ---------------------------------------
	привязка событий селектам
------------------------------------------
*/
function selectEvents() {
jQuery("html").unbind("click");

jQuery("html").click(
	function(e)
	{

		var clicked = jQuery(e.target),
			clickedId = clicked.attr("id"),
			clickedClass = clicked.attr("class");
			
		/* если кликнули по самому селекту (текст) */
		if((clickedClass.indexOf("selectText")!=-1 || clickedClass.indexOf("selectFrameRight")!=-1) && clicked.parent().attr("class").indexOf("classDisSelect")==-1)
		{
			var selectWrap = clicked.parent().find(".select-scroll-wrap").eq(0);
			
			/* если выпадающее меню скрыто - показываем */
			selectShowList(selectWrap);
		}
		/* если кликнули по самому селекту (контейнер) */
		//else if(clickedClass.indexOf("select")!=-1 && clickedClass.indexOf("classDisSelect")==-1 && clicked.is("div"))
//		{
//	
//			var selectWrap = clicked.find(".select-scroll-wrap").eq(0);
//			
//			/* если выпадающее меню скрыто - показываем */
//			selectShowList(selectWrap);
//	
//		}
//		
		/* если выбрали позицию в списке */
		else if(clicked.is(".select-scroll-wrap span") && clickedClass.indexOf("selectActive")==-1)
		{
			var clickedVal;
			(clicked.attr("val") == undefined) ? clickedVal=clicked.text() : clickedVal=clicked.attr("val");
			clicked
				.parents(".select-scroll-wrap").find(".selectActive").eq(0).removeClass("selectActive")
				.end().parents(".select-scroll-wrap")
				.next().val(clickedVal)
				.end().prev().text(clicked.text())
				.end().css("display","none")
				.parent(".select").removeClass("selectOpen");
			clicked.addClass("selectActive");
			clicked.parents(".select-scroll-wrap").find(".selectOptHover").removeClass("selectOptHover");
			if(clickedClass.indexOf("selectActive")==-1) {
				clicked
					.parents(".select")
					.find(".select-scroll-wrap")
					.eq(0)
					.next("input")
					.change(); // чтобы срабатывал onchange
			}
		}
		
		else if(clicked.parents(".select-scroll-wrap").is("div"))
		{
			return;
		}
		
		/*
			скрываем раскрытые списки, если кликнули вне списка
		*/
		else
		{
			jQuery(".select-scroll-wrap")
				.css("display","none")
				.parent(".select").removeClass("selectOpen");
		}
		

		
	});

jQuery(".select").unbind("keydown"); /* чтобы не было двойного срабатывания события */

jQuery(".select").keydown(
function(event)
{
	
	/*
		если селект задизайблин, с не го работает только таб
	*/
	var key, keyChar;
		
	if(window.event) key=window.event.keyCode;
	else if (event) key=event.which;
	
	if(key==null || key==0 || key==9) return true;
	
	if(jQuery(this).attr("class").indexOf("classDisSelect")!=-1) return false;
		
	/*
		если нажали стрелку вниз
	*/
	if(key==40)
	{
		var selectOptHover = jQuery(this).find(".selectOptHover").eq(0);
		if(!selectOptHover.is("span")) var selectActive = jQuery(this).find(".selectActive").eq(0);
		else var selectActive = selectOptHover;
		var selectActiveNext = selectActive.next();
			
		if(selectActiveNext.is("span"))
		{
			jQuery(this)
				.find(".selectText").eq(0).text(selectActiveNext.text());
			selectActive.removeClass("selectOptHover");
			selectActiveNext.addClass("selectOptHover");
			
			jQuery(this).find("input").eq(0).val(selectActiveNext.attr("val"));
					
			/* прокручиваем к текущему оптиону */
			selectScrollToCurent(jQuery(this).find(".select-scroll-wrap").eq(0));
			
			return false;
		}
		else return false;
	}
	
	/*
		если нажали стрелку вверх
	*/
	if(key==38)
	{
		var selectOptHover = jQuery(this).find(".selectOptHover").eq(0);
		if(!selectOptHover.is("span")) var selectActive = jQuery(this).find(".selectActive").eq(0);
		else var selectActive = selectOptHover;
		selectActivePrev = selectActive.prev();
			
		if(selectActivePrev.is("span"))
		{
			jQuery(this)
				.find(".selectText").eq(0).text(selectActivePrev.text());
			selectActive.removeClass("selectOptHover");
			selectActivePrev.addClass("selectOptHover");
			
			jQuery(this).find("input").eq(0).val(selectActivePrev.attr("val"));
			
			/* прокручиваем к текущему оптиону */
			selectScrollToCurent(jQuery(this).find(".select-scroll-wrap").eq(0));
			
			return false;
		}
		else return false;
	}
	
	/*
		если нажали esc
	*/
	if(key==27)
	{
		var selectActiveText = jQuery(this).find(".selectActive").eq(0).text();
		jQuery(this)
			.removeClass("selectOpen")
			.find(".select-scroll-wrap").eq(0).css("display","none")
			.end().find(".selectOptHover").eq(0).removeClass("selectOptHover");
		jQuery(this).find(".selectText").eq(0).text(selectActiveText);

	}
	
	/*
		если нажали enter
	*/
	if(key==13)
	{
		
		var selectHover = jQuery(this).find(".selectOptHover").eq(0);
		if(selectHover.is("span"))
		{
			jQuery(this).find(".selectActive").removeClass("selectActive");
			selectHover.addClass("selectActive");
		}
		else var selectHoverVal = jQuery(this).find(".selectActive").attr("val");
		
		jQuery(this)
			.removeClass("selectOpen")
			.find(".select-scroll-wrap").eq(0).css("display","none")
			.end().find(".selectOptHover").eq(0).removeClass("selectOptHover");
		jQuery(this).find("input").eq(0).change();
	}
	
	/*
		если нажали пробел и это опера - раскрывем список
	*/
	if(key==32 && jQuery.browser.opera)
	{
		var selectWrap = jQuery(this).find(".select-scroll-wrap").eq(0);
		
		/* ракрываем список */
		selectShowList(selectWrap);
	}
		
	if(jQuery.browser.opera) return false; /* специально для опера, чтоб при нажатиии на клавиши не прокручивалось окно браузера */

});

/*
	функция отбора по нажатым символам (от Alexey Choporov)
	отбор идет пока пауза между нажатиями сиволов не будет больше 0.5 сек
	keypress нужен для отлова символа нажатой клавиш
*/
var arr = [];
jQuery(".select").keypress(function(event)
{
	var key, keyChar;
		
	if(window.event) key=window.event.keyCode;
	else if (event) key=event.which;
	
	if(key==null || key==0 || key==9) return true;
	
	if(jQuery(this).attr("class").indexOf("classDisSelect")!=-1) return false;
	
	var o = this;
	arr.push(event);
	clearTimeout(jQuery.data(this, 'timer'));
	var wait = setTimeout(function() { handlingEvent() }, 500);
	jQuery(this).data('timer', wait);
	function handlingEvent()
	{
		var charKey = [];
		for (var iK in arr)
		{
			if(window.event)charKey[iK]=arr[iK].keyCode;
			else if(arr[iK])charKey[iK]=arr[iK].which;
			charKey[iK]=String.fromCharCode(charKey[iK]).toUpperCase();
		}
		var arrOption=jQuery(o).find("span"),colArrOption=arrOption.length,i,letter;
		for(i=0;i<colArrOption;i++)
		{
			var match = true;
			for (var iter in arr)
			{
				letter=arrOption.eq(i).text().charAt(iter).toUpperCase();
				if (letter!=charKey[iter])
				{
					match=false;
				}
			}
			if(match)
			{
				jQuery(o).find(".selectOptHover").removeClass("selectOptHover").end().find("span").eq(i).addClass("selectOptHover").end().end().find(".selectText").eq(0).text(arrOption.eq(i).text());
			
			/* прокручиваем к текущему оптиону */
			selectScrollToCurent(jQuery(o).find(".select-scroll-wrap").eq(0));
			arr = arr.splice;
			arr = [];
			break;
			return true;
			}
		}
		arr = arr.splice;
		arr = [];
	}
	if(jQuery.browser.opera && window.event.keyCode!=9) return false;
});
								
}
	
jQuery(".select").focus(
function()
{
	jQuery(this).addClass("selectFocus");
	
});

jQuery(".select").blur(
function()
{
	jQuery(this).removeClass("selectFocus");
});

jQuery(".select").hover(
function()
{
	jQuery(this).addClass("selectFocus");
},
function()
{
	jQuery(this).removeClass("selectFocus");
});

}

function mySelectRefresh(params)
{
	/*
		устаналиваем высоту выпадающих списков основываясь на числе видимых позиций и высоты одной позиции
		при чем только тем, у которых число оптионов больше числа заданного числа видимых
	*/

	var arrRefreshEl = params.refreshEl.split(","),
		lenArr = arrRefreshEl.length,
		i;
	
	for(i=0;i<lenArr;i++)
	{
		var refreshScroll = jQuery(arrRefreshEl[i]).parents(".select").find(".select-scroll-wrap").eq(0);
		refreshScroll.find(".select-scroll-pane").jScrollPaneRemoveSelect();
		refreshScroll.css({visibility: "hidden", display : "block"});
	
		var	arrSpan = refreshScroll.find("span"),
			defaultHeight = arrSpan.eq(0).outerHeight();
		
	
		if(arrSpan.length>params.visRows)
		{
			refreshScroll
				.css({height: defaultHeight*params.visRows+"px", display : "none", visibility: "visible" })
				.children(".select-scroll-pane").css("height",defaultHeight*params.visRows+"px");
		}
		else
		{
			refreshScroll
				.css({display : "none", visibility: "visible" });
		}
	}
	
}
/*
	фукция раскрытия/скрытия списка 
*/
function selectShowList(selectWrap)
{
	var selectMain = selectWrap.parent(".select");
	
	/* если выпадающее меню скрыто - показываем */
	if(selectWrap.css("display")=="none")
	{
		jQuery(".select-scroll-wrap").css("display","none");
		
		selectMain.addClass("selectOpen");
		selectWrap.css("display","block");
		//var selectArrows = false;
		//if(selectMain.attr("class").indexOf("selectScrollArrows")!=-1) selectArrows=true;
		//if(!selectWrap.find(".jScrollPaneContainer").eq(0).is("div"))
		//{
		//	selectWrap.find("div").eq(0).jScrollPaneSelect({showArrows:selectArrows});
		//}
				
		/* прокручиваем к текущему оптиону */
	selectScrollToCurent(selectWrap);
	}
	else
	{
		selectWrap.css("display","none");
		selectMain.removeClass("selectOpen");
	}
}


/*
	функция прокрутки к текущему элементу
*/
function selectScrollToCurent(selectWrap)
{
	var selectScrollEl = null;
	if(selectWrap.find(".selectOptHover").eq(0).is("span")) selectScrollEl = selectWrap.find(".selectOptHover").eq(0);
	else if(selectWrap.find(".selectActive").eq(0).is("span")) selectScrollEl = selectWrap.find(".selectActive").eq(0);

	if(selectWrap.find(".jScrollPaneTrack").eq(0).is("div") && selectScrollEl)
	{
		
		var posCurrentOpt = selectScrollEl.position(),
			idScrollWrap = selectWrap.find(".select-scroll-pane").eq(0).attr("id");

		jQuery("#"+idScrollWrap)[0].scrollTo(posCurrentOpt.top);	
	
	}	
}
