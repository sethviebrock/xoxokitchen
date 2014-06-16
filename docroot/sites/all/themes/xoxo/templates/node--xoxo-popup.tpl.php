<?php if($node->type == 'recipe'): ?>
    <div class="two_column">
        <h2><?php print render($content['field_recipe_subtitle']['0']['#markup']); ?></h2>
        <div class="column_left">
        	<?php if(render($content['field_recipe_time']['0']['#markup'])): ?> 
                <div class="info_line"> 
                    <h4>Preparation time:</h4>
                    <span class="recipe_info_line">
                        <?php print render($content['field_recipe_time']['0']['#markup']); ?>
                    </span>
                </div>
        	<?php endif; ?>
        	<?php if(render($content['field_recipe_servings']['0']['#markup'])): ?> 
                <div class="info_line"> 
                    <h4>Servings:</h4>
                    <span class="recipe_info_line"><?php print render($content['field_recipe_servings']['0']['#markup']); ?></span>
                </div>
        	<?php endif; ?>
					<?php if(render($content['field_recipe_quantity']['0']['#markup'])): ?> 
                <div class="info_line"> 
                    <h4>Quantity:</h4>
                    <span class="recipe_info_line"><?php print render($content['field_recipe_quantity']['0']['#markup']); ?></span>
                </div>
        	<?php endif; ?>
        	<?php if(render($content['field_recipe_meal_type']['0']['#markup'])): ?> 
                <div class="info_line"> 
                    <h4>Meal type:</h4>
                    <span class="recipe_info_line"><?php print render($content['field_recipe_meal_type']['0']['#markup']); ?></span>
                </div>
        	<?php endif; ?>
        	<?php if(render($content['field_recipe_cuisine']['0']['#markup'])): ?> 
                <div class="info_line"> 
                    <h4>Cuisine:</h4>
                    <span class="recipe_info_line"><?php print render($content['field_recipe_cuisine']['0']['#markup']); ?></span>
                </div>
        	<?php endif; ?>
                  <?php if(render($content['field_recipe_ingredients'])): ?> 
          <div class="info_line red_line"> 
              <h4>Ingredients:</h4>       
              <?php print '<ol>';
            foreach ($content['field_recipe_ingredients'] as $delta => $item) {
                  if(is_numeric($delta)) {
                    print '<li class="ing_line ing-'.$delta.'">';
                    print '<span class="it-'.$delta.'">'.render($content['field_recipe_ingredients']['#items'][$delta]['title']).'</span>';
                    print '<span class="ia-'.$delta.'">'.render($content['field_recipe_ingredients']['#items'][$delta]['amount_']).'</span>';
                    print '<span class="iu-'.$delta.'">'.render($content['field_recipe_ingredients']['#items'][$delta]['unit']).'</span>';
                    print '</li>';
                    }
                  }       
          print '</ol>';
              ?>
          </div>
          <?php endif; ?>  
        	<?php if(render($content['field_recipe_restrictions']['0']['#markup'])): ?> 
                <div class="info_line"> 
                   <h4>Dietary restrictions:</h4>
				  <?php foreach ($content['field_recipe_restrictions'] as $delta => $item) {
                    if(is_numeric($delta)) {
                    print '<span class="recipe_info_line">'.render($content['field_recipe_restrictions'][$delta]['#markup']).'</span>';
                    }
                  } 
                  ?> 
                </div>
        	<?php endif; ?>
        </div>
        <div class="column_right">
        	<?php if(render($content['field_recipe_image'])): ?>     	
                <div class="info_line photo"> 
                    <?php print render($content['field_recipe_image']); ?>
                </div>	
        	<?php endif; ?>
          <?php if(render($content['body']['0']['#markup'])): ?> 
            <div class="info_line"> 
                 <h4>Preparation:</h4>
                 <div class="preparation_text">
                 	<?php print render($content['body']['0']['#markup']); ?>
                 </div>
            </div>
        	<?php endif; ?>
          <?php if(render($content['field_recipe_side_dish']['0'])): ?> 
            <div class="info_line"> 
                <h4>Side Dish:</h4>                
                <?php print '<ul>';
                  foreach ($content['field_recipe_side_dish'] as $delta => $item) {
                    if(is_numeric($delta)) {
                      print '<li class="ing_line ing-'.$delta.'">';
                      print '<span class="it-'.$delta.'">'.render($content['field_recipe_side_dish'][$delta]).'</span>';
                      print '</li>';
                  }
                }       
                    print '</ul>';
            ?>                
            </div>
        <?php endif; ?>
        </div>
    </div>
<?php else: ?>
    <article<?php print $attributes; ?>>
      <?php print $user_picture; ?>
      <?php print render($title_prefix); ?>
      <?php if (!$page && $title): ?>
      <header>
        <h2<?php print $title_attributes; ?> class="333"><a href="<?php print $node_url ?>" title="<?php print $title ?>">
        
    
        <?php print $node->field_page_subtitle[0]['view']; ?>
    
        
    
        <?php print $title ?>
        
        </a></h2>
      </header>
      <?php endif; ?>
      <?php print render($title_suffix); ?>
      <?php if ($display_submitted): ?>
      <footer class="submitted"><?php print $date; ?> -- <?php print $name; ?></footer>
      <?php endif; ?>  
      
      <div<?php print $content_attributes; ?>>
        <?php
          // We hide the comments and links now so that we can render them later.
          hide($content['comments']);
          hide($content['links']);
          print '<div class="myyyyy">'.render($content).'</div>';
        ?>
      </div>
      
      <div class="clearfix">
        <?php if (!empty($content['links'])): ?>
          <nav class="links node-links clearfix"><?php print render($content['links']); ?></nav>
        <?php endif; ?>
    
        <?php print render($content['comments']); ?>
      </div>
    </article>
<?php endif; ?>

