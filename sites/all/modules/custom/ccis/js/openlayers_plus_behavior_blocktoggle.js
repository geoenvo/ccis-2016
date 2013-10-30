/**
 * Implementation of Drupal behavior.
 */
//Drupal.behaviors.openlayers_plus_behavior_blocktoggle = function(context) {
//Drupal.OpenLayersPlusBlocktoggle.attach(context);
//};

(function($) {
  /**
   * Implementation of Drupal behavior.
   */
//Drupal.behaviors.openlayers_plus_behavior_blocktoggle = function(context) {
  Drupal.openlayers.addBehavior('openlayers_plus_behavior_blocktoggle', function (data, options) {
    Drupal.OpenLayersPlusBlocktoggle.attach(data, options);
  });

  /**
   * Blocktoggle is **NOT** an OpenLayers control.
   */
  Drupal.OpenLayersPlusBlocktoggle = {};
  Drupal.OpenLayersPlusBlocktoggle.layerStates = [];

  /**
   * Initializes the blocktoggle and attaches to DOM elements.
   */
  Drupal.OpenLayersPlusBlocktoggle.attach = function(data, options) {
    /**
     * Initializes the blocktoggle and attaches to DOM elements.
     */
//  Drupal.OpenLayersPlusBlocktoggle.attach = function(context) {
//  var data = $(context).data('openlayers');

    if (data && data.map.behaviors.openlayers_plus_behavior_blocktoggle) {

      this.map = data.openlayers;
      this.layer_a = this.map.getLayersBy('drupalID', options.a)[0];
      this.layer_b = this.map.getLayersBy('drupalID', options.b)[0];
      
      // If behavior has requested display inside of map, respect it.
      if (options.enabled == true) {
        var block = $(options.block);

        block.addClass(options.position);
        $(data.openlayers.viewPortDiv).append(block);
      }

      // Don't propagate click events to the map
      // this doesn't catch events that are below the layer list
      $('div.block-openlayers_plus-blocktoggle *').mousedown(function(evt) {
        OpenLayers.Event.stop(evt);
      });

      $('.openlayers-blocktoggle-a').text(
          data.map.behaviors.openlayers_plus_behavior_blocktoggle.a_label
      );

      $('.openlayers-blocktoggle-b').text( 
          data.map.behaviors.openlayers_plus_behavior_blocktoggle.b_label
      );

      var sat = false;
      
      testjq = $('.openlayers-blocktoggle-a');

        $('.openlayers-blocktoggle-a').toggle(
    		  function() {
    			  
    			  if (sat == false) {
    				  data.openlayers.setBaseLayer(map.layers[0]);		  
    				  $('.openlayers-blocktoggle-a').css('background-image', 'url(sites/all/modules/custom/ccis/css/ol/img/satellite_active.png)');
    				  $('.openlayers-blocktoggle-b').css('background-image', 'url(sites/all/modules/custom/ccis/css/ol/img/map.png)');
    				  sat = true; 
    			  }    			 
    		  },
    		  
    		  function() { 
    			  
	   			  if (sat == false) {
	   				  data.openlayers.setBaseLayer(map.layers[0]);
   				      $('.openlayers-blocktoggle-a').css('background-image', 'url(sites/all/modules/custom/ccis/css/ol/img/satellite_active.png)');
				      $('.openlayers-blocktoggle-b').css('background-image', 'url(sites/all/modules/custom/ccis/css/ol/img/map.png)');
	   				  sat = true;
	 			  }
     		  }
      );		  
      
      
      $('.openlayers-blocktoggle-b').toggle(
    		  function() {

    			 if (sat == true) {
    				 data.openlayers.setBaseLayer(map.layers[1]);
   				     $('.openlayers-blocktoggle-a').css('background-image', 'url(sites/all/modules/custom/ccis/css/ol/img/satellite.png)');
				     $('.openlayers-blocktoggle-b').css('background-image', 'url(sites/all/modules/custom/ccis/css/ol/img/map_active.png)');
    				 sat = false;
    			 }    			 
    		  },	
    		  
    		  function() {
     			 
    			 if (sat == true) {
    				 data.openlayers.setBaseLayer(map.layers[1]);
    				 $('.openlayers-blocktoggle-a').css('background-image', 'url(sites/all/modules/custom/ccis/css/ol/img/satellite.png)');
    				 $('.openlayers-blocktoggle-b').css('background-image', 'url(sites/all/modules/custom/ccis/css/ol/img/map_active.png)');
    				 sat = false;
    			 }
     		  }	 
      );	

      data.openlayers.events.on({
        "addlayer": this.redraw,
        "changelayer": this.redraw,
        "removelayer": this.redraw,
        scope: this
      });
    }
  };

  

  /**
   * Checks if the layer state has changed since the last redraw() call.
   *
   * Returns:
   * {Boolean} The layer state changed since the last redraw() call.
   */
  Drupal.OpenLayersPlusBlocktoggle.needsRedraw = function() {
    return (
        (this.a_vis == $(this).find('.openlayers-blocktoggle-a').hasClass('activated')) ? 1 : 0 ^
              (this.b_vis == $(this).find('.openlayers-blocktoggle-b').hasClass('activated')) ? 1 : 0);
  };

  /**
   * Redraws the blocktoggle to reflect the current state of layers.
   */
  Drupal.OpenLayersPlusBlocktoggle.redraw = function() {
    if (this.needsRedraw()) {
      this.a_vis = this.layer_a.visibility;
      this.b_vis = this.layer_b.visibility;
      // Clear out previous layers
      // Save state -- for checking layer if the map state changed.
      // We save this before redrawing, because in the process of redrawing
      // we will trigger more visibility changes, and we want to not redraw
      // and enter an infinite loop.
      $('div.openlayers-blocktoggle').click();
    }
  };
})(jQuery);
