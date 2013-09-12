(function($) {
Drupal.behaviors.ccis = {
  attach: function(d_context, settings) {
    if (settings.ccis && settings.ccis.stations) {
      //console.log(settings.ccis);
      $.each(settings.ccis.stations, function(i, station) {
        var selector = '#' + station.selector;
        // JSON-Format
        var path = station.path;
        // Coding d3.time.format("%d-%b-%y").parse;
        });
    }
  }
}
})(jQuery);