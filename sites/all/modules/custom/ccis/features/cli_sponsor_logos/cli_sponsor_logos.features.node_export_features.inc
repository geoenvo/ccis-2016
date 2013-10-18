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
      \'vid\' => \'73\',
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
      \'created\' => \'1382117293\',
      \'changed\' => \'1382117293\',
      \'tnid\' => \'0\',
      \'translate\' => \'0\',
      \'uuid\' => \'026c7629-fed2-4fd4-8b0c-1df3d85f9a5f\',
      \'revision_timestamp\' => \'1382117293\',
      \'revision_uid\' => \'1\',
      \'field_images_sponsorlogo\' => array(
        \'und\' => array(
          array(
            \'fid\' => \'22\',
            \'alt\' => \'Deutsche Gesellschaft für Internationale Zusammenarbeit (GIZ) GmbH\',
            \'title\' => \'\',
            \'width\' => \'223\',
            \'height\' => \'68\',
            \'uid\' => \'1\',
            \'filename\' => \'giz.png\',
            \'uri\' => \'public://stakeholders/giz.png\',
            \'filemime\' => \'image/png\',
            \'filesize\' => \'10134\',
            \'status\' => \'1\',
            \'timestamp\' => \'1382117293\',
            \'uuid\' => \'98d9382c-bbf4-482c-b9b1-4c4249db7a83\',
            \'rdf_mapping\' => array(),
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
      \'vid\' => \'75\',
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
      \'created\' => \'1382117384\',
      \'changed\' => \'1382117384\',
      \'tnid\' => \'0\',
      \'translate\' => \'0\',
      \'uuid\' => \'b389b496-3295-4e86-bb19-c0f078c0e09b\',
      \'revision_timestamp\' => \'1382117384\',
      \'revision_uid\' => \'1\',
      \'field_images_sponsorlogo\' => array(
        \'und\' => array(
          array(
            \'fid\' => \'24\',
            \'alt\' => \'Federal Ministry for the Environment, Nature Conservation and Nuclear Safety\',
            \'title\' => \'\',
            \'width\' => \'183\',
            \'height\' => \'68\',
            \'uid\' => \'1\',
            \'filename\' => \'bmu_en.png\',
            \'uri\' => \'public://stakeholders/bmu_en.png\',
            \'filemime\' => \'image/png\',
            \'filesize\' => \'8473\',
            \'status\' => \'1\',
            \'timestamp\' => \'1382117384\',
            \'uuid\' => \'49cd1b7d-df28-4b0e-a342-70fd7b26121c\',
            \'rdf_mapping\' => array(),
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
      \'vid\' => \'74\',
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
      \'created\' => \'1382117329\',
      \'changed\' => \'1382117329\',
      \'tnid\' => \'0\',
      \'translate\' => \'0\',
      \'uuid\' => \'c2c566d9-3d6d-4937-b913-0e168adc63cc\',
      \'revision_timestamp\' => \'1382117329\',
      \'revision_uid\' => \'1\',
      \'field_images_sponsorlogo\' => array(
        \'und\' => array(
          array(
            \'fid\' => \'23\',
            \'alt\' => \'BMKG\',
            \'title\' => \'\',
            \'width\' => \'85\',
            \'height\' => \'68\',
            \'uid\' => \'1\',
            \'filename\' => \'bmkg.png\',
            \'uri\' => \'public://stakeholders/bmkg.png\',
            \'filemime\' => \'image/png\',
            \'filesize\' => \'4009\',
            \'status\' => \'1\',
            \'timestamp\' => \'1382117329\',
            \'uuid\' => \'90262133-9a8e-42c1-948f-fba19d036a3c\',
            \'rdf_mapping\' => array(),
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
