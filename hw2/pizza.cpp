/*************************************************************************************************
 * Program: pizza.cpp
 * Author: Tu Lam
 * Date: 04/28/2019
 * Description: A pizza portal where customer can order and employee can modify the restaurant
 * Input: None
 * Output: None
 *************************************************************************************************/
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include "./restaurant.h"

using namespace std;

/****************************
 * Function: Pizza::Pizza();
 * Input: None
 * Output: None
 ***************************/
Pizza::Pizza() {

	name = " ";
	small_cost = 0;
	medium_cost = 0;
	large_cost = 0;
	num_ingredients = 0;
	ingredients = NULL;	
}

/****************************
 * Function: Pizza::~Pizza();
 * Input: None
 * Output: None
 ***************************/
Pizza::~Pizza(){

	if (this->ingredients != NULL) {
		delete[] this->ingredients;
   }
}

/**************************************
 * Function: Pizza::Pizza(const Pizza);
 * Input: None
 * Output: None
 *************************************/
Pizza::Pizza(const Pizza &old_p) {

	this->name = old_p.name;
  	this->small_cost = old_p.small_cost;
  	this->medium_cost = old_p.medium_cost;
   this->large_cost = old_p.large_cost;
   this->num_ingredients = old_p.num_ingredients;

	if (num_ingredients == 0) {
       	ingredients = NULL;
  	}
  
  	else {
		this->ingredients = new string[this->num_ingredients];
   	for (int i = 0; i < this->num_ingredients; i++) {
      	this->ingredients[i] = old_p.ingredients[i];
      }
   }
}

/*************************************************
 * Function: Pizza& Pizza::operator=(const Pizza);
 * Input: None
 * Output: None
 ************************************************/
Pizza& Pizza::operator=(const Pizza &old_p) {

	delete[] this->ingredients;	

	this->name = old_p.name;
  	this->small_cost = old_p.small_cost;
  	this->medium_cost = old_p.medium_cost;
   this->large_cost = old_p.large_cost;
   this->num_ingredients = old_p.num_ingredients;

	if (num_ingredients == 0) {
       	ingredients = NULL;
  	}
  
  	else {	
		this->ingredients = new string[this->num_ingredients];
   	for (int i = 0; i < this->num_ingredients; i++) {
      	this->ingredients[i] = old_p.ingredients[i];
      }
   }

return *this;
}

void Pizza::set_ingredients_array(int num_ingredients) {

	ingredients = new string[num_ingredients];
}

void Pizza::fill_ingredients_array(string *kind_p, int num_ingredients) {

	for (int i = 0; i < num_ingredients; i++) {
		ingredients[i] = kind_p[i];
	}
}

/***********************************
 * Function: void Pizza::set_name();
 * Input: None
 * Output: None
 **********************************/
void Pizza::set_name(string name) {

	this->name = name;
}

/***********************************
 * Function: string Pizza::get_name();
 * Input: None
 * Output: None
 **********************************/
string Pizza::get_name() {

return name;
}

/*******************************
 * Function: Pizza::set_small();
 * Input: None
 * Output: None
 ******************************/
void Pizza::set_small(int small) {

	this->small_cost = small;
}

/***********************************
 * Function: int Pizza::get_small();
 * Input: None
 * Output: None
 **********************************/
int Pizza::get_small() {

return small_cost;
}

/*******************************
 * Function: Pizza::set_medium();
 * Input: None
 * Output: None
 ******************************/
void Pizza::set_medium(int medium) {

	this->medium_cost = medium;
}

/***********************************
 * Function: int Pizza::get_medium();
 * Input: None
 * Output: None
 **********************************/
int Pizza::get_medium() {

return medium_cost;
}

/*******************************
 * Function: Pizza::set_large();
 * Input: None
 * Output: None
 ******************************/
void Pizza::set_large(int large) {

	this->large_cost = large;
}

/***********************************
 * Function: int Pizza::get_large();
 * Input: None
 * Output: None
 **********************************/
int Pizza::get_large() {

return large_cost;
}

/*****************************************
 * Function: Pizza::set_num_ingredients();
 * Input: None
 * Output: None
 ****************************************/
void Pizza::set_num_ingredients(int num) {

	this->num_ingredients = num;
}

/********************************************
 * Function: int Pizza::get_num_ingredients();
 * Input: None
 * Output: None
 *******************************************/
int Pizza::get_num_ingredients() {

return num_ingredients;
}

/*****************************************
 * Function: Pizza::set_ingredients();
 * Input: None
 * Output: None
 ****************************************/
void Pizza::set_ingredients(string *ingredients) {

	this->ingredients = ingredients;
}

/********************************************
 * Function: string *Pizza::get_ingredients();
 * Input: None
 * Output: None
 *******************************************/
string *Pizza::get_ingredients() {

return ingredients;
}

void Pizza::set_ingredients_at(int position, string ingredients) {

	this->ingredients[position] = ingredients;
}

string Pizza::get_ingredients_at(const int position) {

return ingredients[position];
}

/********************************************
 * Function: void Pizza::display();
 * Input: None
 * Output: None
 *******************************************/
void Pizza::display() {
	
	for (int i = 0; i < num_ingredients; i++) {
		cout << " "  << ingredients[i];
	}
}

/********************************************
 * Function: bool Pizza::check_ingredients();
 * Input: None
 * Output: None
 *******************************************/
bool Pizza::check_ingredients(string food) {

	for (int i = 0; i < num_ingredients; i++) {
		if (ingredients[i] == food) {
			return true;
		}
	}

return false;
}

/*Pizza::Pizza(const Pizza &old_pizza) {

	this->name = old_pizza.get_name();
	this->small_cost = old_pizza.get_small();
	this->medium_cost = old_pizza.get_medium();
	this->large_cost = old_pizza.get_large();
	this->num_ingredients = old_pizza.get_num_ingredients();
	this->ingredients = new string[num_ingredients];

	for (int i = 0; i < num_ingredients; i++) {
		this->ingredients[i] = old_pizza.get_ingredients_at(i);
	}
}*/

/*Pizza& Pizza::operator=(const Pizza &old_piz) {

	name = old_piz.get_name();
	small_cost = old_piz.get_small();
	medium_cost = old_piz.get_medium();
	large_cost = old_piz.get_large();
	num_ingredients = old_piz.get_num_ingredients();
	ingredients = new string[num_ingredients];

	for (int i = 0; i < num_ingredients; i++) {
		ingredients[i] = old_piz.get_ingredients_at(const i);
	}

return *this;
}*/
