<?php
/**
 * @file
 * slac_igp_email.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function slac_igp_email_default_rules_configuration() {
  $items = array();
  $items['rules_slac_igp_email_resubscription'] = entity_import('rules_config', '{ "rules_slac_igp_email_resubscription" : {
      "LABEL" : "Weekly email re-subscription",
      "PLUGIN" : "rule",
      "TAGS" : [ "email", "mailchimp", "weekly email" ],
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : { "email" : { "label" : "email", "type" : "text" } },
      "DO" : [
        { "mail" : {
            "to" : "[email:value]",
            "subject" : "You have been re-subscribed to the weekly email.",
            "message" : "=========================================\\r\\nThis is an system generated email, please do not reply\\r\\n=========================================\\r\\n\\r\\nagna, augue sit amet eu, cursus sit proin lundium dignissim dictumst mid! Augue augue sed odio, integer magnis? Vel quis, mattis, sagittis purus ridiculus vel sed. Porttitor odio sociis mattis placerat, turpis augue nec auctor magnis, odio porta in, sit turpis pulvinar nec quis risus quis pulvinar et, ac quis adipiscing et vel ultricies. Risus adipiscing dapibus sed rhoncus nisi! Pulvinar ridiculus adipiscing! Rhoncus ridiculus elementum, nunc risus, nisi, et, proin ut ridiculus et a natoque tortor amet, phasellus vut? Facilisis enim, nunc purus? Nascetur vel? Amet montes nisi magna enim nec aliquet, cum aliquet a parturient pid lundium. Lacus! Sed cursus augue magna! Sociis lectus a mus, habitasse cursus ac elementum, et auctor! A rhoncus risus turpis augue etiam.",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  return $items;
}
