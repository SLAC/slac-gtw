<?php
/**
 * @file
 * ledger_progress_complete.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function ledger_progress_complete_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'ledger_front_list';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'ledger-front-list';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = '<none>';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_progress_state_1',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['row_class'] = 'ledger-row';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['wrapper_class'] = 'item-list-ledger';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Progress State */
  $handler->display->display_options['fields']['field_progress_state']['id'] = 'field_progress_state';
  $handler->display->display_options['fields']['field_progress_state']['table'] = 'field_data_field_progress_state';
  $handler->display->display_options['fields']['field_progress_state']['field'] = 'field_progress_state';
  $handler->display->display_options['fields']['field_progress_state']['label'] = '';
  $handler->display->display_options['fields']['field_progress_state']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_progress_state']['alter']['text'] = '[field_progress_state]';
  $handler->display->display_options['fields']['field_progress_state']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_progress_state']['type'] = 'list_key';
  /* Field: Content: Progress State */
  $handler->display->display_options['fields']['field_progress_state_1']['id'] = 'field_progress_state_1';
  $handler->display->display_options['fields']['field_progress_state_1']['table'] = 'field_data_field_progress_state';
  $handler->display->display_options['fields']['field_progress_state_1']['field'] = 'field_progress_state';
  $handler->display->display_options['fields']['field_progress_state_1']['label'] = '';
  $handler->display->display_options['fields']['field_progress_state_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_progress_state_1']['element_label_colon'] = FALSE;
  /* Field: Field: Link */
  $handler->display->display_options['fields']['field_link']['id'] = 'field_link';
  $handler->display->display_options['fields']['field_link']['table'] = 'field_data_field_link';
  $handler->display->display_options['fields']['field_link']['field'] = 'field_link';
  $handler->display->display_options['fields']['field_link']['label'] = '';
  $handler->display->display_options['fields']['field_link']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_link']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['field_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_link']['type'] = 'link_absolute';
  $handler->display->display_options['fields']['field_link']['delta_offset'] = '0';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '<a href="[field_file]">[title]</a>';
  $handler->display->display_options['fields']['title']['alter']['path'] = '[field_file] ';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: File */
  $handler->display->display_options['fields']['field_file']['id'] = 'field_file';
  $handler->display->display_options['fields']['field_file']['table'] = 'field_data_field_file';
  $handler->display->display_options['fields']['field_file']['field'] = 'field_file';
  $handler->display->display_options['fields']['field_file']['label'] = '';
  $handler->display->display_options['fields']['field_file']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_file']['alter']['text'] = '[title]';
  $handler->display->display_options['fields']['field_file']['alter']['path'] = '/files/ledgers/[field_file]';
  $handler->display->display_options['fields']['field_file']['alter']['alt'] = '[title]';
  $handler->display->display_options['fields']['field_file']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_file']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_file']['type'] = 'file_url_plain';
  $handler->display->display_options['fields']['field_file']['settings'] = array(
    'text' => '[field_file]',
  );
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[title]';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['path'] = '[field_file]';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Progress State (field_progress_state) */
  $handler->display->display_options['sorts']['field_progress_state_value']['id'] = 'field_progress_state_value';
  $handler->display->display_options['sorts']['field_progress_state_value']['table'] = 'field_data_field_progress_state';
  $handler->display->display_options['sorts']['field_progress_state_value']['field'] = 'field_progress_state_value';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'ledger_post' => 'ledger_post',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['block_description'] = 'ledger list view';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '40';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['path'] = 'Improvement-Collaboration';

  /* Display: Content pane */
  $handler = $view->new_display('panel_pane', 'Content pane', 'panel_pane_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Improvement & Collaboration Ledger';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '6';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<p>The Improvement & Collaboration Ledger highlights actions SLAC is taking to remove administrative frustrations and streamline how we get things done. <a href="https://intranet-stage.slac.stanford.edu/content/about-efficiency-initiative"> More...</a></p>
';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['empty'] = TRUE;
  $handler->display->display_options['footer']['area']['content'] = '<div class="view-footer">
<!-- <a href="/all-ledger-items">View All Ledger Items</a>
<a href="/content/about-improvement-collaboration-ledger">About the Improvement & Collaboration Ledger</a> -->
<a href="/content/suggest-process-improvement" style="display:none">Suggest a Process for Improvement</a>
<!-- <a href="/files/About%20the%20Efficiency%20InitiativeRL-AAv2.docx">About the Efficiency Initiative (Website Coming Soon)</a> -->
<a href="https://intranet-stage.slac.stanford.edu/content/efficiency-tools-resources">Efficiency Tools & Resources</a>
</div>';
  $handler->display->display_options['footer']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Progress State */
  $handler->display->display_options['fields']['field_progress_state']['id'] = 'field_progress_state';
  $handler->display->display_options['fields']['field_progress_state']['table'] = 'field_data_field_progress_state';
  $handler->display->display_options['fields']['field_progress_state']['field'] = 'field_progress_state';
  $handler->display->display_options['fields']['field_progress_state']['label'] = '';
  $handler->display->display_options['fields']['field_progress_state']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_progress_state']['alter']['text'] = '[field_progress_state]';
  $handler->display->display_options['fields']['field_progress_state']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_progress_state']['type'] = 'list_key';
  /* Field: Content: Progress State */
  $handler->display->display_options['fields']['field_progress_state_1']['id'] = 'field_progress_state_1';
  $handler->display->display_options['fields']['field_progress_state_1']['table'] = 'field_data_field_progress_state';
  $handler->display->display_options['fields']['field_progress_state_1']['field'] = 'field_progress_state';
  $handler->display->display_options['fields']['field_progress_state_1']['label'] = '';
  $handler->display->display_options['fields']['field_progress_state_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_progress_state_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_progress_state_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_progress_state_1']['field_api_classes'] = TRUE;
  /* Field: Field: Link */
  $handler->display->display_options['fields']['field_link']['id'] = 'field_link';
  $handler->display->display_options['fields']['field_link']['table'] = 'field_data_field_link';
  $handler->display->display_options['fields']['field_link']['field'] = 'field_link';
  $handler->display->display_options['fields']['field_link']['label'] = '';
  $handler->display->display_options['fields']['field_link']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_link']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['field_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_link']['type'] = 'link_absolute';
  $handler->display->display_options['fields']['field_link']['delta_offset'] = '0';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '<a href="[field_file]">[title]</a>';
  $handler->display->display_options['fields']['title']['alter']['path'] = '[field_file] ';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: File */
  $handler->display->display_options['fields']['field_file']['id'] = 'field_file';
  $handler->display->display_options['fields']['field_file']['table'] = 'field_data_field_file';
  $handler->display->display_options['fields']['field_file']['field'] = 'field_file';
  $handler->display->display_options['fields']['field_file']['label'] = '';
  $handler->display->display_options['fields']['field_file']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_file']['alter']['text'] = '[title]';
  $handler->display->display_options['fields']['field_file']['alter']['path'] = '/files/ledgers/[field_file]';
  $handler->display->display_options['fields']['field_file']['alter']['alt'] = '[title]';
  $handler->display->display_options['fields']['field_file']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_file']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_file']['type'] = 'file_url_plain';
  $handler->display->display_options['fields']['field_file']['settings'] = array(
    'text' => '[field_file]',
  );
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[title]';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['path'] = '[field_file]';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $export['ledger_front_list'] = $view;

  return $export;
}
