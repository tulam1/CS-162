/*************************************************************************************************
 * Program: pizza.h
 * Author: Tu Lam
 * Date: 04/28/2019
 * Description: A pizza portal where customer can order and employee can modify the restaurant
 * Input: None
 * Output: None
 ************************************************************************************************/
 
#ifndef PIZZA_H
#define PIZZA_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include "./restaurant.h"

using namespace std;

class Pizza {

	private:
	string name;
	int small_cost;
	int medium_cost;
	int large_cost;
	int num_ingredients;
	string* ingredients;

	public:
	Pizza(); //Default Constructor
	~Pizza(); //Destructor
	Pizza(const Pizza &); //Copy Constructor
	Pizza &operator=(const Pizza &); //Assignment Overload

	void load_pizza();
	void set_ingredients_array(int);
	void fill_ingredients_array(string *, int);
	void set_name(string);
	string get_name();	
	void set_small(int);
	int get_small();
	void set_medium(int);
	int get_medium();
	void set_large(int);
	int get_large();
	void set_num_ingredients(int);
	int get_num_ingredients();
	void set_ingredients(string *);
	string *get_ingredients();
	void set_ingredients_at(int, string);
	string get_ingredients_at(const int);
	void display();
	bool check_ingredients(string);
};
#endif
