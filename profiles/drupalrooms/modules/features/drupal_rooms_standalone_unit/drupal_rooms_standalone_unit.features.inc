<?php
/**
 * @file
 * drupal_rooms_standalone_unit.features.inc
 */

/**
 * Implements hook_default_rooms_unit_type().
 */
function drupal_rooms_standalone_unit_default_rooms_unit_type() {
  $items = array();
  $items['deluxe_unit'] = entity_import('rooms_unit_type', '{
    "type" : "deluxe_unit",
    "label" : "Deluxe Room",
    "weight" : "0",
    "data" : {
      "base_price" : 200,
      "sleeps" : 2
    },
    "rdf_mapping" : []
  }');
  $items['standard_unit'] = entity_import('rooms_unit_type', '{
    "type" : "standard_unit",
    "label" : "Standard Room",
    "weight" : "0",
    "data" : {
      "base_price" : 100,
      "sleeps" : 2
    },
    "rdf_mapping" : []
  }');
  return $items;
}
