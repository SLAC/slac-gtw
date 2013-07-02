<?php

/**
 * implementation of hook_panels_layouts
 */
// Plugin definition
$plugin = array(
  'title' => t('Front Page 3 columns'),
  'category' => t('Slac layouts'),
  'icon' => 'frontpage.png',
  'theme' => 'frontpage',
  'theme arguments' => array('id', 'content'),
  'css' => 'frontpage.css',
  'regions' => array(
    'colonerowone' => t('Lab News slider'),
    'colonerowtwo' => t('Lab News list'),
    'colonerowthree' => t('Slac Science'),
    'coltworowone' => t('Links'),
    'coltworowtwo' => t('Calendar'),
    'coltworowthree' => t('Access Information'),
    'coltworowfour' => t('Weather'),
    'colthreerowone' => t('People finder'),
    'colthreerowtwo' => t('Top links'),
    'colthreerowthree' => t('Slac projects'),
    'colthreerowfour' => t('Directorate links'),
    'colthreerowfive' => t('Help desk, Flea market'),
    'colthreerowsix' => t('Security, Contacts')
  ),
);

