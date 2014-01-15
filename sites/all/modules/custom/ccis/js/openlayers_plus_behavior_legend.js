(function ($) {
/**
 * Implementation of Drupal behavior.
 */
  Drupal.OpenLayersPlusLegend = {};

  Drupal.behaviors.openlayers_plus_behavior_legend = {
          attach: function(context, settings) {
  var data = $(context).data('openlayers');
  if (data && data.map.behaviors.openlayers_plus_behavior_legend) {
    var layer, i;
    for (i in data.openlayers.layers) {
      layer = data.openlayers.layers[i];
      if (data.map.behaviors.openlayers_plus_behavior_legend[layer.drupalID]) {
        if (!$('div.openlayers-legends', context).size()) {
          $(context).append("<div class='openlayers-legends'></div>");
        }
        layer.events.register('visibilitychanged', layer, Drupal.OpenLayersPlusLegend.setLegend);

        // Trigger the setLegend() method at attach time. We don't know whether
        // our behavior is being called after the map has already been drawn.
        Drupal.OpenLayersPlusLegend.setLegend(layer);
      }
    }
  }
}
};

Drupal.OpenLayersPlusLegend.setLegend = function(layer) {
  // The layer param may vary based on the context from which we are called.
  layer = layer.object ? layer.object : layer;
  
  
  
  var name = layer.drupalID;
  var map = $(layer.map.div);
  var data = map.data('openlayers');
  var legend = data.map.behaviors.openlayers_plus_behavior_legend[name];
  var legends = $('div.openlayers-legends', map);
  
  
  if (name== 'grid_precipitation') {

	if (layer.visibility && $('#openlayers-legend-' + name, legends).size() === 0) {
		legend = '<div id="openlayers-legend-grid_precipitation" class="legend legend-count-1 clear-block"><div class="legend-item clear-block"><p style="margin-left:22px">Precipitation Grid</p><span class="swatch" style="border: 1px solid rgba(0, 0, 0, 1); background: rgba(183, 237, 240, 1)"></span> < 500mm<br><span class="swatch" style="border: 1px solid rgba(0, 0, 0, 1); background: rgba(117, 181, 232, 1)"></span>500 - 600mm<br><span class="swatch" style="border: 1px solid rgba(0, 0, 0, 1); background: rgba(33, 132, 224, 1)"></span>600 - 700mm<br><span class="swatch" style="border: 1px solid rgba(0, 0, 0, 1); background: rgba(31, 70, 185, 1)"></span>700 - 900mm<br><span class="swatch" style="border: 1px solid rgba(0, 0, 0, 1); background: rgba(11, 11, 146, 1)"></span> > 900mm</div></div>';
		legends.append(legend);
	}
	else if (!layer.visibility) {
		$('#openlayers-legend-' + name, legends).remove();
    }
  }
  
  else if (name== 'grid_temperature') {

	if (layer.visibility && $('#openlayers-legend-' + name, legends).size() === 0) {
		legend = '<div id="openlayers-legend-grid_temperature" class="legend legend-count-1 clear-block"><div class="legend-item clear-block"><span class="swatch" style="border: 1px solid rgba(237, 154, 3, 1); background: rgba(228, 202, 125, 1)"></span>Temperature Grid</div></div>';
		legends.append(legend);
	}
	else if (!layer.visibility) {
		$('#openlayers-legend-' + name, legends).remove();
    }
  }  

  else {
	  
	  if (layer.visibility && $('#openlayers-legend-' + name, legends).size() === 0) {
		legends.append(legend);
	  }
	  else if (!layer.visibility) {
		$('#openlayers-legend-' + name, legends).remove();
	  }
  }

  
};
})(jQuery);
