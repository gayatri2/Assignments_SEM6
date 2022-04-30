<?php 
$fname = $_POST['firstname'];
$lname = $_POST['lastname'];

$connection = mysql_connect("localhost","root","amazing","php_db");
if(!$connection)
{
    die("Couldn't connect to db");
}

$result = mysql_query($connection,"insert into register values('$fname','$lname')");

if(!$result)
{
    die('Error in query');
}
else
{
    echo "Data inserted successfully";
}
?>