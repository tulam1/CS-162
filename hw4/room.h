/******************************************************************************************
 * Program: room.h
 * Author: Tu Lam
 * Date: 05/16/2019
 * Description: The header file to implement class into the program.
 * Input: None.
 * Output: None.
 *****************************************************************************************/

#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <string>
#include "event.h"
#include "wumpus.h"
#include "gold.h"
#include "bat.h"
#include "pit.h"
#include "player.h"

using namespace std;

class Room {

	protected:
		Event *event_ptr;
		char special_event;	

	public:

		//All of the Big 3 & Constructor
		Room(); //Default Constructor
		~Room(); //Destructor
    	Room(const Room &); //Copy Constructor
    	Room& operator=(const Room &); //Assignment Overload

		//Accessors
		char get_special_event();
    	Event *get_event_ptr();
    

		//Mutators
		void set_special_event(char);
    	void set_event_ptr(Event *);

		//All other functions

};

#endif
