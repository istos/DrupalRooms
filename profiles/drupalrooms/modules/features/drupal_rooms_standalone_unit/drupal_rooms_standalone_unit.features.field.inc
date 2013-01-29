<?php
/**
 * @file
 * drupal_rooms_standalone_unit.features.field.inc
 */

/**
 * Implements hook_field_default_fields().
 */
function drupal_rooms_standalone_unit_field_default_fields() {
  $fields = array();

  // Exported field: 'rooms_unit-standard_unit-field_availability_calendar'.
  $fields['rooms_unit-standard_unit-field_availability_calendar'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_availability_calendar',
      'foreign keys' => array(
        'unit_id' => array(
          'columns' => array(
            'unit_id' => 'unit_id',
          ),
          'table' => 'rooms_units',
        ),
      ),
      'indexes' => array(
        'unit_id' => array(
          0 => 'unit_id',
        ),
      ),
      'locked' => '0',
      'module' => 'rooms_availability_reference',
      'settings' => array(
        'referenceable_booking_unit_types' => array(),
        'referenceable_unit_types' => array(
          'deluxe_unit' => 'deluxe_unit',
          'standard_unit' => 'standard_unit',
        ),
      ),
      'translatable' => '0',
      'type' => 'rooms_availability_reference',
    ),
    'field_instance' => array(
      'bundle' => 'standard_unit',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'rooms_availability_reference',
          'settings' => array(),
          'type' => 'rooms_availability_reference_default',
          'weight' => 2,
        ),
      ),
      'entity_type' => 'rooms_unit',
      'field_name' => 'field_availability_calendar',
      'label' => 'Availability Calendar',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 0,
        'module' => 'rooms_availability_reference',
        'settings' => array(
          'autocomplete_match' => 'contains',
          'autocomplete_path' => 'rooms_availability_reference/autocomplete',
          'size' => 60,
        ),
        'type' => 'rooms_availability_reference_autocomplete',
        'weight' => '3',
      ),
    ),
  );

  // Exported field: 'rooms_unit-standard_unit-field_description'.
  $fields['rooms_unit-standard_unit-field_description'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_description',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => '0',
      'module' => 'text',
      'settings' => array(),
      'translatable' => '0',
      'type' => 'text_long',
    ),
    'field_instance' => array(
      'bundle' => 'standard_unit',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => 1,
        ),
      ),
      'entity_type' => 'rooms_unit',
      'field_name' => 'field_description',
      'label' => 'Description',
      'required' => 0,
      'settings' => array(
        'text_processing' => '0',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'rows' => '5',
        ),
        'type' => 'text_textarea',
        'weight' => '2',
      ),
    ),
  );

  // Exported field: 'rooms_unit-standard_unit-field_images'.
  $fields['rooms_unit-standard_unit-field_images'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_images',
      'foreign keys' => array(
        'fid' => array(
          'columns' => array(
            'fid' => 'fid',
          ),
          'table' => 'file_managed',
        ),
      ),
      'indexes' => array(
        'fid' => array(
          0 => 'fid',
        ),
      ),
      'locked' => '0',
      'module' => 'image',
      'settings' => array(
        'default_image' => 0,
        'uri_scheme' => 'public',
      ),
      'translatable' => '0',
      'type' => 'image',
    ),
    'field_instance' => array(
      'bundle' => 'standard_unit',
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'image',
          'settings' => array(
            'image_link' => '',
            'image_style' => '',
          ),
          'type' => 'image',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'rooms_unit',
      'field_name' => 'field_images',
      'label' => 'Images',
      'required' => 0,
      'settings' => array(
        'alt_field' => 0,
        'default_image' => 0,
        'file_directory' => '',
        'file_extensions' => 'png gif jpg jpeg',
        'max_filesize' => '',
        'max_resolution' => '',
        'min_resolution' => '',
        'title_field' => 0,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'image',
        'settings' => array(
          'preview_image_style' => 'thumbnail',
          'progress_indicator' => 'throbber',
        ),
        'type' => 'image_image',
        'weight' => '1',
      ),
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Availability Calendar');
  t('Description');
  t('Images');

  return $fields;
}
