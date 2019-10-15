/****************************************************************************************
 * Program: link_list.cpp
 * Author: Tu Lam
 * Date: 05/28/2019
 * Description: The implementation file that contain the function to use for the program.
 * Input: None.
 * Output: None.
 ***************************************************************************************/
 
#include <iostream>
#include <string>
#include <cstdlib>
#include "link_list.h"
#include "link_list_node.h"
#include "header.h"

using namespace std;

/***************************************************
 * Function: Link_List::Link_List();
 * Input: None.
 * Output: Assigning value to the member variables.
 **************************************************/
Link_List::Link_List() {

	length = 0;
	first = NULL;
	choice = " ";
}

/***************************************************
 * Function: void Link_List::set_choice(string);
 * Input: None.
 * Output: Set the private member variable.
 **************************************************/
void Link_List::set_choice(string choice) {

	this->choice = choice;
}

/***************************************************
 * Function: int Link_List::get_length();
 * Input: None.
 * Output: Return the private member variable.
 **************************************************/
int Link_List::get_length() {

return this->length;
}

/***************************************************
 * Function: string Link_List::get_choice();
 * Input: None.
 * Output: Return the private member variable.
 **************************************************/
string Link_List::get_choice() {

return this->choice;
}

/**********************************************************
 * Function: void Link_List::print();
 * Input: None.
 * Output: Print out the list of integer store in the list.
 *********************************************************/
void Link_List::print() {

	for (Link_List_Node *n = first; n != NULL; n = n->next) {		
		cout << n->val << " ";
	}
	cout << endl;
}

/**********************************************************
 * Function: void Link_List::clear();
 * Input: None.
 * Output: Act like a Destructor and delete all the nodes.
 *********************************************************/
void Link_List::clear() {

	Link_List_Node *origin1 = first;
	Link_List_Node *origin2 = first->next;

	for (unsigned int i = 0; i < length; i++) {
		if (origin1 != NULL) {
			delete origin1;
			origin1 = origin2;

			if (origin2 != NULL) {
				origin2 = origin2->next;
			}
		}
	}

	first = NULL;
	length = 0;
}

/*******************************************************************
 * Function: unsigned int Link_List::push_front(int);
 * Input: None.
 * Output: Increment/return the length and push the number in front.
 ******************************************************************/
unsigned int Link_List::push_front(int num) {

	if (first == NULL) {
		first = new Link_List_Node;
		first->val = num;
		first->next = NULL;
	}

	else if (first != NULL) {
		Link_List_Node *tmp = new Link_List_Node;
		tmp->val = num;
		tmp->next = first;
		first = tmp;
	}

	length++;

return length;
}

/*******************************************************************
 * Function: unsigned int Link_List::push_back(int);
 * Input: None.
 * Output: Increment/return the length and push the number in back.
 ******************************************************************/
unsigned int Link_List::push_back(int num) {

	if (first == NULL) {
		first = new Link_List_Node;
		first->val = num;
		first->next = NULL;
	}

	else if (first != NULL) {
		Link_List_Node *tmp = new Link_List_Node;
		tmp->val = num;
		for (Link_List_Node *n = first; n != NULL; n = n->next) {
			if (n->next == NULL) {
				n->next = tmp;
				break;
			}
		}
		tmp->next = NULL;
	}

	length++;	

return length;
}

/*******************************************************************
 * Function: unsigned int Link_List::insert(int, unsigned int);
 * Input: None.
 * Output: Inserting a node to a specific location in the Link List.
 ******************************************************************/
unsigned int Link_List::insert(int val, unsigned int index) {

	Link_List_Node *tmp = new Link_List_Node;
	tmp->val = val;

	Link_List_Node *origin = first;
	Link_List_Node *tmp2 = first;

	if (index > 1) {
		for (unsigned int i = 1; i < index; i++) {
			origin = origin->next;
		}

		for (unsigned int j = 1; j < index - 1; j++) {
			tmp2 = tmp2->next;
		}

		tmp2->next = tmp;
		tmp->next = origin;
	}

	else if (index == 1) {
		first = tmp;
		tmp->next = origin;
	}

	length++;

return length;
}

/****************************************************
 * Function: void Link_List::sort_ascending();
 * Input: None.
 * Output: Sort the Link List in the ascending order.
 ***************************************************/
void Link_List::sort_ascending() {

	merge_sort(&first);
}

/*****************************************************
 * Function: void Link_List::sort_descending();
 * Input: None.
 * Output: Sort the Link List in the descending order.
 ****************************************************/
void Link_List::sort_descending() {

	merge_sort(&first);
}

/***********************************************
 * Function: void Link_List::program();
 * Input: Input in the number for the link list.
 * Output: Print out the main program.
 **********************************************/
void Link_List::program() {

	string input;
	int num = 0, count = 0;
	bool try_number = false;

	cout << "\nWelcome to the sorting program!" << endl;

	do {
		cout << "\nPlease enter a number into the Link List." << endl;
		cout << "Your Entry: ";
		cin >> input;
		num = check_i(input);
		push_front(num);
		enter_again(try_number);	
	} while (try_number == false);

	original_list();
	ascend_descend_option();
	prime_number(count);
	modify_list();
	prime_display(count);
	clear();
}

/**********************************************************
 * Function: void Link_List::enter_again(bool &);
 * Input: Input in the number for entering a number again.
 * Output: Go to one of the option that the user enter.
 *********************************************************/
void Link_List::enter_again(bool &try_number) {

	string input2;
	int go = 0;
	bool try_again = false;

	do {
		cout << "\nWould you like to enter another number?" << endl;
		cout << "Press [1] - Yes" << endl;
		cout << "Press [0] - No" << endl;
		cout << "Your Selection: ";
		cin >> input2;
		go = check_i(input2);

		if (go == 1) {
			try_again = true;
			try_number = false;
		}

		else if (go == 0) {
			try_again = true;
			try_number = true;
		}

		else {
			cout << "Sorry! The number you enter was not in the range. Please try again." << endl;
		}
	} while (try_again == false);
}

/**********************************************************
 * Function: void Link_List::ascend_descend_option();
 * Input: Input in the option to pick ascend or descend.
 * Output: Go to one of the option that the user pick.
 *********************************************************/
void Link_List::ascend_descend_option() {

	string input3;
	bool try_word = false;

	do {
		cout << "\nHow would you like to sort your Linked List?" << endl;
		cout << "Press [A] or [a] - Ascend" << endl;
		cout << "Press [D] or [d] - Descend" << endl;
		cout << "Your Selection: ";
		cin >> input3;
		set_choice(input3);

		if (input3 == "A" || input3 == "a") {
			sort_ascending();
			try_word = true;
		}

		else if (input3 == "D" || input3 == "d") {
			sort_descending();
			try_word = true;
		}

		else {
			cout << "Sorry! The selection you enter didn't match with one of our respond. Please try again." << endl;
		}
	} while (try_word == false);
}

/********************************************************************
 * Function: void Link_List::prime_number();
 * Input: None.
 * Output: Look at the Link List and see which one is a prime number.
 *******************************************************************/
void Link_List::prime_number(int &count) {

	int track = 0;
	bool is_prime;

	for (Link_List_Node *n = first; n != NULL; n = n->next) {
		is_prime = true;
		for (int i = 2; i <= (n->val / 2); i++) {
			if ((n->val % i) == 0) {
				is_prime = false;
				break;
			}
		}
	
		if (n->val <= 1) {
			is_prime = false;
		}

		if (is_prime == true) {
			track++;
		}
	}

	count = track;
}

/********************************************************************
 * Function: void Link_List::merge_sort();
 * Input: None.
 * Output: Merge sorting technique that helps sort the Linked List.
 *******************************************************************/
void Link_List::merge_sort(Link_List_Node **ori) {

	Link_List_Node *start = *ori;
	Link_List_Node *A, *B;

	if ((start == NULL) || (start->next == NULL)) {
		return;
	}

	split(start, &A, &B);
	merge_sort(&A);
	merge_sort(&B);

	if (choice == "A" || choice == "a") {
		*ori = merge_back_ascend(A, B);
	}

	else if (choice == "D" || choice == "d") {
		*ori = merge_back_descend(A, B);
	}
}

/******************************************************************************************
 * Function: void Link_List::split(Link_List_Node *, Link_List_Node **, Link_List_Node **);
 * Input: None.
 * Output: Splitting the array up and find the middle of the Linked List.
 *****************************************************************************************/
void Link_List::split(Link_List_Node *head, Link_List_Node **A, Link_List_Node **B) {

	Link_List_Node *skip, *forward;
	forward = head;
	skip = head->next;

	while (skip != NULL) {
		skip = skip->next;
		if (skip != NULL) {
			forward = forward->next;
			skip = skip->next;
		}
	}

	*A = head;
	*B = forward->next;
	forward->next = NULL;
}

/*********************************************************************************************
 * Function: Link_List_Node* Link_List::merge_back_ascend(Link_List_Node *, Link_List_Node *);
 * Input: None.
 * Output: Merge the two lists together into one Linked List in ascending order.
 ********************************************************************************************/
Link_List_Node* Link_List::merge_back_ascend(Link_List_Node *A, Link_List_Node *B) {

	Link_List_Node *finish = NULL;

	if (A == NULL) {
		return B;
	}

	else if (B == NULL) {
		return A;
	}

	if (A->val <= B->val) {
		finish = A;
		finish->next = merge_back_ascend(A->next, B);
	}

	else {
		finish = B;
		finish->next = merge_back_ascend(A, B->next);
	}

return finish;
}

/**********************************************************************************************
 * Function: Link_List_Node* Link_List::merge_back_descend(Link_List_Node *, Link_List_Node *);
 * Input: None.
 * Output: Merge the two lists together into one Linked List in descending order.
 *********************************************************************************************/
Link_List_Node* Link_List::merge_back_descend(Link_List_Node *A, Link_List_Node *B) {

	Link_List_Node *finish = NULL;

	if (A == NULL) {
		return B;
	}

	else if (B == NULL) {
		return A;
	}

	if (A->val >= B->val) {
		finish = A;
		finish->next = merge_back_descend(A->next, B);
	}

	else {
		finish = B;
		finish->next = merge_back_descend(A, B->next);
	}

return finish;
}

/*******************************************************
 * Function: void Link_List::original_list();
 * Input: None.
 * Output: Display the original Linked List before sort.
 ******************************************************/
void Link_List::original_list() {

	cout << "\n___________" << endl;
	cout << "Linked List" << endl;
	cout << "-----------" << endl;
	cout << "This is the Linked List: ";
	print();
}

/*******************************************************
 * Function: void Link_List::modify_list();
 * Input: None.
 * Output: Display the original Linked List before sort.
 ******************************************************/
void Link_List::modify_list() {

	cout << "\n__________________" << endl;
	cout << "Modify Linked List" << endl;
	cout << "------------------" << endl;
	cout << "This is your modify Linked List: ";
	print();
}

/*******************************************************
 * Function: void Link_List::prime_display();
 * Input: None.
 * Output: Display the original Linked List before sort.
 ******************************************************/
void Link_List::prime_display(int count) {

	cout << "\n____________" << endl;
	cout << "Prime Number" << endl;
	cout << "------------" << endl;
	cout << "In your Linked List, you have " << count << " prime number(s)!" << endl;
}
