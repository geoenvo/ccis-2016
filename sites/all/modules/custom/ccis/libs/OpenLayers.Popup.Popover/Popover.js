/* Copyright (c) 2013 by Jean-François VIAL <http://about.me/Jeff_>

Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

 1. Redistributions of source code must retain the above copyright notice, this
list of conditions and the following disclaimer.

 2. Redistributions in binary form must reproduce the above copyright notice,
this list of conditions and the following disclaimer in the documentation and/or
other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS
OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT
SHALL COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

/**
 * @requires OpenLayers/Popup/Framed.js
 * @requires OpenLayers/Util.js
 * @requires OpenLayers/BaseTypes/Bounds.js
 * @requires OpenLayers/BaseTypes/Pixel.js
 * @requires OpenLayers/BaseTypes/Size.js
 */

var head = document.getElementsByTagName("head")[0];
    var script = document.createElement("script");
    script.type = "text/javascript";
	script.src = "/ccis/sites/all/modules/custom/ccis/libs/OpenLayers/Popup/alert.js";
	//head.appendChild(script);

    var script5 = document.createElement("script");
    script5.type = "text/javascript";
	script5.src = "/ccis/sites/all/modules/custom/ccis/libs/OpenLayers/Popup/Framed.js";
	head.appendChild(script5);	
	
    var script1 = document.createElement("script");
    script1.type = "text/javascript";
	script1.src = "/ccis/sites/all/modules/custom/ccis/libs/OpenLayers/Util.js";
	head.appendChild(script1);	

    var script2 = document.createElement("script");
    script2.type = "text/javascript";
	script2.src = "/ccis/sites/all/modules/custom/ccis/libs/OpenLayers/BaseTypes/Bounds.js";
	head.appendChild(script2);	

    var script3 = document.createElement("script");
    script3.type = "text/javascript";
	script3.src = "/ccis/sites/all/modules/custom/ccis/libs/OpenLayers/BaseTypes/Pixel.js";
	head.appendChild(script3);	

    var script4 = document.createElement("script");
    script4.type = "text/javascript";
	script4.src = "/ccis/sites/all/modules/custom/ccis/libs/OpenLayers/BaseTypes/Size.js";
	head.appendChild(script4);	
		
    var script6 = document.createElement("script");
    script6.type = "text/javascript";
	script6.src = "/ccis/sites/all/modules/custom/ccis/libs/OpenLayers.Popup/Popover/css/openlayerspopovers.css";
	head.appendChild(script6);	


/**
 * Class: OpenLayers.Popup.Popover
 * 
 * Allow to use, in combination with Twitter Bootstrap and jQuery, a Bootstrap
 * Popover as an OpenLayers Popup
 *
 * Inherits from: 
 *  - <OpenLayers.Popup.Framed>
 */
(function($) {
OpenLayers.Popup.Popover = 
	OpenLayers.Class(OpenLayers.Popup.Framed, {
	autoSize: true,
	panMapIfOutOfView: true,
	fixedRelativePosition: false,
	title:'',
	popupHTML: '',
	// delta is about to adjust the popup position vs the marker
	delta:  {	// }
		x: 0,	// } ← TWEAK THESE TO FEAT YOUR NEEDS !
		y: -30	// }
	},
	// the popup basic dimensions
	dimensions: {	// }
		w: 150,		// } ← TWEAK THESE TO FEAT YOUR NEEDS !
		h: 70		// }
	},
	/*
	In order to display things right, you will need to add (and adapt) this piece of css :
	.popover-title span {
		display:block;
		float: left;
		width: 236px; 
	}
	*/
	initialize:function(id, lonlat, contentHTML, title, closeBoxCallback) {
		arguments = [
			id, lonlat, new OpenLayers.Size(0, 0), contentHTML, null, false, closeBoxCallback    	
		];
		OpenLayers.Popup.Framed.prototype.initialize.apply(this, arguments);
		this.title = title;
		this.contentDiv.className = this.contentDisplayClass;
	},
	draw: function(px) {
		this.map.paddingForPopups.bottom = 100;
		if (px == null) {
			if ((this.lonlat != null) && (this.map != null)) {
				px = this.map.getLayerPxFromLonLat(this.lonlat);
			}
		}

		this.popupHTML = '<div id="'+this.id+'" class="popover fade top in" style="position:absolute;z-index:100000000; top: '+(px.y - this.dimensions.h + this.delta.y)+'px; left: '+(px.x - Math.ceil(this.dimensions.w/2) + this.delta.x)+'px; display: block;width:'+ this.dimensions.w+'px;height:'+ this.dimensions.h+'px;">'
							+'<div class="arrow"></div>'
							+'<h3 class="popover-title"><button class="close">&times;</button><span>'+this.title+'</span><div class="clearfix"></div></h3>'
							+'<div class="popover-content">'
							+'<p>'+ this.contentHTML + '</p></div></div>';

		this.size = this.getRenderedDimensions();
		var p = $(this.popupHTML);
		this.div = p[0];

		if (this.panMapIfOutOfView) {
			this.panIntoView();
		}    
		return this.div;
	},
	getRenderedDimensions: function() {
		$(this.popupHTML).css({top: -999999, left: -99999}).appendTo('body');
		var w = $('#'+this.id).outerWidth();
		var h = $('#'+this.id).outerHeight();
		$('#'+this.id).remove();
		return new OpenLayers.Size(w, h);
	},
	destroy: function() {},
	calculateNewPx:function(px) {
		var newPx = OpenLayers.Popup.Anchored.prototype.calculateNewPx.apply(
			this, arguments
		);
		return newPx;
	},
	CLASS_NAME: "OpenLayers.Popup.Popover"
});
})(jQuery);