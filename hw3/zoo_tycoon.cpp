/********************************************************************************************************************
 * Program: zoo_tycoon.cpp
 * Author: Tu Lam
 * Date: 04/29/2019
 * Description: A zoo tycoon game where users adopt animal and run a tycoon world where they try not to go brankrupt.
 * Input: The decision and stragety when it comes to playing the game.
 * Output: The outcome of the decision input from the users.
 *******************************************************************************************************************/

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "zoo.h"

using namespace std;

int main() {

	srand(time(NULL));
	Zoo z;
	
	z.main_menu();
}
