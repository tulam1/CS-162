/******************************************************************************************************
 * Program: wumpus.cpp
 * Author: Tu Lam
 * Date: 05/16/2019
 * Description: The implementation file to implement all the body function from class into the program.
 * Input: None.
 * Output: None.
 *****************************************************************************************************/

#include <iostream>
#include <string>
#include "event.h"
#include "wumpus.h"

using namespace std;

/******************************************************
 * Function: Wumpus::Wumpus();
 * Input: Assigning the protected variables with value.
 * Output: None.
 *****************************************************/
Wumpus::Wumpus() {

	message = "You smell a terrible stench.";
	id = 'w';
}

/******************************************************
 * Function: void Wumpus::percept();
 * Input: None.
 * Output: Print out the message for the Wumpus class.
 *****************************************************/
void Wumpus::percept() {

	cout << get_message() << endl;
}

/******************************************************
 * Function: void Wumpus::set_id(char);
 * Input: None.
 * Output: Assign the value to the member variable.
 *****************************************************/
void Wumpus::set_id(char id) {

	this->id = id;
}

/******************************************************
 * Function: string Wumpus::get_message();
 * Input: None.
 * Output: Return the value of the message variable.
 *****************************************************/
string Wumpus::get_message() {

return message;
}

/******************************************************
 * Function: char Wumpus::get_id();
 * Input: None.
 * Output: Return the value of the message variable.
 *****************************************************/
char Wumpus::get_id() {

return id;
}
