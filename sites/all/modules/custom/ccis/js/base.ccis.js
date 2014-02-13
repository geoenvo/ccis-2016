/*jslint sloppy: true, indent: 2 */
(function($) {

Drupal.ccis = Drupal.ccis || {'behaviors': {}};

Drupal.behaviors.ccis_base = {
  attach: function(context, settings) {
    this.fetchStationData(settings);
    this.searchResult();
    this.hidePortlets();
    this.addToolTipFieldsets();
    this.resetHomebox();
    this.clearForm(context);
  },
  clearForm: function(context) {
    var form = $('#ccis-block-filter-form #edit-clear', context);
    if (form.length < 1) {
      return;
    }
    form.click(function(e) {
      e.preventDefault();
      var elements = this.form.elements;
      $.each(elements, function(i, value) {
        var field_type = elements[i].type.toLowerCase();
        switch (field_type) {
          case "text":
          case "password":
          case "textarea":
            elements[i].value = "";
              break;
          case "radio":
          case "checkbox":
              if (elements[i].checked) {
                 elements[i].checked = false;
              }
              break;
          case "select-one":
          case "select-multi":
              elements[i].selectedIndex = 0;
              break;
          default:
              break;
        }
      });
    });
  },
  fetchStationData: function(settings) {
    var $body = $('body');
    if (typeof $body.data('dashboardrefresh') === 'undefined') {
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
    $body.data('dashboardrefresh', 0);
    if (typeof settings.ccis.stations !== 'undefined') {
      var data_found = false;
      $.each(settings.ccis.stations, function(index, station) {
        station.data = [];
        $.ajax({
          dataType: "json",
          url: station.path,
          type: 'GET',
          async: false,
          success: function(json, status) {
            if (json.length > 0) {
              station.data = json;
              data_found = true;
            }
          },
        });
      });
      $.each(Drupal.ccis.behaviors, function() {
        if (this.homebox.length > 0) {
          this.container.html("");
        }
        if (this.homebox.length > 0 && data_found) {
          this.homebox.show();
        }
        if ($.isFunction(this.attach) && data_found) {
          this.attach(settings.ccis.stations, settings.ccis.info, Drupal.settings);
        }
      });
      if (data_found) {
        var hb = $('#homebox-column-3');
        this.moveMap(hb);
        hb.parent().show();
      }
      else{
        // We need this delay to get the right height for the map.
        window.setTimeout(Drupal.behaviors.ccis_base.fallback, 400);
      }
    }
    else {
      this.fallback();
    }
  },
  fallback: function() {
    var hb = $('#homebox-column-2');
    var hbFrom = $('#homebox-column-3');
    Drupal.behaviors.ccis_base.moveMap(hb);
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
        var layer = mapdata.openlayers.getLayersByName("Placeholder for Geofield Formatter");
        if (layer.length > 0 && typeof layer[0] !== undefined) {
          layer[0].destroy();
        }
        mapdata.openlayers.updateSize();
        if (typeof Drupal.homebox.$columns !== 'undefined') {
          // We need this delay so that homebox get the recalcuted width/height
          // of the elements.
          window.setTimeout(Drupal.homebox.equalizeColumnsHeights, 400);
        }
      }
    });
  },
  resetHomebox: function(context) {
    var groups = $('.field-group-format-title, .horizontal-tab-button a');
    groups.click(function() {
      if (typeof Drupal.homebox.$columns != 'undefined') {
        // We need this delay so that homebox get the recalcuted width/height
        // of the elements.
        window.setTimeout(Drupal.homebox.equalizeColumnsHeights, 400);
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
  searchResult: function(context) {
    var $list = $('#ccis-station-search-result', context);
    var $radios = $list.find("[type=radio]");
    var checked, station_number, station_input, form;
    var inputs = [$('#edit-input1'), $('#edit-input2')];
    if ($list.find("[data-station=1]").filter(":checked").length !== 1) {
      $list.find("[data-station=2]").attr('disabled', true);
    }
    inputs[0].bind('keyup', function() {
      if (this.id === 'edit-input1' && this.value === '') {
        // Clear the hidden input 2. Which will be hidden by form states.
        inputs[1].val('');
      }
    });
    $radios.click( function(e) {
      var _this = $(this);
      station_number = _this.data('station');
      station_input = _this.data('station-input');
      form = inputs[station_number - 1]
        .trigger('keyup')
        .val(station_input)
        .closest('form');
      checked = $radios.filter(":checked");
      $list.find("[data-station=2]").attr('disabled', false);
      // Submit only the form when both stations are clicked.
      if (checked.length > 1) {
        form.find("[type=submit]").mousedown();
      }
    });
    // Provided by pager plugin. See ccis_page_alter().
    var wrap = $('#ccis-station-search-result tbody');
    wrap.once('jquerypager', function() {
      wrap.pager({
        perPage: 10,
        useHash: true,
      });
    });
    wrap.first().show();
    // set up click events to trigger the pagination plugins' behaviour
    $('.prev').click(function () {
        wrap.trigger('pager:prev');
        return false;
    });
    $('.next').click(function () {
      wrap.trigger('pager:next');
      return false;
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