<?php
/**
 * @file
 * rb_configuration.features.node_export_features.inc
 */

/**
 * Implements hook_node_export_features_default().
 */
function rb_configuration_node_export_features_default() {
  $node_export = array(
  'code_string' => 'array(
  (object) array(
      \'vid\' => \'59\',
      \'uid\' => \'1\',
      \'title\' => \'Access denied\',
      \'log\' => \'\',
      \'status\' => \'1\',
      \'comment\' => \'1\',
      \'promote\' => \'0\',
      \'sticky\' => \'0\',
      \'vuuid\' => \'be139c78-fcbb-46b1-9db6-7cf07f063707\',
      \'nid\' => \'27\',
      \'type\' => \'page\',
      \'language\' => \'und\',
      \'created\' => \'1382087828\',
      \'changed\' => \'1382087828\',
      \'tnid\' => \'0\',
      \'translate\' => \'0\',
      \'uuid\' => \'5d3d9b60-64fb-4e0c-9585-0c8247b85d33\',
      \'revision_timestamp\' => \'1382089311\',
      \'revision_uid\' => \'1\',
      \'body\' => array(
        \'und\' => array(
          array(
            \'value\' => "You are not authorized to access this page.\\r\\nPlease <a href=\\"/login\\">log in</a> or visit the <a href=\\"/\\">home page</a> for reorientation.",
            \'summary\' => \'\',
            \'format\' => \'simple_html\',
            \'safe_value\' => "<p>You are not authorized to access this page.<br />\\nPlease <a href=\\"/login\\">log in</a> or visit the <a href=\\"/\\">home page</a> for reorientation.</p>\\n",
            \'safe_summary\' => \'\',
          ),
        ),
      ),
      \'rdf_mapping\' => array(
        \'rdftype\' => array(
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
      \'last_comment_timestamp\' => \'1382087828\',
      \'last_comment_name\' => NULL,
      \'last_comment_uid\' => \'1\',
      \'comment_count\' => \'0\',
      \'name\' => \'admin\',
      \'picture\' => \'0\',
      \'data\' => \'b:0;\',
      \'path\' => array(
        \'pid\' => \'10\',
        \'source\' => \'node/27\',
        \'alias\' => \'403\',
        \'language\' => \'und\',
      ),
      \'menu\' => NULL,
      \'node_export_drupal_version\' => \'7\',
    ),
  (object) array(
      \'vid\' => \'60\',
      \'uid\' => \'1\',
      \'title\' => \'Page not found\',
      \'log\' => \'\',
      \'status\' => \'1\',
      \'comment\' => \'1\',
      \'promote\' => \'0\',
      \'sticky\' => \'0\',
      \'vuuid\' => \'def2ac16-cca4-41dc-8e2f-c9da9e51afc7\',
      \'nid\' => \'28\',
      \'type\' => \'page\',
      \'language\' => \'und\',
      \'created\' => \'1382087694\',
      \'changed\' => \'1382087842\',
      \'tnid\' => \'0\',
      \'translate\' => \'0\',
      \'uuid\' => \'71d2f4cb-4f08-4892-b160-13992aced583\',
      \'revision_timestamp\' => \'1382089311\',
      \'revision_uid\' => \'1\',
      \'body\' => array(
        \'und\' => array(
          array(
            \'value\' => "The requested page could not be found.\\r\\nMaybe you followed an outdated link. Please visit the <a href=\\"/\\">home page</a> for reorientation.\\r\\n\\r\\nThank you for your patience.",
            \'summary\' => \'\',
            \'format\' => \'simple_html\',
            \'safe_value\' => "<p>The requested page could not be found.<br />\\nMaybe you followed an outdated link. Please visit the <a href=\\"/\\">home page</a> for reorientation.</p>\\n<p>Thank you for your patience.</p>\\n",
            \'safe_summary\' => \'\',
          ),
        ),
      ),
      \'rdf_mapping\' => array(
        \'rdftype\' => array(
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
      \'last_comment_timestamp\' => \'1382087842\',
      \'last_comment_name\' => NULL,
      \'last_comment_uid\' => \'1\',
      \'comment_count\' => \'0\',
      \'name\' => \'admin\',
      \'picture\' => \'0\',
      \'data\' => \'b:0;\',
      \'path\' => array(
        \'pid\' => \'11\',
        \'source\' => \'node/28\',
        \'alias\' => \'404\',
        \'language\' => \'und\',
      ),
      \'menu\' => NULL,
      \'node_export_drupal_version\' => \'7\',
    ),
)',
);
  return $node_export;
}
