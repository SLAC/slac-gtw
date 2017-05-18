<?php
/**
 * @file
 * ct_flea_market_item.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function ct_flea_market_item_default_rules_configuration() {
  $items = array();
  $items['rules_send_email_when_flea_market_item_is_flagged'] = entity_import('rules_config', '{ "rules_send_email_when_flea_market_item_is_flagged" : {
      "LABEL" : "Send email when Bulletin Board item is flagged",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "flag" ],
      "ON" : { "flag_flagged_flea_market_inappropriate" : [] },
      "DO" : [
        { "mail" : {
            "to" : "communications@slac.stanford.edu",
            "subject" : "A Bulletin Board item has been flagged as inappropriate.",
            "message" : "The Bulletin Board item at: [flagged-node:url] by [flagged-node:author] has been flagged as inappropriate.",
            "from" : "communications@slac.stanford.edu",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  return $items;
}
