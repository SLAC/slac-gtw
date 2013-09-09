<?php

/**
 * @file
 * Export mailchimp campaigns into views
 */


/**
 * Implements hook_views_data().
 */
function mailchimp_dc_views_data() {
  $data = array();

  $data['mailchimp_dc_campaign']['table']['group'] = t('Mailchimp Recurring Campaigns');
  $data['mailchimp_dc_campaign']['table']['base'] = array(
    'field' => 'mc_campaign_id',
    'title' => t('Mailchimp Recurring Campaigns'),
    'help' => t('The mailchimp campaign id'),
  );

  $data['mailchimp_dc_campaign']['mc_campaign_id'] = array(
    'title' => t('Mailchimp Campaign ID'),
    'help' => t('The mailchimp campaign id'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  
  $data['mailchimp_dc_campaign']['list_id'] = array(
    'title' => t('Mailchimp List ID'),
    'help' => t('The mailchimp list id'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  
  $data['mailchimp_dc_campaign']['title'] = array(
    'title' => t('Title'),
    'help' => t('The title of the mailing campaign'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  
  $data['mailchimp_dc_campaign']['archive_url'] = array(
    'title' => t('Archive URL'),
    'help' => t('The archive URL of the campaign'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  
  $data['mailchimp_dc_campaign']['from_name'] = array(
    'title' => t('From name'),
    'help' => t('The from name of the mailing campaign: i.e: John Doe.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  
  $data['mailchimp_dc_campaign']['from_email'] = array(
    'title' => t('From Email'),
    'help' => t('The from email of the mailing campaign'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  
  $data['mailchimp_dc_campaign']['subject'] = array(
    'title' => t('Subject'),
    'help' => t('The subject of the email'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  
  // handler should be a select filter??
  $data['mailchimp_dc_campaign']['status'] = array(
    'title' => t('Status'),
    'help' => t('The status of the email campaign'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  
  // Contains the machine name of the recurring campaign
  $data['mailchimp_dc_campaign']['recurring_campaign'] = array(
    'title' => t('Recurring Campaign'),
    'help' => t('The recurring campaign that generated this mailchimp campaign'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_recurring_campaign',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
    
  $data['mailchimp_dc_campaign']['created'] = array(
    'title' => t('Created date'),
    'help' => t('The date the mailing campaign was added.'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
  );
  
  $data['mailchimp_dc_campaign']['updated'] = array(
    'title' => t('Updated date'),
    'help' => t('The date the mailing campaign was updated.'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
  );
  
  $data['mailchimp_dc_campaign']['sent'] = array(
    'title' => t('Sent date'),
    'help' => t('The date the mailing campaign was sent.'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
  );
  
  return $data;
}