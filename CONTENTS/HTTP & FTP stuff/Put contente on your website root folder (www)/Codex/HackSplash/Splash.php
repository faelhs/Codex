<?php
//date_default_timezone_set("America/New_York");
date_default_timezone_set("Brazil/East");
$Time = date("h:i:sa");
//echo "The time is " . date("h:i:sa");
//================================================
$ip = $_SERVER['REMOTE_ADDR'];
//echo "Your IP adddress: $ip";
//================================================
$file = "Log.txt";
$file = fopen($file, "a"); 
$data = "$Time, $ip \r\n";
fwrite($file, $data); 
fclose($file); 
//================================================
echo '<html><center><img src="Splash.jpg" /></center></html>';
?>