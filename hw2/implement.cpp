/*************************************************************************************************
 * Program: implement.cpp
 * Author: Tu Lam
 * Date: 04/28/2019
 * Description: A pizza portal where customer can order and employee can modify the restaurant
 * Input: None
 * Output: None
 ************************************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "./restaurant.h"

using namespace std;

/********************************************
 * Function: void num_line()
 * Input: None
 * Output: Return the num of line
 *******************************************/
void num_line(int &num_line, string read_file, fstream &read_if) {
	
	int line = 0;

	while (!read_if.eof()) {
		getline(read_if,read_file);
		line++;
	}
	
	num_line = line;
}

/********************************************
 * Function: void get_employee_data()
 * Input: None
 * Output: None
 *******************************************/
void get_employee_data(employee *e_data, int employee_size, fstream &employee_db) {

	employee_db.open("employee.txt");

	for (int i = 0; i < employee_size; i++) {
		employee_db >> e_data[i].id;
		employee_db >> e_data[i].password;
		employee_db >> e_data[i].first_name;
		employee_db >> e_data[i].last_name;		
	}
}

void get_order_data(order *o_data, int order_size, fstream &order_db) {

	order_db.open("orders.txt");

	for (int i = 0; i < order_size; i++) {
		order_db >> o_data[i].order_num;
		order_db >> o_data[i].customer;
		order_db >> o_data[i].credit_card;
		order_db >> o_data[i].phone;
		order_db >> o_data[i].pizza_name;
		order_db >> o_data[i].size;
		order_db >> o_data[i].quantity;
	}
}

/*********************************
 * Function: void title_page()
 * Input: None
 * Output: None
 ********************************/
void title_page() {

	cout << "________________" << endl;
	cout << "The Pizza Portal" << endl;
	cout << "----------------" << endl;
	cout << endl;
}

/***************************************
 * Function: void main_menu()
 * Input: Letter to enter different mode
 * Output: None
 **************************************/
void main_menu(Restaurant r1) {

	string main_option, id, password;
	bool retry_option;

	do {
		cout << "Welcome to the Pizza Portal!" << endl;
		cout << "Are you: An Employee [E], A Customer [C], or Do You Want to Quit [Q]? ";
		getline(cin,main_option);

		if (main_option == "E" || main_option == "e") {
			r1.login(id, password);
		}

		else if (main_option == "C" || main_option == "c") {
			customer_directory(r1);
		}	

		else if (main_option == "Q" || main_option == "q") {
			cout << "\nThank you for using the Pizza Portal, the portal will log out now... .. ." << endl;
			exit(1);
		}

		else {
			cout << "Invalid option, please try again.\n" << endl;
		}
	} while (retry_option == false);
}

/**************************************
 * Function: void employee_login_fail()
 * Input: Enter y/n to try again
 * Output: None
 *************************************/
void employee_login_fail(bool &try_login) {

	bool try_option;
	string e_try;

	do {
		cout << "\nEither your ID or Password input didn't match, would like to try again [Y] or quit [Q]? ";
		getline(cin,e_try);

		if (e_try == "Y" || e_try == "y") {
			try_option = true;	
			try_login = false;
		} 

		else if (e_try == "Q" || e_try == "q") {
			try_option = true;
			cout << endl;
			try_login = true;
		}

		else {
			cout << "Your input was invalid, please try again." << endl;
		}
	} while (try_option == false);
}

/**************************************
 * Function: void customer_directory()
 * Input: Enter a number to choices
 * Output: None
 *************************************/
void customer_directory(Restaurant r1) {

	string c_input;
	int c_choice = 0;
	bool retry_choice;

	do {
		cout << "\nWelcome Customer!" << endl;
		cout << "------------------" << endl;
		cout << "What would you like to do?" << endl;
		cout << "1. View Menu" << endl;
		cout << "2. Search by Cost" << endl;
		cout << "3. Search by Ingredients" << endl;
		cout << "4. Place Order" << endl;
		cout << "5. View Hours" << endl;
		cout << "6. View Address" << endl;
		cout << "7. View Phone" << endl;
		cout << "8. Log Out" << endl;
		cout << "Selection: ";
		getline(cin,c_input);
		c_choice = check_int(c_input);
		
		customer_option(c_choice, retry_choice, r1);
	} while (retry_choice == false);
}

/**************************************
 * Function: void customer_option()
 * Input: None
 * Output: None
 *************************************/
void customer_option(int c_choice, bool &retry_choice, Restaurant r1) {

	if (c_choice == 1) {
		r1.view_menu();
	}

	else if (c_choice == 2) {
		r1.search_cost();
	}

	else if (c_choice == 3) {
		//r1.search_by_ingredients(r1);
	}

	else if (c_choice == 4) {

	}

	else if (c_choice == 5) {
		r1.view_hours();
	}

	else if (c_choice == 6) {
		r1.view_address();
	}

	else if (c_choice == 7) {
		r1.view_phone();
	}

	else if (c_choice == 8) {
		cout << "Thank you for using the customer directory, the program will go to the main menu now... .. .\n" << endl;
		retry_choice = true;
	}
		
	else {
	cout << "Your input was invalid, please try again." << endl;
	retry_choice = false;
	}
}

/***************************************
 * Function: void search_ingredients()
 * Input: None
 * Output: None
 **************************************/
void search_ingredients(Restaurant r1) {

	string search_input;
	bool search;

	do {
		cout << "\nSearch by Ingredients" << endl;
		cout << "---------------------" << endl;
		cout << "Would you like to search for ingredients you want to Include [I] or Exclude [E]? ";
		getline(cin,search_input);

		if (search_input == "I" || search_input == "i") {
			search_include(r1);
		}

		else if (search_input == "E" || search_input == "e") {

		}

		else {
			cout << "Invalid input, please try again!" << endl;
		}
	} while (search == false);

}

void search_include(Restaurant r1) {

	string include, choice;
	string *ingredients = new string[30];
	bool yes_loop;
	int include_food = 0;
	Menu m1, tmp;
	//tmp = r1.get_menu();

	do {
		cout << "What item would you like to include? ";
		getline(cin,include);
		ingredients[include_food] = include;
		cout << "Do you want to include another item? (Yes[Y] / No[N]): ";
		getline(cin,choice); 

		if (choice == "Y" || choice == "y") {
			include_food++;
			yes_loop = false;
		}

		else if (choice == "N" || choice == "n") {
			yes_loop = true;
		}

		else {
			cout << "Invalid input, please try again!" << endl;
		}
	} while (yes_loop == false);

	//m1 = tmp.search_by_pizza_include(ingredients,include_food);

	
}

/***************************************
 * Function: int check_int()
 * Input: Input a string to check number
 * Output: Return a whole integer
 **************************************/
int check_int(string input) {

	int check_i = 0;
	bool re_check;

	do {
		re_check = false;

		for (int i = 0; i < input.size(); i++) {
			if (!(input.at(i) >= '0' && input.at(i) <= '9')) {
				cout << "Your input was not an integer, please try again: ";
				getline(cin,input);
				re_check = true;
				break;
			}
		}
	} while (re_check);

	check_i = atoi(input.c_str());

return check_i;
}

