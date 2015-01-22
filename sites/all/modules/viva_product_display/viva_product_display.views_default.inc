<?php
/**
 * @file
 * viva_product_display.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function viva_product_display_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'clone_of_collection_products';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_product_display';
  $view->human_name = 'Responive collection products';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = '%1';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'name',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['class'] = 'products-per-collection';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Header: Global: View area */
  $handler->display->display_options['header']['view']['id'] = 'view';
  $handler->display->display_options['header']['view']['table'] = 'views';
  $handler->display->display_options['header']['view']['field'] = 'view';
  $handler->display->display_options['header']['view']['view_to_insert'] = 'collection_products:block_1';
  $handler->display->display_options['header']['view']['inherit_arguments'] = TRUE;
  /* Relationship: Category */
  $handler->display->display_options['relationships']['field_product_category']['id'] = 'field_product_category';
  $handler->display->display_options['relationships']['field_product_category']['table'] = 'search_api_index_product_display';
  $handler->display->display_options['relationships']['field_product_category']['field'] = 'field_product_category';
  $handler->display->display_options['relationships']['field_product_category']['ui_name'] = 'Category';
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'entity_taxonomy_term';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'field_category';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_entity'] = 0;
  /* Field: Content: Rendered Node */
  $handler->display->display_options['fields']['rendered_entity']['id'] = 'rendered_entity';
  $handler->display->display_options['fields']['rendered_entity']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['rendered_entity']['field'] = 'rendered_entity';
  $handler->display->display_options['fields']['rendered_entity']['label'] = '';
  $handler->display->display_options['fields']['rendered_entity']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['rendered_entity']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['rendered_entity']['display'] = 'view';
  $handler->display->display_options['fields']['rendered_entity']['view_mode'] = 'product_list';
  /* Contextual filter: Indexed Node: Product category */
  $handler->display->display_options['arguments']['field_product_category']['id'] = 'field_product_category';
  $handler->display->display_options['arguments']['field_product_category']['table'] = 'search_api_index_product_display';
  $handler->display->display_options['arguments']['field_product_category']['field'] = 'field_product_category';
  $handler->display->display_options['arguments']['field_product_category']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['field_product_category']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_product_category']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_product_category']['summary_options']['grouping'] = array(
    0 => array(
      'field' => 'name',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['arguments']['field_product_category']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_product_category']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['field_product_category']['validate_options']['vocabularies'] = array(
    'product_category' => 'product_category',
  );
  $handler->display->display_options['arguments']['field_product_category']['break_phrase'] = 0;
  /* Filter criterion: Indexed Node: Status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'search_api_index_product_display';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = array(
    1 => '1',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = '%1';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'semanticviews_default';
  $handler->display->display_options['style_options']['row']['class'] = 'product-item grid-6';
  $handler->display->display_options['style_options']['row']['first_class'] = 'alpha';
  $handler->display->display_options['style_options']['row']['last_class'] = 'omega';
  $handler->display->display_options['style_options']['row']['last_every_nth'] = '4';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'semanticviews_fields';
  $handler->display->display_options['row_options']['skip_blank'] = 0;
  $handler->display->display_options['row_options']['semantic_html'] = array(
    'rendered_entity' => array(
      'element_type' => 'div',
      'class' => '',
    ),
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: View area */
  $handler->display->display_options['header']['view']['id'] = 'view';
  $handler->display->display_options['header']['view']['table'] = 'views';
  $handler->display->display_options['header']['view']['field'] = 'view';
  $handler->display->display_options['header']['view']['view_to_insert'] = 'collection_products:default';
  $handler->display->display_options['header']['view']['inherit_arguments'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name_1']['id'] = 'name_1';
  $handler->display->display_options['fields']['name_1']['table'] = 'entity_taxonomy_term';
  $handler->display->display_options['fields']['name_1']['field'] = 'name';
  $handler->display->display_options['fields']['name_1']['relationship'] = 'field_product_category';
  $handler->display->display_options['fields']['name_1']['label'] = '';
  $handler->display->display_options['fields']['name_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name_1']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['name_1']['replace_spaces'] = TRUE;
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'entity_taxonomy_term';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'field_product_category';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['text'] = '<span id="[name_1]"></span><div class="collection"><a>[name]</a></div>';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['name']['replace_spaces'] = TRUE;
  /* Field: Content: Rendered Node */
  $handler->display->display_options['fields']['rendered_entity']['id'] = 'rendered_entity';
  $handler->display->display_options['fields']['rendered_entity']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['rendered_entity']['field'] = 'rendered_entity';
  $handler->display->display_options['fields']['rendered_entity']['label'] = '';
  $handler->display->display_options['fields']['rendered_entity']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['rendered_entity']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['rendered_entity']['display'] = 'view';
  $handler->display->display_options['fields']['rendered_entity']['view_mode'] = 'product_list';
  $handler->display->display_options['fields']['rendered_entity']['bypass_access'] = 0;
  /* Field: Indexed Node: URL */
  $handler->display->display_options['fields']['url']['id'] = 'url';
  $handler->display->display_options['fields']['url']['table'] = 'search_api_index_product_display';
  $handler->display->display_options['fields']['url']['field'] = 'url';
  $handler->display->display_options['fields']['url']['exclude'] = TRUE;
  $handler->display->display_options['fields']['url']['link_to_entity'] = 0;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Indexed Node: Product category */
  $handler->display->display_options['arguments']['field_product_category']['id'] = 'field_product_category';
  $handler->display->display_options['arguments']['field_product_category']['table'] = 'search_api_index_product_display';
  $handler->display->display_options['arguments']['field_product_category']['field'] = 'field_product_category';
  $handler->display->display_options['arguments']['field_product_category']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['field_product_category']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_product_category']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_product_category']['summary_options']['grouping'] = array(
    0 => array(
      'field' => 'name',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['arguments']['field_product_category']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_product_category']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['field_product_category']['validate_options']['vocabularies'] = array(
    'wine_country' => 'wine_country',
    'ale' => 'ale',
    'product_category' => 'product_category',
    'type_of_drink' => 'type_of_drink',
  );
  $handler->display->display_options['arguments']['field_product_category']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['field_product_category']['not'] = 0;
  $handler->display->display_options['path'] = 'product_category/%';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'collection-terms';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'name_1',
      'rendered' => 0,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'entity_taxonomy_term';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'field_product_category';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['name']['replace_spaces'] = TRUE;
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name_1']['id'] = 'name_1';
  $handler->display->display_options['fields']['name_1']['table'] = 'entity_taxonomy_term';
  $handler->display->display_options['fields']['name_1']['field'] = 'name';
  $handler->display->display_options['fields']['name_1']['relationship'] = 'field_product_category';
  $handler->display->display_options['fields']['name_1']['label'] = '';
  $handler->display->display_options['fields']['name_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['name_1']['alter']['text'] = '<a href="#[name]">[name_1]</a>';
  $handler->display->display_options['fields']['name_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name_1']['link_to_entity'] = 0;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['hide_empty'] = TRUE;
  /* Field: Taxonomy term: Description */
  $handler->display->display_options['fields']['description']['id'] = 'description';
  $handler->display->display_options['fields']['description']['table'] = 'entity_taxonomy_term';
  $handler->display->display_options['fields']['description']['field'] = 'description';
  $handler->display->display_options['fields']['description']['relationship'] = 'field_product_category';
  $handler->display->display_options['fields']['description']['label'] = '';
  $handler->display->display_options['fields']['description']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['description']['link_to_entity'] = 0;

  /* Display: Book Page */
  $handler = $view->new_display('page', 'Book Page', 'page_1');
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Indexed Node: Title */
  $handler->display->display_options['sorts']['title_field']['id'] = 'title_field';
  $handler->display->display_options['sorts']['title_field']['table'] = 'search_api_index_product_display';
  $handler->display->display_options['sorts']['title_field']['field'] = 'title_field';
  $handler->display->display_options['path'] = 'books/%';
  $export['clone_of_collection_products'] = $view;

  return $export;
}
