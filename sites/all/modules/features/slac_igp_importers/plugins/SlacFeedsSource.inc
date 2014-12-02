<?php

/**
 * Overrides the standard FeedsSource class.
 *
 * NOTE: In order for this to work, the feeds_source_class variable on the site
 * must be set to "SlacFeedsSource".
 *
 * This is basically a stupid trick by which we are allowing event feeds to use
 * both RSS and iCalendar feeds; not normally possible with Feeds.
 */
class SlacFeedsSource extends FeedsSource {
  
  protected function __construct($importer_id, $feed_nid) {
    // First, construct ourself as normal.
    parent::__construct($importer_id, $feed_nid);
    // $importer_id is useless for figuring out which source we have
    // So lets use what we know about the source

    if ($importer_id === 'slac_news') {
      return;
    }

    $this->importer = feeds_importer('slac_events');

    // Cheap; known source
    if (preg_match('/\.ics$/', $this->config['FeedsHTTPFetcher']['source'])) {
      // Use the iCalendar
      $this->importer = feeds_importer('slac_events_ical');
    }
    // doubtful that the rss feeds will end in xml or rss but still check so we don't have to guess
    elseif (preg_match('/\.xml$/', $this->config['FeedsHTTPFetcher']['source'])
          || preg_match('/\.rss$/', $this->config['FeedsHTTPFetcher']['source'])) {
      $this->importer = feeds_importer('slac_events');
    }
    else {
      // fine, we'll just request the data and check content headers
      try {
        $result = drupal_http_request($this->config['FeedsHTTPFetcher']['source']);
      }
      catch (Exception $e) {
      }

      if(isset($result)) {
        foreach ($result->headers as $header => $info) {
          if (strtolower($header) === 'content-type') {
            if (!strpos($info, 'calendar') === FALSE) {
              $this->importer = feeds_importer('slac_events_ical');
            }
            elseif (!strpos($info, 'rss+xml') === FALSE) {
              $this->importer = feeds_importer('slac_events');
            }
            else {
              // All else fails... it's RSS
              $this->importer = feeds_importer('slac_events');
            }
          }
        }
      }
    }
  }
}
