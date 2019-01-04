/*!
  Getting started js for getting start html animation
 */
     var timeout=350;
	 var toopacity=0.96;
	 var patt=/^step\d/g;

    function replace_icon(data)
	 {
		 if (data.indexOf("{")>=0)
		 {
			 icon_des=data.substring(data.indexOf("{"),data.indexOf("}")+1);
			 data=data.replace(icon_des,"<img src=\""+icon_des.substring(1,icon_des.indexOf("}"))+".png\" align=\"absmiddle\"></img>");
			 return data;
		 }
		 else
		 {
			 return data;
	     }
		 
		
		 
	 }
	 
     function getWebdata(args)
	 {
		 if (args=="gettingstarted")
		 {
			 var data='<font size="+3" color="#7c7c7c">'+g_dataArray[langeBaseNum+0]+'</font>';
		     return  data;
		 }			 
		 
		 if (args=="step1")
		 {
			 var step_content_map={
				 "step_icon_text":'<font size="2" color="#515251">'+replace_icon(g_dataArray[langeBaseNum+1])+'</font>',
			 }
			 return step_content_map;
		 }
		 if (args=="step2")
		 {
			 var step_content_map={
				 "step_icon_text":'<font size="2" color="#515251">'+replace_icon(g_dataArray[langeBaseNum+4])+'</font>',
			 }
			 return step_content_map;
		 }
		 if (args=="step3")
		 {
			 
			 var step_content_map={
				 "step_icon_text":'<font size="2" color="#515251">'+replace_icon(g_dataArray[langeBaseNum+7])+'</font>',
			 }
			 return step_content_map;
		 }
		 
	 }
	 
     function update_dis_content(step)
	 {
		 //fade out the dis_content
	     $("div.dis_content").animate({opacity: 0.0},0);
		 $("div.close").animate({opacity: 0.0},0);
		 
	 }
	 
	 function update_step_background(object,status)
	 {
		 step=$(object).attr('id');
		 if ((step.indexOf("step")==0)&& (step.indexOf("_icon")<0))
		 {
			 $(object).css('cursor',"pointer");
			 $(object).css('background',getWebdata("mouseEvent")[status]);
		 }
		 if (step.indexOf("close")==0)
		 {
			 $(object).css('cursor',"pointer");
		 }
	 }
	 

	 
     $(document).ready(function(){
		 
		                    //initial the first the page 
							
						    //$("#dis_content_child").corner("round 100	px").parent().css('padding', '100px').corner("round 100px");
							$("#dis_content").corner("round 10px").parent().css('padding', '2px').corner("round 10px");
						   $("div.dis_content").animate({opacity: 0.0},0);
			               $("div.close").animate({opacity: 0.0},0);
						   $("#title").html(getWebdata("gettingstarted"));
						   $("#step1_icon_text").html(getWebdata("step1")["step_icon_text"]);
						   $("#step2_icon_text").html(getWebdata("step2")["step_icon_text"]);
						   $("#step3_icon_text").html(getWebdata("step3")["step_icon_text"]);							
								
     });
     