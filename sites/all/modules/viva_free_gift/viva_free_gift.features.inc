<?php
/**
 * @file
 * viva_free_gift.features.inc
 */

/**
 * Implements hook_commerce_coupon_default_types().
 */
function viva_free_gift_commerce_coupon_default_types() {
  $items = array(
    'commerce_coupon_pct' => array(
      'type' => 'commerce_coupon_pct',
      'label' => 'Percentage coupon',
      'weight' => '0',
      'data' => NULL,
      'status' => '1',
      'module' => NULL,
    ),
  );
  return $items;
}

/**
 * Implements hook_commerce_product_default_types().
 */
function viva_free_gift_commerce_product_default_types() {
  $items = array(
    'free_gifts' => array(
      'type' => 'free_gifts',
      'name' => 'Free gifts',
      'description' => '',
      'help' => '',
      'revision' => '1',
    ),
  );
  return $items;
}
