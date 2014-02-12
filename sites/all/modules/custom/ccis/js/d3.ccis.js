(function($) {
Drupal.ccis.behaviors.d3 = {
    init: function() {
      var D3 = this;
      D3.container = $("#ccis-weather-d3-block-1, #ccis-weather-d3-block-2");
      D3.homebox = $("#homebox-block-ccis_d3, #homebox-block-ccis_d3_2");
    },
  attach: function(stations, info, settings) {
    var D3 = this;
  // CUSTOM CODING START
	
	// Array with Units used for diagram
	// Position 0: Keyword (the same name as at the parameter groups)
	// Position 1: Icon filename
	// Position 2: Axis label
	// Position 3: Tick format for the axis label
	// Position 4: Tooltip label
	var unitsArray = [];
	var unitsObj = info.d3.units;
	for (var key in unitsObj) {
		if (unitsObj.hasOwnProperty(key)) {

			var unitsArrayKeyword = key; // Position 0

			if (unitsObj[key].field_icon_unit) {
				var unitsArrayIconFilename = unitsObj[key].field_icon_unit; // Position 1
			} else {
				var unitsArrayIconFilename = ""; // Position 1
			}

			if (unitsObj[key].field_label_axis) {
				var unitsArrayAxisLabel = unitsObj[key].field_label_axis; // Position 2
			} else {
				var unitsArrayAxisLabel = ""; // Position 2
			}

			if (unitsObj[key].field_decimal_places_for_tooltip) {
				var unitsArrayTickFormat = "."+unitsObj[key].field_decimal_places_for_tooltip+"f"; // Position 3
			} else {
				var unitsArrayTickFormat = ".0f"; // Position 3
			}

			if (unitsObj[key].field_label_tooltip) {
				var unitsArrayTooltipLabel = unitsObj[key].field_label_tooltip; // Position 4
			} else {
				var unitsArrayTooltipLabel = ""; // Position 4
			}

			unitsArray.push([unitsArrayKeyword, unitsArrayIconFilename, unitsArrayAxisLabel, unitsArrayTickFormat, unitsArrayTooltipLabel]);

		}
	}
	
	// Fill groupArray
	// Position 1: Name of group
	// Position 2: Name of group withour whitespaces (we use it for the ids of divs later in legend)
	// Position 3: Group order
	var groupArray = [];
	var groupsObj = info.d3.groups;
	for (var key in groupsObj) {
		if (groupsObj.hasOwnProperty(key)) {
			if (groupsObj[key].field_group_order) {
				var groupOrder = groupsObj[key].field_group_order;
			} else {
				var groupOrder = "0";
			}
			groupArray.push([key, key.replace(/ /g,''), groupOrder]);
			// Sort the groups by the group order value
			groupArray.sort(function(a, b) {
				return a[2] - b[2];
			});
		}
	}

	// Groups of parameters available including the colors, the legend keywords, the legend hover names, the icons and the units
	// Position 0: Parameter
	// Position 1: Color
	// Position 2: Legend Keyword
	// Position 3: Legend Hover Name
	// Position 4: Graph Type (0:Line / 1:Bar)
	// Position 5: Units

	// Define groups;
	var group = {};
	for (var i=0; i<groupArray.length; i++) {
		group[groupArray[i][1]] = [];
	}

	// Fill Arrays with group information
	var parameterObj = info.d3.parameter;
	for (var key in parameterObj) {
		if (parameterObj.hasOwnProperty(key)) {
		
			var field_name = key; // Get field_name
		
			if (parameterObj[field_name].climate_group) {
				var climate_group = parameterObj[field_name].climate_group; // Get group
			} else {
				var climate_group = "";
			}
			
			// Position 0: Parameter Name
			var parameterName = field_name.slice(6); // Position 0
			
			// Position 1: Color
			if (parameterObj[field_name].color) {
				var parameterColor = "#" + parameterObj[field_name].color; // Position 1
			} else {
				var parameterColor = "#000000";
			}
			
			// Position 2: Legend Keyword
			if (info.legends[field_name]) {
				var parameterKeyword = info.legends[field_name];
				if (parameterKeyword.indexOf('<span class="ccis-datatable-title" title=')!==-1 || parameterKeyword.indexOf('<span class="ccis-datatable-title"  title=')!==-1) {
					var parIndex1 = parameterKeyword.indexOf('">');
					parameterKeyword = parameterKeyword.slice(parIndex1+2);
				} else if (parameterKeyword.indexOf('<span class="ccis-datatable-title" >')!==-1) {
					var parIndex1 = parameterKeyword.indexOf('" >');
					parameterKeyword = parameterKeyword.slice(parIndex1+3);
				}
				var parIndex2 = parameterKeyword.indexOf('</span');
				var parameterKeywordTemp = parameterKeyword.slice(parIndex2);
				parameterKeyword = parameterKeyword.replace(parameterKeywordTemp, ""); // Position 2
			}
			
			// Position 5: Units
			if (parameterObj[field_name].climate_unit) {
				var climateUnit = parameterObj[field_name].climate_unit; // Position 5
			}
			
			// Position 3: Legend Hover Name
			var parameterHoverName;
			var parameterHoverNameInitial = info.legends[field_name];
			if (parameterHoverNameInitial.indexOf('<span class="ccis-datatable-title" title="')!==-1 ) {
				parameterHoverName = parameterHoverNameInitial.replace('<span class="ccis-datatable-title" title="', '');
				var parIndex3 = parameterHoverName.indexOf('">');
				var parameterHoverNameTemp = parameterHoverName.slice(parIndex3);
				parameterHoverName = parameterHoverName.replace(parameterHoverNameTemp, ""); // Position 3
			} else if (parameterHoverNameInitial.indexOf('<span class="ccis-datatable-title"  title="')!==-1 ) {
				parameterHoverName = parameterHoverNameInitial.replace('<span class="ccis-datatable-title"  title="', '');
				var parIndex3 = parameterHoverName.indexOf('">');
				var parameterHoverNameTemp = parameterHoverName.slice(parIndex3);
			parameterHoverName = parameterHoverName.replace(parameterHoverNameTemp, ""); // Position 3
			} else {
				parameterHoverName = ""; // Position 3
			}
			for (var k=0; k<unitsArray.length; k++) {
				if (climateUnit === unitsArray[k][0]) {
					parameterHoverName = parameterHoverName + " (" + unitsArray[k][4] + ")"; // Position 3
				}
			}
			
			// Position 4: Graph Type (0:Line / 1:Bar)
			if (parameterObj[field_name].graph_type) {
				var graphType = parameterObj[field_name].graph_type.toString(); // Position 4
			} else {
				var graphType = "0";
			}
			
			// Fill group arrays
			var parameterArray = [parameterName, parameterColor, parameterKeyword, parameterHoverName, graphType, climateUnit];
			for (var k=0; k<groupArray.length; k++) {
				if (parameterObj[key].climate_group) {
					if (parameterObj[key].climate_group === groupArray[k][0]) {
						group[groupArray[k][1]].push(parameterArray);
					}
				}
			}	
		}
	}
		
	// Icons used for groups
	// Position 0: Group name
	// Position 1: Icon filename
	var groupIconsArray = [];

	var groupsObj = info.d3.groups;
	for (var key in groupsObj) {
		if (groupsObj.hasOwnProperty(key)) {
			var iconTitle = key;
			if (groupsObj[iconTitle].field_icon) {
				var iconFilename = groupsObj[iconTitle].field_icon;
			} else {
				var iconFilename = "";
			}
			groupIconsArray.push([iconTitle, iconFilename]);
		}
	}
	
	// Date Icon for Diagram Tooltip
	var dateIcon = "sites/all/modules/custom/ccis/images/d3/symbol_infobereich_clock.png";
	
	// Print Icon
	var printIcon = "sites/all/modules/custom/ccis/images/d3/symbol_printer.png";

	// SVG legend icons (Line and Bar)
	var partOfSVGLine1 = "<svg width='25' height='13'><g transform='translate(0,-1039.3622)'><path style='fill:none;stroke:";
	var partOfSVGLine2 = ";stroke-width:1.96201527;stroke-linecap:butt;stroke-linejoin:miter;stroke-miterlimit:10;stroke-opacity:1;stroke-dasharray:none' d='m 1.3394886,1047.4364 9.3823584,-6.3952 3.619918,9.4078 4.692159,-5.6505 5.34355,0'/></g></svg>";

	var partOfSVGBar1 = "<svg width='16' height='14'><rect style='fill:";
	var partOfSVGBar2 = "' width='16.044739' height='1.0486692' x='6.6104633e-009' y='12.993272' ry='0.020973505'/><rect style='fill:";
	var partOfSVGBar3 = "' width='3.0831053' height='9.1025019' x='11.996845' y='4.0166111' ry='0.020973505'/><rect style='fill:";
	var partOfSVGBar4 = "' width='3.0411584' height='13.045521' x='7.9489589' y='-0.031275675' ry='0.020973505'/><rect style='fill:";
	var partOfSVGBar5 = "' width='2.9572644' height='7.29878' x='4.0269132' y='6.0090942' ry='0.020973505'/><rect style='fill:";
	var partOfSVGBar6 = "' width='2.9992113' height='3.1669993' x='-0.020973505' y='10.036007' ry='0.020973505'/></svg>";

	
	// ***************************************
	// ********** DIAGRAM 1 - START **********
	// ***************************************
	function diagram1(blockID, data, dataKeysArray, minDate, maxDate) {					
		// *** Variables - START ***
		var block = "_1";
		var margin = {top: 20, right: 10, bottom: 25, left: 140, left_single: 35};
		var widthDiv = $("#"+blockID).width();
		var legendWidth = 150;
		var tooltipWidth = 200;
		var width = widthDiv - margin.left - margin.right - legendWidth;
		var height = width/2;
		var heightPrintSelect = 45;
		var axis_sum = 4;	// MAX: 4
		var axis_selection;
		var svg;	
		var mouseX;
		var mouseY;
		var yAxisArray;
		
		// Object for the Units
		var d3Units = {};
		
		// Arrays for the checkboxes
		var findTicksArray = {};
		
		// *** Variables - END ***
		
		// Define groups that are visible in the graph (maximum 4 parameters total for all groups)
		var groupShown = {};
		for (var i=0; i<groupArray.length; i++) {
			groupShown[groupArray[i][1]] = [];
		}
		
		// Choose initial parameters to show (the first available)
		if (groupArray.length>0) {
			if (group[groupArray[0][1]].length>0) {
				groupShown[groupArray[0][1]] = [group[groupArray[0][1]][0]];
			}
		}
		
		// Fill the unit groups arrays
		function fillUnitGroups() {
			for (var k=0; k<unitsArray.length; k++) {
				d3Units[unitsArray[k][0]+"GroupShown"] = [];
			}

			for (var i=0; i<groupArray.length; i++) {
				for (var k=0; k<groupShown[groupArray[i][1]].length; k++) {
					for (var j=0; j<unitsArray.length; j++) {
						if (groupShown[groupArray[i][1]][k][5] === unitsArray[j][0]) {
							d3Units[unitsArray[j][0]+"GroupShown"].push(groupShown[groupArray[i][1]][k][0]);
						}
					}
				}
			}
		}
		fillUnitGroups();

		// Find the max and min values for the Y scales
		function findMaxMin() {
			for (var i=0; i<unitsArray.length; i++) {
				d3Units["min"+unitsArray[i][0]+"YArray"] = [];
				d3Units["max"+unitsArray[i][0]+"YArray"] = [];
				for (var k=0; k<d3Units[unitsArray[i][0]+"GroupShown"].length; k++) {
					d3Units["min"+unitsArray[i][0]+"YArray"].push(d3.min(data, function(d) { return Math.min(d[d3Units[unitsArray[i][0]+"GroupShown"][k]]); }) );
					d3Units["max"+unitsArray[i][0]+"YArray"].push(d3.max(data, function(d) { return Math.max(d[d3Units[unitsArray[i][0]+"GroupShown"][k]]); }) );
				}
				d3Units["min"+unitsArray[i][0]+"Y"] = d3.min(d3Units["min"+unitsArray[i][0]+"YArray"]);
				d3Units["max"+unitsArray[i][0]+"Y"] = d3.max(d3Units["max"+unitsArray[i][0]+"YArray"]);
			}
		}
		findMaxMin();
		
		// Y Scales
		for (var i=0; i<unitsArray.length; i++) {
			d3Units["yScale"+unitsArray[i][0]] = d3.scale.linear()
				.domain([d3Units["min"+unitsArray[i][0]+"Y"], d3Units["max"+unitsArray[i][0]+"Y"]])
				.range([height, 0]);
		}
		
		// Which and how many Y-Axes we need
		function findAxis() {
			axis_selection = 0;
			yAxisArray = [];			
			for (var i=0; i<unitsArray.length; i++) {
				d3Units[unitsArray[i][0]+"_selection"] = true;
				if (d3Units[unitsArray[i][0]+"GroupShown"].length>0)  {
					d3Units[unitsArray[i][0]+"_selection"] = false;
					//yAxisArray.push([d3Units["yAxis"+unitsArray[i][0]], d3Units["yScale"+unitsArray[i][0]], unitsArray[i][0]]);
					yAxisArray.push([unitsArray[i][0], d3Units["yScale"+unitsArray[i][0]], unitsArray[i][2]]);
					axis_selection=axis_selection+1;
				}
			}
		}
		findAxis();
					
		// X Scale
		var xScale = d3.time.scale()
			.domain([minDate, maxDate])
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
		function graphDraw(graphType, yScale, color, lineORbar) {
			var yScaleType;
			for (var i=0; i<unitsArray.length; i++) {
				switch (yScale){
					case unitsArray[i][0]:
						yScaleType=d3Units["yScale"+unitsArray[i][0]];
						break;
				}
			}
			
			var graphObj = {};
			
			// Clip rects
			var clip = svg.append("svg:clipPath")
				.attr("id", "d3_clip");
			clip.append("svg:rect")
				.attr("width", (width + (margin.left_single)*axis_sum + margin.right))
				.attr("height", height);
							
			if (lineORbar === "1") {
				// Bars
				var barPadding = 3;
				var barWidth = ((width + (margin.left_single)*axis_sum + margin.right)/data.length)-barPadding;
				svg.selectAll("#d3_rectId")
					.data(data)
					.enter()
					.append("rect")
					.attr("id", "d3_rectId")
					.attr("clip-path", "url(#d3_clip)")		// Clip
					.attr("x", function(d) {return xScale(d.date)-barWidth;})
					.attr("y", function(d) {return yScaleType(d[graphType])-1;})
					.attr("width", barWidth+"px")
					.attr("height", function(d) {return height-yScaleType(d[graphType]);})
					.attr("fill", color);
			} else {
				// Lines for the rest				
				graphObj[graphType] = d3.svg.line()
					.interpolate("linear")
					.x(function(d){return xScale(d.date)})
					.y(function(d){return yScaleType(d[graphType])})
					.defined(function(d) {return !isNaN(d[graphType]);});	// do not show NaN

				d3.select("#svg"+block)
					.append("path")
					.attr("clip-path", "url(#d3_clip)")		// Clip
					.attr("id", "d3_path"+graphType+"ID"+block)
					.attr("d", graphObj[graphType](data))
					.attr("stroke", color)
					.attr("stroke-width", "2")
					.attr("fill", "none")
					.attr("transform", "translate(" + (margin.left-((margin.left_single*axis_sum)-(margin.left_single*axis_selection))) + "," + margin.top + ")");	  
			}
			
			// Trendline - START	
			if ($("#d3_checkboxTrendline"+block).is(":checked")) {

				var trendArrayX = [];
				var trendArrayY = [];
				for (var i=0; i<data.length; i++) {
					// Don't use data if isNaN
					if (!isNaN(data[i][graphType])) {
						trendArrayX.push(xScale(data[i].date));
						trendArrayY.push(yScaleType(data[i][graphType]));
					}
				}
				
				// Calculate Linear Regression
				function linearRegression(y,x){

						var lr = {};
						var n = y.length;
						var sum_x = 0;
						var sum_y = 0;
						var sum_xy = 0;
						var sum_xx = 0;
						var sum_yy = 0;

						for (var i = 0; i < y.length; i++) {

							sum_x += x[i];
							sum_y += y[i];
							sum_xy += (x[i]*y[i]);
							sum_xx += (x[i]*x[i]);
							sum_yy += (y[i]*y[i]);
						} 

						lr['slope'] = (n * sum_xy - sum_x * sum_y) / (n*sum_xx - sum_x * sum_x);
						lr['intercept'] = (sum_y - lr.slope * sum_x)/n;
						lr['r2'] = Math.pow((n*sum_xy - sum_x*sum_y)/Math.sqrt((n*sum_xx-sum_x*sum_x)*(n*sum_yy-sum_y*sum_y)),2);

						return lr;

				};

				var lr = linearRegression(trendArrayY, trendArrayX);
				// We get: lr.slope - lr.intercept - lr.r2
				
				var max = d3.max(trendArrayX);
				var myLine = d3.select("#svg"+block).append("svg:line")
					.attr("x1", 0)
					.attr("y1", lr.intercept)
					.attr("x2", max)
					.attr("y2", ( (max * lr.slope) + lr.intercept ))
					.attr("stroke", color)
					.attr("stroke-width", "2")
					.style("stroke-dasharray", ("3, 3"))
					.attr("transform", "translate(" + (margin.left-((margin.left_single*axis_sum)-(margin.left_single*axis_selection))) + "," + margin.top + ")");			
			}	
			// Trendline - END
		}

		function drawGraphs() {
			for (var i=0; i<groupArray.length; i++) {
				for (var k=0; k<groupShown[groupArray[i][1]].length; k++) {
					graphDraw(groupShown[groupArray[i][1]][k][0], groupShown[groupArray[i][1]][k][5], groupShown[groupArray[i][1]][k][1], groupShown[groupArray[i][1]][k][4]);
				}
			}	
		}
		drawGraphs();

		// Draw Y Axis
		function yAxisDraw(axisType, scaleType, axisPosition) {
			var yAxisObj = {};
			var yAxisLabel;
			var yAxisLabelOffset;
			var yAxisTickFormat;
			var iconLink;
			var iconWidth;
			var iconHeight;
			
			for (var i=0; i<unitsArray.length; i++) {
				if (axisType===unitsArray[i][0]) {
					yAxisLabel = unitsArray[i][2];
					var axisTypeID = axisType.replace(/ /g,'');	// Remove whitespaces
					yAxisLabelOffset = -30;
					yAxisTickFormat = unitsArray[i][3];
					if (unitsArray[i][1].length>0) {
						iconLink = unitsArray[i][1];
					} else {
						iconLink = "";
					}
					iconWidth = "10px";
					iconHeight = "20px";
				}
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
				.attr("id", axisTypeID+"id"+block)
				.attr("class", "d3_yAxisClass")
				.style("font-size","10px")
				.attr("transform", "translate("+(axisPosition*(-margin.left_single))+",0)")
				.call(yAxisObj[axisType]);
			d3.select("#"+axisTypeID+"id"+block)
				.append("text")
				.text(yAxisLabel)
				.attr("class", "d3_yAxisText")
				.style("font-size","12px")
				.attr("transform", "translate ("+yAxisLabelOffset+", -7)");
			
			d3.select("#"+axisTypeID+"id"+block)
				.append("image")
				.attr("xlink:href", iconLink)
				.attr("width", iconWidth)
				.attr("height", iconHeight)
				.attr("transform", "translate (-20, "+(height+3)+")");
		}
		
		// Call the Y Axis draw function
		for (var i=0; i<yAxisArray.length; i++) {
			yAxisDraw(yAxisArray[i][0], yAxisArray[i][1], i);
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

		// Hoverintent for legend accordion			
		$.event.special.hoverintent = {
			setup: function () {
				$(this).bind("mouseover", jQuery.event.special.hoverintent.handler);
			},
			teardown: function () {
				$(this).unbind("mouseover", jQuery.event.special.hoverintent.handler);
			},
			handler: function (event) {
				var currentX, currentY, timeout,
				args = arguments,
				target = $(event.target),
				previousX = event.pageX,
				previousY = event.pageY;

				function track(event) {
					currentX = event.pageX;
					currentY = event.pageY;
				};

				function clear() {
					target
					.unbind("mousemove", track)
					.unbind("mouseout", clear);
					clearTimeout(timeout);
				}

				function handler() {
					var prop,
					orig = event;
					if ((Math.abs(previousX - currentX) +
					Math.abs(previousY - currentY)) < 7) {
						clear();
						event = $.Event("hoverintent");
						for (prop in orig) {
							if (!(prop in event)) {
								event[prop] = orig[prop];
							}
						}
						delete event.originalEvent;
						target.trigger(event);
					} else {
						previousX = currentX;
						previousY = currentY;
						timeout = setTimeout(handler, 100);
					}
				}
				timeout = setTimeout(handler, 100);
				target.bind({
				mousemove: track,
				mouseout: clear
				});
			}
		};
		
		// Legend Tooltips
		function hoverLegend(topPosition, keyPlace, text) {			
			$("#d3_tooltipLegend"+keyPlace+block)
				.css("position", "absolute")
				.css("right", (legendWidth-3)+"px")
				.css("top", (topPosition-5)+"px")
				.css("width", "auto")
				.css("clear", "both")
				.css("float", "left")
				.css("background-color", "#fcce00")
				.css("border", "solid 1px #e6e6e6")
				.css("border-radius", "8px 8px 8px 8px")
				.css("-webkit-box-shadow", "4px 4px 10px rgba(0, 0, 0, 1)")
				.css("-moz-box-shadow", "4px 4px 10px rgba(0, 0, 0, 1)")
				.css("box-shadow", "4px 4px 10px rgba(0, 0, 0, 1)")
				.css("padding", "3px")
				.css("font-size","12px")
				.html(text);
		}

		// Add div for the legend
		$("#"+blockID).append("<div id='d3_legendDiv"+block+"' class='d3_legendClass'></div>");
		
		$("#d3_legendDiv"+block)
			.css("width", legendWidth)
			.css("height", height + margin.top + margin.bottom - heightPrintSelect);
			
		// Scrollbar (slimScroll)
		$("#d3_legendDiv"+block).slimScroll({
			width: legendWidth,
			height: height + margin.top + margin.bottom - heightPrintSelect,
			//railVisible: true,
			alwaysVisible: true,
			//railColor: "yellow",
			color: "#455468"
		});
		
		// Create DIVs for the keys
		for (var i=0; i<groupArray.length; i++) {
			$("#d3_legendDiv"+block).append("<h6><a href='#'><div id='legend"+groupArray[i][1]+"Group"+block+"'></div></a></h6>");
			for (var k=0; k<groupIconsArray.length; k++) {
				if (groupArray[i][0]===groupIconsArray[k][0]) {
					if (groupIconsArray[k][1].length>0) {
						$("#legend"+groupArray[i][1]+"Group"+block).append("<div id='d3_iconLegend"+block+"' class='d3_iconLegendClass'><img src='"+groupIconsArray[k][1]+"' width='15' height='20'> "+groupArray[i][0]+"</div>");
					} else {
						$("#legend"+groupArray[i][1]+"Group"+block).append("<div id='d3_iconLegend"+block+"' class='d3_iconLegendClass'> "+groupArray[i][0]+"</div>");
					}
				}
			}
			$("#d3_legendDiv"+block).append("<div id='d3_keysDiv"+groupArray[i][1]+block+"'></div>");
			
			for (var m=0; m<group[groupArray[i][1]].length; m++) {
				function findTemperatureChecked() {
					for (var j=0; j<groupShown[groupArray[i][1]].length; j++) {
						if (group[groupArray[i][1]][m][0]===groupShown[groupArray[i][1]][j][0]) {
							return "checked";
						}
					}
				}
				$("#d3_keysDiv"+groupArray[i][1]+block).append("<div id='d3_keys"+groupArray[i][1]+m+block+"' class='d3_keys'></div>");
				$("#d3_keys"+groupArray[i][1]+m+block).append("<div id='d3_keys"+groupArray[i][1]+"Tick"+m+block+"' class='d3_keysTick'><input id='d3_checkbox"+groupArray[i][1]+m+block+"' class='d3_checkboxClass' type='checkbox' value='"+m+"' "+findTemperatureChecked()+"></div>");
				$("#d3_keys"+groupArray[i][1]+m+block).append("<div id='d3_keys"+groupArray[i][1]+"BoxText"+m+block+"' class='d3_keysBoxText'></div>");
				$("#d3_keys"+groupArray[i][1]+"BoxText"+m+block).append("<div id='keys"+groupArray[i][1]+"Text"+m+block+"' class='d3_keysText'></div>");
				$("#keys"+groupArray[i][1]+"Text"+m+block).append(group[groupArray[i][1]][m][2]);
				
				if (group[groupArray[i][1]][m][4] === "1") {
					$("#d3_keys"+groupArray[i][1]+"BoxText"+m+block).append("<div id='keys"+groupArray[i][1]+"Icon"+m+block+"' class='d3_keysIcon'>"+partOfSVGBar1+group[groupArray[i][1]][m][1]+partOfSVGBar2+group[groupArray[i][1]][m][1]+partOfSVGBar3+group[groupArray[i][1]][m][1]+partOfSVGBar4+group[groupArray[i][1]][m][1]+partOfSVGBar5+group[groupArray[i][1]][m][1]+partOfSVGBar6+"</div>");
				} else {
					$("#d3_keys"+groupArray[i][1]+"BoxText"+m+block).append("<div id='keys"+groupArray[i][1]+"Icon"+m+block+"' class='d3_keysIcon'>"+partOfSVGLine1+group[groupArray[i][1]][m][1]+partOfSVGLine2+"</div>");
				}
				
				// Hover function
				(function(m) {
					$("#d3_keys"+groupArray[i][1]+"BoxText"+m+block)
						.hover(function(){
							$(this).css("cursor","default"); 
							// Create div for tooltip
							$("#"+blockID).append("<div id='d3_tooltipLegend"+m+block+"'></div>");
							// Find position
							var topPositionKeysDiv = $(this).parent().parent().position().top;
							var topPositionBoxText = $(this).position().top;
							var topPosition = topPositionKeysDiv + topPositionBoxText;
							// Find title
							var findTitle = this.id;
							findTitle = findTitle.slice(7);
							var findTitleIndexTemp = findTitle.indexOf("BoxText");
							findTitle = findTitle.slice(0, findTitleIndexTemp);
							var findIndex = this.id.slice(7+findTitleIndexTemp+7, -2);
							var hoverTitle = group[findTitle][findIndex][3];
							// Call legend function
							hoverLegend(topPosition, m, hoverTitle);

						},
						function() {$("#d3_tooltipLegend"+m+block).remove();});
				})(m);
				
				
			}
		}
						
		// Maximum checkboxes checked: 4 / Minimum: 1
		if ($("#"+blockID+" :checkbox.d3_checkboxClass:checked").length >= 4) {
			$("#"+blockID+" :checkbox.d3_checkboxClass").not(":checked").attr("disabled", "disabled");
			$("#d3_SelectDiagramsText"+block).addClass("d3_tooManySelectionsTextClass");
		} else {
			$("#"+blockID+" :checkbox.d3_checkboxClass").not(":checked").attr("disabled", "");
			$("#d3_SelectDiagramsText"+block).removeClass("d3_tooManySelectionsTextClass");
		}
		var minChecked = $("#"+blockID+" :checkbox.d3_checkboxClass:checked").length <= 1;
		$("#"+blockID+" :checkbox.d3_checkboxClass:checked").attr("disabled", minChecked);
		
		// Accordion for Legend
		$("#d3_legendDiv"+block).accordion({
			event: "click hoverintent",
			autoHeight: false,
			changestart: function( event, ui ) {
				accordionShowCheckedKeys();
			}
		});
		
		// Show checked checkboxes when accordion is inactive 
		function accordionShowCheckedKeys() {
			// Remove old checkboxes
			for (var i=0; i<groupArray.length; i++) {
				if ($("#d3_keys"+groupArray[i][1]+"_TEMP"+block).length>0) {
					$("#d3_keys"+groupArray[i][1]+"_TEMP"+block).remove();
				}
			}
			
			// Find active accordion header
			var legendDivActive=$("#d3_legendDiv"+block).accordion("option", "active");

			for (var i=0; i<groupArray.length; i++) {
				if (i!==legendDivActive) {
					$("#legend"+groupArray[i][1]+"Group"+block).append("<div id='d3_keys"+groupArray[i][1]+"_TEMP"+block+"'</div>");
					
					for (var k=0; k<group[groupArray[i][1]].length; k++) {
						if ($("#d3_checkbox"+groupArray[i][1]+k+block).is(":checked")) {
							$("#d3_keys"+groupArray[i][1]+"_TEMP"+block).append("<div id='d3_keys"+groupArray[i][1]+"Tick_TEMP"+k+block+"' class='d3_keysTick'><input type='checkbox' checked></div>");			
							$("#d3_keys"+groupArray[i][1]+"_TEMP"+block).append("<div id='d3_keys"+groupArray[i][1]+"BoxText_TEMP"+k+block+"'></div>");
							$("#d3_keys"+groupArray[i][1]+"_TEMP"+block).append("&nbsp;");
							$("#d3_keys"+groupArray[i][1]+"BoxText_TEMP"+k+block).append("<div id='keys"+groupArray[i][1]+"Text_TEMP"+k+block+"' class='d3_keysText'></div>");
							$("#keys"+groupArray[i][1]+"Text_TEMP"+k+block).append(group[groupArray[i][1]][k][2]);
							if (group[groupArray[i][1]][k][4] === "1") {
								$("#d3_keys"+groupArray[i][1]+"BoxText_TEMP"+k+block).append("<div id='keys"+groupArray[i][1]+"Icon"+k+block+"' class='d3_keysIcon'>"+partOfSVGBar1+group[groupArray[i][1]][k][1]+partOfSVGBar2+group[groupArray[i][1]][k][1]+partOfSVGBar3+group[groupArray[i][1]][k][1]+partOfSVGBar4+group[groupArray[i][1]][k][1]+partOfSVGBar5+group[groupArray[i][1]][k][1]+partOfSVGBar6+"</div>");
							} else {
								$("#d3_keys"+groupArray[i][1]+"BoxText_TEMP"+k+block).append("<div id='keys"+groupArray[i][1]+"Icon"+k+block+"' class='d3_keysIcon'>"+partOfSVGLine1+group[groupArray[i][1]][k][1]+partOfSVGLine2+"</div>");
							}	
						}	
					}
				}
			}
		}
		accordionShowCheckedKeys();

		// Print preview button
		$("#"+blockID).append("<div id='printSelectWrapper"+block+"' class='printSelectWrapperClass'></div>");
		$("#printSelectWrapper"+block)
			.css("width", legendWidth)
			.css("height", heightPrintSelect);

		$("#printSelectWrapper"+block).append("<div id='d3_SelectDiagramsText"+block+"' class='d3_SelectDiagramsTextClass'>Select up to 4 indices</div>");		
		
		$("#printSelectWrapper"+block).append("<div id='d3_SelectTrendline"+block+"' class='d3_SelectTrendlineClass'><input id='d3_checkboxTrendline"+block+"' class='d3_checkboxTrendlineClass' type='checkbox' value='trendline'>Trendline</div>");		
		
		$("#printSelectWrapper"+block).append("<div id='d3_printPreviewId"+block+"' class='d3_printPreviewClass'><img src='"+settings.basePath+printIcon+"' width='16' height='16'><span style='font-size:14px;'>&nbsp;&nbsp;Print</span></div>");
		$("#d3_printPreviewId"+block).hover(function() {
			$(this).css("cursor","pointer").css("background-color", "#9E9E9E");
		}, function () {$(this).css("cursor","default").css("background-color", "#b3b3b3");});
		$("#d3_printPreviewId"+block).click(function() {
			printPreview();
		});

		// *** Redraw the Graph - START ***
		function redrawGraph() {
			var findIDs = {};
			for (var i=0; i<groupArray.length; i++) {
				if (document.getElementById("d3_keysDiv"+groupArray[i][1]+block)) {
					findIDs[groupArray[i][1]] = $("#d3_keysDiv"+groupArray[i][1]+block+" input:checkbox:checked").map(function() {		        
						return $(this).val();      
					});
					findTicksArray[groupArray[i][1]] = findIDs[groupArray[i][1]].get();
				}
			}

			// Which parameters are selected
			var shownSingle = {};
			for (var i=0; i<groupArray.length; i++) {
				groupShown[groupArray[i][1]] = [];
				//var shownSingle[groupArray[i]];
				for (var k=0; k<findTicksArray[groupArray[i][1]].length; k++) {
					shownSingle[groupArray[i][1]] = group[groupArray[i][1]][parseFloat(findTicksArray[groupArray[i][1]][k])];
					groupShown[groupArray[i][1]].push(shownSingle[groupArray[i][1]]);		
				}
			}
			
			// Fill the unit groups arrays
			fillUnitGroups();
			
			// Which and how many Y-Axes we need
			findAxis();

			// Remove the whole graph
			d3.select("#d3_GraphDiv"+block).remove();
			
			// Update X range
			xScale.range([0, (width+(margin.left_single*axis_sum)-(margin.left_single*axis_selection))]);
			
			// Update Y range
			for (var i=0; i<unitsArray.length; i++) {
				d3Units["yScale"+unitsArray[i][0]].range([height, 0]);
			}
			
			// Create again the svg
			createSvg();
			
			// Find the max and min values for the Y scales
			findMaxMin();
			
			// Update Y domains
			for (var i=0; i<unitsArray.length; i++) {
				d3Units["yScale"+unitsArray[i][0]].domain([d3Units["min"+unitsArray[i][0]+"Y"], d3Units["max"+unitsArray[i][0]+"Y"]]);
			}
								
			// Redraw Graphs
			drawGraphs();
			
			// Redraw Y-Axes
			for (var i=0; i<yAxisArray.length; i++) {
				yAxisDraw(yAxisArray[i][0], yAxisArray[i][1], i);
			}
			
			// Redraw X axis
			xAxisDraw();
			
			// Add again CSS for the axes
			addCss();
			
			// Call hover function
			hover();
		}	
		// *** Redraw the Graph - END *** 
		
		// Not Yearly Data? Disable Trendline checkbox
		if (info.range === "Yearly") {
			$("#d3_checkboxTrendline"+block).attr("disabled", "");
			$("#d3_SelectTrendline"+block).css("color", "black");
		} else {
			$("#d3_checkboxTrendline"+block).attr("disabled", "disabled");
			$("#d3_SelectTrendline"+block).css("color", "#808080");
		}

		// Click checkbox
		$("#"+blockID+" :checkbox").click(function() {
			// Maximum checkboxes checked: 4 / Minimum: 1
			if ($("#"+blockID+" :checkbox.d3_checkboxClass:checked").length >= 4) {
				$("#"+blockID+" :checkbox.d3_checkboxClass").not(":checked").attr("disabled", "disabled");
				$("#d3_SelectDiagramsText"+block).addClass("d3_tooManySelectionsTextClass");
			} else {
				$("#"+blockID+" :checkbox.d3_checkboxClass").not(":checked").attr("disabled", "");
				$("#d3_SelectDiagramsText"+block).removeClass("d3_tooManySelectionsTextClass");
			}
			var minChecked = $("#"+blockID+" :checkbox.d3_checkboxClass:checked").length <= 1;
			$("#"+blockID+" :checkbox.d3_checkboxClass:checked").attr("disabled", minChecked);	
			
			// Redraw graph
			redrawGraph();
		});
		
		// Maximize-minimize Window	
		$(".portlet-maximize").click(function(){
			setTimeout(function() { 
				// Get new width
				widthDiv = $("#"+blockID).width();
				width = widthDiv - margin.left - margin.right - legendWidth;
				height = width/2;
				$("#d3_legendDiv"+block).css("height", height + margin.top + margin.bottom - heightPrintSelect);
				
				// Update scrollbar height
				$("#ccis-weather-d3-block-1").children(".slimScrollDiv")[0].style.setProperty("height", height + margin.top + margin.bottom - heightPrintSelect+"px");
			
				// Redraw graph
				redrawGraph();
			}, 1);
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
				
				// Find the Units
				function findHoverUnits(label) {
					for (var i=0; i<unitsArray.length; i++) {
						switch (label) {
							case unitsArray[i][0]:
								return unitsArray[i][4];
								break;
						}
					}
				}
				
				if (item) {
					// Format the date
					var dateParse = d3.time.format("%a %b %d %Y").parse(item.date.toDateString());
					var formatter = d3.time.format("%Y-%m-%d");
					var date = formatter(dateParse);
					
					// Show the icons?
					var showIcons = {};
					for (var i=0; i<groupArray.length; i++) {
						showIcons[groupArray[i][1]] = false;
						if (groupShown[groupArray[i][1]].length>0) {
							showIcons[groupArray[i][1]] = true;
						}
					}

					// Create content for tooltips
					var tooltipText="";
					tooltipText = "<table style='margin:0px;'>";
						
						tooltipText += "<tr>";
							tooltipText += "<td>&nbsp;<img src='"+settings.basePath+dateIcon+"' width='11' height='12'></td>";
							tooltipText += "<td>&nbsp;Date </td>";
							tooltipText += "<td>"+date+"</td>";
						tooltipText += "</tr>";	
						
						for (var i=0; i<groupArray.length; i++) {
							for (var k=0; k<groupShown[groupArray[i][1]].length; k++) {
								if (showIcons[groupArray[i][1]] === true) {
									var iconFilename;
									for (var m=0; m<groupIconsArray.length; m++) {
										if (groupArray[i][0] === groupIconsArray[m][0]) {
											iconFilename = groupIconsArray[m][1];
										}
									}
									tooltipText += "<tr style='border-top: 1px solid #e6e6e6;'>";
									if (iconFilename.length>0) {
										tooltipText += "<td>&nbsp;<img src='"+iconFilename+"' width='7' height='21'></td>";
									} else {
										tooltipText += "<td>&nbsp;</td>";
									}
									showIcons[groupArray[i][1]] = false;
								} else {
									tooltipText += "<tr>";
									tooltipText += "<td></td>";
								}
								tooltipText += "<td style='color:"+groupShown[groupArray[i][1]][k][1]+"'>&nbsp;"+groupShown[groupArray[i][1]][k][2]+"</td>";
								if (item[groupShown[groupArray[i][1]][k][0]]) {
									tooltipText += "<td style='color:"+groupShown[groupArray[i][1]][k][1]+"'>"+item[groupShown[groupArray[i][1]][k][0]].toFixed(1)+" "+findHoverUnits(groupShown[groupArray[i][1]][k][5])+"</td>";
								} else {
									tooltipText += "<td style='color:"+groupShown[groupArray[i][1]][k][1]+"'>No Data</td>";
								}
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
			
			$(newWindow).ready(function() {
		
				// Clone Diagram
				var clone = $("#d3_GraphDiv"+block).clone();
				// Remove background color and border
				clone[0].firstChild.setAttribute("style", "background-color: ; outline: ;");
				
				// Get html
				var html = clone.html();

				// Get the name of the Station
				var stationName = stations[0].name;
				
				var printKeys = "";
				for (var i=0; i<groupArray.length; i++) {
					for (var k=0; k<groupShown[groupArray[i][1]].length; k++) {
						printKeys += "<br><div style='height:0px; width:10px; border-top: 5px solid "+groupShown[groupArray[i][1]][k][1]+"; border-bottom: 5px solid "+groupShown[groupArray[i][1]][k][1]+"; outline:solid 1px black; float:left; margin-left:5px; margin-right:5px; margin-top:3px;'></div><span class='d3_printKeys'>"+groupShown[groupArray[i][1]][k][3]+"</span>";
					}
				}
				
				// Add the content
				newWindow.document.open();						
				newWindow.document.write("<html><head><title>Dashboard | CCIS - Print Diagram</title>");
				newWindow.document.write("<link rel='stylesheet' href='"+settings.basePath+"sites/all/modules/custom/ccis/css/d3.css' type='text/css' />");
				newWindow.document.write("</head><body>");
				newWindow.document.write("<div class='d3_printDiv'><span class='d3_printTitle'>Station: "+stationName+"</span><br/><span class='d3_printDiagDiv''>"+html+"</span>"+printKeys+"</div>");
				newWindow.document.write("</body></html>");
				newWindow.document.close();
				newWindow.print();
				newWindow.close();

			});
		}
	}
	// ***************************************
	// ********** DIAGRAM 1 - END ************
	// ***************************************

	

	// ***************************************
	// ********** DIAGRAM 2 - START **********
	// ***************************************
	function diagram2(blockID, data, dataKeysArray, minDate, maxDate) {					
		// *** Variables - START ***
		var block = "_2";
		var margin = {top: 20, right: 10, bottom: 25, left: 140, left_single: 35};
		var widthDiv = $("#"+blockID).width();
		var legendWidth = 150;
		var tooltipWidth = 200;
		var width = widthDiv - margin.left - margin.right - legendWidth;
		var height = width/2;
		var heightPrintSelect = 45;
		var axis_sum = 4;	// MAX: 4
		var axis_selection;
		var svg;	
		var mouseX;
		var mouseY;
		var yAxisArray;
		
		// Object for the Units
		var d3Units = {};
		
		// Arrays for the checkboxes
		var findTicksArray = {};
		
		// *** Variables - END ***
		
		// Define groups that are visible in the graph (maximum 4 parameters total for all groups)
		var groupShown = {};
		for (var i=0; i<groupArray.length; i++) {
			groupShown[groupArray[i][1]] = [];
		}
		
		// Choose initial parameters to show (the first available)
		if (groupArray.length>0) {
			if (group[groupArray[0][1]].length>0) {
				groupShown[groupArray[0][1]] = [group[groupArray[0][1]][0]];
			}
		}
		
		// Fill the unit groups arrays
		function fillUnitGroups() {
			for (var k=0; k<unitsArray.length; k++) {
				d3Units[unitsArray[k][0]+"GroupShown"] = [];
			}

			for (var i=0; i<groupArray.length; i++) {
				for (var k=0; k<groupShown[groupArray[i][1]].length; k++) {
					for (var j=0; j<unitsArray.length; j++) {
						if (groupShown[groupArray[i][1]][k][5] === unitsArray[j][0]) {
							d3Units[unitsArray[j][0]+"GroupShown"].push(groupShown[groupArray[i][1]][k][0]);
						}
					}
				}
			}
		}
		fillUnitGroups();

		// Find the max and min values for the Y scales
		function findMaxMin() {
			for (var i=0; i<unitsArray.length; i++) {
				d3Units["min"+unitsArray[i][0]+"YArray"] = [];
				d3Units["max"+unitsArray[i][0]+"YArray"] = [];
				for (var k=0; k<d3Units[unitsArray[i][0]+"GroupShown"].length; k++) {
					d3Units["min"+unitsArray[i][0]+"YArray"].push(d3.min(data, function(d) { return Math.min(d[d3Units[unitsArray[i][0]+"GroupShown"][k]]); }) );
					d3Units["max"+unitsArray[i][0]+"YArray"].push(d3.max(data, function(d) { return Math.max(d[d3Units[unitsArray[i][0]+"GroupShown"][k]]); }) );
				}
				d3Units["min"+unitsArray[i][0]+"Y"] = d3.min(d3Units["min"+unitsArray[i][0]+"YArray"]);
				d3Units["max"+unitsArray[i][0]+"Y"] = d3.max(d3Units["max"+unitsArray[i][0]+"YArray"]);
			}
		}
		findMaxMin();
		
		// Y Scales
		for (var i=0; i<unitsArray.length; i++) {
			d3Units["yScale"+unitsArray[i][0]] = d3.scale.linear()
				.domain([d3Units["min"+unitsArray[i][0]+"Y"], d3Units["max"+unitsArray[i][0]+"Y"]])
				.range([height, 0]);
		}
		
		// Which and how many Y-Axes we need
		function findAxis() {
			axis_selection = 0;
			yAxisArray = [];			
			for (var i=0; i<unitsArray.length; i++) {
				d3Units[unitsArray[i][0]+"_selection"] = true;
				if (d3Units[unitsArray[i][0]+"GroupShown"].length>0)  {
					d3Units[unitsArray[i][0]+"_selection"] = false;
					//yAxisArray.push([d3Units["yAxis"+unitsArray[i][0]], d3Units["yScale"+unitsArray[i][0]], unitsArray[i][0]]);
					yAxisArray.push([unitsArray[i][0], d3Units["yScale"+unitsArray[i][0]], unitsArray[i][2]]);
					axis_selection=axis_selection+1;
				}
			}
		}
		findAxis();
					
		// X Scale
		var xScale = d3.time.scale()
			.domain([minDate, maxDate])
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
		function graphDraw(graphType, yScale, color, lineORbar) {
			var yScaleType;
			for (var i=0; i<unitsArray.length; i++) {
				switch (yScale){
					case unitsArray[i][0]:
						yScaleType=d3Units["yScale"+unitsArray[i][0]];
						break;
				}
			}
			
			var graphObj = {};
			
			// Clip rects
			var clip = svg.append("svg:clipPath")
				.attr("id", "d3_clip");
			clip.append("svg:rect")
				.attr("width", (width + (margin.left_single)*axis_sum + margin.right))
				.attr("height", height);
							
			if (lineORbar === "1") {
				// Bars
				var barPadding = 3;
				var barWidth = ((width + (margin.left_single)*axis_sum + margin.right)/data.length)-barPadding;
				svg.selectAll("#d3_rectId")
					.data(data)
					.enter()
					.append("rect")
					.attr("id", "d3_rectId")
					.attr("clip-path", "url(#d3_clip)")		// Clip
					.attr("x", function(d) {return xScale(d.date)-barWidth;})
					.attr("y", function(d) {return yScaleType(d[graphType])-1;})
					.attr("width", barWidth+"px")
					.attr("height", function(d) {return height-yScaleType(d[graphType]);})
					.attr("fill", color);
			} else {
				// Lines for the rest				
				graphObj[graphType] = d3.svg.line()
					.interpolate("linear")
					.x(function(d){return xScale(d.date)})
					.y(function(d){return yScaleType(d[graphType])})
					.defined(function(d) {return !isNaN(d[graphType]);});	// do not show NaN

				d3.select("#svg"+block)
					.append("path")
					.attr("clip-path", "url(#d3_clip)")		// Clip
					.attr("id", "d3_path"+graphType+"ID"+block)
					.attr("d", graphObj[graphType](data))
					.attr("stroke", color)
					.attr("stroke-width", "2")
					.attr("fill", "none")
					.attr("transform", "translate(" + (margin.left-((margin.left_single*axis_sum)-(margin.left_single*axis_selection))) + "," + margin.top + ")");	  
			}
			
			// Trendline - START	
			if ($("#d3_checkboxTrendline"+block).is(":checked")) {

				var trendArrayX = [];
				var trendArrayY = [];
				for (var i=0; i<data.length; i++) {
					// Don't use data if isNaN
					if (!isNaN(data[i][graphType])) {
						trendArrayX.push(xScale(data[i].date));
						trendArrayY.push(yScaleType(data[i][graphType]));
					}
				}
				
				// Calculate Linear Regression
				function linearRegression(y,x){

						var lr = {};
						var n = y.length;
						var sum_x = 0;
						var sum_y = 0;
						var sum_xy = 0;
						var sum_xx = 0;
						var sum_yy = 0;

						for (var i = 0; i < y.length; i++) {

							sum_x += x[i];
							sum_y += y[i];
							sum_xy += (x[i]*y[i]);
							sum_xx += (x[i]*x[i]);
							sum_yy += (y[i]*y[i]);
						} 

						lr['slope'] = (n * sum_xy - sum_x * sum_y) / (n*sum_xx - sum_x * sum_x);
						lr['intercept'] = (sum_y - lr.slope * sum_x)/n;
						lr['r2'] = Math.pow((n*sum_xy - sum_x*sum_y)/Math.sqrt((n*sum_xx-sum_x*sum_x)*(n*sum_yy-sum_y*sum_y)),2);

						return lr;

				};

				var lr = linearRegression(trendArrayY, trendArrayX);
				// We get: lr.slope - lr.intercept - lr.r2
				
				var max = d3.max(trendArrayX);
				var myLine = d3.select("#svg"+block).append("svg:line")
					.attr("x1", 0)
					.attr("y1", lr.intercept)
					.attr("x2", max)
					.attr("y2", ( (max * lr.slope) + lr.intercept ))
					.attr("stroke", color)
					.attr("stroke-width", "2")
					.style("stroke-dasharray", ("3, 3"))
					.attr("transform", "translate(" + (margin.left-((margin.left_single*axis_sum)-(margin.left_single*axis_selection))) + "," + margin.top + ")");			
			}	
			// Trendline - END
		}

		function drawGraphs() {
			for (var i=0; i<groupArray.length; i++) {
				for (var k=0; k<groupShown[groupArray[i][1]].length; k++) {
					graphDraw(groupShown[groupArray[i][1]][k][0], groupShown[groupArray[i][1]][k][5], groupShown[groupArray[i][1]][k][1], groupShown[groupArray[i][1]][k][4]);
				}
			}	
		}
		drawGraphs();

		// Draw Y Axis
		function yAxisDraw(axisType, scaleType, axisPosition) {
			var yAxisObj = {};
			var yAxisLabel;
			var yAxisLabelOffset;
			var yAxisTickFormat;
			var iconLink;
			var iconWidth;
			var iconHeight;
			
			for (var i=0; i<unitsArray.length; i++) {
				if (axisType===unitsArray[i][0]) {
					yAxisLabel = unitsArray[i][2];
					var axisTypeID = axisType.replace(/ /g,'');	// Remove whitespaces
					yAxisLabelOffset = -30;
					yAxisTickFormat = unitsArray[i][3];
					if (unitsArray[i][1].length>0) {
						iconLink = unitsArray[i][1];
					} else {
						iconLink = "";
					}
					iconWidth = "10px";
					iconHeight = "20px";
				}
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
				.attr("id", axisTypeID+"id"+block)
				.attr("class", "d3_yAxisClass")
				.style("font-size","10px")
				.attr("transform", "translate("+(axisPosition*(-margin.left_single))+",0)")
				.call(yAxisObj[axisType]);
			d3.select("#"+axisTypeID+"id"+block)
				.append("text")
				.text(yAxisLabel)
				.attr("class", "d3_yAxisText")
				.style("font-size","12px")
				.attr("transform", "translate ("+yAxisLabelOffset+", -7)");
			
			d3.select("#"+axisTypeID+"id"+block)
				.append("image")
				.attr("xlink:href", iconLink)
				.attr("width", iconWidth)
				.attr("height", iconHeight)
				.attr("transform", "translate (-20, "+(height+3)+")");
		}
		
		// Call the Y Axis draw function
		for (var i=0; i<yAxisArray.length; i++) {
			yAxisDraw(yAxisArray[i][0], yAxisArray[i][1], i);
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

		// Hoverintent for legend accordion			
		$.event.special.hoverintent = {
			setup: function () {
				$(this).bind("mouseover", jQuery.event.special.hoverintent.handler);
			},
			teardown: function () {
				$(this).unbind("mouseover", jQuery.event.special.hoverintent.handler);
			},
			handler: function (event) {
				var currentX, currentY, timeout,
				args = arguments,
				target = $(event.target),
				previousX = event.pageX,
				previousY = event.pageY;

				function track(event) {
					currentX = event.pageX;
					currentY = event.pageY;
				};

				function clear() {
					target
					.unbind("mousemove", track)
					.unbind("mouseout", clear);
					clearTimeout(timeout);
				}

				function handler() {
					var prop,
					orig = event;
					if ((Math.abs(previousX - currentX) +
					Math.abs(previousY - currentY)) < 7) {
						clear();
						event = $.Event("hoverintent");
						for (prop in orig) {
							if (!(prop in event)) {
								event[prop] = orig[prop];
							}
						}
						delete event.originalEvent;
						target.trigger(event);
					} else {
						previousX = currentX;
						previousY = currentY;
						timeout = setTimeout(handler, 100);
					}
				}
				timeout = setTimeout(handler, 100);
				target.bind({
				mousemove: track,
				mouseout: clear
				});
			}
		};
		
		// Legend Tooltips
		function hoverLegend(topPosition, keyPlace, text) {			
			$("#d3_tooltipLegend"+keyPlace+block)
				.css("position", "absolute")
				.css("right", (legendWidth-3)+"px")
				.css("top", (topPosition-5)+"px")
				.css("width", "auto")
				.css("clear", "both")
				.css("float", "left")
				.css("background-color", "#fcce00")
				.css("border", "solid 1px #e6e6e6")
				.css("border-radius", "8px 8px 8px 8px")
				.css("-webkit-box-shadow", "4px 4px 10px rgba(0, 0, 0, 1)")
				.css("-moz-box-shadow", "4px 4px 10px rgba(0, 0, 0, 1)")
				.css("box-shadow", "4px 4px 10px rgba(0, 0, 0, 1)")
				.css("padding", "3px")
				.css("font-size","12px")
				.html(text);
		}

		// Add div for the legend
		$("#"+blockID).append("<div id='d3_legendDiv"+block+"' class='d3_legendClass'></div>");
		
		$("#d3_legendDiv"+block)
			.css("width", legendWidth)
			.css("height", height + margin.top + margin.bottom - heightPrintSelect);
			
		// Scrollbar (slimScroll)
		$("#d3_legendDiv"+block).slimScroll({
			width: legendWidth,
			height: height + margin.top + margin.bottom - heightPrintSelect,
			//railVisible: true,
			alwaysVisible: true,
			//railColor: "yellow",
			color: "#455468"
		});
		
		// Create DIVs for the keys
		for (var i=0; i<groupArray.length; i++) {
			$("#d3_legendDiv"+block).append("<h6><a href='#'><div id='legend"+groupArray[i][1]+"Group"+block+"'></div></a></h6>");
			for (var k=0; k<groupIconsArray.length; k++) {
				if (groupArray[i][0]===groupIconsArray[k][0]) {
					if (groupIconsArray[k][1].length>0) {
						$("#legend"+groupArray[i][1]+"Group"+block).append("<div id='d3_iconLegend"+block+"' class='d3_iconLegendClass'><img src='"+groupIconsArray[k][1]+"' width='15' height='20'> "+groupArray[i][0]+"</div>");
					} else {
						$("#legend"+groupArray[i][1]+"Group"+block).append("<div id='d3_iconLegend"+block+"' class='d3_iconLegendClass'> "+groupArray[i][0]+"</div>");
					}
				}
			}
			$("#d3_legendDiv"+block).append("<div id='d3_keysDiv"+groupArray[i][1]+block+"'></div>");
			
			for (var m=0; m<group[groupArray[i][1]].length; m++) {
				function findTemperatureChecked() {
					for (var j=0; j<groupShown[groupArray[i][1]].length; j++) {
						if (group[groupArray[i][1]][m][0]===groupShown[groupArray[i][1]][j][0]) {
							return "checked";
						}
					}
				}
				$("#d3_keysDiv"+groupArray[i][1]+block).append("<div id='d3_keys"+groupArray[i][1]+m+block+"' class='d3_keys'></div>");
				$("#d3_keys"+groupArray[i][1]+m+block).append("<div id='d3_keys"+groupArray[i][1]+"Tick"+m+block+"' class='d3_keysTick'><input id='d3_checkbox"+groupArray[i][1]+m+block+"' class='d3_checkboxClass' type='checkbox' value='"+m+"' "+findTemperatureChecked()+"></div>");
				$("#d3_keys"+groupArray[i][1]+m+block).append("<div id='d3_keys"+groupArray[i][1]+"BoxText"+m+block+"' class='d3_keysBoxText'></div>");
				$("#d3_keys"+groupArray[i][1]+"BoxText"+m+block).append("<div id='keys"+groupArray[i][1]+"Text"+m+block+"' class='d3_keysText'></div>");
				$("#keys"+groupArray[i][1]+"Text"+m+block).append(group[groupArray[i][1]][m][2]);
				
				if (group[groupArray[i][1]][m][4] === "1") {
					$("#d3_keys"+groupArray[i][1]+"BoxText"+m+block).append("<div id='keys"+groupArray[i][1]+"Icon"+m+block+"' class='d3_keysIcon'>"+partOfSVGBar1+group[groupArray[i][1]][m][1]+partOfSVGBar2+group[groupArray[i][1]][m][1]+partOfSVGBar3+group[groupArray[i][1]][m][1]+partOfSVGBar4+group[groupArray[i][1]][m][1]+partOfSVGBar5+group[groupArray[i][1]][m][1]+partOfSVGBar6+"</div>");
				} else {
					$("#d3_keys"+groupArray[i][1]+"BoxText"+m+block).append("<div id='keys"+groupArray[i][1]+"Icon"+m+block+"' class='d3_keysIcon'>"+partOfSVGLine1+group[groupArray[i][1]][m][1]+partOfSVGLine2+"</div>");
				}
				
				// Hover function
				(function(m) {
					$("#d3_keys"+groupArray[i][1]+"BoxText"+m+block)
						.hover(function(){
							$(this).css("cursor","default"); 
							// Create div for tooltip
							$("#"+blockID).append("<div id='d3_tooltipLegend"+m+block+"'></div>");
							// Find position
							var topPositionKeysDiv = $(this).parent().parent().position().top;
							var topPositionBoxText = $(this).position().top;
							var topPosition = topPositionKeysDiv + topPositionBoxText;
							// Find title
							var findTitle = this.id;
							findTitle = findTitle.slice(7);
							var findTitleIndexTemp = findTitle.indexOf("BoxText");
							findTitle = findTitle.slice(0, findTitleIndexTemp);
							var findIndex = this.id.slice(7+findTitleIndexTemp+7, -2);
							var hoverTitle = group[findTitle][findIndex][3];
							// Call legend function
							hoverLegend(topPosition, m, hoverTitle);

						},
						function() {$("#d3_tooltipLegend"+m+block).remove();});
				})(m);
				
				
			}
		}
						
		// Maximum checkboxes checked: 4 / Minimum: 1
		if ($("#"+blockID+" :checkbox.d3_checkboxClass:checked").length >= 4) {
			$("#"+blockID+" :checkbox.d3_checkboxClass").not(":checked").attr("disabled", "disabled");
			$("#d3_SelectDiagramsText"+block).addClass("d3_tooManySelectionsTextClass");
		} else {
			$("#"+blockID+" :checkbox.d3_checkboxClass").not(":checked").attr("disabled", "");
			$("#d3_SelectDiagramsText"+block).removeClass("d3_tooManySelectionsTextClass");
		}
		var minChecked = $("#"+blockID+" :checkbox.d3_checkboxClass:checked").length <= 1;
		$("#"+blockID+" :checkbox.d3_checkboxClass:checked").attr("disabled", minChecked);
		
		// Accordion for Legend
		$("#d3_legendDiv"+block).accordion({
			event: "click hoverintent",
			autoHeight: false,
			changestart: function( event, ui ) {
				accordionShowCheckedKeys();
			}
		});
		
		// Show checked checkboxes when accordion is inactive 
		function accordionShowCheckedKeys() {
			// Remove old checkboxes
			for (var i=0; i<groupArray.length; i++) {
				if ($("#d3_keys"+groupArray[i][1]+"_TEMP"+block).length>0) {
					$("#d3_keys"+groupArray[i][1]+"_TEMP"+block).remove();
				}
			}
			
			// Find active accordion header
			var legendDivActive=$("#d3_legendDiv"+block).accordion("option", "active");

			for (var i=0; i<groupArray.length; i++) {
				if (i!==legendDivActive) {
					$("#legend"+groupArray[i][1]+"Group"+block).append("<div id='d3_keys"+groupArray[i][1]+"_TEMP"+block+"'</div>");
					
					for (var k=0; k<group[groupArray[i][1]].length; k++) {
						if ($("#d3_checkbox"+groupArray[i][1]+k+block).is(":checked")) {
							$("#d3_keys"+groupArray[i][1]+"_TEMP"+block).append("<div id='d3_keys"+groupArray[i][1]+"Tick_TEMP"+k+block+"' class='d3_keysTick'><input type='checkbox' checked></div>");			
							$("#d3_keys"+groupArray[i][1]+"_TEMP"+block).append("<div id='d3_keys"+groupArray[i][1]+"BoxText_TEMP"+k+block+"'></div>");
							$("#d3_keys"+groupArray[i][1]+"_TEMP"+block).append("&nbsp;");
							$("#d3_keys"+groupArray[i][1]+"BoxText_TEMP"+k+block).append("<div id='keys"+groupArray[i][1]+"Text_TEMP"+k+block+"' class='d3_keysText'></div>");
							$("#keys"+groupArray[i][1]+"Text_TEMP"+k+block).append(group[groupArray[i][1]][k][2]);
							if (group[groupArray[i][1]][k][4] === "1") {
								$("#d3_keys"+groupArray[i][1]+"BoxText_TEMP"+k+block).append("<div id='keys"+groupArray[i][1]+"Icon"+k+block+"' class='d3_keysIcon'>"+partOfSVGBar1+group[groupArray[i][1]][k][1]+partOfSVGBar2+group[groupArray[i][1]][k][1]+partOfSVGBar3+group[groupArray[i][1]][k][1]+partOfSVGBar4+group[groupArray[i][1]][k][1]+partOfSVGBar5+group[groupArray[i][1]][k][1]+partOfSVGBar6+"</div>");
							} else {
								$("#d3_keys"+groupArray[i][1]+"BoxText_TEMP"+k+block).append("<div id='keys"+groupArray[i][1]+"Icon"+k+block+"' class='d3_keysIcon'>"+partOfSVGLine1+group[groupArray[i][1]][k][1]+partOfSVGLine2+"</div>");
							}	
						}	
					}
				}
			}
		}
		accordionShowCheckedKeys();

		// Print preview button
		$("#"+blockID).append("<div id='printSelectWrapper"+block+"' class='printSelectWrapperClass'></div>");
		$("#printSelectWrapper"+block)
			.css("width", legendWidth)
			.css("height", heightPrintSelect);

		$("#printSelectWrapper"+block).append("<div id='d3_SelectDiagramsText"+block+"' class='d3_SelectDiagramsTextClass'>Select up to 4 indices</div>");		
		
		$("#printSelectWrapper"+block).append("<div id='d3_SelectTrendline"+block+"' class='d3_SelectTrendlineClass'><input id='d3_checkboxTrendline"+block+"' class='d3_checkboxTrendlineClass' type='checkbox' value='trendline'>Trendline</div>");		
		
		$("#printSelectWrapper"+block).append("<div id='d3_printPreviewId"+block+"' class='d3_printPreviewClass'><img src='"+settings.basePath+printIcon+"' width='16' height='16'><span style='font-size:14px;'>&nbsp;&nbsp;Print</span></div>");
		$("#d3_printPreviewId"+block).hover(function() {
			$(this).css("cursor","pointer").css("background-color", "#9E9E9E");
		}, function () {$(this).css("cursor","default").css("background-color", "#b3b3b3");});
		$("#d3_printPreviewId"+block).click(function() {
			printPreview();
		});

		// *** Redraw the Graph - START ***
		function redrawGraph() {
			var findIDs = {};
			for (var i=0; i<groupArray.length; i++) {
				if (document.getElementById("d3_keysDiv"+groupArray[i][1]+block)) {
					findIDs[groupArray[i][1]] = $("#d3_keysDiv"+groupArray[i][1]+block+" input:checkbox:checked").map(function() {		        
						return $(this).val();      
					});
					findTicksArray[groupArray[i][1]] = findIDs[groupArray[i][1]].get();
				}
			}

			// Which parameters are selected
			var shownSingle = {};
			for (var i=0; i<groupArray.length; i++) {
				groupShown[groupArray[i][1]] = [];
				//var shownSingle[groupArray[i]];
				for (var k=0; k<findTicksArray[groupArray[i][1]].length; k++) {
					shownSingle[groupArray[i][1]] = group[groupArray[i][1]][parseFloat(findTicksArray[groupArray[i][1]][k])];
					groupShown[groupArray[i][1]].push(shownSingle[groupArray[i][1]]);		
				}
			}
			
			// Fill the unit groups arrays
			fillUnitGroups();
			
			// Which and how many Y-Axes we need
			findAxis();

			// Remove the whole graph
			d3.select("#d3_GraphDiv"+block).remove();
			
			// Update X range
			xScale.range([0, (width+(margin.left_single*axis_sum)-(margin.left_single*axis_selection))]);
			
			// Update Y range
			for (var i=0; i<unitsArray.length; i++) {
				d3Units["yScale"+unitsArray[i][0]].range([height, 0]);
			}
			
			// Create again the svg
			createSvg();
			
			// Find the max and min values for the Y scales
			findMaxMin();
			
			// Update Y domains
			for (var i=0; i<unitsArray.length; i++) {
				d3Units["yScale"+unitsArray[i][0]].domain([d3Units["min"+unitsArray[i][0]+"Y"], d3Units["max"+unitsArray[i][0]+"Y"]]);
			}
								
			// Redraw Graphs
			drawGraphs();
			
			// Redraw Y-Axes
			for (var i=0; i<yAxisArray.length; i++) {
				yAxisDraw(yAxisArray[i][0], yAxisArray[i][1], i);
			}
			
			// Redraw X axis
			xAxisDraw();
			
			// Add again CSS for the axes
			addCss();
			
			// Call hover function
			hover();
		}	
		// *** Redraw the Graph - END *** 
		
		// Not Yearly Data? Disable Trendline checkbox
		if (info.range === "Yearly") {
			$("#d3_checkboxTrendline"+block).attr("disabled", "");
			$("#d3_SelectTrendline"+block).css("color", "black");
		} else {
			$("#d3_checkboxTrendline"+block).attr("disabled", "disabled");
			$("#d3_SelectTrendline"+block).css("color", "#808080");
		}

		// Click checkbox
		$("#"+blockID+" :checkbox").click(function() {
			// Maximum checkboxes checked: 4 / Minimum: 1
			if ($("#"+blockID+" :checkbox.d3_checkboxClass:checked").length >= 4) {
				$("#"+blockID+" :checkbox.d3_checkboxClass").not(":checked").attr("disabled", "disabled");
				$("#d3_SelectDiagramsText"+block).addClass("d3_tooManySelectionsTextClass");
			} else {
				$("#"+blockID+" :checkbox.d3_checkboxClass").not(":checked").attr("disabled", "");
				$("#d3_SelectDiagramsText"+block).removeClass("d3_tooManySelectionsTextClass");
			}
			var minChecked = $("#"+blockID+" :checkbox.d3_checkboxClass:checked").length <= 1;
			$("#"+blockID+" :checkbox.d3_checkboxClass:checked").attr("disabled", minChecked);	
			
			// Redraw graph
			redrawGraph();
		});
		
		// Maximize-minimize Window	
		$(".portlet-maximize").click(function(){
			setTimeout(function() { 
				// Get new width
				widthDiv = $("#"+blockID).width();
				width = widthDiv - margin.left - margin.right - legendWidth;
				height = width/2;
				$("#d3_legendDiv"+block).css("height", height + margin.top + margin.bottom - heightPrintSelect);
				
				// Update scrollbar height
				$("#ccis-weather-d3-block-2").children(".slimScrollDiv")[0].style.setProperty("height", height + margin.top + margin.bottom - heightPrintSelect+"px");
			
				// Redraw graph
				redrawGraph();
			}, 1);
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
				
				// Find the Units
				function findHoverUnits(label) {
					for (var i=0; i<unitsArray.length; i++) {
						switch (label) {
							case unitsArray[i][0]:
								return unitsArray[i][4];
								break;
						}
					}
				}
				
				if (item) {
					// Format the date
					var dateParse = d3.time.format("%a %b %d %Y").parse(item.date.toDateString());
					var formatter = d3.time.format("%Y-%m-%d");
					var date = formatter(dateParse);
					
					// Show the icons?
					var showIcons = {};
					for (var i=0; i<groupArray.length; i++) {
						showIcons[groupArray[i][1]] = false;
						if (groupShown[groupArray[i][1]].length>0) {
							showIcons[groupArray[i][1]] = true;
						}
					}

					// Create content for tooltips
					var tooltipText="";
					tooltipText = "<table style='margin:0px;'>";
						
						tooltipText += "<tr>";
							tooltipText += "<td>&nbsp;<img src='"+settings.basePath+dateIcon+"' width='11' height='12'></td>";
							tooltipText += "<td>&nbsp;Date </td>";
							tooltipText += "<td>"+date+"</td>";
						tooltipText += "</tr>";	
						
						for (var i=0; i<groupArray.length; i++) {
							for (var k=0; k<groupShown[groupArray[i][1]].length; k++) {
								if (showIcons[groupArray[i][1]] === true) {
									var iconFilename;
									for (var m=0; m<groupIconsArray.length; m++) {
										if (groupArray[i][0] === groupIconsArray[m][0]) {
											iconFilename = groupIconsArray[m][1];
										}
									}
									tooltipText += "<tr style='border-top: 1px solid #e6e6e6;'>";
									if (iconFilename.length>0) {
										tooltipText += "<td>&nbsp;<img src='"+iconFilename+"' width='7' height='21'></td>";
									} else {
										tooltipText += "<td>&nbsp;</td>";
									}
									showIcons[groupArray[i][1]] = false;
								} else {
									tooltipText += "<tr>";
									tooltipText += "<td></td>";
								}
								tooltipText += "<td style='color:"+groupShown[groupArray[i][1]][k][1]+"'>&nbsp;"+groupShown[groupArray[i][1]][k][2]+"</td>";
								if (item[groupShown[groupArray[i][1]][k][0]]) {
									tooltipText += "<td style='color:"+groupShown[groupArray[i][1]][k][1]+"'>"+item[groupShown[groupArray[i][1]][k][0]].toFixed(1)+" "+findHoverUnits(groupShown[groupArray[i][1]][k][5])+"</td>";
								} else {
									tooltipText += "<td style='color:"+groupShown[groupArray[i][1]][k][1]+"'>No Data</td>";
								}
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
			
			$(newWindow).ready(function() {
		
				// Clone Diagram
				var clone = $("#d3_GraphDiv"+block).clone();
				// Remove background color and border
				clone[0].firstChild.setAttribute("style", "background-color: ; outline: ;");
				
				// Get html
				var html = clone.html();

				// Get the name of the Station
				var stationName = stations[1].name;
				
				var printKeys = "";
				for (var i=0; i<groupArray.length; i++) {
					for (var k=0; k<groupShown[groupArray[i][1]].length; k++) {
						printKeys += "<br><div style='height:0px; width:10px; border-top: 5px solid "+groupShown[groupArray[i][1]][k][1]+"; border-bottom: 5px solid "+groupShown[groupArray[i][1]][k][1]+"; outline:solid 1px black; float:left; margin-left:5px; margin-right:5px; margin-top:3px;'></div><span class='d3_printKeys'>"+groupShown[groupArray[i][1]][k][3]+"</span>";
					}
				}
				
				// Add the content
				newWindow.document.open();						
				newWindow.document.write("<html><head><title>Dashboard | CCIS - Print Diagram</title>");
				newWindow.document.write("<link rel='stylesheet' href='"+settings.basePath+"sites/all/modules/custom/ccis/css/d3.css' type='text/css' />");
				newWindow.document.write("</head><body>");
				newWindow.document.write("<div class='d3_printDiv'><span class='d3_printTitle'>Station: "+stationName+"</span><br/><span class='d3_printDiagDiv''>"+html+"</span>"+printKeys+"</div>");
				newWindow.document.write("</body></html>");
				newWindow.document.close();
				newWindow.print();
				newWindow.close();

			});
		}
	}
	// ***************************************
	// ********** DIAGRAM 2 - END ************
	// ***************************************
	
	// Hide Divs for D3
	$("#homebox-block-ccis_d3").hide();
	$("#homebox-block-ccis_d3_2").hide();
	
	// Variables used to find the date range we will display
	var minDate;
	var maxDate;
	var minDate2;
	var maxDate2;
	// Check which diagram will be displayed
	var drawDiagram1 = false;
	var drawDiagram2 = false;
	// Variables for diagrams data
	var dataKeysArray;
	var data;
	var obj;
	var dataKeysArray2;
	var data2;
	var obj2;
	
	// Diagram 1
	if (stations[0]) {
		if (stations[0].selector === "ccis-weather-d3-block-1" && stations[0].name.length>0) {
			$("#homebox-block-ccis_d3").show();

			var blockID = stations[0].selector;
			var json = stations[0].data;
			//d3.json(settings.ccis.stations[0].path, function(json) {
//				if (json.length===0) {
//					$("#"+blockID).html("");
//				} else {		
					$("#"+blockID).html("");
					
					drawDiagram1 = true;

					// Get parameters names
					dataKeysArray = Object.keys(json[0]);
					
					// Create object with the parameters and the values
					data = json.map(function(d) {
					obj = {};
						//obj.date: d3.time.format("%Y-%m-%d %H:%M:%S").parse(d.date.slice(0,-3); // Datum & Zeit ohne Zeitzone
						obj.date = d3.time.format("%Y-%m-%d").parse(d.date.slice(0,-12)); // Nur Datum
						// i=1: The first parameter is the Date
						for (var i=1; i<dataKeysArray.length; i++) {
							obj[dataKeysArray[i]] = parseFloat(d[dataKeysArray[i]]);
						}
						return obj;
					});
					
					// Find the data date range
					minDate = d3.min(data, function(d) { return d.date});
					maxDate = d3.max(data, function(d) { return d.date});
					
					// Check the 2nd diagram
					prepareDiagram2();	
				//}
			//});
		}
	}
	//diagram1(blockID, data, dataKeysArray, minDate, maxDate);
	// Find the common date range
	function findDateRange() {
		// Latest start Date
		minDate = d3.max([minDate, minDate2]);
		// Earliest end Date
		maxDate = d3.min([maxDate, maxDate2]);
	}
	
	// Diagram 2
	function prepareDiagram2() {
		if (typeof stations[1] != 'undefined') {
			if (stations[1].selector === "ccis-weather-d3-block-2" && stations[1].name.length>0) {
				$("#homebox-block-ccis_d3_2").show();
			
				var blockID2 = stations[1].selector;
				var json = stations[1].data;
				//d3.json(settings.ccis.stations[1].path, function(json) {
					if (json.length===0) {
						$("#"+blockID2).html("");
					} else {		
						$("#"+blockID2).html("");

						drawDiagram2 = true;	

						// Get parameters names
						dataKeysArray2 = Object.keys(json[0]);
						
						// Create object with the parameters and the values
						data2 = json.map(function(d) {
						obj2 = {};
							//obj.date: d3.time.format("%Y-%m-%d %H:%M:%S").parse(d.date.slice(0,-3); // Datum & Zeit ohne Zeitzone
							obj2.date = d3.time.format("%Y-%m-%d").parse(d.date.slice(0,-12)); // Nur Datum
							// i=1: The first parameter is the Date
							for (var i=1; i<dataKeysArray2.length; i++) {
								obj2[dataKeysArray2[i]] = parseFloat(d[dataKeysArray2[i]]);
							}
							return obj2;
						});
								
						minDate2 = d3.min(data2, function(d) { return d.date});
						maxDate2 = d3.max(data2, function(d) { return d.date});

						// Find the common date range
						findDateRange();
						
						// 2 diagrams: Draw both
						diagram1(blockID, data, dataKeysArray, minDate, maxDate);
						diagram2(blockID2, data2, dataKeysArray2, minDate, maxDate);
					}
				//});
			}
		} 	
		 else {
       // 1 diagram: Draw only the 1st
       diagram1(blockID, data, dataKeysArray, minDate, maxDate);
     }
	}
	
  // CUSTOM CODING END
  }
}
})(jQuery);