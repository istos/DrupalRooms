<?php

/**
 * Implements hook_form_FORM_ID_alter().
 *
 * Allows the profile to alter the site configuration form.
 */
function drupalrooms_form_install_configure_form_alter(&$form, $form_state) {
  // Pre-populate the site name with the server name.
  $form['site_information']['site_name']['#default_value'] = $_SERVER['SERVER_NAME'];
  
    // Set a default name for the dev site.
  $form['site_information']['site_name']['#default_value'] = t('Drupal Rooms');

  // Set a default country so I can benefit from it on Address Fields.
  $form['server_settings']['site_default_country']['#default_value'] = 'IT';

}
