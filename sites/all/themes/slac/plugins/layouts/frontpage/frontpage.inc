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
    'colonerowone' => t('Lab News slider'),
    'colonerowtwo' => t('Lab News list'),
    'colonerowthree' => t('Slac Science'),
    'coltworowone' => t('Slideshow Mobile'),
    'coltworowtwo' => t('Links'),
    'coltworowthree' => t('Calendar'),
    'coltworowfour' => t('Access Information'),
    'coltworowfive' => t('Weather'),
    'colthreerowone' => t('People finder'),
    'colthreerowtwo' => t('Top links'),
    'colthreerowthree' => t('Slac projects'),
    'colthreerowfour' => t('Directorate links'),
    'colthreerowfive' => t('Help desk, Flea market'),
    'colthreerowsix' => t('Security, Contacts')
  ),
);

