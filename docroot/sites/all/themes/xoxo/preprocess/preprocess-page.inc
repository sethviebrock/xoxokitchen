<?php
//$vars - all the page data.
if (arg(0) == 'user' && arg(1) == 'register') {
  $vars['tabs']['#access'] = FALSE;
  $vars['title_suffix'] = '<h2>' . t('Become A Member Today.') . '</h2>';
}
