/********************************************************************************************
 * Program: sorting.cpp
 * Author: Tu Lam
 * Date: 05/28/2019
 * Description: The program create a sorting algorithm to sort numbers based on user input.
 * Input: User input a number in to be sorted by the computer.
 * Output: Display the user's number they enter from the ascending or descending order.
 *******************************************************************************************/

#include <iostream>
#include <string>
#include "header.h" //The library that include the .h file 'Header'
#include "link_list.h" //The library that include the class 'Link_List'
#include "link_list_node.h" //The library that include the class 'Link_List_Node'

using namespace std;

int main() {

	Link_List l;
	string enter;
	string go_again = "y";

	while (go_again == "Y" || go_again == "y") {
		cout << endl;
		main_title();
		l.program();
		cout << "\nWould you like to run the program again?" << endl;
		cout << "Press [Y] or [y] - Yes" << endl;
		cout << "Press [N] or [n] - No" << endl;
		cout << "Your Selection: ";
		cin >> go_again;

		while (!(go_again == "y" || go_again == "Y" || go_again == "N" || go_again == "n")) {
			cout << "\nSorry! Wrong input. Please enter again: ";
			cin >> go_again;
		}
	}

	cout << "\nThank You for using the Program." << endl;

return 0;
}
