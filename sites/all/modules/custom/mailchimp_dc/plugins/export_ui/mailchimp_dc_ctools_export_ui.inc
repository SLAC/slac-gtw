<?php
/**
 * @file
 * Code for the mailchimp dc module
 */

/**
 * Define this Export UI plugin.
 */
$plugin = array(
  'schema' => 'mailchimp_dc_config',  // As defined in hook_schema().
  'access' => 'administer mailchimp campaigns',  // Define a permission users must have to access these pages.

  // Define the menu item.
  'menu' => array(
    'menu item' => 'admin/config/services/mailchimp/mcdc',
    'menu title' => 'Manage recurring campaigns',
    'menu description' => 'Manage recurring campaigns',
  ),

  // Define user interface texts.
  'title singular' => t('recurring campaign'),
  'title plural' => t('recurring campaigns'),
  'title singular proper' => t('Mailchimp recurring campaign'),
  'title plural proper' => t('Mailchimp recurring campaigns'),

  // Define the names of the functions that provide the add/edit forms.
  'form' => array(
    'settings' => 'mailchimp_dc_ctools_export_ui_form',
    // 'submit' and 'validate' are also valid callbacks.
  ),
);


/**
 * Define the preset add/edit form.
 */
function mailchimp_dc_ctools_export_ui_form(&$form, &$form_state) {
  $preset = $form_state['item'];

  $form['description'] = array(
    '#type' => 'textfield',
    '#title' => t('Description'),
    '#description' => t('The human readable name or description of this preset.'),
    // '#default_value' => $preset->description,
    '#required' => true,
  );

  // Add Mymodule's configuration interface.
  $form['mydata'] = array(
    '#type' => 'textfield',
    '#title' => t('Mymodule configuration'),
    '#description' => t('This is just the simplest possible example of a configuration interface.'),
    // '#default_value' => $preset->mydata,
    '#required' => true,
  );

}
