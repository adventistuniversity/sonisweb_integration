<?php

function check_availability () {
	// Make a test sql call to Sonis to check it's availability
	if(sonisweb_integration_test_sql()) {
		echo "Success"; 
	}
}