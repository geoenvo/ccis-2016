<?php
/**
 * @file
 * cli_sample_content.features.node_export_features.inc
 */

/**
 * Implements hook_node_export_features_default().
 */
function cli_sample_content_node_export_features_default() {
  $node_export = array(
  'code_string' => 'array(
  (object) array(
      \'vid\' => \'123\',
      \'uid\' => \'1\',
      \'title\' => \'Welcome\',
      \'log\' => \'\',
      \'status\' => \'1\',
      \'comment\' => \'1\',
      \'promote\' => \'0\',
      \'sticky\' => \'0\',
      \'vuuid\' => \'2c09f13f-786f-4df8-8076-b20396312c5b\',
      \'nid\' => \'123\',
      \'type\' => \'page\',
      \'language\' => \'und\',
      \'created\' => \'1382453294\',
      \'changed\' => \'1382453294\',
      \'tnid\' => \'0\',
      \'translate\' => \'0\',
      \'uuid\' => \'0dc9951a-04d5-48a0-8ba4-eb2046aeef29\',
      \'revision_timestamp\' => \'1382453294\',
      \'revision_uid\' => \'1\',
      \'body\' => array(),
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
      \'last_comment_timestamp\' => \'1382453294\',
      \'last_comment_name\' => NULL,
      \'last_comment_uid\' => \'1\',
      \'comment_count\' => \'0\',
      \'name\' => \'admin\',
      \'picture\' => \'0\',
      \'data\' => \'b:0;\',
      \'path\' => FALSE,
      \'menu\' => NULL,
      \'node_export_drupal_version\' => \'7\',
    ),
  (object) array(
      \'vid\' => \'124\',
      \'uid\' => \'1\',
      \'title\' => \'Why is adaptation to climate change necessary?\',
      \'log\' => \'\',
      \'status\' => \'1\',
      \'comment\' => \'2\',
      \'promote\' => \'1\',
      \'sticky\' => \'0\',
      \'vuuid\' => \'d3652c76-6231-4e6c-9e42-29722d26c604\',
      \'nid\' => \'124\',
      \'type\' => \'blog_article\',
      \'language\' => \'en\',
      \'created\' => \'1382453294\',
      \'changed\' => \'1382453294\',
      \'tnid\' => \'0\',
      \'translate\' => \'0\',
      \'uuid\' => \'2efaadcb-7a7f-4379-b6f1-ee723b909d44\',
      \'revision_timestamp\' => \'1382453294\',
      \'revision_uid\' => \'1\',
      \'body\' => array(
        \'und\' => array(
          array(
            \'value\' => "For several decades, our global climate has been changing, with increasingly severe consequences. Global climate change causes gradual and longterm climatic shifts, such as an increase in average temperature and thus a rise in sea levels. Extreme weather events are also occurring with greater frequency and intensity.\\r\\n\\r\\nAs a result, many vital sectors – such as water resources, agricultural production, coastal zones, human settlements, as well as energy supply and the health sector – are under threat worldwide. However, the threats resulting from climate change cause highly disparate problems in the different regions of the world. Some regions will quite literally be deluged, while others will face water shortages. Some countries will experience more frequent and stronger floods and the permanent submersion of entire coastal areas.Yet in regions already prone to aridity, drought will occur with greater frequency and intensity. Other countries and regions – or, in a worst-case scenario, the same ones – are likely to suffer other extreme events, such as storms, mudslides and avalanches. Entire cities, road networks and economic regions are thus at risk.\\r\\n\\r\\nThe impacts of climate change have become more acute in recent decades, and we must assume that they are likely to intensify further. Identifying appropriate responses to climate change should therefore be a key element of the sustainable development strategies adopted by the affected countries. Yet at present, there is virtually no experience of how to manage this adaptation process.There are scarcely any systematic risk assessments predicting who will be affected, and when. What is certain, however, is that the impacts will be felt most acutely by those with least adaptive capacity due to their lack of financial and technical resources: the poor countries, and the poor in the developing countries. For this reason, the developing countries are calling for intensive support from the industrialized countries – which are primarily responsible for climate change – in planning and implementing adaptation measures.\\r\\n\\r\\n<h2>Visible effects of climate change</h2>\\r\\n<h3>Glaciers</h3>\\r\\nGlaciers are the world’s climate thermometers, casting an icy spotlight upon rising global mean temperatures.Throughout the world, glaciers are shrinking. In the Himalayas, for example, glacial waters are filling the centuries-old natural catch basins far too quickly, posing a risk to human life, ecosystems and infrastructure, such as hydro-electric plants. In East Africa, Mount Kilimanjaro’s ice cap is melting, while in Central Europe, glacial retreat may result in long-term problems with water supplies. The shrinking of the Alpine glaciers is scientifically proven and is further accelerated by extreme heat waves, as in summer 2003.\\r\\n\\r\\nTwo-thirds of Africa is already affected by aridity and drought, and desertification is advancing. Climate change is intensifying these trends.\\r\\nIn parts of the Indian subcontinent, on the other hand, precipitation is increasing significantly. In northern India and in Bangladesh, more and more houses are washed away during the monsoons and many lives are lost through drowning.Yet other provinces are reliant on consignments of water, delivered by train, after years of extreme drought.\\r\\nIslands in the Pacific Ocean are severely affected, and the impact of rising sea levels is felt acutely by local communities. Parts of these islands are already submerged, and if sea levels rise by a further 1 m, the Marshall Islands and Tuvalu will vanish into the sea.\\r\\n\\r\\n<em>[Source: www2.gtz.de/dokumente/bib-2011/giz2011-0159en-climate-change.pdf ]</em>",
            \'summary\' => \'For several decades, our global climate has been changing, with increasingly severe consequences. Global climate change causes gradual and longterm climatic shifts, such as an increase in average temperature and thus a rise in sea levels. Extreme weather events are also occurring with greater frequency and intensity.\',
            \'format\' => \'filtered_html\',
            \'safe_value\' => "<p>For several decades, our global climate has been changing, with increasingly severe consequences. Global climate change causes gradual and longterm climatic shifts, such as an increase in average temperature and thus a rise in sea levels. Extreme weather events are also occurring with greater frequency and intensity.</p>\\n<p>As a result, many vital sectors – such as water resources, agricultural production, coastal zones, human settlements, as well as energy supply and the health sector – are under threat worldwide. However, the threats resulting from climate change cause highly disparate problems in the different regions of the world. Some regions will quite literally be deluged, while others will face water shortages. Some countries will experience more frequent and stronger floods and the permanent submersion of entire coastal areas.Yet in regions already prone to aridity, drought will occur with greater frequency and intensity. Other countries and regions – or, in a worst-case scenario, the same ones – are likely to suffer other extreme events, such as storms, mudslides and avalanches. Entire cities, road networks and economic regions are thus at risk.</p>\\n<p>The impacts of climate change have become more acute in recent decades, and we must assume that they are likely to intensify further. Identifying appropriate responses to climate change should therefore be a key element of the sustainable development strategies adopted by the affected countries. Yet at present, there is virtually no experience of how to manage this adaptation process.There are scarcely any systematic risk assessments predicting who will be affected, and when. What is certain, however, is that the impacts will be felt most acutely by those with least adaptive capacity due to their lack of financial and technical resources: the poor countries, and the poor in the developing countries. For this reason, the developing countries are calling for intensive support from the industrialized countries – which are primarily responsible for climate change – in planning and implementing adaptation measures.</p>\\n<h2>Visible effects of climate change</h2>\\n<h3>Glaciers</h3>\\n<p>Glaciers are the world’s climate thermometers, casting an icy spotlight upon rising global mean temperatures.Throughout the world, glaciers are shrinking. In the Himalayas, for example, glacial waters are filling the centuries-old natural catch basins far too quickly, posing a risk to human life, ecosystems and infrastructure, such as hydro-electric plants. In East Africa, Mount Kilimanjaro’s ice cap is melting, while in Central Europe, glacial retreat may result in long-term problems with water supplies. The shrinking of the Alpine glaciers is scientifically proven and is further accelerated by extreme heat waves, as in summer 2003.</p>\\n<p>Two-thirds of Africa is already affected by aridity and drought, and desertification is advancing. Climate change is intensifying these trends.<br />\\nIn parts of the Indian subcontinent, on the other hand, precipitation is increasing significantly. In northern India and in Bangladesh, more and more houses are washed away during the monsoons and many lives are lost through drowning.Yet other provinces are reliant on consignments of water, delivered by train, after years of extreme drought.<br />\\nIslands in the Pacific Ocean are severely affected, and the impact of rising sea levels is felt acutely by local communities. Parts of these islands are already submerged, and if sea levels rise by a further 1 m, the Marshall Islands and Tuvalu will vanish into the sea.</p>\\n<p><em>[Source: www2.gtz.de/dokumente/bib-2011/giz2011-0159en-climate-change.pdf ]</em></p>\\n",
            \'safe_summary\' => "<p>For several decades, our global climate has been changing, with increasingly severe consequences. Global climate change causes gradual and longterm climatic shifts, such as an increase in average temperature and thus a rise in sea levels. Extreme weather events are also occurring with greater frequency and intensity.</p>\\n",
          ),
        ),
      ),
      \'field_blog_image\' => array(),
      \'field_tags\' => array(),
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
      \'last_comment_timestamp\' => \'1382453294\',
      \'last_comment_name\' => NULL,
      \'last_comment_uid\' => \'1\',
      \'comment_count\' => \'0\',
      \'name\' => \'admin\',
      \'picture\' => \'0\',
      \'data\' => \'b:0;\',
      \'path\' => FALSE,
      \'menu\' => NULL,
      \'node_export_drupal_version\' => \'7\',
    ),
  (object) array(
      \'vid\' => \'125\',
      \'uid\' => \'1\',
      \'title\' => \'Climate Summit 2014\',
      \'log\' => \'\',
      \'status\' => \'1\',
      \'comment\' => \'1\',
      \'promote\' => \'1\',
      \'sticky\' => \'0\',
      \'vuuid\' => \'4aa79390-6a12-4215-a4e5-bcc18ecf5290\',
      \'nid\' => \'125\',
      \'type\' => \'event\',
      \'language\' => \'und\',
      \'created\' => \'1382453294\',
      \'changed\' => \'1382453294\',
      \'tnid\' => \'0\',
      \'translate\' => \'0\',
      \'uuid\' => \'34bb65e2-ead6-4131-b45d-5a9378cd4574\',
      \'revision_timestamp\' => \'1382453294\',
      \'revision_uid\' => \'1\',
      \'body\' => array(
        \'und\' => array(
          array(
            \'value\' => "<blockquote>“I challenge you to bring to the Summit bold pledges. Innovate, scale-up, cooperate and deliver concrete action that will close the emissions gap and put us on track for an ambitious legal agreement through the UNFCCC process.”\\r\\n<em>UN Secretary-General Ban Ki-moon</em>\\r\\n</blockquote>\\r\\nAs part of a global effort to mobilize action and ambition on climate change, United Nations Secretary-General Ban Ki-moon is inviting Heads of State and Government along with business, finance, civil society and local leaders to a Climate Summit in September 2014, New York.\\r\\n\\r\\nThis Summit will be a different kind of Climate Summit. It is aimed at catalyzing action by governments, business, finance, industry, and civil society in areas for new commitments and substantial, scalable and replicable contributions to the Summit that will help the world shift toward a low-carbon economy.\\r\\n\\r\\nThe Summit will come one year before countries aim to conclude a global climate agreement in 2015 through the United Nations Framework Convention on Climate Change. Although the 2014 Climate Summit is not part of the negotiating process, countries have recognized the value of the Summit, including by welcoming the Secretary-General’s efforts in a Decision of the Doha climate conference in 2012.\\r\\n\\r\\nBy catalyzing action on climate change prior to the UNFCCC Climate Change Conference in 2015, the Secretary-General intends to build a solid foundation on which to anchor successful negotiations and sustained progress on the road to reducing emissions and strengthening adaptation strategies.",
            \'summary\' => \'\',
            \'format\' => \'simple_html\',
            \'safe_value\' => "<blockquote><p>“I challenge you to bring to the Summit bold pledges. Innovate, scale-up, cooperate and deliver concrete action that will close the emissions gap and put us on track for an ambitious legal agreement through the UNFCCC process.”<br /><em>UN Secretary-General Ban Ki-moon</em>\\n</p></blockquote>\\n<p>As part of a global effort to mobilize action and ambition on climate change, United Nations Secretary-General Ban Ki-moon is inviting Heads of State and Government along with business, finance, civil society and local leaders to a Climate Summit in September 2014, New York.</p>\\n<p>This Summit will be a different kind of Climate Summit. It is aimed at catalyzing action by governments, business, finance, industry, and civil society in areas for new commitments and substantial, scalable and replicable contributions to the Summit that will help the world shift toward a low-carbon economy.</p>\\n<p>The Summit will come one year before countries aim to conclude a global climate agreement in 2015 through the United Nations Framework Convention on Climate Change. Although the 2014 Climate Summit is not part of the negotiating process, countries have recognized the value of the Summit, including by welcoming the Secretary-General’s efforts in a Decision of the Doha climate conference in 2012.</p>\\n<p>By catalyzing action on climate change prior to the UNFCCC Climate Change Conference in 2015, the Secretary-General intends to build a solid foundation on which to anchor successful negotiations and sustained progress on the road to reducing emissions and strengthening adaptation strategies.</p>\\n",
            \'safe_summary\' => \'\',
          ),
        ),
      ),
      \'field_country_event\' => array(
        \'und\' => array(
          array(
            \'value\' => \'USA\',
            \'format\' => NULL,
            \'safe_value\' => \'USA\',
          ),
        ),
      ),
      \'field_date_event\' => array(
        \'und\' => array(
          array(
            \'value\' => \'2014-09-01 00:00:00\',
            \'value2\' => \'2014-09-01 00:00:00\',
            \'timezone\' => \'Europe/Berlin\',
            \'timezone_db\' => \'Europe/Berlin\',
            \'date_type\' => \'datetime\',
          ),
        ),
      ),
      \'field_image_event_logo\' => array(
        \'und\' => array(
          array(
            \'fid\' => \'36\',
            \'alt\' => NULL,
            \'title\' => NULL,
            \'width\' => \'170\',
            \'height\' => \'144\',
            \'uid\' => \'1\',
            \'filename\' => \'ClimateSummit14.jpg\',
            \'uri\' => \'public://events/ClimateSummit14.jpg\',
            \'filemime\' => \'image/jpeg\',
            \'filesize\' => \'23596\',
            \'status\' => \'1\',
            \'timestamp\' => \'1382453294\',
            \'uuid\' => \'2acbee53-5768-4644-9f03-0a6bb47bbb9d\',
            \'rdf_mapping\' => array(),
          ),
        ),
      ),
      \'field_place_event\' => array(
        \'und\' => array(
          array(
            \'value\' => \'New York City\',
            \'format\' => NULL,
            \'safe_value\' => \'New York City\',
          ),
        ),
      ),
      \'field_url_event\' => array(
        \'und\' => array(
          array(
            \'url\' => \'http://www.un.org/climatechange/summit2014/\',
            \'title\' => \'Website "Gateway to the United Nations systems work on Climate Change\',
            \'attributes\' => array(),
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
      \'last_comment_timestamp\' => \'1382453294\',
      \'last_comment_name\' => NULL,
      \'last_comment_uid\' => \'1\',
      \'comment_count\' => \'0\',
      \'name\' => \'admin\',
      \'picture\' => \'0\',
      \'data\' => \'b:0;\',
      \'path\' => FALSE,
      \'menu\' => NULL,
      \'node_export_drupal_version\' => \'7\',
    ),
  (object) array(
      \'vid\' => \'126\',
      \'uid\' => \'1\',
      \'title\' => \'International Conference on Regional Climate - CORDEX 2013\',
      \'log\' => \'\',
      \'status\' => \'1\',
      \'comment\' => \'1\',
      \'promote\' => \'1\',
      \'sticky\' => \'0\',
      \'vuuid\' => \'ccf1b39d-3b4c-4626-ba6f-b43c5c3eb0e3\',
      \'nid\' => \'126\',
      \'type\' => \'event\',
      \'language\' => \'und\',
      \'created\' => \'1382453294\',
      \'changed\' => \'1382453294\',
      \'tnid\' => \'0\',
      \'translate\' => \'0\',
      \'uuid\' => \'3697f547-a635-4f83-9265-35c7ab18cb93\',
      \'revision_timestamp\' => \'1382453294\',
      \'revision_uid\' => \'1\',
      \'body\' => array(
        \'und\' => array(
          array(
            \'value\' => "<h3>A partnership between WCRP, the European Commission and IPCC</h3>\\r\\n\\r\\nThe International Conference on Regional Climate - CORDEX 2013 brings together the international community of regional climate scientists to present and discuss results from WCRP regional climate studies, with a particular emphasis on the CORDEX initiative.\\r\\n\\r\\nThe first day of the meeting will feature two important pre-conference events: a High Level Session with the participation of the European Commissioners for Research & Innovation and for Climate Action where the Intergovernmental Panel on Climate Change (IPCC) presents key findings from the IPCC Working Group I contribution to the Fifth Assessment Report Climate Change 2013: The Physical Science Basis. This will be followed by a Stakeholder Dialogue focusing on how science-based regional climate information can best serve the needs of regional decision-makers. Both events are open to all the conference participants.\\r\\n\\r\\n- The second segment of the conference over the following three days is organized around the key scientific results from CORDEX Phase I. A discussion on future priority research areas for the next phase of CORDEX, of other WCRP regional climate initiatives and of major funding programmes – such as the EU FP7 and the future Horizon2020 - will also take place, taking into account the recommendations from the first segment of the conference. ",
            \'summary\' => \'\',
            \'format\' => \'filtered_html\',
            \'safe_value\' => "<h3>A partnership between WCRP, the European Commission and IPCC</h3>\\n<p>The International Conference on Regional Climate - CORDEX 2013 brings together the international community of regional climate scientists to present and discuss results from WCRP regional climate studies, with a particular emphasis on the CORDEX initiative.</p>\\n<p>The first day of the meeting will feature two important pre-conference events: a High Level Session with the participation of the European Commissioners for Research &amp; Innovation and for Climate Action where the Intergovernmental Panel on Climate Change (IPCC) presents key findings from the IPCC Working Group I contribution to the Fifth Assessment Report Climate Change 2013: The Physical Science Basis. This will be followed by a Stakeholder Dialogue focusing on how science-based regional climate information can best serve the needs of regional decision-makers. Both events are open to all the conference participants.</p>\\n<p>- The second segment of the conference over the following three days is organized around the key scientific results from CORDEX Phase I. A discussion on future priority research areas for the next phase of CORDEX, of other WCRP regional climate initiatives and of major funding programmes – such as the EU FP7 and the future Horizon2020 - will also take place, taking into account the recommendations from the first segment of the conference.</p>\\n",
            \'safe_summary\' => \'\',
          ),
        ),
      ),
      \'field_country_event\' => array(
        \'und\' => array(
          array(
            \'value\' => \'Belgium\',
            \'format\' => NULL,
            \'safe_value\' => \'Belgium\',
          ),
        ),
      ),
      \'field_date_event\' => array(
        \'und\' => array(
          array(
            \'value\' => \'2013-11-04 00:00:00\',
            \'value2\' => \'2013-11-07 00:00:00\',
            \'timezone\' => \'Europe/Berlin\',
            \'timezone_db\' => \'Europe/Berlin\',
            \'date_type\' => \'datetime\',
          ),
        ),
      ),
      \'field_image_event_logo\' => array(
        \'und\' => array(
          array(
            \'fid\' => \'37\',
            \'alt\' => NULL,
            \'title\' => NULL,
            \'width\' => \'170\',
            \'height\' => \'60\',
            \'uid\' => \'1\',
            \'filename\' => \'logo_cordex.jpg\',
            \'uri\' => \'public://events/logo_cordex.jpg\',
            \'filemime\' => \'image/jpeg\',
            \'filesize\' => \'41476\',
            \'status\' => \'1\',
            \'timestamp\' => \'1382453294\',
            \'uuid\' => \'7842cb39-215d-45db-9ec2-d738af72d1cb\',
            \'rdf_mapping\' => array(),
          ),
        ),
      ),
      \'field_place_event\' => array(
        \'und\' => array(
          array(
            \'value\' => \'Brussels\',
            \'format\' => NULL,
            \'safe_value\' => \'Brussels\',
          ),
        ),
      ),
      \'field_url_event\' => array(
        \'und\' => array(
          array(
            \'url\' => \'http://cordex2013.wcrp-climate.org\',
            \'title\' => \'Cordex website\',
            \'attributes\' => array(),
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
      \'last_comment_timestamp\' => \'1382453294\',
      \'last_comment_name\' => NULL,
      \'last_comment_uid\' => \'1\',
      \'comment_count\' => \'0\',
      \'name\' => \'admin\',
      \'picture\' => \'0\',
      \'data\' => \'b:0;\',
      \'path\' => FALSE,
      \'menu\' => NULL,
      \'node_export_drupal_version\' => \'7\',
    ),
  (object) array(
      \'vid\' => \'127\',
      \'uid\' => \'1\',
      \'title\' => \'The climate is changing\',
      \'log\' => \'\',
      \'status\' => \'1\',
      \'comment\' => \'1\',
      \'promote\' => \'1\',
      \'sticky\' => \'0\',
      \'vuuid\' => \'ac9b6214-9f51-4fae-9c2e-3d4ffc2b3ab0\',
      \'nid\' => \'127\',
      \'type\' => \'article_climatechange\',
      \'language\' => \'en\',
      \'created\' => \'1382453294\',
      \'changed\' => \'1382453294\',
      \'tnid\' => \'0\',
      \'translate\' => \'0\',
      \'uuid\' => \'3a44663d-c000-4b38-bd34-c4883d5b7442\',
      \'revision_timestamp\' => \'1382453294\',
      \'revision_uid\' => \'1\',
      \'body\' => array(
        \'und\' => array(
          array(
            \'value\' => "Global climate change has become a tangible reality. Already, climate change is having devastating effects on humankind and nature in many regions of the world. How can, and must, humankind respond to climate change? \\r\\n\\r\\nLorem ipsum dolor sit amet, consetetur sadipscing elitr, sed diam nonumy eirmod tempor invidunt ut labore et dolore magna aliquyam erat, sed diam voluptua. At vero eos et accusam et justo duo dolores et ea rebum. Stet clita kasd gubergren, no sea takimata sanctus est Lorem ipsum dolor sit amet. \\r\\n\\r\\nLorem ipsum dolor sit amet, consetetur sadipscing elitr, sed diam nonumy eirmod tempor invidunt ut labore et dolore magna aliquyam erat, sed diam voluptua. At vero eos et accusam et justo duo dolores et ea rebum. Stet clita kasd gubergren, no sea takimata sanctus est Lorem ipsum dolor sit amet.",
            \'summary\' => \'Global climate change has become a tangible reality. Already, climate change is having devastating effects on humankind and nature in many regions of the world. How can, and must, humankind respond to climate change?\',
            \'format\' => \'filtered_html\',
            \'safe_value\' => "<p>Global climate change has become a tangible reality. Already, climate change is having devastating effects on humankind and nature in many regions of the world. How can, and must, humankind respond to climate change? </p>\\n<p>Lorem ipsum dolor sit amet, consetetur sadipscing elitr, sed diam nonumy eirmod tempor invidunt ut labore et dolore magna aliquyam erat, sed diam voluptua. At vero eos et accusam et justo duo dolores et ea rebum. Stet clita kasd gubergren, no sea takimata sanctus est Lorem ipsum dolor sit amet. </p>\\n<p>Lorem ipsum dolor sit amet, consetetur sadipscing elitr, sed diam nonumy eirmod tempor invidunt ut labore et dolore magna aliquyam erat, sed diam voluptua. At vero eos et accusam et justo duo dolores et ea rebum. Stet clita kasd gubergren, no sea takimata sanctus est Lorem ipsum dolor sit amet.</p>\\n",
            \'safe_summary\' => "<p>Global climate change has become a tangible reality. Already, climate change is having devastating effects on humankind and nature in many regions of the world. How can, and must, humankind respond to climate change?</p>\\n",
          ),
        ),
      ),
      \'field_cc_image\' => array(
        \'und\' => array(
          array(
            \'fid\' => \'38\',
            \'alt\' => \'\',
            \'title\' => \'\',
            \'width\' => \'960\',
            \'height\' => \'249\',
            \'uid\' => \'1\',
            \'filename\' => \'polarbear.jpg\',
            \'uri\' => \'public://slides/polarbear.jpg\',
            \'filemime\' => \'image/jpeg\',
            \'filesize\' => \'88371\',
            \'status\' => \'1\',
            \'timestamp\' => \'1382453294\',
            \'uuid\' => \'ae7335b1-6b16-4ec1-9e89-0b9baf19c79f\',
            \'rdf_mapping\' => array(),
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
      \'last_comment_timestamp\' => \'1382453294\',
      \'last_comment_name\' => NULL,
      \'last_comment_uid\' => \'1\',
      \'comment_count\' => \'0\',
      \'name\' => \'admin\',
      \'picture\' => \'0\',
      \'data\' => \'b:0;\',
      \'path\' => FALSE,
      \'menu\' => NULL,
      \'node_export_drupal_version\' => \'7\',
    ),
  (object) array(
      \'vid\' => \'128\',
      \'uid\' => \'1\',
      \'title\' => \'COP19/CMP9 Warsaw 2013\',
      \'log\' => \'\',
      \'status\' => \'1\',
      \'comment\' => \'1\',
      \'promote\' => \'1\',
      \'sticky\' => \'0\',
      \'vuuid\' => \'130346c2-ef8c-418e-aa70-e1756cb09def\',
      \'nid\' => \'128\',
      \'type\' => \'event\',
      \'language\' => \'und\',
      \'created\' => \'1382453294\',
      \'changed\' => \'1382453294\',
      \'tnid\' => \'0\',
      \'translate\' => \'0\',
      \'uuid\' => \'3f5b056b-3d0e-4e9b-a9b8-e04ea63760c4\',
      \'revision_timestamp\' => \'1382453294\',
      \'revision_uid\' => \'1\',
      \'body\' => array(
        \'und\' => array(
          array(
            \'value\' => "Warsaw Climate Change Conference - November 2013\\r\\n\\r\\nThe 19th session of the Conference of the Parties to the UNFCCC and the 9th session of the Conference of the Parties serving as the Meeting of the Parties to the Kyoto Protocol will take place from 11 to 22 November. The conference will be held at the National Stadium in Warsaw, Poland. \\r\\n\\r\\nSource [http://unfccc.int ] ",
            \'summary\' => \'\',
            \'format\' => \'filtered_html\',
            \'safe_value\' => "<p>Warsaw Climate Change Conference - November 2013</p>\\n<p>The 19th session of the Conference of the Parties to the UNFCCC and the 9th session of the Conference of the Parties serving as the Meeting of the Parties to the Kyoto Protocol will take place from 11 to 22 November. The conference will be held at the National Stadium in Warsaw, Poland. </p>\\n<p>Source [<a href=\\"http://unfccc.int\\">http://unfccc.int</a> ]</p>\\n",
            \'safe_summary\' => \'\',
          ),
        ),
      ),
      \'field_country_event\' => array(
        \'und\' => array(
          array(
            \'value\' => \'Poland\',
            \'format\' => NULL,
            \'safe_value\' => \'Poland\',
          ),
        ),
      ),
      \'field_date_event\' => array(
        \'und\' => array(
          array(
            \'value\' => \'2013-11-11 00:00:00\',
            \'value2\' => \'2013-11-22 00:00:00\',
            \'timezone\' => \'Europe/Berlin\',
            \'timezone_db\' => \'Europe/Berlin\',
            \'date_type\' => \'datetime\',
          ),
        ),
      ),
      \'field_image_event_logo\' => array(
        \'und\' => array(
          array(
            \'fid\' => \'39\',
            \'alt\' => NULL,
            \'title\' => NULL,
            \'width\' => \'173\',
            \'height\' => \'173\',
            \'uid\' => \'1\',
            \'filename\' => \'cop19_logo_173.jpg\',
            \'uri\' => \'public://events/cop19_logo_173.jpg\',
            \'filemime\' => \'image/jpeg\',
            \'filesize\' => \'26338\',
            \'status\' => \'1\',
            \'timestamp\' => \'1382453294\',
            \'uuid\' => \'f9a2777d-cc99-42ba-9532-99b471d4859f\',
            \'rdf_mapping\' => array(),
          ),
        ),
      ),
      \'field_place_event\' => array(
        \'und\' => array(
          array(
            \'value\' => \'Warsaw\',
            \'format\' => NULL,
            \'safe_value\' => \'Warsaw\',
          ),
        ),
      ),
      \'field_url_event\' => array(
        \'und\' => array(
          array(
            \'url\' => \'http://unfccc.int\',
            \'title\' => \'\',
            \'attributes\' => array(),
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
      \'last_comment_timestamp\' => \'1382453294\',
      \'last_comment_name\' => NULL,
      \'last_comment_uid\' => \'1\',
      \'comment_count\' => \'0\',
      \'name\' => \'admin\',
      \'picture\' => \'0\',
      \'data\' => \'b:0;\',
      \'path\' => FALSE,
      \'menu\' => NULL,
      \'node_export_drupal_version\' => \'7\',
    ),
)',
);
  return $node_export;
}
