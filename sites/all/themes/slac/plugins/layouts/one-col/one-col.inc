<?php

/**
 * implementation of hook_panels_layouts
 */
// Plugin definition
$plugin = array(
  'title' => t('Basic 1 col'),
  'category' => t('Slac layouts'),
  'icon' => 'one_col.png',
  'theme' => 'one-col',
  'theme arguments' => array('id', 'content'),
  'regions' => array(
    'main_content_column' => t('Main Content Column')
  ),
);

