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
	
	var margin = {top: 20, right: 10, bottom: 25, left: 165, left_single: 55};
	var widthDiv = $("#ccis-weather-d3-block").width();
	var width = widthDiv - margin.left - margin.right;
	var height = 250;
	var axis_sum = 3;
	var axis_selection;
	var svg;
	
	// Groups of parameters including the colors
	var temperature = [
   	    ["avg_temp", "orange", "Average mean temperature"],
   	    ["avg_min_temp", "green", "Average min temperature"],
   	    ["avg_max_temp", "red", "Average max temperature"]
   	];
   	var precipitation = [
   	    ["avg_prec", "blue", "Average precipitation amount"]
   	];
   	var pressure = [
   	    ["avg_press", "orchid", "Average sea level pressure"]
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
			
			// Create an array per group with the parameters used, the colors and the legend names
			for (var i=2; i<dataKeysArray.length; i++) {
				for (var k=0; k<temperature.length; k++) {
					if (dataKeysArray[i]===temperature[k][0]) {
						temperatureUsed.push([temperature[k][0], temperature[k][1], temperature[k][2]]);
					}
				}
				for (var k=0; k<precipitation.length; k++) {
					if (dataKeysArray[i]===precipitation[k][0]) {
						precipitationUsed.push([precipitation[k][0], precipitation[k][1], precipitation[k][2]]);
					}
				}
				for (var k=0; k<pressure.length; k++) {
					if (dataKeysArray[i]===pressure[k][0]) {
						pressureUsed.push([pressure[k][0], pressure[k][1], pressure[k][2]]);
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
				//.domain([minTempY, maxTempY])
				.domain([30, maxTempY])	// Temporary - Wrong Temperature Data
				.range([height, 0]);
			var yScalePrec = d3.scale.linear()
				//.domain([minPrecY, maxPrecY])
				.domain([0, maxPrecY]) // Temporary - Wrong Precipitation Data
				.range([height, 0]);
			var yScalePress = d3.scale.linear()
				//.domain([minPressY, maxPressY])
				.domain([9800, maxPressY]) // Temporary - Wrong Pressure Data
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
				$("#ccis-weather-d3-block").prepend("<div id='d3GraphDiv'></div>");	
				svg = d3.select("#d3GraphDiv")
					.style("position", "relative")
					.append("svg")
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
					.x(function(d){return xScale(d.date)})
					.y(function(d){return yscaleType(d[graphType])});
	 
				d3.select("svg")
					.append("path")
				  	.attr("id", "path"+graphType+"ID")
					.attr("d", graphObj[graphType](data))
					.attr("stroke", color)
					.attr("stroke-width", "1")
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
				yAxisObj[axisType] = d3.svg.axis()
					.scale(scaleType)
					.orient("left")
					.ticks(5);
				svg.append("g")
					.attr("id", axisType+"id")
					.attr("class", "yAxisClass")
					.style("font-family", "Arial")
					.style("font-size","10px")
					.attr("transform", "translate("+(axisPosition*(-margin.left_single))+",0)")
					.call(yAxisObj[axisType]);
				d3.select("#"+axisType+"id")
					.append("text")
					.text(label)
					.style("font-size","12px")
					.style("font-family", "Arial")
					.attr("transform", "rotate (-90 ,90,125)");
			}
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
					.attr("class", "xAxisLine")
					.style("font-family", "Arial")
					.style("font-size","10px")
					.attr("transform", "translate(0," + height + ")")
					.call(xAxis);
			}
			xAxisDraw();
		  
			// Add CSS to the axes
			function addCss() {
				$(".yAxisClass path, .yAxisClass line, .xAxisLine path, .xAxisLine line")
				  .css("fill", "none")
				  .css("stroke", "#000")
				  .css("shape-rendering", "crispEdges");
			}
			addCss();
	
			// Create DIVs for the keys
			if (temperatureUsed.length>0) {
				$("#ccis-weather-d3-block").append("<div id='temperatureToggle'><b><span id='tempMinus'>[-]</span> Temperature</b></div>");
				$("#ccis-weather-d3-block").append("<div id='keysDivTemperature'></div>");
				for (var i=0; i<temperatureUsed.length; i++) {
					function findTempChecked() {
						for (var k=0; k<temperatureShown.length; k++) {
							if (temperatureUsed[i][0]===temperatureShown[k][0]) {
								return "checked";
							}
						}
					}
					$("#keysDivTemperature").append("<div id='keysTemperature"+i+"'></div>");
					$("#keysTemperature"+i).css("margin-left", "10px");
					$("#keysTemperature"+i).append("<div id='keysTemperatureTick"+i+"' style='float:left'><input id='checkboxTemperature"+i+"' type='checkbox' value='"+i+"' "+findTempChecked()+"></div>");
					$("#keysTemperature"+i).append("<div id='keysTemperatureBox"+i+"' class='keysBox'></div>");
					$("#keysTemperatureBox"+i).css("background-color", temperatureUsed[i][1]);
					$("#keysTemperature"+i).append("<div id='keysTemperatureText"+i+"'></div>");
					$("#keysTemperatureText"+i).append(temperatureUsed[i][2]);
				}		
			}
			if (precipitationUsed.length>0) {
				$("#ccis-weather-d3-block").append("<div id='precipitationToggle'><b><span id='precMinus'>[-]</span> Precipitation</b></div>");
				$("#ccis-weather-d3-block").append("<div id='keysDivPrecipitation'></div>");
				for (var i=0; i<precipitationUsed.length; i++) {
					function findPrecChecked() {
						for (var k=0; k<precipitationShown.length; k++) {
							if (precipitationUsed[i][0]===precipitationShown[k][0]) {
								return "checked";
							}
						}
					}
					$("#keysDivPrecipitation").append("<div id='keysPrecipitation"+i+"'></div>");
					$("#keysPrecipitation"+i).css("margin-left", "10px");
					$("#keysPrecipitation"+i).append("<div id='keysPrecipitationTick"+i+"' style='float:left'><input id='checkboxPrecipitation"+i+"' type='checkbox' value='"+i+"' "+findPrecChecked()+"></div>");
					$("#keysPrecipitation"+i).append("<div id='keysPrecipitationBox"+i+"' class='keysBox'></div>");
					$("#keysPrecipitationBox"+i).css("background-color", precipitationUsed[i][1]);
					$("#keysPrecipitation"+i).append("<div id='keysPrecipitationText"+i+"'></div>");
					$("#keysPrecipitationText"+i).append(precipitationUsed[i][2]);
				}
			}
			if (pressureUsed.length>0) {
				$("#ccis-weather-d3-block").append("<div id='pressureToggle'><b><span id='pressMinus'>[-]</span> Pressure</b></div>");	
				$("#ccis-weather-d3-block").append("<div id='keysDivPressure'></div>");
				for (var i=0; i<pressureUsed.length; i++) {
					function findPressChecked() {
						for (var k=0; k<pressureShown.length; k++) {
							if (pressureUsed[i][0]===pressureShown[k][0]) {
								return "checked";
							}
						}
					}
					$("#keysDivPressure").append("<div id='keysPressure"+i+"'></div>");
					$("#keysPressure"+i).css("margin-left", "10px");
					$("#keysPressure"+i).append("<div id='keysPressureTick"+i+"' style='float:left'><input id='checkboxPressure"+i+"' type='checkbox' value='"+i+"' "+findPressChecked()+"></div>");
					$("#keysPressure"+i).append("<div id='keysPressureBox"+i+"' class='keysBox'></div>");
					$("#keysPressureBox"+i).css("background-color", pressureUsed[i][1]);
					$("#keysPressure"+i).append("<div id='keysPressureText"+i+"'></div>");
					$("#keysPressureText"+i).append(pressureUsed[i][2]);
				}
			}
			$("#ccis-weather-d3-block").append("<i>Select up to 4 diagrams</i>");

			$(".keysBox")
				.css("height", "10px")
			  	.css("width", "10px")
			  	.css("outline", "solid 1px black")
			  	.css("float", "left")
			  	.css("margin-left", "5px")
			  	.css("margin-right", "5px")
			  	.css("margin-top", "5px");
			
			// Maximum checkboxes checked: 4
			var maxChecked = $("#ccis-weather-d3-block :checkbox:checked").length >= 4; 
			$("#ccis-weather-d3-block :checkbox").not(":checked").attr("disabled",maxChecked);
			$("#keysDivTemperature").show();
					
			// Collapse
			$("#tempMinus").click(function() {
				$("#keysDivTemperature").toggle();
			}).toggle(function() {
				$(this).html("[+]");
			}, function() {
				$(this).html("[-]");
			});
			$("#precMinus").click(function() {
				$("#keysDivPrecipitation").toggle();
			}).toggle(function() {
				$(this).html("[+]");
			}, function() {
				$(this).html("[-]");
			});
			$("#pressMinus").click(function() {
				$("#keysDivPressure").toggle();
			}).toggle(function() {
				$(this).html("[+]");
			}, function() {
				$(this).html("[-]");
			});
			
			// *** Redraw the Graph - START ***
			function redrawGraph() {

				if (document.getElementById("keysDivTemperature")) {
					var findIDsTemperature = $("#keysDivTemperature input:checkbox:checked").map(function(){		        
						return $(this).val();      
					});
					var findTicksArrayTemperature = findIDsTemperature.get();
				}
				if (document.getElementById("keysDivPrecipitation")) {
					var findIDsPrecipitation = $("#keysDivPrecipitation input:checkbox:checked").map(function(){		        
						return $(this).val();      
					});
					var findTicksArrayPrecipitation = findIDsPrecipitation.get();
				}
				if (document.getElementById("keysDivPressure")) {
					var findIDsPressure = $("#keysDivPressure input:checkbox:checked").map(function(){		        
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
				d3.select("#d3GraphDiv").remove();
				
				// Update X range
				xScale.range([0, (width+(margin.left_single*axis_sum)-(margin.left_single*axis_selection))]);
				
				// Create again the svg
				createSvg();
				
				// Create again the X axis
				xAxisDraw();

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
					//yScaleTemp.domain([minTempY, maxTempY]);
					yScaleTemp.domain([30, maxTempY]); // Temporary - Wrong Temperature Data
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
					//yScalePrec.domain([minPrecY, maxPrecY])
					yScalePrec.domain([0, maxPrecY]) // Temporary - Wrong Precipitation Data
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
					//yScalePress.domain([minPressY, maxPressY])
					yScalePress.domain([9800, maxPressY]) // Temporary - Wrong Pressure Data
				}

				// Redraw Y-Axes
				for (var i=0; i<yAxisArray.length; i++) {
					yAxisDraw(yAxisArray[i][0], yAxisArray[i][1], yAxisArray[i][2], i);
				}
				
				// Add again CSS for the axes
				addCss();
				
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
				
				// Call hover function
				hover();
			}	
			// *** Redraw the Graph - END *** 
			
			// Click checkbox
			$("#ccis-weather-d3-block :checkbox").click(function() {
				// Maximum checkboxes checked: 4
				var maxChecked = $("#ccis-weather-d3-block :checkbox:checked").length >= 4; 
				$("#ccis-weather-d3-block :checkbox").not(":checked").attr("disabled",maxChecked);
				// Redraw the graph
				redrawGraph();
			});
			
			// Maximise-minimize Window	
			$(".portlet-maximize").click(function(){
				// Get new width
				widthDiv = $("#ccis-weather-d3-block").width();
				width = widthDiv - margin.left - margin.right;
				// Redraw graph
				redrawGraph();
			});
			
			// *** Hover function - START ***
			function hover() {
				var element;
				var position;
				var x;
				var y;
				
				$("#d3GraphDiv").mousemove(function(event) {
					element = document.getElementById("d3GraphDiv");
					position = element.getBoundingClientRect();
					x = position.left;
					y = position.top;
					
					mouseOver(event);
				});
				
				$("#d3GraphDiv").mouseleave(function(event) {
					mouseLeave(event);
				});
				
				function mouseOver(event) {
					mouseX = event.pageX;
					mouseY = event.pageY;
					if (mouseX > (x+(margin.left_single*axis_selection)) && mouseX < (x+widthDiv-margin.right)) {
						$("#hoverLine").show();
						$("#tooltip").show();
						hoverLine.attr("x1", mouseX-x).attr("x2", mouseX-x);
						showLabels((mouseX-x-margin.left_single*axis_selection),500);
					} else {
						$("#hoverLine").hide();
						$("#tooltip").hide();
					}
				}
				
				function mouseLeave(event) {
					$("#hoverLine").hide();
					$("#tooltip").hide();
				}
					
				// Create line
				var hoverLineGroup = d3.select("svg").append("g")
					.style("stroke", "black")
					.attr("id", "hoverLine");
				// Add line to the group
				var hoverLine = hoverLineGroup
					.append("line")
					.attr("x1", 0).attr("x2", 0)
					.attr("y1", margin.top).attr("y2", height+margin.top);
						
				$("#hoverLine").hide();
				
				var showLabels = function(xPosition, yPosition) {
					// Get the date on X-Axis for the current location
					var xValue = xScale.invert(xPosition);
					var bisect = d3.bisector(function(d) { return d.date; }).left;
					var item = data[bisect(data, xValue)];
					
					if (item) {
						var tooltipText="";
						tooltipText="Date: <b>"+item.date.toDateString()+"</b>";
						for (var i=0; i<temperatureShown.length; i++) {
							tooltipText += "<br><div id='tooltipBox"+i+
							"' style='height:10px; width:10px; outline:solid 1px black; background-color:"+temperatureShown[i][1]+"; float:left; margin-left:5px; margin-right:5px; margin-top:3px;'></div>"+temperatureShown[i][2]+": "+item[temperatureShown[i][0]].toFixed(1);
						}
						for (var i=0; i<precipitationShown.length; i++) {
							tooltipText += "<br><div id='tooltipBox"+i+
							"' style='height:10px; width:10px; outline:solid 1px black; background-color:"+precipitationShown[i][1]+"; float:left; margin-left:5px; margin-right:5px; margin-top:3px;'></div>"+precipitationShown[i][2]+": "+item[precipitationShown[i][0]].toFixed(1);
						}
						for (var i=0; i<pressureShown.length; i++) {
							tooltipText += "<br><div id='tooltipBox"+i+
							"' style='height:10px; width:10px; outline:solid 1px black; background-color:"+pressureShown[i][1]+"; float:left; margin-left:5px; margin-right:5px; margin-top:3px;'></div>"+pressureShown[i][2]+": "+item[pressureShown[i][0]].toFixed(1);
						}
	
						// Create tooltip
						$("#d3GraphDiv").append("<div id='tooltip'</div>");				
						d3.select("#tooltip")
							.style("position", "absolute")
							.style("left", (mouseX-x+5)+"px")
							.style("top", (height/2)+"px")
							.style("width", "210px")
							.style("height", "auto")
							.style("background-color", "white")
							.style("border", "solid 1px black")
							.style("font-size","11px")
							.style("font-family", "Arial")
							.html(tooltipText);
	
						// Change direction of tooltip
						if (mouseX+($("#tooltip").width()) > x+widthDiv-margin.right) {
							d3.select("#tooltip")
								.style("left", (mouseX-x-5-$("#tooltip").width())+"px")
						}
					}
				}
			}
			// *** Hover function - END ***
			hover();
				
			// *** Print functions - START ***
			$("#ccis-weather-d3-block").append("<br/><br/><button id='printPreviewId' class='buttonId'>Print Preview</button>");
			
			// CSS for the Buttons (initial window)
			$(".buttonId")
				.css("border", "1px solid #dcdcdc")
				.css("-webkit-border-radius", "10px")
				.css("-moz-border-radius", "10px")
				.css("border-radius", "10px")
				.css("background-color", "#ededed")
				.css("color", "#211921")
				.css("-moz-box-shadow", "inset 0px -1px 0px 0px #877087")
				.css("-webkit-box-shadow", "inset 0px -1px 0px 0px #877087")
				.css("box-shadow", "inset 0px -1px 0px 0px #877087");		
			$(".buttonId").hover( function(){
			     $(this).css("background-color", "#dfdfdf");
			},
			function(){
				$(this).css('background-color', '#ededed');
			});
							
			$("#printPreviewId").click(function() {
				printPreview();
			});
			function printPreview() {
				var newWindow=window.open("","","");
				
				$(newWindow).ready(function(){
			
					// Get the Diagram
					var html = d3.select("svg")
				        .node().parentNode.innerHTML;
					
					// Get the name of the Station
					var stationName = document.getElementById("ccis-station-info-block").getElementsByClassName("views-field views-field-title")[0].children[0].innerHTML;

					var printKeys = "";
					for (var i=0; i<temperatureShown.length; i++) {
						printKeys += "<br><div style='height:0px; width:10px; border-top: 5px solid "+temperatureShown[i][1]+"; border-bottom: 5px solid "+temperatureShown[i][1]+"; outline:solid 1px black; float:left; margin-left:5px; margin-right:5px; margin-top:3px;'></div><span style='font-size:14px'>"+temperatureShown[i][2]+"</span>";
					}
					for (var i=0; i<precipitationShown.length; i++) {
						printKeys += "<br><div style='height:0px; width:10px; border-top: 5px solid "+precipitationShown[i][1]+"; border-bottom: 5px solid "+precipitationShown[i][1]+"; outline:solid 1px black; float:left; margin-left:5px; margin-right:5px; margin-top:3px;'></div><span style='font-size:14px'>"+precipitationShown[i][2]+"</span>";
}
					for (var i=0; i<pressureShown.length; i++) {
						printKeys += "<br><div style='height:0px; width:10px; border-top: 5px solid "+pressureShown[i][1]+"; border-bottom: 5px solid "+pressureShown[i][1]+"; outline:solid 1px black; float:left; margin-left:5px; margin-right:5px; margin-top:3px;'></div><span style='font-size:14px'>"+pressureShown[i][2]+"</span>";
}
					newWindow.document.body.innerHTML = "<span style='font-size:16px'>Station: <b>"+stationName+"</b></span><br/>"+html+printKeys+"<br/><br/><button id='printButton' class='buttonId'>Print</button>  <button id='closePreviewWindow' class='buttonId'>Close Window</button>";
					
					// CSS for the Buttons (new window)
					$(newWindow.document).contents().find(".buttonId")
						.css("border", "1px solid #dcdcdc")
						.css("-webkit-border-radius", "10px")
						.css("-moz-border-radius", "10px")
						.css("border-radius", "10px")
						.css("background-color", "#ededed")
						.css("color", "#211921")
						.css("-moz-box-shadow", "inset 0px -1px 0px 0px #877087")
						.css("-webkit-box-shadow", "inset 0px -1px 0px 0px #877087")
						.css("box-shadow", "inset 0px -1px 0px 0px #877087");		
					$(newWindow.document).contents().find(".buttonId").hover( function(){
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