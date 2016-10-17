<?php

// For more information, please visit: http://www.swduino.com/

class swDuino
{
	public $server="10.10.2.99";
	public $port=8085;

	public function test()
	{
		return(file_get_contents("http://".$this->server.":".$this->port."/test"));
	}

	public function timer()
	{
		return(file_get_contents("http://".$this->server.":".$this->port."/timer"));
	}

	public function com()
	{
		return(file_get_contents("http://".$this->server.":".$this->port."/com"));
	}

	public function get($variable="")
	{
		return(file_get_contents("http://".$this->server.":".$this->port."/get/".$variable));
	}


	public function getlike($variable="")
	{
		return(file_get_contents("http://".$this->server.":".$this->port."/getlike/".$variable));
	}

	public function set($variable,$value)
	{
		return(file_get_contents("http://".$this->server.":".$this->port."/set/".$variable."/".$value));
	}

	public function setlike($variable,$value)
	{
		return(file_get_contents("http://".$this->server.":".$this->port."/setlike/".$variable."/".$value));
	}

	public function put($variable,$value)
	{
		return(file_get_contents("http://".$this->server.":".$this->port."/put/".$variable."/".$value));
	}

	public function putlike($variable,$value)
	{
		return(file_get_contents("http://".$this->server.":".$this->port."/putlike/".$variable."/".$value));
	}

	public function push($variable="")
	{
		return(file_get_contents("http://".$this->server.":".$this->port."/push/".$variable));
	}

	public function pushlike($variable="")
	{
		return(file_get_contents("http://".$this->server.":".$this->port."/pushlike/".$variable));
	}

	public function unset_($variable)
	{
		return(file_get_contents("http://".$this->server.":".$this->port."/unset/".$variable));
	}

	public function unsetlike($variable)
	{
		return(file_get_contents("http://".$this->server.":".$this->port."/unsetlike/".$variable));
	}

	public function reset()
	{
		return(file_get_contents("http://".$this->server.":".$this->port."/reset"));
	}
}
?>