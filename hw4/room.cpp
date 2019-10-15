/******************************************************************************************************
 * Program: room.cpp
 * Author: Tu Lam
 * Date: 05/16/2019
 * Description: The implementation file to implement all the body function from class into the program.
 * Input: None.
 * Output: None.
 *****************************************************************************************************/

#include <iostream>
#include <string>
#include "room.h"

using namespace std;

/******************************************************
 * Function: Room::Room();
 * Input: Assigning the protected variables with value.
 * Output: None.
 *****************************************************/
Room::Room() {

	event_ptr = NULL;
}

/*********************************************************
 * Function: Room::~Room();
 * Input: Delete the protected variables if it's an array.
 * Output: None.
 ********************************************************/
Room::~Room() {

}

/******************************************************
 * Function: Room::Room(const Room &);
 * Input: Copying the protected variables with value.
 * Output: None.
 *****************************************************/
Room::Room(const Room &old_obj) {

  this->event_ptr = old_obj.event_ptr;
}

/********************************************************
 * Function: Room& Room::operator=(const Room &);
 * Input: Overloading the protected variables with value.
 * Output: None.
 *******************************************************/
Room& Room::operator=(const Room &old_obj) {
    
  this->event_ptr = old_obj.event_ptr;
  
return *this;
}

/******************************************************
 * Function: void Room::set_event_ptr(Event *);
 * Input: None.
 * Output: Set up and assign the member variable.
 *****************************************************/
void Room::set_event_ptr(Event *event_ptr) {

  this->event_ptr = event_ptr;
}

/******************************************************
 * Function: Event *Room::get_event_ptr();
 * Input: None.
 * Output: Return the pointer in the member variable.
 *****************************************************/
Event *Room::get_event_ptr() {

return event_ptr;
}
