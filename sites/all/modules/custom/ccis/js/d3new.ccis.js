(function ($) {
  Drupal.ccis.behaviors.d3 = {
    init : function () {
      var D3 = this;
      D3.homebox = $("#homebox-block-ccis_d3, #homebox-block-ccis_d3_2");
      // Groups of parameters available including the colors, the legend
      // keywords, the legend hover names, the icons and the units
      // Position 0: Parameter
      // Position 1: Color
      // Position 2: Legend Keyword
      // Position 3: Legend Hover Name
      // Position 4: Icon (in case we do not want to use the built-in svg icon)
      // Position 5: Units
      D3.temperatureGroup = [
          [ "tx", "#FF0000", "TX", "Daily maximum temperature (&#8451;)",
              "icon.png", "celsius" ],
          [ "tn", "#FCB205", "TN", "Daily minimum temperature (&#8451;)",
              "icon.png", "celsius" ],
          [ "tg", "#FF8000", "TG", "Daily mean temperature (&#8451;)",
              "icon.png", "celsius" ],
          [ "dtr", "#FF8400", "DTR", "Daily temperature range (&#8451;)",
              "icon.png", "celsius" ] ];
      D3.warmExtremesGroup = [
          [ "su", "#FB6A4A", "SU", "Number of summer days (days)", "icon.png",
              "days" ],
          [ "tr", "#EF3B2C", "TR", "Number of tropical nights (days)",
              "icon.png", "days" ],
          [ "txx", "#99000D", "Txx", "Monthly maximum value of TX (&#8451;)",
              "icon.png", "celsius" ],
          [ "tnx", "#CB181D", "Tnx", "Monthly maximum value of TN (&#8451;)",
              "icon.png", "celsius" ],
          [ "tn90p", "#FC9272", "TN90p",
              "Percentage of days when TN > 90th percentile (%)", "icon.png",
              "percent" ],
          [ "tx90p", "#D4B9DA", "TX90p",
              "Percentage of days when TX > 90th percentile (%)", "icon.png",
              "percent" ],
          [ "wsdi", "#CC6699", "WSDI", "Warm speel duration index (days)",
              "icon.png", "days" ] ];
      D3.coldExtremesGroup = [
          [ "fd", "#5100FF", "FD", "Number of frost days (days)", "icon.png",
              "days" ],
          [ "id", "#7A3EFA", "ID", "Number of icing days (days)", "icon.png",
              "days" ],
          [ "txn", "#5E56F0", "Txn", "Monthly minimum value of TX (&#8451;)",
              "icon.png", "celsius" ],
          [ "tnn", "#5C72ED", "Tnn", "Monthly minimum value of TN (&#8451;)",
              "icon.png", "celsius" ],
          [ "tn10p", "#6B91E3", "TN10p",
              "Percentage of days when TN < 10th percentile (%)", "icon.png",
              "percent" ],
          [ "tx10p", "#6BA7E3", "TX10p",
              "Percentage of days when TX < 10th percentile (%)", "icon.png",
              "percent" ],
          [ "csdi", "#7FBED4", "CSDI", "Cold speel duration index (days)",
              "icon.png", "days" ] ];
      D3.precipitationGroup = [
          [ "rr", "#3B516C", "RR", "Daily precipitation amount (mm)",
              "symbol_legende_rr.png", "milimeter" ],
          [ "cwd", "#B87EDE", "CWD",
              "Maximum length of wet spell (days with RR = 1mm) (days)",
              "icon.png", "days" ],
          [ "prcptot", "#B897DB", "PRCPTOT",
              "Annual total precipitation in wet days (mm)", "icon.png",
              "milimeter" ] ];
      D3.extremePrecipitationGroup = [
          [ "rx1day", "#00FFB3", "Rx1day",
              "Monthly maximum 1-day precipitation (mm)", "icon.png",
              "milimeter" ],
          [ "rx5day", "#00FF77", "Rx5day",
              "Monthly maximum consecutive 5-day precipitation (mm)",
              "icon.png", "milimeter" ],
          [ "sdii", "#1BCF45", "SDII",
              "Simple pricipitation intensity index (mm)", "icon.png",
              "milimeter" ],
          [ "r10mm", "#15B33A", "R10mm",
              "Annual count of days when PRCP= 10mm (days)", "icon.png", "days" ],
          [ "r20mm", "#96C98D", "R20mm",
              "Annual count of days when PRCP= 20mm (days)", "icon.png", "days" ],
          [ "rnnmm", "#A3C482", "Rnnmm",
              "Annual count of days when PRCP= nnmm (days)", "icon.png", "days" ],
          [ "r95ptot", "#91A86A", "R95pTOT",
              "Annual total PRCP when RR > 95p (mm)", "icon.png", "milimeter" ],
          [ "r99ptot", "#8B9C6E", "R99pTOT",
              "Annual total PRCP when RR > 99p (mm)", "icon.png", "milimeter" ] ];
      D3.windGroup = [
          [ "fg", "#00BBC4", "FG", "Daily mean wind speed (m/s)", "icon.png",
              "meterPerSecond" ],
          [ "fx", "#8DC6C9", "FX", "Daily maximum wind gust (m/s)", "icon.png",
              "meterPerSecond" ],
          [ "dd", "#45ABB0", "DD", "Daily wind direction (degrees)",
              "icon.png", "degrees" ] ];
      D3.otherGroup = [
          [ "gsl", "#FF9900", "GSL", "Growing season length (days)",
              "icon.png", "days" ],
          [ "cc", "#00FF00", "CC", "Daily cloud cover (octas)", "icon.png",
              "octas" ],
          [ "hu", "#33CCFF", "HU", "Daily humidity (%)", "icon.png", "percent" ],
          [ "pp", "#009900", "PP", "Daily mean sea level pressure (hPa)",
              "icon.png", "pascal" ],
          [ "cdd", "#996600", "CDD",
              "Maximum length of dry spell with RR < 1mm (days)", "icon.png",
              "days" ],
          [ "sd", "#AD886F", "SD", "Daily snow depth (cm)", "icon.png",
              "centimeter" ],
          [ "ss", "#CCBC08", "SS", "Daily sunshine duration (hours)",
              "icon.png", "hours" ] ];

      // Array with the Units used for the diagram
      // Position 0: Keyword (the same name as at the parameter groups)
      // Position 1: Icon filename
      // Position 2: Axis label
      // Position 3: Tick format for the axis label
      // Position 4: Tooltip label
      D3.unitsArray = [
          [ "celsius", "symbol_legende_thermometer.png", "Celsius", ".1f",
              "&#8451;" ], [ "days", "", "days", ".0f", "days" ],
          [ "percent", "", "%", ".1f", "%" ],
          [ "milimeter", "symbol_legende_drop.png", "mm", ".1f", "mm" ],
          [ "pascal", "symbol_legende_pressure.png", "hPa", ".0f", "hPa" ],
          [ "meterPerSecond", "", "m/s", ".1f", "m/s" ],
          [ "degrees", "", "degrees", ".0f", "&#176;" ],
          [ "octas", "symbol_legende_octas.png", "octas", ".1f", "octas" ],
          [ "centimeter", "", "cm", ".1f", "cm" ],
          [ "hours", "", "hours", ".1f", "hours" ] ];
    },
    hide : function () {
      var D3 = this;
      D3.homebox.hide();
    },
    attach : function (stations, info, settings) {
      var D3 = this;
      D3.storage = {};
      $.each(stations, function () {
        D3.storage.current_station = this;
        D3.prepareData();
        D3.findMinMax();
      });
      console.log(D3.storage);
    },
    findMinMax : function () {
      var D3 = this;
      var minDate = d3.min(D3.storage.current_station.data, function(d) {
        return d.date
      });
      // Find the data date range
      if (typeof D3.storage.minDate == 'undefined') {
        D3.storage.minDate = minDate;
      }
      else{
        D3.storage.minDate = d3.min([D3.storage.minDate, minDate], function(d) {
          return d
        });
      }
      
      var maxDate = d3.max(D3.storage.current_station.data, function(d) {
        return d.date
      });
      // Find the data date range
      if (typeof D3.storage.maxDate == 'undefined') {
        D3.storage.maxDate = maxDate;
      }
      else{
        D3.storage.maxDate = d3.max([D3.storage.maxDate, maxDate], function(d) {
          return d
        });
      }
    },
    prepareData : function () {
      var D3 = this;
      D3.storage.current_station.data = D3.storage.current_station.data.map( function(row) {
        row.date = row.shortdate;
//        row.date = d3.time.format("%Y-%m-%d").parse(
//            row.date.slice(0, -12)); // Nur Datum
        return row;
      });
    }
  };// End of Drupal.ccis.behaviors.d3.
})(jQuery);