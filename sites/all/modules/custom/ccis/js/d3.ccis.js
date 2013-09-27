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
	
	var barWidth = 5;
	var margin = {top: 20, right: 10, bottom: 25, left: 165, left_single: 55};
	var widthDiv = $("#ccis-weather-d3-block").width();
	var width = widthDiv - margin.left - margin.right;
	var height = 250;
	var axis_sum = 3;
	var axis_selection = 3;
	var svg;
	var arrayColors = [
	        ["avg_temp", "orange"],
	        ["avg_prec", "#CAE1FF"],
	        ["avg_press", "orchid"],
	        ["avg_min_temp", "green"],
	        ["avg_max_temp", "red"]
        ];
	var mouseX;
	var mouseY;

	// Parse the JSON
	d3.json(settings.ccis.stations[0].path, function(json) {
		if (json.length===0) {
			$("#ccis-weather-d3-block").html("");
		} else {
			$("#ccis-weather-d3-block").html("");
			var data = json.map(function(d) {
				return {
					//date: d3.time.format("%Y-%m-%d %H:%M:%S").parse(d.date.slice(0,-3), // Datum & Zeit ohne Zeitzone
					date: d3.time.format("%Y-%m-%d").parse(d.date.slice(0,-12)), // Nur Datum
					avg_temp: parseFloat(d.avg_temp),
					avg_prec: parseFloat(d.avg_prec),
					avg_press: parseFloat(d.avg_press),
					avg_min_temp: parseFloat(d.avg_min_temp),
					avg_max_temp: parseFloat(d.avg_max_temp)
				};        
			});
			
			var arrayNames = [
	                ["avg_temp", settings.ccis.legends[2]],
	                ["avg_prec", settings.ccis.legends[3]],
	                ["avg_press", settings.ccis.legends[4],],
	                ["avg_min_temp", settings.ccis.legends[5]],
	                ["avg_max_temp", settings.ccis.legends[6]]
                ];

			// X Scale
			var xScale = d3.time.scale()
	  			.domain(d3.extent(data, function(d) { return d.date; }))
	  			.range([0, (width+(margin.left_single*axis_sum)-(margin.left_single*axis_selection))]);
	  		
			// Y Scales
			var minTempY = d3.min(data, function(d) { return Math.min(d.avg_temp, d.avg_min_temp, d.avg_max_temp); });  
			var maxTempY = d3.max(data, function(d) { return Math.max(d.avg_temp, d.avg_min_temp, d.avg_max_temp); });			
			var yScaleTemp = d3.scale.linear()
				//.domain([minTempY, maxTempY])
				.domain([30, maxTempY])	// Temporary - Wrong Temperature Data
				.range([height, 0]);
			var minPrecY = d3.min(data, function(d) { return d.avg_prec; });
			var maxPrecY = d3.max(data, function(d) { return d.avg_prec; });
			var yScalePrec = d3.scale.linear()
				//.domain([minPrecY, maxPrecY])
				.domain([0, maxPrecY]) // Temporary - Wrong Precipitation Data
				.range([height, 0]);
			var minPressY = d3.min(data, function(d) { return d.avg_press; });
			var maxPressY = d3.max(data, function(d) { return d.avg_press; });
			var yScalePress = d3.scale.linear()
				//.domain([minPressY, maxPressY])
				.domain([9800, maxPressY]) // Temporary - Wrong Pressure Data
				.range([height, 0]);
			
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
		  
			// ***CREATE THE GRAPHS - START***
			
			// Average mean temperature
			function avgTempGraph(){
				var avgTemp = d3.svg.line()
					.x(function(d){return xScale(d.date)})
					.y(function(d){return yScaleTemp(d.avg_temp)});
		 
				d3.select("svg")
					.append("path")
				  	.attr("id", "pathAvgTempID")
					.attr("d", avgTemp(data))
					.attr("stroke", arrayColors[0][1])
					.attr("stroke-width", "1")
					.attr("fill", "none")
					.attr("transform", "translate(" + (margin.left-((margin.left_single*axis_sum)-(margin.left_single*axis_selection))) + "," + margin.top + ")");		  
			}	  
			avgTempGraph();
		  
			// Average precipitation amount
			function avgPrecGraph(){
				// Bars
				svg.selectAll("rect")
				   .data(data)
				   .enter()
				   .append("rect")
				   .attr("x", function(d) {return xScale(d.date)-barWidth;})
				   .attr("y", function(d) {return yScalePrec(d.avg_prec)-1;})
				   .attr("width", barWidth+"px")
				   .attr("height", function(d) {return height-yScalePrec(d.avg_prec);})
				   .attr("fill", arrayColors[1][1]);
			}	  
			avgPrecGraph();
			
			// Average sea level pressure
			function avgPressGraph(){
				var avgPress = d3.svg.line()
					.x(function(d){return xScale(d.date)})
					.y(function(d){return yScalePress(d.avg_press)});
		 
				  d3.select("svg")
				  	.append("path")
				  	.attr("id", "pathAvgPressID")
					.attr("d", avgPress(data))
					.attr("stroke", arrayColors[2][1])
					.attr("stroke-width", "1")
					.attr("fill", "none")
					.attr("transform", "translate(" + (margin.left-((margin.left_single*axis_sum)-(margin.left_single*axis_selection))) + "," + margin.top + ")");
			}	  
			avgPressGraph();
			
			// Average min temperature
			function avgMinTempGraph(){
				var avgMinTemp = d3.svg.line()
					.x(function(d){return xScale(d.date)})
					.y(function(d){return yScaleTemp(d.avg_min_temp)});
		 
				d3.select("svg")
					.append("path")
				  	.attr("id", "pathAvgMinTempID")
					.attr("d", avgMinTemp(data))
					.attr("stroke", arrayColors[3][1])
					.attr("stroke-width", "1")
					.attr("fill", "none")
					.attr("transform", "translate(" + (margin.left-((margin.left_single*axis_sum)-(margin.left_single*axis_selection))) + "," + margin.top + ")");
			}	  
			avgMinTempGraph();
			
			// Average max temperature
			function avgMaxTempGraph(){
				var avgMaxTemp = d3.svg.line()
					.x(function(d){return xScale(d.date)})
					.y(function(d){return yScaleTemp(d.avg_max_temp)});
		 
				d3.select("svg")
					.append("path")
				  	.attr("id", "pathAvgMaxTempID")
					.attr("d", avgMaxTemp(data))
					.attr("stroke", arrayColors[4][1])
					.attr("stroke-width", "1")
					.attr("fill", "none")
					.attr("transform", "translate(" + (margin.left-((margin.left_single*axis_sum)-(margin.left_single*axis_selection))) + "," + margin.top + ")");
			}	  
			avgMaxTempGraph();
			
			// ***CREATE THE GRAPHS - END***
			
			// Create Y Axes
			function yAxisTempDraw(axisPosition) {
				var yAxisTemp = d3.svg.axis()
					.scale(yScaleTemp)
					.orient("left")
					.ticks(5);
				svg.append("g")
					.attr("id", "yAxisLineTemp")
					.attr("class", "yAxisClass")
					.style("font-family", "Arial")
					.style("font-size","10px")
					.attr("transform", "translate("+(axisPosition*(-margin.left_single)-barWidth)+",0)")
					.call(yAxisTemp);
				d3.select("#yAxisLineTemp")
					.append("text")
					.text("Temperature")
					.style("font-size","12px")
					.style("font-family", "Arial")
					.attr("transform", "rotate (-90 ,90,125)");
			}
			yAxisTempDraw(0);
			function yAxisPrecDraw(axisPosition) {
				var yAxisPrec = d3.svg.axis()
					.scale(yScalePrec)
					.orient("left")
					.ticks(5);
				svg.append("g")
					.attr("id", "yAxisLinePrec")
					.attr("class", "yAxisClass")
					.style("font-family", "Arial")
					.style("font-size","10px")
					.attr("transform", "translate("+(axisPosition*(-margin.left_single)-barWidth)+",0)")
					.call(yAxisPrec);
				d3.select("#yAxisLinePrec")
					.append("text")
					.text("Precipitation")
					.style("font-size","12px")
					.style("font-family", "Arial")
					.attr("transform", "rotate (-90 ,90,125)");
			}
			yAxisPrecDraw(1);
			function yAxisPressDraw(axisPosition) {
				var yAxisPress = d3.svg.axis()
					.scale(yScalePress)
					.orient("left")
					.tickFormat(d3.format('.0f'))
					.ticks(5);
				svg.append("g")
					.attr("id", "yAxisLinePress")
					.attr("class", "yAxisClass")
					.style("font-family", "Arial")
					.style("font-size","10px")
					.attr("transform", "translate("+(axisPosition*(-margin.left_single)-barWidth)+",0)")
					.call(yAxisPress);
				d3.select("#yAxisLinePress")
					.append("text")
					.text("Sea Level Pressure")
					.style("font-size","12px")
					.style("font-family", "Arial")
					.attr("transform", "rotate (-90 ,85,125)");
			}
			yAxisPressDraw(2);	
			
			// Create X Axis
			function createxAxis() {
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
			createxAxis();
		  
			// Add CSS
			function addCss() {
				$(".yAxisClass path, .yAxisClass line, .xAxisLine path, .xAxisLine line")
				  .css("fill", "none")
				  .css("stroke", "#000")
				  .css("shape-rendering", "crispEdges");
			}
			addCss();
			
			// Create DIVs for the keys
			for (var i=1; i<6; i++) {
				$("#ccis-weather-d3-block").append("<div id='keysDiv"+i+"'></div>");
				$("#keysDiv"+i).append("<div id='keysTick"+i+"' style='float:left'><input id='checkbox"+i+"' type='checkbox' value='"+i+"'checked='checked'></div>");
				$("#keysDiv"+i).append("<div id='keysBox"+i+"'></div>");
				$("#keysBox"+i)
					.css("height", "10px")
				  	.css("width", "10px")
				  	.css("outline", "solid 1px black")
				  	.css("background-color", arrayColors[i-1][1])
				  	.css("float", "left")
				  	.css("margin-left", "5px")
				  	.css("margin-right", "5px")
				  	.css("margin-top", "5px");
				$("#keysDiv"+i).append("<div id='keysText"+i+"'></div>");
				$("#keysText"+i).append(settings.ccis.legends[i+1]);			
			}
			
			// Redraw-Graphs functions
			function graph1(){
				avgTempGraph();
			}
			function graph2(){
				avgPrecGraph();
			}
			function graph3(){
				avgPressGraph();
			}
			function graph4(){
				avgMinTempGraph();
			}
			function graph5(){
				avgMaxTempGraph();
			}
			
			var graphsArray = [graph1, graph2, graph3, graph4, graph5];
			
			// Redraw the Graph
			function redrawGraph() {
				var findIDs = $("#ccis-weather-d3-block input:checkbox:checked").map(function(){		        
					return $(this).val();      
				});
				var findTicksArray = findIDs.get();
				
				//How many Y-Axes we need
				axis_selection=0;
				var temperature_selection=false;		
				for (var i=0; i<findTicksArray.length; i++) {
			  		var tick_selection = parseInt(findTicksArray[i]);
					if (tick_selection===1) {
						axis_selection=axis_selection+1;
						temperature_selection=true;
					} else if (tick_selection===2) {
						axis_selection=axis_selection+1;
					} else if (tick_selection===3) {				
						axis_selection=axis_selection+1;	
					} else if (tick_selection===4 && temperature_selection===true) {
						
					} else if (tick_selection===4 && temperature_selection===false) {
						axis_selection=axis_selection+1;
						temperature_selection=true;			
					} else if (tick_selection===5 && temperature_selection===true) {
						
					} else if (tick_selection===5 && temperature_selection===false) {
						axis_selection=axis_selection+1;
						temperature_selection=true;
					} else {}	
				}

				d3.select("#d3GraphDiv").remove();
				xScale.range([0, (width+(margin.left_single*axis_sum)-(margin.left_single*axis_selection))]);
				createSvg();
				createxAxis();
				
				// Update Y-Axes
				var temp_axis=false;
				var prec_axis=false;
				var press_axis=false;
				
				arrayNames=[];	// For the tooltips
				var temperatureArrayNames=[];
				for (var i=0; i<findTicksArray.length; i++) {
					var tick = parseInt(findTicksArray[i]);
					if (tick===1) {
						temp_axis=true;
						temperatureArrayNames.push("avg_temp");
						arrayNames.push(["avg_temp", settings.ccis.legends[2]]);
					} else if (tick===2) {
						prec_axis=true;
						arrayNames.push(["avg_prec", settings.ccis.legends[3]]);
					} else if (tick===3) {
						press_axis=true;
						arrayNames.push(["avg_press", settings.ccis.legends[4]]);
					} else if (tick===4) {
						temp_axis=true;
						temperatureArrayNames.push("avg_min_temp");
						arrayNames.push(["avg_min_temp", settings.ccis.legends[5]]);
					} else if (tick===5) {
						temp_axis=true;
						temperatureArrayNames.push("avg_max_temp");
						arrayNames.push(["avg_max_temp", settings.ccis.legends[6]]);
					} else {}
				}

				// Update temperature domain
				var temperatureArrayMax=[];
				var minTempY = d3.min(data, function(d) { return Math.min(d.avg_temp, d.avg_min_temp, d.avg_max_temp); }); 
				for (var i=0; i<temperatureArrayNames.length; i++) {
					temperatureArrayMax.push(d3.max(data, function(d) { return Math.max(d[temperatureArrayNames[i]]); }) );
				}
				maxTempY = d3.max(temperatureArrayMax);
				//yScaleTemp.domain([minTempY, maxTempY])
				yScaleTemp.domain([30, maxTempY]); // Temporary - Wrong Temperature Data

				// Redraw Y-Axes
				if (temp_axis===true && prec_axis===false && press_axis===false) {
					yAxisTempDraw(0);		
				} else if (temp_axis===true && prec_axis===true && press_axis===false) {
					yAxisTempDraw(0);
					yAxisPrecDraw(1);
				} else if (temp_axis===true && prec_axis===true && press_axis===true) {
					yAxisTempDraw(0);
					yAxisPrecDraw(1);
					yAxisPressDraw(2);
				} else if (temp_axis===true && prec_axis===false && press_axis===true){
					yAxisTempDraw(0);
					yAxisPressDraw(1);
				} else if (temp_axis===false && prec_axis===true && press_axis===false) {
					yAxisPrecDraw(0);
				} else if (temp_axis===false && prec_axis===true && press_axis===true) {
					yAxisPrecDraw(0);
					yAxisPressDraw(1);
				} else if (temp_axis===false && prec_axis===false && press_axis===true) {
					yAxisPressDraw(0);
				} else {}
				
				// Redraw Graphs
				for (var i=0; i<findTicksArray.length; i++) {
					var tick = parseInt(findTicksArray[i])-1;
					graphsArray[tick]();
				}
				
				// Add again CSS
				addCss();
				
				// Call hover function
				hover();
			}	
			
			$("#checkbox1").click(function() {
				redrawGraph();
			});
			$("#checkbox2").click(function() {
				redrawGraph();
			});  
			$("#checkbox3").click(function() {
				redrawGraph();
			});		
			$("#checkbox4").click(function() {
				redrawGraph();
			});			
			$("#checkbox5").click(function() {
				redrawGraph();
			});	
			
			// Hover function
			function hover() {
				var element = document.getElementById("d3GraphDiv");
				var position = element.getBoundingClientRect();
				var x = position.left;
				var y = position.top;
				
				$("#d3GraphDiv").mousemove(function(event) {
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
					
					// Which colors to use in the tooltip
					function findColor(i) {
						for (var k=0; k<arrayColors.length; k++) {
							if (arrayNames[i][0]===arrayColors[k][0]) {
								return arrayColors[k][1];
							}
						}
					}
					
					if (item) {
						var tooltipText="";
						tooltipText="Date: <b>"+item.date.toDateString()+"</b>";	// Day Data
						//tooltipText="Year: <b>"+item.date.getFullYear()+"</b>";	// Year data
						for (var i=0; i<arrayNames.length; i++) {
							tooltipText += "<br><div id='tooltipBox"+i+
							"' style='height:10px; width:10px; outline:solid 1px black; background-color:"+findColor(i)+"; float:left; margin-left:5px; margin-right:5px; margin-top:3px;'></div>"+arrayNames[i][1]+": "+item[arrayNames[i][0]].toFixed(1);
						}
	
						// Create tooltip
						$("#d3GraphDiv").append("<div id='tooltip'</div>");				
						d3.select("#tooltip")
							.style("position", "absolute")
							.style("left", (mouseX-x+5)+"px")
							.style("top", (height/2)+"px")
							//.style("width", "auto")
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
			hover();
		}
	});
  // CUSTOM CODING END
  }
}
})(jQuery);