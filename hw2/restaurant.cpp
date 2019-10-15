/*************************************************************************************************
 * Program: restaurant.cpp
 * Author: Tu Lam
 * Date: 04/28/2019
 * Description: A pizza portal where customer can order and employee can modify the restaurant
 * Input: None
 * Output: None
 ************************************************************************************************/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include "./restaurant.h"

using namespace std;

/****************************************
 * Function: Restaurant::Restaurant()
 * Input: None
 * Output: None
 ***************************************/
Restaurant::Restaurant() {

   employees = NULL;
   week = NULL;
   name = " ";
   phone = " ";
   address = " ";
   employee_size = 0;	
   order_size = 0;
}

/****************************************
 * Function: Restaurant::~Restaurant()
 * Input: None
 * Output: None
 ***************************************/
/*Restaurant::~Restaurant() {

   if (employees != NULL) {
      delete [] this->employees;
   }

   if (week != NULL) {
      delete [] this->week;
   }

   if (orders != NULL) {
      delete [] this->orders;
   }

   employees = NULL;
   week = NULL;
   orders = NULL;
}*/

/****************************************
 * Function: Restaurant::Restaurant(const)
 * Input: None
 * Output: None
 ***************************************/
/*Restaurant::Restaurant(const Restaurant &old_rest){

   this->menu = old_rest.menu;
   this->week = new hours[7];
   this->name = old_rest.name;
   this->phone = old_rest.phone;
   this->address = old_rest.address;
   
	// employee_size was not initialized... This caused bugs
   //this->employee_size = old_rest.employee_size;
   if (employee_size == 0) {
      employees = NULL;
   }

   else {
      //this->employees = new employee[this->employee_size]; 
      for(int i = 0; i < this->employee_size; i++) {
	 this->employees[i] = old_rest.employees[i];
      }
   }

   // order_size was not initialized... This also caused bugs
   //this->order_size = old_rest.order_size;
   if (order_size == 0) {
      orders = NULL;
   }

   else {
      this->orders = new order[this->order_size];
      for(int i = 0; i < this->order_size; i++) {
	 this->orders[i] = old_rest.orders[i];
      }
   }
}*/

/*****************************************************
 * Function: Restaurant& Restaurant::operator=(const)
 * Input: None
 * Output: None
 ****************************************************/
/*Restaurant& Restaurant::operator=(const Restaurant &old_rest){

   delete[] this->employees;
   delete[] this->week;
   delete[] this->orders;

   this->menu = old_rest.menu;
   this->week = new hours[7];
   this->name = old_rest.name;
   this->phone = old_rest.phone;
   this->address = old_rest.address;

   if (employee_size == 0) {
      employees = NULL;
   }

   else {
      //this->employees = new employee[this->employee_size]; 
      for(int i = 0; i < this->employee_size; i++){
	 this->employees[i] = old_rest.employees[i];
      }
   }

   if (order_size == 0) {
      orders = NULL;
   }

   else {
      //this->orders = new order[this->order_size];
      for(int i = 0; i < this->order_size; i++){
	 this->orders[i] = old_rest.orders[i];
      }
   }

   return *this;
}*/

/****************************************
 * Function: void Restaurant::load_data()
 * Input: None
 * Output: None
 ***************************************/
void Restaurant::load_data() {

   string read1;

   fstream employee_db;
   employee_db.open("employee.txt");
   while (!employee_db.is_open()) {
      cout << "No file was detected for the employee! Program will exit.. ." << endl;
      exit(1);
   }
   num_line(employee_size, read1, employee_db);
   employee_db.close();
   this->employees = new employee[employee_size];
   get_employee_data(employees, employee_size, employee_db);
   employee_db.close();

   load_restaurant_info();
   menu.get_info();
   load_orders();
}

/************************************************
 * Function: bool Restaurant::login() 
 * Input: Enter in ID and Password
 * Output: Return true/false
 ***********************************************/
bool Restaurant::login(string id, string password) {

   int enter_id = 0;
   bool try_login;	

   do {
      cout << "\nWelcome Employee!" << endl;
      cout << "-----------------" << endl;
      cout << "Please enter in your ID: ";
      getline(cin,id);
      enter_id = check_int(id);

      cout << "Please enter in your Password: ";
      getline(cin,password);	

      for (int i = 0; i < employee_size; i++) {
	 if (enter_id == employees[i].id && password == employees[i].password) {
	    cout << "\nLogin Successful!" << endl;
	    employee_login_info(enter_id, password, employee_size, employees);
	    employee_directory();
	    try_login = true;
	 }
      }

      if (try_login != true) {
	 employee_login_fail(try_login);	
      }
   } while (try_login == false);

   return true;
}

/**************************************************
 * Function: void Restaurant::employee_login_info() 
 * Input: None
 * Output: None
 *************************************************/
void Restaurant::employee_login_info(int enter_id, string password, int employee_size, employee *employees) {

   for (int i = 0; i < employee_size; i++) {
      if (enter_id == employees[i].id && password == employees[i].password) {
	 cout << "\nWelcome " << employees[i].first_name << " " << employees[i].last_name << endl;
      }
   }
}

/***************************************************
 * Function: void Restaurant::load_restaurant_info() 
 * Input: None
 * Output: None
 **************************************************/
void Restaurant::load_restaurant_info() {

   fstream restaurant_db;
   restaurant_db.open("restaurant_info.txt");
   while (!restaurant_db.is_open()) {
      cout << "No file was detected for the restaurant info! Program will exit.. ." << endl;
      exit(1);
   }
   getline(restaurant_db,this->name);
   getline(restaurant_db,this->phone);
   getline(restaurant_db,this->address);
   this->week = new hours[7];

   for (int i = 0; i < 7; i++) {
      restaurant_db >> week[i].day;
      restaurant_db >> week[i].open_hour;
      restaurant_db >> week[i].close_hour;
   }
   restaurant_db.close();
}

/***************************************************
 * Function: void Restaurant::load_orders() 
 * Input: None
 * Output: None
 **************************************************/
void Restaurant::load_orders() {

   string read3;
   fstream order_db;
   order_db.open("orders.txt");
   while (!order_db.is_open()) {
      cout << "No file was dectected for the order! Program will exit.. ." << endl;
      exit(1);
   }
   num_line(order_size, read3, order_db);
   order_db.close();	
   this->orders = new order[order_size];
   get_order_data(orders, order_size, order_db);
   order_db.close();

}

void Restaurant::view_orders() {

   cout << "\nView Order" << endl;
   cout << "----------" << endl;

   for (int i = 0; i < order_size-1; i++) {
      cout << orders[i].order_num << " " << orders[i].customer << " " << orders[i].credit_card << " " << orders[i].phone;
      cout << " " << orders[i].pizza_name << " " << orders[i].size << " " << orders[i].quantity << endl;
   }
}

/***************************************************
 * Function: void Restaurant::view_menu() 
 * Input: None
 * Output: None
 **************************************************/
void Restaurant::view_menu() {

   menu.display_menu();
}

/***************************************************
 * Function: void Restaurant::view_hours() 
 * Input: None
 * Output: None
 **************************************************/
void Restaurant::view_hours() {

   cout << "\nRestaurant Hours" << endl;
   cout << "----------------" << endl;

   for (int i = 0; i < 7; i++) {
      cout << week[i].day << " " << week[i].open_hour << " " << week[i].close_hour << endl;
   }
}

/***************************************************
 * Function: void Restaurant::view_phone() 
 * Input: None
 * Output: None
 **************************************************/
void Restaurant::view_phone() {

   cout << "\nRestaurant Phone Number" << endl;
   cout << "-----------------------" << endl;

   cout << "Phone: " << phone << endl;
}

/***************************************************
 * Function: void Restaurant::view_address() 
 * Input: None
 * Output: None
 **************************************************/
void Restaurant::view_address() {

   cout << "\nRestaurant Address" << endl;
   cout << "------------------" << endl;

   cout << "Name: " << name << endl;
   cout << "Address: " << address << endl;
}

/***************************************************
 * Function: void Restaurant::employee_directory() 
 * Input: None
 * Output: None
 **************************************************/
void Restaurant::employee_directory() {

   string e_input;
   int e_choice = 0;
   bool retry_chance;

   do {
      cout << "\nWhat would you like to do?" << endl;
      cout << "1. Change Hours" << endl;
      cout << "2. View Orders" << endl;
      cout << "3. Remove Order" << endl;
      cout << "4. Add Item To Menu" << endl;
      cout << "5. Remove Item From Menu" << endl;
      cout << "6. View Menu" << endl;
      cout << "7. View Hours" << endl;
      cout << "8. View Address" << endl;
      cout << "9. View Phone" << endl;
      cout << "10. Log Out" << endl;
      cout << "Selection: ";
      getline(cin,e_input);
      e_choice = check_int(e_input);

      employee_option(e_choice, retry_chance);	
   } while (retry_chance == false);
}

/***************************************************
 * Function: void Restaurant::employee_option() 
 * Input: None
 * Output: None
 **************************************************/
void Restaurant::employee_option(int e_choice, bool &retry_chance) {

   if (e_choice == 1) {
      change_hours();
   }

   else if (e_choice == 2) {
      view_orders();
   }

   else if (e_choice == 3) {

   }

   else if (e_choice == 4) {
      add_to_menu();
   }

   else if (e_choice == 5) {

   }

   else if (e_choice == 6) {
      view_menu();
   }

   else if (e_choice == 7) {
      view_hours();
   }

   else if (e_choice == 8) {
      view_address();
   }

   else if (e_choice == 9) {
      view_phone();
   }

   else if (e_choice == 10) {
      cout << "Thank you for using the employee directory, the program will go to the main menu now... .. .\n" << endl;
      retry_chance = true;
   }

   else {
      cout << "Your input was invalid, please try again." << endl;
      retry_chance = false;
   }
}

/*******************************************
 * Function: void Restaurant::change_hours() 
 * Input: None
 * Output: None
 ******************************************/
void Restaurant::change_hours() {

   string change_day, change_open, change_close;
   bool enter_day;

   do {
      cout << "\nWhat day would you like you change the hours for? ";
      getline(cin,change_day);

      for (int i = 0; i < 7; i++) {
	 if (change_day == week[i].day) {
	    cout << "What should be the opening time be: ";
	    getline(cin,change_open);
	    week[i].open_hour = change_open;
	    cout << "What should be the closing time be: ";
	    getline(cin,change_close);
	    week[i].close_hour = change_close;
	    update_hours();
	    write_hours();
	    enter_day = true;
	 }
      }

      if (enter_day != true) {
	 cout << "Your input was invalid, please try again!" << endl;
      }	
   } while (enter_day == false);
}

/*******************************************
 * Function: void Restaurant::update_hours() 
 * Input: None
 * Output: None
 ******************************************/
void Restaurant::update_hours() {

   cout << "\nUpdate Hours" << endl;
   cout << "------------" << endl;

   for (int i = 0; i < 7; i++) {
      cout << week[i].day << " " << week[i].open_hour << " " << week[i].close_hour << endl;
   }
}

/*******************************************
 * Function: void Restaurant::write_hours() 
 * Input: None
 * Output: None
 ******************************************/
void Restaurant::write_hours() {

   ofstream hour;
   hour.open("restaurant_info.txt"); 

   hour << get_name() << endl;
   hour << get_phone() << endl;	
   hour << get_address() << endl;

   for (int i = 0; i < 7; i++) {
      hour << week[i].day << " " << week[i].open_hour << " " << week[i].close_hour << endl;
   }
   hour.close();
}

/*******************************************
 * Function: void Restaurant::set_name() 
 * Input: None
 * Output: None
 ******************************************/
void Restaurant::set_name(string name) {

   this->name = name;
}

/*******************************************
 * Function: string Restaurant::get_name() 
 * Input: None
 * Output: None
 ******************************************/
string Restaurant::get_name() {

   return name;
}

/*******************************************
 * Function: void Restaurant::set_phone() 
 * Input: None
 * Output: None
 ******************************************/
void Restaurant::set_phone(string phone) {

   this->phone = phone;
}

/*******************************************
 * Function: string Restaurant::get_phone() 
 * Input: None
 * Output: None
 ******************************************/
string Restaurant::get_phone() {

   return phone;
}

/*******************************************
 * Function: void Restaurant::set_address() 
 * Input: None
 * Output: None
 ******************************************/
void Restaurant::set_address(string address) {

   this->address = address;
}

/*******************************************
 * Function: string Restaurant::get_address() 
 * Input: None
 * Output: None
 ******************************************/
string Restaurant::get_address() {

   return address;
}

/*******************************************
 * Function: int Restaurant::get_employee_size() 
 * Input: None
 * Output: None
 ******************************************/
int Restaurant::get_employee_size() {

   return employee_size;
}

/*******************************************
 * Function: int Restaurant::get_order_size() 
 * Input: None
 * Output: None
 ******************************************/
int Restaurant::get_order_size() {

   return order_size;
}

/*******************************************
 * Function: void Restaurant::add_to_menu() 
 * Input: None
 * Output: None
 ******************************************/
void Restaurant::add_to_menu() {
	
	menu.add_to_menu();
}

/******************************************************
 * Function: void Restaurant::search_by_cost();
 * Input: None
 * Output: None
 *****************************************************/
void Restaurant::search_cost() {

	string input, size;
	int num_p = 0;

	cout << "\nSearch by Cost" << endl;
	cout << "--------------" << endl;
	cout << "What is your budget on the pizza? ";
	getline(cin,input);
	num_p = check_int(input);
	
	cout << "Enter the size you want to search: small [S], medium [M], large [L]: ";
	getline(cin,size);

	menu.search_by_cost(num_p, size);

}
