/******************************************************************************************************
 * Program: pit.cpp
 * Author: Tu Lam
 * Date: 05/16/2019
 * Description: The implementation file to implement all the body function from class into the program.
 * Input: None.
 * Output: None.
 *****************************************************************************************************/

#include <iostream>
#include <string>
#include "event.h"
#include "pit.h"

using namespace std;

/******************************************************
 * Function: Pit::Pit();
 * Input: Assigning the protected variables with value.
 * Output: None.
 *****************************************************/
Pit::Pit() {

	message = "You feel a breeze.";
  id = 'p';
}

/******************************************************
 * Function: void Pit::percept();
 * Input: None.
 * Output: Print out the message for the Pit class.
 *****************************************************/
void Pit::percept() {

	cout << get_message() << endl;
}

/******************************************************
 * Function: void Pit::set_id(char);
 * Input: None.
 * Output: Assign the variable in the member varaible.
 *****************************************************/
void Pit::set_id(char id) {

	this->id = id;
}

/******************************************************
 * Function: string Pit::get_message();
 * Input: None.
 * Output: Return the value of the message variable.
 *****************************************************/
string Pit::get_message() {

return message;
}

/******************************************************
 * Function: char Pit::get_id();
 * Input: None.
 * Output: Return the value of the message variable.
 *****************************************************/
char Pit::get_id() {

return id;
}
