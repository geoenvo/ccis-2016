(function($) {
Drupal.behaviors.ccis_datatables = {
  attach: function(context, settings) {
    var datatable = this;
    datatable.homebox = $("#homebox-block-ccis_datatables");
    datatable.container = $('#ccis-weather-datatable-block');
    datatable.range = settings.ccis_dt.range;
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
    $.ajax({
      dataType: "json",
      url: datatable.current_station.path,
      type: 'GET',
      async: false,
      success: function(json, status) {
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
      },
    });
  },
  drawTable : function(index) {
    var _datatable = this;
    var dt_c = "<div id='ccis-weather-datatable-content-" + index + "'></div>";
    var $div = $(dt_c);
    $div.append("<div class='ccis-datatable-station-number'>" + (index + 1) + "</div>");
    $div.append("<div class='ccis-datatable-station-range'>" + Drupal.t("Data: ") + _datatable.range + "</div>");
    $div.append(table(index));
    _datatable.container.append($div);
    var _tableId = '#ccis-datatable-' + index;
    var aTargets = [0];
    for (var i = 5; i < _datatable.data.aoColumns.length; i++) {
      aTargets.push(i);
    }
    var options = {
      "sScrollY": "300px",
      "bScrollCollapse": true,
      "bPaginate": false,
      "sDom": 'RC<"clear">lfrtip',
      "aoColumnDefs": [{ "bVisible": false, "aTargets": aTargets }],
      "oColVis": {
        "aiExclude": [ 0 ],
        "bRestore": true,
        "sAlign": "right"
      },
      "oLanguage": {
        "sEmptyTable":     Drupal.t("No data available in table"),
        "sInfo":           Drupal.t("Showing _START_ to _END_ of _TOTAL_ entries"),
        "sInfoEmpty":      Drupal.t("Showing 0 to 0 of 0 entries"),
        "sInfoFiltered":   Drupal.t("(filtered from _MAX_ total entries)"),
        "sInfoPostFix":    "",
        "sInfoThousands":  ",",
        "sLengthMenu":     Drupal.t("Show _MENU_ entries"),
        "sLoadingRecords": Drupal.t("Loading..."),
        "sProcessing":     Drupal.t("Processing..."),
        "sSearch":         Drupal.t("Search:"),
        "sZeroRecords":    Drupal.t("No matching records found"),
        "oPaginate": {
            "sFirst":    Drupal.t("First"),
            "sLast":     Drupal.t("Last"),
            "sNext":     Drupal.t("Next"),
            "sPrevious": Drupal.t("Previous")
        },
        "oAria": {
            "sSortAscending":  Drupal.t(": activate to sort column ascending"),
            "sSortDescending": Drupal.t(": activate to sort column descending")
        }
      }
    };
    options = $.extend(true, _datatable.data, options);
    var oTable = $(_tableId).dataTable(options);
    oTable.fnSort( [ [1,'asc'] ] );
    _datatable.homebox.show();
    $('.ccis-datatable-title[title]').tipsy({gravity: 's'});
  }
}

function table(id) {
  return '<table class="display" id="ccis-datatable-' + id + '"></table>';
}
})(jQuery);