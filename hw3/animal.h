/********************************************************************************************************************
 * Program: animal.h
 * Author: Tu Lam
 * Date: 04/29/2019
 * Description: The header file for the zoo_tycoon.cpp including all function prototype.
 * Input: None input.
 * Output: None output.
 *******************************************************************************************************************/

#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <string>
#include <cstdlib>
#include "zoo.h"

using namespace std;

class Animal {

	protected:
	int age;
	float animal_cost;
	float food_multiplier;
	float income;
	int babies;
	

	public:
	Animal(); //Default Constructor

	void set_age(int);
	void set_animal_cost(float);
	void set_food_multiplier(float);
	void set_income(float);
	void set_babies(int);
	int get_age();
	float get_animal_cost();
	float get_food_multiplier();
	float get_income();
	int get_babies();
	void increment_age(int);
	float food_expense(float);
	void add_babies(int);

};

#endif
