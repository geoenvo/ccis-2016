(function ($) {
/**
 * Implementation of Drupal behavior.
 */
  Drupal.OpenLayersPlusLegend = {};

  Drupal.behaviors.openlayers_plus_behavior_legend = {
          attach: function(context, settings) {
  context2 = context;			  
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
		if (layer.visibility != true) {
		}
		else {
        Drupal.OpenLayersPlusLegend.setLegend(layer);
		}
      }
    }
  }
  
  
}
};

count = 0;

Drupal.OpenLayersPlusLegend.setLegend = function(layer) {
  // The layer param may vary based on the context from which we are called.
  layer = layer.object ? layer.object : layer;

	// Check layer visibility, if true increase the counter, else decrease
	if (layer.visibility != true) {
		count = count - 1;
	}
	
	else {
		count = count + 1;
	}	

	// If at least one layer is visible, show legend
	if (count > 0) {
		$('div.openlayers-legends').css("display", "block");	
			
		var name = layer.drupalID;
		var map = $(layer.map.div);
		var data = map.data('openlayers');
		var legend = data.map.behaviors.openlayers_plus_behavior_legend[name];
		var legends = $('div.openlayers-legends', map);

		// Check the according layer
		// The grid layer need custom style, all others will be rendered with default style
		
		if (name== 'grid_precipitation') {

			if (layer.visibility && $('#openlayers-legend-' + name, legends).size() === 0) {
				legend = '<div id="openlayers-legend-grid_precipitation" class="legend legend-count-1 clear-block"><div class="legend-item clear-block"><p style="margin-left:22px; margin-top: 0px; margin-bottom: 0px; padding:0px;">Precipitation Grid</p><span class="swatch" style="border: 1px solid rgba(0, 0, 0, 1); background: rgba(183, 237, 240, 1)"></span> < 500mm<br><span class="swatch" style="border: 1px solid rgba(0, 0, 0, 1); background: rgba(117, 181, 232, 1)"></span>500 - 600mm<br><span class="swatch" style="border: 1px solid rgba(0, 0, 0, 1); background: rgba(33, 132, 224, 1)"></span>600 - 700mm<br><span class="swatch" style="border: 1px solid rgba(0, 0, 0, 1); background: rgba(31, 70, 185, 1)"></span>700 - 900mm<br><span class="swatch" style="border: 1px solid rgba(0, 0, 0, 1); background: rgba(11, 11, 146, 1)"></span> > 900mm</div></div>';
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
	}
		
	// If no layer is visible, hide the legend
	else {		
		$('div.openlayers-legends').css("display", "none");
		$('div.openlayers-legends').html("");		
	}
	
};
})(jQuery);
