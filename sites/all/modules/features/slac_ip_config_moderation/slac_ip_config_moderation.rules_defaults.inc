<?php
/**
 * @file
 * slac_ip_config_moderation.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function slac_ip_config_moderation_default_rules_configuration() {
  $items = array();
  $items['rules_workbench_notification_flea_market_published_notification'] = entity_import('rules_config', '{ "rules_workbench_notification_flea_market_published_notification" : {
      "LABEL" : "Workbench notification Flea Market PUBLISHED notification",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "SLAC IP Config Moderation" ],
      "REQUIRES" : [ "rules", "workbench_moderation" ],
      "ON" : { "workbench_moderation_after_moderation_transition" : [] },
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "node" ],
            "type" : { "value" : { "flea_market_post" : "flea_market_post" } }
          }
        },
        { "contents_current_state" : { "node" : [ "node" ], "moderation_state" : "published" } }
      ],
      "DO" : [
        { "mail" : {
            "to" : [ "node:author:mail" ],
            "subject" : "Your SLAC Flea Market ad, \\u0022[node:title],\\u0022 has been published.",
            "message" : "Your SLAC Flea Market ad, \\u0022[node:title],\\u0022 has been published. You can view the item at: [node:url].\\r\\n\\r\\nTo edit, unpublish or delete your ad, click the \\u0022New Draft\\u0022 tab.\\r\\n\\r\\nPlease be responsible with your Flea Market ads. Flea market ads are not anonymous and link to your name in the SLAC directory. The Office of Communications reviews all published ads when flagged as inappropriate.\\r\\n\\r\\nIf you have any questions, please see the Flea Market guidelines (https:\\/\\/intranet.slac.stanford.edu\\/about-flea-market) or contact communications@slac.stanford.edu.\\r\\n\\r\\nThank you,\\r\\nSLAC Communications",
            "from" : "communications@slac.stanford.edu",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  $items['rules_workbench_notification_new_draft_author_notification'] = entity_import('rules_config', '{ "rules_workbench_notification_new_draft_author_notification" : {
      "LABEL" : "Workbench notification new DRAFT author notification",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "SLAC IP Config Moderation" ],
      "REQUIRES" : [ "rules", "workbench_moderation" ],
      "ON" : { "node_insert" : [] },
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "node" ],
            "type" : { "value" : {
                "access_information" : "access_information",
                "event" : "event",
                "news" : "news"
              }
            }
          }
        },
        { "content_is_using_workbench_moderation" : { "node" : [ "node" ] } },
        { "contents_current_state" : { "node" : [ "node" ], "moderation_state" : "draft" } }
      ],
      "DO" : [
        { "mail" : {
            "to" : [ "node:author:mail" ],
            "subject" : "Your SLAC Today [node:content-type] item, \\u0022[node:title],\\u0022 has been saved.",
            "message" : "A draft of your SLAC Today [node:content-type] item, \\u0022[node:title],\\u0022 has been saved. You can view, edit and submit the item for publishing at: [node:url].\\r\\n\\r\\nBefore submitting your item, please take the time to review the text for clarity and mistakes and ensure the content has been vetted and approved by all appropriate managers responsible for the subject area. Once submitted, you will not have the ability to make changes yourself and will need to contact us to make any updates.\\r\\n\\r\\nIf you have any questions, please see About SLAC Today (https:\\/\\/intranet.slac.stanford.edu\\/about-slac-today) or contact communications@slac.stanford.edu.\\r\\n\\r\\nThank you,\\r\\nSLAC Communications",
            "from" : "communications@slac.stanford.edu",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  $items['rules_workbench_notification_new_flea_market_draft_notification'] = entity_import('rules_config', '{ "rules_workbench_notification_new_flea_market_draft_notification" : {
      "LABEL" : "Workbench notification new Flea Market DRAFT notification",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "SLAC IP Config Moderation" ],
      "REQUIRES" : [ "workbench_moderation", "rules" ],
      "ON" : { "node_insert--flea_market_post" : { "bundle" : "flea_market_post" } },
      "IF" : [
        { "content_is_using_workbench_moderation" : { "node" : [ "node" ] } },
        { "contents_current_state" : { "node" : [ "node" ], "moderation_state" : "draft" } }
      ],
      "DO" : [
        { "mail" : {
            "to" : [ "node:author:mail" ],
            "subject" : "Your SLAC Flea Market ad, \\u0022[node:title],\\u0022 has been saved.",
            "message" : "Your draft SLAC Flea Market ad, \\u0022[node:title],\\u0022 has been saved. You can view, edit and publish the ad at: [node:url].\\r\\n\\r\\nTo edit or delete your draft, click the \\u0022Edit Draft\\u0022 tab.\\r\\n\\r\\nBefore publishing your item, please take care to be responsible with your ad. Flea market ads are not anonymous and automatically link with your name in the SLAC directory. The Office of Communications reviews all published ads when flagged as inappropriate.\\r\\n\\r\\nIf you have any questions, please see the Flea Market guidelines (https:\\/\\/intranet.slac.stanford.edu\\/about-flea-market) or contact communications@slac.stanford.edu.\\r\\n\\r\\nThank you,\\r\\nSLAC Communications",
            "from" : "communications@slac.stanford.edu",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  $items['rules_workbench_notification_published_author_notification'] = entity_import('rules_config', '{ "rules_workbench_notification_published_author_notification" : {
      "LABEL" : "Workbench notification PUBLISHED author notification",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "SLAC IP Config Moderation" ],
      "REQUIRES" : [ "rules", "workbench_moderation" ],
      "ON" : { "workbench_moderation_after_moderation_transition" : [] },
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "node" ],
            "type" : { "value" : {
                "access_information" : "access_information",
                "event" : "event",
                "news" : "news"
              }
            }
          }
        },
        { "contents_current_state" : { "node" : [ "node" ], "moderation_state" : "published" } }
      ],
      "DO" : [
        { "mail" : {
            "to" : [ "node:author:mail" ],
            "subject" : "Your SLAC Today [node:content-type] item, \\u0022[node:title],\\u0022 has been published.",
            "message" : "Your SLAC Today [node:content-type] item, \\u0022[node:title],\\u0022 has been published. You can view the item at: [node:url].\\r\\n\\r\\nTo make changes to your submission, please contact SLAC\\u2019s internal communications coordinator at mjhorton@slac.stanford.edu or ext. 4289.\\r\\n\\r\\nPlease note that SLAC Communications edits all submissions for style and clarity. See About SLAC Today (https:\\/\\/intranet.slac.stanford.edu\\/about-slac-today) for submission guidelines.\\r\\n\\r\\nThank you,\\r\\nSLAC Communications",
            "language" : [ "" ]
          }
        },
        { "mail" : {
            "to" : "communications@slac.stanford.edu",
            "subject" : "\\u0022[node:title],\\u201d has been reviewed and approved for publication.",
            "message" : "You can view the published version at:\\r\\n[node:url].\\r\\n\\r\\nThank you,\\r\\nSLAC Communications",
            "from" : "communications@slac.stanford.edu",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  $items['rules_workbench_notification_submitted_mod_author_notification'] = entity_import('rules_config', '{ "rules_workbench_notification_submitted_mod_author_notification" : {
      "LABEL" : "Workbench notification Submitted mod\\/author notification",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "SLAC IP Config Moderation" ],
      "REQUIRES" : [ "rules", "workbench_moderation" ],
      "ON" : { "workbench_moderation_after_moderation_transition" : [] },
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "node" ],
            "type" : { "value" : {
                "access_information" : "access_information",
                "event" : "event",
                "news" : "news"
              }
            }
          }
        },
        { "contents_current_state" : { "node" : [ "node" ], "moderation_state" : "needs_review" } }
      ],
      "DO" : [
        { "mail" : {
            "to" : [ "node:author:mail" ],
            "subject" : "Your SLAC Today [node:content-type] item, \\u0022[node:title],\\u0022 has been submitted for publication. ",
            "message" : "Your SLAC Today [node:content-type] item, \\u0022[node:title],\\u0022 has been submitted for publication. We will review your item and publish it or contact you with any issues within two business days, most likely sooner.\\r\\n\\r\\nYou can view the submitted item at: [node:url].\\r\\n\\r\\nIf your submission is urgent or you need to make changes, please contact SLAC\\u2019s internal communications coordinator at mjhorton@slac.stanford.edu or ext. 4289.\\r\\n\\r\\nPlease note that SLAC Communications edits all submissions for style and clarity. We will contact you if additional information or significant changes are needed. See About SLAC Today (https:\\/\\/intranet.slac.stanford.edu\\/about-slac-today) for submission guidelines.\\r\\n\\r\\nThank you,\\r\\nSLAC Communications",
            "from" : "communications@slac.stanford.edu",
            "language" : [ "" ]
          }
        },
        { "mail" : {
            "to" : "communications@slac.stanford.edu",
            "subject" : "\\u0022[node:title],\\u0022 has been submitted for publication.",
            "message" : "You can view the submitted version at:\\r\\n[node:url].\\r\\n\\r\\nThank you,\\r\\n\\r\\nSLAC Communications",
            "from" : "communications@slac.stanford.edu",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  return $items;
}
