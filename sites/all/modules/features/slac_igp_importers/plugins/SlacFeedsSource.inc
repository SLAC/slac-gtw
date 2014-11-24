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
    // If it looks like the feed is an iCalendar feed (has an ".ics" extension),
    // clobber our importer with the slac_events_cal importer instead.
    if ($importer_id === 'slac_events' && preg_match('/\.ics$/', $this->config['FeedsHTTPFetcher']['source'])) {
      // Use the iCalendar importer instead.
      $this->importer = feeds_importer('slac_events_ical');
    }
    elseif ($importer_id === 'slac_events_ical') {
      // Use the RSS importer if it's not already being used.
      $this->importer = feeds_importer('slac_events');
    }
  }
}
