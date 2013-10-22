<?php
/**
 * @file
 * cli_sponsor_logos.features.node_export_features.inc
 */

/**
 * Implements hook_node_export_features_default().
 */
function cli_sponsor_logos_node_export_features_default() {
  $node_export = array(
  'code_string' => 'array(
  (object) array(
      \'vid\' => \'82\',
      \'uid\' => \'1\',
      \'title\' => \'GIZ\',
      \'log\' => \'\',
      \'status\' => \'1\',
      \'comment\' => \'1\',
      \'promote\' => \'1\',
      \'sticky\' => \'0\',
      \'vuuid\' => \'f92ef939-933e-4698-b630-004911e72c1d\',
      \'nid\' => \'39\',
      \'type\' => \'sponsor_logo\',
      \'language\' => \'und\',
      \'created\' => \'1382357547\',
      \'changed\' => \'1382357547\',
      \'tnid\' => \'0\',
      \'translate\' => \'0\',
      \'uuid\' => \'026c7629-fed2-4fd4-8b0c-1df3d85f9a5f\',
      \'revision_timestamp\' => \'1382357547\',
      \'revision_uid\' => \'1\',
      \'field_images_sponsorlogo\' => array(
        \'und\' => array(
          array(
            \'fid\' => NULL,
            \'alt\' => NULL,
            \'title\' => NULL,
            \'width\' => \'223\',
            \'height\' => \'68\',
            \'uid\' => \'1\',
            \'filename\' => \'giz.png\',
            \'uri\' => \'public://stakeholders/giz.png\',
            \'filemime\' => \'image/png\',
            \'filesize\' => \'10134\',
            \'status\' => \'1\',
            \'timestamp\' => \'1382357547\',
            \'uuid\' => \'98d9382c-bbf4-482c-b9b1-4c4249db7a83\',
            \'rdf_mapping\' => array(),
            \'node_export_file_data\' => \'iVBORw0KGgoAAAANSUhEUgAAAN8AAABECAIAAACOOnf7AAAAGXRFWHRTb2Z0d2FyZQBBZG9iZSBJbWFnZVJlYWR5ccllPAAAAyJpVFh0WE1MOmNvbS5hZG9iZS54bXAAAAAAADw/eHBhY2tldCBiZWdpbj0i77u/IiBpZD0iVzVNME1wQ2VoaUh6cmVTek5UY3prYzlkIj8+IDx4OnhtcG1ldGEgeG1sbnM6eD0iYWRvYmU6bnM6bWV0YS8iIHg6eG1wdGs9IkFkb2JlIFhNUCBDb3JlIDUuMy1jMDExIDY2LjE0NTY2MSwgMjAxMi8wMi8wNi0xNDo1NjoyNyAgICAgICAgIj4gPHJkZjpSREYgeG1sbnM6cmRmPSJodHRwOi8vd3d3LnczLm9yZy8xOTk5LzAyLzIyLXJkZi1zeW50YXgtbnMjIj4gPHJkZjpEZXNjcmlwdGlvbiByZGY6YWJvdXQ9IiIgeG1sbnM6eG1wPSJodHRwOi8vbnMuYWRvYmUuY29tL3hhcC8xLjAvIiB4bWxuczp4bXBNTT0iaHR0cDovL25zLmFkb2JlLmNvbS94YXAvMS4wL21tLyIgeG1sbnM6c3RSZWY9Imh0dHA6Ly9ucy5hZG9iZS5jb20veGFwLzEuMC9zVHlwZS9SZXNvdXJjZVJlZiMiIHhtcDpDcmVhdG9yVG9vbD0iQWRvYmUgUGhvdG9zaG9wIENTNiAoV2luZG93cykiIHhtcE1NOkluc3RhbmNlSUQ9InhtcC5paWQ6N0Y4RUZBRUQzODE4MTFFMzhENTNCMjRGNkUyRDYxNUEiIHhtcE1NOkRvY3VtZW50SUQ9InhtcC5kaWQ6N0Y4RUZBRUUzODE4MTFFMzhENTNCMjRGNkUyRDYxNUEiPiA8eG1wTU06RGVyaXZlZEZyb20gc3RSZWY6aW5zdGFuY2VJRD0ieG1wLmlpZDo3RjhFRkFFQjM4MTgxMUUzOEQ1M0IyNEY2RTJENjE1QSIgc3RSZWY6ZG9jdW1lbnRJRD0ieG1wLmRpZDo3RjhFRkFFQzM4MTgxMUUzOEQ1M0IyNEY2RTJENjE1QSIvPiA8L3JkZjpEZXNjcmlwdGlvbj4gPC9yZGY6UkRGPiA8L3g6eG1wbWV0YT4gPD94cGFja2V0IGVuZD0iciI/PoBZqxwAACQKSURBVHja7FwHmBRF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\',
          ),
        ),
      ),
      \'field_caption_top\' => array(
        \'und\' => array(
          array(
            \'value\' => \'Implemented by:\',
            \'format\' => NULL,
            \'safe_value\' => \'Implemented by:\',
          ),
        ),
      ),
      \'field_caption_bottom\' => array(),
      \'rdf_mapping\' => array(
        \'rdftype\' => array(
          \'sioc:Item\',
          \'foaf:Document\',
        ),
        \'title\' => array(
          \'predicates\' => array(
            \'dc:title\',
          ),
        ),
        \'created\' => array(
          \'predicates\' => array(
            \'dc:date\',
            \'dc:created\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
        \'changed\' => array(
          \'predicates\' => array(
            \'dc:modified\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
        \'body\' => array(
          \'predicates\' => array(
            \'content:encoded\',
          ),
        ),
        \'uid\' => array(
          \'predicates\' => array(
            \'sioc:has_creator\',
          ),
          \'type\' => \'rel\',
        ),
        \'name\' => array(
          \'predicates\' => array(
            \'foaf:name\',
          ),
        ),
        \'comment_count\' => array(
          \'predicates\' => array(
            \'sioc:num_replies\',
          ),
          \'datatype\' => \'xsd:integer\',
        ),
        \'last_activity\' => array(
          \'predicates\' => array(
            \'sioc:last_activity_date\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
      ),
      \'cid\' => \'0\',
      \'last_comment_timestamp\' => \'1382117293\',
      \'last_comment_name\' => NULL,
      \'last_comment_uid\' => \'1\',
      \'comment_count\' => \'0\',
      \'name\' => \'CCI-Adm\',
      \'picture\' => \'0\',
      \'data\' => \'b:0;\',
      \'path\' => array(
        \'pid\' => \'10\',
        \'source\' => \'node/39\',
        \'alias\' => \'stakeholder/giz\',
        \'language\' => \'und\',
      ),
      \'menu\' => NULL,
      \'node_export_drupal_version\' => \'7\',
    ),
  (object) array(
      \'vid\' => \'83\',
      \'uid\' => \'1\',
      \'title\' => \'BMU\',
      \'log\' => \'\',
      \'status\' => \'1\',
      \'comment\' => \'1\',
      \'promote\' => \'1\',
      \'sticky\' => \'0\',
      \'vuuid\' => \'ea4294e7-80f4-46f8-8be2-ff39af0c446c\',
      \'nid\' => \'41\',
      \'type\' => \'sponsor_logo\',
      \'language\' => \'und\',
      \'created\' => \'1382357547\',
      \'changed\' => \'1382357547\',
      \'tnid\' => \'0\',
      \'translate\' => \'0\',
      \'uuid\' => \'b389b496-3295-4e86-bb19-c0f078c0e09b\',
      \'revision_timestamp\' => \'1382357547\',
      \'revision_uid\' => \'1\',
      \'field_images_sponsorlogo\' => array(
        \'und\' => array(
          array(
            \'fid\' => NULL,
            \'alt\' => NULL,
            \'title\' => NULL,
            \'width\' => \'183\',
            \'height\' => \'68\',
            \'uid\' => \'1\',
            \'filename\' => \'bmu_en.png\',
            \'uri\' => \'public://stakeholders/bmu_en.png\',
            \'filemime\' => \'image/png\',
            \'filesize\' => \'8473\',
            \'status\' => \'1\',
            \'timestamp\' => \'1382357547\',
            \'uuid\' => \'49cd1b7d-df28-4b0e-a342-70fd7b26121c\',
            \'rdf_mapping\' => array(),
            \'node_export_file_data\' => \'iVBORw0KGgoAAAANSUhEUgAAALcAAABECAIAAABMCjN/AAAAGXRFWHRTb2Z0d2FyZQBBZG9iZSBJbWFnZVJlYWR5ccllPAAAAyJpVFh0WE1MOmNvbS5hZG9iZS54bXAAAAAAADw/eHBhY2tldCBiZWdpbj0i77u/IiBpZD0iVzVNME1wQ2VoaUh6cmVTek5UY3prYzlkIj8+IDx4OnhtcG1ldGEgeG1sbnM6eD0iYWRvYmU6bnM6bWV0YS8iIHg6eG1wdGs9IkFkb2JlIFhNUCBDb3JlIDUuMy1jMDExIDY2LjE0NTY2MSwgMjAxMi8wMi8wNi0xNDo1NjoyNyAgICAgICAgIj4gPHJkZjpSREYgeG1sbnM6cmRmPSJodHRwOi8vd3d3LnczLm9yZy8xOTk5LzAyLzIyLXJkZi1zeW50YXgtbnMjIj4gPHJkZjpEZXNjcmlwdGlvbiByZGY6YWJvdXQ9IiIgeG1sbnM6eG1wPSJodHRwOi8vbnMuYWRvYmUuY29tL3hhcC8xLjAvIiB4bWxuczp4bXBNTT0iaHR0cDovL25zLmFkb2JlLmNvbS94YXAvMS4wL21tLyIgeG1sbnM6c3RSZWY9Imh0dHA6Ly9ucy5hZG9iZS5jb20veGFwLzEuMC9zVHlwZS9SZXNvdXJjZVJlZiMiIHhtcDpDcmVhdG9yVG9vbD0iQWRvYmUgUGhvdG9zaG9wIENTNiAoV2luZG93cykiIHhtcE1NOkluc3RhbmNlSUQ9InhtcC5paWQ6Nzc4QjA1RDkzODE4MTFFM0E1NUFDNzIzOTNFNUFBNkIiIHhtcE1NOkRvY3VtZW50SUQ9InhtcC5kaWQ6Nzc4QjA1REEzODE4MTFFM0E1NUFDNzIzOTNFNUFBNkIiPiA8eG1wTU06RGVyaXZlZEZyb20gc3RSZWY6aW5zdGFuY2VJRD0ieG1wLmlpZDo3NzhCMDVENzM4MTgxMUUzQTU1QUM3MjM5M0U1QUE2QiIgc3RSZWY6ZG9jdW1lbnRJRD0ieG1wLmRpZDo3NzhCMDVEODM4MTgxMUUzQTU1QUM3MjM5M0U1QUE2QiIvPiA8L3JkZjpEZXNjcmlwdGlvbj4gPC9yZGY6UkRGPiA8L3g6eG1wbWV0YT4gPD94cGFja2V0IGVuZD0iciI/PooXAtcAAB2NSURBVHja7FxnQFTX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\',
          ),
        ),
      ),
      \'field_caption_top\' => array(
        \'und\' => array(
          array(
            \'value\' => \'On behalf of:\',
            \'format\' => NULL,
            \'safe_value\' => \'On behalf of:\',
          ),
        ),
      ),
      \'field_caption_bottom\' => array(
        \'und\' => array(
          array(
            \'value\' => \'of the Federal Republic of Germany\',
            \'format\' => NULL,
            \'safe_value\' => \'of the Federal Republic of Germany\',
          ),
        ),
      ),
      \'rdf_mapping\' => array(
        \'rdftype\' => array(
          \'sioc:Item\',
          \'foaf:Document\',
        ),
        \'title\' => array(
          \'predicates\' => array(
            \'dc:title\',
          ),
        ),
        \'created\' => array(
          \'predicates\' => array(
            \'dc:date\',
            \'dc:created\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
        \'changed\' => array(
          \'predicates\' => array(
            \'dc:modified\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
        \'body\' => array(
          \'predicates\' => array(
            \'content:encoded\',
          ),
        ),
        \'uid\' => array(
          \'predicates\' => array(
            \'sioc:has_creator\',
          ),
          \'type\' => \'rel\',
        ),
        \'name\' => array(
          \'predicates\' => array(
            \'foaf:name\',
          ),
        ),
        \'comment_count\' => array(
          \'predicates\' => array(
            \'sioc:num_replies\',
          ),
          \'datatype\' => \'xsd:integer\',
        ),
        \'last_activity\' => array(
          \'predicates\' => array(
            \'sioc:last_activity_date\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
      ),
      \'cid\' => \'0\',
      \'last_comment_timestamp\' => \'1382117384\',
      \'last_comment_name\' => NULL,
      \'last_comment_uid\' => \'1\',
      \'comment_count\' => \'0\',
      \'name\' => \'CCI-Adm\',
      \'picture\' => \'0\',
      \'data\' => \'b:0;\',
      \'path\' => array(
        \'pid\' => \'12\',
        \'source\' => \'node/41\',
        \'alias\' => \'stakeholder/bmu\',
        \'language\' => \'und\',
      ),
      \'menu\' => NULL,
      \'node_export_drupal_version\' => \'7\',
    ),
  (object) array(
      \'vid\' => \'84\',
      \'uid\' => \'1\',
      \'title\' => \'BMKG\',
      \'log\' => \'\',
      \'status\' => \'1\',
      \'comment\' => \'1\',
      \'promote\' => \'1\',
      \'sticky\' => \'0\',
      \'vuuid\' => \'79a22d32-d70c-4f79-81f0-c326a445861b\',
      \'nid\' => \'40\',
      \'type\' => \'sponsor_logo\',
      \'language\' => \'und\',
      \'created\' => \'1382357547\',
      \'changed\' => \'1382357547\',
      \'tnid\' => \'0\',
      \'translate\' => \'0\',
      \'uuid\' => \'c2c566d9-3d6d-4937-b913-0e168adc63cc\',
      \'revision_timestamp\' => \'1382357547\',
      \'revision_uid\' => \'1\',
      \'field_images_sponsorlogo\' => array(
        \'und\' => array(
          array(
            \'fid\' => NULL,
            \'alt\' => NULL,
            \'title\' => NULL,
            \'width\' => \'85\',
            \'height\' => \'68\',
            \'uid\' => \'1\',
            \'filename\' => \'bmkg.png\',
            \'uri\' => \'public://stakeholders/bmkg.png\',
            \'filemime\' => \'image/png\',
            \'filesize\' => \'4009\',
            \'status\' => \'1\',
            \'timestamp\' => \'1382357547\',
            \'uuid\' => \'90262133-9a8e-42c1-948f-fba19d036a3c\',
            \'rdf_mapping\' => array(),
            \'node_export_file_data\' => \'iVBORw0KGgoAAAANSUhEUgAAAFUAAABECAIAAAB/He4zAAAAGXRFWHRTb2Z0d2FyZQBBZG9iZSBJbWFnZVJlYWR5ccllPAAAAyJpVFh0WE1MOmNvbS5hZG9iZS54bXAAAAAAADw/eHBhY2tldCBiZWdpbj0i77u/IiBpZD0iVzVNME1wQ2VoaUh6cmVTek5UY3prYzlkIj8+IDx4OnhtcG1ldGEgeG1sbnM6eD0iYWRvYmU6bnM6bWV0YS8iIHg6eG1wdGs9IkFkb2JlIFhNUCBDb3JlIDUuMy1jMDExIDY2LjE0NTY2MSwgMjAxMi8wMi8wNi0xNDo1NjoyNyAgICAgICAgIj4gPHJkZjpSREYgeG1sbnM6cmRmPSJodHRwOi8vd3d3LnczLm9yZy8xOTk5LzAyLzIyLXJkZi1zeW50YXgtbnMjIj4gPHJkZjpEZXNjcmlwdGlvbiByZGY6YWJvdXQ9IiIgeG1sbnM6eG1wPSJodHRwOi8vbnMuYWRvYmUuY29tL3hhcC8xLjAvIiB4bWxuczp4bXBNTT0iaHR0cDovL25zLmFkb2JlLmNvbS94YXAvMS4wL21tLyIgeG1sbnM6c3RSZWY9Imh0dHA6Ly9ucy5hZG9iZS5jb20veGFwLzEuMC9zVHlwZS9SZXNvdXJjZVJlZiMiIHhtcDpDcmVhdG9yVG9vbD0iQWRvYmUgUGhvdG9zaG9wIENTNiAoV2luZG93cykiIHhtcE1NOkluc3RhbmNlSUQ9InhtcC5paWQ6N0M1MkI0NDgzODE4MTFFM0FBM0RDQ0IwNTkzQTlGMUIiIHhtcE1NOkRvY3VtZW50SUQ9InhtcC5kaWQ6N0M1MkI0NDkzODE4MTFFM0FBM0RDQ0IwNTkzQTlGMUIiPiA8eG1wTU06RGVyaXZlZEZyb20gc3RSZWY6aW5zdGFuY2VJRD0ieG1wLmlpZDo3QzUyQjQ0NjM4MTgxMUUzQUEzRENDQjA1OTNBOUYxQiIgc3RSZWY6ZG9jdW1lbnRJRD0ieG1wLmRpZDo3QzUyQjQ0NzM4MTgxMUUzQUEzRENDQjA1OTNBOUYxQiIvPiA8L3JkZjpEZXNjcmlwdGlvbj4gPC9yZGY6UkRGPiA8L3g6eG1wbWV0YT4gPD94cGFja2V0IGVuZD0iciI/PkLKTwsAAAwdSURBVHja7FsJcBRV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\',
          ),
        ),
      ),
      \'field_caption_top\' => array(
        \'und\' => array(
          array(
            \'value\' => \'In cooperation with:\',
            \'format\' => NULL,
            \'safe_value\' => \'In cooperation with:\',
          ),
        ),
      ),
      \'field_caption_bottom\' => array(),
      \'rdf_mapping\' => array(
        \'rdftype\' => array(
          \'sioc:Item\',
          \'foaf:Document\',
        ),
        \'title\' => array(
          \'predicates\' => array(
            \'dc:title\',
          ),
        ),
        \'created\' => array(
          \'predicates\' => array(
            \'dc:date\',
            \'dc:created\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
        \'changed\' => array(
          \'predicates\' => array(
            \'dc:modified\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
        \'body\' => array(
          \'predicates\' => array(
            \'content:encoded\',
          ),
        ),
        \'uid\' => array(
          \'predicates\' => array(
            \'sioc:has_creator\',
          ),
          \'type\' => \'rel\',
        ),
        \'name\' => array(
          \'predicates\' => array(
            \'foaf:name\',
          ),
        ),
        \'comment_count\' => array(
          \'predicates\' => array(
            \'sioc:num_replies\',
          ),
          \'datatype\' => \'xsd:integer\',
        ),
        \'last_activity\' => array(
          \'predicates\' => array(
            \'sioc:last_activity_date\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
      ),
      \'cid\' => \'0\',
      \'last_comment_timestamp\' => \'1382117329\',
      \'last_comment_name\' => NULL,
      \'last_comment_uid\' => \'1\',
      \'comment_count\' => \'0\',
      \'name\' => \'CCI-Adm\',
      \'picture\' => \'0\',
      \'data\' => \'b:0;\',
      \'path\' => array(
        \'pid\' => \'11\',
        \'source\' => \'node/40\',
        \'alias\' => \'stakeholder/bmkg\',
        \'language\' => \'und\',
      ),
      \'menu\' => NULL,
      \'node_export_drupal_version\' => \'7\',
    ),
)',
);
  return $node_export;
}
