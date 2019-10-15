/********************************************************************************************************************
 * Program: sea_otter.cpp
 * Author: Tu Lam
 * Date: 04/29/2019
 * Description: The sea_otter cpp file where all the function body is in a function.
 * Input: No input.
 * Output: No output.
 *******************************************************************************************************************/

#include <iostream>
#include <string>
#include "zoo.h"

using namespace std;

/***********************************************
 * Function:: Sea_Otter::Sea_Otter();
 * Input: None.
 * Output: Assigning the values to Animal class.
 **********************************************/
Sea_Otter::Sea_Otter() {

	set_age(730);
	set_animal_cost(5000);
	set_food_multiplier(2);
	set_income(250);
	set_babies(0);
}
