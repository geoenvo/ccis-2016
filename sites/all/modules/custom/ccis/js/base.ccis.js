(function($) {
Drupal.behaviors.ccis_base = {
  attach: function(context, settings) {
    this.searchResultClicker();
    this.hidePortlets();
    this.addToolTipFieldsets();
    this.resetHomebox();
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