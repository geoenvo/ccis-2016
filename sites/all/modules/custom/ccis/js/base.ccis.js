(function($) {
Drupal.ccis = Drupal.ccis || {'behaviors': {}};

Drupal.behaviors.ccis_base = {
  attach: function(context, settings) {
    this.fetchStationData(settings);
    this.searchResultClicker();
    this.hidePortlets();
    this.addToolTipFieldsets();
    this.resetHomebox();
  },
  fetchStationData: function (settings) {
    var $body = $('body');
    if (typeof $body.data('dashboardrefresh') == 'undefined') {
      $body.data('dashboardrefresh', 1);
    }
    if ($body.data('dashboardrefresh') != 1) {
      return null;
    }
    $.each(Drupal.ccis.behaviors, function() {
      if ($.isFunction(this.init)) {
        this.init();
      }
    });
    if (typeof settings.ccis.stations != 'undefined') {
      $body.data('dashboardrefresh', 0);
      $.each(settings.ccis.stations, function(index, station) {
        station.data = {};
        $.ajax({
          dataType: "json",
          url: station.path,
          type: 'GET',
          async: false,
          success: function(json, status) {
            if (json.length > 0) {
              station.data = json;
            }
          },
        });
      });
      $.each(Drupal.ccis.behaviors, function() {
        if (this.homebox.length > 0)
          this.container.html("");
        if (this.homebox.length > 0)
          this.homebox.show();
        
        if ($.isFunction(this.attach)) {
          this.attach(settings.ccis.stations, settings.ccis.info, Drupal.settings);
        }
      });
      var hb = $('#homebox-column-3');
      this.moveMap(hb);
      hb.parent().show();
    }
    else {
      var hb = $('#homebox-column-2');
      var hbFrom = $('#homebox-column-3');
      this.moveMap(hb);
      hbFrom.data('move', 0).parent().hide();
      $.each(Drupal.ccis.behaviors, function() {
        if (this.homebox.length > 0)
          this.homebox.hide();
        if (this.container.length > 0)
          this.container.html("");
        if ($.isFunction(this.hide)) {
          this.hide();
        }
      });
    }
  },
  moveMap: function(hb) {
    var ids = Object.keys(Drupal.settings.openlayers.maps);
    $.each(ids, function(index, value) {
      var map = $('#' + value);
      if (map.length > 0) {
        var mapblock = $('#homebox-block-ccis_stationmap');
        hb.append(mapblock);
        map.parent().width(hb.width()).height(hb.height());
        var mapdata = map.data('openlayers');
        map.width(hb.width()).height(hb.height());
        mapdata.openlayers.updateSize();
      }
    });
    
  },
  resetHomebox: function(context) {
    var groups = $('.field-group-format-title, .horizontal-tab-button a');
    groups.click(function() {
      if (typeof Drupal.homebox.$columns != 'undefined') {
       Drupal.homebox.equalizeColumnsHeights();
      }
    });
  },
  addToolTipFieldsets: function() {
    var ankers = $('body.page-dashboard .horizontal-tab-button > a');
    $.each(ankers, function() {
      var a = $(this);
      a.attr('title', a.find('strong').text());
    });
    ankers.tipsy({gravity: 's'});
  },
  searchResultClicker: function(context) {
    var $list = $('#ccis-station-search-result', context);
    var $radios = $list.find("[type=radio]");
    var checked, station_number, station_input, form;
    $radios.click( function(e) {
      var _this = $(this);
      station_number = _this.data('station');
      station_input = _this.data('station-input');
      form = $('#edit-input' + station_number)
        .val(station_input)
        .closest('form');
      checked = $radios.filter(":checked");
      // Submit only the form when both stations are clicked.
      if (checked.length > 1) {
        form.find("[type=submit]").mousedown();
      }
    });
  },
  hidePortlets: function() {
    var $homeboxcontent = $(".portlet-content");
    if ($homeboxcontent.length > 0) {
      for (var i = 0; i < $homeboxcontent.length; i++) {
        var _this = $($homeboxcontent[i]);
        var child = _this.children();
        if (child.data("hide-portlet") == "1") {
          _this.closest(".homebox-portlet").hide();
        }
        else if (child.data("hide-portlet") == "0") {
          _this.closest(".homebox-portlet").show();
        }
      }
    }
  }
}
Drupal.jsAC.prototype.select = function (node) {
  this.input.value = $(node).data('autocompleteValue');
  if (jQuery(this.input).hasClass('form-autocomplete-mousedown')) {
    var form = $(this.input.form);
    form.find("[type=submit]").mousedown();
  }
};
})(jQuery);