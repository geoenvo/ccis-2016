(function($) {
Drupal.behaviors.ccis_base = {
  attach: function(d_context, settings) {
    var $list = $('#ccis-station-search-result', d_context);
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
    var $homeboxcontent = $(".portlet-content");
    if ($homeboxcontent.length < 1) {
      return;
    }
    $homeboxcontent.closest(".homebox-portlet").show();
    for (var i = 0; i < $homeboxcontent.length; i++) {
      var _this = $($homeboxcontent[i]);
      var id = _this.children().attr("id");
      if (id.indexOf("d3") > -1) {
        continue;
      }
      if (_this.children().html() == "") {
        _this.closest(".homebox-portlet").hide();
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