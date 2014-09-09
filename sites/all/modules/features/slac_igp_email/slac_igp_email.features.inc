<?php
/**
 * @file
 * slac_igp_email.features.inc
 */

/**
 * Implements hook_views_api().
 */
function slac_igp_email_views_api() {
  return array("api" => "3.0");
}

/**
 * Implements hook_eck_bundle_info().
 */
function slac_igp_email_eck_bundle_info() {
  $items = array(
    'campaign_news_campaign_news' => array(
      'machine_name' => 'campaign_news_campaign_news',
      'entity_type' => 'campaign_news',
      'name' => 'campaign_news',
      'label' => 'Campaign news',
    ),
  );
  return $items;
}

/**
 * Implements hook_eck_entity_type_info().
 */
function slac_igp_email_eck_entity_type_info() {
  $items = array(
    'campaign_news' => array(
      'name' => 'campaign_news',
      'label' => 'Campaign news',
      'properties' => array(
        'created' => array(
          'label' => 'Created',
          'type' => 'integer',
          'behavior' => 'created',
        ),
        'changed' => array(
          'label' => 'Changed',
          'type' => 'integer',
          'behavior' => 'changed',
        ),
      ),
    ),
  );
  return $items;
}
