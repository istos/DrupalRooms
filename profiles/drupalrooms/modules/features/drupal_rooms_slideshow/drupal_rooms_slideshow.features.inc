<?php
/**
 * @file
 * drupal_rooms_slideshow.features.inc
 */

/**
 * Implements hook_views_api().
 */
function drupal_rooms_slideshow_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function drupal_rooms_slideshow_node_info() {
  $items = array(
    'slide' => array(
      'name' => t('Slide'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
