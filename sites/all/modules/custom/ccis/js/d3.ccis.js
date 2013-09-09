(function($) {
Drupal.behaviors.ccis = {
  attach: function(d_context, settings) {
  // CUSTOM CODING START
    var dashboard_ID = '#ccis_dashboard';
    var csvDrupalBase = settings.basePath + 'weather';
    //var csvDrupalYear = csvDrupalBase + '/STATION/YYYY';
    var csvFilesystemBase = settings.basePath + 'sites/default/files/csv';
    //var csvFilesystemYear = csvFilesystemBase + '/FILENAME.csv';
    // Coding d3.time.format("%d-%b-%y").parse; ...
  // CUSTOM CODING END
  }
}
})(jQuery);