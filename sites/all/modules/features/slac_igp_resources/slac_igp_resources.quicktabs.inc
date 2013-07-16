<?php
/**
 * @file
 * slac_igp_resources.quicktabs.inc
 */

/**
 * Implements hook_quicktabs_default_quicktabs().
 */
function slac_igp_resources_quicktabs_default_quicktabs() {
  $export = array();

  $quicktabs = new stdClass();
  $quicktabs->disabled = FALSE; /* Edit this to true to make a default quicktabs disabled initially */
  $quicktabs->api_version = 1;
  $quicktabs->machine_name = 'staff_resources';
  $quicktabs->ajax = 0;
  $quicktabs->hide_empty_tabs = FALSE;
  $quicktabs->default_tab = 0;
  $quicktabs->title = 'Staff Resources';
  $quicktabs->tabs = array(
    0 => array(
      'vid' => 'staff_resources_classic',
      'display' => 'block_4',
      'args' => '',
      'title' => 'Top Links',
      'weight' => '-100',
      'type' => 'view',
    ),
    1 => array(
      'vid' => 'staff_resources_classic',
      'display' => 'block_2',
      'args' => 'Central Services',
      'title' => 'Central Services',
      'weight' => '-99',
      'type' => 'view',
    ),
    2 => array(
      'vid' => 'staff_resources_classic',
      'display' => 'block_2',
      'args' => 'Helpful Resources',
      'title' => 'Helpful Resources',
      'weight' => '-98',
      'type' => 'view',
    ),
    3 => array(
      'vid' => 'staff_resources_classic',
      'display' => 'block_2',
      'args' => 'HR Services & Benefits',
      'title' => 'HR Services & Benefits',
      'weight' => '-97',
      'type' => 'view',
    ),
    4 => array(
      'vid' => 'staff_resources_classic',
      'display' => 'block_2',
      'args' => 'Life at SLAC',
      'title' => 'Life at SLAC',
      'weight' => '-96',
      'type' => 'view',
    ),
    5 => array(
      'vid' => 'staff_resources_classic',
      'display' => 'block_2',
      'args' => ' Policies & Procedures',
      'title' => 'Policies & Procedures',
      'weight' => '-95',
      'type' => 'view',
    ),
    6 => array(
      'vid' => 'staff_resources_classic',
      'display' => 'block_2',
      'args' => 'Safety & Training',
      'title' => 'Safety & Training',
      'weight' => '-94',
      'type' => 'view',
    ),
  );
  $quicktabs->renderer = 'quicktabs';
  $quicktabs->style = 'nostyle';
  $quicktabs->options = array();

  // Translatables
  // Included for use with string extractors like potx.
  t('Central Services');
  t('HR Services & Benefits');
  t('Helpful Resources');
  t('Life at SLAC');
  t('Policies & Procedures');
  t('Safety & Training');
  t('Staff Resources');
  t('Top Links');

  $export['staff_resources'] = $quicktabs;

  $quicktabs = new stdClass();
  $quicktabs->disabled = FALSE; /* Edit this to true to make a default quicktabs disabled initially */
  $quicktabs->api_version = 1;
  $quicktabs->machine_name = 'staff_resources_mobile_';
  $quicktabs->ajax = 0;
  $quicktabs->hide_empty_tabs = FALSE;
  $quicktabs->default_tab = 0;
  $quicktabs->title = 'Staff Resources (Mobile)';
  $quicktabs->tabs = array(
    0 => array(
      'vid' => 'staff_resources_classic',
      'display' => 'block_4',
      'args' => '',
      'title' => 'Top Links',
      'weight' => '-100',
      'type' => 'view',
    ),
    1 => array(
      'vid' => 'staff_resources_classic',
      'display' => 'block_2',
      'args' => 'Central Services',
      'title' => 'Central Services',
      'weight' => '-99',
      'type' => 'view',
    ),
    2 => array(
      'vid' => 'staff_resources_classic',
      'display' => 'block_2',
      'args' => 'Helpful Resources',
      'title' => 'Helpful Resources',
      'weight' => '-98',
      'type' => 'view',
    ),
    3 => array(
      'vid' => 'staff_resources_classic',
      'display' => 'block_2',
      'args' => 'HR Services & Benefits',
      'title' => 'HR Services & Benefits',
      'weight' => '-97',
      'type' => 'view',
    ),
    4 => array(
      'vid' => 'staff_resources_classic',
      'display' => 'block_2',
      'args' => 'Life at SLAC',
      'title' => 'Life at SLAC',
      'weight' => '-96',
      'type' => 'view',
    ),
    5 => array(
      'vid' => 'staff_resources_classic',
      'display' => 'block_2',
      'args' => ' Policies & Procedures',
      'title' => 'Policies & Procedures',
      'weight' => '-95',
      'type' => 'view',
    ),
    6 => array(
      'vid' => 'staff_resources_classic',
      'display' => 'block_2',
      'args' => 'Safety & Training',
      'title' => 'Safety & Training',
      'weight' => '-94',
      'type' => 'view',
    ),
  );
  $quicktabs->renderer = 'accordion';
  $quicktabs->style = 'nostyle';
  $quicktabs->options = array(
    'history' => 0,
    'jquery_ui' => array(
      'autoHeight' => 0,
      'collapsible' => 1,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Central Services');
  t('HR Services & Benefits');
  t('Helpful Resources');
  t('Life at SLAC');
  t('Policies & Procedures');
  t('Safety & Training');
  t('Staff Resources (Mobile)');
  t('Top Links');

  $export['staff_resources_mobile_'] = $quicktabs;

  return $export;
}
