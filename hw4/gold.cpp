/******************************************************************************************************
 * Program: gold.cpp
 * Author: Tu Lam
 * Date: 05/16/2019
 * Description: The implementation file to implement all the body function from class into the program.
 * Input: None.
 * Output: None.
 *****************************************************************************************************/

#include <iostream>
#include <string>
#include "event.h"
#include "gold.h"

using namespace std;

/******************************************************
 * Function: Gold::Gold();
 * Input: Assigning the protected variables with value.
 * Output: None.
 *****************************************************/
Gold::Gold() {

	message = "You see a glimmer nearby.";
  id = 'g';
}

/******************************************************
 * Function: void Gold::percept();
 * Input: None.
 * Output: Print out the message for the Gold class.
 *****************************************************/
void Gold::percept() {

	cout << get_message() << endl;
}

/******************************************************
 * Function: void Gold::set_id();
 * Input: None.
 * Output: Assign value to the member variable.
 *****************************************************/
void Gold::set_id(char id) {

	this->id = id;
}

/******************************************************
 * Function: string Gold::get_message();
 * Input: None.
 * Output: Return the value of the message variable.
 *****************************************************/
string Gold::get_message() {

return message;
}

/******************************************************
 * Function: char Gold::get_id();
 * Input: None.
 * Output: Return the value of the message variable.
 *****************************************************/
char Gold::get_id() {

return id;
}
