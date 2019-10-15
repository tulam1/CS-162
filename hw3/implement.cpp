/********************************************************************************************************************
 * Program: implement.cpp
 * Author: Tu Lam
 * Date: 04/29/2019
 * Description: The implementation cpp file where all the function body is in a function.
 * Input: No input.
 * Output: No output.
 *******************************************************************************************************************/

#include <iostream>
#include <string>
#include <cstdlib>
#include "zoo.h"

using namespace std;

/*******************************************
 * Function: void title_screen();
 * Input: None.
 * Output: The title screen of the program.
 ******************************************/
void title_screen() {

	cout << "_______________" << endl;
	cout << "Zoo Tycoon Game" << endl;
	cout << "---------------" << endl;
}

/*******************************************
 * Function: void random_event_title();
 * Input: None.
 * Output: The title screen of random event.
 ******************************************/
void random_event_title() {

	cout << endl;
	cout << "Random Events from Zoo" << endl;
	cout << "----------------------" << endl;
}

/*************************************************
 * Function: int check_i(string);
 * Input: None.
 * Output: Check if users enter in a whole number.
 ************************************************/
int check_i(string input) {

	int good_i = 0;
	bool recheck;

	do {
		recheck = false;
		for (int i = 0; i < input.size(); i++) {
			if (!(input.at(i) >= '0' && input.at(i) <= '9')) {
				cout << "Your input was not an integer, please try again: ";
				getline(cin,input);
				recheck = true;
				break;
			}
		}
	} while (recheck);

	good_i = atoi(input.c_str());

return good_i;
}
