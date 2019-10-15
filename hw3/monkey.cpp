/********************************************************************************************************************
 * Program: monkey.cpp
 * Author: Tu Lam
 * Date: 04/29/2019
 * Description: The monkey cpp file where all the function body is in a function.
 * Input: No input.
 * Output: No output.
 *******************************************************************************************************************/

#include <iostream>
#include <string>
#include "zoo.h"

using namespace std;

/*********************************************
 * Function: Monkey::Monkey()
 * Input: None.
 * Output: Assigning value to the animal class
 ********************************************/
Monkey::Monkey() {

	set_age(730);
	set_animal_cost(15000);
	set_food_multiplier(4);
	set_income(1500);
	set_babies(0);
}

