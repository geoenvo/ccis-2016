/**
 * @file
 * JS Implementation of OpenLayers behavior.
 */

/**
 * Javascript Drupal Theming function for inside of Popups
 *
 * To override
 *
 * @param feature
 *  OpenLayers feature object.
 * @return
 *  Formatted HTML.
 */


Drupal.theme.prototype.openlayersPopup = function(feature) {
  var output = '';

  if (feature.attributes.name) {
    output += '<div class="openlayers-popup openlayers-tooltip-name">' + feature.attributes.name + '</div>';
  }
  if (feature.attributes.description) {
    output += '<div class="openlayers-popup openlayers-tooltip-description">' + feature.attributes.description + '</div>';
  }

  return output;
};

// Make sure the namespace exists
Drupal.openlayers.popup = Drupal.openlayers.popup || {};

/**
 * OpenLayers Popup Behavior
 */
Drupal.openlayers.addBehavior('openlayers_behavior_popup', function (data, options) {
	//$(function(){
	//$("head").append("<script type='text/javascript' src='"+settings.basePath+"sites/all/modules/custom/ccis/js/jquery-1.10.2.js'></script>");
	//});
  map = data.openlayers;
  var layers = [];
  var selectedFeature;

  // For backwards compatiability, if layers is not
  // defined, then include all vector layers
  if (typeof options.layers == 'undefined' || options.layers.length == 0) {
    layers = map.getLayersByClass('OpenLayers.Layer.Vector');
  }
  else {
    for (var i in options.layers) {
      var selectedLayer = map.getLayersBy('drupalID', options.layers[i]);
      if (typeof selectedLayer[0] != 'undefined') {
        layers.push(selectedLayer[0]);
      }
    }
  }

  // if only 1 layer exists, do not add as an array.  Kind of a
  // hack, see https://drupal.org/node/1393460
  if (layers.length == 1) {
    layers = layers[0];
  }

  
  // Select control for hover / select popup behaviour
  var selectControl = new OpenLayers.Control.SelectFeature(layers, {
      
      callbacks: {
	  	  // On mouse-over:
          over: function(feat) {
              
      	    feature = feat;
      	    
      	    // Look for the number of features in cluster:
      	    
      	    // If the cluster consists of more than three features, 
      	    // generate the number of stations and a hint as content of a hover popup
      	    if (feature.cluster.length > 3) {
      	    	
      	    	var html = '<p class="popupName">' +
      	    	feature.cluster.length + ' Stations</p>' +
      	    	'<p class="popup_wmo">Click to zoom in</p>';
      	    }

      	    // If the cluster consists of 2 or 3 features,
      	    // generate the names of the stations as links as content of a hover popup
      	    else if (feature.cluster.length <= 3 && feature.cluster.length > 1) {
      	    	
      	    	var html = new String();
      	    	
      	    	if (feature.cluster.length == 3) {
      	    		
    			    // Get NID of the selected features and call dashboard with the NID of the selected features as station 1
    			    posNid1 = feature.cluster[0].attributes.name.indexOf('"', 29);  
    			    nid1 = feature.cluster[0].attributes.name.substring(29, posNid1);    
    			    posNid2 = feature.cluster[1].attributes.name.indexOf('"', 29);  
    			    nid2 = feature.cluster[1].attributes.name.substring(29, posNid2);
    			    posNid3 = feature.cluster[2].attributes.name.indexOf('"', 29);  
    			    nid3 = feature.cluster[2].attributes.name.substring(29, posNid3);
      	    		
      	    		html = '<p class="popup_list"><a class="popupName" href=dashboard?nid="' + nid1 + '">' + 
      	    		feature.cluster[0].attributes.title + '</a></p>' +
      	    		'<p class="popup_list"><a class="popupName" href=dashboard?nid="' + nid2 + '">' + 
      	    		feature.cluster[1].attributes.title + '</a></p>' +
      	    		'<p class="popup_list"><a class="popupName" href=dashboard?nid="' + nid3 + '">' + 
      	    		feature.cluster[2].attributes.title + '</a></p>'; 
      	    	}
      	    	
      	    	else {
      	    		
    			    // Get NID of the selected features and call dashboard with the NID of the selected features as station 1
    			    posNid1 = feature.cluster[0].attributes.name.indexOf('"', 29);  
    			    nid1 = feature.cluster[0].attributes.name.substring(29, posNid1);    
    			    posNid2 = feature.cluster[1].attributes.name.indexOf('"', 29);  
    			    nid2 = feature.cluster[1].attributes.name.substring(29, posNid2);
      	    		
      	    		html = '<p class="popup_list"><a class="popupName" href=dashboard?nid="' + nid1 + '">' + 
      	    		feature.cluster[0].attributes.title + '</a></p>' +
      	    		'<p class="popup_list"><a class="popupName" href=dashboard?nid="' + nid2 + '">' + 
      	    		feature.cluster[1].attributes.title + '</a></p>'; 	    		
      	    	}
      	    }      	    

      	    // If the cluster consists of 1 feature,
      	    // generate the names of the stations and the wmo / national code as content of a hover popup
      	    else if (feature.cluster.length == 1) {
      	    	
      	    	if (feature.cluster[0].attributes.field_wmocode != null){
      	    	     	    
    	    	    var html = '<p class="popupName">' +
    	    	    feature.cluster[0].attributes.title + '</p>' +
    	            '<p class="popup_wmo">WMO-Code: ' + 
    	            feature.cluster[0].attributes.field_wmocode + '</p>';   
      	    	}
      	    	
      	    	else {
      	    	
		    	    var html = '<p class="popupName">' +
		    	    feature.cluster[0].attributes.title + '</p>' +
		            '<p class="popup_wmo">Station-Code: ' + 
		            feature.cluster[0].attributes.field_stationcode + '</p>';       	    		      	    		
      	    	}
      	    }
      	    
      	  /*   	popup = new OpenLayers.Popup.Popover(
			          'popup',
			          feature.geometry.getBounds().getCenterLonLat(),
			          "dsdsds",
			          "hghh",
			          function(evt) {
			            while( map.popups.length ) {
			              map.popups[0].destroy();
			              }
			          }
			        );  */

      	    
    	    //Generate the popup with the prepared content
    	    popup = new OpenLayers.Popup.FramedCloud(
			          'popup',
			          feature.geometry.getBounds().getCenterLonLat(),
			          null,
			          
			          html,

			          null,
			          true,
  			          function(evt) {
	  			            while( map.popups.length ) {
	  			              map.popups[0].destroy();
	  			              }
	  			          }
			        ); 
    	    		
			      	  //popup.calculateRelativePosition = function () {
				      //	    return 'tr';
				      //	}
    	    
			        // Assign popup to feature and map.
			        popup.panMapIfOutOfView = options.panMapIfOutOfView;
			        popup.keepInMap = options.keepInMap;
			        selectedFeature = feature;       
			        feature.popup = popup;
			        Drupal.attachBehaviors();
			        map.addPopup(popup); 
              
              
          },
          
          //On mouse-out:
          out: function(feat) {
            
        	feature = feat;  
        	// If the cluster consists of 2 or 3 features,
        	// close the hover popup with a timeout
      	    if (feature.cluster.length <= 3 && feature.cluster.length > 1) {
		            setTimeout('map.removePopup(feature.popup)',1000);
    	    }
    	    
      	    // Else close the popup immediately
    	    else {
    	    	map.removePopup(feature.popup);	        	    	
    	    	
    	    }
        	  
          }
      },
      
      // On feature select:
      eventListeners: {
          featurehighlighted: function(feat) {
    	   
      	    feature = feat;
      	    //Close existing popups
      	    map.removePopup(feat.feature.popup);
      	    
      	    // Look for the number of features in cluster:
      	    
      	    // If the cluster consists of more than 3 features,
      	    // zoom in to see the individual features
      	    if (feat.feature.cluster.length > 3) {
      	    	
      	    	var cluster_bounds = new OpenLayers.Bounds();
      	    	feat.feature.cluster.forEach(function(feature){
      	    	    cluster_bounds.extend(feature.geometry);
      	    	})
      	    	map.zoomToExtent(cluster_bounds);
      	    }
      	    
      	    // If the cluster consists of 1 feature,
      	    // call dashboard for the selected station    	    
      	    else if (feat.feature.cluster.length == 1) {     	    
    	  
			    // Get NID of the selected feature
			    posNid = feat.feature.cluster[0].attributes.name.indexOf('"', 29);  
			    nid = feat.feature.cluster[0].attributes.name.substring(29, posNid);
			
			    // Call dashboard with the NID of the selected feature as station 1
			    window.location.href="dashboard?nid=" + nid;
      	    }
      	    
          },
          // On unselect close popup
          featureunhighlighted: function(feat) {
        	  map.removePopup(feat.feature.popup);
          }
      }    
  });    
  
  // Add control to map and activate
  map.addControls([selectControl]);
  selectControl.activate();
  Drupal.openlayers.popup.popupSelect = selectControl;

});
