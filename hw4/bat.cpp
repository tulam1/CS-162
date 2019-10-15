/******************************************************************************************************
 * Program: bat.cpp
 * Author: Tu Lam
 * Date: 05/16/2019
 * Description: The implementation file to implement all the body function from class into the program.
 * Input: None.
 * Output: None.
 *****************************************************************************************************/

#include <iostream>
#include <string>
#include "event.h"
#include "bat.h"

using namespace std;

/******************************************************
 * Function: Bat::Bat();
 * Input: Assigning the protected variables with value.
 * Output: None.
 *****************************************************/
Bat::Bat() {

	message = "You hear wings flapping.";
	id = 'b';
}

/******************************************************
 * Function: void Bat::percept();
 * Input: None.
 * Output: Print out the message for the Bat class.
 *****************************************************/
void Bat::percept() {

	cout << get_message() << endl;
}

/******************************************************
 * Function: void Bat::set_id(char);
 * Input: Assigning the message variable with value.
 * Output: None.
 *****************************************************/
void Bat::set_id(char id) {

	this->id = id;
}

/******************************************************
 * Function: string Bat::get_message();
 * Input: None.
 * Output: Return the value of the message variable.
 *****************************************************/
string Bat::get_message() {

return message;
}

/******************************************************
 * Function: char Bat::get_id();
 * Input: None.
 * Output: Return the value of the message variable.
 *****************************************************/
char Bat::get_id() {

return id;
}
