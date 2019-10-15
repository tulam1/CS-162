/******************************************************************************************
 * Program: wumpus.h
 * Author: Tu Lam
 * Date: 05/16/2019
 * Description: The header file to implement class into the program.
 * Input: None.
 * Output: None.
 *****************************************************************************************/

#ifndef WUMPUS_H
#define WUMPUS_H

#include <iostream>
#include <string>
#include "event.h"

using namespace std;

class Wumpus : public Event {

	public:

		//All of the Big 3 & Constructor
		Wumpus(); //Default Constructor

		//Accessors
		virtual string get_message() override; //Child class override the function in Parent class
		virtual char get_id() override; //Child class override the function in Parent class (Mandatory)

		//Mutators
		virtual void set_id(char) override; //Child class override the function in Parent class

		//All other functions
		virtual void percept() override; //Child class override the function in Parent class (Mandatory)
};

#endif
