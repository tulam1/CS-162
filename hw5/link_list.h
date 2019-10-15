/****************************************************************************
 * Program: link_list.h
 * Author: Tu Lam
 * Date: 05/28/2019
 * Description: The header file containing the class to use for the program.
 * Input: None.
 * Output: None.
 ***************************************************************************/

#ifndef LINK_LIST_H
#define LINK_LIST_H

#include <iostream>
#include <string>
#include "link_list_node.h"

using namespace std;

class Link_List {

	private:
		unsigned int length;
		Link_List_Node *first;
		string choice;


	public:
		//The Big 3 & Other Constructors
		Link_List(); //Default Constructor
	
		//Mutator
		void set_choice(string);
		//Accessor
		int get_length();
		string get_choice();

		//Other Functions
		void print();
		void clear();
		void program();
		void enter_again(bool &);
		unsigned int push_front(int);
		unsigned int push_back(int);
		unsigned int insert(int, unsigned int);
		void sort_ascending();
		void sort_descending();
		void front_back(int);
		void ascend_descend_option();
		void insert_option();
		void prime_number(int &);
		void split(Link_List_Node *, Link_List_Node **, Link_List_Node **);
		void merge_sort(Link_List_Node **);
		Link_List_Node *merge_back_ascend(Link_List_Node *, Link_List_Node *);
		Link_List_Node *merge_back_descend(Link_List_Node *, Link_List_Node *);
		void original_list();
		void modify_list();
		void prime_display(int);
};

#endif
