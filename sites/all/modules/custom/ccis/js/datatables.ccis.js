(function($) {
Drupal.behaviors.ccis_datatables = {
  attach: function(d_context, settings) {
    var datatable = this;
    datatable.homebox = $("#homebox-block-ccis_datatables");
    datatable.container = $('#ccis-weather-datatable-block');
    datatable.settings = settings;
    datatable.legends = settings.ccis_dt.legends;
    var $stations = settings.ccis_dt.stations;
    if ($stations.length > 0) {
      var $refresh = datatable.container.data('refresh');
      if ($refresh != 1) {
        return;
      }
      datatable.container.html("");
      $($stations).each(function(index, station) {
        datatable.current_station = station;
        datatable.fetchData(index);
      });
      datatable.container.data('refresh', 0);
      if (datatable.container.html() == "") {
        // Hide it by default.
        datatable.homebox.hide();
      }
    }
  },
  fetchData: function(index) {
    var datatable = this;
    $.getJSON(datatable.current_station.path, function(json) {
      if (json['aaData'].length < 1) {
        return;
      }
      var $cols = [];
      $(json['fields']).each(function(key, value) {
        $cols[key] = {"sTitle" : datatable.legends['field_' + value]};
      });
      datatable.data = {
        "aaData": json['aaData'],
        "aoColumns": $cols
      };
      datatable.drawTable(index);
    });
  },
  drawTable : function(index) {
    var _datatable = this;
    _datatable.container.append("<div id='ccis-weather-datatable-content-" + index + "'></div>");
    var $div = $('#ccis-weather-datatable-content-' + index);
    $div.append("<div class='ccis-datatable-station-number'>" + (index + 1)  +"</div>");
    $div.append(table(index));
    var _tableId = '#ccis-datatable-' + index;
    var options = {
      "sScrollY": "300px",
      "sScrollX": "100%",
      "bScrollCollapse": true,
      "bPaginate": false,
    };
    options = $.extend(true, _datatable.data, options);
    var oTable = $(_tableId).dataTable(options);
    oTable.fnSort( [ [1,'asc'] ] );
    _datatable.homebox.show();
  }
}

function table(id) {
  return '<table cellpadding="0" class="display" cellspacing="0" border="0" id="ccis-datatable-' + id + '"></table>';
}
})(jQuery);