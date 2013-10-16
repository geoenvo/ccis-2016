(function($) {
Drupal.behaviors.ccis_search_terms = {
  attach: function(d_context, settings) {
    var list = $('#ccis-station-search-result');
    list.find("[type=radio]").click( function(e) {
      var _this = $(this);
      var station_number = _this.data('station');
      var station_input = _this.data('station-input');
      var form = $('#edit-input' + station_number)
        .val(station_input)
        .closest('form');
      console.log(form.find("[type=submit]"));
      form.find("[type=submit]").mousedown();
    });
  }
}
})(jQuery);