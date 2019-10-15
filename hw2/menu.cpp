/**********************************************************************************************
 * Program: menu.cpp
 * Author: Tu Lam
 * Date: 04/28/2019
 * Description: A pizza portal where customer can order and employee can modify the restaurant
 * Input: None
 * Output: None
 *********************************************************************************************/

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <bits/stdc++.h>
#include "./restaurant.h"

using namespace std;

/************************
 * Function: Menu::Menu()
 * Input: None
 * Output: None
 ***********************/
Menu::Menu() {

	num_pizza = 0;
	pizzas = NULL;
}

/*************************
 * Function: Menu::~Menu()
 * Input: None
 * Output: None
 ***********************/
Menu::~Menu(){

  if(pizzas != NULL) {
    delete [] pizzas;
  }
  
  pizzas = NULL;
}

/********************************************
 * Function: Menu::Menu(const Menu &old_menu)
 * Input: None
 * Output: None
 *******************************************/
Menu::Menu(const Menu &old_menu) {	

	this->num_pizza = old_menu.num_pizza;

	if(this->num_pizza > 0) {
		this->pizzas = new Pizza[this->num_pizza];
		
		for(int i = 0; i < this->num_pizza; i++) {
      	this->pizzas[i] = old_menu.pizzas[i];
    	}
	}

	else {
    this->pizzas = NULL;
	}
}

/*******************************************************
 * Function: Menu& Menu::operator=(const Menu &old_menu)
 * Input: None
 * Output: None
 ******************************************************/
Menu& Menu::operator=(const Menu &old_menu) {	

	delete[] this->pizzas;
	this->num_pizza = old_menu.num_pizza;

	if(this->num_pizza > 0) {
		this->pizzas = new Pizza[this->num_pizza];
		
		for(int i = 0; i < this->num_pizza; i++) {
      	this->pizzas[i] = old_menu.pizzas[i];
    	}
	}

	else {
    this->pizzas = NULL;
	}

return *this;
}

/*********************************
 * Function: void Menu::get_info()
 * Input: None
 * Output: None
 ********************************/
void Menu::get_info() {

	string read2;
	Pizza tmp;
	int tmp_num = 0;

	fstream menu_db;
	menu_db.open("menu.txt");
	while (!menu_db.is_open()) {
		cout << "No file was detected for menu! Program will exit.. ." << endl;
		exit(1);
	}
	num_line(tmp_num,read2,menu_db);
	set_num_pizza(tmp_num);
	menu_db.close();
	load_data();	
}

/*********************************
 * Function: void Menu::load_data()
 * Input: None
 * Output: None
 ********************************/
void Menu::load_data() {

	string line, name, small, medium, large, num_ingredients, ingredients;

	fstream menu_db;
	menu_db.open("menu.txt");
	this->pizzas = new Pizza[num_pizza];

	for (int i = 0; i < num_pizza-1; i++) {
		getline(menu_db,line);
		istringstream pi(line);
		pi >> name;
		pi >> small;
		pi >> medium;
		pi >> large;
		pi >> num_ingredients;
		this->pizzas[i].set_name(name);
		this->pizzas[i].set_small(atoi(small.c_str()));
		this->pizzas[i].set_medium(atoi(medium.c_str()));
		this->pizzas[i].set_large(atoi(large.c_str()));
		this->pizzas[i].set_num_ingredients(atoi(num_ingredients.c_str()));

		string *food = new string[atoi(num_ingredients.c_str())];
	
		for (int j = 0; j < atoi(num_ingredients.c_str()); j++) {
			pi >> ingredients;
			food[j] = ingredients;
		}	
		this->pizzas[i].set_ingredients(food);
	}
	menu_db.close();	
}

/*************************************
 * Function: void Menu::display_menu()
 * Input: None
 * Output: None
 *************************************/
void Menu::display_menu() {

	cout << "\nRestaurant Menu" << endl;
	cout << "---------------" << endl;

	for (int i = 0; i < num_pizza-1; i++) {
		cout << pizzas[i].get_name() << " " << pizzas[i].get_small() << " " << pizzas[i].get_medium();
		cout << " " << pizzas[i].get_large() << " " << pizzas[i].get_num_ingredients();
		pizzas[i].display();
		cout << endl;	
	}

}

/*************************************
 * Function: void Menu::add_to_menu()
 * Input: None
 * Output: None
 *************************************/
void Menu::add_to_menu() {

	Pizza p1;
	string name, s, m, l, num_ingredients, ingredients;
	int s1, m2, l3, num;

	cout << "\nAdd To Menu" << endl;
	cout << "-----------" << endl;
	cout << "What you want to name the pizza? ";
	getline(cin,name);
	p1.set_name(name);

	cout << "How much does it cost for a small pizza? ";
	getline(cin,s);
	s1 = check_int(s);
	p1.set_small(s1);

	cout << "How much does it cost for a medium pizza? ";
	getline(cin,s);
	m2 = check_int(m);
	p1.set_medium(m2);

	cout << "How much does it cost for a large pizza? ";
	getline(cin,l);
	l3 = check_int(l);
	p1.set_large(l3);

	cout << "How many ingredients going to be on the pizza? ";
	getline(cin,num_ingredients);
	num = check_int(num_ingredients);
	p1.set_num_ingredients(num);
	
	string *kind_p = new string[num];
	p1.set_ingredients_array(num);

	for (int i = 0; i < num; i++) {
		cout << "Provide the ingredients name: ";
		getline(cin,ingredients);
		kind_p[i] = ingredients;
	}

	p1.fill_ingredients_array(kind_p, num);
	num_pizza++;

	Pizza *tmp = new Pizza[num_pizza+1];
	for (int i = 0; i < num_pizza; i++) {
		tmp[i] = pizzas[i];
	}

	tmp[num_pizza] = p1;
	delete[] pizzas;
	pizzas = tmp;

	delete [] kind_p;
	delete [] tmp;
	cout << "Add-to-Menu was complete" << endl;
}

/*************************************
 * Function: void Menu::set_num_pizza()
 * Input: None
 * Output: None
 *************************************/
void Menu::set_num_pizza(int pizza) {
	
	this->num_pizza = pizza;
}

/*************************************
 * Function: int Menu::get_num_pizza()
 * Input: None
 * Output: None
 *************************************/
int Menu::get_num_pizza() {

return num_pizza;
}

/***************************************
 * Function: void Menu::search_by_cost()
 * Input: None
 * Output: None
 **************************************/
void Menu::search_by_cost(int upper_bound, string size) {

	load_data();
	
	if (size == "S") {
		for (int i = 0; i < num_pizza-1; i++) {
			if (pizzas[i].get_small() <= upper_bound) {
				cout << i+1 << ".  small " << pizzas[i].get_name() << "  $" << pizzas[i].get_small() << endl;
			}
			
			else if (pizzas[i].get_small() > upper_bound) {
				cout << i+1 << ".  N/A" << endl;
			}
		}
	}

	if (size == "M") {
		for (int i = 0; i < num_pizza-1; i++) {
			if (pizzas[i].get_medium() <= upper_bound) {
				cout << i+1 << ".  medium " << pizzas[i].get_name() << "  $" << pizzas[i].get_medium() << endl;
			}

			else if (pizzas[i].get_medium() > upper_bound) {
				cout << i+1 << ".  N/A" << endl;
			}
		}
	}

	if (size == "L") {
		for (int i = 0; i < num_pizza-1; i++) {
			if (pizzas[i].get_large() <= upper_bound) {
				cout << i+1 << ".  large " << pizzas[i].get_name() << "  $" << pizzas[i].get_large() << endl;
			}

			else if (pizzas[i].get_large() > upper_bound) {
				cout << i+1 << ".  N/A" << endl;
			}
		}
	}

	pizza_order(size);
}

void Menu::pizza_order(string size) {

	string input, input2, input3;
	bool yes_no;
	int selection_num = 0, item = 0, num_i = 0;
	cout << "\nDo you want to place an order off of this search? (Yes/No) ";
	getline(cin,input);

	if (input == "Yes" || input == "yes") {
		do {
			cout << "Please select the option from the list above, press (0) to cancel press any pizza display above to continue: ";
			getline(cin,input2);
			selection_num = check_int(input2);
			if (size == "S") {
				if (selection_num == 0) {
					break;
					yes_no = true;
				}
				cout << "How many small " << pizzas[selection_num-1].get_name() << " do you want? ";
				getline(cin,input3);
				item = check_int(input3);
				num_i++;
			}

			if (size == "L") {
				if (selection_num == 0) {
					break;
					yes_no = true;
				}
				cout << "How many large " << pizzas[selection_num-1].get_name() << " do you want? ";
				getline(cin,input3);
				item = check_int(input3);
				num_i++;
			}
		} while (yes_no == false);

	ask_order(size, selection_num, num_i);
	}

	else if (input == "No" || input == "no") {
		cout << "Thanks for using the search function!" << endl;
	}
}

void Menu::ask_order(string size, int selection_num, int num_i) {

	string name, cc, phone;
	int order = 1, quantity = 0;

	++order;
	cout << "\nPlease provide the information as the following: " << endl;
	cout << "What is your name? ";
	getline(cin,name);
	cout << "What is your Credit Card Number? ";
	getline(cin,cc);
	cout << "What is your phone number? ";
	getline(cin,phone);
	cout << "Thanks your order number is " << order << "! " << endl; 
}
