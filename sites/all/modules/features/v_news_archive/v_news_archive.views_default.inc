<?php
/**
 * @file
 * v_news_archive.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function v_news_archive_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'news_archive';
  $view->description = 'Listing of News articles optionally filtered by day, month, and category.';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'News Archive';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'All News';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Submit';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['view_mode'] = 'news_archive';
  $handler->display->display_options['row_options']['links'] = FALSE;
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['content'] = 'NOTE: This archive only includes content published since May 23, 2011. For older content, see the <em><a href="http://today.slac.stanford.edu/a/">SLAC Today Archives</a></em>.';
  $handler->display->display_options['footer']['area']['format'] = 'full_html';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'There are no News articles that match the selected filters.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Node: Published at */
  $handler->display->display_options['sorts']['published_at_1']['id'] = 'published_at_1';
  $handler->display->display_options['sorts']['published_at_1']['table'] = 'publication_date';
  $handler->display->display_options['sorts']['published_at_1']['field'] = 'published_at';
  $handler->display->display_options['sorts']['published_at_1']['order'] = 'DESC';
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
      'access_information' => 'access_information',
      'event' => 'event',
      'news' => 'news',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Promote As News (field_shared_promote_news) */
  $handler->display->display_options['filters']['field_shared_promote_news_value']['id'] = 'field_shared_promote_news_value';
  $handler->display->display_options['filters']['field_shared_promote_news_value']['table'] = 'field_data_field_shared_promote_news';
  $handler->display->display_options['filters']['field_shared_promote_news_value']['field'] = 'field_shared_promote_news_value';
  $handler->display->display_options['filters']['field_shared_promote_news_value']['value'] = array(
      1 => '1',
  );
  $handler->display->display_options['filters']['field_shared_promote_news_value']['group'] = 1;
  /* Filter criterion: Content: News Type (field_news_news_type) */
  $handler->display->display_options['filters']['field_news_news_type_value']['id'] = 'field_news_news_type_value';
  $handler->display->display_options['filters']['field_news_news_type_value']['table'] = 'field_data_field_news_news_type';
  $handler->display->display_options['filters']['field_news_news_type_value']['field'] = 'field_news_news_type_value';
  $handler->display->display_options['filters']['field_news_news_type_value']['group'] = 1;
  $handler->display->display_options['filters']['field_news_news_type_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_news_news_type_value']['expose']['operator_id'] = 'field_news_news_type_value_op';
  $handler->display->display_options['filters']['field_news_news_type_value']['expose']['operator'] = 'field_news_news_type_value_op';
  $handler->display->display_options['filters']['field_news_news_type_value']['expose']['identifier'] = 'field_news_news_type_value';
  $handler->display->display_options['filters']['field_news_news_type_value']['expose']['remember_roles'] = array(
      2 => '2',
      1 => 0,
      5 => 0,
      4 => 0,
      6 => 0,
      7 => 0,
      3 => 0,
  );
  /* Filter criterion: Node: Published at */
  $handler->display->display_options['filters']['published_at']['id'] = 'published_at';
  $handler->display->display_options['filters']['published_at']['table'] = 'publication_date';
  $handler->display->display_options['filters']['published_at']['field'] = 'published_at';
  $handler->display->display_options['filters']['published_at']['operator'] = 'between';
  $handler->display->display_options['filters']['published_at']['group'] = 1;
  $handler->display->display_options['filters']['published_at']['exposed'] = TRUE;
  $handler->display->display_options['filters']['published_at']['expose']['operator_id'] = 'published_at_op';
  $handler->display->display_options['filters']['published_at']['expose']['operator'] = 'published_at_op';
  $handler->display->display_options['filters']['published_at']['expose']['identifier'] = 'published_at';
  $handler->display->display_options['filters']['published_at']['expose']['remember_roles'] = array(
      2 => '2',
      1 => 0,
      5 => 0,
      4 => 0,
      6 => 0,
      7 => 0,
      3 => 0,
  );

  /* Display: Content pane */
  $handler = $view->new_display('panel_pane', 'Content pane', 'panel_pane_1');
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 0;
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 'title_override';
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;
  $handler->display->display_options['inherit_panels_path'] = '1';
  $export['news_archive'] = $view;

  return $export;
}
