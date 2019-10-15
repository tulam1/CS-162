/********************************************************************************************************************
 * Program: animal.cpp
 * Author: Tu Lam
 * Date: 04/29/2019
 * Description: The animal cpp file where all the function body is in a function.
 * Input: No input.
 * Output: No output.
 *******************************************************************************************************************/

#include <iostream>
#include <string>
#include "zoo.h"

using namespace std;

/*****************************************************
 * Function: Animal::Animal();
 * Input: None.
 * Output: Assigning the procted variable with values.
 ****************************************************/
Animal::Animal() {

	age = 0;
	animal_cost = 0;
	food_multiplier = 0;
	income = 0;
	babies = 0;	
}

/*************************************************
 * Function: void Animal::set_age(int);
 * Input: None.
 * Output: Setting up the age to assign it.
 ************************************************/
void Animal::set_age(int age) {

	this->age = age;
}

/**************************************************
 * Function: void Animal::set_animal_cost(float);
 * Input: None.
 * Output: Setting up the animal cost to assign it.
 *************************************************/
void Animal::set_animal_cost(float cost) {

	this->animal_cost = cost;
}

/**************************************************
 * Function: void Animal::set_food_cost(float);
 * Input: None.
 * Output: Setting up the food cost and assign it.
 *************************************************/
void Animal::set_food_multiplier(float f_cost) {

	this->food_multiplier = f_cost;
}

/**************************************************
 * Function: void Animal::set_income(float);
 * Input: None.
 * Output: Setting up the income and assign it.
 *************************************************/
void Animal::set_income(float income) {

	this->income = income;
}

/**********************************************
 * Function: void Animal::set_babies(int);
 * Input: None.
 * Output: Setting up the babies and assign it.
 *********************************************/
void Animal::set_babies(int baby) {

	this->babies = baby;
}

/**************************************************
 * Function: int Animal::get_age();
 * Input: None.
 * Output: Return the member variable age.
 *************************************************/
int Animal::get_age() {

return age;
}

/**************************************************
 * Function: float Animal::get_animal_cost();
 * Input: None.
 * Output: Return the member variable animal cost.
 *************************************************/
float Animal::get_animal_cost() {

return animal_cost;
}

/**************************************************
 * Function: float Animal::get_food_cost();
 * Input: None.
 * Output: Return the member variable food cost.
 *************************************************/
float Animal::get_food_multiplier() {

return food_multiplier;
}

/**************************************************
 * Function: float Animal::get_income();
 * Input: None.
 * Output: Return the member variable income.
 *************************************************/
float Animal::get_income() {

return income;
}

/**********************************************
 * Function: int Animal::get_babies();
 * Input: None.
 * Output: Return the member variable babies.
 *********************************************/
int Animal::get_babies() {

return babies;
}

/**************************************************
 * Function: void Animal::increment_age();
 * Input: None.
 * Output: Assign age with increment age.
 *************************************************/
void Animal::increment_age(int adjust) {

	this->age += adjust;
}

/**************************************************
 * Function: float Animal::food_expense(float);
 * Input: None.
 * Output: Return cost to get the total cost.
 *************************************************/
float Animal::food_expense(float base) {

	float cost = 0;

	if (age > 35) {
		cost = base * food_multiplier;
	}

	else if (age < 35) {
		cost = ((base * food_multiplier) * 2);
	} 

return cost;	
}

/**************************************************
 * Function: void Animal::add_babies(int);
 * Input: None.
 * Output: Adding the babies into the array.
 *************************************************/
void Animal::add_babies(int kid) {

	this->babies += kid;
}
