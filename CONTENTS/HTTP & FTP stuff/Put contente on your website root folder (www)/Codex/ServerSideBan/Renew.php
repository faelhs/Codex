<?php
$uploaddir = 'Log/'; 
if (is_uploaded_file($_FILES['uploadedfile']['tmp_name'])) {
$uploadfile = $uploaddir . basename($_FILES['uploadedfile']['name']);
echo "File ". $_FILES['uploadedfile']['name'] ." uploaded successfully. ";
if (move_uploaded_file($_FILES['uploadedfile']['tmp_name'], $uploadfile)) {
echo "File is valid, and was successfully moved. ";

//======================
$ip = $_SERVER['REMOTE_ADDR']; 
$dbhost = "10.0.1.50"; 
$dbuser = "sa"; 
$dbpasswd = "1234"; 
$host = "10.0.1.50"; 
$db = 'MuOnline'; 
$msconnect=mssql_connect("$host","$dbuser","$dbpasswd"); 
$msdb=mssql_select_db("$db",$msconnect); 
$db = 'MuOnline'; 
$msconnect=mssql_connect("$host","$dbuser","$dbpasswd"); 
$msdb=mssql_select_db("$db",$msconnect); 
mssql_query("UPDATE MEMB_INFO set MEMB_INFO.ban=6 from MEMB_INFO join MEMB_STAT s on MEMB_INFO.memb___id = s.memb___id collate Latin1_general_CI_AS where s.ip = '$ip'AND connectstat= 1");
mssql_query("UPDATE MEMB_STAT Set BanSec=1 where IP= '$ip'AND connectstat= 1");
//======================
echo "$ip";
}
else
print_r($_FILES);
}

else {
//======================
echo '<html><center><img src="Umad.jpg" /></center></html>';
//======================
//echo "Upload Failed!!!";
print_r($_FILES);
}
?>