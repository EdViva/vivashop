<?php
/**
 * @file
 * viva_free_gift.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function viva_free_gift_default_rules_configuration() {
  $items = array();
  $items['rules_redeem_a_coupon'] = entity_import('rules_config', '{ "rules_redeem_a_coupon" : {
      "LABEL" : "Redeem a coupon",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "commerce_cart", "commerce_coupon" ],
      "ON" : { "commerce_coupon_redeem" : [] },
      "IF" : [
        { "data_is" : { "data" : [ "coupon:commerce-coupon-code" ], "value" : "VIVAVL" } }
      ],
      "DO" : [
        { "commerce_cart_product_add_by_sku" : {
            "USING" : {
              "user" : [ "site:current-user" ],
              "sku" : "freegift2",
              "quantity" : "1",
              "combine" : 0
            },
            "PROVIDE" : { "product_add_line_item" : { "product_add_line_item" : "Added product line item" } }
          }
        }
      ]
    }
  }');
  $items['rules_redeem_a_coupon_mug'] = entity_import('rules_config', '{ "rules_redeem_a_coupon_mug" : {
      "LABEL" : "Redeem a coupon - mug",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "commerce_cart", "commerce_coupon" ],
      "ON" : { "commerce_coupon_redeem" : [] },
      "IF" : [
        { "data_is" : { "data" : [ "coupon:commerce-coupon-code" ], "value" : "VIVABF" } }
      ],
      "DO" : [
        { "commerce_cart_product_add_by_sku" : {
            "USING" : {
              "user" : [ "site:current-user" ],
              "sku" : "freemug",
              "quantity" : "1",
              "combine" : 0
            },
            "PROVIDE" : { "product_add_line_item" : { "product_add_line_item" : "Added product line item" } }
          }
        }
      ]
    }
  }');
  $items['rules_restrict_the_quantity_of_the_promo_product'] = entity_import('rules_config', '{ "rules_restrict_the_quantity_of_the_promo_product" : {
      "LABEL" : "Remove the promo product from the cart when all other products are removed.",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "commerce_order", "commerce_cart", "entity" ],
      "ON" : { "commerce_order_update" : [] },
      "IF" : [
        { "commerce_order_compare_total_product_quantity" : {
            "commerce_order" : [ "site:current-cart-order" ],
            "operator" : "=",
            "value" : "1"
          }
        },
        { "commerce_order_contains_product" : {
            "commerce_order" : [ "site:current-cart-order" ],
            "product_id" : "freegift2",
            "operator" : "=",
            "value" : "1"
          }
        }
      ],
      "DO" : [
        { "commerce_cart_empty" : { "commerce_order" : [ "site:current-cart-order" ] } }
      ]
    }
  }');
  $items['rules_restrict_the_quantity_of_the_promo_product_1'] = entity_import('rules_config', '{ "rules_restrict_the_quantity_of_the_promo_product_1" : {
      "LABEL" : "Restrict the quantity of the promo product.",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "entity" ],
      "ON" : { "commerce_line_item_update" : [] },
      "IF" : [
        { "data_is" : {
            "data" : [ "commerce-line-item:line-item-label" ],
            "value" : "freegift2"
          }
        },
        { "data_is" : {
            "data" : [ "commerce-line-item:quantity" ],
            "op" : "\\u003E",
            "value" : "1"
          }
        }
      ],
      "DO" : [
        { "data_set" : { "data" : [ "commerce-line-item:quantity" ], "value" : "1" } }
      ]
    }
  }');
  $items['rules_restrict_the_quantity_of_the_promo_product_mug'] = entity_import('rules_config', '{ "rules_restrict_the_quantity_of_the_promo_product_mug" : {
      "LABEL" : "Restrict the quantity of the promo product - mug",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "entity" ],
      "ON" : { "commerce_line_item_update" : [] },
      "IF" : [
        { "data_is" : { "data" : [ "commerce-line-item:line-item-label" ], "value" : "freemug" } },
        { "data_is" : {
            "data" : [ "commerce-line-item:quantity" ],
            "op" : "\\u003E",
            "value" : "1"
          }
        }
      ],
      "DO" : [
        { "data_set" : { "data" : [ "commerce-line-item:quantity" ], "value" : "1" } }
      ]
    }
  }');
  $items['rules_restrict_the_quantity_of_the_promo_product_mug_2'] = entity_import('rules_config', '{ "rules_restrict_the_quantity_of_the_promo_product_mug_2" : {
      "LABEL" : "Restrict the quantity of the promo product - mug",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "entity" ],
      "ON" : { "commerce_line_item_update" : [] },
      "IF" : [
        { "data_is" : { "data" : [ "commerce-line-item:line-item-label" ], "value" : "freemug" } },
        { "data_is" : {
            "data" : [ "commerce-line-item:quantity" ],
            "op" : "\\u003E",
            "value" : "1"
          }
        }
      ],
      "DO" : [
        { "data_set" : { "data" : [ "commerce-line-item:quantity" ], "value" : "1" } }
      ]
    }
  }');
  return $items;
}
