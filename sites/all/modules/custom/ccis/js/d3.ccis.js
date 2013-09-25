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

	var height = 250;
	var width = 450;
	var margin = {top: 20, right: 10, bottom: 25, left: 150, left_single: 50};
	var axis_sum = 3;
	var axis_selection = 3;
	var svg;
	var colors = ["red", "green", "blue", "orchid", "orange"];
	
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
					.attr("stroke", colors[0])
					.attr("fill", "none")
					.attr("transform", "translate(" + (margin.left-((margin.left_single*axis_sum)-(margin.left_single*axis_selection))) + "," + margin.top + ")");		  
			}	  
			avgTempGraph();
		  
			// Average precipitation amount
			function avgPrecGraph(){
				var avgPrec = d3.svg.line()
					.x(function(d){return xScale(d.date)})
					.y(function(d){return yScalePrec(d.avg_prec)});
		 
				d3.select("svg")
					.append("path")
				  	.attr("id", "pathAvgPrecID")
					.attr("d", avgPrec(data))
					.attr("stroke", colors[1])
					.attr("fill", "none")
					.attr("transform", "translate(" + (margin.left-((margin.left_single*axis_sum)-(margin.left_single*axis_selection))) + "," + margin.top + ")");
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
					.attr("stroke", colors[2])
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
					.attr("stroke", colors[3])
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
					.attr("stroke", colors[4])
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
					.attr("fill", "none")
					.attr("stroke", "black")
					.attr("stroke-width", "1")
					.style("font-size","10px")
					.attr("transform", "translate("+(axisPosition*(-50))+",0)")
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
					.attr("fill", "none")
					.attr("stroke", "black")
					.attr("stroke-width", "1")
					.style("font-size","10px")
					.attr("transform", "translate("+(axisPosition*(-50))+",0)")
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
					.attr("fill", "none")
					.attr("stroke", "black")
					.attr("stroke-width", "1")
					.style("font-size","10px")
					.attr("transform", "translate("+(axisPosition*(-50))+",0)")
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
				.attr("transform", "translate(0," + height + ")")
				.attr("fill", "none")
				.attr("stroke", "black")
				.attr("stroke-width", "1")
				.call(xAxis);
			}
			createxAxis();
		  
			// Create DIVs for the keys
			for (var i=1; i<6; i++) {
				$("#ccis-weather-d3-block").append("<div id='keysDiv"+i+"'></div>");
				$("#keysDiv"+i).append("<div id='keysTick"+i+"' style='float:left'><input id='checkbox"+i+"' type='checkbox' value='"+i+"'checked='checked'></div>");
				$("#keysDiv"+i).append("<div id='keysBox"+i+"'></div>");
				$("#keysBox"+i)
					.css("height", "10px")
				  	.css("width", "10px")
				  	.css("outline", "solid 1px black")
				  	.css("background-color", colors[i-1])
				  	.css("float", "left")
				  	.css("margin-left", "5px")
				  	.css("margin-right", "5px")
				  	.css("margin-top", "5px");
				$("#keysDiv"+i).append("<div id='keysText"+i+"'></div>");
				$("#keysText"+i).append(settings.ccis.legends[i-1]);			
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
				
				var temperatureArrayNames=[];
				for (var i=0; i<findTicksArray.length; i++) {
					var tick = parseInt(findTicksArray[i]);
					if (tick===1) {
						temp_axis=true;
						temperatureArrayNames.push("avg_temp");
					} else if (tick===2) {
						prec_axis=true;
					} else if (tick===3) {
						press_axis=true;
					} else if (tick===4) {
						temp_axis=true;
						temperatureArrayNames.push("avg_min_temp");
					} else if (tick===5) {
						temp_axis=true;
						temperatureArrayNames.push("avg_max_temp");
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
		}
	});
  // CUSTOM CODING END
  }
}
})(jQuery);