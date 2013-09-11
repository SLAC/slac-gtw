<?php
/**
 * @file
 * VBO action code for the mailchimp dc module
 */
 
/**
 * Implements hook_action_info
 */
function mailchimp_dc_action_info() {
  return array(
    'mailchimp_dc_action_add_content' => array(
      'label' => t('Add to Mailchimp campaign'),
      'type' => 'node',
      'configurable' => FALSE,
      'vbo_configurable' => TRUE,
      'triggers' => array('any'),
    ),
  );  
}

/**
 * Action callback
 */
function mailchimp_dc_action_add_content($entity, $context) {
  // add this content item as mailchimp filter style into the campaign
  // 1. load the campaign
  // 2. get the content from the specific section
  // 3. append the content as standard entity|teaser
  $campaign = mailchimp_campaign_load($context['mc_campaign']);
  if (empty($campaign)) {
    return;
  }
  if (array_key_exists('html_' . $context['mc_template'], $campaign->template)) {
    $content = "\n";
    $content .= '<div class="item">';
    $content .= '[mailchimp_campaign|entity_type=node|entity_id=' . $entity->nid . '|view_mode=' . $context['mc_view_mode'] . ']';
    $content .= '</div>';
    $campaign->template['html_' . $context['mc_template']]['value'] .= $content;
  }
  $options = array(
    'title' => $campaign->mc_data['title'],
    'subject' => $campaign->mc_data['subject'],
    'list_id' => $campaign->list['id'],
    'from_email' => $campaign->mc_data['from_email'],
    'from_name' => $campaign->mc_data['from_name'],
    'template_id' => $campaign->mc_template['id'],
  );
  mailchimp_campaign_save_campaign($campaign->template, $options, $campaign->mc_campaign_id);
  cache_clear_all('mailchimp_campaign_campaigns', 'cache');
}

/**
 * VBO Action configuration form
 */
function mailchimp_dc_action_add_content_form($context, &$form_state) {
  $form['#attached']['css'] = array(
    drupal_get_path('module', 'mailchimp_dc') . '/mailchimp_dc_action.css',
  );

  // load all of the campaigns (that are not sent)
  module_load_include('inc','mailchimp_dc', 'mailchimp_dc.database');
  $campaigns = mailchimp_campaign_load_multiple();
  $options = array(); //array('' => t('--Please select--'));
  if (!empty($campaigns)) {
    foreach($campaigns as $campaign_id => $campaign) {
      if ($campaign->mc_data['status'] === 'save') {
        $local_record = mailchimp_dc_record_load('mc_campaign_id', $campaign_id, 'mailchimp_dc_campaign');
        $row = array(
          array('data' => l($local_record['subject'], 'admin/config/services/mailchimp/campaigns/' . $campaign_id, array('attributes' => array('target' => '_blank'))), 'width' => '30%'),
          array('data' => $local_record['recurring_campaign'], 'width' => '30%'),
          array('data' => date('Y-m-d', $local_record['created']), 'width' => '20%'),
          array('data' => l('View', $local_record['archive_url'], array('attributes' => array('target' => '_blank'))), 'width' => '20%'),
        );
        $options[$campaign_id] = theme('table', array('header' => array(), 'rows' => array($row)));
      }
    }
  }
  
  $form['mc_campaign'] = array(
    '#type' => 'radios',
    '#title' => t('Mailchimp Campaign (Subject, Recurring Campaign, Date Created, Archive Link)'),
    '#description' => t('Please choose the campaign this content should be added to'),
    '#options' => $options,
    '#ajax' => array(
      'callback' => 'mailchimp_dc_action_add_content_form_ajax_callback',
      'wrapper' => 'mc_template',
     ),
     '#required' => TRUE,
  );
  
  $template_regions = array();
  if (!empty($form_state['values']['mc_campaign'])) {
    $template_regions = $campaigns[$form_state['values']['mc_campaign']]->mc_template['info']['sections'];
    $template_regions = array_combine($template_regions, $template_regions); 
    // exclude some standard sections
    foreach ($template_regions as $key => $value) {
      if (substr($value, 0, 4) === 'std_') {
        unset($template_regions[$key]);
      }
    }
  }
  
  // template region in which the story should be added to
  $form['mc_template'] = array(
    '#type' => 'select',
    '#title' => t('Template Region'),
    '#options' => $template_regions,
    '#description' => t('Please select the template region this news article should go into'),
    '#prefix' => '<div id="mc_template">',
    '#suffix' => '</div>',
    '#required' => TRUE,
  );
  
  // view modes
  $entity_info = entity_get_info($context['entity_type']);
  $options = array();
  
  // exclude some view mode that doesn't need to appear
  $exclude = array('rss', 'search_index', 'search_result', 'diff_standard');
  if (!empty($entity_info['view modes'])) {
    foreach ($entity_info['view modes'] as $view_mode => $info) {
      if (in_array($view_mode, $exclude)) {
        continue;
      }
      $options[$view_mode] = $info['label'];
    } 
  }
  $form['mc_view_mode'] = array(
    '#type' => 'select',
    '#title' => t('View mode'),
    '#options' => $options,
  );
  
  return $form;
}

/**
 * Form submission callback
 */
function mailchimp_dc_action_add_content_submit($form, &$form_state) {
  return array(
    'mc_campaign' => $form_state['values']['mc_campaign'],
    'mc_template' => $form_state['values']['mc_template'],
    'mc_view_mode' => $form_state['values']['mc_view_mode'],
  );
}

/**
 * Ajax callback
 */
function mailchimp_dc_action_add_content_form_ajax_callback($form, $form_state) {
  return $form['mc_template'];
}