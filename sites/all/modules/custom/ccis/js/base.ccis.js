(function($) {
Drupal.behaviors.ccis_search_terms = {
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
  }
}
})(jQuery);