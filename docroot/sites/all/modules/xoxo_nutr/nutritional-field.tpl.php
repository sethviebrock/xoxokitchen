<div class="nutritional">
  <?php foreach($nutritional as $delta => $data): ?>
    <?php print $data['property']; ?>
    <?php print $data['amount_render']; ?>
    <?php print $data['uom']; ?>
  <?php endforeach; ?>
</div>