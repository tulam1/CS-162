/******************************************************************************************************
 * Program: event.cpp
 * Author: Tu Lam
 * Date: 05/16/2019
 * Description: The implementation file to implement all the body function from class into the program.
 * Input: None.
 * Output: None.
 *****************************************************************************************************/

#include <iostream>
#include <string>
#include "event.h"

using namespace std;

/******************************************************
 * Function: Event::Event();
 * Input: Assigning the protected variables with value.
 * Output: None.
 *****************************************************/
Event::Event() {

	message = " ";
	id = ' ';
}

/******************************************************
 * Function: void Event::set_message(string);
 * Input: Assigning the message variable with value.
 * Output: None.
 *****************************************************/
void Event::set_message(string message) {

	this->message = message;
}

/******************************************************
 * Function: void Event::set_id(char);
 * Input: Assigning the message variable with value.
 * Output: None.
 *****************************************************/
void Event::set_id(char id) {

	this->id = id;
}

/******************************************************
 * Function: string Event::get_message();
 * Input: None.
 * Output: Return the value of the message variable.
 *****************************************************/
string Event::get_message() {

return message;
}
