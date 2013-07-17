<?php
/**
 * @file
 * Code for the mailchimp dc module
 */

/**
 * Saves a recurring campaign configuration
 */
function mailchimp_dc_config_save($record) {
  $config = mailchimp_dc_config_load($record['name']);
  if (!empty($config)) {
    drupal_write_record('mailchimp_dc_config', $record, 'name');  
  } 
  else {
    drupal_write_record('mailchimp_dc_config', $record);
  } 
}

/**
 * Loads a recurring campaign configuration
 */
function mailchimp_dc_config_load($machine_name) {
  
  $data = array();
  $query = db_select('mailchimp_dc_config', 'm')
  ->fields('m')
  ->condition('name', $machine_name);

  $result = $query->execute();
  $data = $result->fetchAssoc();

  return $data;  
}

/**
 * Loads recurring campaign configuration
 */
function mailchimp_dc_config_load_all($conditions = array()) {
  $data = array();
  $query = db_select('mailchimp_dc_config', 'm')
  ->fields('m');
  
  if (!empty($conditions)) {
    foreach($conditions as $condition) {
      if (!array_key_exists('operator', $condition)) {
        $condition['operator'] = '=';  
      }
      $query->condition($condition['field'], $condition['value'], $condition['operator']);
    }  
  }
  $result = $query->execute();
  while($record = $result->fetchAssoc()) {
    $data[] = $record;  
  }

  return $data;    
}

/**
 * Delete a daily campaign record
 */
function mailchimp_dc_config_delete($machine_name) {
  $query = db_delete('mailchimp_dc_config')
  ->condition('name', $machine_name);
  $query->execute();
}

/**
 * Save daily campaign record
 */
function mailchimp_dc_save_dc($campaign_id, $config_name) {
  $existing = mailchimp_dc_load_dc(date('Y-m-d'));
  if (!empty($existing)) {
    return;
  }
  
  $record = array(
    'date' => date('Y-m-d'),
    'timestamp' => REQUEST_TIME,
    'created' => 1,
    'name' => $config_name,
  );
  
  $record['mc_campaign_id'] = $campaign_id;
  
  drupal_write_record('mailchimp_dc', $record);
}

/**
 * Load recurring campaign record
 */
function mailchimp_dc_load_dc($name, $date = NULL) {
  $data = array();
  $query = db_select('mailchimp_dc', 'm')
  ->fields('m')
  ->condition('name', $name);
  if (isset($date)) {
    if (is_array($date)) {
      $query->condition('date', $date, 'BETWEEN');
    }
    else {
      $query->condition('date', $date);
    }
  }
  $results = $query->execute();
  foreach ($results as $result) {
    $data[] = (array) $result;
  }
  return (!empty($data)) ? $data[0] : array(); 
}

/**
 * Delete a daily campaign record
 */
function mailchimp_dc_delete_dc($campaign_id) {
  $query = db_delete('mailchimp_dc')
  ->condition('mc_campaign_id', $campaign_id);
  $query->execute();
}
