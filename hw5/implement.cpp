/****************************************************************************************
 * Program: implement.cpp
 * Author: Tu Lam
 * Date: 05/28/2019
 * Description: The implementation file that contain the function to use for the program.
 * Input: None.
 * Output: None.
 ***************************************************************************************/

#include <iostream>
#include <string>
#include <cstdlib>
#include "header.h"

using namespace std;

/***************************************************
 * Function: void main_title();
 * Input: None.
 * Output: Display the name of the program.
 **************************************************/
void main_title() {

	cout << "___________________" << endl;
	cout << "Linked List Program" << endl;
	cout << "-------------------" << endl;
}

/************************************************************
 * Function: int check_i(string);
 * Input: The string on what the user enter.
 * Output: Check if the string that user enter is an integer.
 ***********************************************************/
int check_i(string input) {

	int good_i = 0;
	bool correct;

	do {
		correct = false;
		for (unsigned int i = 0; i < input.length(); i++) {
			if ((input.at(i) == '-') && (i == 0)) {
				
			}

			else if (!(input.at(i) >= '0' && input.at(i) <= '9')) {
				cout << "Sorry! The number you enter was not an integer, please try again: ";
				cin >> input;
				correct = true;
				break;
			}
		}
	} while (correct);

	good_i = atoi(input.c_str());

return good_i;
}
