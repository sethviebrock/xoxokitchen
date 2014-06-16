<?php print $doctype; ?>
<html lang="<?php print $language->language; ?>" dir="<?php print $language->dir; ?>"<?php print $rdf->version . $rdf->namespaces; ?>>
<head<?php print $rdf->profile; ?>>
  <?php print $head; ?>
  <title><?php print $head_title; ?></title>
  <link rel="stylesheet" type="text/css" href="<?php print base_path() . path_to_theme(); ?>/css/print_sl.css">
  <style>
    @media print {
      @page {
        size: landscape;
      }
      body {
        margin: 0;
      }
      .name {
        width: 160px;
      }
      .description {
        width: 450px;
      }
     .brand {
        width: 120px;
      }
      table {
        border: 1px solid #603813;
        width: 100%;
        border-collapse: separate;
	      text-align: left;
        margin-left: auto;
        margin-right: auto;
      }
      th {
        font-weight: bold;
      }
      td, th {
        padding: 5px;;
        border: 1px solid #603813;
        border-collapse: separate;
        color: #603813;
        font-size: 10px;
//        font-family: Georgia,'Times New Roman',Times,serif
      }
      .week-pager {
        margin-left: 10px;
      }
      .amount {
        width: 150px;
      }
      #logo, .sh_pr_title {
        margin-left: 10px;
      }
    }
    @media screen {
      .name {
        width: 160px;
	  }
	  .description {
        width: 450px;
	  }
	  .brand {
	    width: 120px;
      }
      table {
        margin-left: 80px;
        border: 1px solid #603813;
        width: 80%;
        border-collapse: separate;
        text-align: left;
      }
      th {
        font-weight: bold;
      }
      td, th {
        padding: 5px;;
        border: 1px solid #603813;
        color: #603813;
        font-size: 17px;
//        font-family: Georgia,'Times New Roman',Times,serif
      }
      #block-system-main, .sh_pr_title {
//        margin-left: 80px;
      }
      .week-pager {
        margin-left: 10px;
      }
      #logo, .sh_pr_title {
//        margin-left: 90px;
      }
    }
  </style>
</head>
<body<?php print $attributes;?>>
  <?php print $page; ?>
</body>
</html>
