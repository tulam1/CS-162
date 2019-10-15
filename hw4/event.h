/******************************************************************************************
 * Program: event.h
 * Author: Tu Lam
 * Date: 05/16/2019
 * Description: The header file to implement class into the program.
 * Input: None.
 * Output: None.
 *****************************************************************************************/

#ifndef EVENT_H
#define EVENT_H

#include <iostream>
#include <string>

using namespace std;

class Event {

	protected:
		string message;
		char id;

	public:

		//All of the Big 3 & Constructor
		Event(); 

		//Accessors
		virtual string get_message(); //Virtual function (Polymorphic)
		virtual char get_id() = 0; //Pure virtual function (Polymorphic)

		//Mutators
		void set_message(string);	
		virtual void set_id(char);	//Virtual function (Polymorphic)

		//All other functions
		virtual void percept() = 0; //Pure virtual function (Polymorphic)
};

#endif
