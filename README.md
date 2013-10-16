SONISWEB Integration Module
===========================

This is a set of developer APIs that allows Drupal to interact with the SONISWEB Academic Administration System (Version 2.3 or higher).

What this module does not do

* Provide any functionality visible to users.

What this module does do

* Allows all of the authentication data to be centrally maintained.
* Provides an easy abstracted way to call the SONISWEB APIs.
* Provides an easy abstracted way to run read only SQL queries.
* Converts ColdFusion SQL results into PHP like SQL results.
* Converts html dropboxes to Form API options array.
* Converts a SQL query to a Form API options array

Some Important Notes:

* This module is not maintained by RJM Systems. Please don't report problems to them! Report them in the issue queue.
* The SONISWEB API will prevent any non-read only SQL queries from running. However, you are responsible for preventing SQL injection attacks.
* The available SONISWEB APIs are listed in your SONISWEB documentation.
* This module requires PHP 5, the SOAP extension and highly recommends the OpenSSL extension.
* If you are new to Drupal read the Module Developer Guide for more information.

## Installation

### Requirements
* SONISWEB 2.3 or higher
* PHP 5.x
* SOAP Extension
* OpenSSL Extension
* Willingness to write your own custom Drupal modules

### Installation
Normal Drupal module installation, see [this page](https://drupal.org/node/70151) for further information.

## Use 
### API Calls
Your code should try to exclusively use API calls.

Here is an example of how to call the fictitious graduateAllProspects function.

    ...
    $results = sonisweb_integration_api("CFC.graduateAllProspects", "graduateThemAll", "yes",
                                                    array(array('adminUsername', '@username'),
                                                            array('reason', $reason)));
    ...

What those things mean.

* $results holds the results returned by the function.
* sonisweb_integration_api() The function that actually calls the SONISWEB API.
* CFC.graduateAllProspects The location of the API call. See your documentation.
* graduateThemAll The actual function name you are calling.
* "yes" This is a yes no flag that specifies if the function returns a variable (yes) or outputs text (no). (If one doesn't work try the other.)
* array(array('adminUsername', '@username'), array('reason', $reason)) The arguments required by the graduateThemAll function.
* array('adminUsername', '@username') Argument name is adminUsername, value is @username (Note: @username is a special value. It will dynamically be replaced by the Administrative Username stored by this module. @password will be similarly be replaced.)
* array('reason', $reason) Argument name is reason, Argument Value will be $reason

### SQL Calls
This functionality should only be used sparingly.

    ...
    $results = sonisweb_integration_sql($sql);
    ...
    
* sonisweb_integration_sql() The function that actually makes the SONISWEB API call.
* $sql The SQL Command you wish to run. (Note: Tha API will only run select commands. However, you are still responsible for preventing SQL Injection attacks
* $results The SQL results. They are returned in a 2D associative array with the rows numbered and the columns are named. (i.e. 0 => ([course] => 'English', ...), 1 => ([course] => 'Math', ...))

## Configuration

1. Goto Administer / Site Configuration / SONISWEB Integration Settings
2. Enter the Base URL to the SONISWEB SOAP functionality.
3. Enter the SONISWEB Administrator Username that your site will use.
4. Enter the password associated with the SONISWEB Administrator Username.
5. Click Save Settings


### Notes
* The permissions granted to the SONISWEB Administrator may restrict the available SONISWEB API Functions.
* You cannot save invalid settings here. It checks the connection before allowing you to save.
* Once settings are saved the password field will be empty. However, that password is saved. To change the password simply enter a new one and click Save Settings.
* Beware of entering false passwords here. You will disable you SONISWEB administrator account.
