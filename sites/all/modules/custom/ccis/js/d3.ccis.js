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

	stations_test=settings.ccis.stations;	// Delete
	console.log(settings.ccis.stations[0].path);	// Delete
	legends=settings.ccis.legends;	// Legends!!! -- Delete

	var margin = {top: 20, right: 45, bottom: 25, left: 45};
	
	// Parse the JSON
	d3.json(settings.ccis.stations[0].path, function(json) {
		
		if (json.length===0) {
			$("#ccis-weather-d3-block").html("");
		} else {
			$("#ccis-weather-d3-block").html("");
			data = json.map(function(d) {
				//console.log(d3.time.format("%Y-%m-%d").parse(d.date.slice(0,-12)));
				return {
					//date: d3.time.format("%Y-%m-%d %H:%M:%S").parse(d.date.slice(0,-3), // Datum & Zeit ohne Zeitzone
					date: d3.time.format("%Y-%m-%d").parse(d.date.slice(0,-12)), // Nur Datum
					avg_temp: d.avg_temp,
					avg_prec: d.avg_prec
				};        
			});
  
		  // X Scale
		  xScale = d3.time.scale()
		  	.domain(d3.extent(data, function(d) { return d.date; }))
		  	// .domain([d3.min(data, function(d) {return d.date;}), (data[data.length-2].date)]) // Change it!
		  	.range([0, 500]);
 
		  // Y Scales
		  yScaleAvgTemp = d3.scale.linear()
		  	//.domain(d3.extent(data, function(d) { return d.avg_temp; }))
		  	.domain([70, d3.max(data, function(d) { return d.avg_temp; })])
		  	.range([300, 0]);	  
		  yScaleAvgPrec = d3.scale.linear()
		  	//.domain(d3.extent(data, function(d) { return d.avg_prec; }))
		  	.domain([14, d3.max(data, function(d) { return d.avg_prec; })])
		  	.range([300, 0]);
	
		  //Create SVG element
		  var svg = d3.select("#ccis-weather-d3-block")
		  	.append("svg")
			.attr("width", 500 + margin.left + margin.right)
			.attr("height", 300 + margin.top + margin.bottom)
			.append("g")
			.attr("transform", "translate(" + margin.left + "," + margin.top + ")");
		  
		  function avgTempGraph(){
			  // avgTemp Graph
			  var avgTemp = d3.svg.line()
			  	.x(function(d){return xScale(d.date)})
			  	.y(function(d){return yScaleAvgTemp(d.avg_temp)});
			  	//.interpolate("linear")
	 
			  d3.select("svg")
			  	.append("path")
			  	.attr("id", "pathAvgTempID")
				.attr("d", avgTemp(data))
				.attr("stroke", "red")
				.attr("fill", "none")
				.attr("transform", "translate(" + margin.left + "," + margin.top + ")");
			  
			  // Create the Y Axis
			  var yAxisAvgTemp = d3.svg.axis()
			  	.scale(yScaleAvgTemp)
				.orient("left")
				.ticks(5);
			  svg.append("g")
			  	.attr("id", "yAxisLineAvgTemp")
				.attr("fill", "none")
				.attr("stroke", "black")
				.attr("stroke-width", "2")
				.call(yAxisAvgTemp);
	
			/*  svg.selectAll("circle")
			  	.data(data)
			  	.enter()
			  	.append("circle")
			  	.attr("id", "circleAvgTempID")
			  	.attr("cx", function(d) {
			  		return xScale(d.date);
			  	})
			  	.attr("cy", function(d) {
			  		return yScaleAvgTemp(d.avg_temp);
			  	})
			  	.attr("r", 2);	*/
		  }	  
		  avgTempGraph();
		  
		  function avgPrecGraph(){
			  // avgTemp Graph
			  var avgPrec = d3.svg.line()
			  	.x(function(d){return xScale(d.date)})
			  	.y(function(d){return yScaleAvgPrec(d.avg_prec)});
			  	//.interpolate("linear")
	 
			  d3.select("svg")
			  	.append("path")
			  	.attr("id", "pathAvgPrecID")
				.attr("d", avgPrec(data))
				.attr("stroke", "green")
				.attr("fill", "none")
				.attr("transform", "translate(" + margin.left + "," + margin.top + ")");
			  
			  // Create the Y Axis
			  var yAxisAvgPrec = d3.svg.axis()
			  	.scale(yScaleAvgPrec)
				.orient("right")
				.ticks(5);
			  svg.append("g")
			  	.attr("id", "yAxisLineAvgPrec")
				.attr("fill", "none")
				.attr("stroke", "black")
				.attr("stroke-width", "2")
				.attr("transform", "translate(" + 500 + ",0)")
				.call(yAxisAvgPrec);
		  }	  
		  avgPrecGraph();
		  
		  // Create the X Axis
		  var xAxis = d3.svg.axis()
		  	.scale(xScale)
		  	.orient("bottom")
		  	.ticks(5);
		  svg.append("g")
		  	.attr("class", "xAxisLine")
			.attr("transform", "translate(0," + 300 + ")")
			.attr("fill", "none")
			.attr("stroke", "black")
			.attr("stroke-width", "2")
			.call(xAxis);
  
		  // Create DIVs for the keys
		  var colors=["red", "green"];
		  for (var i=1; i<3; i++) {
			  $("#ccis-weather-d3-block").append("<div id='keysDiv"+i+"'></div>");
			  $("#keysDiv"+i).append("<div id='keys_box"+i+"'></div>")
			  $("#keys_box"+i)
			  	.css("height", "10px")
			  	.css("width", "10px")
			  	.css("outline", "solid 1px black")
			  	.css("background-color", colors[i-1])
			  	.css("float", "left")
			  	.css("margin-left", "5px")
			  	.css("margin-right", "5px")
			  	.css("margin-top", "5px");
			  $("#keysDiv"+i).append("<div id='keysText"+i+"'></div>");
			  $("#keysText"+i).append(settings.ccis.legends[i+1])		  
		  }
		  
		  $("#keysDiv1").click(function() {
			  if (document.getElementById("pathAvgTempID")) {
				  d3.select("#pathAvgTempID").remove();
				  d3.select("#yAxisLineAvgTemp").remove();
				  //d3.selectAll("#circleAvgTempID").remove();
			  } else {
				  avgTempGraph();
			  }	  
		  });
		  
		  $("#keysDiv2").click(function() {
			  if (document.getElementById("pathAvgPrecID")) {
				  d3.select("#pathAvgPrecID").remove();
				  d3.select("#yAxisLineAvgPrec").remove();
			  } else {
				  avgPrecGraph();
			  }	  
		  });
		}
	});
  // CUSTOM CODING END
  }
}
})(jQuery);