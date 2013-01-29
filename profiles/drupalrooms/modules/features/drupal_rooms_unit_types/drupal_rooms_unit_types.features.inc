<?php
/**
 * @file
 * drupal_rooms_unit_types.features.inc
 */

/**
 * Implements hook_node_info().
 */
function drupal_rooms_unit_types_node_info() {
  $items = array(
    'drupal_rooms_standalone_unit' => array(
      'name' => t('Drupal Rooms Standalone Unit'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
