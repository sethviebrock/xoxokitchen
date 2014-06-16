<div class="nutritional">
  <?php foreach($nutritional as $delta => $data): ?>
    <div><?php print $data['property']; ?>: <?php print $data['amount_render']; ?> <?php print $data['uom']; ?></div>
  <?php endforeach; ?>
</div>