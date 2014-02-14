(function($) {
  jQuery.fn.entireHtml = function() {
    if(this.length == 1) {
      return this.clone().wrap('<div></div>').parent().html();
    }
    else {
      var html = '';
      $(this).each(function() {
        html+= $(this).entireHtml();
      });
      return html;
    }
  }
  Drupal.ccis.behaviors.datatables = {
      init : function() {
        var datatable = this;
        datatable.homebox = $("#homebox-block-ccis_datatables");
        datatable.container = $('#ccis-weather-datatable-block');
      },
      attach : function(stations, info, settings) {
        var datatable = this;
        datatable.info = info;
        $.each(stations, function() {
          datatable.current_station = this;
          datatable.prepareData();
        });
      },
      prepareData : function() {
        var datatable = this;
        datatable.data = {};
        datatable.data.aaData = datatable.current_station.data;
        datatable.current_station.fields = [];
        delete datatable.current_station.data;
        datatable.data.aaData = datatable.data.aaData.map(function(value) {
          if (typeof value.shortdate !== 'undefined') {
            value.date = value.shortdate;
            delete value.shortdate;
          }
          datatable.current_station.fields = Object.keys(value);
          return datatable.current_station.fields.map(function (key) {
            return value[key];
          });
        });
        datatable.data.aoColumns = [];
        if (datatable.current_station.fields.length > 0) {
          // We need todo this to get the right order.
          $.each(datatable.current_station.fields, function(key, value) {
            datatable.data.aoColumns.push({
              "sTitle" : datatable.info.legends['field_' + value]
            });
          });
        }
        else{
          $.each(datatable.info.legends, function(key, value) {
            datatable.data.aoColumns.push({
              "sTitle" : value
            });
          });
        }
        datatable.drawTable();
      },
      drawTable : function() {
        var _datatable = this;
        var dt_c = "<div id='ccis-weather-datatable-content-" + _datatable.current_station.nr + "'></div>";
        var $div = $(dt_c);
        $div.append("<div class='ccis-datatable-station-number'>" + _datatable.current_station.nr + "</div>");
        $div.append("<div class='ccis-datatable-station-range'>" + Drupal.t("Data: ") + _datatable.info.range + "</div>");
        if (_datatable.current_station.download) {
          $div.append(_datatable.current_station.download);
        }
        $div.append(table(_datatable.current_station.nr));
        _datatable.container.append($div);
        var aTargets = [];
        for ( var i = 5; i < _datatable.data.aoColumns.length; i++) {
          aTargets.push(i);
        }
        var options = {
            "sScrollY" : "300px",
            "sScrollX" : "100%",
            "bScrollCollapse" : true,
            "bPaginate" : false,
            "sDom" : 'RC<"clear">lfrtip<"clear">',
            "aoColumnDefs" : [ {
              "bVisible" : false,
              "aTargets" : aTargets
            } ],
            "oColVis" : {
              "bRestore" : true,
              "sAlign" : "right",
              "aiExclude": [0],
            },
            "fields" : _datatable.current_station.fields,
            "fnDrawCallback": function( oSettings ) {
              var dl_link = $(oSettings.nTableWrapper).prev().find('a');
              var filter = [];
              $.each(oSettings.aoColumns, function(i, v) {
                if (v.bVisible) {
                  filter.push("field_" + oSettings.oInit.fields[i]);
                }
              });
              dl_link.data('filter', filter.join());
              dl_link.once('filter-click', function() {
                $(this).click(function(e) {
                  var _this = $(this);
                  var href = _this.data('origin-href') + "&filter_fields=" + _this.data('filter');
                  _this.attr('href', href);
                });
              });
              _trigger_tipsy();
            },
            "oLanguage" : {
              "sEmptyTable" : Drupal.t("No data available in table"),
              "sInfo" : Drupal.t("Showing _START_ to _END_ of _TOTAL_ entries"),
              "sInfoEmpty" : Drupal.t("Showing 0 to 0 of 0 entries"),
              "sInfoFiltered" : Drupal.t("(filtered from _MAX_ total entries)"),
              "sInfoPostFix" : "",
              "sInfoThousands" : ",",
              "sLengthMenu" : Drupal.t("Show _MENU_ entries"),
              "sLoadingRecords" : Drupal.t("Loading..."),
              "sProcessing" : Drupal.t("Processing..."),
              "sSearch" : "",
              "sZeroRecords" : Drupal.t("No matching records found"),
              "oPaginate" : {
                "sFirst" : Drupal.t("First"),
                "sLast" : Drupal.t("Last"),
                "sNext" : Drupal.t("Next"),
                "sPrevious" : Drupal.t("Previous")
              },
              "oAria" : {
                "sSortAscending" : Drupal.t(": activate to sort column ascending"),
                "sSortDescending" : Drupal.t(": activate to sort column descending")
              }
            }
        };
        options = $.extend(true, _datatable.data, options);
        var tableid = '#ccis-datatable-' + _datatable.current_station.nr;
        $(tableid).dataTable(options);
        _trigger_tipsy();
      }
  };

  function _trigger_tipsy() {
    $('.ccis-datatable-title[title]').tipsy({
      "gravity" : "s"
    });
  }

  function table(id) {
    return '<table class="display" id="ccis-datatable-' + id + '"></table>';
  }
})(jQuery);