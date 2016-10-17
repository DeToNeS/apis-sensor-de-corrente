<html>
<head>
	<title>swDuino-PHP (Class) Interface Example</title>
</head>
<body>

<p>
In this example, <i>swduino.class.php</i> class is used to access swDuino via <a href='http://www.swduino.com/?tab=api' target='_blank'>HTTP APIs</a>.
</p>

<?php
	include("swduino.class.php");
	$swDuino = new swDuino();
	$response = $swDuino->get('P');
?>

<p>
Response of <i>test()</i>: <?php echo $response;?>
</p>

</body>
</html>