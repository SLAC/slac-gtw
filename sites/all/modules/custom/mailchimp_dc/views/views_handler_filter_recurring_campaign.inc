<?php

/**
 * @file
 * Definition of views_handler_filter_node_type.
 */

/**
 * Filter by node type.
 *
 * @ingroup views_filter_handlers
 */
class views_handler_filter_recurring_campaign extends views_handler_filter_in_operator {
  function get_value_options() {
    if (!isset($this->value_options)) {
      $this->value_title = t('Recurring campaigns');
      module_load_include('inc', 'mailchimp_dc', 'mailchimp_dc.database');
      $configs = mailchimp_dc_config_load_all();
      $options = array();
      foreach ($configs as $config) {
        $options[$config['name']] = $config['label'];
      }
      asort($options);
      $this->value_options = $options;
    }
  }
}
