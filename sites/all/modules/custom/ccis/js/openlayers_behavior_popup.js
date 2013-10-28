/**
 * @file
 * JS Implementation of OpenLayers behavior.
 */

/**
 * Javascript Drupal Theming function for inside of Popups To override
 * 
 * @param feature
 *          OpenLayers feature object.
 * @return Formatted HTML.
 */

Drupal.theme.prototype.openlayersPopup = function(feature) {
  var output = '';

  if (feature.attributes.name) {
    output += '<div class="openlayers-popup openlayers-tooltip-name">'
        + feature.attributes.name + '</div>';
  }
  if (feature.attributes.description) {
    output += '<div class="openlayers-popup openlayers-tooltip-description">'
        + feature.attributes.description + '</div>';
  }

  return output;
};

// Make sure the namespace exists
Drupal.openlayers.popup = Drupal.openlayers.popup || {};

/**
 * OpenLayers Popup Behavior
 */
Drupal.openlayers.addBehavior('openlayers_behavior_popup',
    function (data, options) {
      map = data.openlayers;
      var layers = [];
      var selectedFeature;

      // For backwards compatiability, if layers is not
      // defined, then include all vector layers
      if (typeof options.layers == 'undefined' || options.layers.length == 0) {
        layers = map.getLayersByClass('OpenLayers.Layer.Vector');
      }
      else {
        for ( var i in options.layers) {
          var selectedLayer = map.getLayersBy('drupalID', options.layers[i]);
          if (typeof selectedLayer[0] != 'undefined') {
            layers.push(selectedLayer[0]);
          }
        }
      }

      // if only 1 layer exists, do not add as an array. Kind of a
      // hack, see https://drupal.org/node/1393460
      if (layers.length == 1) {
        layers = layers[0];
      }

      // Select control for hover / select popup behaviour
      var selectControl = new OpenLayers.Control.SelectFeature(layers,
          {
            callbacks : {
              // On mouse-over:
              over : function (feature) {
                Drupal.openlayers.current_feature = feature;
                var html = '';
                // Look for the number of features in cluster:
                // If the cluster consists of more than three features,
                // generate the number of stations and a hint as content of a
                // hover
                // popup
                html = '<div class="popup_list">';
                if (feature.cluster.length > 3) {
                  html += '<p class="popupName">' + feature.cluster.length
                      + ' ' + Drupal.t('Stations') + '</p>'
                      + '<p class="popupAttr">'
                      + Drupal.t('Click to zoom in') + '</p>';
                }
                else if (feature.cluster.length <= 3 && feature.cluster.length > 1) {
                  for ( var i = 0; i < feature.cluster.length; i++) {
                    html += '<p><a class="popupName" href="'
                        + Drupal.settings.basePath + 'dashboard?='
                        + feature.cluster[i].data.nid + '">'
                        + feature.cluster[i].attributes.title + '</a></p>';
                  }
                }
                else if (feature.cluster.length > 0) {
                  html = '<p class="popupName">'
                      + feature.cluster[0].attributes.title + '</p>';
                  var title = Drupal.t('Station code');
                  var attr = feature.cluster[0].attributes.field_stationcode;
                  if (feature.cluster[0].attributes.field_wmocode != null) {
                    title = Drupal.t('WMO code');
                    attr = feature.cluster[0].attributes.field_wmocode;
                  }
                  html += '<p class="popupAttr">' + title + ':' + attr + '</p>';
                }
                html += '</div>';
                // Generate the popup with the prepared content
                popup = new OpenLayers.Popup.FramedCloud('popup',
                    feature.geometry.getBounds().getCenterLonLat(), null, html,
                    null, true, function(evt) {
                      while (map.popups.length) {
                        map.popups[0].destroy();
                      }
                    });

                // Assign popup to feature and map.
                popup.panMapIfOutOfView = options.panMapIfOutOfView;
                popup.keepInMap = options.keepInMap;
                selectedFeature = feature;
                feature.popup = popup;
                Drupal.attachBehaviors();
                map.addPopup(popup);
              }, // over
              // On mouse-out:
              out : function (feature) {
                Drupal.openlayers.current_feature = feature;
                // If the cluster consists of 2 or 3 features,
                // close the hover popup with a timeout
                if (feature.cluster.length <= 3 && feature.cluster.length > 1) {
                  setTimeout("map.removePopup(Drupal.openlayers.current_feature.popup)", 1000);
                }
                // Else close the popup immediately
                else {
                  map.removePopup(feature.popup);
                }
              }
            },
            // On feature select:
            eventListeners : {
              featurehighlighted : function(data) {
                var feature = data.feature;
                Drupal.openlayers.current_feature = feature;
                // Close existing popups
                map.removePopup(feature.popup);
                // Look for the number of features in cluster:

                // If the cluster consists of more than 3 features,
                // zoom in to see the individual features
                if (feature.cluster.length > 3) {
                  var cluster_bounds = new OpenLayers.Bounds();
                  feature.cluster.forEach(function(_feature) {
                    cluster_bounds.extend(_feature.geometry);
                  })
                  map.zoomToExtent(cluster_bounds);
                }
                // If the cluster consists of 1 feature,
                // call dashboard for the selected station
                else if (feature.cluster.length == 1) {
                  // Call dashboard with the NID of the selected feature as station 1
                  window.location.href = "dashboard?nid="
                      + feature.cluster[0].data.nid;
                }
              },
              // On unselect close popup
              featureunhighlighted : function(feature) {
                map.removePopup(feature.popup);
              }
            }
          });

      // Add control to map and activate
      map.addControls([ selectControl ]);
      selectControl.activate();
      Drupal.openlayers.popup.popupSelect = selectControl;
});
