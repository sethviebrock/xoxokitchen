<?php
/**
 * @file
 * xoxo_image.features.inc
 */

/**
 * Implements hook_image_default_styles().
 */
function xoxo_image_image_default_styles() {
  $styles = array();

  // Exported image style: brand_logo
  $styles['brand_logo'] = array(
    'name' => 'brand_logo',
    'effects' => array(),
  );

  // Exported image style: brand_page_product
  $styles['brand_page_product'] = array(
    'name' => 'brand_page_product',
    'effects' => array(),
  );

  // Exported image style: recipe_image
  $styles['recipe_image'] = array(
    'name' => 'recipe_image',
    'effects' => array(),
  );

  // Exported image style: recipe_node
  $styles['recipe_node'] = array(
    'name' => 'recipe_node',
    'effects' => array(),
  );

  // Exported image style: recipies_list
  $styles['recipies_list'] = array(
    'name' => 'recipies_list',
    'effects' => array(
      12 => array(
        'label' => 'Change file format',
        'help' => 'Choose to save the image as a different filetype.',
        'effect callback' => 'coloractions_convert_image',
        'dimensions passthrough' => TRUE,
        'form callback' => 'coloractions_convert_form',
        'summary theme' => 'coloractions_convert_summary',
        'module' => 'imagecache_coloractions',
        'name' => 'coloractions_convert',
        'data' => array(
          'format' => 'image/png',
          'quality' => '75',
        ),
        'weight' => '-10',
      ),
      8 => array(
        'label' => 'Rounded Corners',
        'help' => 'This is true cropping, not overlays, so the result <em>can</em> be transparent.',
        'effect callback' => 'canvasactions_roundedcorners_image',
        'dimensions passthrough' => TRUE,
        'form callback' => 'canvasactions_roundedcorners_form',
        'summary theme' => 'canvasactions_roundedcorners_summary',
        'module' => 'imagecache_canvasactions',
        'name' => 'canvasactions_roundedcorners',
        'data' => array(
          'radius' => '7',
          'independent_corners_set' => array(
            'independent_corners' => 0,
            'radii' => array(
              'tl' => 0,
              'tr' => 0,
              'bl' => 0,
              'br' => 0,
            ),
          ),
        ),
        'weight' => '-8',
      ),
      13 => array(
        'label' => 'Define canvas',
        'help' => 'Define the size of the working canvas and background color, this controls the dimensions of the output image.',
        'effect callback' => 'canvasactions_definecanvas_effect',
        'dimensions callback' => 'canvasactions_definecanvas_dimensions',
        'form callback' => 'canvasactions_definecanvas_form',
        'summary theme' => 'canvasactions_definecanvas_summary',
        'module' => 'imagecache_canvasactions',
        'name' => 'canvasactions_definecanvas',
        'data' => array(
          'RGB' => array(
            'HEX' => 'ffffff',
          ),
          'under' => 1,
          'exact' => array(
            'width' => '75',
            'height' => '75',
            'xpos' => 'center',
            'ypos' => 'center',
          ),
          'relative' => array(
            'leftdiff' => '',
            'rightdiff' => '',
            'topdiff' => '',
            'bottomdiff' => '',
          ),
        ),
        'weight' => '4',
      ),
    ),
  );

  // Exported image style: userpic_74
  $styles['userpic_74'] = array(
    'name' => 'userpic_74',
    'effects' => array(
      3 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => '102',
          'height' => '',
          'upscale' => 1,
        ),
        'weight' => '1',
      ),
    ),
  );

  return $styles;
}
