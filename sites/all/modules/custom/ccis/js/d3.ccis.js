(function($) {
Drupal.behaviors.ccis = {
  attach: function(d_context, settings) {
  // CUSTOM CODING START
	var dashboard_ID = '#ccis_dashboard';
	var csvDrupalBase = settings.basePath + 'weather';
	//var csvDrupalYear = csvDrupalBase + '/STATION/YYYY';
	var csvFilesystemBase = settings.basePath + 'sites/default/files/csv';
	//var csvFilesystemYear = csvFilesystemBase + '/FILENAME.csv';
	// Coding d3.time.format("%d-%b-%y").parse; ...

	// *** Variables - START ***
	var margin = {top: 20, right: 10, bottom: 25, left: 105, left_single: 35};
	var widthDiv = $("#ccis-weather-d3-block").width();
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
	
	// Groups of parameters including the colors, names and the icons
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
	// *** Variables - END ***

	// Parse the JSON
	d3.json(settings.ccis.stations[0].path, function(json) {
		if (json.length===0) {
			$("#ccis-weather-d3-block").html("");
		} else {
			$("#ccis-weather-d3-block").html("");

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
				$("#ccis-weather-d3-block").prepend("<div id='d3_GraphDiv'></div>");
				svg = d3.select("#d3_GraphDiv")
					.append("svg")
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
	 
				d3.select("svg")
					.append("path")
				  	.attr("id", "d3_path"+graphType+"ID")
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
					.attr("id", axisType+"id")
					.attr("class", "d3_yAxisClass")
					.style("font-size","10px")
					.attr("transform", "translate("+(axisPosition*(-margin.left_single))+",0)")
					.call(yAxisObj[axisType]);
				d3.select("#"+axisType+"id")
					.append("text")
					.html(yAxisLabel)
					.attr("class", "d3_yAxisText")
					.style("font-size","12px")
					.attr("transform", "translate ("+yAxisLabelOffset+", 0)");
				
				d3.select("#"+axisType+"id")
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
				$("#d3_tooltipLegend"+keyPlace)
					.css("position", "absolute")
					.css("right", (legendWidth-3)+"px")
					.css("top", (topPosition+50)+"px")
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
			$("#ccis-weather-d3-block").append("<div id='d3_legendDiv' class='d3_legendClass'></div>");
			
			$("#d3_legendDiv")
				.css("width", legendWidth-1)
				.css("height", height + margin.top + margin.bottom - heightPrintSelect);
				
			// Create DIVs for the keys
			// Temperature
			if (temperatureUsed.length>0) {
				$("#d3_legendDiv").append("<div id='d3_iconLegendTemp'><img src='"+settings.basePath+"sites/all/modules/custom/ccis/images/d3/symbol_legende_thermometer.png' width='7' height='21'></div>");
				$("#d3_legendDiv").append("<div id='d3_temperatureToggle' class='d3_toggleClass'><b><span id='d3_tempMinus' class='d3_minus'>[-]</span> Temperature <span class='d3_unitLegend'>[&#8451;]</span></b></div>");
				$("#d3_legendDiv").append("<div id='d3_keysDivTemperature'></div>");
				for (var i=0; i<temperatureUsed.length; i++) {
					function findTempChecked() {
						for (var k=0; k<temperatureShown.length; k++) {
							if (temperatureUsed[i][0]===temperatureShown[k][0]) {
								return "checked";
							}
						}
					}
					$("#d3_keysDivTemperature").append("<div id='d3_keysTemperature"+i+"' class='d3_keys'></div>");
					$("#d3_keysTemperature"+i).append("<div id='d3_keysTemperatureTick"+i+"' class='d3_keysTick'><input id='d3_checkboxTemperature"+i+"' type='checkbox' value='"+i+"' "+findTempChecked()+"></div>");			
					$("#d3_keysTemperature"+i).append("<div id='d3_keysTemperatureBoxText"+i+"' class='d3_keysBoxText'></div>");
					$("#d3_keysTemperatureBoxText"+i).append("<div id='keysTemperatureText"+i+"' class='d3_keysText'></div>");
					$("#keysTemperatureText"+i).append(temperatureUsed[i][2]);
					$("#d3_keysTemperatureBoxText"+i).append("<div id='keysTemperatureIcon"+i+"' class='d3_keysIcon'><img src='"+settings.basePath+"sites/all/modules/custom/ccis/images/d3/"+temperatureUsed[i][4]+"' width='25' height='15'></div>");
					(function(i) {
				    	$("#d3_keysTemperatureBoxText"+i)
				    		.hover(function(){
		    					$(this).css("cursor","default"); 
		    					$("#ccis-weather-d3-block").append("<div id='d3_tooltipLegend"+i+"'></div>"); 
		    					var topPosition = $("#d3_keysTemperatureBoxText"+i).position().top; 
		    					hoverLegend(topPosition, i, temperatureUsed[i][3]);
				    		},
		    				function() {$("#d3_tooltipLegend"+i).remove();});
				    })(i);
				}		
			}
			// Precipitation
			if (precipitationUsed.length>0) {
				$("#d3_legendDiv").append("<div id='d3_iconLegendPrec'><img src='"+settings.basePath+"sites/all/modules/custom/ccis/images/d3/symbol_legende_drop.png' width='11' height='17'></div>");
				$("#d3_legendDiv").append("<div id='d3_precipitationToggle' class='d3_toggleClass'><b><span id='d3_precMinus' class='d3_minus'>[-]</span> Precipitation <span class='d3_unitLegend'>[mm]</span></b></div>");
				$("#d3_legendDiv").append("<div id='d3_keysDivPrecipitation'></div>");
				for (var i=0; i<precipitationUsed.length; i++) {
					function findPrecChecked() {
						for (var k=0; k<precipitationShown.length; k++) {
							if (precipitationUsed[i][0]===precipitationShown[k][0]) {
								return "checked";
							}
						}
					}
					$("#d3_keysDivPrecipitation").append("<div id='d3_keysPrecipitation"+i+"' class='d3_keys'></div>");
					$("#d3_keysPrecipitation"+i).append("<div id='keysPrecipitationTick"+i+"' class='d3_keysTick'><input id='d3_checkboxPrecipitation"+i+"' type='checkbox' value='"+i+"' "+findPrecChecked()+"></div>");
					$("#d3_keysPrecipitation"+i).append("<div id='d3_keysPrecipitationBoxText"+i+"' class='d3_keysBoxText'></div>");			
					$("#d3_keysPrecipitationBoxText"+i).append("<div id='d3_keysPrecipitationText"+i+"' class='d3_keysText'></div>");
					$("#d3_keysPrecipitationText"+i).append(precipitationUsed[i][2]);
					$("#d3_keysPrecipitationBoxText"+i).append("<div id='d3_keysPrecipitationIcon"+i+"' class='d3_keysIcon'><img src='"+settings.basePath+"sites/all/modules/custom/ccis/images/d3/"+precipitationUsed[i][4]+"' width='25' height='15'></div>");
					(function(i) {
				    	$("#d3_keysPrecipitationBoxText"+i)
				    		.hover(function(){
		    					$(this).css("cursor","default"); 
		    					$("#ccis-weather-d3-block").append("<div id='d3_tooltipLegend"+i+"'></div>"); 
		    					var topPosition = $("#d3_keysPrecipitationBoxText"+i).position().top; 
		    					hoverLegend(topPosition, i, precipitationUsed[i][3]);
				    		},
		    				function() {$("#d3_tooltipLegend"+i).remove();});
				    })(i);
				}
			}
			// Pressure
			if (pressureUsed.length>0) {
				$("#d3_legendDiv").append("<div id='d3_iconLegendPress'><img src='"+settings.basePath+"sites/all/modules/custom/ccis/images/d3/symbol_legende_pressure.png' width='19' height='16'></div>");
				$("#d3_legendDiv").append("<div id='d3_pressureToggle' class='d3_toggleClass'><b><span id='pressMinus' class='d3_minus'>[-]</span> Pressure <span class='d3_unitLegend'>[hPa]</span></b></div>");
				$("#d3_legendDiv").append("<div id='d3_keysDivPressure'></div>");
				for (var i=0; i<pressureUsed.length; i++) {
					function findPressChecked() {
						for (var k=0; k<pressureShown.length; k++) {
							if (pressureUsed[i][0]===pressureShown[k][0]) {
								return "checked";
							}
						}
					}
					$("#d3_keysDivPressure").append("<div id='d3_keysPressure"+i+"' class='d3_keys'></div>");
					$("#d3_keysPressure"+i).append("<div id='d3_keysPressureTick"+i+"' class='d3_keysTick'><input id='d3_checkboxPressure"+i+"' type='checkbox' value='"+i+"' "+findPressChecked()+"></div>");
					$("#d3_keysPressure"+i).append("<div id='d3_keysPressureBoxText"+i+"' class='d3_keysBoxText'></div>");
					$("#d3_keysPressureBoxText"+i).append("<div id='d3_keysPressureText"+i+"' class='d3_keysText'></div>");
					$("#d3_keysPressureText"+i).append(pressureUsed[i][2]);
					$("#d3_keysPressureBoxText"+i).append("<div id='d3_keysPressureIcon"+i+"' class='d3_keysIcon'><img src='"+settings.basePath+"sites/all/modules/custom/ccis/images/d3/"+pressureUsed[i][4]+"' width='25' height='15'></div>");
					(function(i) {
				    	$("#d3_keysPressureBoxText"+i)
				    		.hover(function(){
		    					$(this).css("cursor","default"); 
		    					$("#ccis-weather-d3-block").append("<div id='d3_tooltipLegend"+i+"'></div>"); 
		    					var topPosition = $("#d3_keysPressureBoxText"+i).position().top; 
		    					hoverLegend(topPosition, i, pressureUsed[i][3]);
				    		},
		    				function() {$("#d3_tooltipLegend"+i).remove();});
				    })(i);
				}
			}
			
			// Maximum checkboxes checked: 4 / Minimum: 1
			var maxChecked = $("#ccis-weather-d3-block :checkbox:checked").length >= 4; 
			$("#ccis-weather-d3-block :checkbox").not(":checked").attr("disabled",maxChecked);
			var minChecked = $("#ccis-weather-d3-block :checkbox:checked").length <= 1;
			$("#ccis-weather-d3-block :checkbox:checked").attr("disabled",minChecked);
								
			// Change cursor on hover
			$(".d3_minus").hover(function() {
				$(this).css("cursor","pointer");
			});
			
			// Collapse
			$("#d3_tempMinus").click(function() {
				for (var i=0; i<temperatureUsed.length; i++) {
					$("#d3_keysTemperature"+i).toggle();
				} 
			}).toggle(function() {
				temperatureHidden=true;
				$(this).html("[+]");
				for (var i=0; i<temperatureUsed.length; i++) {
					if ($("#d3_checkboxTemperature"+i).is(":checked")) {
						$("#d3_keysTemperature"+i).css("display", "");
					}	
				}
			}, function() {
				temperatureHidden=false;
				$(this).html("[-]");
				for (var i=0; i<temperatureUsed.length; i++) {			
					$("#d3_keysTemperature"+i).css("display", "");
				}
			});
			$("#d3_precMinus").click(function() {
				for (var i=0; i<precipitationUsed.length; i++) {
					$("#d3_keysPrecipitation"+i).toggle();
				}
			}).toggle(function() {
				precipitationHidden=true;
				$(this).html("[+]");
				for (var i=0; i<precipitationUsed.length; i++) {
					if ($("#d3_checkboxPrecipitation"+i).is(":checked")) {
						$("#d3_keysPrecipitation"+i).css("display", "");
					}	
				}
			}, function() {
				precipitationHidden=false;
				$(this).html("[-]");
				for (var i=0; i<precipitationUsed.length; i++) {			
					$("#d3_keysPrecipitation"+i).css("display", "");
				}
			});
			$("#pressMinus").click(function() {
				for (var i=0; i<pressureUsed.length; i++) {
					$("#d3_keysPressure"+i).toggle();
				}
			}).toggle(function() {
				pressureHidden=true;
				$(this).html("[+]");
				for (var i=0; i<pressureUsed.length; i++) {
					if ($("#d3_checkboxPressure"+i).is(":checked")) {
						$("#d3_keysPressure"+i).css("display", "");
					}	
				}
			}, function() {
				pressureHidden=false;
				$(this).html("[-]");
				for (var i=0; i<pressureUsed.length; i++) {			
					$("#d3_keysPressure"+i).css("display", "");
				}
			});
			
			// Print preview button
			$("#ccis-weather-d3-block").append("<div id='printSelectWrapper'></div>");
			$("#printSelectWrapper")
				.css("width", legendWidth)
				.css("height", heightPrintSelect);
			$("#printSelectWrapper").append("<div id='d3_SelectDiagramsText'><i>Select up to 4 indices</i></div>");
			$("#printSelectWrapper").append("<div id='d3_printPreviewId'><img src='"+settings.basePath+"sites/all/modules/custom/ccis/images/d3/symbol_printer.png' width='16' height='16'><b><span style='font-size:14px;'>&nbsp;Print Preview</span></b></div>");
			$("#d3_printPreviewId").hover(function() {
				$(this).css("cursor","pointer");
			});
			$("#d3_printPreviewId").click(function() {
				printPreview();
			});
			
			// *** Redraw the Graph - START ***
			function redrawGraph() {

				if (document.getElementById("d3_keysDivTemperature")) {
					var findIDsTemperature = $("#d3_keysDivTemperature input:checkbox:checked").map(function(){		        
						return $(this).val();      
					});
					var findTicksArrayTemperature = findIDsTemperature.get();
				}
				if (document.getElementById("d3_keysDivPrecipitation")) {
					var findIDsPrecipitation = $("#d3_keysDivPrecipitation input:checkbox:checked").map(function(){		        
						return $(this).val();      
					});
					var findTicksArrayPrecipitation = findIDsPrecipitation.get();
				}
				if (document.getElementById("d3_keysDivPressure")) {
					var findIDsPressure = $("#d3_keysDivPressure input:checkbox:checked").map(function(){		        
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
				d3.select("#d3_GraphDiv").remove();
				
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
			$("#ccis-weather-d3-block :checkbox").click(function() {
				// Maximum checkboxes checked: 4 / Minimum: 1
				var maxChecked = $("#ccis-weather-d3-block :checkbox:checked").length >= 4; 
				$("#ccis-weather-d3-block :checkbox").not(":checked").attr("disabled",maxChecked);
				var minChecked = $("#ccis-weather-d3-block :checkbox:checked").length <= 1;
				$("#ccis-weather-d3-block :checkbox:checked").attr("disabled",minChecked);
				if (temperatureHidden===true) {
					for (var i=0; i<temperatureUsed.length; i++) {
						if ($("#d3_checkboxTemperature"+i).is(":checked")) {
							$("#d3_keysTemperature"+i).css("display", "");
						} else {
							$("#d3_keysTemperature"+i).css("display", "none");
						}
					}
				}
				if (precipitationHidden===true) {
					for (var i=0; i<precipitationUsed.length; i++) {
						if ($("#d3_checkboxPrecipitation"+i).is(":checked")) {
							$("#d3_keysPrecipitation"+i).css("display", "");
						} else {
							$("#d3_keysPrecipitation"+i).css("display", "none");
						}
					}
				}
				if (pressureHidden===true) {
					for (var i=0; i<pressureUsed.length; i++) {
						if ($("#d3_checkboxPressure"+i).is(":checked")) {
							$("#d3_keysPressure"+i).css("display", "");
						} else {
							$("#d3_keysPressure"+i).css("display", "none");
						}
					}
				}
				
				// Redraw graph
				redrawGraph();
			});
			
			// Maximize-minimize Window	
			$(".portlet-maximize").click(function(){
				// Get new width
				widthDiv = $("#ccis-weather-d3-block").width();
				width = widthDiv - margin.left - margin.right - legendWidth;
				height = width/2;
				$("#d3_legendDiv").css("height", height + margin.top + margin.bottom - heightPrintSelect);
				// Redraw graph
				redrawGraph();
			});
			
			// *** Diagram Hover function - START ***
			function hover() {
				var element;
				var position;
				var x;
				var y;
				
				$("#d3_GraphDiv").mousemove(function(event) {
					element = document.getElementById("d3_GraphDiv");
					position = element.getBoundingClientRect();
					x = position.left;
					y = position.top;
					
					mouseOver(event);
				});
				
				$("#d3_GraphDiv").mouseleave(function(event) {
					mouseLeave(event);
				});
				
				function mouseOver(event) {
					mouseX = event.pageX;
					mouseY = event.pageY;
					if (mouseX > (x+(margin.left_single*axis_selection)) && mouseX < (x+widthDiv-margin.right)) {
						$("#d3_hoverLine").show();
						$("#d3_tooltip").show();
						hoverLine.attr("x1", mouseX-x).attr("x2", mouseX-x);
						showLabels((mouseX-x-margin.left_single*axis_selection),500);
					} else {
						$("#d3_hoverLine").hide();
						$("#d3_tooltip").hide();
					}
				}
				
				function mouseLeave(event) {
					$("#d3_hoverLine").hide();
					$("#d3_tooltip").hide();
				}
					
				// Create line
				var hoverLineGroup = d3.select("svg").append("g")
					//.style("stroke", "black")
					.attr("id", "d3_hoverLine");
				// Add line to the group
				var hoverLine = hoverLineGroup
					.append("line")
					.attr("x1", 0).attr("x2", 0)
					.attr("y1", margin.top).attr("y2", height+margin.top);
						
				$("#d3_hoverLine").hide();
				
				var showLabels = function(xPosition, yPosition) {
					// Get the date on X-Axis for the current location
					var xValue = xScale.invert(xPosition);
					var bisect = d3.bisector(function(d) { return d.date; }).left;
					var item = data[bisect(data, xValue)];
					
					// Create content for tooltips
					if (item) {
						var tooltipText="";
						tooltipText = "<table style='margin:0px;'>";
							
							tooltipText += "<tr>";
								tooltipText += "<td>&nbsp;<img src='"+settings.basePath+"sites/all/modules/custom/ccis/images/d3/symbol_infobereich_clock.png' width='11' height='12'></td>";
								tooltipText += "<td>&nbsp;Date: </td>";
								tooltipText += "<td><b>"+item.date.toDateString()+"</b></td>";
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
						$("#d3_GraphDiv").append("<div id='d3_tooltip'</div>");		
						d3.select("#d3_tooltip")			
							.style("left", (mouseX-x+5)+"px")
							.style("top", (height/2)+"px")
							.html(tooltipText);

						// Change direction of tooltip
						if (mouseX+($("#d3_tooltip").width()) > x+widthDiv-margin.right-legendWidth) {
							d3.select("#d3_tooltip")
								.style("left", (mouseX-x-5-$("#d3_tooltip").width())+"px")
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
					var clone = $("#d3_GraphDiv").clone();
					// Remove background color and border
					clone[0].firstChild.setAttribute("style", "background-color: ; outline: ;");
					
					// Get html
					var html = clone.html();
					
					// Get the name of the Station
					var stationName = document.getElementById("ccis-station-info-block").getElementsByClassName("node-weather-station")[0].children[0].children[0].innerHTML;
					
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
					newWindow.document.body.innerHTML = "<span style='font-size:16px'>Station: <b>"+stationName+"</b></span><br/>"+html+printKeys+"<br/><br/><button id='printButton' class='d3_buttonId'>Print</button>  <button id='closePreviewWindow' class='d3_buttonId'>Close Window</button>";
					
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
					
					$(newWindow.document).contents().find("#printButton").click(function() {
						printFunction();
					});	
					
					$(newWindow.document).contents().find("#closePreviewWindow").click(function() {
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
  // CUSTOM CODING END
  }
}
})(jQuery);