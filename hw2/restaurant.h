/*************************************************************************************************
 * Program: restaurant.h
 * Author: Tu Lam
 * Date: 04/28/2019
 * Description: A pizza portal where customer can order and employee can modify the restaurant
 * Input: None
 * Output: None
 ************************************************************************************************/
 
#ifndef RESTAURANT_H
#define RESTAURANT_H

#include <iostream>
#include <string>
#include "./pizza.h"
#include "./menu.h"
#include "./struct.h"

using namespace std;

class Restaurant {

	private:
		Menu menu;
    	employee* employees;
    	hours* week;
		order* orders;
    	string name;
    	string phone;
    	string address;
		int employee_size;
		int order_size;

	public:
	Restaurant(); //Default constructor
  	//~Restaurant(); //Destructor
 	//Restaurant(const Restaurant &); //Copy constructor
	//Restaurant& operator=(const Restaurant &); //Assignment overload

	void load_data();
	bool login(string, string);
	void employee_login_info(int, string, int, employee *);
	void load_restaurant_info();
	void load_orders();
	void view_orders();
	void view_menu();
	void view_hours();
	void view_phone();
	void view_address();
	void employee_directory();
	void employee_option(int, bool &);
	void change_hours();
	void update_hours();
	void write_hours();
	void add_to_menu();
	void set_name(string);
	void set_address(string);
	void set_phone(string);
	string get_name();
	string get_phone();
	string get_address();
	int get_employee_size();
	int get_order_size();
	void search_cost();
};
#endif
