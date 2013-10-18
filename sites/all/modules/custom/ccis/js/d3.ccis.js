(function($) {
Drupal.behaviors.ccis = {
  attach: function(d_context, settings) {
  // CUSTOM CODING START

	// Groups of parameters available including the colors, names and the icons
	var temperature = [
	    ["avg_temp", "#FFA500", "TG", "Average mean temperature", "symbol_legende_tg.png"],
	    ["avg_min_temp", "#008000", "TN", "Average min temperature", "symbol_legende_tn.png"],
	    ["avg_max_temp", "#FF0000", "TX", "Average max temperature", "symbol_legende_tx.png"]
	];
	var precipitation = [
	    ["avg_prec", "#2c4563", "RR", "Average precipitation amount", "symbol_legende_rr.png"]
	];
	var pressure = [
	    ["avg_press", "#33CCFF", "PP", "Average sea level pressure", "symbol_legende_pp.png"]
	];
	
	// ***************************************
	// ********** DIAGRAM 1 - START **********
	// ***************************************
	function diagram1() {
		// *** Variables - START ***
		var blockID = settings.ccis.stations[0].selector;
		var block = "_1";
		
		var margin = {top: 20, right: 10, bottom: 25, left: 105, left_single: 35};
		var widthDiv = $("#"+blockID).width();
		var legendWidth = 170;
		var tooltipWidth = 200;
		var width = widthDiv - margin.left - margin.right - legendWidth;
		var height = width/2;
		var heightPrintSelect = 50;
		var axis_sum = 3;
		var axis_selection;
		var svg;
		var temperatureHidden;
		var precipitationHidden;
		var pressureHidden;
	   	
	   	// Parameters parsed for the specific user
		var temperatureUsed = [];
		var precipitationUsed = [];
		var pressureUsed = [];
		
		// Parameters shown at the graph (max: 4)
		var temperatureShown = [];
		var precipitationShown = [];
		var pressureShown = [];
		
		var mouseX;
		var mouseY;
		var yAxisArray = [];
		var temperature_selection;
		var precipitation_selection;
		var pressure_selection;
		var legendCategoriesOpen = "Open categories";
		var legendCategoriesClose = "Close categories";
		var plus = "<img src='"+settings.basePath+"sites/all/modules/custom/ccis/images/d3/plus.png' width='7' height='7'>"
		var minus = "<img src='"+settings.basePath+"sites/all/modules/custom/ccis/images/d3/minus.png' width='7' height='7'>"
		// *** Variables - END ***

		// Parse the JSON with the data
		d3.json(settings.ccis.stations[0].path, function(json) {
			if (json.length===0) {
				$("#"+blockID).html("");
			} else {
				$("#"+blockID).html("");
	
				// Get parameters names
				var dataKeysArray = Object.keys(json[0]);
				
				// Create object with the parameters and the values
				var data = json.map(function(d) {
					var obj = {};
					//obj.date: d3.time.format("%Y-%m-%d %H:%M:%S").parse(d.date.slice(0,-3); // Datum & Zeit ohne Zeitzone
					obj.date = d3.time.format("%Y-%m-%d").parse(d.date.slice(0,-12)); // Nur Datum
					// i=2: The first two parameters are Station and Date
					for (var i=2; i<dataKeysArray.length; i++) {
						obj[dataKeysArray[i]] = parseFloat(d[dataKeysArray[i]]);
					}
					return obj;
	  
				});

				// Create an array per group with the parameters used, the colors, the legend keywords and the legend hover names
				for (var i=2; i<dataKeysArray.length; i++) {
					for (var k=0; k<temperature.length; k++) {
						if (dataKeysArray[i]===temperature[k][0]) {
							temperatureUsed.push([temperature[k][0], temperature[k][1], temperature[k][2], temperature[k][3], temperature[k][4]]);
						}
					}
					for (var k=0; k<precipitation.length; k++) {
						if (dataKeysArray[i]===precipitation[k][0]) {
							precipitationUsed.push([precipitation[k][0], precipitation[k][1], precipitation[k][2], precipitation[k][3], precipitation[k][4]]);
						}
					}
					for (var k=0; k<pressure.length; k++) {
						if (dataKeysArray[i]===pressure[k][0]) {
							pressureUsed.push([pressure[k][0], pressure[k][1], pressure[k][2], pressure[k][3], pressure[k][4]]);
						}
					} 
				}
				
				// Choose initial parameters to show
				temperatureShown.push(temperatureUsed[0], temperatureUsed[1]);
				precipitationShown.push(precipitationUsed[0]);
				//pressureShown.push(pressureUsed[0]);
	
				// Find the max and min values for the Y scales
				// Temperature values
				var minTempYArray = [];
				var maxTempYArray = [];
				for (var i=0; i<temperatureShown.length; i++) {
					minTempYArray.push(d3.min(data, function(d) { return Math.min(d[temperatureShown[i][0]]); }) );
					maxTempYArray.push(d3.max(data, function(d) { return Math.max(d[temperatureShown[i][0]]); }) );  
				}
				var minTempY = d3.min(minTempYArray);
				var maxTempY = d3.max(maxTempYArray);
				// Precipitation values
				var minPrecYArray = [];
				var maxPrecYArray = [];
				for (var i=0; i<precipitationShown.length; i++) {
					minPrecYArray.push(d3.min(data, function(d) { return Math.min(d[precipitationShown[i][0]]); }) );
					maxPrecYArray.push(d3.max(data, function(d) { return Math.max(d[precipitationShown[i][0]]); }) );  
				}
				var minPrecY = d3.min(minPrecYArray);
				var maxPrecY = d3.max(maxPrecYArray);
				// Pressure values
				var minPressYArray = [];
				var maxPressYArray = [];
				for (var i=0; i<pressureShown.length; i++) {
					minPressYArray.push(d3.min(data, function(d) { return Math.min(d[pressureShown[i][0]]); }) );
					maxPressYArray.push(d3.max(data, function(d) { return Math.max(d[pressureShown[i][0]]); }) );  
				}
				var minPressY = d3.min(minPressYArray);
				var maxPressY = d3.max(maxPressYArray);
				
				// Y Scales
				var yScaleTemp = d3.scale.linear()
					.domain([minTempY, maxTempY])
					.range([height, 0]);
				var yScalePrec = d3.scale.linear()
					.domain([minPrecY, maxPrecY])
					.range([height, 0]);
				var yScalePress = d3.scale.linear()
					.domain([minPressY, maxPressY])
					.range([height, 0]);
				
				// Which and how many Y-Axes we need
				function findAxis() {
					axis_selection = 0;
					yAxisArray = [];
					temperature_selection = false;
					if (temperatureShown.length>0) {
						temperature_selection=true;
						yAxisArray.push(["yAxisTemp", yScaleTemp, "Temperature"]);
						axis_selection=axis_selection+1;
					}
					precipitation_selection = false;
					if (precipitationShown.length>0) {
						precipitation_selection = true;
						yAxisArray.push(["yAxisPrec", yScalePrec, "Precipitation"]);
						axis_selection=axis_selection+1;
					}
					pressure_selection = false;
					if (pressureShown.length>0) {
						pressure_selection = true;
						yAxisArray.push(["yAxisPress", yScalePress, "Pressure"]);
						axis_selection=axis_selection+1;
					}
				}
				findAxis();
							
				// X Scale
				var xScale = d3.time.scale()
		  			.domain(d3.extent(data, function(d) { return d.date; }))
		  			.range([0, (width+(margin.left_single*axis_sum)-(margin.left_single*axis_selection))]);
	
				//Create SVG element
				function createSvg() {
					$("#"+blockID).prepend("<div id='d3_GraphDiv"+block+"' class='d3_GraphDivClass'></div>");
					svg = d3.select("#d3_GraphDiv"+block)
						.append("svg")
						.attr("id", "svg"+block)
						.attr("class", "d3_svgElement")
						.attr("width", (width + (margin.left_single)*axis_sum + margin.right))
						.attr("height", height + margin.top + margin.bottom)
						.append("g")
						.attr("transform", "translate(" + (margin.left-((margin.left_single*axis_sum)-(margin.left_single*axis_selection))) + "," + margin.top + ")");
				}
				createSvg();
			  
				// Create graphs
				function graphDraw(graphType, yscaleType, color) {
					
					var graphObj = {};
					
					graphObj[graphType] = d3.svg.line()
						.interpolate("linear")
						.x(function(d){return xScale(d.date)})
						.y(function(d){return yscaleType(d[graphType])});
	
					d3.select("#svg"+block)
						.append("path")
					  	.attr("id", "d3_path"+graphType+"ID"+block)
						.attr("d", graphObj[graphType](data))
						.attr("stroke", color)
						.attr("stroke-width", "2")
						.attr("fill", "none")
						.attr("transform", "translate(" + (margin.left-((margin.left_single*axis_sum)-(margin.left_single*axis_selection))) + "," + margin.top + ")");		  
				}
	
				for (var i=0; i<temperatureShown.length; i++) {
					graphDraw(temperatureShown[i][0], yScaleTemp, temperatureShown[i][1]);
				}
				for (var i=0; i<precipitationShown.length; i++) {
					graphDraw(precipitationShown[i][0], yScalePrec, precipitationShown[i][1]);
				}
				for (var i=0; i<pressureShown.length; i++) {
					graphDraw(pressureShown[i][0], yScalePress, pressureShown[i][1]);
				}
				
				// Draw Y Axis
				function yAxisDraw(axisType, scaleType, label, axisPosition) {
					var yAxisObj = {};
					var yAxisLabel;
					var yAxisLabelOffset;
					var yAxisTickFormat;
					var iconLink;
					var iconWidth;
					var iconHeight;
					if (axisType==="yAxisTemp") {
						yAxisLabel = "&#8451;" // Celsius
						yAxisLabelOffset = -20;
						yAxisTickFormat = ".1f";
						iconLink = settings.basePath +"sites/all/modules/custom/ccis/images/d3/symbol_legende_thermometer.png";
						iconWidth = "7px";
						iconHeight = "21px";
					} else if (axisType==="yAxisPrec") {
						yAxisLabel = "mm"
						yAxisLabelOffset = -30;
						yAxisTickFormat = ".1f";
						iconLink = settings.basePath +"sites/all/modules/custom/ccis/images/d3/symbol_legende_drop.png";
						iconWidth = "11px";
						iconHeight = "17px";
					} else if (axisType==="yAxisPress") {
						yAxisLabel = "hPa"
						yAxisLabelOffset = -30;
						yAxisTickFormat = ".0f";
						iconLink = settings.basePath +"sites/all/modules/custom/ccis/images/d3/symbol_legende_pressure.png";
						iconWidth = "19px";
						iconHeight = "16px";
					}
								
					// Grid only for the first y axis
					if (axisPosition === 0) {
						var yGrid = -(width+(margin.left_single*axis_sum)-(margin.left_single*axis_selection));
						yAxisObj["grid"] = d3.svg.axis()
							.scale(scaleType)
							.orient("left")
							.tickSize(yGrid, 0, 0)
							.tickFormat("")
							.ticks(5);
						svg.append("g")
							.attr("class", "d3_yGrid")
							.attr("transform", "translate("+(axisPosition*(-margin.left_single))+",0)")
							.call(yAxisObj["grid"]);
					}
	
					yAxisObj[axisType] = d3.svg.axis()
						.scale(scaleType)
						.orient("left")
						.tickFormat(d3.format(yAxisTickFormat))
						.ticks(5);
					svg.append("g")
						.attr("id", axisType+"id"+block)
						.attr("class", "d3_yAxisClass")
						.style("font-size","10px")
						.attr("transform", "translate("+(axisPosition*(-margin.left_single))+",0)")
						.call(yAxisObj[axisType]);
					d3.select("#"+axisType+"id"+block)
						.append("text")
						.html(yAxisLabel)
						.attr("class", "d3_yAxisText")
						.style("font-size","12px")
						.attr("transform", "translate ("+yAxisLabelOffset+", 0)");
					
					d3.select("#"+axisType+"id"+block)
						.append("image")
						.attr("xlink:href", iconLink)
						.attr("width", iconWidth)
						.attr("height", iconHeight)
						.attr("transform", "translate (-20, "+(height+3)+")");
				}
				
				// Call the Y Axis draw function
				for (var i=0; i<yAxisArray.length; i++) {
					yAxisDraw(yAxisArray[i][0], yAxisArray[i][1], yAxisArray[i][2], i);
				}
				
				// Draw X Axis
				function xAxisDraw() {
					var xAxis = d3.svg.axis()
						.scale(xScale)
					  	.orient("bottom")
					  	.ticks(5);
					svg.append("g")
						.attr("class", "d3_xAxisLine")
						.style("font-size","10px")
						.attr("transform", "translate(0," + height + ")")
						.call(xAxis);
				}	
				xAxisDraw();
			  
				// Add CSS to the axes (Do not place it in the css file)
				function addCss() {	
					$(".d3_yGrid")
						.css("stroke", "#D1D1FF")
						.css("shape-rendering", "crispEdges");
					
					$(".d3_yAxisClass path, .d3_yAxisClass line, .d3_xAxisLine path, .d3_xAxisLine line")
						.css("fill", "none")
						.css("stroke", "#000")
						.css("shape-rendering", "crispEdges");
				}
				addCss();
	
				// Legend Tooltips
				function hoverLegend(topPosition, keyPlace, text) {			
					$("#d3_tooltipLegend"+keyPlace+block)
						.css("position", "absolute")
						.css("right", (legendWidth-3)+"px")
						.css("top", (topPosition+30)+"px")
						.css("width", "auto")
						.css("clear", "both")
						.css("float", "left")
						.css("background-color", "#fcce00")
						.css("border", "solid 1px #D1D1FF")
						.css("border-radius", "8px 8px 8px 8px")
						.css("-webkit-box-shadow", "4px 4px 10px rgba(0, 0, 0, 0.4)")
						.css("-moz-box-shadow", "4px 4px 10px rgba(0, 0, 0, 0.4)")
						.css("box-shadow", "4px 4px 10px rgba(0, 0, 0, 0.4)")
						.css("font-size","12px")
						.html(text);
				}
				function hoverLegendCategories(topPosition, text) {			
					$("#d3_tooltipLegendCategories"+block)
						.css("position", "absolute")
						.css("right", (legendWidth+5)+"px")
						.css("top", (topPosition+30)+"px")
						.css("width", "auto")
						.css("clear", "both")
						.css("float", "left")
						.css("background-color", "#fcce00")
						.css("border", "solid 1px #D1D1FF")
						.css("border-radius", "8px 8px 8px 8px")
						.css("-webkit-box-shadow", "4px 4px 10px rgba(0, 0, 0, 0.4)")
						.css("-moz-box-shadow", "4px 4px 10px rgba(0, 0, 0, 0.4)")
						.css("box-shadow", "4px 4px 10px rgba(0, 0, 0, 0.4)")
						.css("font-size","12px")
						.html(text);
				}
				
				// Add div for the legend
				$("#"+blockID).append("<div id='d3_legendDiv"+block+"' class='d3_legendClass'></div>");
				
				$("#d3_legendDiv"+block)
					.css("width", legendWidth-1)
					.css("height", height + margin.top + margin.bottom - heightPrintSelect);
					
				// Create DIVs for the keys
				// Temperature
				if (temperatureUsed.length>0) {
					$("#d3_legendDiv"+block).append("<div id='d3_iconLegendTemp"+block+"' class='d3_iconLegendTempClass'><img src='"+settings.basePath+"sites/all/modules/custom/ccis/images/d3/symbol_legende_thermometer.png' width='7' height='21'></div>");
					$("#d3_legendDiv"+block).append("<div id='d3_temperatureToggle"+block+"' class='d3_toggleClass'><b><span id='d3_tempMinus"+block+"' class='d3_minus'>"+plus+"</span> Temperature <span class='d3_unitLegend'>[&#8451;]</span></b></div>");
					$("#d3_temperatureToggle"+block).hover(function() {
						$(this).css("cursor","pointer");
						$("#"+blockID).append("<div id='d3_tooltipLegendCategories"+block+"'></div>"); 
						var topPosition = $("#d3_temperatureToggle"+block).position().top;
						var legendText;
						if (temperatureHidden===true) {
							legendText = legendCategoriesOpen;
						} else if (temperatureHidden===false) {
							legendText = legendCategoriesClose;
						}
						hoverLegendCategories(topPosition, legendText);
					}, function() {$("#d3_tooltipLegendCategories"+block).remove();});
					$("#d3_legendDiv"+block).append("<div id='d3_keysDivTemperature"+block+"'></div>");
					for (var i=0; i<temperatureUsed.length; i++) {
						function findTempChecked() {
							for (var k=0; k<temperatureShown.length; k++) {
								if (temperatureUsed[i][0]===temperatureShown[k][0]) {
									return "checked";
								}
							}
						}
						$("#d3_keysDivTemperature"+block).append("<div id='d3_keysTemperature"+i+block+"' class='d3_keys'></div>");
						$("#d3_keysTemperature"+i+block).append("<div id='d3_keysTemperatureTick"+i+block+"' class='d3_keysTick'><input id='d3_checkboxTemperature"+i+block+"' type='checkbox' value='"+i+"' "+findTempChecked()+"></div>");			
						$("#d3_keysTemperature"+i+block).append("<div id='d3_keysTemperatureBoxText"+i+block+"' class='d3_keysBoxText'></div>");
						$("#d3_keysTemperatureBoxText"+i+block).append("<div id='keysTemperatureText"+i+block+"' class='d3_keysText'></div>");
						$("#keysTemperatureText"+i+block).append(temperatureUsed[i][2]);
						$("#d3_keysTemperatureBoxText"+i+block).append("<div id='keysTemperatureIcon"+i+block+"' class='d3_keysIcon'><img src='"+settings.basePath+"sites/all/modules/custom/ccis/images/d3/"+temperatureUsed[i][4]+"' width='25' height='15'></div>");
						(function(i) {
					    	$("#d3_keysTemperatureBoxText"+i+block)
					    		.hover(function(){
			    					$(this).css("cursor","default"); 
			    					$("#"+blockID).append("<div id='d3_tooltipLegend"+i+block+"'></div>"); 
			    					var topPosition = $("#d3_keysTemperatureBoxText"+i+block).position().top; 
			    					hoverLegend(topPosition, i, temperatureUsed[i][3]);
					    		},
			    				function() {$("#d3_tooltipLegend"+i+block).remove();});
					    })(i);
					}		
				}
				// Precipitation
				if (precipitationUsed.length>0) {
					$("#d3_legendDiv"+block).append("<div id='d3_iconLegendPrec"+block+"' class='d3_iconLegendPrecClass'><img src='"+settings.basePath+"sites/all/modules/custom/ccis/images/d3/symbol_legende_drop.png' width='11' height='17'></div>");
					$("#d3_legendDiv"+block).append("<div id='d3_precipitationToggle"+block+"' class='d3_toggleClass'><b><span id='d3_precMinus"+block+"' class='d3_minus'>"+plus+"</span> Precipitation <span class='d3_unitLegend'>[mm]</span></b></div>");
					$("#d3_precipitationToggle"+block).hover(function() {
						$(this).css("cursor","pointer");
						$("#"+blockID).append("<div id='d3_tooltipLegendCategories"+block+"'></div>"); 
						var topPosition = $("#d3_precipitationToggle"+block).position().top;
						var legendText;
						if (precipitationHidden===true) {
							legendText = legendCategoriesOpen;
						} else if (precipitationHidden===false) {
							legendText = legendCategoriesClose;
						}
						hoverLegendCategories(topPosition, legendText);
					}, function() {$("#d3_tooltipLegendCategories"+block).remove();});
					$("#d3_legendDiv"+block).append("<div id='d3_keysDivPrecipitation"+block+"'></div>");
					for (var i=0; i<precipitationUsed.length; i++) {
						function findPrecChecked() {
							for (var k=0; k<precipitationShown.length; k++) {
								if (precipitationUsed[i][0]===precipitationShown[k][0]) {
									return "checked";
								}
							}
						}
						$("#d3_keysDivPrecipitation"+block).append("<div id='d3_keysPrecipitation"+i+block+"' class='d3_keys'></div>");
						$("#d3_keysPrecipitation"+i+block).append("<div id='keysPrecipitationTick"+i+block+"' class='d3_keysTick'><input id='d3_checkboxPrecipitation"+i+block+"' type='checkbox' value='"+i+"' "+findPrecChecked()+"></div>");
						$("#d3_keysPrecipitation"+i+block).append("<div id='d3_keysPrecipitationBoxText"+i+block+"' class='d3_keysBoxText'></div>")
						
						$("#d3_keysPrecipitationBoxText"+i+block).append("<div id='d3_keysPrecipitationText"+i+block+"' class='d3_keysText'></div>");
						$("#d3_keysPrecipitationText"+i+block).append(precipitationUsed[i][2]);
						$("#d3_keysPrecipitationBoxText"+i+block).append("<div id='d3_keysPrecipitationIcon"+i+block+"' class='d3_keysIcon'><img src='"+settings.basePath+"sites/all/modules/custom/ccis/images/d3/"+precipitationUsed[i][4]+"' width='25' height='15'></div>");
						(function(i) {
					    	$("#d3_keysPrecipitationBoxText"+i+block)
					    		.hover(function(){
			    					$(this).css("cursor","default"); 
			    					$("#"+blockID).append("<div id='d3_tooltipLegend"+i+block+"'></div>"); 
			    					var topPosition = $("#d3_keysPrecipitationBoxText"+i+block).position().top; 
			    					hoverLegend(topPosition, i, precipitationUsed[i][3]);
					    		},
			    				function() {$("#d3_tooltipLegend"+i+block).remove();});
					    })(i);
					}
				}
				// Pressure
				if (pressureUsed.length>0) {
					$("#d3_legendDiv"+block).append("<div id='d3_iconLegendPress"+block+"' class='d3_iconLegendPressClass'><img src='"+settings.basePath+"sites/all/modules/custom/ccis/images/d3/symbol_legende_pressure.png' width='19' height='16'></div>");
					$("#d3_legendDiv"+block).append("<div id='d3_pressureToggle"+block+"' class='d3_toggleClass'><b><span id='d3_pressMinus"+block+"' class='d3_minus'>"+plus+"</span> Pressure <span class='d3_unitLegend'>[hPa]</span></b></div>");
					$("#d3_pressureToggle"+block).hover(function() {
						$(this).css("cursor","pointer");
						$("#"+blockID).append("<div id='d3_tooltipLegendCategories"+block+"'></div>"); 
						var topPosition = $("#d3_pressureToggle"+block).position().top;
						var legendText;
						if (pressureHidden===true) {
							legendText = legendCategoriesOpen;
						} else if (pressureHidden===false) {
							legendText = legendCategoriesClose;
						}
						hoverLegendCategories(topPosition, legendText);
					}, function() {$("#d3_tooltipLegendCategories"+block).remove();});
					$("#d3_legendDiv"+block).append("<div id='d3_keysDivPressure"+block+"'></div>");
					for (var i=0; i<pressureUsed.length; i++) {
						function findPressChecked() {
							for (var k=0; k<pressureShown.length; k++) {
								if (pressureUsed[i][0]===pressureShown[k][0]) {
									return "checked";
								}
							}
						}
						$("#d3_keysDivPressure"+block).append("<div id='d3_keysPressure"+i+block+"' class='d3_keys'></div>");
						$("#d3_keysPressure"+i+block).append("<div id='d3_keysPressureTick"+i+block+"' class='d3_keysTick'><input id='d3_checkboxPressure"+i+block+"' type='checkbox' value='"+i+"' "+findPressChecked()+"></div>");
						$("#d3_keysPressure"+i+block).append("<div id='d3_keysPressureBoxText"+i+block+"' class='d3_keysBoxText'></div>");
						$("#d3_keysPressureBoxText"+i+block).append("<div id='d3_keysPressureText"+i+block+"' class='d3_keysText'></div>");
						$("#d3_keysPressureText"+i+block).append(pressureUsed[i][2]);
						$("#d3_keysPressureBoxText"+i+block).append("<div id='d3_keysPressureIcon"+i+block+"' class='d3_keysIcon'><img src='"+settings.basePath+"sites/all/modules/custom/ccis/images/d3/"+pressureUsed[i][4]+"' width='25' height='15'></div>");
						(function(i) {
					    	$("#d3_keysPressureBoxText"+i+block)
					    		.hover(function(){
			    					$(this).css("cursor","default"); 
			    					$("#"+blockID).append("<div id='d3_tooltipLegend"+i+block+"'></div>"); 
			    					var topPosition = $("#d3_keysPressureBoxText"+i+block).position().top; 
			    					hoverLegend(topPosition, i, pressureUsed[i][3]);
					    		},
			    				function() {$("#d3_tooltipLegend"+i+block).remove();});
					    })(i);
					}
				}
				
				// Maximum checkboxes checked: 4 / Minimum: 1
				var maxChecked = $("#"+blockID+" :checkbox:checked").length >= 4; 
				$("#"+blockID+" :checkbox").not(":checked").attr("disabled",maxChecked);
				var minChecked = $("#"+blockID+" :checkbox:checked").length <= 1;
				$("#"+blockID+" :checkbox:checked").attr("disabled",minChecked);
				
				// By default is the dropdown hidden
				for (var i=0; i<temperatureUsed.length; i++) {
					$("#d3_keysTemperature"+i+block).hide();
					if ($("#d3_checkboxTemperature"+i+block).is(":checked")) {
						$("#d3_keysTemperature"+i+block).show();
					}	
				}
				temperatureHidden=true;
				for (var i=0; i<precipitationUsed.length; i++) {
					$("#d3_keysPrecipitation"+i+block).hide();
					if ($("#d3_checkboxPrecipitation"+i+block).is(":checked")) {
						$("#d3_keysPrecipitation"+i+block).show();
					}	
				} 
				precipitationHidden=true;
				for (var i=0; i<pressureUsed.length; i++) {
					$("#d3_keysPressure"+i+block).hide();
					if ($("#d3_checkboxPressure"+i+block).is(":checked")) {
						$("#d3_keysPressure"+i+block).show();
					}	
				}
				pressureHidden=true;
				
				// Collapse	
				$("#d3_temperatureToggle"+block).click(function() {
					if (temperatureHidden===true) {
						$("#d3_tempMinus"+block).html(minus);
						for (var i=0; i<temperatureUsed.length; i++) {			
							$("#d3_keysTemperature"+i+block).show();
						}
						temperatureHidden=false;
						$("#d3_tooltipLegendCategories"+block).html(legendCategoriesClose);
					} else if (temperatureHidden===false) {
						$("#d3_tempMinus"+block).html(plus);
						for (var i=0; i<temperatureUsed.length; i++) {
							$("#d3_keysTemperature"+i+block).hide();
							if ($("#d3_checkboxTemperature"+i+block).is(":checked")) {
								$("#d3_keysTemperature"+i+block).show();
							}	
						}
						temperatureHidden=true;
						$("#d3_tooltipLegendCategories"+block).html(legendCategoriesOpen);
					}
				});
				$("#d3_precipitationToggle"+block).click(function() {
					if (precipitationHidden===true) {
						$("#d3_precMinus"+block).html(minus);
						for (var i=0; i<precipitationUsed.length; i++) {			
							$("#d3_keysPrecipitation"+i+block).show();
						}
						precipitationHidden=false;
						$("#d3_tooltipLegendCategories"+block).html(legendCategoriesClose);
					} else if (precipitationHidden===false) {
						$("#d3_precMinus"+block).html(plus);
						for (var i=0; i<precipitationUsed.length; i++) {
							$("#d3_keysPrecipitation"+i+block).hide();
							if ($("#d3_checkboxPrecipitation"+i+block).is(":checked")) {
								$("#d3_keysPrecipitation"+i+block).show();
							}	
						}
						precipitationHidden=true;
						$("#d3_tooltipLegendCategories"+block).html(legendCategoriesOpen);
					}
				});
				$("#d3_pressureToggle"+block).click(function() {
					if (pressureHidden===true) {
						$("#d3_pressMinus"+block).html(minus);
						for (var i=0; i<pressureUsed.length; i++) {			
							$("#d3_keysPressure"+i+block).show();
						}
						pressureHidden=false;
						$("#d3_tooltipLegendCategories"+block).html(legendCategoriesClose);
					} else if (pressureHidden===false) {
						$("#d3_pressMinus"+block).html(plus);
						for (var i=0; i<pressureUsed.length; i++) {
							$("#d3_keysPressure"+i+block).hide();
							if ($("#d3_checkboxPressure"+i+block).is(":checked")) {
								$("#d3_keysPressure"+i+block).show();
							}	
						}
						pressureHidden=true;
						$("#d3_tooltipLegendCategories"+block).html(legendCategoriesOpen);
					}
				});
				
				// Print preview button
				$("#"+blockID).append("<div id='printSelectWrapper"+block+"' class='printSelectWrapperClass'></div>");
				$("#printSelectWrapper"+block)
					.css("width", legendWidth)
					.css("height", heightPrintSelect);
				$("#printSelectWrapper"+block).append("<div id='d3_SelectDiagramsText"+block+"' class='d3_SelectDiagramsTextClass'><i>Select up to 4 indices</i></div>");
				$("#printSelectWrapper"+block).append("<div id='d3_printPreviewId"+block+"' class='d3_printPreviewClass'><img src='"+settings.basePath+"sites/all/modules/custom/ccis/images/d3/symbol_printer.png' width='16' height='16'><b><span style='font-size:14px;'>&nbsp;Print Preview</span></b></div>");
				$("#d3_printPreviewId"+block).hover(function() {
					$(this).css("cursor","pointer");
				});
				$("#d3_printPreviewId"+block).click(function() {
					printPreview();
				});
				
				// *** Redraw the Graph - START ***
				function redrawGraph() {
	
					if (document.getElementById("d3_keysDivTemperature"+block)) {
						var findIDsTemperature = $("#d3_keysDivTemperature"+block+" input:checkbox:checked").map(function(){		        
							return $(this).val();      
						});
						var findTicksArrayTemperature = findIDsTemperature.get();
					}
					if (document.getElementById("d3_keysDivPrecipitation"+block)) {
						var findIDsPrecipitation = $("#d3_keysDivPrecipitation"+block+" input:checkbox:checked").map(function(){		        
							return $(this).val();      
						});
						var findTicksArrayPrecipitation = findIDsPrecipitation.get();
					}
					if (document.getElementById("d3_keysDivPressure"+block)) {
						var findIDsPressure = $("#d3_keysDivPressure"+block+" input:checkbox:checked").map(function(){		        
							return $(this).val();      
						});
						var findTicksArrayPressure = findIDsPressure.get();
					}
	
					// Which parameters are selected
					temperatureShown = [];
					var temperatureShownSingle;
					for (var i=0; i<findTicksArrayTemperature.length; i++) {
						temperatureShownSingle = temperatureUsed[parseFloat(findTicksArrayTemperature[i])];
						temperatureShown.push(temperatureShownSingle);			
					}
					precipitationShown = [];
					var precipitationShownSingle;
					for (var i=0; i<findTicksArrayPrecipitation.length; i++) {
						precipitationShownSingle = precipitationUsed[parseFloat(findTicksArrayPrecipitation[i])];
						precipitationShown.push(precipitationShownSingle);			
					}
					pressureShown = [];
					var pressureShownSingle;
					for (var i=0; i<findTicksArrayPressure.length; i++) {
						pressureShownSingle = pressureUsed[parseFloat(findTicksArrayPressure[i])];
						pressureShown.push(pressureShownSingle);			
					}
	
					// Which and how many Y-Axes we need
					findAxis();
	
					// Remove the whole graph
					d3.select("#d3_GraphDiv"+block).remove();
					
					// Update X range
					xScale.range([0, (width+(margin.left_single*axis_sum)-(margin.left_single*axis_selection))]);
					
					// Update Y range
					yScaleTemp.range([height, 0]);
					yScalePrec.range([height, 0]);
					yScalePress.range([height, 0]);
					
					// Create again the svg
					createSvg();
					
					// Update domains
					minTempYArray = [];
					maxTempYArray = [];
					if (temperature_selection===true) {
						for (var i=0; i<temperatureShown.length; i++) {
							minTempYArray.push(d3.min(data, function(d) { return Math.min(d[temperatureShown[i][0]]); }) );
							maxTempYArray.push(d3.max(data, function(d) { return Math.max(d[temperatureShown[i][0]]); }) );  
						}
						minTempY = d3.min(minTempYArray);
						maxTempY = d3.max(maxTempYArray);
						yScaleTemp.domain([minTempY, maxTempY]);
					}
					minPrecYArray = [];
					maxPrecYArray = [];
					if (precipitation_selection===true) {
						for (var i=0; i<precipitationShown.length; i++) {
							minPrecYArray.push(d3.min(data, function(d) { return Math.min(d[precipitationShown[i][0]]); }) );
							maxPrecYArray.push(d3.max(data, function(d) { return Math.max(d[precipitationShown[i][0]]); }) );  
						}
						minPrecY = d3.min(minPrecYArray);
						maxPrecY = d3.max(maxPrecYArray);
						yScalePrec.domain([minPrecY, maxPrecY]);
					}
					minPressYArray = [];
					maxPressYArray = [];
					if (pressure_selection===true) {
						for (var i=0; i<pressureShown.length; i++) {
							minPressYArray.push(d3.min(data, function(d) { return Math.min(d[pressureShown[i][0]]); }) );
							maxPressYArray.push(d3.max(data, function(d) { return Math.max(d[pressureShown[i][0]]); }) );  
						}
						minPressY = d3.min(minPressYArray);
						maxPressY = d3.max(maxPressYArray);
						yScalePress.domain([minPressY, maxPressY]);
					}
					
					// Redraw Graphs
					for (var i=0; i<temperatureShown.length; i++) {
						graphDraw(temperatureShown[i][0], yScaleTemp, temperatureShown[i][1]);
					}
					for (var i=0; i<precipitationShown.length; i++) {
						graphDraw(precipitationShown[i][0], yScalePrec, precipitationShown[i][1]);
					}
					for (var i=0; i<pressureShown.length; i++) {
						graphDraw(pressureShown[i][0], yScalePress, pressureShown[i][1]);
					}
					
					// Redraw Y-Axes
					for (var i=0; i<yAxisArray.length; i++) {
						yAxisDraw(yAxisArray[i][0], yAxisArray[i][1], yAxisArray[i][2], i);
					}
					
					// Redraw X axis
					xAxisDraw();
					
					// Add again CSS for the axes
					addCss();
					
					// Call hover function
					hover();
				}	
				// *** Redraw the Graph - END *** 
				
				// Click checkbox
				$("#"+blockID+" :checkbox").click(function() {
					// Maximum checkboxes checked: 4 / Minimum: 1
					var maxChecked = $("#"+blockID+" :checkbox:checked").length >= 4; 
					$("#"+blockID+" :checkbox").not(":checked").attr("disabled",maxChecked);
					var minChecked = $("#"+blockID+" :checkbox:checked").length <= 1;
					$("#"+blockID+" :checkbox:checked").attr("disabled",minChecked);
					if (temperatureHidden===true) {
						for (var i=0; i<temperatureUsed.length; i++) {
							if ($("#d3_checkboxTemperature"+i+block).is(":checked")) {
								$("#d3_keysTemperature"+i+block).show();
							} else {
								$("#d3_keysTemperature"+i+block).hide();
							}
						}
					}
					if (precipitationHidden===true) {
						for (var i=0; i<precipitationUsed.length; i++) {
							if ($("#d3_checkboxPrecipitation"+i+block).is(":checked")) {
								$("#d3_keysPrecipitation"+i+block).show();
							} else {
								$("#d3_keysPrecipitation"+i+block).hide();
							}
						}
					}
					if (pressureHidden===true) {
						for (var i=0; i<pressureUsed.length; i++) {
							if ($("#d3_checkboxPressure"+i+block).is(":checked")) {
								$("#d3_keysPressure"+i+block).show();
							} else {
								$("#d3_keysPressure"+i+block).hide();
							}
						}
					}
		
					// Hide dropdowns with delay
					if (temperatureHidden===false) {
						setTimeout(function(){$("#d3_temperatureToggle"+block).click();}, 2000);
					}
					if (precipitationHidden===false) {
						setTimeout(function(){$("#d3_precipitationToggle"+block).click();}, 2000); 
					}
					if (pressureHidden===false) {
						setTimeout(function(){$("#d3_pressureToggle"+block).click();}, 2000); 
					}
					
					// Redraw graph
					redrawGraph();
				});
				
				// Maximize-minimize Window	
				$(".portlet-maximize").click(function(){
					// Get new width
					widthDiv = $("#"+blockID).width();
					width = widthDiv - margin.left - margin.right - legendWidth;
					height = width/2;
					$("#d3_legendDiv"+block).css("height", height + margin.top + margin.bottom - heightPrintSelect);
					// Redraw graph
					redrawGraph();
				});
				
				// *** Diagram Hover function - START ***
				function hover() {
					var element;
					var position;
					var x;
					var y;
					
					$("#d3_GraphDiv"+block).mousemove(function(event) {
						element = document.getElementById("d3_GraphDiv"+block);
						position = element.getBoundingClientRect();
						x = position.left;
						y = position.top;
						
						mouseOver(event);
					});
					
					$("#d3_GraphDiv"+block).mouseleave(function(event) {
						mouseLeave(event);
					});
					
					function mouseOver(event) {
						mouseX = event.pageX;
						mouseY = event.pageY;
						if (mouseX > (x+(margin.left_single*axis_selection)) && mouseX < (x+widthDiv-margin.right)) {
							$("#d3_hoverLine"+block).show();
							$("#d3_tooltip"+block).show();
							hoverLine.attr("x1", mouseX-x).attr("x2", mouseX-x);
							showLabels((mouseX-x-margin.left_single*axis_selection),500);
						} else {
							$("#d3_hoverLine"+block).hide();
							$("#d3_tooltip"+block).hide();
						}
					}
					
					function mouseLeave(event) {
						$("#d3_hoverLine"+block).hide();
						$("#d3_tooltip"+block).hide();
					}
						
					// Create line
					var hoverLineGroup = d3.select("#svg"+block).append("g")
						.attr("id", "d3_hoverLine"+block)
						.attr("class", "d3_hoverLineClass");
					// Add line to the group
					var hoverLine = hoverLineGroup
						.append("line")
						.attr("x1", 0).attr("x2", 0)
						.attr("y1", margin.top).attr("y2", height+margin.top);
							
					$("#d3_hoverLine"+block).hide();
					
					var showLabels = function(xPosition, yPosition) {
						// Get the date on X-Axis for the current location
						var xValue = xScale.invert(xPosition);
						var bisect = d3.bisector(function(d) { return d.date; }).left;
						var item = data[bisect(data, xValue)];
						
						if (item) {
							// Format the date
							var dateParse = d3.time.format("%a %b %d %Y").parse(item.date.toDateString());
							var formatter = d3.time.format("%Y-%m-%d");
							var date = formatter(dateParse);
							
							// Create content for tooltips
							var tooltipText="";
							tooltipText = "<table style='margin:0px;'>";
								
								tooltipText += "<tr>";
									tooltipText += "<td>&nbsp;<img src='"+settings.basePath+"sites/all/modules/custom/ccis/images/d3/symbol_infobereich_clock.png' width='11' height='12'></td>";
									tooltipText += "<td>&nbsp;Date: </td>";
									tooltipText += "<td><b>"+date+"</b></td>";
								tooltipText += "</tr>";				
								if (temperatureShown.length>0) {
									for (var i=0; i<temperatureShown.length; i++) {									
										if (i===0) {
											tooltipText += "<tr style='border-top: 1pt solid #D1D1FF;'>";
											tooltipText += "<td>&nbsp;<img src='"+settings.basePath+"sites/all/modules/custom/ccis/images/d3/symbol_legende_thermometer.png' width='7' height='21'></td>";
										} else {
											tooltipText += "<tr>";
											tooltipText += "<td></td>";
										}
										tooltipText += "<td style='color:"+temperatureShown[i][1]+"'>&nbsp;"+temperatureShown[i][2]+"</td>";
										tooltipText += "<td style='color:"+temperatureShown[i][1]+"'>"+item[temperatureShown[i][0]].toFixed(1)+" &#8451;</td>";
										tooltipText += "</tr>";
									}		
								}
								if (precipitationShown.length>0) {
									for (var i=0; i<precipitationShown.length; i++) {
										if (i===0) {
											tooltipText += "<tr style='border-top: 1pt solid #D1D1FF;'>";
											tooltipText += "<td>&nbsp;<img src='"+settings.basePath+"sites/all/modules/custom/ccis/images/d3/symbol_legende_drop.png' width='11' height='17'></td>";
										} else {
											tooltipText += "<tr>";
											tooltipText += "<td></td>";
										}
										tooltipText += "<td style='color:"+precipitationShown[i][1]+"'>&nbsp;"+precipitationShown[i][2]+"</td>";
										tooltipText += "<td style='color:"+precipitationShown[i][1]+"'>"+item[precipitationShown[i][0]].toFixed(1)+" mm</td>";
										tooltipText += "</tr>";
									}		
								}
								if (pressureShown.length>0) {
									for (var i=0; i<pressureShown.length; i++) {
										if (i===0) {
											tooltipText += "<tr style='border-top: 1pt solid #D1D1FF;'>";
											tooltipText += "<td>&nbsp;<img src='"+settings.basePath+"sites/all/modules/custom/ccis/images/d3/symbol_legende_pressure.png' width='19' height='16'></td>";
										} else {
											tooltipText += "<tr>";
											tooltipText += "<td></td>";
										}
										tooltipText += "<td style='color:"+pressureShown[i][1]+"'>&nbsp;"+pressureShown[i][2]+"</td>";
										tooltipText += "<td style='color:"+pressureShown[i][1]+"'>"+item[pressureShown[i][0]].toFixed(1)+" hPa</td>";
										tooltipText += "</tr>";
									}		
								}
								
							tooltipText += "</table>";
	
							// Create tooltip
							$("#d3_GraphDiv"+block).append("<div id='d3_tooltip"+block+"' class='d3_tooltipClass'</div>");		
							d3.select("#d3_tooltip"+block)			
								.style("left", (mouseX-x+5)+"px")
								.style("top", (height/3)+"px")
								.html(tooltipText);
	
							// Change direction of tooltip
							if (mouseX+($("#d3_tooltip"+block).width()) > x+widthDiv-margin.right-legendWidth) {
								d3.select("#d3_tooltip"+block)
									.style("left", (mouseX-x-5-$("#d3_tooltip"+block).width())+"px")
							}
						}
					}
				}
				// *** Diagram Hover function - END ***
				hover();
					
				// *** Print functions - START ***
				function printPreview() {
					var newWindow=window.open("","","");
					
					$(newWindow).ready(function(){
				
						// Clone Diagram
						clone = $("#d3_GraphDiv"+block).clone();
						// Remove background color and border
						clone[0].firstChild.setAttribute("style", "background-color: ; outline: ;");
						
						// Get html
						var html = clone.html();
						
						// Get the name of the Station
						var stationName = settings.ccis.stations[0].station_name;
							
						var printKeys = "";
						for (var i=0; i<temperatureShown.length; i++) {
							printKeys += "<br><div style='height:0px; width:10px; border-top: 5px solid "+temperatureShown[i][1]+"; border-bottom: 5px solid "+temperatureShown[i][1]+"; outline:solid 1px black; float:left; margin-left:5px; margin-right:5px; margin-top:3px;'></div><span style='font-size:14px'>"+temperatureShown[i][3]+" (&#8451;)</span>";
						}
						for (var i=0; i<precipitationShown.length; i++) {
							printKeys += "<br><div style='height:0px; width:10px; border-top: 5px solid "+precipitationShown[i][1]+"; border-bottom: 5px solid "+precipitationShown[i][1]+"; outline:solid 1px black; float:left; margin-left:5px; margin-right:5px; margin-top:3px;'></div><span style='font-size:14px'>"+precipitationShown[i][3]+" (mm)</span>";
						}
						for (var i=0; i<pressureShown.length; i++) {
							printKeys += "<br><div style='height:0px; width:10px; border-top: 5px solid "+pressureShown[i][1]+"; border-bottom: 5px solid "+pressureShown[i][1]+"; outline:solid 1px black; float:left; margin-left:5px; margin-right:5px; margin-top:3px;'></div><span style='font-size:14px'>"+pressureShown[i][3]+" (hPa)</span>";
						}
						newWindow.document.body.innerHTML = "<span style='font-size:16px'>Station: <b>"+stationName+"</b></span><br/>"+html+printKeys+"<br/><br/><button id='printButton"+block+"' class='d3_buttonId'>Print</button>  <button id='closePreviewWindow"+block+"' class='d3_buttonId'>Close Window</button>";
			
						// CSS for the Buttons (new window)
						$(newWindow.document).contents().find(".d3_buttonId")
							.css("border", "1px solid #dcdcdc")
							.css("-webkit-border-radius", "10px")
							.css("-moz-border-radius", "10px")
							.css("border-radius", "10px")
							.css("background-color", "#ededed")
							.css("color", "#211921")
							.css("-moz-box-shadow", "inset 0px -1px 0px 0px #877087")
							.css("-webkit-box-shadow", "inset 0px -1px 0px 0px #877087")
							.css("box-shadow", "inset 0px -1px 0px 0px #877087");		
						$(newWindow.document).contents().find(".d3_buttonId").hover( function(){
						     $(this).css("background-color", "#dfdfdf");
						},
						function(){
							$(this).css('background-color', '#ededed');
						});
						
						$(newWindow.document).contents().find("#printButton"+block).click(function() {
							printFunction();
						});	
						
						$(newWindow.document).contents().find("#closePreviewWindow"+block).click(function() {
							newWindow.close();
						});	
						
						function printFunction() {
							var printWindow=window.open("","","");
							$(newWindow).ready(function(){
								printWindow.document.body.innerHTML = "<span style='font-size:16px'>Station: <b>"+stationName+"</b></span><br/>"+html+printKeys;
	
								printWindow.print();
								printWindow.close();
							});			
						}
					});
				}
				// *** Print functions - END ***
			}
		});
	}
	// ***************************************
	// ********** DIAGRAM 1 - END ************
	// ***************************************

	

	// ***************************************
	// ********** DIAGRAM 2 - START **********
	// ***************************************
	function diagram2(){
		// *** Variables - START ***
		var blockID = settings.ccis.stations[1].selector;
		var block = "_2"
			
		var margin = {top: 20, right: 10, bottom: 25, left: 105, left_single: 35};
		var widthDiv = $("#"+blockID).width();
		var legendWidth = 170;
		var tooltipWidth = 200;
		var width = widthDiv - margin.left - margin.right - legendWidth;
		var height = width/2;
		var widthTemp = width;
		var topOffset = 310;
		var heightPrintSelect = 50;
		var axis_sum = 3;
		var axis_selection;
		var svg;
		var temperatureHidden;
		var precipitationHidden;
		var pressureHidden;
	   	
	   	// Parameters parsed for the specific user
		var temperatureUsed = [];
		var precipitationUsed = [];
		var pressureUsed = [];
		
		// Parameters shown at the graph (max: 4)
		var temperatureShown = [];
		var precipitationShown = [];
		var pressureShown = [];
		
		var mouseX;
		var mouseY;
		var yAxisArray = [];
		var temperature_selection;
		var precipitation_selection;
		var pressure_selection;
		var legendCategoriesOpen = "Open categories";
		var legendCategoriesClose = "Close categories";
		var plus = "<img src='"+settings.basePath+"sites/all/modules/custom/ccis/images/d3/plus.png' width='7' height='7'>"
		var minus = "<img src='"+settings.basePath+"sites/all/modules/custom/ccis/images/d3/minus.png' width='7' height='7'>"	
		// *** Variables - END ***

		// Parse the JSON
		d3.json(settings.ccis.stations[1].path, function(json) {
			if (json.length===0) {
				$("#"+blockID).html("");
			} else {
				$("#"+blockID).html("");

				// Get parameters names
				var dataKeysArray = Object.keys(json[0]);
				
				// Create object with the parameters and the values
				var data = json.map(function(d) {
					var obj = {};
					//obj.date: d3.time.format("%Y-%m-%d %H:%M:%S").parse(d.date.slice(0,-3); // Datum & Zeit ohne Zeitzone
					obj.date = d3.time.format("%Y-%m-%d").parse(d.date.slice(0,-12)); // Nur Datum
					// i=2: The first two parameters are Station and Date
					for (var i=2; i<dataKeysArray.length; i++) {
						obj[dataKeysArray[i]] = parseFloat(d[dataKeysArray[i]]);
					}
					return obj;
	  
				});
				
				// Create an array per group with the parameters used, the colors, the legend keywords and the legend hover names
				for (var i=2; i<dataKeysArray.length; i++) {
					for (var k=0; k<temperature.length; k++) {
						if (dataKeysArray[i]===temperature[k][0]) {
							temperatureUsed.push([temperature[k][0], temperature[k][1], temperature[k][2], temperature[k][3], temperature[k][4]]);
						}
					}
					for (var k=0; k<precipitation.length; k++) {
						if (dataKeysArray[i]===precipitation[k][0]) {
							precipitationUsed.push([precipitation[k][0], precipitation[k][1], precipitation[k][2], precipitation[k][3], precipitation[k][4]]);
						}
					}
					for (var k=0; k<pressure.length; k++) {
						if (dataKeysArray[i]===pressure[k][0]) {
							pressureUsed.push([pressure[k][0], pressure[k][1], pressure[k][2], pressure[k][3], pressure[k][4]]);
						}
					} 
				}
				
				// Choose initial parameters to show
				temperatureShown.push(temperatureUsed[0], temperatureUsed[1]);
				precipitationShown.push(precipitationUsed[0]);
				//pressureShown.push(pressureUsed[0]);

				// Find the max and min values for the Y scales
				// Temperature values
				var minTempYArray = [];
				var maxTempYArray = [];
				for (var i=0; i<temperatureShown.length; i++) {
					minTempYArray.push(d3.min(data, function(d) { return Math.min(d[temperatureShown[i][0]]); }) );
					maxTempYArray.push(d3.max(data, function(d) { return Math.max(d[temperatureShown[i][0]]); }) );  
				}
				var minTempY = d3.min(minTempYArray);
				var maxTempY = d3.max(maxTempYArray);
				// Precipitation values
				var minPrecYArray = [];
				var maxPrecYArray = [];
				for (var i=0; i<precipitationShown.length; i++) {
					minPrecYArray.push(d3.min(data, function(d) { return Math.min(d[precipitationShown[i][0]]); }) );
					maxPrecYArray.push(d3.max(data, function(d) { return Math.max(d[precipitationShown[i][0]]); }) );  
				}
				var minPrecY = d3.min(minPrecYArray);
				var maxPrecY = d3.max(maxPrecYArray);
				// Pressure values
				var minPressYArray = [];
				var maxPressYArray = [];
				for (var i=0; i<pressureShown.length; i++) {
					minPressYArray.push(d3.min(data, function(d) { return Math.min(d[pressureShown[i][0]]); }) );
					maxPressYArray.push(d3.max(data, function(d) { return Math.max(d[pressureShown[i][0]]); }) );  
				}
				var minPressY = d3.min(minPressYArray);
				var maxPressY = d3.max(maxPressYArray);
				
				// Y Scales
				var yScaleTemp = d3.scale.linear()
					.domain([minTempY, maxTempY])
					.range([height, 0]);
				var yScalePrec = d3.scale.linear()
					.domain([minPrecY, maxPrecY])
					.range([height, 0]);
				var yScalePress = d3.scale.linear()
					.domain([minPressY, maxPressY])
					.range([height, 0]);
				
				// Which and how many Y-Axes we need
				function findAxis() {
					axis_selection = 0;
					yAxisArray = [];
					temperature_selection = false;
					if (temperatureShown.length>0) {
						temperature_selection=true;
						yAxisArray.push(["yAxisTemp", yScaleTemp, "Temperature"]);
						axis_selection=axis_selection+1;
					}
					precipitation_selection = false;
					if (precipitationShown.length>0) {
						precipitation_selection = true;
						yAxisArray.push(["yAxisPrec", yScalePrec, "Precipitation"]);
						axis_selection=axis_selection+1;
					}
					pressure_selection = false;
					if (pressureShown.length>0) {
						pressure_selection = true;
						yAxisArray.push(["yAxisPress", yScalePress, "Pressure"]);
						axis_selection=axis_selection+1;
					}
				}
				findAxis();
							
				// X Scale
				var xScale = d3.time.scale()
		  			.domain(d3.extent(data, function(d) { return d.date; }))
		  			.range([0, (width+(margin.left_single*axis_sum)-(margin.left_single*axis_selection))]);

				//Create SVG element
				function createSvg() {
					$("#"+blockID).prepend("<div id='d3_GraphDiv"+block+"' class='d3_GraphDivClass'></div>");
					svg = d3.select("#d3_GraphDiv"+block)
						.append("svg")
						.attr("id", "svg"+block)
						.attr("class", "d3_svgElement")
						.attr("width", (width + (margin.left_single)*axis_sum + margin.right))
						.attr("height", height + margin.top + margin.bottom)
						.append("g")
						.attr("transform", "translate(" + (margin.left-((margin.left_single*axis_sum)-(margin.left_single*axis_selection))) + "," + margin.top + ")");
				}
				createSvg();
			  
				// Create graphs
				function graphDraw(graphType, yscaleType, color) {
					
					var graphObj = {};
					
					graphObj[graphType] = d3.svg.line()
						.interpolate("linear")
						.x(function(d){return xScale(d.date)})
						.y(function(d){return yscaleType(d[graphType])});

					d3.select("#svg"+block)
						.append("path")
					  	.attr("id", "d3_path"+graphType+"ID"+block)
						.attr("d", graphObj[graphType](data))
						.attr("stroke", color)
						.attr("stroke-width", "2")
						.attr("fill", "none")
						.attr("transform", "translate(" + (margin.left-((margin.left_single*axis_sum)-(margin.left_single*axis_selection))) + "," + margin.top + ")");		  
				}

				for (var i=0; i<temperatureShown.length; i++) {
					graphDraw(temperatureShown[i][0], yScaleTemp, temperatureShown[i][1]);
				}
				for (var i=0; i<precipitationShown.length; i++) {
					graphDraw(precipitationShown[i][0], yScalePrec, precipitationShown[i][1]);
				}
				for (var i=0; i<pressureShown.length; i++) {
					graphDraw(pressureShown[i][0], yScalePress, pressureShown[i][1]);
				}
				
				// Draw Y Axis
				function yAxisDraw(axisType, scaleType, label, axisPosition) {
					var yAxisObj = {};
					var yAxisLabel;
					var yAxisLabelOffset;
					var yAxisTickFormat;
					var iconLink;
					var iconWidth;
					var iconHeight;
					if (axisType==="yAxisTemp") {
						yAxisLabel = "&#8451;" // Celsius
						yAxisLabelOffset = -20;
						yAxisTickFormat = ".1f";
						iconLink = settings.basePath +"sites/all/modules/custom/ccis/images/d3/symbol_legende_thermometer.png";
						iconWidth = "7px";
						iconHeight = "21px";
					} else if (axisType==="yAxisPrec") {
						yAxisLabel = "mm"
						yAxisLabelOffset = -30;
						yAxisTickFormat = ".1f";
						iconLink = settings.basePath +"sites/all/modules/custom/ccis/images/d3/symbol_legende_drop.png";
						iconWidth = "11px";
						iconHeight = "17px";
					} else if (axisType==="yAxisPress") {
						yAxisLabel = "hPa"
						yAxisLabelOffset = -30;
						yAxisTickFormat = ".0f";
						iconLink = settings.basePath +"sites/all/modules/custom/ccis/images/d3/symbol_legende_pressure.png";
						iconWidth = "19px";
						iconHeight = "16px";
					}
								
					// Grid only for the first y axis
					if (axisPosition === 0) {
						var yGrid = -(width+(margin.left_single*axis_sum)-(margin.left_single*axis_selection));
						yAxisObj["grid"] = d3.svg.axis()
							.scale(scaleType)
							.orient("left")
							.tickSize(yGrid, 0, 0)
							.tickFormat("")
							.ticks(5);
						svg.append("g")
							.attr("class", "d3_yGrid")
							.attr("transform", "translate("+(axisPosition*(-margin.left_single))+",0)")
							.call(yAxisObj["grid"]);
					}

					yAxisObj[axisType] = d3.svg.axis()
						.scale(scaleType)
						.orient("left")
						.tickFormat(d3.format(yAxisTickFormat))
						.ticks(5);
					svg.append("g")
						.attr("id", axisType+"id"+block)
						.attr("class", "d3_yAxisClass")
						.style("font-size","10px")
						.attr("transform", "translate("+(axisPosition*(-margin.left_single))+",0)")
						.call(yAxisObj[axisType]);
					d3.select("#"+axisType+"id"+block)
						.append("text")
						.html(yAxisLabel)
						.attr("class", "d3_yAxisText")
						.style("font-size","12px")
						.attr("transform", "translate ("+yAxisLabelOffset+", 0)");
					
					d3.select("#"+axisType+"id"+block)
						.append("image")
						.attr("xlink:href", iconLink)
						.attr("width", iconWidth)
						.attr("height", iconHeight)
						.attr("transform", "translate (-20, "+(height+3)+")");
				}
				
				// Call the Y Axis draw function
				for (var i=0; i<yAxisArray.length; i++) {
					yAxisDraw(yAxisArray[i][0], yAxisArray[i][1], yAxisArray[i][2], i);
				}
				
				// Draw X Axis
				function xAxisDraw() {
					var xAxis = d3.svg.axis()
						.scale(xScale)
					  	.orient("bottom")
					  	.ticks(5);
					svg.append("g")
						.attr("class", "d3_xAxisLine")
						.style("font-size","10px")
						.attr("transform", "translate(0," + height + ")")
						.call(xAxis);
				}	
				xAxisDraw();
			  
				// Add CSS to the axes (Do not place it in the css file)
				function addCss() {	
					$(".d3_yGrid")
						.css("stroke", "#D1D1FF")
						.css("shape-rendering", "crispEdges");
					
					$(".d3_yAxisClass path, .d3_yAxisClass line, .d3_xAxisLine path, .d3_xAxisLine line")
						.css("fill", "none")
						.css("stroke", "#000")
						.css("shape-rendering", "crispEdges");
				}
				addCss();

				// Legend Tooltips
				function hoverLegend(topPosition, keyPlace, text) {	
					$("#d3_tooltipLegend"+keyPlace+block)
						.css("position", "absolute")
						.css("right", (legendWidth-3)+"px")
						.css("top", (topPosition+topOffset)+"px")
						.css("width", "auto")
						.css("clear", "both")
						.css("float", "left")
						.css("background-color", "#fcce00")
						.css("border", "solid 1px #D1D1FF")
						.css("border-radius", "8px 8px 8px 8px")
						.css("-webkit-box-shadow", "4px 4px 10px rgba(0, 0, 0, 0.4)")
						.css("-moz-box-shadow", "4px 4px 10px rgba(0, 0, 0, 0.4)")
						.css("box-shadow", "4px 4px 10px rgba(0, 0, 0, 0.4)")
						.css("font-size","12px")
						.html(text);
				}
				
				function hoverLegendCategories(topPosition, text) {			
					$("#d3_tooltipLegendCategories"+block)
						.css("position", "absolute")
						.css("right", (legendWidth+5)+"px")
						.css("top", (topPosition+topOffset)+"px")
						.css("width", "auto")
						.css("clear", "both")
						.css("float", "left")
						.css("background-color", "#fcce00")
						.css("border", "solid 1px #D1D1FF")
						.css("border-radius", "8px 8px 8px 8px")
						.css("-webkit-box-shadow", "4px 4px 10px rgba(0, 0, 0, 0.4)")
						.css("-moz-box-shadow", "4px 4px 10px rgba(0, 0, 0, 0.4)")
						.css("box-shadow", "4px 4px 10px rgba(0, 0, 0, 0.4)")
						.css("font-size","12px")
						.html(text);
				}
				
				// Add div for the legend
				$("#"+blockID).append("<div id='d3_legendDiv"+block+"' class='d3_legendClass'></div>");
				
				$("#d3_legendDiv"+block)
					.css("width", legendWidth-1)
					.css("height", height + margin.top + margin.bottom - heightPrintSelect);
					
				// Create DIVs for the keys
				// Temperature
				if (temperatureUsed.length>0) {
					$("#d3_legendDiv"+block).append("<div id='d3_iconLegendTemp"+block+"' class='d3_iconLegendTempClass'><img src='"+settings.basePath+"sites/all/modules/custom/ccis/images/d3/symbol_legende_thermometer.png' width='7' height='21'></div>");
					$("#d3_legendDiv"+block).append("<div id='d3_temperatureToggle"+block+"' class='d3_toggleClass'><b><span id='d3_tempMinus"+block+"' class='d3_minus'>"+plus+"</span> Temperature <span class='d3_unitLegend'>[&#8451;]</span></b></div>");
					$("#d3_temperatureToggle"+block).hover(function() {
						$(this).css("cursor","pointer");
						$("#"+blockID).append("<div id='d3_tooltipLegendCategories"+block+"'></div>"); 
						var topPosition = $("#d3_temperatureToggle"+block).position().top;
						var legendText;
						if (temperatureHidden===true) {
							legendText = legendCategoriesOpen;
						} else if (temperatureHidden===false) {
							legendText = legendCategoriesClose;
						}
						hoverLegendCategories(topPosition, legendText);
					}, function() {$("#d3_tooltipLegendCategories"+block).remove();});
					$("#d3_legendDiv"+block).append("<div id='d3_keysDivTemperature"+block+"'></div>");
					for (var i=0; i<temperatureUsed.length; i++) {
						function findTempChecked() {
							for (var k=0; k<temperatureShown.length; k++) {
								if (temperatureUsed[i][0]===temperatureShown[k][0]) {
									return "checked";
								}
							}
						}
						$("#d3_keysDivTemperature"+block).append("<div id='d3_keysTemperature"+i+block+"' class='d3_keys'></div>");
						$("#d3_keysTemperature"+i+block).append("<div id='d3_keysTemperatureTick"+i+block+"' class='d3_keysTick'><input id='d3_checkboxTemperature"+i+block+"' type='checkbox' value='"+i+"' "+findTempChecked()+"></div>");			
						$("#d3_keysTemperature"+i+block).append("<div id='d3_keysTemperatureBoxText"+i+block+"' class='d3_keysBoxText'></div>");
						$("#d3_keysTemperatureBoxText"+i+block).append("<div id='keysTemperatureText"+i+block+"' class='d3_keysText'></div>");
						$("#keysTemperatureText"+i+block).append(temperatureUsed[i][2]);
						$("#d3_keysTemperatureBoxText"+i+block).append("<div id='keysTemperatureIcon"+i+block+"' class='d3_keysIcon'><img src='"+settings.basePath+"sites/all/modules/custom/ccis/images/d3/"+temperatureUsed[i][4]+"' width='25' height='15'></div>");
						(function(i) {
					    	$("#d3_keysTemperatureBoxText"+i+block)
					    		.hover(function(){
			    					$(this).css("cursor","default"); 
			    					
			    					$("#"+blockID).append("<div id='d3_tooltipLegend"+i+block+"'></div>"); 
			    					var topPosition = $("#d3_keysTemperatureBoxText"+i+block).position().top; 
			    					hoverLegend(topPosition, i, temperatureUsed[i][3]);
					    		},
			    				function() {$("#d3_tooltipLegend"+i+block).remove();});
					    })(i);
					}		
				}
				// Precipitation
				if (precipitationUsed.length>0) {
					$("#d3_legendDiv"+block).append("<div id='d3_iconLegendPrec"+block+"' class='d3_iconLegendPrecClass'><img src='"+settings.basePath+"sites/all/modules/custom/ccis/images/d3/symbol_legende_drop.png' width='11' height='17'></div>");
					$("#d3_legendDiv"+block).append("<div id='d3_precipitationToggle"+block+"' class='d3_toggleClass'><b><span id='d3_precMinus"+block+"' class='d3_minus'>"+plus+"</span> Precipitation <span class='d3_unitLegend'>[mm]</span></b></div>");
					$("#d3_precipitationToggle"+block).hover(function() {
						$(this).css("cursor","pointer");
						$("#"+blockID).append("<div id='d3_tooltipLegendCategories"+block+"'></div>"); 
						var topPosition = $("#d3_precipitationToggle"+block).position().top;
						var legendText;
						if (precipitationHidden===true) {
							legendText = legendCategoriesOpen;
						} else if (precipitationHidden===false) {
							legendText = legendCategoriesClose;
						}
						hoverLegendCategories(topPosition, legendText);
					}, function() {$("#d3_tooltipLegendCategories"+block).remove();});
					$("#d3_legendDiv"+block).append("<div id='d3_keysDivPrecipitation"+block+"'></div>");
					for (var i=0; i<precipitationUsed.length; i++) {
						function findPrecChecked() {
							for (var k=0; k<precipitationShown.length; k++) {
								if (precipitationUsed[i][0]===precipitationShown[k][0]) {
									return "checked";
								}
							}
						}
						$("#d3_keysDivPrecipitation"+block).append("<div id='d3_keysPrecipitation"+i+block+"' class='d3_keys'></div>");
						$("#d3_keysPrecipitation"+i+block).append("<div id='keysPrecipitationTick"+i+block+"' class='d3_keysTick'><input id='d3_checkboxPrecipitation"+i+block+"' type='checkbox' value='"+i+"' "+findPrecChecked()+"></div>");
						$("#d3_keysPrecipitation"+i+block).append("<div id='d3_keysPrecipitationBoxText"+i+block+"' class='d3_keysBoxText'></div>")
						
						$("#d3_keysPrecipitationBoxText"+i+block).append("<div id='d3_keysPrecipitationText"+i+block+"' class='d3_keysText'></div>");
						$("#d3_keysPrecipitationText"+i+block).append(precipitationUsed[i][2]);
						$("#d3_keysPrecipitationBoxText"+i+block).append("<div id='d3_keysPrecipitationIcon"+i+block+"' class='d3_keysIcon'><img src='"+settings.basePath+"sites/all/modules/custom/ccis/images/d3/"+precipitationUsed[i][4]+"' width='25' height='15'></div>");
						(function(i) {
					    	$("#d3_keysPrecipitationBoxText"+i+block)
					    		.hover(function(){
			    					$(this).css("cursor","default"); 
			    					$("#"+blockID).append("<div id='d3_tooltipLegend"+i+block+"'></div>"); 
			    					var topPosition = $("#d3_keysPrecipitationBoxText"+i+block).position().top; 
			    					hoverLegend(topPosition, i, precipitationUsed[i][3]);
					    		},
			    				function() {$("#d3_tooltipLegend"+i+block).remove();});
					    })(i);
					}
				}
				// Pressure
				if (pressureUsed.length>0) {
					$("#d3_legendDiv"+block).append("<div id='d3_iconLegendPress"+block+"' class='d3_iconLegendPressClass'><img src='"+settings.basePath+"sites/all/modules/custom/ccis/images/d3/symbol_legende_pressure.png' width='19' height='16'></div>");
					$("#d3_legendDiv"+block).append("<div id='d3_pressureToggle"+block+"' class='d3_toggleClass'><b><span id='d3_pressMinus"+block+"' class='d3_minus'>"+plus+"</span> Pressure <span class='d3_unitLegend'>[hPa]</span></b></div>");
					$("#d3_pressureToggle"+block).hover(function() {
						$(this).css("cursor","pointer");
						$("#"+blockID).append("<div id='d3_tooltipLegendCategories"+block+"'></div>"); 
						var topPosition = $("#d3_pressureToggle"+block).position().top;
						var legendText;
						if (pressureHidden===true) {
							legendText = legendCategoriesOpen;
						} else if (pressureHidden===false) {
							legendText = legendCategoriesClose;
						}
						hoverLegendCategories(topPosition, legendText);
					}, function() {$("#d3_tooltipLegendCategories"+block).remove();});
					$("#d3_legendDiv"+block).append("<div id='d3_keysDivPressure"+block+"'></div>");
					for (var i=0; i<pressureUsed.length; i++) {
						function findPressChecked() {
							for (var k=0; k<pressureShown.length; k++) {
								if (pressureUsed[i][0]===pressureShown[k][0]) {
									return "checked";
								}
							}
						}
						$("#d3_keysDivPressure"+block).append("<div id='d3_keysPressure"+i+block+"' class='d3_keys'></div>");
						$("#d3_keysPressure"+i+block).append("<div id='d3_keysPressureTick"+i+block+"' class='d3_keysTick'><input id='d3_checkboxPressure"+i+block+"' type='checkbox' value='"+i+"' "+findPressChecked()+"></div>");
						$("#d3_keysPressure"+i+block).append("<div id='d3_keysPressureBoxText"+i+block+"' class='d3_keysBoxText'></div>");
						$("#d3_keysPressureBoxText"+i+block).append("<div id='d3_keysPressureText"+i+block+"' class='d3_keysText'></div>");
						$("#d3_keysPressureText"+i+block).append(pressureUsed[i][2]);
						$("#d3_keysPressureBoxText"+i+block).append("<div id='d3_keysPressureIcon"+i+block+"' class='d3_keysIcon'><img src='"+settings.basePath+"sites/all/modules/custom/ccis/images/d3/"+pressureUsed[i][4]+"' width='25' height='15'></div>");
						(function(i) {
					    	$("#d3_keysPressureBoxText"+i+block)
					    		.hover(function(){
			    					$(this).css("cursor","default"); 
			    					$("#"+blockID).append("<div id='d3_tooltipLegend"+i+block+"'></div>"); 
			    					var topPosition = $("#d3_keysPressureBoxText"+i+block).position().top; 
			    					hoverLegend(topPosition, i, pressureUsed[i][3]);
					    		},
			    				function() {$("#d3_tooltipLegend"+i+block).remove();});
					    })(i);
					}
				}
				
				// Maximum checkboxes checked: 4 / Minimum: 1
				var maxChecked = $("#"+blockID+" :checkbox:checked").length >= 4; 
				$("#"+blockID+" :checkbox").not(":checked").attr("disabled",maxChecked);
				var minChecked = $("#"+blockID+" :checkbox:checked").length <= 1;
				$("#"+blockID+" :checkbox:checked").attr("disabled",minChecked);
				
				// By default is the dropdown hidden
				for (var i=0; i<temperatureUsed.length; i++) {
					$("#d3_keysTemperature"+i+block).hide();
					if ($("#d3_checkboxTemperature"+i+block).is(":checked")) {
						$("#d3_keysTemperature"+i+block).show();
					}	
				}
				temperatureHidden=true;
				for (var i=0; i<precipitationUsed.length; i++) {
					$("#d3_keysPrecipitation"+i+block).hide();
					if ($("#d3_checkboxPrecipitation"+i+block).is(":checked")) {
						$("#d3_keysPrecipitation"+i+block).show();
					}	
				} 
				precipitationHidden=true;
				for (var i=0; i<pressureUsed.length; i++) {
					$("#d3_keysPressure"+i+block).hide();
					if ($("#d3_checkboxPressure"+i+block).is(":checked")) {
						$("#d3_keysPressure"+i+block).show();
					}	
				}
				pressureHidden=true;
				
				// Collapse	
				$("#d3_temperatureToggle"+block).click(function() {
					if (temperatureHidden===true) {
						$("#d3_tempMinus"+block).html(minus);
						for (var i=0; i<temperatureUsed.length; i++) {			
							$("#d3_keysTemperature"+i+block).show();
						}
						temperatureHidden=false;
						$("#d3_tooltipLegendCategories"+block).html(legendCategoriesClose);
					} else if (temperatureHidden===false) {
						$("#d3_tempMinus"+block).html(plus);
						for (var i=0; i<temperatureUsed.length; i++) {
							$("#d3_keysTemperature"+i+block).hide();
							if ($("#d3_checkboxTemperature"+i+block).is(":checked")) {
								$("#d3_keysTemperature"+i+block).show();
							}	
						}
						temperatureHidden=true;
						$("#d3_tooltipLegendCategories"+block).html(legendCategoriesOpen);
					}
				});
				$("#d3_precipitationToggle"+block).click(function() {
					if (precipitationHidden===true) {
						$("#d3_precMinus"+block).html(minus);
						for (var i=0; i<precipitationUsed.length; i++) {			
							$("#d3_keysPrecipitation"+i+block).show();
						}
						precipitationHidden=false;
						$("#d3_tooltipLegendCategories"+block).html(legendCategoriesClose);
					} else if (precipitationHidden===false) {
						$("#d3_precMinus"+block).html(plus);
						for (var i=0; i<precipitationUsed.length; i++) {
							$("#d3_keysPrecipitation"+i+block).hide();
							if ($("#d3_checkboxPrecipitation"+i+block).is(":checked")) {
								$("#d3_keysPrecipitation"+i+block).show();
							}	
						}
						precipitationHidden=true;
						$("#d3_tooltipLegendCategories"+block).html(legendCategoriesOpen);
					}
				});
				$("#d3_pressureToggle"+block).click(function() {
					if (pressureHidden===true) {
						$("#d3_pressMinus"+block).html(minus);
						for (var i=0; i<pressureUsed.length; i++) {			
							$("#d3_keysPressure"+i+block).show();
						}
						pressureHidden=false;
						$("#d3_tooltipLegendCategories"+block).html(legendCategoriesClose);
					} else if (pressureHidden===false) {
						$("#d3_pressMinus"+block).html(plus);
						for (var i=0; i<pressureUsed.length; i++) {
							$("#d3_keysPressure"+i+block).hide();
							if ($("#d3_checkboxPressure"+i+block).is(":checked")) {
								$("#d3_keysPressure"+i+block).show();
							}	
						}
						pressureHidden=true;
						$("#d3_tooltipLegendCategories"+block).html(legendCategoriesOpen);
					}
				});
				
				// Print preview button
				$("#"+blockID).append("<div id='printSelectWrapper"+block+"' class='printSelectWrapperClass'></div>");
				$("#printSelectWrapper"+block)
					.css("width", legendWidth)
					.css("height", heightPrintSelect);
				$("#printSelectWrapper"+block).append("<div id='d3_SelectDiagramsText"+block+"' class='d3_SelectDiagramsTextClass'><i>Select up to 4 indices</i></div>");
				$("#printSelectWrapper"+block).append("<div id='d3_printPreviewId"+block+"' class='d3_printPreviewClass'><img src='"+settings.basePath+"sites/all/modules/custom/ccis/images/d3/symbol_printer.png' width='16' height='16'><b><span style='font-size:14px;'>&nbsp;Print Preview</span></b></div>");
				$("#d3_printPreviewId"+block).hover(function() {
					$(this).css("cursor","pointer");
				});
				$("#d3_printPreviewId"+block).click(function() {
					printPreview();
				});
				
				// *** Redraw the Graph - START ***
				function redrawGraph() {

					if (document.getElementById("d3_keysDivTemperature"+block)) {
						var findIDsTemperature = $("#d3_keysDivTemperature"+block+" input:checkbox:checked").map(function(){		        
							return $(this).val();      
						});
						var findTicksArrayTemperature = findIDsTemperature.get();
					}
					if (document.getElementById("d3_keysDivPrecipitation"+block)) {
						var findIDsPrecipitation = $("#d3_keysDivPrecipitation"+block+" input:checkbox:checked").map(function(){		        
							return $(this).val();      
						});
						var findTicksArrayPrecipitation = findIDsPrecipitation.get();
					}
					if (document.getElementById("d3_keysDivPressure"+block)) {
						var findIDsPressure = $("#d3_keysDivPressure"+block+" input:checkbox:checked").map(function(){		        
							return $(this).val();      
						});
						var findTicksArrayPressure = findIDsPressure.get();
					}

					// Which parameters are selected
					temperatureShown = [];
					var temperatureShownSingle;
					for (var i=0; i<findTicksArrayTemperature.length; i++) {
						temperatureShownSingle = temperatureUsed[parseFloat(findTicksArrayTemperature[i])];
						temperatureShown.push(temperatureShownSingle);			
					}
					precipitationShown = [];
					var precipitationShownSingle;
					for (var i=0; i<findTicksArrayPrecipitation.length; i++) {
						precipitationShownSingle = precipitationUsed[parseFloat(findTicksArrayPrecipitation[i])];
						precipitationShown.push(precipitationShownSingle);			
					}
					pressureShown = [];
					var pressureShownSingle;
					for (var i=0; i<findTicksArrayPressure.length; i++) {
						pressureShownSingle = pressureUsed[parseFloat(findTicksArrayPressure[i])];
						pressureShown.push(pressureShownSingle);			
					}

					// Which and how many Y-Axes we need
					findAxis();

					// Remove the whole graph
					d3.select("#d3_GraphDiv"+block).remove();
					
					// Update X range
					xScale.range([0, (width+(margin.left_single*axis_sum)-(margin.left_single*axis_selection))]);
					
					// Update Y range
					yScaleTemp.range([height, 0]);
					yScalePrec.range([height, 0]);
					yScalePress.range([height, 0]);
					
					// Create again the svg
					createSvg();
					
					// Update domains
					minTempYArray = [];
					maxTempYArray = [];
					if (temperature_selection===true) {
						for (var i=0; i<temperatureShown.length; i++) {
							minTempYArray.push(d3.min(data, function(d) { return Math.min(d[temperatureShown[i][0]]); }) );
							maxTempYArray.push(d3.max(data, function(d) { return Math.max(d[temperatureShown[i][0]]); }) );  
						}
						minTempY = d3.min(minTempYArray);
						maxTempY = d3.max(maxTempYArray);
						yScaleTemp.domain([minTempY, maxTempY]);
					}
					minPrecYArray = [];
					maxPrecYArray = [];
					if (precipitation_selection===true) {
						for (var i=0; i<precipitationShown.length; i++) {
							minPrecYArray.push(d3.min(data, function(d) { return Math.min(d[precipitationShown[i][0]]); }) );
							maxPrecYArray.push(d3.max(data, function(d) { return Math.max(d[precipitationShown[i][0]]); }) );  
						}
						minPrecY = d3.min(minPrecYArray);
						maxPrecY = d3.max(maxPrecYArray);
						yScalePrec.domain([minPrecY, maxPrecY]);
					}
					minPressYArray = [];
					maxPressYArray = [];
					if (pressure_selection===true) {
						for (var i=0; i<pressureShown.length; i++) {
							minPressYArray.push(d3.min(data, function(d) { return Math.min(d[pressureShown[i][0]]); }) );
							maxPressYArray.push(d3.max(data, function(d) { return Math.max(d[pressureShown[i][0]]); }) );  
						}
						minPressY = d3.min(minPressYArray);
						maxPressY = d3.max(maxPressYArray);
						yScalePress.domain([minPressY, maxPressY]);
					}
					
					// Redraw Graphs
					for (var i=0; i<temperatureShown.length; i++) {
						graphDraw(temperatureShown[i][0], yScaleTemp, temperatureShown[i][1]);
					}
					for (var i=0; i<precipitationShown.length; i++) {
						graphDraw(precipitationShown[i][0], yScalePrec, precipitationShown[i][1]);
					}
					for (var i=0; i<pressureShown.length; i++) {
						graphDraw(pressureShown[i][0], yScalePress, pressureShown[i][1]);
					}
					
					// Redraw Y-Axes
					for (var i=0; i<yAxisArray.length; i++) {
						yAxisDraw(yAxisArray[i][0], yAxisArray[i][1], yAxisArray[i][2], i);
					}
					
					// Redraw X axis
					xAxisDraw();
					
					// Add again CSS for the axes
					addCss();
					
					// Call hover function
					hover();
				}	
				// *** Redraw the Graph - END *** 
				
				// Click checkbox
				$("#"+blockID+" :checkbox").click(function() {
					// Maximum checkboxes checked: 4 / Minimum: 1
					var maxChecked = $("#"+blockID+" :checkbox:checked").length >= 4; 
					$("#"+blockID+" :checkbox").not(":checked").attr("disabled",maxChecked);
					var minChecked = $("#"+blockID+" :checkbox:checked").length <= 1;
					$("#"+blockID+" :checkbox:checked").attr("disabled",minChecked);
					if (temperatureHidden===true) {
						for (var i=0; i<temperatureUsed.length; i++) {
							if ($("#d3_checkboxTemperature"+i+block).is(":checked")) {
								$("#d3_keysTemperature"+i+block).show();
							} else {
								$("#d3_keysTemperature"+i+block).hide();
							}
						}
					}
					if (precipitationHidden===true) {
						for (var i=0; i<precipitationUsed.length; i++) {
							if ($("#d3_checkboxPrecipitation"+i+block).is(":checked")) {
								$("#d3_keysPrecipitation"+i+block).show();
							} else {
								$("#d3_keysPrecipitation"+i+block).hide();
							}
						}
					}
					if (pressureHidden===true) {
						for (var i=0; i<pressureUsed.length; i++) {
							if ($("#d3_checkboxPressure"+i+block).is(":checked")) {
								$("#d3_keysPressure"+i+block).show();
							} else {
								$("#d3_keysPressure"+i+block).hide();
							}
						}
					}
					
					// Hide dropdowns with delay
					if (temperatureHidden===false) {
						setTimeout(function(){$("#d3_temperatureToggle"+block).click();}, 2000);
					}
					if (precipitationHidden===false) {
						setTimeout(function(){$("#d3_precipitationToggle"+block).click();}, 2000); 
					}
					if (pressureHidden===false) {
						setTimeout(function(){$("#d3_pressureToggle"+block).click();}, 2000); 
					}
					
					// Redraw graph
					redrawGraph();
				});
				
				// Maximize-minimize Window	
				$(".portlet-maximize").click(function(){
					// Get new width
					widthDiv = $("#"+blockID).width();
					width = widthDiv - margin.left - margin.right - legendWidth;
					height = width/2;
					// Change offset for the legend tooltips
					if (width>widthTemp) {
						topOffset = 30;
					} else {
						topOffset = 310;
					}
					$("#d3_legendDiv"+block).css("height", height + margin.top + margin.bottom - heightPrintSelect);
					// Redraw graph
					redrawGraph();
				});
				
				// *** Diagram Hover function - START ***
				function hover() {
					var element;
					var position;
					var x;
					var y;
					
					$("#d3_GraphDiv"+block).mousemove(function(event) {
						element = document.getElementById("d3_GraphDiv"+block);
						position = element.getBoundingClientRect();
						x = position.left;
						y = position.top;
						
						mouseOver(event);
					});
					
					$("#d3_GraphDiv"+block).mouseleave(function(event) {
						mouseLeave(event);
					});
					
					function mouseOver(event) {
						mouseX = event.pageX;
						mouseY = event.pageY;
						if (mouseX > (x+(margin.left_single*axis_selection)) && mouseX < (x+widthDiv-margin.right)) {
							$("#d3_hoverLine"+block).show();
							$("#d3_tooltip"+block).show();
							hoverLine.attr("x1", mouseX-x).attr("x2", mouseX-x);
							showLabels((mouseX-x-margin.left_single*axis_selection),500);
						} else {
							$("#d3_hoverLine"+block).hide();
							$("#d3_tooltip"+block).hide();
						}
					}
					
					function mouseLeave(event) {
						$("#d3_hoverLine"+block).hide();
						$("#d3_tooltip"+block).hide();
					}
						
					// Create line
					var hoverLineGroup = d3.select("#svg"+block).append("g")
						.attr("id", "d3_hoverLine"+block)
						.attr("class", "d3_hoverLineClass");
					// Add line to the group
					var hoverLine = hoverLineGroup
						.append("line")
						.attr("x1", 0).attr("x2", 0)
						.attr("y1", margin.top).attr("y2", height+margin.top);
							
					$("#d3_hoverLine"+block).hide();
					
					var showLabels = function(xPosition, yPosition) {
						// Get the date on X-Axis for the current location
						var xValue = xScale.invert(xPosition);
						var bisect = d3.bisector(function(d) { return d.date; }).left;
						var item = data[bisect(data, xValue)];
						
						if (item) {				
							// Format the date
							var dateParse = d3.time.format("%a %b %d %Y").parse(item.date.toDateString());
							var formatter = d3.time.format("%Y-%m-%d");
							var date = formatter(dateParse);
							
							// Create content for tooltips
							var tooltipText="";
							tooltipText = "<table style='margin:0px;'>";
								
								tooltipText += "<tr>";
									tooltipText += "<td>&nbsp;<img src='"+settings.basePath+"sites/all/modules/custom/ccis/images/d3/symbol_infobereich_clock.png' width='11' height='12'></td>";
									tooltipText += "<td>&nbsp;Date: </td>";
									tooltipText += "<td><b>"+date+"</b></td>";
								tooltipText += "</tr>";				
								if (temperatureShown.length>0) {
									for (var i=0; i<temperatureShown.length; i++) {									
										if (i===0) {
											tooltipText += "<tr style='border-top: 1pt solid #D1D1FF;'>";
											tooltipText += "<td>&nbsp;<img src='"+settings.basePath+"sites/all/modules/custom/ccis/images/d3/symbol_legende_thermometer.png' width='7' height='21'></td>";
										} else {
											tooltipText += "<tr>";
											tooltipText += "<td></td>";
										}
										tooltipText += "<td style='color:"+temperatureShown[i][1]+"'>&nbsp;"+temperatureShown[i][2]+"</td>";
										tooltipText += "<td style='color:"+temperatureShown[i][1]+"'>"+item[temperatureShown[i][0]].toFixed(1)+" &#8451;</td>";
										tooltipText += "</tr>";
									}		
								}
								if (precipitationShown.length>0) {
									for (var i=0; i<precipitationShown.length; i++) {
										if (i===0) {
											tooltipText += "<tr style='border-top: 1pt solid #D1D1FF;'>";
											tooltipText += "<td>&nbsp;<img src='"+settings.basePath+"sites/all/modules/custom/ccis/images/d3/symbol_legende_drop.png' width='11' height='17'></td>";
										} else {
											tooltipText += "<tr>";
											tooltipText += "<td></td>";
										}
										tooltipText += "<td style='color:"+precipitationShown[i][1]+"'>&nbsp;"+precipitationShown[i][2]+"</td>";
										tooltipText += "<td style='color:"+precipitationShown[i][1]+"'>"+item[precipitationShown[i][0]].toFixed(1)+" mm</td>";
										tooltipText += "</tr>";
									}		
								}
								if (pressureShown.length>0) {
									for (var i=0; i<pressureShown.length; i++) {
										if (i===0) {
											tooltipText += "<tr style='border-top: 1pt solid #D1D1FF;'>";
											tooltipText += "<td>&nbsp;<img src='"+settings.basePath+"sites/all/modules/custom/ccis/images/d3/symbol_legende_pressure.png' width='19' height='16'></td>";
										} else {
											tooltipText += "<tr>";
											tooltipText += "<td></td>";
										}
										tooltipText += "<td style='color:"+pressureShown[i][1]+"'>&nbsp;"+pressureShown[i][2]+"</td>";
										tooltipText += "<td style='color:"+pressureShown[i][1]+"'>"+item[pressureShown[i][0]].toFixed(1)+" hPa</td>";
										tooltipText += "</tr>";
									}		
								}
								
							tooltipText += "</table>";

							// Create tooltip
							$("#d3_GraphDiv"+block).append("<div id='d3_tooltip"+block+"' class='d3_tooltipClass'</div>");		
							d3.select("#d3_tooltip"+block)			
								.style("left", (mouseX-x+5)+"px")
								.style("top", (height/3)+"px")
								.html(tooltipText);

							// Change direction of tooltip
							if (mouseX+($("#d3_tooltip"+block).width()) > x+widthDiv-margin.right-legendWidth) {
								d3.select("#d3_tooltip"+block)
									.style("left", (mouseX-x-5-$("#d3_tooltip"+block).width())+"px")
							}
						}
					}
				}
				// *** Diagram Hover function - END ***
				hover();
					
				// *** Print functions - START ***
				function printPreview() {
					var newWindow=window.open("","","");
					
					$(newWindow).ready(function(){
				
						// Clone Diagram
						clone = $("#d3_GraphDiv"+block).clone();
						// Remove background color and border
						clone[0].firstChild.setAttribute("style", "background-color: ; outline: ;");
						
						// Get html
						var html = clone.html();
						
						// Get the name of the Station
						var stationName = settings.ccis.stations[1].station_name;
						
						var printKeys = "";
						for (var i=0; i<temperatureShown.length; i++) {
							printKeys += "<br><div style='height:0px; width:10px; border-top: 5px solid "+temperatureShown[i][1]+"; border-bottom: 5px solid "+temperatureShown[i][1]+"; outline:solid 1px black; float:left; margin-left:5px; margin-right:5px; margin-top:3px;'></div><span style='font-size:14px'>"+temperatureShown[i][3]+" (&#8451;)</span>";
						}
						for (var i=0; i<precipitationShown.length; i++) {
							printKeys += "<br><div style='height:0px; width:10px; border-top: 5px solid "+precipitationShown[i][1]+"; border-bottom: 5px solid "+precipitationShown[i][1]+"; outline:solid 1px black; float:left; margin-left:5px; margin-right:5px; margin-top:3px;'></div><span style='font-size:14px'>"+precipitationShown[i][3]+" (mm)</span>";
						}
						for (var i=0; i<pressureShown.length; i++) {
							printKeys += "<br><div style='height:0px; width:10px; border-top: 5px solid "+pressureShown[i][1]+"; border-bottom: 5px solid "+pressureShown[i][1]+"; outline:solid 1px black; float:left; margin-left:5px; margin-right:5px; margin-top:3px;'></div><span style='font-size:14px'>"+pressureShown[i][3]+" (hPa)</span>";
						}
						newWindow.document.body.innerHTML = "<span style='font-size:16px'>Station: <b>"+stationName+"</b></span><br/>"+html+printKeys+"<br/><br/><button id='printButton"+block+"' class='d3_buttonId'>Print</button>  <button id='closePreviewWindow"+block+"' class='d3_buttonId'>Close Window</button>";

						// CSS for the Buttons (new window)
						$(newWindow.document).contents().find(".d3_buttonId")
							.css("border", "1px solid #dcdcdc")
							.css("-webkit-border-radius", "10px")
							.css("-moz-border-radius", "10px")
							.css("border-radius", "10px")
							.css("background-color", "#ededed")
							.css("color", "#211921")
							.css("-moz-box-shadow", "inset 0px -1px 0px 0px #877087")
							.css("-webkit-box-shadow", "inset 0px -1px 0px 0px #877087")
							.css("box-shadow", "inset 0px -1px 0px 0px #877087");		
						$(newWindow.document).contents().find(".d3_buttonId").hover( function(){
						     $(this).css("background-color", "#dfdfdf");
						},
						function(){
							$(this).css('background-color', '#ededed');
						});
						
						$(newWindow.document).contents().find("#printButton"+block).click(function() {
							printFunction();
						});	
						
						$(newWindow.document).contents().find("#closePreviewWindow"+block).click(function() {
							newWindow.close();
						});	
						
						function printFunction() {
							var printWindow=window.open("","","");
							$(newWindow).ready(function(){
								printWindow.document.body.innerHTML = "<span style='font-size:16px'>Station: <b>"+stationName+"</b></span><br/>"+html+printKeys;
								printWindow.print();
								printWindow.close();
							});			
						}
					});
				}
				// *** Print functions - END ***
			}
		});
	}
	// ***************************************
	// ********** DIAGRAM 2 - END ************
	// ***************************************

	// Select diagram
	if (settings.ccis.stations[0]) {
		if (settings.ccis.stations[0].selector === "ccis-weather-d3-block-1") {
			diagram1();
		}
	}
	if (settings.ccis.stations[1]) {
		if (settings.ccis.stations[1].selector === "ccis-weather-d3-block-2") {
			diagram2();
		}
	}
		
  // CUSTOM CODING END
  }
}
})(jQuery);