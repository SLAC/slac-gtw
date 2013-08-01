<?php
/**
 * @file
 * Code for the mailchimp dc module
 */
 
/**
 * Save function that rules them all
 *
 * @params
 * (array) $record    an associative array key = db table field name, value = field value
 * (string) $pk       primary key field
 * (string) $table    table name
 */
function mailchimp_dc_record_save($record, $pk, $table) {
  $existing = mailchimp_dc_record_load($pk, $record[$pk], $table);
  if (!empty($existing)) {
    drupal_write_record($table, $record, $pk);
  }
  else {
    drupal_write_record($table, $record);
  }
}

/**
 * Load function that rules them all
 * (string) $pk       primary key field
 * (string) $value    primary key field value
 * (string) $table    table name
 */
function mailchimp_dc_record_load($pk, $value, $table) {
  $data = array();
  $query = db_select($table, 't')
  ->fields('t')
  ->condition($pk, $value);
  
  $result = $query->execute();
  $data = $result->fetchAssoc();

  return $data;  
}

/**
 * Delete a database record
 * (string) $pk       primary key field
 * (string) $value    primary key field value
 * (string) $table    table name 
 */
function mailchimp_dc_record_delete($pk, $value, $table) {
  $query = db_delete($table)
  ->condition($pk, $value);
  $query->execute();  
} 

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
 * Load
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