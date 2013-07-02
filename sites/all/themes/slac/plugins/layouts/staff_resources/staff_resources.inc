<?php

/**
 * implementation of hook_panels_layouts
 */
// Plugin definition
$plugin = array(
  'title' => t('Staff resources'),
  'category' => t('Slac layouts'),
  'icon' => 'staff_resources.png',
  'theme' => 'staff_resources',
  'theme arguments' => array('id', 'content'),
  'css' => 'staff_resources.css',
  'regions' => array(
    'staffresourcesone' => t('Left Column'),
    'staffresourcesone' => t('Right Column'),
    'rowone' => t('First row'),
    'rowtwo' => t('Seccond row')
  ),
);

