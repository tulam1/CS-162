#ifndef STRUCT_H
#define STRUCT_H

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "./restaurant.h"

using namespace std;

class Restaurant;

struct employee {

	int id;
	string password;
	string first_name;
	string last_name;
};

struct hours {

	string day;
	string open_hour;
	string close_hour;
};

struct order {

	int order_num;
	string customer;
	string credit_card;
	string phone;
	string pizza_name;
	string size;
	int quantity;
};

void num_line(int &, string, fstream &);
void get_employee_data(employee *, int, fstream &);
void get_order_data(order *, int, fstream &);

void title_page();
void main_menu(Restaurant);
void employee_login_fail(bool &);
void employee_directory();
void employee_option(int, bool &);
void customer_directory(Restaurant);
void customer_option(int, bool &, Restaurant);
void search_ingredients(Restaurant);
void search_include(Restaurant);
int check_int(string);
#endif
