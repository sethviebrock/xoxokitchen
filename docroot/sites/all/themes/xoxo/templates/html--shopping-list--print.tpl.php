<?php print $doctype; ?>
<html lang="<?php print $language->language; ?>" dir="<?php print $language->dir; ?>"<?php print $rdf->version . $rdf->namespaces; ?>>
<head<?php print $rdf->profile; ?>>
  <?php print $head; ?>
  <title><?php print $head_title; ?></title>
  <link rel="stylesheet" type="text/css" href="<?php print base_path() . path_to_theme(); ?>/css/print_sl.css">
  <style>
    @media print {
      table {
        border: 1px solid #603813;
        width: 100%;
      }
      thead td {
        font-weight: bold;
      }
      td {
        padding: 5px;;
        border: 1px solid #603813;
        border-collapse: collapse;
        color: #603813;
        font-size: 12px;
        font-family: Georgia,'Times New Roman',Times,serif
      }
      .week-pager {
        margin-left: 10px;
      }
      #logo, .sh_pr_title {
        margin-left: 10px;
      }
    }
    @media screen {
      table {
        border: 1px solid #603813;
        width: 80%;
      }
      thead td {
        font-weight: bold;
      }
      td {
        padding: 5px;;
        border: 1px solid #603813;
        border-collapse: collapse;
        color: #603813;
        font-size: 17px;
        font-family: Georgia,'Times New Roman',Times,serif
      }
      #block-system-main, .sh_pr_title {
        margin-left: 80px;;
      }
      .week-pager {
        margin-left: 10px;
      }
      #logo, .sh_pr_title {
        margin-left: 90px;
      }
    }
  </style>
</head>
<body<?php print $attributes;?>>
  <?php print $page; ?>
</body>
</html>
