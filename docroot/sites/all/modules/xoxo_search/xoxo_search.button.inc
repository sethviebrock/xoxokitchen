<?php
function _xoxo_search_button_hack($content, $element) {
  return str_replace('type="submit"', 'type="button"', $content);
}
