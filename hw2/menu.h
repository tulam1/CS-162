/*************************************************************************************************
 * Program: menu.h
 * Author: Tu Lam
 * Date: 04/28/2019
 * Description: A pizza portal where customer can order and employee can modify the restaurant
 * Input: None
 * Output: None
 ************************************************************************************************/

#ifndef MENU_H
#define MENU_H

using namespace std;

class Menu {

	private:
	int num_pizza;
	Pizza* pizzas;

	public:
	Menu(); //Default constructor
	~Menu(); //Destructor
	Menu(const Menu &); //Copy constructor
	Menu &operator=(const Menu &); //Assignment Overload

	void get_info();
	void load_data();
	void display_menu();
	void add_to_menu();
	void set_num_pizza(int);
	int get_num_pizza();
	void search_by_cost(int, string);
	void pizza_order(string);
	void ask_order(string, int, int);
	
};

#endif
