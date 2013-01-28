<?php
/**
 * @file
 * drupal_rooms_location.features.inc
 */

/**
 * Implements hook_node_info().
 */
function drupal_rooms_location_node_info() {
  $items = array(
    'location' => array(
      'name' => t('Location'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
