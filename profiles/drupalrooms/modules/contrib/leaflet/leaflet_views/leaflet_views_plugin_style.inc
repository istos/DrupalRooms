<?php

/**
 * @file
 * Extension of the Views Plugin Style for Leaflet Map
 * Adapted from the GeoField Map views module and the OpenLayers Views module.
 */
class leaflet_views_plugin_style extends views_plugin_style {

  /**
   * Set default options
   */
  function option_definition() {
    $options = parent::option_definition();
    $options['data_source'] = array('default' => '');
    $options['name_field'] = array('default' => '');
    $options['description_field'] = array('default' => '');
    $options['view_mode'] = array('default' => 'full');
    $options['map'] = array('default' => '');
    $options['height'] = array('default' => '400');
    return $options;
  }

  /**
   * Options form
   */
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    // Get list of fields in this view & flag available geodata fields
    $handlers = $this->display->handler->get_handlers('field');

    $fields = array();
    $fields_data = array();
    foreach ($handlers as $field_id => $handler) {
      $fields[$field_id] = $handler->ui_name();
      
      if (!empty($handler->field_info['type']) && $handler->field_info['type'] == 'geofield') {
        $fields_data[$field_id] = $handler->ui_name();
      }
    }
    
    // Check whether we have a geofield we can work with
    if (!count($fields_data)) {
      $form['error'] = array(
        '#markup' => t('Please add at least one geofield to the view'),
      );
      return;
    }

    // Map preset.
    $form['data_source'] = array(
      '#type' => 'select',
      '#title' => t('Data Source'),
      '#description' => t('Which field contains geodata?'),
      '#options' => $fields_data,
      '#default_value' => $this->options['data_source'],
      '#required' => TRUE,
    );
    
    // Name field
    $form['name_field'] = array(
      '#type' => 'select',
      '#title' => t('Title Field'),
      '#description' => t('Choose the field which will appear as a title on tooltips.'),
      // '#options' => $fields,
      '#options' => array_merge(array('' => ''), $fields),
      '#default_value' => $this->options['name_field'],
    );

    // Look for entity render modes - only support #node and #profile for the moment
    // @todo support all entities; we need then to rely on Entity API probably    
    $entity = NULL;
    switch ($this->view->base_table) {
      case 'node':
        $entity = 'node';
        break;
      case 'profile':
        $entity = 'profile2';
        break;
    }

    if ($entity) {
      $desc_options = array_merge(array(
        '' => '',
        '#' . $entity => '<' . t('!entity entity', array('!entity' => $entity)) . '>',
      ), $fields);
    }
    else {
      $desc_options = array_merge(array(
        '' => '',
      ), $fields);
    }

    $form['description_field'] = array(
      '#type' => 'select',
      '#title' => t('Description Content'),
      '#description' => t('Choose the field or rendering method which will appear as a description on tooltips or popups.'),
      '#required' => FALSE,
      '#options' => $desc_options,
      '#default_value' => $this->options['description_field'],
    );

    // Taken from openlayers_views_style_data::options_form().
    // Create view mode options
    if ($entity) {
      // Available_view_modes is the array to contain the avaible
      // view modes, for now this is not content type aware, but should be
      $available_view_modes = array();
      $entity_info = entity_get_info();

      // Get the machine names of the view modes
      $view_modes_machine_names[] = array_keys($entity_info[$entity]['view modes']);
      // Get the labels (human readable) of the view modes
      foreach ($entity_info[$entity]['view modes'] as $key => $view_mode) {
        $view_modes_labels[] = $view_mode['label'];
      }
      // Combine the machine view mode name with the label, this could sure be done much better?
      $entities_to_display = array_combine($view_modes_machine_names[0], $view_modes_labels);

      //output the form
      $form['view_mode'] = array(
        '#type' => 'select',
        '#title' => t('View mode'),
        '#description' => t('View modes are ways of displaying entities.'),
        '#options' => $entities_to_display,
        '#default_value' => !empty($this->options['view_mode']) ?
          $this->options['view_mode'] : 'full',
        '#states' => array(
          'visible' => array(
            ':input[name="style_options[description_field]"]' => array('value' => '#' . $entity),
          ),
        ),
      );
    }

    // Choose a map preset
    $map_options = array();
    foreach (leaflet_map_get_info() as $key => $map) {
      $map_options[$key] = t($map['label']);
    }

    $form['map'] = array(
      '#title' => t('Map'),
      '#type' => 'select',
      '#options' => $map_options,
      '#default_value' => $this->options['map'] ? $this->options['map'] : '',
      '#required' => TRUE,
    );

    $form['height'] = array(
      '#title' => t('Map height'),
      '#type' => 'textfield',
      '#field_suffix' => t('px'),
      '#size' => 4,
      '#default_value' => $this->options['height'],
      '#required' => FALSE,
    );
  }

  /**
   * Validate the options form.
   */
  function options_validate(&$form, &$form_state) {
    if (!is_numeric($form_state['values']['style_options']['height']) || $form_state['values']['style_options']['height'] < 0) {
      form_error($form['height'], t('Map height needs to be a positive number'));
    }
  }

  /**
   * Renders view
   */
  function render() {
    if (!empty($this->view->live_preview)) {
      return t('No preview available');
    }
    
    $data = array();
    
    if ($this->options['data_source']) {
      $this->render_fields($this->view->result);

      foreach ($this->view->result as $id => $result) {
        $data_source_field = 'field_' . $this->options['data_source'];
        $geofield = (!empty($result->$data_source_field)) ? $result->$data_source_field : NULL;

        if (!empty($geofield)) {
          // Handle rendering of a node view     
          if ($this->options['description_field'] === '#node' && is_object($result) && isset($result->nid)) {          
            $build = node_view(node_load($result->nid), $this->options['view_mode']);
            $description = drupal_render($build);
          }

          // Handle rendering of a profile2 view
          else if ($this->options['description_field'] === '#profile2' && is_object($result) && isset($result->pid)) { 
            $build = entity_view('profile2', array(profile2_load($result->pid)), $this->options['view_mode']);
            $description = drupal_render($build);
          }
        
          // Normal rendering via fields
          else if($this->options['description_field']) {
            $description = $this->rendered_fields[$id][$this->options['description_field']];
          }
          
          $raw_data = array();
          foreach ($geofield as $item) {
            $raw_data[] = $item['raw'];
          }
          $points = leaflet_process_geofield($raw_data);
          
          // Attach pop-ups if we have a description field
          if (isset($description)) {
            array_walk($points, create_function('&$p,$i,$t', '$p[\'popup\'] = $t;'), $description);
          }
          
          $data = array_merge($data, $points);
        }
      }
      
      $map = leaflet_map_get_info($this->options['map']);
      return leaflet_render_map($map, $data, $this->options['height'] . 'px');
    }
    
    return '';
  }
}
