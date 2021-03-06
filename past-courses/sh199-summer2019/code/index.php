<?php
  $wd = "~sbaker/sh/code/";
  $view = isset($_GET['view'])? htmlspecialchars($_GET['view']) : null;
  $dir = isset($_GET['dir'])? htmlspecialchars($_GET['dir']) : ".";
  if ($dir != ".") {
    $wd .= substr($dir, 2);
    if (dirname($dir) == ".") $prev = "?";
    else $prev = "?dir=" . dirname($dir);
  } else {
    $prev = "..";
  }
  if (strstr($dir, "..") !== false || $dir[0] == "/") {
    echo "Relative paths including .. or absolute paths are not allowed.";
    exit(1);
  }
  if (strstr($view, "..") !== false || $view[0] == "/") {
    echo "Relative paths including .. or absolute paths are not allowed.";
    exit(1);
  }
  if (strstr($dir, ":/") !== false || strstr($view,":/") !== false) {
    echo "URL's are not allowed in paths or file-names.";
    exit(1);
  }
  if ($dir[0] != '.' || ($view != null && $view[0] != '.')) {
    echo "Invalid path.";
    exit(1);
  }
  if ($view == null) {
?>
<!DOCTYPE html>
<html>
<head>
 <title>Index of <?php echo "$wd"; ?></title>
 <meta charset='utf-8'>
 <style>
 * { font-family: "Arial"; }
 </style>
</head>
<body>
<h1>Index of <?php echo "$wd"; ?></h1>
<ul>
 <li><a href='<?php echo "$prev"; ?>'> Parent Directory </a></li>
<?php
  $files = scandir($dir);
  foreach($files as $file) {
    if ($file[0] == "." || $file == "index.php" ) continue;
    if (is_dir($dir ."/". $file)) {
      echo "<li><a href='?dir=$dir/$file'> $file </a></li>";
    } else {
      echo "<li><a download style='text-decoration: none; font-weight: bold;' href='$dir/$file'>[&DownArrowBar;]<a>";
      echo "<a href='$dir/$file'> $file </a>";
      echo " <a href='?view=$dir/$file'> (view source) </a></li>";
    }
  }
?>
</ul>
</body>
</html>
<?php
  } else {
?>
<!DOCTYPE html>
<html>
<head>
 <title>Displaying <?php echo "$view"; ?></title>
 <meta charset='utf-8'>
 <style>
  #editor {
    font-size: 14pt;
    margin: 0;position: absolute;
    top: 0; bottom: 0; left: 0; right: 0;
  }
 </style>
 <script src="/~sbaker/js/ace/ace.js" type="text/javascript" charset="utf-8"></script>
</head>
<body>
<pre id='editor'>
<?php
  $exts = array(
    "html" => "html", "php" => "php", "c" => "c_cpp", "cpp" => "c_cpp",
    "js" => "javascript", "sql" => "mysql", "mysql" => "mysql",
    "sh" => "sh", "css" => "css", "java" => "java", "py" => "python",
    "txt" => "text", "s" => "assembly_x86", "asm" => "assembly_x86"
  );
  $ext = substr(strrchr($view, "."), 1);
  if (isset($exts[$ext])) $ext = $exts[$ext];
  $data = htmlspecialchars(file_get_contents($view));
  echo "$data";
?>
</pre>
<script>
    var editor = ace.edit("editor");
    editor.setTheme("ace/theme/tomorrow");
    editor.session.setMode("ace/mode/<?php echo "$ext";?>");
    editor.session.setOption("tabSize", 8);
    editor.setReadOnly(true);
</script>
</body>
</html>
<?php
  }
?>
