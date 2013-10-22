(function($) {
Drupal.behaviors.ccis = {
  attach: function(d_context, settings) {
  // CUSTOM CODING START

	// Groups of parameters available including the colors, the legend keywords, the legend hover names, the icons and the units
	// Position 0: Parameter
	// Position 1: Color
	// Position 2: Legend Keyword
	// Position 3: Legend Hover Name
	// Position 4: Icon
	// Position 5: Units
	var temperatureGroup = [
		["tx", "#FF0000", "TX", "Daily maximum temperature (&#8451;)", "symbol_legende_tg.png", "celsius"],
		["tn", "#FCB205", "TN", "Daily minimum temperature (&#8451;)", "symbol_legende_tn.png", "celsius"],
		["tg", "#FF8000", "TG", "Daily mean temperature (&#8451;)", "symbol_legende_tx.png", "celsius"],
		["dtr", "#FF8400", "DTR", "Daily temperature range (&#8451;)", "symbol_legende_rr.png", "celsius"]
	];
	var warmExtremesGroup = [
		["su", "#FB6A4A", "SU", "Number of summer days (days)", "symbol_legende_tg.png", "days"],
		["tr", "#EF3B2C", "TR", "Number of tropical nights (days)", "symbol_legende_tg.png", "days"],
		["txx", "#99000D", "Txx", "Monthly maximum value of TX (&#8451;)", "symbol_legende_tg.png", "celsius"],
		["tnx", "#CB181D", "Tnx", "Monthly maximum value of TN (&#8451;)", "symbol_legende_tg.png", "celsius"],
		["tn90p", "#FC9272", "TN90p", "Percentage of days when TN > 90th percentile (%)", "symbol_legende_tg.png", "percent"],
		["tx90p", "#D4B9DA", "TX90p", "Percentage of days when TX > 90th percentile (%)", "symbol_legende_tg.png", "percent"],
		["wsdi", "#DF65B0C", "WSDI", "Warm speel duration index (days)", "symbol_legende_tg.png", "days"]
	];
	var coldExtremesGroup = [
		["fd", "#5100FF", "FD", "Number of frost days (days)", "symbol_legende_tn.png", "days"],
		["id", "#7A3EFA", "ID", "Number of icing days (days)", "symbol_legende_tn.png", "days"],
		["txn", "#5E56F0", "Txn", "Monthly minimum value of TX (&#8451;)", "symbol_legende_tn.png", "celsius"],
		["tnn", "#5C72ED", "Tnn", "Monthly minimum value of TN (&#8451;)", "symbol_legende_tn.png", "celsius"],
		["tn10p", "#6B91E3", "TN10p", "Percentage of days when TN < 10th percentile (%)", "symbol_legende_tn.png", "percent"],
		["tx10p", "#6BA7E3", "TX10p", "Percentage of days when TX < 10th percentile (%)", "symbol_legende_tn.png", "percent"],
		["csdi", "#7FBED4", "CSDI", "Cold speel duration index (days)", "symbol_legende_tn.png", "days"]
	];
	var precipitationGroup = [
		["rr", "#9900FF", "RR", "Daily precipitation amount (mm)", "symbol_legende_rr.png", "milimeter"],
		["cwd", "#B87EDE", "CWD", "Maximum length of wet spell (days with RR = 1mm) (days)", "symbol_legende_rr.png", "days"],
		["prcptot", "#B897DB", "PRCPTOT", "Annual total precipitation in wet days (mm)", "symbol_legende_rr.png", "milimeter"]
	];
	var extremePrecipitationGroup = [
		["rx1day", "#00FFB3", "Rx1day", "Monthly maximum 1-day precipitation (mm)", "symbol_legende_rr.png", "milimeter"],
		["rx5day", "#00FF77", "Rx5day", "Monthly maximum consecutive 5-day precipitation (mm)", "symbol_legende_rr.png", "milimeter"],
		["sdii", "#1BCF45", "SDII", "Simple pricipitation intensity index (mm)", "symbol_legende_rr.png", "milimeter"],
		["r10mm", "#15B33A", "R10mm", "Annual count of days when PRCP= 10mm (days)", "symbol_legende_rr.png", "days"],
		["r20mm", "#96C98D", "R20mm", "Annual count of days when PRCP= 20mm (days)", "symbol_legende_rr.png", "days"],
		["rnnmm", "#A3C482", "Rnnmm", "Annual count of days when PRCP= nnmm (days)", "symbol_legende_rr.png", "days"],
		["r95ptot", "#91A86A", "R95pTOT", "Annual total PRCP when RR > 95p (mm)", "symbol_legende_rr.png", "milimeter"],
		["r99ptot", "#8B9C6E", "R99pTOT", "Annual total PRCP when RR > 99p (mm)", "symbol_legende_rr.png", "milimeter"]
	];
	var windGroup = [
		["fg", "#00BBC4", "FG", "Daily mean wind speed (m/s)", "symbol_legende_rr.png", "meterPerSecond"],
		["fx", "#8DC6C9", "FX", "Daily maximum wind gust (m/s)", "symbol_legende_rr.png", "meterPerSecond"],
		["dd", "#45ABB0", "DD", "Daily wind direction (degrees)", "symbol_legende_rr.png", "degrees"]
	];
	var otherGroup = [
		["gsl", "#FF9900", "GSL", "Growing season length (days)", "symbol_legende_rr.png", "days"],
		["cc", "#00FF00", "CC", "Daily cloud cover (octas)", "symbol_legende_rr.png", "octas"],
		["hu", "#33CCFF", "HU", "Daily humidity (%)", "symbol_legende_rr.png", "percent"],
		["pp", "#009900", "PP", "Daily mean sea level pressure (hPa)", "symbol_legende_rr.png", "pascal"],
		["cdd", "#996600", "CDD", "Maximum length of dry spell with RR < 1mm (days)", "symbol_legende_rr.png", "days"]
	];
	
	// ***************************************
	// ********** DIAGRAM 1 - START **********
	// ***************************************
	function diagram1() {
		// *** Variables - START ***
		var blockID = settings.ccis.stations[0].selector;
		var block = "_1";
		
		var margin = {top: 20, right: 10, bottom: 25, left: 140, left_single: 35};
		var widthDiv = $("#"+blockID).width();
		var legendWidth = 170;
		var tooltipWidth = 200;
		var width = widthDiv - margin.left - margin.right - legendWidth;
		var height = width/2;
		var heightPrintSelect = 50;
		var axis_sum = 4;	// MAX: 4
		var axis_selection;
		var svg;	
		var mouseX;
		var mouseY;
		var yAxisArray;
		
		var temperatureHidden;
		var warmExtremesHidden;
		var coldExtremesHidden;
		var precipitationHidden;
		var extremePrecipitationHidden;
		var windHidden;
		var otherHidden;
		
		// Unit groups shown at the graph (max: 4)
		var celsiusGroupShown;
		var daysGroupShown;
		var percentGroupShown;
		var milimeterGroupShown;
		var pascalGroupShown;
		var meterPerSecondGroupShown;
		var degreesGroupShown;
		var octasGroupShown;
		
		// Y-Scales
		var yScaleCelsius;
		var yScaleDays;
		var yScalePercent;
		var yScaleMilimeter;
		var yScalePascal;
		var yScaleMeterPerSecond;
		var yScaleDegrees;
		var yScaleOctas;
		
		// Max-Min Values for Y Scales
		// Celsius values
		var minCelsiusYArray;
		var maxCelsiusYArray;
		var minCelsiusY;
		var maxCelsiusY;
		// Days values
		var minDaysYArray;
		var maxDaysYArray;
		var minDaysY;
		var maxDaysY;
		// Percent values
		var minPercentYArray;
		var maxPercentYArray;
		var minPercentY;
		var maxPercentY;
		// Milimeter values
		var minMilimeterYArray;
		var maxMilimeterYArray;
		var minMilimeterY;
		var maxMilimeterY;
		// Pascal values
		var minPascalYArray;
		var maxPascalYArray;
		var minPascalY;
		var maxPascalY;
		// Meter per second values
		var minMeterPerSecondYArray;
		var maxMeterPerSecondYArray;
		var minMeterPerSecondY;
		var maxMeterPerSecondY;
		// Degrees values
		var minDegreesYArray;
		var maxDegreesYArray;
		var minDegreesY;
		var maxDegreesY;
		// Octas values
		var minOctasYArray;
		var maxOctasYArray;
		var minOctasY;
		var maxOctasY;
		
		// Arrays for the checkboxes
		var findTicksArrayTemperature = [];
		var findTicksArrayWarmExtremes = [];
		var findTicksArrayColdExtremes = [];
		var findTicksArrayPrecipitation = [];
		var findTicksArrayExtremePrecipitation = [];
		var findTicksArrayWind = [];
		var findTicksArrayOther = [];
		
		// Selection for Y Axis
		var celsius_selection;
		var days_selection;
		var percent_selection;
		var milimeter_selection;
		var pascal_selection;	
		var meterPerSecond_selection;
		var degrees_selection;
		var octas_selection;
		
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
				
				// Parameter groups parsed for the specific user
				var temperatureGroupUsed = [];
				var warmExtremesGroupUsed = [];
				var coldExtremesGroupUsed = [];
				var precipitationGroupUsed = [];
				var extremePrecipitationGroupUsed = [];
				var windGroupUsed = [];
				var otherGroupUsed = [];
				
				// Create an array per group with the parameters used, the colors, the legend keywords, the legend hover names, the icons and the units
				for (var i=2; i<dataKeysArray.length; i++) {
					for (var k=0; k<temperatureGroup.length; k++) {
						if (dataKeysArray[i]===temperatureGroup[k][0]) {
							temperatureGroupUsed.push([temperatureGroup[k][0], temperatureGroup[k][1], temperatureGroup[k][2], temperatureGroup[k][3], temperatureGroup[k][4], temperatureGroup[k][5]]);
						}
					}
					for (var k=0; k<warmExtremesGroup.length; k++) {
						if (dataKeysArray[i]===warmExtremesGroup[k][0]) {
							warmExtremesGroupUsed.push([warmExtremesGroup[k][0], warmExtremesGroup[k][1], warmExtremesGroup[k][2], warmExtremesGroup[k][3], warmExtremesGroup[k][4], warmExtremesGroup[k][5]]);
						}
					}
					for (var k=0; k<coldExtremesGroup.length; k++) {
						if (dataKeysArray[i]===coldExtremesGroup[k][0]) {
							coldExtremesGroupUsed.push([coldExtremesGroup[k][0], coldExtremesGroup[k][1], coldExtremesGroup[k][2], coldExtremesGroup[k][3], coldExtremesGroup[k][4], coldExtremesGroup[k][5]]);
						}
					}
					for (var k=0; k<precipitationGroup.length; k++) {
						if (dataKeysArray[i]===precipitationGroup[k][0]) {
							precipitationGroupUsed.push([precipitationGroup[k][0], precipitationGroup[k][1], precipitationGroup[k][2], precipitationGroup[k][3], precipitationGroup[k][4], precipitationGroup[k][5]]);
						}
					}
					for (var k=0; k<extremePrecipitationGroup.length; k++) {
						if (dataKeysArray[i]===extremePrecipitationGroup[k][0]) {
							extremePrecipitationGroupUsed.push([extremePrecipitationGroup[k][0], extremePrecipitationGroup[k][1], extremePrecipitationGroup[k][2], extremePrecipitationGroup[k][3], extremePrecipitationGroup[k][4], extremePrecipitationGroup[k][5]]);
						}
					}
					for (var k=0; k<windGroup.length; k++) {
						if (dataKeysArray[i]===windGroup[k][0]) {
							windGroupUsed.push([windGroup[k][0], windGroup[k][1], windGroup[k][2], windGroup[k][3], windGroup[k][4], windGroup[k][5]]);
						}
					}
					for (var k=0; k<otherGroup.length; k++) {
						if (dataKeysArray[i]===otherGroup[k][0]) {
							otherGroupUsed.push([otherGroup[k][0], otherGroup[k][1], otherGroup[k][2], otherGroup[k][3], otherGroup[k][4], otherGroup[k][5]]);
						}
					}
				}
				
				// Parameter groups shown at the graph (max: 4)
				var temperatureGroupShown = [];
				var warmExtremesGroupShown = [];
				var coldExtremesGroupShown = [];
				var precipitationGroupShown = [];
				var extremePrecipitationGroupShown = [];
				var windGroupShown = [];
				var otherGroupShown = [];
				
				// Choose initial parameters to show
				temperatureGroupShown = [temperatureGroupUsed[0]];
				
				// Fill the unit groups arrays
				function fillUnitGroups() {
				
					celsiusGroupShown = [];
					daysGroupShown = [];
					percentGroupShown = [];
					milimeterGroupShown = [];
					pascalGroupShown = [];
					meterPerSecondGroupShown = [];
					degreesGroupShown = [];
					octasGroupShown = [];
					

					for (var i=0; i<temperatureGroupShown.length; i++) {
						switch (temperatureGroupShown[i][5]) {
							case "celsius":
								celsiusGroupShown.push(temperatureGroupShown[i][0]);
								break;
							case "days":
								daysGroupShown.push(temperatureGroupShown[i][0]);
								break;
							case "percent":
								percentGroupShown.push(temperatureGroupShown[i][0]);
								break;
							case "milimeter":
								milimeterGroupShown.push(temperatureGroupShown[i][0]);
								break;
							case "pascal":
								pascalGroupShown.push(temperatureGroupShown[i][0]);
								break;
							case "meterPerSecond":
								meterPerSecondGroupShown.push(temperatureGroupShown[i][0]);
								break;
							case "degrees":
								degreesGroupShown.push(temperatureGroupShown[i][0]);
								break;
							case "octas":
								octasGroupShown.push(temperatureGroupShown[i][0]);
								break;
						}
					}
					for (var i=0; i<warmExtremesGroupShown.length; i++) {
						switch (warmExtremesGroupShown[i][5]) {
							case "celsius":
								celsiusGroupShown.push(warmExtremesGroupShown[i][0]);
								break;
							case "days":
								daysGroupShown.push(warmExtremesGroupShown[i][0]);
								break;
							case "percent":
								percentGroupShown.push(warmExtremesGroupShown[i][0]);
								break;
							case "milimeter":
								milimeterGroupShown.push(warmExtremesGroupShown[i][0]);
								break;
							case "pascal":
								pascalGroupShown.push(warmExtremesGroupShown[i][0]);
								break;
							case "meterPerSecond":
								meterPerSecondGroupShown.push(warmExtremesGroupShown[i][0]);
								break;
							case "degrees":
								degreesGroupShown.push(warmExtremesGroupShown[i][0]);
								break;
							case "octas":
								octasGroupShown.push(warmExtremesGroupShown[i][0]);
								break;
						}
					}
					for (var i=0; i<coldExtremesGroupShown.length; i++) {
						switch (coldExtremesGroupShown[i][5]) {
							case "celsius":
								celsiusGroupShown.push(coldExtremesGroupShown[i][0]);
								break;
							case "days":
								daysGroupShown.push(coldExtremesGroupShown[i][0]);
								break;
							case "percent":
								percentGroupShown.push(coldExtremesGroupShown[i][0]);
								break;
							case "milimeter":
								milimeterGroupShown.push(coldExtremesGroupShown[i][0]);
								break;
							case "pascal":
								pascalGroupShown.push(coldExtremesGroupShown[i][0]);
								break;
							case "meterPerSecond":
								meterPerSecondGroupShown.push(coldExtremesGroupShown[i][0]);
								break;
							case "degrees":
								degreesGroupShown.push(coldExtremesGroupShown[i][0]);
								break;
							case "octas":
								octasGroupShown.push(coldExtremesGroupShown[i][0]);
								break;
						}
					}
					for (var i=0; i<precipitationGroupShown.length; i++) {
						switch (precipitationGroupShown[i][5]) {
							case "celsius":
								celsiusGroupShown.push(precipitationGroupShown[i][0]);
								break;
							case "days":
								daysGroupShown.push(precipitationGroupShown[i][0]);
								break;
							case "percent":
								percentGroupShown.push(precipitationGroupShown[i][0]);
								break;
							case "milimeter":
								milimeterGroupShown.push(precipitationGroupShown[i][0]);
								break;
							case "pascal":
								pascalGroupShown.push(precipitationGroupShown[i][0]);
								break;
							case "meterPerSecond":
								meterPerSecondGroupShown.push(precipitationGroupShown[i][0]);
								break;
							case "degrees":
								degreesGroupShown.push(precipitationGroupShown[i][0]);
								break;
							case "octas":
								octasGroupShown.push(precipitationGroupShown[i][0]);
								break;
						}
					}			
					for (var i=0; i<extremePrecipitationGroupShown.length; i++) {
						switch (extremePrecipitationGroupShown[i][5]) {
							case "celsius":
								celsiusGroupShown.push(extremePrecipitationGroupShown[i][0]);
								break;
							case "days":
								daysGroupShown.push(extremePrecipitationGroupShown[i][0]);
								break;
							case "percent":
								percentGroupShown.push(extremePrecipitationGroupShown[i][0]);
								break;
							case "milimeter":
								milimeterGroupShown.push(extremePrecipitationGroupShown[i][0]);
								break;
							case "pascal":
								pascalGroupShown.push(extremePrecipitationGroupShown[i][0]);
								break;
							case "meterPerSecond":
								meterPerSecondGroupShown.push(extremePrecipitationGroupShown[i][0]);
								break;
							case "degrees":
								degreesGroupShown.push(extremePrecipitationGroupShown[i][0]);
								break;
							case "octas":
								octasGroupShown.push(extremePrecipitationGroupShown[i][0]);
								break;
						}
					}
					for (var i=0; i<windGroupShown.length; i++) {
						switch (windGroupShown[i][5]) {
							case "celsius":
								celsiusGroupShown.push(windGroupShown[i][0]);
								break;
							case "days":
								daysGroupShown.push(windGroupShown[i][0]);
								break;
							case "percent":
								percentGroupShown.push(windGroupShown[i][0]);
								break;
							case "milimeter":
								milimeterGroupShown.push(windGroupShown[i][0]);
								break;
							case "pascal":
								pascalGroupShown.push(windGroupShown[i][0]);
								break;
							case "meterPerSecond":
								meterPerSecondGroupShown.push(windGroupShown[i][0]);
								break;
							case "degrees":
								degreesGroupShown.push(windGroupShown[i][0]);
								break;
							case "octas":
								octasGroupShown.push(windGroupShown[i][0]);
								break;
						}
					}
					for (var i=0; i<otherGroupShown.length; i++) {
						switch (otherGroupShown[i][5]) {
							case "celsius":
								celsiusGroupShown.push(otherGroupShown[i][0]);
								break;
							case "days":
								daysGroupShown.push(otherGroupShown[i][0]);
								break;
							case "percent":
								percentGroupShown.push(otherGroupShown[i][0]);
								break;
							case "milimeter":
								milimeterGroupShown.push(otherGroupShown[i][0]);
								break;
							case "pascal":
								pascalGroupShown.push(otherGroupShown[i][0]);
								break;
							case "meterPerSecond":
								meterPerSecondGroupShown.push(otherGroupShown[i][0]);
								break;
							case "degrees":
								degreesGroupShown.push(otherGroupShown[i][0]);
								break;
							case "octas":
								octasGroupShown.push(otherGroupShown[i][0]);
								break;
						}
					}
				}
				fillUnitGroups();
		
				// Find the max and min values for the Y scales
				function findMaxMin() {
					// Celsius values
					minCelsiusYArray = [];
					maxCelsiusYArray = [];
					for (var i=0; i<celsiusGroupShown.length; i++) {
						minCelsiusYArray.push(d3.min(data, function(d) { return Math.min(d[celsiusGroupShown[i]]); }) );
						maxCelsiusYArray.push(d3.max(data, function(d) { return Math.max(d[celsiusGroupShown[i]]); }) );  
					}
					minCelsiusY = d3.min(minCelsiusYArray);
					maxCelsiusY = d3.max(maxCelsiusYArray);
					// Days values
					minDaysYArray = [];
					maxDaysYArray = [];
					for (var i=0; i<daysGroupShown.length; i++) {
						minDaysYArray.push(d3.min(data, function(d) { return Math.min(d[daysGroupShown[i]]); }) );
						maxDaysYArray.push(d3.max(data, function(d) { return Math.max(d[daysGroupShown[i]]); }) );  
					}
					minDaysY = d3.min(minDaysYArray);
					maxDaysY = d3.max(maxDaysYArray);
					// Percent values
					minPercentYArray = [];
					maxPercentYArray = [];
					for (var i=0; i<percentGroupShown.length; i++) {
						minPercentYArray.push(d3.min(data, function(d) { return Math.min(d[percentGroupShown[i]]); }) );
						maxPercentYArray.push(d3.max(data, function(d) { return Math.max(d[percentGroupShown[i]]); }) );  
					}
					minPercentY = d3.min(minPercentYArray);
					maxPercentY = d3.max(maxPercentYArray);
					// Milimeter values
					minMilimeterYArray = [];
					maxMilimeterYArray = [];
					for (var i=0; i<milimeterGroupShown.length; i++) {
						minMilimeterYArray.push(d3.min(data, function(d) { return Math.min(d[milimeterGroupShown[i]]); }) );
						maxMilimeterYArray.push(d3.max(data, function(d) { return Math.max(d[milimeterGroupShown[i]]); }) );  
					}
					minMilimeterY = d3.min(minMilimeterYArray);
					maxMilimeterY = d3.max(maxMilimeterYArray);
					// Pascal values
					minPascalYArray = [];
					maxPascalYArray = [];
					for (var i=0; i<pascalGroupShown.length; i++) {
						minPascalYArray.push(d3.min(data, function(d) { return Math.min(d[pascalGroupShown[i]]); }) );
						maxPascalYArray.push(d3.max(data, function(d) { return Math.max(d[pascalGroupShown[i]]); }) );  
					}
					minPascalY = d3.min(minPascalYArray);
					maxPascalY = d3.max(maxPascalYArray);
					// Meter per second values
					minMeterPerSecondYArray = [];
					maxMeterPerSecondYArray = [];
					for (var i=0; i<meterPerSecondGroupShown.length; i++) {
						minMeterPerSecondYArray.push(d3.min(data, function(d) { return Math.min(d[meterPerSecondGroupShown[i]]); }) );
						maxMeterPerSecondYArray.push(d3.max(data, function(d) { return Math.max(d[meterPerSecondGroupShown[i]]); }) );  
					}
					minMeterPerSecondY = d3.min(minMeterPerSecondYArray);
					maxMeterPerSecondY = d3.max(maxMeterPerSecondYArray);
					// Degrees values
					minDegreesYArray = [];
					maxDegreesYArray = [];
					for (var i=0; i<degreesGroupShown.length; i++) {
						minDegreesYArray.push(d3.min(data, function(d) { return Math.min(d[degreesGroupShown[i]]); }) );
						maxDegreesYArray.push(d3.max(data, function(d) { return Math.max(d[degreesGroupShown[i]]); }) );  
					}
					minDegreesY = d3.min(minDegreesYArray);
					maxDegreesY = d3.max(maxDegreesYArray);
					// Octas values
					minOctasYArray = [];
					maxOctasYArray = [];
					for (var i=0; i<octasGroupShown.length; i++) {
						minOctasYArray.push(d3.min(data, function(d) { return Math.min(d[octasGroupShown[i]]); }) );
						maxOctasYArray.push(d3.max(data, function(d) { return Math.max(d[octasGroupShown[i]]); }) );  
					}
					minOctasY = d3.min(minOctasYArray);
					maxOctasY = d3.max(maxOctasYArray);
				}
				findMaxMin();
				
				// Y Scales
				yScaleCelsius = d3.scale.linear()
					.domain([minCelsiusY, maxCelsiusY])
					.range([height, 0]);
				yScaleDays = d3.scale.linear()
					.domain([minDaysY, maxDaysY])
					.range([height, 0]);
				yScalePercent = d3.scale.linear()
					.domain([minPercentY, maxPercentY])
					.range([height, 0]);
				yScaleMilimeter = d3.scale.linear()
					.domain([minMilimeterY, maxMilimeterY])
					.range([height, 0]);
				yScalePascal = d3.scale.linear()
					.domain([minPascalY, maxPascalY])
					.range([height, 0]);
					
				yScaleMeterPerSecond = d3.scale.linear()
					.domain([minMeterPerSecondY, maxMeterPerSecondY])
					.range([height, 0]);
				yScaleDegrees = d3.scale.linear()
					.domain([minDegreesY, maxDegreesY])
					.range([height, 0]);
				yScaleOctas = d3.scale.linear()
					.domain([minOctasY, maxOctasY])
					.range([height, 0]);
				
				// Which and how many Y-Axes we need
				function findAxis() {
					axis_selection = 0;
					yAxisArray = [];
					celsius_selection = false;
					if (celsiusGroupShown.length>0) {
						celsius_selection=true;
						yAxisArray.push(["yAxisCelsius", yScaleCelsius, "Celsius"]);
						axis_selection=axis_selection+1;
					}
					days_selection = false;
					if (daysGroupShown.length>0) {
						days_selection = true;
						yAxisArray.push(["yAxisDays", yScaleDays, "Days"]);
						axis_selection=axis_selection+1;
					}
					percent_selection = false;
					if (percentGroupShown.length>0) {
						percent_selection = true;
						yAxisArray.push(["yAxisPercent", yScalePercent, "Percent"]);
						axis_selection=axis_selection+1;
					}
					milimeter_selection = false;
					if (milimeterGroupShown.length>0) {
						milimeter_selection = true;
						yAxisArray.push(["yAxisMilimeter", yScaleMilimeter, "Milimeter"]);
						axis_selection=axis_selection+1;
					}
					pascal_selection = false;
					if (pascalGroupShown.length>0) {
						pascal_selection = true;
						yAxisArray.push(["yAxisPascal", yScalePascal, "Pascal"]);
						axis_selection=axis_selection+1;
					}	
					meterPerSecond_selection = false;
					if (meterPerSecondGroupShown.length>0) {
						meterPerSecond_selection = true;
						yAxisArray.push(["yAxisMeterPerSecond", yScaleMeterPerSecond, "Meter Per Second"]);
						axis_selection=axis_selection+1;
					}
					degrees_selection = false;
					if (degreesGroupShown.length>0) {
						degrees_selection = true;
						yAxisArray.push(["yAxisDegrees", yScaleDegrees, "Degrees"]);
						axis_selection=axis_selection+1;
					}
					octas_selection = false;
					if (octasGroupShown.length>0) {
						octas_selection = true;
						yAxisArray.push(["yAxisOctas", yScaleOctas, "Octas"]);
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
				function graphDraw(graphType, yScale, color) {
					var yScaleType;
					switch (yScale) {
						case "celsius":
							yScaleType=yScaleCelsius;
							break;
						case "days":
							yScaleType=yScaleDays;
							break;
						case "percent":
							yScaleType=yScalePercent;
							break;
						case "milimeter":
							yScaleType=yScaleMilimeter;
							break;
						case "pascal":
							yScaleType=yScalePascal;
							break;
						case "meterPerSecond":
							yScaleType=yScaleMeterPerSecond;
							break;
						case "degrees":
							yScaleType=yScaleDegrees;
							break;
						case "octas":
							yScaleType=yScaleOctas;
							break;								
					}
					
					var graphObj = {};
					
					graphObj[graphType] = d3.svg.line()
						.interpolate("linear")
						.x(function(d){return xScale(d.date)})
						.y(function(d){return yScaleType(d[graphType])});
	
					d3.select("#svg"+block)
						.append("path")
					  	.attr("id", "d3_path"+graphType+"ID"+block)
						.attr("d", graphObj[graphType](data))
						.attr("stroke", color)
						.attr("stroke-width", "2")
						.attr("fill", "none")
						.attr("transform", "translate(" + (margin.left-((margin.left_single*axis_sum)-(margin.left_single*axis_selection))) + "," + margin.top + ")");	  
				}
				
				function drawGraphs() {
					for (var i=0; i<temperatureGroupShown.length; i++) {
						graphDraw(temperatureGroupShown[i][0], temperatureGroupShown[i][5], temperatureGroupShown[i][1]);
					}
					for (var i=0; i<warmExtremesGroupShown.length; i++) {
						graphDraw(warmExtremesGroupShown[i][0], warmExtremesGroupShown[i][5], warmExtremesGroupShown[i][1]);
					}
					for (var i=0; i<coldExtremesGroupShown.length; i++) {
						graphDraw(coldExtremesGroupShown[i][0], coldExtremesGroupShown[i][5], coldExtremesGroupShown[i][1]);
					}
					for (var i=0; i<precipitationGroupShown.length; i++) {
						graphDraw(precipitationGroupShown[i][0], precipitationGroupShown[i][5], precipitationGroupShown[i][1]);
					}
					for (var i=0; i<extremePrecipitationGroupShown.length; i++) {
						graphDraw(extremePrecipitationGroupShown[i][0], extremePrecipitationGroupShown[i][5], extremePrecipitationGroupShown[i][1]);
					}
					for (var i=0; i<windGroupShown.length; i++) {
						graphDraw(windGroupShown[i][0], windGroupShown[i][5], windGroupShown[i][1]);
					}
					for (var i=0; i<otherGroupShown.length; i++) {
						graphDraw(otherGroupShown[i][0], otherGroupShown[i][5], otherGroupShown[i][1]);
					}
				}
				drawGraphs();
	
				// Draw Y Axis
				function yAxisDraw(axisType, scaleType, label, axisPosition) {
					var yAxisObj = {};
					var yAxisLabel;
					var yAxisLabelOffset;
					var yAxisTickFormat;
					var iconLink;
					var iconWidth;
					var iconHeight;
					if (axisType==="yAxisCelsius") {
						yAxisLabel = "&#8451;" // Celsius
						yAxisLabelOffset = -20;
						yAxisTickFormat = ".1f";
						iconLink = settings.basePath +"sites/all/modules/custom/ccis/images/d3/symbol_legende_thermometer.png";
						iconWidth = "7px";
						iconHeight = "21px";
					} else if (axisType==="yAxisDays") {
						yAxisLabel = "days"
						yAxisLabelOffset = -20;
						yAxisTickFormat = ".0f";
						iconLink = "";
						//iconLink = settings.basePath +"sites/all/modules/custom/ccis/images/d3/symbol_legende_thermometer.png";
						iconWidth = "7px";
						iconHeight = "21px";
					} else if (axisType==="yAxisPercent") {
						yAxisLabel = "%"
						yAxisLabelOffset = -20;
						yAxisTickFormat = ".1f";
						iconLink = "";
						//iconLink = settings.basePath +"sites/all/modules/custom/ccis/images/d3/symbol_legende_thermometer.png";
						iconWidth = "7px";
						iconHeight = "21px";
					} else if (axisType==="yAxisMilimeter") {
						yAxisLabel = "mm"
						yAxisLabelOffset = -20;
						yAxisTickFormat = ".1f";
						iconLink = settings.basePath +"sites/all/modules/custom/ccis/images/d3/symbol_legende_drop.png";
						iconWidth = "12px";
						iconHeight = "17px";
					} else if (axisType==="yAxisPascal") {
						yAxisLabel = "hPa"
						yAxisLabelOffset = -20;
						yAxisTickFormat = ".0f";
						iconLink = settings.basePath +"sites/all/modules/custom/ccis/images/d3/symbol_legende_pressure.png";
						iconWidth = "19px";
						iconHeight = "16px";
					} else if (axisType==="yAxisMeterPerSecond") {
						yAxisLabel = "m/s"
						yAxisLabelOffset = -20;
						yAxisTickFormat = ".1f";
						iconLink = "";
						//iconLink = settings.basePath +"sites/all/modules/custom/ccis/images/d3/symbol_legende_thermometer.png";
						iconWidth = "7px";
						iconHeight = "21px";
					} else if (axisType==="yAxisDegrees") {
						yAxisLabel = "degrees"
						yAxisLabelOffset = -20;
						yAxisTickFormat = ".0f";
						iconLink = "";
						//iconLink = settings.basePath +"sites/all/modules/custom/ccis/images/d3/symbol_legende_drop.png";
						iconWidth = "12px";
						iconHeight = "17px";
					} else if (axisType==="yAxisOctas") {
						yAxisLabel = "octas"
						yAxisLabelOffset = -20;
						yAxisTickFormat = ".1f";
						iconLink = "";
						//iconLink = settings.basePath +"sites/all/modules/custom/ccis/images/d3/symbol_legende_pressure.png";
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
						.attr("transform", "translate ("+yAxisLabelOffset+", -5)");
					
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
				// Temperature group
				if (temperatureGroupUsed.length>0 || warmExtremesGroupUsed.length>0 || coldExtremesGroupUsed.length>0) {
					$("#d3_legendDiv"+block).append("<div id='d3_iconLegendTemp"+block+"' class='d3_iconLegendTempClass'><img src='"+settings.basePath+"sites/all/modules/custom/ccis/images/d3/symbol_legende_thermometer.png' width='7' height='21'></div>");
					$("#d3_legendDiv"+block).append("<div id='d3_temperatureToggle"+block+"' class='d3_toggleClass'><b><span id='d3_tempMinus"+block+"' class='d3_minus'>"+plus+"</span> Temperature<span class='d3_unitLegend'></span></b></div>");
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
					// Main temperature group
					if (temperatureGroupUsed.length>0) {
						$("#d3_legendDiv"+block).append("<div id='d3_keysDivTemperature"+block+"'></div>");
						for (var i=0; i<temperatureGroupUsed.length; i++) {
							function findTemperatureChecked() {
								for (var k=0; k<temperatureGroupShown.length; k++) {
									if (temperatureGroupUsed[i][0]===temperatureGroupShown[k][0]) {
										return "checked";
									}
								}
							}
							$("#d3_keysDivTemperature"+block).append("<div id='d3_keysTemperature"+i+block+"' class='d3_keys'></div>");
							$("#d3_keysTemperature"+i+block).append("<div id='d3_keysTemperatureTick"+i+block+"' class='d3_keysTick'><input id='d3_checkboxTemperature"+i+block+"' type='checkbox' value='"+i+"' "+findTemperatureChecked()+"></div>");			
							$("#d3_keysTemperature"+i+block).append("<div id='d3_keysTemperatureBoxText"+i+block+"' class='d3_keysBoxText'></div>");
							$("#d3_keysTemperatureBoxText"+i+block).append("<div id='keysTemperatureText"+i+block+"' class='d3_keysText'></div>");
							$("#keysTemperatureText"+i+block).append(temperatureGroupUsed[i][2]);
							$("#d3_keysTemperatureBoxText"+i+block).append("<div id='keysTemperatureIcon"+i+block+"' class='d3_keysIcon'><img src='"+settings.basePath+"sites/all/modules/custom/ccis/images/d3/"+temperatureGroupUsed[i][4]+"' width='25' height='15'></div>");
							(function(i) {
								$("#d3_keysTemperatureBoxText"+i+block)
									.hover(function(){
										$(this).css("cursor","default"); 
										$("#"+blockID).append("<div id='d3_tooltipLegend"+i+block+"'></div>"); 
										var topPosition = $("#d3_keysTemperatureBoxText"+i+block).position().top; 
										hoverLegend(topPosition, i, temperatureGroupUsed[i][3]);
									},
									function() {$("#d3_tooltipLegend"+i+block).remove();});
							})(i);
						}
					}
					// Warm Extremes group
					if (warmExtremesGroupUsed.length>0) {
						$("#d3_legendDiv"+block).append("<div id='d3_warmExtremesToggle"+block+"' class='d3_toggleSubClass'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<b><span id='d3_warmExtremesMinus"+block+"' class='d3_minus'>"+plus+"</span> Warm Extremes <span class='d3_unitLegend'></span></b></div>");
						$("#d3_warmExtremesToggle"+block).hover(function() {
						$(this).css("cursor","pointer");
						$("#"+blockID).append("<div id='d3_tooltipLegendCategories"+block+"'></div>"); 
						var topPosition = $("#d3_warmExtremesToggle"+block).position().top;
						var legendText;
						if (warmExtremesHidden===true) {
							legendText = legendCategoriesOpen;
						} else if (warmExtremesHidden===false) {
							legendText = legendCategoriesClose;
						}
						hoverLegendCategories(topPosition, legendText);
					}, function() {$("#d3_tooltipLegendCategories"+block).remove();});
						$("#d3_legendDiv"+block).append("<div id='d3_keysDivWarmExtremes"+block+"'></div>");
						for (var i=0; i<warmExtremesGroupUsed.length; i++) {
							function findWarmExtremesChecked() {
								for (var k=0; k<warmExtremesGroupShown.length; k++) {
									if (warmExtremesGroupUsed[i][0]===warmExtremesGroupShown[k][0]) {
										return "checked";
									}
								}
							}
							$("#d3_keysDivWarmExtremes"+block).append("<div id='d3_keysWarmExtremes"+i+block+"' class='d3_keys'></div>");
							$("#d3_keysWarmExtremes"+i+block).append("<div id='d3_keysWarmExtremesTick"+i+block+"' class='d3_keysTick d3_keysSubTick'><input id='d3_checkboxWarmExtremes"+i+block+"' type='checkbox' value='"+i+"' "+findWarmExtremesChecked()+"></div>");			
							$("#d3_keysWarmExtremes"+i+block).append("<div id='d3_keysWarmExtremesBoxText"+i+block+"' class='d3_keysBoxText'></div>");
							$("#d3_keysWarmExtremesBoxText"+i+block).append("<div id='keysWarmExtremesText"+i+block+"' class='d3_keysText'></div>");
							$("#keysWarmExtremesText"+i+block).append(warmExtremesGroupUsed[i][2]);
							$("#d3_keysWarmExtremesBoxText"+i+block).append("<div id='keysWarmExtremesIcon"+i+block+"' class='d3_keysIcon'><img src='"+settings.basePath+"sites/all/modules/custom/ccis/images/d3/"+warmExtremesGroupUsed[i][4]+"' width='25' height='15'></div>");
							(function(i) {
								$("#d3_keysWarmExtremesBoxText"+i+block)
									.hover(function(){
										$(this).css("cursor","default"); 
										$("#"+blockID).append("<div id='d3_tooltipLegend"+i+block+"'></div>"); 
										var topPosition = $("#d3_keysWarmExtremesBoxText"+i+block).position().top; 
										hoverLegend(topPosition, i, warmExtremesGroupUsed[i][3]);
									},
									function() {$("#d3_tooltipLegend"+i+block).remove();});
							})(i);
						}
					}
					// Cold Extremes group
					if (coldExtremesGroupUsed.length>0) {
						$("#d3_legendDiv"+block).append("<div id='d3_coldExtremesToggle"+block+"' class='d3_toggleSubClass'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<b><span id='d3_coldExtremesMinus"+block+"' class='d3_minus'>"+plus+"</span> Cold Extremes <span class='d3_unitLegend'></span></b></div>");
						$("#d3_coldExtremesToggle"+block).hover(function() {
						$(this).css("cursor","pointer");
						$("#"+blockID).append("<div id='d3_tooltipLegendCategories"+block+"'></div>"); 
						var topPosition = $("#d3_coldExtremesToggle"+block).position().top;
						var legendText;
						if (coldExtremesHidden===true) {
							legendText = legendCategoriesOpen;
						} else if (coldExtremesHidden===false) {
							legendText = legendCategoriesClose;
						}
						hoverLegendCategories(topPosition, legendText);
					}, function() {$("#d3_tooltipLegendCategories"+block).remove();});
						$("#d3_legendDiv"+block).append("<div id='d3_keysDivColdExtremes"+block+"'></div>");
						for (var i=0; i<coldExtremesGroupUsed.length; i++) {
							function findColdExtremesChecked() {
								for (var k=0; k<coldExtremesGroupShown.length; k++) {
									if (coldExtremesGroupUsed[i][0]===coldExtremesGroupShown[k][0]) {
										return "checked";
									}
								}
							}
							$("#d3_keysDivColdExtremes"+block).append("<div id='d3_keysColdExtremes"+i+block+"' class='d3_keys'></div>");
							$("#d3_keysColdExtremes"+i+block).append("<div id='d3_keysColdExtremesTick"+i+block+"' class='d3_keysTick d3_keysSubTick'><input id='d3_checkboxColdExtremes"+i+block+"' type='checkbox' value='"+i+"' "+findColdExtremesChecked()+"></div>");			
							$("#d3_keysColdExtremes"+i+block).append("<div id='d3_keysColdExtremesBoxText"+i+block+"' class='d3_keysBoxText'></div>");
							$("#d3_keysColdExtremesBoxText"+i+block).append("<div id='keysColdExtremesText"+i+block+"' class='d3_keysText'></div>");
							$("#keysColdExtremesText"+i+block).append(coldExtremesGroupUsed[i][2]);
							$("#d3_keysColdExtremesBoxText"+i+block).append("<div id='keysColdExtremesIcon"+i+block+"' class='d3_keysIcon'><img src='"+settings.basePath+"sites/all/modules/custom/ccis/images/d3/"+coldExtremesGroupUsed[i][4]+"' width='25' height='15'></div>");
							(function(i) {
								$("#d3_keysColdExtremesBoxText"+i+block)
									.hover(function(){
										$(this).css("cursor","default"); 
										$("#"+blockID).append("<div id='d3_tooltipLegend"+i+block+"'></div>"); 
										var topPosition = $("#d3_keysColdExtremesBoxText"+i+block).position().top; 
										hoverLegend(topPosition, i, coldExtremesGroupUsed[i][3]);
									},
									function() {$("#d3_tooltipLegend"+i+block).remove();});
							})(i);
						}
					}
				}		
				// Precipitation group
				if (precipitationGroupUsed.length>0 || extremePrecipitationGroupUsed.length>0) {
					$("#d3_legendDiv"+block).append("<div id='d3_iconLegendPrec"+block+"' class='d3_iconLegendPrecClass'><img src='"+settings.basePath+"sites/all/modules/custom/ccis/images/d3/symbol_legende_drop.png' width='11' height='17'></div>");
					$("#d3_legendDiv"+block).append("<div id='d3_precipitationToggle"+block+"' class='d3_toggleClass'><b><span id='d3_precMinus"+block+"' class='d3_minus'>"+plus+"</span> Precipitation<span class='d3_unitLegend'></span></b></div>");
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
					// Main precipitation group
					if (precipitationGroupUsed.length>0) {
						$("#d3_legendDiv"+block).append("<div id='d3_keysDivPrecipitation"+block+"'></div>");
						for (var i=0; i<precipitationGroupUsed.length; i++) {
							function findPrecipitationChecked() {
								for (var k=0; k<precipitationGroupShown.length; k++) {
									if (precipitationGroupUsed[i][0]===precipitationGroupShown[k][0]) {
										return "checked";
									}
								}
							}
							$("#d3_keysDivPrecipitation"+block).append("<div id='d3_keysPrecipitation"+i+block+"' class='d3_keys'></div>");
							$("#d3_keysPrecipitation"+i+block).append("<div id='d3_keysPrecipitationTick"+i+block+"' class='d3_keysTick'><input id='d3_checkboxPrecipitation"+i+block+"' type='checkbox' value='"+i+"' "+findPrecipitationChecked()+"></div>");
							$("#d3_keysPrecipitation"+i+block).append("<div id='d3_keysPrecipitationBoxText"+i+block+"' class='d3_keysBoxText'></div>")
							
							$("#d3_keysPrecipitationBoxText"+i+block).append("<div id='d3_keysPrecipitationText"+i+block+"' class='d3_keysText'></div>");
							$("#d3_keysPrecipitationText"+i+block).append(precipitationGroupUsed[i][2]);
							$("#d3_keysPrecipitationBoxText"+i+block).append("<div id='d3_keysPrecipitationIcon"+i+block+"' class='d3_keysIcon'><img src='"+settings.basePath+"sites/all/modules/custom/ccis/images/d3/"+precipitationGroupUsed[i][4]+"' width='25' height='15'></div>");
							(function(i) {
								$("#d3_keysPrecipitationBoxText"+i+block)
									.hover(function(){
										$(this).css("cursor","default"); 
										$("#"+blockID).append("<div id='d3_tooltipLegend"+i+block+"'></div>"); 
										var topPosition = $("#d3_keysPrecipitationBoxText"+i+block).position().top; 
										hoverLegend(topPosition, i, precipitationGroupUsed[i][3]);
									},
									function() {$("#d3_tooltipLegend"+i+block).remove();});
							})(i);
						}
					}
					// Extreme Precipitation group
					if (extremePrecipitationGroupUsed.length>0) {
						$("#d3_legendDiv"+block).append("<div id='d3_extremePrecipitationToggle"+block+"' class='d3_toggleSubClass'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<b><span id='d3_extremePrecMinus"+block+"' class='d3_minus'>"+plus+"</span> Extreme Precipitation <span class='d3_unitLegend'></span></b></div>");
						$("#d3_extremePrecipitationToggle"+block).hover(function() {
						$(this).css("cursor","pointer");
						$("#"+blockID).append("<div id='d3_tooltipLegendCategories"+block+"'></div>"); 
						var topPosition = $("#d3_extremePrecipitationToggle"+block).position().top;
						var legendText;
						if (extremePrecipitationHidden===true) {
							legendText = legendCategoriesOpen;
						} else if (extremePrecipitationHidden===false) {
							legendText = legendCategoriesClose;
						}
						hoverLegendCategories(topPosition, legendText);
					}, function() {$("#d3_tooltipLegendCategories"+block).remove();});
						$("#d3_legendDiv"+block).append("<div id='d3_keysDivExtremePrecipitation"+block+"'></div>");
						for (var i=0; i<extremePrecipitationGroupUsed.length; i++) {
							function findExtremePrecipitationChecked() {
								for (var k=0; k<extremePrecipitationGroupShown.length; k++) {
									if (extremePrecipitationGroupUsed[i][0]===extremePrecipitationGroupShown[k][0]) {
										return "checked";
									}
								}
							}
							$("#d3_keysDivExtremePrecipitation"+block).append("<div id='d3_keysExtremePrecipitation"+i+block+"' class='d3_keys'></div>");
							$("#d3_keysExtremePrecipitation"+i+block).append("<div id='d3_keysExtremePrecipitationTick"+i+block+"' class='d3_keysTick d3_keysSubTick'><input id='d3_checkboxExtremePrecipitation"+i+block+"' type='checkbox' value='"+i+"' "+findExtremePrecipitationChecked()+"></div>");
							$("#d3_keysExtremePrecipitation"+i+block).append("<div id='d3_keysExtremePrecipitationBoxText"+i+block+"' class='d3_keysBoxText'></div>")
							
							$("#d3_keysExtremePrecipitationBoxText"+i+block).append("<div id='d3_keysExtremePrecipitationnText"+i+block+"' class='d3_keysText'></div>");
							$("#d3_keysExtremePrecipitationnText"+i+block).append(extremePrecipitationGroupUsed[i][2]);
							$("#d3_keysExtremePrecipitationBoxText"+i+block).append("<div id='d3_keysExtremePrecipitationIcon"+i+block+"' class='d3_keysIcon'><img src='"+settings.basePath+"sites/all/modules/custom/ccis/images/d3/"+extremePrecipitationGroupUsed[i][4]+"' width='25' height='15'></div>");
							(function(i) {
								$("#d3_keysExtremePrecipitationBoxText"+i+block)
									.hover(function(){
										$(this).css("cursor","default"); 
										$("#"+blockID).append("<div id='d3_tooltipLegend"+i+block+"'></div>"); 
										var topPosition = $("#d3_keysExtremePrecipitationBoxText"+i+block).position().top; 
										hoverLegend(topPosition, i, extremePrecipitationGroupUsed[i][3]);
									},
									function() {$("#d3_tooltipLegend"+i+block).remove();});
							})(i);
						}
					}
				}
				// Wind group
				if (windGroupUsed.length>0) {
					$("#d3_legendDiv"+block).append("<div id='d3_iconLegendWind"+block+"' class='d3_iconLegendWindClass'><img src='"+settings.basePath+"sites/all/modules/custom/ccis/images/d3/symbol_legende_wind.png' width='11' height='17'></div>");
					$("#d3_legendDiv"+block).append("<div id='d3_windToggle"+block+"' class='d3_toggleClass'><b><span id='d3_windMinus"+block+"' class='d3_minus'>"+plus+"</span> Wind<span class='d3_unitLegend'></span></b></div>");
					$("#d3_windToggle"+block).hover(function() {
						$(this).css("cursor","pointer");
						$("#"+blockID).append("<div id='d3_tooltipLegendCategories"+block+"'></div>"); 
						var topPosition = $("#d3_windToggle"+block).position().top;
						var legendText;
						if (windHidden===true) {
							legendText = legendCategoriesOpen;
						} else if (windHidden===false) {
							legendText = legendCategoriesClose;
						}
						hoverLegendCategories(topPosition, legendText);
					}, function() {$("#d3_tooltipLegendCategories"+block).remove();});
					$("#d3_legendDiv"+block).append("<div id='d3_keysDivWind"+block+"'></div>");
					for (var i=0; i<windGroupUsed.length; i++) {
						function findWindChecked() {
							for (var k=0; k<windGroupShown.length; k++) {
								if (windGroupUsed[i][0]===windGroupShown[k][0]) {
									return "checked";
								}
							}
						}
						$("#d3_keysDivWind"+block).append("<div id='d3_keysWind"+i+block+"' class='d3_keys'></div>");
						$("#d3_keysWind"+i+block).append("<div id='d3_keysWindTick"+i+block+"' class='d3_keysTick'><input id='d3_checkboxWind"+i+block+"' type='checkbox' value='"+i+"' "+findWindChecked()+"></div>");
						$("#d3_keysWind"+i+block).append("<div id='d3_keysWindBoxText"+i+block+"' class='d3_keysBoxText'></div>")
						
						$("#d3_keysWindBoxText"+i+block).append("<div id='d3_keysWindText"+i+block+"' class='d3_keysText'></div>");
						$("#d3_keysWindText"+i+block).append(windGroupUsed[i][2]);
						$("#d3_keysWindBoxText"+i+block).append("<div id='d3_keysWindIcon"+i+block+"' class='d3_keysIcon'><img src='"+settings.basePath+"sites/all/modules/custom/ccis/images/d3/"+windGroupUsed[i][4]+"' width='17' height='13'></div>");
						(function(i) {
							$("#d3_keysWindBoxText"+i+block)
								.hover(function(){
									$(this).css("cursor","default"); 
									$("#"+blockID).append("<div id='d3_tooltipLegend"+i+block+"'></div>"); 
									var topPosition = $("#d3_keysWindBoxText"+i+block).position().top; 
									hoverLegend(topPosition, i, windGroupUsed[i][3]);
								},
								function() {$("#d3_tooltipLegend"+i+block).remove();});
						})(i);
					}
				}
				// Other group
				if (otherGroupUsed.length>0) {
					$("#d3_legendDiv"+block).append("<div id='d3_iconLegendOther"+block+"' class='d3_iconLegendOtherClass'><img src='"+settings.basePath+"sites/all/modules/custom/ccis/images/d3/symbol_legende_other.png' width='16' height='4'></div>");
					$("#d3_legendDiv"+block).append("<div id='d3_otherToggle"+block+"' class='d3_toggleClass'><b><span id='d3_otherMinus"+block+"' class='d3_minus'>"+plus+"</span> Other<span class='d3_unitLegend'></span></b></div>");
					$("#d3_otherToggle"+block).hover(function() {
						$(this).css("cursor","pointer");
						$("#"+blockID).append("<div id='d3_tooltipLegendCategories"+block+"'></div>"); 
						var topPosition = $("#d3_otherToggle"+block).position().top;
						var legendText;
						if (otherHidden===true) {
							legendText = legendCategoriesOpen;
						} else if (otherHidden===false) {
							legendText = legendCategoriesClose;
						}
						hoverLegendCategories(topPosition, legendText);
					}, function() {$("#d3_tooltipLegendCategories"+block).remove();});
					$("#d3_legendDiv"+block).append("<div id='d3_keysDivOther"+block+"'></div>");
					for (var i=0; i<otherGroupUsed.length; i++) {
						function findOtherChecked() {
							for (var k=0; k<otherGroupShown.length; k++) {
								if (otherGroupUsed[i][0]===otherGroupShown[k][0]) {
									return "checked";
								}
							}
						}
						$("#d3_keysDivOther"+block).append("<div id='d3_keysOther"+i+block+"' class='d3_keys'></div>");
						$("#d3_keysOther"+i+block).append("<div id='d3_keysOtherTick"+i+block+"' class='d3_keysTick'><input id='d3_checkboxOther"+i+block+"' type='checkbox' value='"+i+"' "+findOtherChecked()+"></div>");
						$("#d3_keysOther"+i+block).append("<div id='d3_keysOtherBoxText"+i+block+"' class='d3_keysBoxText'></div>")
						
						$("#d3_keysOtherBoxText"+i+block).append("<div id='d3_keysOtherText"+i+block+"' class='d3_keysText'></div>");
						$("#d3_keysOtherText"+i+block).append(otherGroupUsed[i][2]);
						$("#d3_keysOtherBoxText"+i+block).append("<div id='d3_keysOtherIcon"+i+block+"' class='d3_keysIcon'><img src='"+settings.basePath+"sites/all/modules/custom/ccis/images/d3/"+otherGroupUsed[i][4]+"' width='25' height='15'></div>");
						(function(i) {
							$("#d3_keysOtherBoxText"+i+block)
								.hover(function(){
									$(this).css("cursor","default"); 
									$("#"+blockID).append("<div id='d3_tooltipLegend"+i+block+"'></div>"); 
									var topPosition = $("#d3_keysOtherBoxText"+i+block).position().top; 
									hoverLegend(topPosition, i, otherGroupUsed[i][3]);
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
				for (var i=0; i<temperatureGroupUsed.length; i++) {
					$("#d3_keysTemperature"+i+block).hide();
					if ($("#d3_checkboxTemperature"+i+block).is(":checked")) {
						$("#d3_keysTemperature"+i+block).show();
					}	
				}
				temperatureHidden=true;
				for (var i=0; i<warmExtremesGroupUsed.length; i++) {
					$("#d3_keysWarmExtremes"+i+block).hide();
					if ($("#d3_checkboxWarmExtremes"+i+block).is(":checked")) {
						$("#d3_keysWarmExtremes"+i+block).show();
					}	
				} 
				warmExtremesHidden=true;
				for (var i=0; i<coldExtremesGroupUsed.length; i++) {
					$("#d3_keysColdExtremes"+i+block).hide();
					if ($("#d3_checkboxColdExtremes"+i+block).is(":checked")) {
						$("#d3_keysColdExtremes"+i+block).show();
					}	
				}
				coldExtremesHidden=true;
				for (var i=0; i<precipitationGroupUsed.length; i++) {
					$("#d3_keysPrecipitation"+i+block).hide();
					if ($("#d3_checkboxPrecipitation"+i+block).is(":checked")) {
						$("#d3_keysPrecipitation"+i+block).show();
					}	
				}
				precipitationHidden=true;
				for (var i=0; i<extremePrecipitationGroupUsed.length; i++) {
					$("#d3_keysExtremePrecipitation"+i+block).hide();
					if ($("#d3_checkboxExtremePrecipitation"+i+block).is(":checked")) {
						$("#d3_keysExtremePrecipitation"+i+block).show();
					}	
				}
				extremePrecipitationHidden=true;
				for (var i=0; i<windGroupUsed.length; i++) {
					$("#d3_keysWind"+i+block).hide();
					if ($("#d3_checkboxWind"+i+block).is(":checked")) {
						$("#d3_keysWind"+i+block).show();
					}	
				}
				windHidden=true;
				for (var i=0; i<otherGroupUsed.length; i++) {
					$("#d3_keysOther"+i+block).hide();
					if ($("#d3_checkboxOther"+i+block).is(":checked")) {
						$("#d3_keysOther"+i+block).show();
					}	
				}
				otherHidden=true;
				
				// Collapse	
				$("#d3_temperatureToggle"+block).click(function() {
					if (temperatureHidden===true) {
						$("#d3_tempMinus"+block).html(minus);
						for (var i=0; i<temperatureGroupUsed.length; i++) {			
							$("#d3_keysTemperature"+i+block).show();
						}
						temperatureHidden=false;
						$("#d3_tooltipLegendCategories"+block).html(legendCategoriesClose);
					} else if (temperatureHidden===false) {
						$("#d3_tempMinus"+block).html(plus);
						for (var i=0; i<temperatureGroupUsed.length; i++) {
							$("#d3_keysTemperature"+i+block).hide();
							if ($("#d3_checkboxTemperature"+i+block).is(":checked")) {
								$("#d3_keysTemperature"+i+block).show();
							}	
						}
						temperatureHidden=true;
						$("#d3_tooltipLegendCategories"+block).html(legendCategoriesOpen);
					}
				});
				$("#d3_warmExtremesToggle"+block).click(function() {
					if (warmExtremesHidden===true) {
						$("#d3_warmExtremesMinus"+block).html(minus);
						for (var i=0; i<warmExtremesGroupUsed.length; i++) {			
							$("#d3_keysWarmExtremes"+i+block).show();
						}
						warmExtremesHidden=false;
						$("#d3_tooltipLegendCategories"+block).html(legendCategoriesClose);
					} else if (warmExtremesHidden===false) {
						$("#d3_warmExtremesMinus"+block).html(plus);
						for (var i=0; i<warmExtremesGroupUsed.length; i++) {
							$("#d3_keysWarmExtremes"+i+block).hide();
							if ($("#d3_checkboxWarmExtremes"+i+block).is(":checked")) {
								$("#d3_keysWarmExtremes"+i+block).show();
							}	
						}
						warmExtremesHidden=true;
						$("#d3_tooltipLegendCategories"+block).html(legendCategoriesOpen);
					}
				});
				$("#d3_coldExtremesToggle"+block).click(function() {
					if (coldExtremesHidden===true) {
						$("#d3_coldExtremesMinus"+block).html(minus);
						for (var i=0; i<coldExtremesGroupUsed.length; i++) {			
							$("#d3_keysColdExtremes"+i+block).show();
						}
						coldExtremesHidden=false;
						$("#d3_tooltipLegendCategories"+block).html(legendCategoriesClose);
					} else if (coldExtremesHidden===false) {
						$("#d3_coldExtremesMinus"+block).html(plus);
						for (var i=0; i<coldExtremesGroupUsed.length; i++) {
							$("#d3_keysColdExtremes"+i+block).hide();
							if ($("#d3_checkboxColdExtremes"+i+block).is(":checked")) {
								$("#d3_keysColdExtremes"+i+block).show();
							}	
						}
						coldExtremesHidden=true;
						$("#d3_tooltipLegendCategories"+block).html(legendCategoriesOpen);
					}
				});
				$("#d3_precipitationToggle"+block).click(function() {
					if (precipitationHidden===true) {
						$("#d3_precMinus"+block).html(minus);
						for (var i=0; i<precipitationGroupUsed.length; i++) {			
							$("#d3_keysPrecipitation"+i+block).show();
						}
						precipitationHidden=false;
						$("#d3_tooltipLegendCategories"+block).html(legendCategoriesClose);
					} else if (precipitationHidden===false) {
						$("#d3_precMinus"+block).html(plus);
						for (var i=0; i<precipitationGroupUsed.length; i++) {
							$("#d3_keysPrecipitation"+i+block).hide();
							if ($("#d3_checkboxPrecipitation"+i+block).is(":checked")) {
								$("#d3_keysPrecipitation"+i+block).show();
							}	
						}
						precipitationHidden=true;
						$("#d3_tooltipLegendCategories"+block).html(legendCategoriesOpen);
					}
				});
				$("#d3_extremePrecipitationToggle"+block).click(function() {
					if (extremePrecipitationHidden===true) {
						$("#d3_extremePrecMinus"+block).html(minus);
						for (var i=0; i<extremePrecipitationGroupUsed.length; i++) {			
							$("#d3_keysExtremePrecipitation"+i+block).show();
						}
						extremePrecipitationHidden=false;
						$("#d3_tooltipLegendCategories"+block).html(legendCategoriesClose);
					} else if (extremePrecipitationHidden===false) {
						$("#d3_extremePrecMinus"+block).html(plus);
						for (var i=0; i<extremePrecipitationGroupUsed.length; i++) {
							$("#d3_keysExtremePrecipitation"+i+block).hide();
							if ($("#d3_checkboxExtremePrecipitation"+i+block).is(":checked")) {
								$("#d3_keysExtremePrecipitation"+i+block).show();
							}	
						}
						extremePrecipitationHidden=true;
						$("#d3_tooltipLegendCategories"+block).html(legendCategoriesOpen);
					}
				});
				$("#d3_windToggle"+block).click(function() {
					if (windHidden===true) {
						$("#d3_windMinus"+block).html(minus);
						for (var i=0; i<windGroupUsed.length; i++) {			
							$("#d3_keysWind"+i+block).show();
						}
						windHidden=false;
						$("#d3_tooltipLegendCategories"+block).html(legendCategoriesClose);
					} else if (windHidden===false) {
						$("#d3_windMinus"+block).html(plus);
						for (var i=0; i<windGroupUsed.length; i++) {
							$("#d3_keysWind"+i+block).hide();
							if ($("#d3_checkboxWind"+i+block).is(":checked")) {
								$("#d3_keysWind"+i+block).show();
							}	
						}
						windHidden=true;
						$("#d3_tooltipLegendCategories"+block).html(legendCategoriesOpen);
					}
				});
				$("#d3_otherToggle"+block).click(function() {
					if (otherHidden===true) {
						$("#d3_otherMinus"+block).html(minus);
						for (var i=0; i<otherGroupUsed.length; i++) {			
							$("#d3_keysOther"+i+block).show();
						}
						otherHidden=false;
						$("#d3_tooltipLegendCategories"+block).html(legendCategoriesClose);
					} else if (otherHidden===false) {
						$("#d3_otherMinus"+block).html(plus);
						for (var i=0; i<otherGroupUsed.length; i++) {
							$("#d3_keysOther"+i+block).hide();
							if ($("#d3_checkboxOther"+i+block).is(":checked")) {
								$("#d3_keysOther"+i+block).show();
							}	
						}
						otherHidden=true;
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
						var findIDsTemperature = $("#d3_keysDivTemperature"+block+" input:checkbox:checked").map(function() {		        
							return $(this).val();      
						});
						findTicksArrayTemperature = findIDsTemperature.get();
					}
					if (document.getElementById("d3_keysDivWarmExtremes"+block)) {
						var findIDsWarmExtremes = $("#d3_keysDivWarmExtremes"+block+" input:checkbox:checked").map(function() {		        
							return $(this).val();      
						});
						findTicksArrayWarmExtremes = findIDsWarmExtremes.get();
					}
					if (document.getElementById("d3_keysDivColdExtremes"+block)) {
						var findIDsColdExtremes = $("#d3_keysDivColdExtremes"+block+" input:checkbox:checked").map(function() {		        
							return $(this).val();      
						});
						findTicksArrayColdExtremes = findIDsColdExtremes.get();
					}
					if (document.getElementById("d3_keysDivPrecipitation"+block)) {
						var findIDsPrecipitation = $("#d3_keysDivPrecipitation"+block+" input:checkbox:checked").map(function() {		        
							return $(this).val();      
						});
						findTicksArrayPrecipitation = findIDsPrecipitation.get();
					}
					if (document.getElementById("d3_keysDivExtremePrecipitation"+block)) {
						var findIDsExtremePrecipitation = $("#d3_keysDivExtremePrecipitation"+block+" input:checkbox:checked").map(function() {		        
							return $(this).val();      
						});
						findTicksArrayExtremePrecipitation = findIDsExtremePrecipitation.get();
					}
					if (document.getElementById("d3_keysDivWind"+block)) {
						var findIDsWind = $("#d3_keysDivWind"+block+" input:checkbox:checked").map(function() {		        
							return $(this).val();      
						});
						findTicksArrayWind = findIDsWind.get();
					}
					if (document.getElementById("d3_keysDivOther"+block)) {
						var findIDsOther = $("#d3_keysDivOther"+block+" input:checkbox:checked").map(function() {		        
							return $(this).val();      
						});
						findTicksArrayOther = findIDsOther.get();
					}
	
					// Which parameters are selected
					temperatureGroupShown = [];
					var temperatureShownSingle;
					for (var i=0; i<findTicksArrayTemperature.length; i++) {
						temperatureShownSingle = temperatureGroupUsed[parseFloat(findTicksArrayTemperature[i])];
						temperatureGroupShown.push(temperatureShownSingle);			
					}
					warmExtremesGroupShown = [];
					var warmExtremesShownSingle;
					for (var i=0; i<findTicksArrayWarmExtremes.length; i++) {
						warmExtremesShownSingle = warmExtremesGroupUsed[parseFloat(findTicksArrayWarmExtremes[i])];
						warmExtremesGroupShown.push(warmExtremesShownSingle);			
					}
					coldExtremesGroupShown = [];
					var coldExtremesShownSingle;
					for (var i=0; i<findTicksArrayColdExtremes.length; i++) {
						coldExtremesShownSingle = coldExtremesGroupUsed[parseFloat(findTicksArrayColdExtremes[i])];
						coldExtremesGroupShown.push(coldExtremesShownSingle);			
					}
					precipitationGroupShown = [];
					var precipitationShownSingle;
					for (var i=0; i<findTicksArrayPrecipitation.length; i++) {
						precipitationShownSingle = precipitationGroupUsed[parseFloat(findTicksArrayPrecipitation[i])];
						precipitationGroupShown.push(precipitationShownSingle);			
					}
					extremePrecipitationGroupShown = [];
					var extremePrecipitationShownSingle;
					for (var i=0; i<findTicksArrayExtremePrecipitation.length; i++) {
						extremePrecipitationShownSingle = extremePrecipitationGroupUsed[parseFloat(findTicksArrayExtremePrecipitation[i])];
						extremePrecipitationGroupShown.push(extremePrecipitationShownSingle);			
					}
					windGroupShown = [];
					var windShownSingle;
					for (var i=0; i<findTicksArrayWind.length; i++) {
						windShownSingle = windGroupUsed[parseFloat(findTicksArrayWind[i])];
						windGroupShown.push(windShownSingle);			
					}
					otherGroupShown = [];
					var otherShownSingle;
					for (var i=0; i<findTicksArrayOther.length; i++) {
						otherShownSingle = otherGroupUsed[parseFloat(findTicksArrayOther[i])];
						otherGroupShown.push(otherShownSingle);			
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
					yScaleCelsius.range([height, 0]);
					yScaleDays.range([height, 0]);
					yScalePercent.range([height, 0]);
					yScaleMilimeter.range([height, 0]);
					yScaleDays.range([height, 0]);
					yScalePascal.range([height, 0]);	
					yScaleMeterPerSecond.range([height, 0]);
					yScaleDegrees.range([height, 0]);
					yScaleOctas.range([height, 0]);
					
					/*yScaleTemp.range([height, 0]);
					yScalePrec.range([height, 0]);
					yScalePress.range([height, 0]);*/
					
					// Create again the svg
					createSvg();
					
					// Find the max and min values for the Y scales
					findMaxMin();
					
					// Update Y domains
					yScaleCelsius.domain([minCelsiusY, maxCelsiusY]);
					yScaleDays.domain([minDaysY, maxDaysY]);
					yScalePercent.domain([minPercentY, maxPercentY]);
					yScaleMilimeter.domain([minMilimeterY, maxMilimeterY]);
					yScalePascal.domain([minPascalY, maxPascalY]);		
					yScaleMeterPerSecond.domain([minMeterPerSecondY, maxMeterPerSecondY]);
					yScaleDegrees.domain([minDegreesY, maxDegreesY]);
					yScaleOctas.domain([minOctasY, maxOctasY]);
										
					// Redraw Graphs
					drawGraphs();
					
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
						for (var i=0; i<temperatureGroupUsed.length; i++) {
							if ($("#d3_checkboxTemperature"+i+block).is(":checked")) {
								$("#d3_keysTemperature"+i+block).show();
							} else {
								$("#d3_keysTemperature"+i+block).hide();
							}
						}
					}
					if (warmExtremesHidden===true) {
						for (var i=0; i<warmExtremesGroupUsed.length; i++) {
							if ($("#d3_checkboxWarmExtremes"+i+block).is(":checked")) {
								$("#d3_keysWarmExtremes"+i+block).show();
							} else {
								$("#d3_keysWarmExtremes"+i+block).hide();
							}
						}
					}
					if (coldExtremesHidden===true) {
						for (var i=0; i<coldExtremesGroupUsed.length; i++) {
							if ($("#d3_checkboxColdExtremes"+i+block).is(":checked")) {
								$("#d3_keysColdExtremes"+i+block).show();
							} else {
								$("#d3_keysColdExtremes"+i+block).hide();
							}
						}
					}
					if (precipitationHidden===true) {
						for (var i=0; i<precipitationGroupUsed.length; i++) {
							if ($("#d3_checkboxPrecipitation"+i+block).is(":checked")) {
								$("#d3_keysPrecipitation"+i+block).show();
							} else {
								$("#d3_keysPrecipitation"+i+block).hide();
							}
						}
					}
					if (extremePrecipitationHidden===true) {
						for (var i=0; i<extremePrecipitationGroupUsed.length; i++) {
							if ($("#d3_checkboxExtremePrecipitation"+i+block).is(":checked")) {
								$("#d3_keysExtremePrecipitation"+i+block).show();
							} else {
								$("#d3_keysExtremePrecipitation"+i+block).hide();
							}
						}
					}
					if (windHidden===true) {
						for (var i=0; i<windGroupUsed.length; i++) {
							if ($("#d3_checkboxWind"+i+block).is(":checked")) {
								$("#d3_keysWind"+i+block).show();
							} else {
								$("#d3_keysWind"+i+block).hide();
							}
						}
					}
					if (otherHidden===true) {
						for (var i=0; i<otherGroupUsed.length; i++) {
							if ($("#d3_checkboxOther"+i+block).is(":checked")) {
								$("#d3_keysOther"+i+block).show();
							} else {
								$("#d3_keysOther"+i+block).hide();
							}
						}
					}
		
					// Hide dropdowns with delay
					if (temperatureHidden===false) {
						setTimeout(function(){$("#d3_temperatureToggle"+block).click();}, 2000);
					}
					if (warmExtremesHidden===false) {
						setTimeout(function(){$("#d3_warmExtremesToggle"+block).click();}, 2000);
					}
					if (coldExtremesHidden===false) {
						setTimeout(function(){$("#d3_coldExtremesToggle"+block).click();}, 2000);
					}
					if (precipitationHidden===false) {
						setTimeout(function(){$("#d3_precipitationToggle"+block).click();}, 2000); 
					}
					if (extremePrecipitationHidden===false) {
						setTimeout(function(){$("#d3_extremePrecipitationToggle"+block).click();}, 2000); 
					}
					if (windHidden===false) {
						setTimeout(function(){$("#d3_windToggle"+block).click();}, 2000); 
					}
					if (otherHidden===false) {
						setTimeout(function(){$("#d3_otherToggle"+block).click();}, 2000); 
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
						
						// Find the Units
						function findHoverUnits(label) {
							switch (label) {
								case "celsius":
									return "&#8451;";
									break;
								case "days":
									return "days";
									break;
								case "percent":
									return "%";
									break;
								case "milimeter":
									return "mm";
									break;
								case "pascal":
									return "hPa";
									break;
								case "meterPerSecond":
									return "m/s";
									break;
								case "degrees":
									return "&#176;";
									break;
								case "octas":
									return "octas";
									break;
							}
						}
						
						if (item) {
							// Format the date
							var dateParse = d3.time.format("%a %b %d %Y").parse(item.date.toDateString());
							var formatter = d3.time.format("%Y-%m-%d");
							var date = formatter(dateParse);
							
							// Show the icons?
							var thermometer = false;
							if (temperatureGroupShown.length>0 || warmExtremesGroupShown.length>0 || coldExtremesGroupShown.length>0) {
								thermometer = true;
							}
							var drop = false;
							if (precipitationGroupShown.length>0 || extremePrecipitationGroupShown.length>0) {
								drop = true;
							}
							var wind = false;
							if (windGroupShown.length>0) {
								wind = true;
							}
							var other = false;
							if (otherGroupShown.length>0) {
								other = true;
							}
							// Create content for tooltips
							var tooltipText="";
							tooltipText = "<b><table style='margin:0px;'>";
								
								tooltipText += "<tr>";
									tooltipText += "<td>&nbsp;<img src='"+settings.basePath+"sites/all/modules/custom/ccis/images/d3/symbol_infobereich_clock.png' width='11' height='12'></td>";
									tooltipText += "<td>&nbsp;Date: </td>";
									tooltipText += "<td><b>"+date+"</b></td>";
								tooltipText += "</tr>";	
								if (temperatureGroupShown.length>0) {
									for (var i=0; i<temperatureGroupShown.length; i++) {									
										if (thermometer===true) {
											tooltipText += "<tr style='border-top: 1pt solid #D1D1FF;'>";
											tooltipText += "<td>&nbsp;<img src='"+settings.basePath+"sites/all/modules/custom/ccis/images/d3/symbol_legende_thermometer.png' width='7' height='21'></td>";
											thermometer = false;
										} else {
											tooltipText += "<tr>";
											tooltipText += "<td></td>";
										}
										tooltipText += "<td style='color:"+temperatureGroupShown[i][1]+"'>&nbsp;"+temperatureGroupShown[i][2]+"</td>";
										tooltipText += "<td style='color:"+temperatureGroupShown[i][1]+"'>"+item[temperatureGroupShown[i][0]].toFixed(1)+" "+findHoverUnits(temperatureGroupShown[i][5])+"</td>";
										tooltipText += "</tr>";
									}		
								}
								if (warmExtremesGroupShown.length>0) {
									for (var i=0; i<warmExtremesGroupShown.length; i++) {									
										if (thermometer===true) {
											tooltipText += "<tr style='border-top: 1pt solid #D1D1FF;'>";
											tooltipText += "<td>&nbsp;<img src='"+settings.basePath+"sites/all/modules/custom/ccis/images/d3/symbol_legende_thermometer.png' width='7' height='21'></td>";
											thermometer = false;
										} else {
											tooltipText += "<tr>";
											tooltipText += "<td></td>";
										}
										tooltipText += "<td style='color:"+warmExtremesGroupShown[i][1]+"'>&nbsp;"+warmExtremesGroupShown[i][2]+"</td>";
										tooltipText += "<td style='color:"+warmExtremesGroupShown[i][1]+"'>"+item[warmExtremesGroupShown[i][0]].toFixed(1)+" "+findHoverUnits(warmExtremesGroupShown[i][5])+"</td>";
										tooltipText += "</tr>";
									}		
								}
								if (coldExtremesGroupShown.length>0) {
									for (var i=0; i<coldExtremesGroupShown.length; i++) {									
										if (thermometer===true) {
											tooltipText += "<tr style='border-top: 1pt solid #D1D1FF;'>";
											tooltipText += "<td>&nbsp;<img src='"+settings.basePath+"sites/all/modules/custom/ccis/images/d3/symbol_legende_thermometer.png' width='7' height='21'></td>";
											thermometer = false;
										} else {
											tooltipText += "<tr>";
											tooltipText += "<td></td>";
										}
										tooltipText += "<td style='color:"+coldExtremesGroupShown[i][1]+"'>&nbsp;"+coldExtremesGroupShown[i][2]+"</td>";
										tooltipText += "<td style='color:"+coldExtremesGroupShown[i][1]+"'>"+item[coldExtremesGroupShown[i][0]].toFixed(1)+" "+findHoverUnits(coldExtremesGroupShown[i][5])+"</td>";
										tooltipText += "</tr>";
									}		
								}
								if (precipitationGroupShown.length>0) {
									for (var i=0; i<precipitationGroupShown.length; i++) {
										if (drop===true) {
											tooltipText += "<tr style='border-top: 1pt solid #D1D1FF;'>";
											tooltipText += "<td>&nbsp;<img src='"+settings.basePath+"sites/all/modules/custom/ccis/images/d3/symbol_legende_drop.png' width='11' height='17'></td>";
											drop = false;
										} else {
											tooltipText += "<tr>";
											tooltipText += "<td></td>";
										}
										tooltipText += "<td style='color:"+precipitationGroupShown[i][1]+"'>&nbsp;"+precipitationGroupShown[i][2]+"</td>";
										tooltipText += "<td style='color:"+precipitationGroupShown[i][1]+"'>"+item[precipitationGroupShown[i][0]].toFixed(1)+" "+findHoverUnits(precipitationGroupShown[i][5])+"</td>";
										tooltipText += "</tr>";
									}		
								}
								if (extremePrecipitationGroupShown.length>0) {
									for (var i=0; i<extremePrecipitationGroupShown.length; i++) {
										if (drop===true) {
											tooltipText += "<tr style='border-top: 1pt solid #D1D1FF;'>";
											tooltipText += "<td>&nbsp;<img src='"+settings.basePath+"sites/all/modules/custom/ccis/images/d3/symbol_legende_drop.png' width='11' height='17'></td>";
											drop = false;
										} else {
											tooltipText += "<tr>";
											tooltipText += "<td></td>";
										}
										tooltipText += "<td style='color:"+extremePrecipitationGroupShown[i][1]+"'>&nbsp;"+extremePrecipitationGroupShown[i][2]+"</td>";
										tooltipText += "<td style='color:"+extremePrecipitationGroupShown[i][1]+"'>"+item[extremePrecipitationGroupShown[i][0]].toFixed(1)+" "+findHoverUnits(extremePrecipitationGroupShown[i][5])+"</td>";
										tooltipText += "</tr>";
									}		
								}
								if (windGroupShown.length>0) {
									for (var i=0; i<windGroupShown.length; i++) {
										if (wind===true) {
											tooltipText += "<tr style='border-top: 1pt solid #D1D1FF;'>";
											tooltipText += "<td>&nbsp;<img src='"+settings.basePath+"sites/all/modules/custom/ccis/images/d3/symbol_legende_wind.png' width='19' height='16'></td>";
										} else {
											tooltipText += "<tr>";
											tooltipText += "<td></td>";
										}
										tooltipText += "<td style='color:"+windGroupShown[i][1]+"'>&nbsp;"+windGroupShown[i][2]+"</td>";
										tooltipText += "<td style='color:"+windGroupShown[i][1]+"'>"+item[windGroupShown[i][0]].toFixed(1)+" "+findHoverUnits(windGroupShown[i][5])+"</td>";
										tooltipText += "</tr>";
									}		
								}
								if (otherGroupShown.length>0) {
									for (var i=0; i<otherGroupShown.length; i++) {
										if (other===true) {
											tooltipText += "<tr style='border-top: 1pt solid #D1D1FF;'>";
											tooltipText += "<td>&nbsp;<img src='"+settings.basePath+"sites/all/modules/custom/ccis/images/d3/symbol_legende_other.png' width='19' height='16'></td>";
										} else {
											tooltipText += "<tr>";
											tooltipText += "<td></td>";
										}
										tooltipText += "<td style='color:"+otherGroupShown[i][1]+"'>&nbsp;"+otherGroupShown[i][2]+"</td>";
										tooltipText += "<td style='color:"+otherGroupShown[i][1]+"'>"+item[otherGroupShown[i][0]].toFixed(1)+" "+findHoverUnits(otherGroupShown[i][5])+"</td>";
										tooltipText += "</tr>";
									}		
								}
								
							tooltipText += "</table></b>";
	
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
						for (var i=0; i<temperatureGroupShown.length; i++) {
							printKeys += "<br><div style='height:0px; width:10px; border-top: 5px solid "+temperatureGroupShown[i][1]+"; border-bottom: 5px solid "+temperatureGroupShown[i][1]+"; outline:solid 1px black; float:left; margin-left:5px; margin-right:5px; margin-top:3px;'></div><span style='font-size:14px'>"+temperatureGroupShown[i][3]+"</span>";
						}
						for (var i=0; i<warmExtremesGroupShown.length; i++) {
							printKeys += "<br><div style='height:0px; width:10px; border-top: 5px solid "+warmExtremesGroupShown[i][1]+"; border-bottom: 5px solid "+warmExtremesGroupShown[i][1]+"; outline:solid 1px black; float:left; margin-left:5px; margin-right:5px; margin-top:3px;'></div><span style='font-size:14px'>"+warmExtremesGroupShown[i][3]+"</span>";
						}
						for (var i=0; i<coldExtremesGroupShown.length; i++) {
							printKeys += "<br><div style='height:0px; width:10px; border-top: 5px solid "+coldExtremesGroupShown[i][1]+"; border-bottom: 5px solid "+coldExtremesGroupShown[i][1]+"; outline:solid 1px black; float:left; margin-left:5px; margin-right:5px; margin-top:3px;'></div><span style='font-size:14px'>"+coldExtremesGroupShown[i][3]+"</span>";
						}
						for (var i=0; i<precipitationGroupShown.length; i++) {
							printKeys += "<br><div style='height:0px; width:10px; border-top: 5px solid "+precipitationGroupShown[i][1]+"; border-bottom: 5px solid "+precipitationGroupShown[i][1]+"; outline:solid 1px black; float:left; margin-left:5px; margin-right:5px; margin-top:3px;'></div><span style='font-size:14px'>"+precipitationGroupShown[i][3]+"</span>";
						}
						for (var i=0; i<extremePrecipitationGroupShown.length; i++) {
							printKeys += "<br><div style='height:0px; width:10px; border-top: 5px solid "+extremePrecipitationGroupShown[i][1]+"; border-bottom: 5px solid "+extremePrecipitationGroupShown[i][1]+"; outline:solid 1px black; float:left; margin-left:5px; margin-right:5px; margin-top:3px;'></div><span style='font-size:14px'>"+extremePrecipitationGroupShown[i][3]+"</span>";
						}
						for (var i=0; i<windGroupShown.length; i++) {
							printKeys += "<br><div style='height:0px; width:10px; border-top: 5px solid "+windGroupShown[i][1]+"; border-bottom: 5px solid "+windGroupShown[i][1]+"; outline:solid 1px black; float:left; margin-left:5px; margin-right:5px; margin-top:3px;'></div><span style='font-size:14px'>"+windGroupShown[i][3]+"</span>";
						}
						for (var i=0; i<otherGroupShown.length; i++) {
							printKeys += "<br><div style='height:0px; width:10px; border-top: 5px solid "+otherGroupShown[i][1]+"; border-bottom: 5px solid "+otherGroupShown[i][1]+"; outline:solid 1px black; float:left; margin-left:5px; margin-right:5px; margin-top:3px;'></div><span style='font-size:14px'>"+otherGroupShown[i][3]+"</span>";
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
	function diagram2() {
		// *** Variables - START ***
		var blockID = settings.ccis.stations[1].selector;
		var block = "_2";
		
		var margin = {top: 20, right: 10, bottom: 25, left: 140, left_single: 35};
		var widthDiv = $("#"+blockID).width();
		var legendWidth = 170;
		var tooltipWidth = 200;
		var width = widthDiv - margin.left - margin.right - legendWidth;
		var height = width/2;
		var widthTemp = width;
		var topOffset = 290;
		var heightPrintSelect = 50;
		var axis_sum = 4;	// MAX: 4
		var axis_selection;
		var svg;	
		var mouseX;
		var mouseY;
		var yAxisArray;
		
		var temperatureHidden;
		var warmExtremesHidden;
		var coldExtremesHidden;
		var precipitationHidden;
		var extremePrecipitationHidden;
		var windHidden;
		var otherHidden;
		
		// Unit groups shown at the graph (max: 4)
		var celsiusGroupShown;
		var daysGroupShown;
		var percentGroupShown;
		var milimeterGroupShown;
		var pascalGroupShown;
		var meterPerSecondGroupShown;
		var degreesGroupShown;
		var octasGroupShown;
		
		// Y-Scales
		var yScaleCelsius;
		var yScaleDays;
		var yScalePercent;
		var yScaleMilimeter;
		var yScalePascal;
		var yScaleMeterPerSecond;
		var yScaleDegrees;
		var yScaleOctas;
		
		// Max-Min Values for Y Scales
		// Celsius values
		var minCelsiusYArray;
		var maxCelsiusYArray;
		var minCelsiusY;
		var maxCelsiusY;
		// Days values
		var minDaysYArray;
		var maxDaysYArray;
		var minDaysY;
		var maxDaysY;
		// Percent values
		var minPercentYArray;
		var maxPercentYArray;
		var minPercentY;
		var maxPercentY;
		// Milimeter values
		var minMilimeterYArray;
		var maxMilimeterYArray;
		var minMilimeterY;
		var maxMilimeterY;
		// Pascal values
		var minPascalYArray;
		var maxPascalYArray;
		var minPascalY;
		var maxPascalY;
		// Meter per second values
		var minMeterPerSecondYArray;
		var maxMeterPerSecondYArray;
		var minMeterPerSecondY;
		var maxMeterPerSecondY;
		// Degrees values
		var minDegreesYArray;
		var maxDegreesYArray;
		var minDegreesY;
		var maxDegreesY;
		// Octas values
		var minOctasYArray;
		var maxOctasYArray;
		var minOctasY;
		var maxOctasY;
		
		// Arrays for the checkboxes
		var findTicksArrayTemperature = [];
		var findTicksArrayWarmExtremes = [];
		var findTicksArrayColdExtremes = [];
		var findTicksArrayPrecipitation = [];
		var findTicksArrayExtremePrecipitation = [];
		var findTicksArrayWind = [];
		var findTicksArrayOther = [];
		
		// Selection for Y Axis
		var celsius_selection;
		var days_selection;
		var percent_selection;
		var milimeter_selection;
		var pascal_selection;	
		var meterPerSecond_selection;
		var degrees_selection;
		var octas_selection;
		
		var legendCategoriesOpen = "Open categories";
		var legendCategoriesClose = "Close categories";
		var plus = "<img src='"+settings.basePath+"sites/all/modules/custom/ccis/images/d3/plus.png' width='7' height='7'>"
		var minus = "<img src='"+settings.basePath+"sites/all/modules/custom/ccis/images/d3/minus.png' width='7' height='7'>"
		// *** Variables - END ***

		// Parse the JSON with the data
		d3.json(settings.ccis.stations[1].path, function(json) {
			if (json.length===0) {
				$("#"+blockID).html("");
			} else {
				$("#"+blockID).html("");
				
				// Get parameters names
				var dataKeysArray = Object.keys(json[1]);
				
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
				
				// Parameter groups parsed for the specific user
				var temperatureGroupUsed = [];
				var warmExtremesGroupUsed = [];
				var coldExtremesGroupUsed = [];
				var precipitationGroupUsed = [];
				var extremePrecipitationGroupUsed = [];
				var windGroupUsed = [];
				var otherGroupUsed = [];
				
				// Create an array per group with the parameters used, the colors, the legend keywords, the legend hover names, the icons and the units
				for (var i=2; i<dataKeysArray.length; i++) {
					for (var k=0; k<temperatureGroup.length; k++) {
						if (dataKeysArray[i]===temperatureGroup[k][0]) {
							temperatureGroupUsed.push([temperatureGroup[k][0], temperatureGroup[k][1], temperatureGroup[k][2], temperatureGroup[k][3], temperatureGroup[k][4], temperatureGroup[k][5]]);
						}
					}
					for (var k=0; k<warmExtremesGroup.length; k++) {
						if (dataKeysArray[i]===warmExtremesGroup[k][0]) {
							warmExtremesGroupUsed.push([warmExtremesGroup[k][0], warmExtremesGroup[k][1], warmExtremesGroup[k][2], warmExtremesGroup[k][3], warmExtremesGroup[k][4], warmExtremesGroup[k][5]]);
						}
					}
					for (var k=0; k<coldExtremesGroup.length; k++) {
						if (dataKeysArray[i]===coldExtremesGroup[k][0]) {
							coldExtremesGroupUsed.push([coldExtremesGroup[k][0], coldExtremesGroup[k][1], coldExtremesGroup[k][2], coldExtremesGroup[k][3], coldExtremesGroup[k][4], coldExtremesGroup[k][5]]);
						}
					}
					for (var k=0; k<precipitationGroup.length; k++) {
						if (dataKeysArray[i]===precipitationGroup[k][0]) {
							precipitationGroupUsed.push([precipitationGroup[k][0], precipitationGroup[k][1], precipitationGroup[k][2], precipitationGroup[k][3], precipitationGroup[k][4], precipitationGroup[k][5]]);
						}
					}
					for (var k=0; k<extremePrecipitationGroup.length; k++) {
						if (dataKeysArray[i]===extremePrecipitationGroup[k][0]) {
							extremePrecipitationGroupUsed.push([extremePrecipitationGroup[k][0], extremePrecipitationGroup[k][1], extremePrecipitationGroup[k][2], extremePrecipitationGroup[k][3], extremePrecipitationGroup[k][4], extremePrecipitationGroup[k][5]]);
						}
					}
					for (var k=0; k<windGroup.length; k++) {
						if (dataKeysArray[i]===windGroup[k][0]) {
							windGroupUsed.push([windGroup[k][0], windGroup[k][1], windGroup[k][2], windGroup[k][3], windGroup[k][4], windGroup[k][5]]);
						}
					}
					for (var k=0; k<otherGroup.length; k++) {
						if (dataKeysArray[i]===otherGroup[k][0]) {
							otherGroupUsed.push([otherGroup[k][0], otherGroup[k][1], otherGroup[k][2], otherGroup[k][3], otherGroup[k][4], otherGroup[k][5]]);
						}
					}
				}
				
				// Parameter groups shown at the graph (max: 4)
				var temperatureGroupShown = [];
				var warmExtremesGroupShown = [];
				var coldExtremesGroupShown = [];
				var precipitationGroupShown = [];
				var extremePrecipitationGroupShown = [];
				var windGroupShown = [];
				var otherGroupShown = [];
				
				// Choose initial parameters to show
				temperatureGroupShown = [temperatureGroupUsed[0]];
				
				// Fill the unit groups arrays
				function fillUnitGroups() {
				
					celsiusGroupShown = [];
					daysGroupShown = [];
					percentGroupShown = [];
					milimeterGroupShown = [];
					pascalGroupShown = [];
					meterPerSecondGroupShown = [];
					degreesGroupShown = [];
					octasGroupShown = [];
					

					for (var i=0; i<temperatureGroupShown.length; i++) {
						switch (temperatureGroupShown[i][5]) {
							case "celsius":
								celsiusGroupShown.push(temperatureGroupShown[i][0]);
								break;
							case "days":
								daysGroupShown.push(temperatureGroupShown[i][0]);
								break;
							case "percent":
								percentGroupShown.push(temperatureGroupShown[i][0]);
								break;
							case "milimeter":
								milimeterGroupShown.push(temperatureGroupShown[i][0]);
								break;
							case "pascal":
								pascalGroupShown.push(temperatureGroupShown[i][0]);
								break;
							case "meterPerSecond":
								meterPerSecondGroupShown.push(temperatureGroupShown[i][0]);
								break;
							case "degrees":
								degreesGroupShown.push(temperatureGroupShown[i][0]);
								break;
							case "octas":
								octasGroupShown.push(temperatureGroupShown[i][0]);
								break;
						}
					}
					for (var i=0; i<warmExtremesGroupShown.length; i++) {
						switch (warmExtremesGroupShown[i][5]) {
							case "celsius":
								celsiusGroupShown.push(warmExtremesGroupShown[i][0]);
								break;
							case "days":
								daysGroupShown.push(warmExtremesGroupShown[i][0]);
								break;
							case "percent":
								percentGroupShown.push(warmExtremesGroupShown[i][0]);
								break;
							case "milimeter":
								milimeterGroupShown.push(warmExtremesGroupShown[i][0]);
								break;
							case "pascal":
								pascalGroupShown.push(warmExtremesGroupShown[i][0]);
								break;
							case "meterPerSecond":
								meterPerSecondGroupShown.push(warmExtremesGroupShown[i][0]);
								break;
							case "degrees":
								degreesGroupShown.push(warmExtremesGroupShown[i][0]);
								break;
							case "octas":
								octasGroupShown.push(warmExtremesGroupShown[i][0]);
								break;
						}
					}
					for (var i=0; i<coldExtremesGroupShown.length; i++) {
						switch (coldExtremesGroupShown[i][5]) {
							case "celsius":
								celsiusGroupShown.push(coldExtremesGroupShown[i][0]);
								break;
							case "days":
								daysGroupShown.push(coldExtremesGroupShown[i][0]);
								break;
							case "percent":
								percentGroupShown.push(coldExtremesGroupShown[i][0]);
								break;
							case "milimeter":
								milimeterGroupShown.push(coldExtremesGroupShown[i][0]);
								break;
							case "pascal":
								pascalGroupShown.push(coldExtremesGroupShown[i][0]);
								break;
							case "meterPerSecond":
								meterPerSecondGroupShown.push(coldExtremesGroupShown[i][0]);
								break;
							case "degrees":
								degreesGroupShown.push(coldExtremesGroupShown[i][0]);
								break;
							case "octas":
								octasGroupShown.push(coldExtremesGroupShown[i][0]);
								break;
						}
					}
					for (var i=0; i<precipitationGroupShown.length; i++) {
						switch (precipitationGroupShown[i][5]) {
							case "celsius":
								celsiusGroupShown.push(precipitationGroupShown[i][0]);
								break;
							case "days":
								daysGroupShown.push(precipitationGroupShown[i][0]);
								break;
							case "percent":
								percentGroupShown.push(precipitationGroupShown[i][0]);
								break;
							case "milimeter":
								milimeterGroupShown.push(precipitationGroupShown[i][0]);
								break;
							case "pascal":
								pascalGroupShown.push(precipitationGroupShown[i][0]);
								break;
							case "meterPerSecond":
								meterPerSecondGroupShown.push(precipitationGroupShown[i][0]);
								break;
							case "degrees":
								degreesGroupShown.push(precipitationGroupShown[i][0]);
								break;
							case "octas":
								octasGroupShown.push(precipitationGroupShown[i][0]);
								break;
						}
					}			
					for (var i=0; i<extremePrecipitationGroupShown.length; i++) {
						switch (extremePrecipitationGroupShown[i][5]) {
							case "celsius":
								celsiusGroupShown.push(extremePrecipitationGroupShown[i][0]);
								break;
							case "days":
								daysGroupShown.push(extremePrecipitationGroupShown[i][0]);
								break;
							case "percent":
								percentGroupShown.push(extremePrecipitationGroupShown[i][0]);
								break;
							case "milimeter":
								milimeterGroupShown.push(extremePrecipitationGroupShown[i][0]);
								break;
							case "pascal":
								pascalGroupShown.push(extremePrecipitationGroupShown[i][0]);
								break;
							case "meterPerSecond":
								meterPerSecondGroupShown.push(extremePrecipitationGroupShown[i][0]);
								break;
							case "degrees":
								degreesGroupShown.push(extremePrecipitationGroupShown[i][0]);
								break;
							case "octas":
								octasGroupShown.push(extremePrecipitationGroupShown[i][0]);
								break;
						}
					}
					for (var i=0; i<windGroupShown.length; i++) {
						switch (windGroupShown[i][5]) {
							case "celsius":
								celsiusGroupShown.push(windGroupShown[i][0]);
								break;
							case "days":
								daysGroupShown.push(windGroupShown[i][0]);
								break;
							case "percent":
								percentGroupShown.push(windGroupShown[i][0]);
								break;
							case "milimeter":
								milimeterGroupShown.push(windGroupShown[i][0]);
								break;
							case "pascal":
								pascalGroupShown.push(windGroupShown[i][0]);
								break;
							case "meterPerSecond":
								meterPerSecondGroupShown.push(windGroupShown[i][0]);
								break;
							case "degrees":
								degreesGroupShown.push(windGroupShown[i][0]);
								break;
							case "octas":
								octasGroupShown.push(windGroupShown[i][0]);
								break;
						}
					}
					for (var i=0; i<otherGroupShown.length; i++) {
						switch (otherGroupShown[i][5]) {
							case "celsius":
								celsiusGroupShown.push(otherGroupShown[i][0]);
								break;
							case "days":
								daysGroupShown.push(otherGroupShown[i][0]);
								break;
							case "percent":
								percentGroupShown.push(otherGroupShown[i][0]);
								break;
							case "milimeter":
								milimeterGroupShown.push(otherGroupShown[i][0]);
								break;
							case "pascal":
								pascalGroupShown.push(otherGroupShown[i][0]);
								break;
							case "meterPerSecond":
								meterPerSecondGroupShown.push(otherGroupShown[i][0]);
								break;
							case "degrees":
								degreesGroupShown.push(otherGroupShown[i][0]);
								break;
							case "octas":
								octasGroupShown.push(otherGroupShown[i][0]);
								break;
						}
					}
				}
				fillUnitGroups();
		
				// Find the max and min values for the Y scales
				function findMaxMin() {
					// Celsius values
					minCelsiusYArray = [];
					maxCelsiusYArray = [];
					for (var i=0; i<celsiusGroupShown.length; i++) {
						minCelsiusYArray.push(d3.min(data, function(d) { return Math.min(d[celsiusGroupShown[i]]); }) );
						maxCelsiusYArray.push(d3.max(data, function(d) { return Math.max(d[celsiusGroupShown[i]]); }) );  
					}
					minCelsiusY = d3.min(minCelsiusYArray);
					maxCelsiusY = d3.max(maxCelsiusYArray);
					// Days values
					minDaysYArray = [];
					maxDaysYArray = [];
					for (var i=0; i<daysGroupShown.length; i++) {
						minDaysYArray.push(d3.min(data, function(d) { return Math.min(d[daysGroupShown[i]]); }) );
						maxDaysYArray.push(d3.max(data, function(d) { return Math.max(d[daysGroupShown[i]]); }) );  
					}
					minDaysY = d3.min(minDaysYArray);
					maxDaysY = d3.max(maxDaysYArray);
					// Percent values
					minPercentYArray = [];
					maxPercentYArray = [];
					for (var i=0; i<percentGroupShown.length; i++) {
						minPercentYArray.push(d3.min(data, function(d) { return Math.min(d[percentGroupShown[i]]); }) );
						maxPercentYArray.push(d3.max(data, function(d) { return Math.max(d[percentGroupShown[i]]); }) );  
					}
					minPercentY = d3.min(minPercentYArray);
					maxPercentY = d3.max(maxPercentYArray);
					// Milimeter values
					minMilimeterYArray = [];
					maxMilimeterYArray = [];
					for (var i=0; i<milimeterGroupShown.length; i++) {
						minMilimeterYArray.push(d3.min(data, function(d) { return Math.min(d[milimeterGroupShown[i]]); }) );
						maxMilimeterYArray.push(d3.max(data, function(d) { return Math.max(d[milimeterGroupShown[i]]); }) );  
					}
					minMilimeterY = d3.min(minMilimeterYArray);
					maxMilimeterY = d3.max(maxMilimeterYArray);
					// Pascal values
					minPascalYArray = [];
					maxPascalYArray = [];
					for (var i=0; i<pascalGroupShown.length; i++) {
						minPascalYArray.push(d3.min(data, function(d) { return Math.min(d[pascalGroupShown[i]]); }) );
						maxPascalYArray.push(d3.max(data, function(d) { return Math.max(d[pascalGroupShown[i]]); }) );  
					}
					minPascalY = d3.min(minPascalYArray);
					maxPascalY = d3.max(maxPascalYArray);
					// Meter per second values
					minMeterPerSecondYArray = [];
					maxMeterPerSecondYArray = [];
					for (var i=0; i<meterPerSecondGroupShown.length; i++) {
						minMeterPerSecondYArray.push(d3.min(data, function(d) { return Math.min(d[meterPerSecondGroupShown[i]]); }) );
						maxMeterPerSecondYArray.push(d3.max(data, function(d) { return Math.max(d[meterPerSecondGroupShown[i]]); }) );  
					}
					minMeterPerSecondY = d3.min(minMeterPerSecondYArray);
					maxMeterPerSecondY = d3.max(maxMeterPerSecondYArray);
					// Degrees values
					minDegreesYArray = [];
					maxDegreesYArray = [];
					for (var i=0; i<degreesGroupShown.length; i++) {
						minDegreesYArray.push(d3.min(data, function(d) { return Math.min(d[degreesGroupShown[i]]); }) );
						maxDegreesYArray.push(d3.max(data, function(d) { return Math.max(d[degreesGroupShown[i]]); }) );  
					}
					minDegreesY = d3.min(minDegreesYArray);
					maxDegreesY = d3.max(maxDegreesYArray);
					// Octas values
					minOctasYArray = [];
					maxOctasYArray = [];
					for (var i=0; i<octasGroupShown.length; i++) {
						minOctasYArray.push(d3.min(data, function(d) { return Math.min(d[octasGroupShown[i]]); }) );
						maxOctasYArray.push(d3.max(data, function(d) { return Math.max(d[octasGroupShown[i]]); }) );  
					}
					minOctasY = d3.min(minOctasYArray);
					maxOctasY = d3.max(maxOctasYArray);
				}
				findMaxMin();
				
				// Y Scales
				yScaleCelsius = d3.scale.linear()
					.domain([minCelsiusY, maxCelsiusY])
					.range([height, 0]);
				yScaleDays = d3.scale.linear()
					.domain([minDaysY, maxDaysY])
					.range([height, 0]);
				yScalePercent = d3.scale.linear()
					.domain([minPercentY, maxPercentY])
					.range([height, 0]);
				yScaleMilimeter = d3.scale.linear()
					.domain([minMilimeterY, maxMilimeterY])
					.range([height, 0]);
				yScalePascal = d3.scale.linear()
					.domain([minPascalY, maxPascalY])
					.range([height, 0]);
					
				yScaleMeterPerSecond = d3.scale.linear()
					.domain([minMeterPerSecondY, maxMeterPerSecondY])
					.range([height, 0]);
				yScaleDegrees = d3.scale.linear()
					.domain([minDegreesY, maxDegreesY])
					.range([height, 0]);
				yScaleOctas = d3.scale.linear()
					.domain([minOctasY, maxOctasY])
					.range([height, 0]);
				
				// Which and how many Y-Axes we need
				function findAxis() {
					axis_selection = 0;
					yAxisArray = [];
					celsius_selection = false;
					if (celsiusGroupShown.length>0) {
						celsius_selection=true;
						yAxisArray.push(["yAxisCelsius", yScaleCelsius, "Celsius"]);
						axis_selection=axis_selection+1;
					}
					days_selection = false;
					if (daysGroupShown.length>0) {
						days_selection = true;
						yAxisArray.push(["yAxisDays", yScaleDays, "Days"]);
						axis_selection=axis_selection+1;
					}
					percent_selection = false;
					if (percentGroupShown.length>0) {
						percent_selection = true;
						yAxisArray.push(["yAxisPercent", yScalePercent, "Percent"]);
						axis_selection=axis_selection+1;
					}
					milimeter_selection = false;
					if (milimeterGroupShown.length>0) {
						milimeter_selection = true;
						yAxisArray.push(["yAxisMilimeter", yScaleMilimeter, "Milimeter"]);
						axis_selection=axis_selection+1;
					}
					pascal_selection = false;
					if (pascalGroupShown.length>0) {
						pascal_selection = true;
						yAxisArray.push(["yAxisPascal", yScalePascal, "Pascal"]);
						axis_selection=axis_selection+1;
					}	
					meterPerSecond_selection = false;
					if (meterPerSecondGroupShown.length>0) {
						meterPerSecond_selection = true;
						yAxisArray.push(["yAxisMeterPerSecond", yScaleMeterPerSecond, "Meter Per Second"]);
						axis_selection=axis_selection+1;
					}
					degrees_selection = false;
					if (degreesGroupShown.length>0) {
						degrees_selection = true;
						yAxisArray.push(["yAxisDegrees", yScaleDegrees, "Degrees"]);
						axis_selection=axis_selection+1;
					}
					octas_selection = false;
					if (octasGroupShown.length>0) {
						octas_selection = true;
						yAxisArray.push(["yAxisOctas", yScaleOctas, "Octas"]);
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
				function graphDraw(graphType, yScale, color) {
					var yScaleType;
					switch (yScale) {
						case "celsius":
							yScaleType=yScaleCelsius;
							break;
						case "days":
							yScaleType=yScaleDays;
							break;
						case "percent":
							yScaleType=yScalePercent;
							break;
						case "milimeter":
							yScaleType=yScaleMilimeter;
							break;
						case "pascal":
							yScaleType=yScalePascal;
							break;
						case "meterPerSecond":
							yScaleType=yScaleMeterPerSecond;
							break;
						case "degrees":
							yScaleType=yScaleDegrees;
							break;
						case "octas":
							yScaleType=yScaleOctas;
							break;								
					}
					
					var graphObj = {};
					
					graphObj[graphType] = d3.svg.line()
						.interpolate("linear")
						.x(function(d){return xScale(d.date)})
						.y(function(d){return yScaleType(d[graphType])});
	
					d3.select("#svg"+block)
						.append("path")
					  	.attr("id", "d3_path"+graphType+"ID"+block)
						.attr("d", graphObj[graphType](data))
						.attr("stroke", color)
						.attr("stroke-width", "2")
						.attr("fill", "none")
						.attr("transform", "translate(" + (margin.left-((margin.left_single*axis_sum)-(margin.left_single*axis_selection))) + "," + margin.top + ")");	  
				}
				
				function drawGraphs() {
					for (var i=0; i<temperatureGroupShown.length; i++) {
						graphDraw(temperatureGroupShown[i][0], temperatureGroupShown[i][5], temperatureGroupShown[i][1]);
					}
					for (var i=0; i<warmExtremesGroupShown.length; i++) {
						graphDraw(warmExtremesGroupShown[i][0], warmExtremesGroupShown[i][5], warmExtremesGroupShown[i][1]);
					}
					for (var i=0; i<coldExtremesGroupShown.length; i++) {
						graphDraw(coldExtremesGroupShown[i][0], coldExtremesGroupShown[i][5], coldExtremesGroupShown[i][1]);
					}
					for (var i=0; i<precipitationGroupShown.length; i++) {
						graphDraw(precipitationGroupShown[i][0], precipitationGroupShown[i][5], precipitationGroupShown[i][1]);
					}
					for (var i=0; i<extremePrecipitationGroupShown.length; i++) {
						graphDraw(extremePrecipitationGroupShown[i][0], extremePrecipitationGroupShown[i][5], extremePrecipitationGroupShown[i][1]);
					}
					for (var i=0; i<windGroupShown.length; i++) {
						graphDraw(windGroupShown[i][0], windGroupShown[i][5], windGroupShown[i][1]);
					}
					for (var i=0; i<otherGroupShown.length; i++) {
						graphDraw(otherGroupShown[i][0], otherGroupShown[i][5], otherGroupShown[i][1]);
					}
				}
				drawGraphs();
	
				// Draw Y Axis
				function yAxisDraw(axisType, scaleType, label, axisPosition) {
					var yAxisObj = {};
					var yAxisLabel;
					var yAxisLabelOffset;
					var yAxisTickFormat;
					var iconLink;
					var iconWidth;
					var iconHeight;
					if (axisType==="yAxisCelsius") {
						yAxisLabel = "&#8451;" // Celsius
						yAxisLabelOffset = -20;
						yAxisTickFormat = ".1f";
						iconLink = settings.basePath +"sites/all/modules/custom/ccis/images/d3/symbol_legende_thermometer.png";
						iconWidth = "7px";
						iconHeight = "21px";
					} else if (axisType==="yAxisDays") {
						yAxisLabel = "days"
						yAxisLabelOffset = -20;
						yAxisTickFormat = ".0f";
						iconLink = "";
						//iconLink = settings.basePath +"sites/all/modules/custom/ccis/images/d3/symbol_legende_thermometer.png";
						iconWidth = "7px";
						iconHeight = "21px";
					} else if (axisType==="yAxisPercent") {
						yAxisLabel = "%"
						yAxisLabelOffset = -20;
						yAxisTickFormat = ".1f";
						iconLink = "";
						//iconLink = settings.basePath +"sites/all/modules/custom/ccis/images/d3/symbol_legende_thermometer.png";
						iconWidth = "7px";
						iconHeight = "21px";
					} else if (axisType==="yAxisMilimeter") {
						yAxisLabel = "mm"
						yAxisLabelOffset = -20;
						yAxisTickFormat = ".1f";
						iconLink = settings.basePath +"sites/all/modules/custom/ccis/images/d3/symbol_legende_drop.png";
						iconWidth = "12px";
						iconHeight = "17px";
					} else if (axisType==="yAxisPascal") {
						yAxisLabel = "hPa"
						yAxisLabelOffset = -20;
						yAxisTickFormat = ".0f";
						iconLink = settings.basePath +"sites/all/modules/custom/ccis/images/d3/symbol_legende_pressure.png";
						iconWidth = "19px";
						iconHeight = "16px";
					} else if (axisType==="yAxisMeterPerSecond") {
						yAxisLabel = "m/s"
						yAxisLabelOffset = -20;
						yAxisTickFormat = ".1f";
						iconLink = "";
						//iconLink = settings.basePath +"sites/all/modules/custom/ccis/images/d3/symbol_legende_thermometer.png";
						iconWidth = "7px";
						iconHeight = "21px";
					} else if (axisType==="yAxisDegrees") {
						yAxisLabel = "degrees"
						yAxisLabelOffset = -20;
						yAxisTickFormat = ".0f";
						iconLink = "";
						//iconLink = settings.basePath +"sites/all/modules/custom/ccis/images/d3/symbol_legende_drop.png";
						iconWidth = "12px";
						iconHeight = "17px";
					} else if (axisType==="yAxisOctas") {
						yAxisLabel = "octas"
						yAxisLabelOffset = -20;
						yAxisTickFormat = ".1f";
						iconLink = "";
						//iconLink = settings.basePath +"sites/all/modules/custom/ccis/images/d3/symbol_legende_pressure.png";
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
						.attr("transform", "translate ("+yAxisLabelOffset+", -5)");
					
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
				// Temperature group
				if (temperatureGroupUsed.length>0 || warmExtremesGroupUsed.length>0 || coldExtremesGroupUsed.length>0) {
					$("#d3_legendDiv"+block).append("<div id='d3_iconLegendTemp"+block+"' class='d3_iconLegendTempClass'><img src='"+settings.basePath+"sites/all/modules/custom/ccis/images/d3/symbol_legende_thermometer.png' width='7' height='21'></div>");
					$("#d3_legendDiv"+block).append("<div id='d3_temperatureToggle"+block+"' class='d3_toggleClass'><b><span id='d3_tempMinus"+block+"' class='d3_minus'>"+plus+"</span> Temperature<span class='d3_unitLegend'></span></b></div>");
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
					// Main temperature group
					if (temperatureGroupUsed.length>0) {
						$("#d3_legendDiv"+block).append("<div id='d3_keysDivTemperature"+block+"'></div>");
						for (var i=0; i<temperatureGroupUsed.length; i++) {
							function findTemperatureChecked() {
								for (var k=0; k<temperatureGroupShown.length; k++) {
									if (temperatureGroupUsed[i][0]===temperatureGroupShown[k][0]) {
										return "checked";
									}
								}
							}
							$("#d3_keysDivTemperature"+block).append("<div id='d3_keysTemperature"+i+block+"' class='d3_keys'></div>");
							$("#d3_keysTemperature"+i+block).append("<div id='d3_keysTemperatureTick"+i+block+"' class='d3_keysTick'><input id='d3_checkboxTemperature"+i+block+"' type='checkbox' value='"+i+"' "+findTemperatureChecked()+"></div>");			
							$("#d3_keysTemperature"+i+block).append("<div id='d3_keysTemperatureBoxText"+i+block+"' class='d3_keysBoxText'></div>");
							$("#d3_keysTemperatureBoxText"+i+block).append("<div id='keysTemperatureText"+i+block+"' class='d3_keysText'></div>");
							$("#keysTemperatureText"+i+block).append(temperatureGroupUsed[i][2]);
							$("#d3_keysTemperatureBoxText"+i+block).append("<div id='keysTemperatureIcon"+i+block+"' class='d3_keysIcon'><img src='"+settings.basePath+"sites/all/modules/custom/ccis/images/d3/"+temperatureGroupUsed[i][4]+"' width='25' height='15'></div>");
							(function(i) {
								$("#d3_keysTemperatureBoxText"+i+block)
									.hover(function(){
										$(this).css("cursor","default"); 
										$("#"+blockID).append("<div id='d3_tooltipLegend"+i+block+"'></div>"); 
										var topPosition = $("#d3_keysTemperatureBoxText"+i+block).position().top; 
										hoverLegend(topPosition, i, temperatureGroupUsed[i][3]);
									},
									function() {$("#d3_tooltipLegend"+i+block).remove();});
							})(i);
						}
					}
					// Warm Extremes group
					if (warmExtremesGroupUsed.length>0) {
						$("#d3_legendDiv"+block).append("<div id='d3_warmExtremesToggle"+block+"' class='d3_toggleSubClass'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<b><span id='d3_warmExtremesMinus"+block+"' class='d3_minus'>"+plus+"</span> Warm Extremes <span class='d3_unitLegend'></span></b></div>");
						$("#d3_warmExtremesToggle"+block).hover(function() {
						$(this).css("cursor","pointer");
						$("#"+blockID).append("<div id='d3_tooltipLegendCategories"+block+"'></div>"); 
						var topPosition = $("#d3_warmExtremesToggle"+block).position().top;
						var legendText;
						if (warmExtremesHidden===true) {
							legendText = legendCategoriesOpen;
						} else if (warmExtremesHidden===false) {
							legendText = legendCategoriesClose;
						}
						hoverLegendCategories(topPosition, legendText);
					}, function() {$("#d3_tooltipLegendCategories"+block).remove();});
						$("#d3_legendDiv"+block).append("<div id='d3_keysDivWarmExtremes"+block+"'></div>");
						for (var i=0; i<warmExtremesGroupUsed.length; i++) {
							function findWarmExtremesChecked() {
								for (var k=0; k<warmExtremesGroupShown.length; k++) {
									if (warmExtremesGroupUsed[i][0]===warmExtremesGroupShown[k][0]) {
										return "checked";
									}
								}
							}
							$("#d3_keysDivWarmExtremes"+block).append("<div id='d3_keysWarmExtremes"+i+block+"' class='d3_keys'></div>");
							$("#d3_keysWarmExtremes"+i+block).append("<div id='d3_keysWarmExtremesTick"+i+block+"' class='d3_keysTick d3_keysSubTick'><input id='d3_checkboxWarmExtremes"+i+block+"' type='checkbox' value='"+i+"' "+findWarmExtremesChecked()+"></div>");			
							$("#d3_keysWarmExtremes"+i+block).append("<div id='d3_keysWarmExtremesBoxText"+i+block+"' class='d3_keysBoxText'></div>");
							$("#d3_keysWarmExtremesBoxText"+i+block).append("<div id='keysWarmExtremesText"+i+block+"' class='d3_keysText'></div>");
							$("#keysWarmExtremesText"+i+block).append(warmExtremesGroupUsed[i][2]);
							$("#d3_keysWarmExtremesBoxText"+i+block).append("<div id='keysWarmExtremesIcon"+i+block+"' class='d3_keysIcon'><img src='"+settings.basePath+"sites/all/modules/custom/ccis/images/d3/"+warmExtremesGroupUsed[i][4]+"' width='25' height='15'></div>");
							(function(i) {
								$("#d3_keysWarmExtremesBoxText"+i+block)
									.hover(function(){
										$(this).css("cursor","default"); 
										$("#"+blockID).append("<div id='d3_tooltipLegend"+i+block+"'></div>"); 
										var topPosition = $("#d3_keysWarmExtremesBoxText"+i+block).position().top; 
										hoverLegend(topPosition, i, warmExtremesGroupUsed[i][3]);
									},
									function() {$("#d3_tooltipLegend"+i+block).remove();});
							})(i);
						}
					}
					// Cold Extremes group
					if (coldExtremesGroupUsed.length>0) {
						$("#d3_legendDiv"+block).append("<div id='d3_coldExtremesToggle"+block+"' class='d3_toggleSubClass'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<b><span id='d3_coldExtremesMinus"+block+"' class='d3_minus'>"+plus+"</span> Cold Extremes <span class='d3_unitLegend'></span></b></div>");
						$("#d3_coldExtremesToggle"+block).hover(function() {
						$(this).css("cursor","pointer");
						$("#"+blockID).append("<div id='d3_tooltipLegendCategories"+block+"'></div>"); 
						var topPosition = $("#d3_coldExtremesToggle"+block).position().top;
						var legendText;
						if (coldExtremesHidden===true) {
							legendText = legendCategoriesOpen;
						} else if (coldExtremesHidden===false) {
							legendText = legendCategoriesClose;
						}
						hoverLegendCategories(topPosition, legendText);
					}, function() {$("#d3_tooltipLegendCategories"+block).remove();});
						$("#d3_legendDiv"+block).append("<div id='d3_keysDivColdExtremes"+block+"'></div>");
						for (var i=0; i<coldExtremesGroupUsed.length; i++) {
							function findColdExtremesChecked() {
								for (var k=0; k<coldExtremesGroupShown.length; k++) {
									if (coldExtremesGroupUsed[i][0]===coldExtremesGroupShown[k][0]) {
										return "checked";
									}
								}
							}
							$("#d3_keysDivColdExtremes"+block).append("<div id='d3_keysColdExtremes"+i+block+"' class='d3_keys'></div>");
							$("#d3_keysColdExtremes"+i+block).append("<div id='d3_keysColdExtremesTick"+i+block+"' class='d3_keysTick d3_keysSubTick'><input id='d3_checkboxColdExtremes"+i+block+"' type='checkbox' value='"+i+"' "+findColdExtremesChecked()+"></div>");			
							$("#d3_keysColdExtremes"+i+block).append("<div id='d3_keysColdExtremesBoxText"+i+block+"' class='d3_keysBoxText'></div>");
							$("#d3_keysColdExtremesBoxText"+i+block).append("<div id='keysColdExtremesText"+i+block+"' class='d3_keysText'></div>");
							$("#keysColdExtremesText"+i+block).append(coldExtremesGroupUsed[i][2]);
							$("#d3_keysColdExtremesBoxText"+i+block).append("<div id='keysColdExtremesIcon"+i+block+"' class='d3_keysIcon'><img src='"+settings.basePath+"sites/all/modules/custom/ccis/images/d3/"+coldExtremesGroupUsed[i][4]+"' width='25' height='15'></div>");
							(function(i) {
								$("#d3_keysColdExtremesBoxText"+i+block)
									.hover(function(){
										$(this).css("cursor","default"); 
										$("#"+blockID).append("<div id='d3_tooltipLegend"+i+block+"'></div>"); 
										var topPosition = $("#d3_keysColdExtremesBoxText"+i+block).position().top; 
										hoverLegend(topPosition, i, coldExtremesGroupUsed[i][3]);
									},
									function() {$("#d3_tooltipLegend"+i+block).remove();});
							})(i);
						}
					}
				}		
				// Precipitation group
				if (precipitationGroupUsed.length>0 || extremePrecipitationGroupUsed.length>0) {
					$("#d3_legendDiv"+block).append("<div id='d3_iconLegendPrec"+block+"' class='d3_iconLegendPrecClass'><img src='"+settings.basePath+"sites/all/modules/custom/ccis/images/d3/symbol_legende_drop.png' width='11' height='17'></div>");
					$("#d3_legendDiv"+block).append("<div id='d3_precipitationToggle"+block+"' class='d3_toggleClass'><b><span id='d3_precMinus"+block+"' class='d3_minus'>"+plus+"</span> Precipitation<span class='d3_unitLegend'></span></b></div>");
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
					// Main precipitation group
					if (precipitationGroupUsed.length>0) {
						$("#d3_legendDiv"+block).append("<div id='d3_keysDivPrecipitation"+block+"'></div>");
						for (var i=0; i<precipitationGroupUsed.length; i++) {
							function findPrecipitationChecked() {
								for (var k=0; k<precipitationGroupShown.length; k++) {
									if (precipitationGroupUsed[i][0]===precipitationGroupShown[k][0]) {
										return "checked";
									}
								}
							}
							$("#d3_keysDivPrecipitation"+block).append("<div id='d3_keysPrecipitation"+i+block+"' class='d3_keys'></div>");
							$("#d3_keysPrecipitation"+i+block).append("<div id='d3_keysPrecipitationTick"+i+block+"' class='d3_keysTick'><input id='d3_checkboxPrecipitation"+i+block+"' type='checkbox' value='"+i+"' "+findPrecipitationChecked()+"></div>");
							$("#d3_keysPrecipitation"+i+block).append("<div id='d3_keysPrecipitationBoxText"+i+block+"' class='d3_keysBoxText'></div>")
							
							$("#d3_keysPrecipitationBoxText"+i+block).append("<div id='d3_keysPrecipitationText"+i+block+"' class='d3_keysText'></div>");
							$("#d3_keysPrecipitationText"+i+block).append(precipitationGroupUsed[i][2]);
							$("#d3_keysPrecipitationBoxText"+i+block).append("<div id='d3_keysPrecipitationIcon"+i+block+"' class='d3_keysIcon'><img src='"+settings.basePath+"sites/all/modules/custom/ccis/images/d3/"+precipitationGroupUsed[i][4]+"' width='25' height='15'></div>");
							(function(i) {
								$("#d3_keysPrecipitationBoxText"+i+block)
									.hover(function(){
										$(this).css("cursor","default"); 
										$("#"+blockID).append("<div id='d3_tooltipLegend"+i+block+"'></div>"); 
										var topPosition = $("#d3_keysPrecipitationBoxText"+i+block).position().top; 
										hoverLegend(topPosition, i, precipitationGroupUsed[i][3]);
									},
									function() {$("#d3_tooltipLegend"+i+block).remove();});
							})(i);
						}
					}
					// Extreme Precipitation group
					if (extremePrecipitationGroupUsed.length>0) {
						$("#d3_legendDiv"+block).append("<div id='d3_extremePrecipitationToggle"+block+"' class='d3_toggleSubClass'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<b><span id='d3_extremePrecMinus"+block+"' class='d3_minus'>"+plus+"</span> Extreme Precipitation <span class='d3_unitLegend'></span></b></div>");
						$("#d3_extremePrecipitationToggle"+block).hover(function() {
						$(this).css("cursor","pointer");
						$("#"+blockID).append("<div id='d3_tooltipLegendCategories"+block+"'></div>"); 
						var topPosition = $("#d3_extremePrecipitationToggle"+block).position().top;
						var legendText;
						if (extremePrecipitationHidden===true) {
							legendText = legendCategoriesOpen;
						} else if (extremePrecipitationHidden===false) {
							legendText = legendCategoriesClose;
						}
						hoverLegendCategories(topPosition, legendText);
					}, function() {$("#d3_tooltipLegendCategories"+block).remove();});
						$("#d3_legendDiv"+block).append("<div id='d3_keysDivExtremePrecipitation"+block+"'></div>");
						for (var i=0; i<extremePrecipitationGroupUsed.length; i++) {
							function findExtremePrecipitationChecked() {
								for (var k=0; k<extremePrecipitationGroupShown.length; k++) {
									if (extremePrecipitationGroupUsed[i][0]===extremePrecipitationGroupShown[k][0]) {
										return "checked";
									}
								}
							}
							$("#d3_keysDivExtremePrecipitation"+block).append("<div id='d3_keysExtremePrecipitation"+i+block+"' class='d3_keys'></div>");
							$("#d3_keysExtremePrecipitation"+i+block).append("<div id='d3_keysExtremePrecipitationTick"+i+block+"' class='d3_keysTick d3_keysSubTick'><input id='d3_checkboxExtremePrecipitation"+i+block+"' type='checkbox' value='"+i+"' "+findExtremePrecipitationChecked()+"></div>");
							$("#d3_keysExtremePrecipitation"+i+block).append("<div id='d3_keysExtremePrecipitationBoxText"+i+block+"' class='d3_keysBoxText'></div>")
							
							$("#d3_keysExtremePrecipitationBoxText"+i+block).append("<div id='d3_keysExtremePrecipitationnText"+i+block+"' class='d3_keysText'></div>");
							$("#d3_keysExtremePrecipitationnText"+i+block).append(extremePrecipitationGroupUsed[i][2]);
							$("#d3_keysExtremePrecipitationBoxText"+i+block).append("<div id='d3_keysExtremePrecipitationIcon"+i+block+"' class='d3_keysIcon'><img src='"+settings.basePath+"sites/all/modules/custom/ccis/images/d3/"+extremePrecipitationGroupUsed[i][4]+"' width='25' height='15'></div>");
							(function(i) {
								$("#d3_keysExtremePrecipitationBoxText"+i+block)
									.hover(function(){
										$(this).css("cursor","default"); 
										$("#"+blockID).append("<div id='d3_tooltipLegend"+i+block+"'></div>"); 
										var topPosition = $("#d3_keysExtremePrecipitationBoxText"+i+block).position().top; 
										hoverLegend(topPosition, i, extremePrecipitationGroupUsed[i][3]);
									},
									function() {$("#d3_tooltipLegend"+i+block).remove();});
							})(i);
						}
					}
				}
				// Wind group
				if (windGroupUsed.length>0) {
					$("#d3_legendDiv"+block).append("<div id='d3_iconLegendWind"+block+"' class='d3_iconLegendWindClass'><img src='"+settings.basePath+"sites/all/modules/custom/ccis/images/d3/symbol_legende_wind.png' width='11' height='17'></div>");
					$("#d3_legendDiv"+block).append("<div id='d3_windToggle"+block+"' class='d3_toggleClass'><b><span id='d3_windMinus"+block+"' class='d3_minus'>"+plus+"</span> Wind<span class='d3_unitLegend'></span></b></div>");
					$("#d3_windToggle"+block).hover(function() {
						$(this).css("cursor","pointer");
						$("#"+blockID).append("<div id='d3_tooltipLegendCategories"+block+"'></div>"); 
						var topPosition = $("#d3_windToggle"+block).position().top;
						var legendText;
						if (windHidden===true) {
							legendText = legendCategoriesOpen;
						} else if (windHidden===false) {
							legendText = legendCategoriesClose;
						}
						hoverLegendCategories(topPosition, legendText);
					}, function() {$("#d3_tooltipLegendCategories"+block).remove();});
					$("#d3_legendDiv"+block).append("<div id='d3_keysDivWind"+block+"'></div>");
					for (var i=0; i<windGroupUsed.length; i++) {
						function findWindChecked() {
							for (var k=0; k<windGroupShown.length; k++) {
								if (windGroupUsed[i][0]===windGroupShown[k][0]) {
									return "checked";
								}
							}
						}
						$("#d3_keysDivWind"+block).append("<div id='d3_keysWind"+i+block+"' class='d3_keys'></div>");
						$("#d3_keysWind"+i+block).append("<div id='d3_keysWindTick"+i+block+"' class='d3_keysTick'><input id='d3_checkboxWind"+i+block+"' type='checkbox' value='"+i+"' "+findWindChecked()+"></div>");
						$("#d3_keysWind"+i+block).append("<div id='d3_keysWindBoxText"+i+block+"' class='d3_keysBoxText'></div>")
						
						$("#d3_keysWindBoxText"+i+block).append("<div id='d3_keysWindText"+i+block+"' class='d3_keysText'></div>");
						$("#d3_keysWindText"+i+block).append(windGroupUsed[i][2]);
						$("#d3_keysWindBoxText"+i+block).append("<div id='d3_keysWindIcon"+i+block+"' class='d3_keysIcon'><img src='"+settings.basePath+"sites/all/modules/custom/ccis/images/d3/"+windGroupUsed[i][4]+"' width='17' height='13'></div>");
						(function(i) {
							$("#d3_keysWindBoxText"+i+block)
								.hover(function(){
									$(this).css("cursor","default"); 
									$("#"+blockID).append("<div id='d3_tooltipLegend"+i+block+"'></div>"); 
									var topPosition = $("#d3_keysWindBoxText"+i+block).position().top; 
									hoverLegend(topPosition, i, windGroupUsed[i][3]);
								},
								function() {$("#d3_tooltipLegend"+i+block).remove();});
						})(i);
					}
				}
				// Other group
				if (otherGroupUsed.length>0) {
					$("#d3_legendDiv"+block).append("<div id='d3_iconLegendOther"+block+"' class='d3_iconLegendOtherClass'><img src='"+settings.basePath+"sites/all/modules/custom/ccis/images/d3/symbol_legende_other.png' width='16' height='4'></div>");
					$("#d3_legendDiv"+block).append("<div id='d3_otherToggle"+block+"' class='d3_toggleClass'><b><span id='d3_otherMinus"+block+"' class='d3_minus'>"+plus+"</span> Other<span class='d3_unitLegend'></span></b></div>");
					$("#d3_otherToggle"+block).hover(function() {
						$(this).css("cursor","pointer");
						$("#"+blockID).append("<div id='d3_tooltipLegendCategories"+block+"'></div>"); 
						var topPosition = $("#d3_otherToggle"+block).position().top;
						var legendText;
						if (otherHidden===true) {
							legendText = legendCategoriesOpen;
						} else if (otherHidden===false) {
							legendText = legendCategoriesClose;
						}
						hoverLegendCategories(topPosition, legendText);
					}, function() {$("#d3_tooltipLegendCategories"+block).remove();});
					$("#d3_legendDiv"+block).append("<div id='d3_keysDivOther"+block+"'></div>");
					for (var i=0; i<otherGroupUsed.length; i++) {
						function findOtherChecked() {
							for (var k=0; k<otherGroupShown.length; k++) {
								if (otherGroupUsed[i][0]===otherGroupShown[k][0]) {
									return "checked";
								}
							}
						}
						$("#d3_keysDivOther"+block).append("<div id='d3_keysOther"+i+block+"' class='d3_keys'></div>");
						$("#d3_keysOther"+i+block).append("<div id='d3_keysOtherTick"+i+block+"' class='d3_keysTick'><input id='d3_checkboxOther"+i+block+"' type='checkbox' value='"+i+"' "+findOtherChecked()+"></div>");
						$("#d3_keysOther"+i+block).append("<div id='d3_keysOtherBoxText"+i+block+"' class='d3_keysBoxText'></div>")
						
						$("#d3_keysOtherBoxText"+i+block).append("<div id='d3_keysOtherText"+i+block+"' class='d3_keysText'></div>");
						$("#d3_keysOtherText"+i+block).append(otherGroupUsed[i][2]);
						$("#d3_keysOtherBoxText"+i+block).append("<div id='d3_keysOtherIcon"+i+block+"' class='d3_keysIcon'><img src='"+settings.basePath+"sites/all/modules/custom/ccis/images/d3/"+otherGroupUsed[i][4]+"' width='25' height='15'></div>");
						(function(i) {
							$("#d3_keysOtherBoxText"+i+block)
								.hover(function(){
									$(this).css("cursor","default"); 
									$("#"+blockID).append("<div id='d3_tooltipLegend"+i+block+"'></div>"); 
									var topPosition = $("#d3_keysOtherBoxText"+i+block).position().top; 
									hoverLegend(topPosition, i, otherGroupUsed[i][3]);
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
				for (var i=0; i<temperatureGroupUsed.length; i++) {
					$("#d3_keysTemperature"+i+block).hide();
					if ($("#d3_checkboxTemperature"+i+block).is(":checked")) {
						$("#d3_keysTemperature"+i+block).show();
					}	
				}
				temperatureHidden=true;
				for (var i=0; i<warmExtremesGroupUsed.length; i++) {
					$("#d3_keysWarmExtremes"+i+block).hide();
					if ($("#d3_checkboxWarmExtremes"+i+block).is(":checked")) {
						$("#d3_keysWarmExtremes"+i+block).show();
					}	
				} 
				warmExtremesHidden=true;
				for (var i=0; i<coldExtremesGroupUsed.length; i++) {
					$("#d3_keysColdExtremes"+i+block).hide();
					if ($("#d3_checkboxColdExtremes"+i+block).is(":checked")) {
						$("#d3_keysColdExtremes"+i+block).show();
					}	
				}
				coldExtremesHidden=true;
				for (var i=0; i<precipitationGroupUsed.length; i++) {
					$("#d3_keysPrecipitation"+i+block).hide();
					if ($("#d3_checkboxPrecipitation"+i+block).is(":checked")) {
						$("#d3_keysPrecipitation"+i+block).show();
					}	
				}
				precipitationHidden=true;
				for (var i=0; i<extremePrecipitationGroupUsed.length; i++) {
					$("#d3_keysExtremePrecipitation"+i+block).hide();
					if ($("#d3_checkboxExtremePrecipitation"+i+block).is(":checked")) {
						$("#d3_keysExtremePrecipitation"+i+block).show();
					}	
				}
				extremePrecipitationHidden=true;
				for (var i=0; i<windGroupUsed.length; i++) {
					$("#d3_keysWind"+i+block).hide();
					if ($("#d3_checkboxWind"+i+block).is(":checked")) {
						$("#d3_keysWind"+i+block).show();
					}	
				}
				windHidden=true;
				for (var i=0; i<otherGroupUsed.length; i++) {
					$("#d3_keysOther"+i+block).hide();
					if ($("#d3_checkboxOther"+i+block).is(":checked")) {
						$("#d3_keysOther"+i+block).show();
					}	
				}
				otherHidden=true;
				
				// Collapse	
				$("#d3_temperatureToggle"+block).click(function() {
					if (temperatureHidden===true) {
						$("#d3_tempMinus"+block).html(minus);
						for (var i=0; i<temperatureGroupUsed.length; i++) {			
							$("#d3_keysTemperature"+i+block).show();
						}
						temperatureHidden=false;
						$("#d3_tooltipLegendCategories"+block).html(legendCategoriesClose);
					} else if (temperatureHidden===false) {
						$("#d3_tempMinus"+block).html(plus);
						for (var i=0; i<temperatureGroupUsed.length; i++) {
							$("#d3_keysTemperature"+i+block).hide();
							if ($("#d3_checkboxTemperature"+i+block).is(":checked")) {
								$("#d3_keysTemperature"+i+block).show();
							}	
						}
						temperatureHidden=true;
						$("#d3_tooltipLegendCategories"+block).html(legendCategoriesOpen);
					}
				});
				$("#d3_warmExtremesToggle"+block).click(function() {
					if (warmExtremesHidden===true) {
						$("#d3_warmExtremesMinus"+block).html(minus);
						for (var i=0; i<warmExtremesGroupUsed.length; i++) {			
							$("#d3_keysWarmExtremes"+i+block).show();
						}
						warmExtremesHidden=false;
						$("#d3_tooltipLegendCategories"+block).html(legendCategoriesClose);
					} else if (warmExtremesHidden===false) {
						$("#d3_warmExtremesMinus"+block).html(plus);
						for (var i=0; i<warmExtremesGroupUsed.length; i++) {
							$("#d3_keysWarmExtremes"+i+block).hide();
							if ($("#d3_checkboxWarmExtremes"+i+block).is(":checked")) {
								$("#d3_keysWarmExtremes"+i+block).show();
							}	
						}
						warmExtremesHidden=true;
						$("#d3_tooltipLegendCategories"+block).html(legendCategoriesOpen);
					}
				});
				$("#d3_coldExtremesToggle"+block).click(function() {
					if (coldExtremesHidden===true) {
						$("#d3_coldExtremesMinus"+block).html(minus);
						for (var i=0; i<coldExtremesGroupUsed.length; i++) {			
							$("#d3_keysColdExtremes"+i+block).show();
						}
						coldExtremesHidden=false;
						$("#d3_tooltipLegendCategories"+block).html(legendCategoriesClose);
					} else if (coldExtremesHidden===false) {
						$("#d3_coldExtremesMinus"+block).html(plus);
						for (var i=0; i<coldExtremesGroupUsed.length; i++) {
							$("#d3_keysColdExtremes"+i+block).hide();
							if ($("#d3_checkboxColdExtremes"+i+block).is(":checked")) {
								$("#d3_keysColdExtremes"+i+block).show();
							}	
						}
						coldExtremesHidden=true;
						$("#d3_tooltipLegendCategories"+block).html(legendCategoriesOpen);
					}
				});
				$("#d3_precipitationToggle"+block).click(function() {
					if (precipitationHidden===true) {
						$("#d3_precMinus"+block).html(minus);
						for (var i=0; i<precipitationGroupUsed.length; i++) {			
							$("#d3_keysPrecipitation"+i+block).show();
						}
						precipitationHidden=false;
						$("#d3_tooltipLegendCategories"+block).html(legendCategoriesClose);
					} else if (precipitationHidden===false) {
						$("#d3_precMinus"+block).html(plus);
						for (var i=0; i<precipitationGroupUsed.length; i++) {
							$("#d3_keysPrecipitation"+i+block).hide();
							if ($("#d3_checkboxPrecipitation"+i+block).is(":checked")) {
								$("#d3_keysPrecipitation"+i+block).show();
							}	
						}
						precipitationHidden=true;
						$("#d3_tooltipLegendCategories"+block).html(legendCategoriesOpen);
					}
				});
				$("#d3_extremePrecipitationToggle"+block).click(function() {
					if (extremePrecipitationHidden===true) {
						$("#d3_extremePrecMinus"+block).html(minus);
						for (var i=0; i<extremePrecipitationGroupUsed.length; i++) {			
							$("#d3_keysExtremePrecipitation"+i+block).show();
						}
						extremePrecipitationHidden=false;
						$("#d3_tooltipLegendCategories"+block).html(legendCategoriesClose);
					} else if (extremePrecipitationHidden===false) {
						$("#d3_extremePrecMinus"+block).html(plus);
						for (var i=0; i<extremePrecipitationGroupUsed.length; i++) {
							$("#d3_keysExtremePrecipitation"+i+block).hide();
							if ($("#d3_checkboxExtremePrecipitation"+i+block).is(":checked")) {
								$("#d3_keysExtremePrecipitation"+i+block).show();
							}	
						}
						extremePrecipitationHidden=true;
						$("#d3_tooltipLegendCategories"+block).html(legendCategoriesOpen);
					}
				});
				$("#d3_windToggle"+block).click(function() {
					if (windHidden===true) {
						$("#d3_windMinus"+block).html(minus);
						for (var i=0; i<windGroupUsed.length; i++) {			
							$("#d3_keysWind"+i+block).show();
						}
						windHidden=false;
						$("#d3_tooltipLegendCategories"+block).html(legendCategoriesClose);
					} else if (windHidden===false) {
						$("#d3_windMinus"+block).html(plus);
						for (var i=0; i<windGroupUsed.length; i++) {
							$("#d3_keysWind"+i+block).hide();
							if ($("#d3_checkboxWind"+i+block).is(":checked")) {
								$("#d3_keysWind"+i+block).show();
							}	
						}
						windHidden=true;
						$("#d3_tooltipLegendCategories"+block).html(legendCategoriesOpen);
					}
				});
				$("#d3_otherToggle"+block).click(function() {
					if (otherHidden===true) {
						$("#d3_otherMinus"+block).html(minus);
						for (var i=0; i<otherGroupUsed.length; i++) {			
							$("#d3_keysOther"+i+block).show();
						}
						otherHidden=false;
						$("#d3_tooltipLegendCategories"+block).html(legendCategoriesClose);
					} else if (otherHidden===false) {
						$("#d3_otherMinus"+block).html(plus);
						for (var i=0; i<otherGroupUsed.length; i++) {
							$("#d3_keysOther"+i+block).hide();
							if ($("#d3_checkboxOther"+i+block).is(":checked")) {
								$("#d3_keysOther"+i+block).show();
							}	
						}
						otherHidden=true;
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
						var findIDsTemperature = $("#d3_keysDivTemperature"+block+" input:checkbox:checked").map(function() {		        
							return $(this).val();      
						});
						findTicksArrayTemperature = findIDsTemperature.get();
					}
					if (document.getElementById("d3_keysDivWarmExtremes"+block)) {
						var findIDsWarmExtremes = $("#d3_keysDivWarmExtremes"+block+" input:checkbox:checked").map(function() {		        
							return $(this).val();      
						});
						findTicksArrayWarmExtremes = findIDsWarmExtremes.get();
					}
					if (document.getElementById("d3_keysDivColdExtremes"+block)) {
						var findIDsColdExtremes = $("#d3_keysDivColdExtremes"+block+" input:checkbox:checked").map(function() {		        
							return $(this).val();      
						});
						findTicksArrayColdExtremes = findIDsColdExtremes.get();
					}
					if (document.getElementById("d3_keysDivPrecipitation"+block)) {
						var findIDsPrecipitation = $("#d3_keysDivPrecipitation"+block+" input:checkbox:checked").map(function() {		        
							return $(this).val();      
						});
						findTicksArrayPrecipitation = findIDsPrecipitation.get();
					}
					if (document.getElementById("d3_keysDivExtremePrecipitation"+block)) {
						var findIDsExtremePrecipitation = $("#d3_keysDivExtremePrecipitation"+block+" input:checkbox:checked").map(function() {		        
							return $(this).val();      
						});
						findTicksArrayExtremePrecipitation = findIDsExtremePrecipitation.get();
					}
					if (document.getElementById("d3_keysDivWind"+block)) {
						var findIDsWind = $("#d3_keysDivWind"+block+" input:checkbox:checked").map(function() {		        
							return $(this).val();      
						});
						findTicksArrayWind = findIDsWind.get();
					}
					if (document.getElementById("d3_keysDivOther"+block)) {
						var findIDsOther = $("#d3_keysDivOther"+block+" input:checkbox:checked").map(function() {		        
							return $(this).val();      
						});
						findTicksArrayOther = findIDsOther.get();
					}
	
					// Which parameters are selected
					temperatureGroupShown = [];
					var temperatureShownSingle;
					for (var i=0; i<findTicksArrayTemperature.length; i++) {
						temperatureShownSingle = temperatureGroupUsed[parseFloat(findTicksArrayTemperature[i])];
						temperatureGroupShown.push(temperatureShownSingle);			
					}
					warmExtremesGroupShown = [];
					var warmExtremesShownSingle;
					for (var i=0; i<findTicksArrayWarmExtremes.length; i++) {
						warmExtremesShownSingle = warmExtremesGroupUsed[parseFloat(findTicksArrayWarmExtremes[i])];
						warmExtremesGroupShown.push(warmExtremesShownSingle);			
					}
					coldExtremesGroupShown = [];
					var coldExtremesShownSingle;
					for (var i=0; i<findTicksArrayColdExtremes.length; i++) {
						coldExtremesShownSingle = coldExtremesGroupUsed[parseFloat(findTicksArrayColdExtremes[i])];
						coldExtremesGroupShown.push(coldExtremesShownSingle);			
					}
					precipitationGroupShown = [];
					var precipitationShownSingle;
					for (var i=0; i<findTicksArrayPrecipitation.length; i++) {
						precipitationShownSingle = precipitationGroupUsed[parseFloat(findTicksArrayPrecipitation[i])];
						precipitationGroupShown.push(precipitationShownSingle);			
					}
					extremePrecipitationGroupShown = [];
					var extremePrecipitationShownSingle;
					for (var i=0; i<findTicksArrayExtremePrecipitation.length; i++) {
						extremePrecipitationShownSingle = extremePrecipitationGroupUsed[parseFloat(findTicksArrayExtremePrecipitation[i])];
						extremePrecipitationGroupShown.push(extremePrecipitationShownSingle);			
					}
					windGroupShown = [];
					var windShownSingle;
					for (var i=0; i<findTicksArrayWind.length; i++) {
						windShownSingle = windGroupUsed[parseFloat(findTicksArrayWind[i])];
						windGroupShown.push(windShownSingle);			
					}
					otherGroupShown = [];
					var otherShownSingle;
					for (var i=0; i<findTicksArrayOther.length; i++) {
						otherShownSingle = otherGroupUsed[parseFloat(findTicksArrayOther[i])];
						otherGroupShown.push(otherShownSingle);			
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
					yScaleCelsius.range([height, 0]);
					yScaleDays.range([height, 0]);
					yScalePercent.range([height, 0]);
					yScaleMilimeter.range([height, 0]);
					yScaleDays.range([height, 0]);
					yScalePascal.range([height, 0]);	
					yScaleMeterPerSecond.range([height, 0]);
					yScaleDegrees.range([height, 0]);
					yScaleOctas.range([height, 0]);
					
					/*yScaleTemp.range([height, 0]);
					yScalePrec.range([height, 0]);
					yScalePress.range([height, 0]);*/
					
					// Create again the svg
					createSvg();
					
					// Find the max and min values for the Y scales
					findMaxMin();
					
					// Update Y domains
					yScaleCelsius.domain([minCelsiusY, maxCelsiusY]);
					yScaleDays.domain([minDaysY, maxDaysY]);
					yScalePercent.domain([minPercentY, maxPercentY]);
					yScaleMilimeter.domain([minMilimeterY, maxMilimeterY]);
					yScalePascal.domain([minPascalY, maxPascalY]);		
					yScaleMeterPerSecond.domain([minMeterPerSecondY, maxMeterPerSecondY]);
					yScaleDegrees.domain([minDegreesY, maxDegreesY]);
					yScaleOctas.domain([minOctasY, maxOctasY]);
										
					// Redraw Graphs
					drawGraphs();
					
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
						for (var i=0; i<temperatureGroupUsed.length; i++) {
							if ($("#d3_checkboxTemperature"+i+block).is(":checked")) {
								$("#d3_keysTemperature"+i+block).show();
							} else {
								$("#d3_keysTemperature"+i+block).hide();
							}
						}
					}
					if (warmExtremesHidden===true) {
						for (var i=0; i<warmExtremesGroupUsed.length; i++) {
							if ($("#d3_checkboxWarmExtremes"+i+block).is(":checked")) {
								$("#d3_keysWarmExtremes"+i+block).show();
							} else {
								$("#d3_keysWarmExtremes"+i+block).hide();
							}
						}
					}
					if (coldExtremesHidden===true) {
						for (var i=0; i<coldExtremesGroupUsed.length; i++) {
							if ($("#d3_checkboxColdExtremes"+i+block).is(":checked")) {
								$("#d3_keysColdExtremes"+i+block).show();
							} else {
								$("#d3_keysColdExtremes"+i+block).hide();
							}
						}
					}
					if (precipitationHidden===true) {
						for (var i=0; i<precipitationGroupUsed.length; i++) {
							if ($("#d3_checkboxPrecipitation"+i+block).is(":checked")) {
								$("#d3_keysPrecipitation"+i+block).show();
							} else {
								$("#d3_keysPrecipitation"+i+block).hide();
							}
						}
					}
					if (extremePrecipitationHidden===true) {
						for (var i=0; i<extremePrecipitationGroupUsed.length; i++) {
							if ($("#d3_checkboxExtremePrecipitation"+i+block).is(":checked")) {
								$("#d3_keysExtremePrecipitation"+i+block).show();
							} else {
								$("#d3_keysExtremePrecipitation"+i+block).hide();
							}
						}
					}
					if (windHidden===true) {
						for (var i=0; i<windGroupUsed.length; i++) {
							if ($("#d3_checkboxWind"+i+block).is(":checked")) {
								$("#d3_keysWind"+i+block).show();
							} else {
								$("#d3_keysWind"+i+block).hide();
							}
						}
					}
					if (otherHidden===true) {
						for (var i=0; i<otherGroupUsed.length; i++) {
							if ($("#d3_checkboxOther"+i+block).is(":checked")) {
								$("#d3_keysOther"+i+block).show();
							} else {
								$("#d3_keysOther"+i+block).hide();
							}
						}
					}
		
					// Hide dropdowns with delay
					if (temperatureHidden===false) {
						setTimeout(function(){$("#d3_temperatureToggle"+block).click();}, 2000);
					}
					if (warmExtremesHidden===false) {
						setTimeout(function(){$("#d3_warmExtremesToggle"+block).click();}, 2000);
					}
					if (coldExtremesHidden===false) {
						setTimeout(function(){$("#d3_coldExtremesToggle"+block).click();}, 2000);
					}
					if (precipitationHidden===false) {
						setTimeout(function(){$("#d3_precipitationToggle"+block).click();}, 2000); 
					}
					if (extremePrecipitationHidden===false) {
						setTimeout(function(){$("#d3_extremePrecipitationToggle"+block).click();}, 2000); 
					}
					if (windHidden===false) {
						setTimeout(function(){$("#d3_windToggle"+block).click();}, 2000); 
					}
					if (otherHidden===false) {
						setTimeout(function(){$("#d3_otherToggle"+block).click();}, 2000); 
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
						topOffset = 25;
					} else {
						topOffset = 290;
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
						
						// Find the Units
						function findHoverUnits(label) {
							switch (label) {
								case "celsius":
									return "&#8451;";
									break;
								case "days":
									return "days";
									break;
								case "percent":
									return "%";
									break;
								case "milimeter":
									return "mm";
									break;
								case "pascal":
									return "hPa";
									break;
								case "meterPerSecond":
									return "m/s";
									break;
								case "degrees":
									return "&#176;";
									break;
								case "octas":
									return "octas";
									break;
							}
						}
						
						if (item) {
							// Format the date
							var dateParse = d3.time.format("%a %b %d %Y").parse(item.date.toDateString());
							var formatter = d3.time.format("%Y-%m-%d");
							var date = formatter(dateParse);
							
							// Show the icons?
							var thermometer = false;
							if (temperatureGroupShown.length>0 || warmExtremesGroupShown.length>0 || coldExtremesGroupShown.length>0) {
								thermometer = true;
							}
							var drop = false;
							if (precipitationGroupShown.length>0 || extremePrecipitationGroupShown.length>0) {
								drop = true;
							}
							var wind = false;
							if (windGroupShown.length>0) {
								wind = true;
							}
							var other = false;
							if (otherGroupShown.length>0) {
								other = true;
							}
							// Create content for tooltips
							var tooltipText="";
							tooltipText = "<b><table style='margin:0px;'>";
								
								tooltipText += "<tr>";
									tooltipText += "<td>&nbsp;<img src='"+settings.basePath+"sites/all/modules/custom/ccis/images/d3/symbol_infobereich_clock.png' width='11' height='12'></td>";
									tooltipText += "<td>&nbsp;Date: </td>";
									tooltipText += "<td><b>"+date+"</b></td>";
								tooltipText += "</tr>";	
								if (temperatureGroupShown.length>0) {
									for (var i=0; i<temperatureGroupShown.length; i++) {									
										if (thermometer===true) {
											tooltipText += "<tr style='border-top: 1pt solid #D1D1FF;'>";
											tooltipText += "<td>&nbsp;<img src='"+settings.basePath+"sites/all/modules/custom/ccis/images/d3/symbol_legende_thermometer.png' width='7' height='21'></td>";
											thermometer = false;
										} else {
											tooltipText += "<tr>";
											tooltipText += "<td></td>";
										}
										tooltipText += "<td style='color:"+temperatureGroupShown[i][1]+"'>&nbsp;"+temperatureGroupShown[i][2]+"</td>";
										tooltipText += "<td style='color:"+temperatureGroupShown[i][1]+"'>"+item[temperatureGroupShown[i][0]].toFixed(1)+" "+findHoverUnits(temperatureGroupShown[i][5])+"</td>";
										tooltipText += "</tr>";
									}		
								}
								if (warmExtremesGroupShown.length>0) {
									for (var i=0; i<warmExtremesGroupShown.length; i++) {									
										if (thermometer===true) {
											tooltipText += "<tr style='border-top: 1pt solid #D1D1FF;'>";
											tooltipText += "<td>&nbsp;<img src='"+settings.basePath+"sites/all/modules/custom/ccis/images/d3/symbol_legende_thermometer.png' width='7' height='21'></td>";
											thermometer = false;
										} else {
											tooltipText += "<tr>";
											tooltipText += "<td></td>";
										}
										tooltipText += "<td style='color:"+warmExtremesGroupShown[i][1]+"'>&nbsp;"+warmExtremesGroupShown[i][2]+"</td>";
										tooltipText += "<td style='color:"+warmExtremesGroupShown[i][1]+"'>"+item[warmExtremesGroupShown[i][0]].toFixed(1)+" "+findHoverUnits(warmExtremesGroupShown[i][5])+"</td>";
										tooltipText += "</tr>";
									}		
								}
								if (coldExtremesGroupShown.length>0) {
									for (var i=0; i<coldExtremesGroupShown.length; i++) {									
										if (thermometer===true) {
											tooltipText += "<tr style='border-top: 1pt solid #D1D1FF;'>";
											tooltipText += "<td>&nbsp;<img src='"+settings.basePath+"sites/all/modules/custom/ccis/images/d3/symbol_legende_thermometer.png' width='7' height='21'></td>";
											thermometer = false;
										} else {
											tooltipText += "<tr>";
											tooltipText += "<td></td>";
										}
										tooltipText += "<td style='color:"+coldExtremesGroupShown[i][1]+"'>&nbsp;"+coldExtremesGroupShown[i][2]+"</td>";
										tooltipText += "<td style='color:"+coldExtremesGroupShown[i][1]+"'>"+item[coldExtremesGroupShown[i][0]].toFixed(1)+" "+findHoverUnits(coldExtremesGroupShown[i][5])+"</td>";
										tooltipText += "</tr>";
									}		
								}
								if (precipitationGroupShown.length>0) {
									for (var i=0; i<precipitationGroupShown.length; i++) {
										if (drop===true) {
											tooltipText += "<tr style='border-top: 1pt solid #D1D1FF;'>";
											tooltipText += "<td>&nbsp;<img src='"+settings.basePath+"sites/all/modules/custom/ccis/images/d3/symbol_legende_drop.png' width='11' height='17'></td>";
											drop = false;
										} else {
											tooltipText += "<tr>";
											tooltipText += "<td></td>";
										}
										tooltipText += "<td style='color:"+precipitationGroupShown[i][1]+"'>&nbsp;"+precipitationGroupShown[i][2]+"</td>";
										tooltipText += "<td style='color:"+precipitationGroupShown[i][1]+"'>"+item[precipitationGroupShown[i][0]].toFixed(1)+" "+findHoverUnits(precipitationGroupShown[i][5])+"</td>";
										tooltipText += "</tr>";
									}		
								}
								if (extremePrecipitationGroupShown.length>0) {
									for (var i=0; i<extremePrecipitationGroupShown.length; i++) {
										if (drop===true) {
											tooltipText += "<tr style='border-top: 1pt solid #D1D1FF;'>";
											tooltipText += "<td>&nbsp;<img src='"+settings.basePath+"sites/all/modules/custom/ccis/images/d3/symbol_legende_drop.png' width='11' height='17'></td>";
											drop = false;
										} else {
											tooltipText += "<tr>";
											tooltipText += "<td></td>";
										}
										tooltipText += "<td style='color:"+extremePrecipitationGroupShown[i][1]+"'>&nbsp;"+extremePrecipitationGroupShown[i][2]+"</td>";
										tooltipText += "<td style='color:"+extremePrecipitationGroupShown[i][1]+"'>"+item[extremePrecipitationGroupShown[i][0]].toFixed(1)+" "+findHoverUnits(extremePrecipitationGroupShown[i][5])+"</td>";
										tooltipText += "</tr>";
									}		
								}
								if (windGroupShown.length>0) {
									for (var i=0; i<windGroupShown.length; i++) {
										if (wind===true) {
											tooltipText += "<tr style='border-top: 1pt solid #D1D1FF;'>";
											tooltipText += "<td>&nbsp;<img src='"+settings.basePath+"sites/all/modules/custom/ccis/images/d3/symbol_legende_wind.png' width='19' height='16'></td>";
										} else {
											tooltipText += "<tr>";
											tooltipText += "<td></td>";
										}
										tooltipText += "<td style='color:"+windGroupShown[i][1]+"'>&nbsp;"+windGroupShown[i][2]+"</td>";
										tooltipText += "<td style='color:"+windGroupShown[i][1]+"'>"+item[windGroupShown[i][0]].toFixed(1)+" "+findHoverUnits(windGroupShown[i][5])+"</td>";
										tooltipText += "</tr>";
									}		
								}
								if (otherGroupShown.length>0) {
									for (var i=0; i<otherGroupShown.length; i++) {
										if (other===true) {
											tooltipText += "<tr style='border-top: 1pt solid #D1D1FF;'>";
											tooltipText += "<td>&nbsp;<img src='"+settings.basePath+"sites/all/modules/custom/ccis/images/d3/symbol_legende_other.png' width='19' height='16'></td>";
										} else {
											tooltipText += "<tr>";
											tooltipText += "<td></td>";
										}
										tooltipText += "<td style='color:"+otherGroupShown[i][1]+"'>&nbsp;"+otherGroupShown[i][2]+"</td>";
										tooltipText += "<td style='color:"+otherGroupShown[i][1]+"'>"+item[otherGroupShown[i][0]].toFixed(1)+" "+findHoverUnits(otherGroupShown[i][5])+"</td>";
										tooltipText += "</tr>";
									}		
								}
								
							tooltipText += "</table></b>";
	
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
						for (var i=0; i<temperatureGroupShown.length; i++) {
							printKeys += "<br><div style='height:0px; width:10px; border-top: 5px solid "+temperatureGroupShown[i][1]+"; border-bottom: 5px solid "+temperatureGroupShown[i][1]+"; outline:solid 1px black; float:left; margin-left:5px; margin-right:5px; margin-top:3px;'></div><span style='font-size:14px'>"+temperatureGroupShown[i][3]+"</span>";
						}
						for (var i=0; i<warmExtremesGroupShown.length; i++) {
							printKeys += "<br><div style='height:0px; width:10px; border-top: 5px solid "+warmExtremesGroupShown[i][1]+"; border-bottom: 5px solid "+warmExtremesGroupShown[i][1]+"; outline:solid 1px black; float:left; margin-left:5px; margin-right:5px; margin-top:3px;'></div><span style='font-size:14px'>"+warmExtremesGroupShown[i][3]+"</span>";
						}
						for (var i=0; i<coldExtremesGroupShown.length; i++) {
							printKeys += "<br><div style='height:0px; width:10px; border-top: 5px solid "+coldExtremesGroupShown[i][1]+"; border-bottom: 5px solid "+coldExtremesGroupShown[i][1]+"; outline:solid 1px black; float:left; margin-left:5px; margin-right:5px; margin-top:3px;'></div><span style='font-size:14px'>"+coldExtremesGroupShown[i][3]+"</span>";
						}
						for (var i=0; i<precipitationGroupShown.length; i++) {
							printKeys += "<br><div style='height:0px; width:10px; border-top: 5px solid "+precipitationGroupShown[i][1]+"; border-bottom: 5px solid "+precipitationGroupShown[i][1]+"; outline:solid 1px black; float:left; margin-left:5px; margin-right:5px; margin-top:3px;'></div><span style='font-size:14px'>"+precipitationGroupShown[i][3]+"</span>";
						}
						for (var i=0; i<extremePrecipitationGroupShown.length; i++) {
							printKeys += "<br><div style='height:0px; width:10px; border-top: 5px solid "+extremePrecipitationGroupShown[i][1]+"; border-bottom: 5px solid "+extremePrecipitationGroupShown[i][1]+"; outline:solid 1px black; float:left; margin-left:5px; margin-right:5px; margin-top:3px;'></div><span style='font-size:14px'>"+extremePrecipitationGroupShown[i][3]+"</span>";
						}
						for (var i=0; i<windGroupShown.length; i++) {
							printKeys += "<br><div style='height:0px; width:10px; border-top: 5px solid "+windGroupShown[i][1]+"; border-bottom: 5px solid "+windGroupShown[i][1]+"; outline:solid 1px black; float:left; margin-left:5px; margin-right:5px; margin-top:3px;'></div><span style='font-size:14px'>"+windGroupShown[i][3]+"</span>";
						}
						for (var i=0; i<otherGroupShown.length; i++) {
							printKeys += "<br><div style='height:0px; width:10px; border-top: 5px solid "+otherGroupShown[i][1]+"; border-bottom: 5px solid "+otherGroupShown[i][1]+"; outline:solid 1px black; float:left; margin-left:5px; margin-right:5px; margin-top:3px;'></div><span style='font-size:14px'>"+otherGroupShown[i][3]+"</span>";
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
	
	// Hide Divs for D3
	$("#homebox-block-ccis_d3").hide();
	$("#homebox-block-ccis_d3_2").hide();
	
	// Select diagram
	if (settings.ccis.stations[0]) {
		if (settings.ccis.stations[0].selector === "ccis-weather-d3-block-1" && settings.ccis.stations[0].station_name.length>0) {
			$("#homebox-block-ccis_d3").show();
			diagram1();
		}
	}
	if (settings.ccis.stations[1]) {
		if (settings.ccis.stations[1].selector === "ccis-weather-d3-block-2" && settings.ccis.stations[1].station_name.length>0) {
			$("#homebox-block-ccis_d3_2").show();
			diagram2();
		}
	}
		
  // CUSTOM CODING END
  }
}
})(jQuery);