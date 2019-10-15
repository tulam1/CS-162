/********************************************************************************************************************
 * Program: meerkat.cpp
 * Author: Tu Lam
 * Date: 04/29/2019
 * Description: The meerkat cpp file where all the function body is in a function.
 * Input: No input.
 * Output: No output.
 *******************************************************************************************************************/

#include <iostream>
#include <string>
#include "zoo.h"

using namespace std;


/***********************************************
 * Function: Meerkat::Meerkat();
 * Input: None.
 * Output: Assigning values to the Animal class.
 **********************************************/
Meerkat::Meerkat() {

	set_age(730);
	set_animal_cost(500);
	set_food_multiplier(1);
	set_income(25);
	set_babies(0);
}
