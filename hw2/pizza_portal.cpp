/************************************************************************************************
 * Program: pizza_portal.cpp
 * Author: Tu Lam
 * Date: 04/28/2019
 * Description: A pizza portal where customer can order and employee can modify the restaurant
 * Input: The users which option to choose
 * Output: Print out the desire option as the users choose
 ***********************************************************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "./restaurant.h"

using namespace std;

int main() {

	Restaurant r1;

	title_page();
	r1.load_data();
	main_menu(r1);

return 0;
} 

