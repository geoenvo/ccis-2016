(function($) {
Drupal.behaviors.ccis_datatable = {
  attach: function(d_context, settings) {
  // CUSTOM CODING START
    var dashboard_ID = '#ccis_datatables';
    var csvDrupalBase = settings.basePath + 'weather';
    //var csvDrupalYear = csvDrupalBase + '/STATION/YYYY';
    var csvFilesystemBase = settings.basePath + 'sites/default/files/csv';
    //var csvFilesystemYear = csvFilesystemBase + '/FILENAME.csv';
    // Coding $(dashboard_ID).dataTable ...
  // CUSTOM CODING END
  }
}
})(jQuery);