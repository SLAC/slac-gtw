<?php

/**
 * @file
 * Export mailchimp campaigns to views.
 */
function mailchimp_dc_views_default_views() {
  
  $view = new view();
  $view->name = 'mailchimp_campaigns';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'mailchimp_dc_campaign';
  $view->human_name = 'Mailchimp Campaigns';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  
  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Mailchimp Campaigns';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'administer mailchimp campaigns';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['style_plugin'] = 'table';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = '<div class="messages warning">There are no campaigns created yet, please add a new campaign first.</div>';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Field: Mailchimp Recurring Campaigns: Mailchimp Campaign ID */
  $handler->display->display_options['fields']['mc_campaign_id']['id'] = 'mc_campaign_id';
  $handler->display->display_options['fields']['mc_campaign_id']['table'] = 'mailchimp_dc_campaign';
  $handler->display->display_options['fields']['mc_campaign_id']['field'] = 'mc_campaign_id';
  $handler->display->display_options['fields']['mc_campaign_id']['label'] = '';
  $handler->display->display_options['fields']['mc_campaign_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['mc_campaign_id']['element_label_colon'] = FALSE;
  /* Field: Mailchimp Recurring Campaigns: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'mailchimp_dc_campaign';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  /* Field: Mailchimp Recurring Campaigns: Subject */
  $handler->display->display_options['fields']['subject']['id'] = 'subject';
  $handler->display->display_options['fields']['subject']['table'] = 'mailchimp_dc_campaign';
  $handler->display->display_options['fields']['subject']['field'] = 'subject';
  /* Field: Mailchimp Recurring Campaigns: Status */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'mailchimp_dc_campaign';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  /* Field: Mailchimp Recurring Campaigns: Created date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'mailchimp_dc_campaign';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Created';
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'Y-m-d';
  /* Field: Mailchimp Recurring Campaigns: Archive URL */
  $handler->display->display_options['fields']['archive_url']['id'] = 'archive_url';
  $handler->display->display_options['fields']['archive_url']['table'] = 'mailchimp_dc_campaign';
  $handler->display->display_options['fields']['archive_url']['field'] = 'archive_url';
  $handler->display->display_options['fields']['archive_url']['label'] = '';
  $handler->display->display_options['fields']['archive_url']['exclude'] = TRUE;
  $handler->display->display_options['fields']['archive_url']['element_label_colon'] = FALSE;
  /* Field: View Archive */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'View Archive';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'View Archive';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['path'] = '[archive_url]';
  $handler->display->display_options['fields']['nothing']['alter']['external'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['target'] = '_blank';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: View */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['ui_name'] = 'View';
  $handler->display->display_options['fields']['nothing_1']['label'] = '';
  $handler->display->display_options['fields']['nothing_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = 'View';
  $handler->display->display_options['fields']['nothing_1']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing_1']['alter']['path'] = 'admin/config/services/mailchimp/campaigns/[mc_campaign_id]';
  $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_2']['id'] = 'nothing_2';
  $handler->display->display_options['fields']['nothing_2']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_2']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_2']['label'] = 'Actions';
  $handler->display->display_options['fields']['nothing_2']['alter']['text'] = '[nothing] | [nothing_1]';
  /* Sort criterion: Mailchimp Recurring Campaigns: Created date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'mailchimp_dc_campaign';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Mailchimp Recurring Campaigns: Status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'mailchimp_dc_campaign';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Status';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['is_grouped'] = TRUE;
  $handler->display->display_options['filters']['status']['group_info']['label'] = 'Status';
  $handler->display->display_options['filters']['status']['group_info']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['group_info']['group_items'] = array(
    1 => array(
      'title' => 'Saved',
      'operator' => '=',
      'value' => 'save',
    ),
    2 => array(
      'title' => 'Sent',
      'operator' => '=',
      'value' => 'sent',
    ),
    3 => array(
      'title' => '',
      'operator' => '=',
      'value' => '',
    ),
  );
  /* Filter criterion: Mailchimp Recurring Campaigns: Created date */
  $handler->display->display_options['filters']['created']['id'] = 'created';
  $handler->display->display_options['filters']['created']['table'] = 'mailchimp_dc_campaign';
  $handler->display->display_options['filters']['created']['field'] = 'created';
  $handler->display->display_options['filters']['created']['operator'] = 'between';
  $handler->display->display_options['filters']['created']['value']['type'] = 'offset';
  $handler->display->display_options['filters']['created']['exposed'] = TRUE;
  $handler->display->display_options['filters']['created']['expose']['operator_id'] = 'created_op';
  $handler->display->display_options['filters']['created']['expose']['label'] = 'Created date';
  $handler->display->display_options['filters']['created']['expose']['description'] = 'Enter values such as -30 days';
  $handler->display->display_options['filters']['created']['expose']['operator'] = 'created_op';
  $handler->display->display_options['filters']['created']['expose']['identifier'] = 'created';
  $handler->display->display_options['filters']['created']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['created']['is_grouped'] = TRUE;
  $handler->display->display_options['filters']['created']['group_info']['label'] = 'Created date';
  $handler->display->display_options['filters']['created']['group_info']['identifier'] = 'created';
  $handler->display->display_options['filters']['created']['group_info']['group_items'] = array(
    1 => array(
      'title' => 'Last 30 days',
      'operator' => 'between',
      'value' => array(
        'type' => 'offset',
        'value' => '',
        'min' => '-30 days',
        'max' => 'now +1 day',
      ),
    ),
    2 => array(
      'title' => 'Last 60 days',
      'operator' => 'between',
      'value' => array(
        'type' => 'offset',
        'value' => '',
        'min' => '- 60 days',
        'max' => 'now + 1 day',
      ),
    ),
    3 => array(
      'title' => 'Last 6 month (180 days)',
      'operator' => 'between',
      'value' => array(
        'type' => 'offset',
        'value' => '',
        'min' => '- 180 days',
        'max' => 'now + 1 day',
      ),
    ),
  );
  /* Filter criterion: Mailchimp Recurring Campaigns: Recurring Campaign */
  $handler->display->display_options['filters']['recurring_campaign']['id'] = 'recurring_campaign';
  $handler->display->display_options['filters']['recurring_campaign']['table'] = 'mailchimp_dc_campaign';
  $handler->display->display_options['filters']['recurring_campaign']['field'] = 'recurring_campaign';
  $handler->display->display_options['filters']['recurring_campaign']['exposed'] = TRUE;
  $handler->display->display_options['filters']['recurring_campaign']['expose']['operator_id'] = 'recurring_campaign_op';
  $handler->display->display_options['filters']['recurring_campaign']['expose']['label'] = 'Recurring Campaign';
  $handler->display->display_options['filters']['recurring_campaign']['expose']['operator'] = 'recurring_campaign_op';
  $handler->display->display_options['filters']['recurring_campaign']['expose']['identifier'] = 'recurring_campaign';
  $handler->display->display_options['filters']['recurring_campaign']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  
  /* Display: Mailchimp Campaigns */
  $handler = $view->new_display('block', 'Mailchimp Campaigns', 'main');

  $views['mailchimp_campaigns'] = $view; 
  return $views;  
}