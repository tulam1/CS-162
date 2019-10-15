/********************************************************************************************************************
 * Program: zoo.h
 * Author: Tu Lam
 * Date: 04/29/2019
 * Description: The header file for the zoo_tycoon.cpp including all function prototype.
 * Input: None input.
 * Output: None output.
 *******************************************************************************************************************/

#ifndef ZOO_H
#define ZOO_H

#include <iostream>
#include <string>
#include <cstdlib>
#include "header.h"
#include "animal.h"
#include "monkey.h"
#include "sea_otter.h"
#include "meerkat.h"

using namespace std;

class Zoo {

	private:
	int week;
	float bank;
	float base_food;
	int capacity;
	bool bankrupt;
	int num_monkey;
	int num_sea_otter;
	int num_meerkat;
	Monkey *monkey_arr;
	Sea_Otter *sea_otter_arr;
	Meerkat *meerkat_arr;


	public:
	Zoo(); //Default Constructor
	~Zoo(); //Destructor
	Zoo(const Zoo &); //Copy Constructor
	Zoo& operator=(const Zoo &); //Assignment Overload

	void main_menu();
	void play_again(bool &);	
	void increment_animal();
	void buy_animal();
	void animal_type(int, int);
	void cost_deduction();
	void random_events();
	void add_monkey();
	void add_sea_otter();
	void add_meerkat();
	void increase_capacity_monkey();
	void increase_capacity_sea_otter();
	void increase_capacity_meerkat();
	void set_week(int);
	int get_week();
	void set_bank(float);
	float get_bank();
	void set_base_food(float);
	float get_base_food();
	void sick_animal();
	void sick_monkey();
	void sick_sea_otter();
	void sick_meerkat();
	void remove_monkey(int);
	void remove_sea_otter(int);
	void remove_meerkat(int);
	void babies_populate();
	void add_monkey_babies();
	void add_sea_otter_babies();
	void add_meerkat_babies();
	void revenue_bonus();
	void revenue_collect();
};

#endif
