/**************************************************************************************************************
 * Program: wizard_cat.cpp
 * Author: Tu Lam
 * Date: 04/14/2019
 * Description: The users are searching for the catalog of wizard's books and spells and sorted to users desire
 * Intput: Users type in the sorting option and how to print it out
 * Output: Going through the option of sorting and print out on screen depend on the sorting or print to file
 *************************************************************************************************************/
#include <iostream> //This library is for cout and cin function
#include <fstream> //This library help with opening textfile and help read and write file
#include <string> //This library let user access C++ string style
#include <cstdlib> //This library help to access atoi, and the exit() prototype
#include "./wizard_struct.h" //This library help to access all the structs

using namespace std;

/********************************************************
 * Function: wizard* create_wizard_db()
 * Input: None
 * Output None
 *******************************************************/
wizard* create_wizard_db(int wizard_size) {

	wizard *wizard_info = new wizard[wizard_size];

return wizard_info;
}

/********************************************************
 * Function: void get_wizard_db()
 * Input: None
 * Output None
 *******************************************************/
void get_wizard_db(wizard *wizard_data, int read_file1, fstream &wizard_db) {

	for (int i = 0; i < read_file1; i++) {
		wizard_db >> wizard_data[i].name;
		wizard_db >> wizard_data[i].id;
		wizard_db >> wizard_data[i].password;
		wizard_db >> wizard_data[i].position_title;
		wizard_db >> wizard_data[i].beard_length;
	}
}

/********************************************************
 * Function: spellbook* create_spellbook_db()
 * Input: None
 * Output None
 *******************************************************/
spellbook* create_spellbook_db(int spellbook_size) {

	spellbook *book_info = new spellbook[spellbook_size];

return book_info;	
}

/********************************************************
 * Function: void get_spellbook_db()
 * Input: None
 * Output None
 *******************************************************/
void get_spellbook_db(spellbook *book_data, int read_file2, fstream &spellbook_db) {

	for (int i = 0; i < read_file2; i++) {
		spellbook_db >> book_data[i].title;
		spellbook_db >> book_data[i].author;
		spellbook_db >> book_data[i].num_pages;
		spellbook_db >> book_data[i].edition;
		spellbook_db >> book_data[i].num_spells;
		book_data[i].s = create_spell_db(book_data[i].num_spells);
		get_spell_db(book_data[i].s, book_data[i].num_spells, spellbook_db);
		avg_calculation(book_data[i].s, book_data[i].num_spells, book_data[i]);
	}
}

/********************************************************
 * Function: spell*  create_spell_db()
 * Input: None
 * Output None
 *******************************************************/
spell* create_spell_db(int spell_size) {

	spell *spell_info = new spell[spell_size];

return spell_info;
}

/********************************************************
 * Function: void get_spell_db()
 * Input: None
 * Output None
 *******************************************************/
void get_spell_db(spell *spell_data, int spell_size, fstream &spellbook_db) {

	for (int i = 0; i < spell_size; i++) {
		spellbook_db >> spell_data[i].name;
		spellbook_db >> spell_data[i].success_rate;
		spellbook_db >> spell_data[i].effect;
	}
}

/********************************************************
 * Function: void avg_calculation()
 * Input: None
 * Output None
 *******************************************************/
void avg_calculation(spell *spell_data, int spell_size, spellbook &book_data) {

	float total_effect = 0;

	for (int i = 0; i < spell_size; i++) {
		total_effect += spell_data[i].success_rate;
	}

	book_data.avg_success_rate = (total_effect / spell_size);
}

/********************************************************
 * Function: void title()
 * Input: None
 * Output None
 *******************************************************/
void title() {

	cout << "_______________________" << endl;
	cout << "Wizard Catalog Database" << endl;
	cout << "-----------------------" << endl;
}

/********************************************************
 * Function: void wizard_login_info()
 * Input: Insert in the id and password information
 * Output None
 *******************************************************/
void wizard_login_info(wizard *wizard_data, int wizard_size, wizard *wiz_info) {

	string id_input, password_i;
	int enter_id = 0, attempt = 0;
	bool good_attempt;

	do {
		++attempt;
		cout << "\nWizard Login" << endl;
		cout << "------------" << endl;
		cout << "Please enter your ID Number: ";
		getline(cin,id_input);
		enter_id = check_int(id_input);
		
		cout << "Please enter your Password: ";
		getline(cin,password_i);

		for (int i = 0; i < wizard_size; i++) {
			if (enter_id == wizard_data[i].id && password_i == wizard_data[i].password) {
				cout << "\nLogin was Successful" << endl;
				good_attempt = true;
				wizard_login_print(wizard_data, enter_id, wizard_size, password_i);
				*wiz_info = wizard_data[i];
			}
		}

		if ((good_attempt != true) && (attempt < 3)) {
			cout << "Either the ID or Password didn't match, please try again\n" << endl;
		}

		else if ((good_attempt != true) && (attempt == 3)) {
			cout << "Sorry, it took you too many attempts to login. Program will exit now... .. ." << endl;
			exit(1);
		}	
	} while (good_attempt == false);
}

/********************************************************
 * Function: void wizard_login_print()
 * Input: None
 * Output Printing the wizard information onto the screen
 *******************************************************/
void wizard_login_print(wizard *wizard_data, int enter_id, int wizard_size, string password_i) {

	for (int i = 0; i < wizard_size; i++) {
		if(enter_id == wizard_data[i].id && password_i == wizard_data[i].password) {
			cout << "\nLogin Detail Info" << endl;
			cout << "-----------------" << endl;
			cout << "Welcome: " << wizard_data[i].name << endl;
			cout << "ID: " << wizard_data[i].id << endl;
			cout << "Status: " << wizard_data[i].position_title << endl;
			cout << "Beard Length: " << wizard_data[i].beard_length << endl;
		}
	}
}

/********************************************************
 * Function: void faculty_display()
 * Input: Insert in the number for the sorting information
 * Output None
 *******************************************************/
void faculty_display (spellbook *book_data, int spellbook_size, wizard *wizard_data) {

	string user_input;
	int num_option = 0;
	bool repeat;

	do {
		cout << endl;
		cout << "\nSorting Option Display" << endl;
		cout << "----------------------" << endl;
		cout << "Which option would you like to choose from the selection down below: " << endl;
		cout << "(Press 1) Sort spellbooks by number of pages" << endl;
		cout << "(Press 2) Sort spellbooks by their effect" << endl;
		cout << "(Press 3) Sort spellbooks by their average success rate" << endl;
		cout << "(Press 4) Quit Program" << endl;
		getline(cin,user_input);
		num_option = check_int(user_input);

		if (num_option == 1) {
			faculty_print_pages(book_data, spellbook_size); 
			repeat = true;
		}

		else if (num_option == 2) {
			faculty_print_effect(book_data, spellbook_size);
			repeat = true;
		}

		else if (num_option == 3) {
			faculty_print_avg(book_data, spellbook_size);
			repeat = true;
		}

		else if (num_option == 4) {		
			delete_info(&wizard_data, spellbook_size, &book_data);
			cout << "Thank you for using the Wizard Catalog Database! The program is exiting now.. ." << endl;
			exit(1);	
		}

		else {			
			repeat = true;
		}
	} while (repeat == true);
}

/********************************************************
 * Function: void student_display()
 * Input: Insert in the number for the sorting information
 * Output None
 *******************************************************/
void student_display (spellbook *book_data, int spellbook_size, wizard *wizard_data) {
	
	string user_input;
	int num_option = 0;
	bool repeat;

	do {
		cout << endl;
		cout << "\nSorting Option Display" << endl;
		cout << "----------------------" << endl;
		cout << "Which option would you like to choose from the selection down below: " << endl;
		cout << "(Press 1) Sort spellbooks by number of pages" << endl;
		cout << "(Press 2) Sort spellbooks by their effect" << endl;
		cout << "(Press 3) Sort spellbooks by their average success rate" << endl;
		cout << "(Press 4) Quit Program" << endl;
		getline(cin,user_input);
		num_option = check_int(user_input);
		
		if (num_option == 1) {
			student_print_pages(book_data, spellbook_size);
			repeat = true;
		}

		else if (num_option == 2) {
			student_print_effect(book_data, spellbook_size);
			repeat = true;
		}

		else if (num_option == 3) {
			student_print_avg(book_data, spellbook_size);
			repeat = true;
		}

		else if (num_option == 4) {
			delete_info(&wizard_data, spellbook_size, &book_data);
			cout << "Thank you for using the Wizard Catalog Database! The program is exiting now.. ." << endl;
			exit(1);
		}

		else {
			exit(1);
		}
	} while (repeat == true);

}

/********************************************************
 * Function: void faculty_print_pages()
 * Input: Insert in the number for the sorting of pages
 * Output Print to screen or file
 *******************************************************/
void faculty_print_pages(spellbook *book_data, int spellbook_size) {

	string user_input, file_input;
	int num_option = 0;

	for (int i = 0; i < spellbook_size-1; i++) {
		for (int j = 0; j < spellbook_size-i-1; j++) {
			if(book_data[j].num_pages > book_data[j+1].num_pages) {
				spellbook tmp = book_data[j+1];
				book_data[j+1] = book_data[j];
				book_data[j] = tmp;
			}
		}
	}

	cout << endl;
	cout << "\nMore Sorting Option" << endl;
	cout << "-------------------" << endl;
	cout << "How would you like your information to be display: " << endl;
	cout << "(Press 1) Print to Screen" << endl;
	cout << "(Press 2) Print to File" << endl;
	getline(cin,user_input);
	num_option = check_int(user_input);

	if (num_option == 1) {
		for (int i = 0; i < spellbook_size; i++) {
			cout << "Title: " << book_data[i].title << "  -  Pages: " << book_data[i].num_pages << endl;
		}
	}

	else if (num_option == 2) {
		ofstream file1;
		cout << "Please type in your file name you wanted to be store: ";
		cin >> file_input;
		file1.open(file_input.c_str());
		for (int i = 0; i < spellbook_size; i++) {
			file1 << book_data[i].title << book_data[i].num_pages << endl;
		} 
		cout << "Appended requested information to file!" << endl;
	}

	else {
		cout << "Sorry, your input was not in the range of 1-2. Program exiting now.. ." << endl;
		exit(1);
	}	
}

/********************************************************
 * Function: void student_print_pages()
 * Input: Insert in the number for the sorting of pages
 * Output Print to screen or file
 *******************************************************/
void student_print_pages(spellbook *book_data, int spellbook_size) {

	string user_input, file_input;
	int num_option = 0;

	for (int i = 0; i < spellbook_size-1; i++) {
		for (int j = 0; j < spellbook_size-i-1; j++) {
			if(book_data[j].num_pages > book_data[j+1].num_pages) {
				spellbook tmp = book_data[j+1];
				book_data[j+1] = book_data[j];
				book_data[j] = tmp;
			}
		}
	}

	cout << endl;
	cout << "\nMore Sorting Option" << endl;
	cout << "-------------------" << endl;
	cout << "How would you like your information to be display: " << endl;
	cout << "(Press 1) Print to Screen" << endl;
	cout << "(Press 2) Print to File" << endl;
	getline(cin,user_input);
	num_option = check_int(user_input);

	if (num_option == 1) {
		for (int i = 0; i < spellbook_size; i++) {
			bool access = true;
			for (int j = 0; j < book_data[i].num_spells; j++) {
				if (book_data[i].s[j].effect == "poison" || book_data[i].s[j].effect == "death") {
					access = false;
					break;
				}
			}

			if (access) { 
			cout << "Title: " << book_data[i].title << "  -  Pages: " << book_data[i].num_pages << endl;
			}
		}
	}

	else if (num_option == 2) {
		ofstream file1;
		cout << "Please type in your file name you wanted to be store: ";
		cin >> file_input;
		file1.open(file_input.c_str());
		for (int i = 0; i < spellbook_size; i++) {
			bool access = true;
			for (int j = 0; j < book_data[i].num_spells; j++) {
				if (book_data[i].s[j].effect == "poison" || book_data[i].s[j].effect == "death") {
					access = false;
					break;
				}
			}

			if (access) { 
			file1 << book_data[i].title << book_data[i].num_pages << endl;
			}
		}
		cout << "Appended requested information to file!" << endl;

	}

	else {
		cout << "Sorry, your input was not in the range of 1-2. Program exiting now.. ." << endl;
		exit(1);
	}	
}

/********************************************************
 * Function: void faculty_print_effect()
 * Input: Insert in the number for the sorting of effect
 * Output Print to screen or file
 *******************************************************/
void faculty_print_effect(spellbook *book_data, int spellbook_size) {

	string user_input, file_input;
	int num_option = 0;

	cout << endl;
	cout << "\nMore Sorting Option" << endl;
	cout << "-------------------" << endl;
	cout << "How would you like your information to be display: " << endl;
	cout << "(Press 1) Print to Screen" << endl;
	cout << "(Press 2) Print to File" << endl;
	getline(cin,user_input);
	num_option = check_int(user_input);

	if (num_option == 1) {
		for (int i = 0; i < spellbook_size; i++) {
			for (int j = 0; j < book_data[i].num_spells; j++) {
				if (book_data[i].s[j].effect.compare("bubble") == 0) {
					cout << "Effect: " << book_data[i].s[j].effect << "  -  Spell: " << book_data[i].s[j].name << endl;
				}
			}
		}
		for (int i = 0; i < spellbook_size; i++) {
			for (int j = 0; j < book_data[i].num_spells; j++) {
				if (book_data[i].s[j].effect.compare("memory_loss") == 0) {
					cout << "Effect: " << book_data[i].s[j].effect << "  -  Spell: " << book_data[i].s[j].name << endl;
				}
			}
		}
		for (int i = 0; i < spellbook_size; i++) {
			for (int j = 0; j < book_data[i].num_spells; j++) {
				if (book_data[i].s[j].effect.compare("fire") == 0) {
					cout << "Effect: " << book_data[i].s[j].effect << "  -  Spell: " << book_data[i].s[j].name << endl;
				}
			}
		}
		for (int i = 0; i < spellbook_size; i++) {
			for (int j = 0; j < book_data[i].num_spells; j++) {
				if (book_data[i].s[j].effect.compare("poison") == 0) {
					cout << "Effect: " << book_data[i].s[j].effect << "  -  Spell: " << book_data[i].s[j].name << endl;
				}
			}
		}
		for (int i = 0; i < spellbook_size; i++) {
			for (int j = 0; j < book_data[i].num_spells; j++) {
				if (book_data[i].s[j].effect.compare("death") == 0) {
					cout << "Effect: " << book_data[i].s[j].effect << "  -  Spell: " << book_data[i].s[j].name << endl;
				}
			}
		}
	}

	else if (num_option == 2) {
		ofstream file2;
		cout << "Please type in your file name you wanted to be store: ";
		cin >> file_input;
		file2.open(file_input.c_str());
		for (int i = 0; i < spellbook_size; i++) {
			for (int j = 0; j < book_data[i].num_spells; j++) {
				if (book_data[i].s[j].effect.compare("bubble") == 0) {
					file2 << book_data[i].s[j].effect << book_data[i].s[j].name << endl;
				}
			}
		}
		for (int i = 0; i < spellbook_size; i++) {
			for (int j = 0; j < book_data[i].num_spells; j++) {
				if (book_data[i].s[j].effect.compare("memory_loss") == 0) {
					file2 << book_data[i].s[j].effect << book_data[i].s[j].name << endl;
				}
			}
		}
		for (int i = 0; i < spellbook_size; i++) {
			for (int j = 0; j < book_data[i].num_spells; j++) {
				if (book_data[i].s[j].effect.compare("fire") == 0) {
					file2 << book_data[i].s[j].effect << book_data[i].s[j].name << endl;
				}
			}
		}
		for (int i = 0; i < spellbook_size; i++) {
			for (int j = 0; j < book_data[i].num_spells; j++) {
				if (book_data[i].s[j].effect.compare("poison") == 0) {
					file2 << book_data[i].s[j].effect << book_data[i].s[j].name << endl;
				}
			}
		}
		for (int i = 0; i < spellbook_size; i++) {
			for (int j = 0; j < book_data[i].num_spells; j++) {
				if (book_data[i].s[j].effect.compare("death") == 0) {
					file2 << book_data[i].s[j].effect << book_data[i].s[j].name << endl;
				}
			}
		}
		cout << "Appended requested information to file!" << endl;
	}

	else {
		cout << "Sorry, your input was not in the range of 1-2. Program exiting now.. ." << endl;
		exit(1);
	}	
}

/********************************************************
 * Function: void student_print_effect()
 * Input: Insert in the number for the sorting of effect
 * Output Print to screen or file
 *******************************************************/
void student_print_effect(spellbook *book_data, int spellbook_size) {

	string user_input, file_input;
	int num_option = 0;

	cout << endl;
	cout << "\nMore Sorting Option" << endl;
	cout << "-------------------" << endl;
	cout << "How would you like your information to be display: " << endl;
	cout << "(Press 1) Print to Screen" << endl;
	cout << "(Press 2) Print to File" << endl;
	getline(cin,user_input);
	num_option = check_int(user_input);

	if (num_option == 1) {
		for (int i = 0; i < spellbook_size; i++) {
			for (int j = 0; j < book_data[i].num_spells; j++) {
				if (book_data[i].s[j].effect.compare("bubble") == 0) {
					cout << "Effect: " << book_data[i].s[j].effect << "  -  Spell: " << book_data[i].s[j].name << endl;
				}
			}
		}
		for (int i = 0; i < spellbook_size; i++) {
			for (int j = 0; j < book_data[i].num_spells; j++) {
				if (book_data[i].s[j].effect.compare("memory_loss") == 0) {
					cout << "Effect: " << book_data[i].s[j].effect << "  -  Spell: " << book_data[i].s[j].name << endl;
				}
			}
		}
		for (int i = 0; i < spellbook_size; i++) {
			for (int j = 0; j < book_data[i].num_spells; j++) {
				if (book_data[i].s[j].effect.compare("fire") == 0) {
					cout << "Effect: " << book_data[i].s[j].effect << "  -  Spell: " << book_data[i].s[j].name << endl;
				}
			}
		}
	}

	else if (num_option == 2) {
		ofstream file2;
		cout << "Please type in your file name you wanted to be store: ";
		cin >> file_input;
		file2.open(file_input.c_str());
		for (int i = 0; i < spellbook_size; i++) {
			for (int j = 0; j < book_data[i].num_spells; j++) {
				if (book_data[i].s[j].effect.compare("bubble") == 0) {
					file2 << book_data[i].s[j].effect << book_data[i].s[j].name << endl;
				}
			}
		}
		for (int i = 0; i < spellbook_size; i++) {
			for (int j = 0; j < book_data[i].num_spells; j++) {
				if (book_data[i].s[j].effect.compare("memory_loss") == 0) {
					file2 << book_data[i].s[j].effect << book_data[i].s[j].name << endl;
				}
			}
		}
		for (int i = 0; i < spellbook_size; i++) {
			for (int j = 0; j < book_data[i].num_spells; j++) {
				if (book_data[i].s[j].effect.compare("fire") == 0) {
					file2 << book_data[i].s[j].effect << book_data[i].s[j].name << endl;
				}
			}
		}
		cout << "Appended requested information to file!" << endl;
	}

	else {
		cout << "Sorry, your input was not in the range of 1-2. Program exiting now.. ." << endl;
		exit(1);
	}	
}

/********************************************************
 * Function: void faculty_print_avg()
 * Input: Insert in the number for the sorting of avg
 * Output Print to screen or file
 *******************************************************/
void faculty_print_avg(spellbook *book_data, int spellbook_size) {

	string user_input, file_input;
	int num_option = 0;

	for (int i = 0; i < spellbook_size-1; i++) {
		for (int j = 0; j < spellbook_size-i-1; j++) {
			if(book_data[j].avg_success_rate < book_data[j+1].avg_success_rate) {
				spellbook tmp = book_data[j];
				book_data[j] = book_data[j+1];
				book_data[j+1] = tmp;
			}
		}
	}

	cout << endl;
	cout << "\nMore Sorting Option" << endl;
	cout << "-------------------" << endl;
	cout << "How would you like your information to be display: " << endl;
	cout << "(Press 1) Print to Screen" << endl;
	cout << "(Press 2) Print to File" << endl;
	getline(cin,user_input);
	num_option = check_int(user_input);

	if (num_option == 1) {
		for (int i = 0; i < spellbook_size; i++) {
			cout << "Title: " << book_data[i].title << "  -  Average Rate: " << book_data[i].avg_success_rate << endl;
		}
	}

	else if (num_option == 2) {
		ofstream file3;
		cout << "Please type in your file name you wanted to be store: ";
		cin >> file_input;
		file3.open(file_input.c_str());
		for (int i = 0; i < spellbook_size; i++) {
			file3 << book_data[i].title << book_data[i].avg_success_rate << endl;
		} 
		cout << "Appended requested information to file!" << endl;
	}

	else {
		cout << "Sorry, your input was not in the range of 1-2. Program exiting now.. ." << endl;
		exit(1);
	}	
}

/********************************************************
 * Function: void student_print_avg()
 * Input: Insert in the number for the sorting of avg
 * Output Print to screen or file
 *******************************************************/
void student_print_avg(spellbook *book_data, int spellbook_size) {

	string user_input, file_input;
	int num_option = 0;

	for (int i = 0; i < spellbook_size-1; i++) {
		for (int j = 0; j < spellbook_size-i-1; j++) {
			if(book_data[j].avg_success_rate < book_data[j+1].avg_success_rate) {
				spellbook tmp = book_data[j];
				book_data[j] = book_data[j+1];
				book_data[j+1] = tmp;
			}
		}
	}

	cout << endl;
	cout << "\nMore Sorting Option" << endl;
	cout << "-------------------" << endl;
	cout << "How would you like your information to be display: " << endl;
	cout << "(Press 1) Print to Screen" << endl;
	cout << "(Press 2) Print to File" << endl;
	getline(cin,user_input);
	num_option = check_int(user_input);

	if (num_option == 1) {
			for (int i = 0; i < spellbook_size; i++) {
				bool access = true;
				for (int j = 0; j < book_data[i].num_spells; j++) {
					if (book_data[i].s[j].effect == "poison" || book_data[i].s[j].effect == "death") {
						access = false;
						break;
					}
				}

				if (access) { 
					cout << "Title: " << book_data[i].title << "  -  Average Rate: " << book_data[i].avg_success_rate << endl;
				}
			}
	}

	else if (num_option == 2) {
		ofstream file3;
		cout << "Please type in your file name you wanted to be store: ";
		cin >> file_input;
		file3.open(file_input.c_str());
		for (int i = 0; i < spellbook_size; i++) {
			bool access = true;
			for (int j = 0; j < book_data[i].num_spells; j++) {
				if (book_data[i].s[j].effect == "poison" || book_data[i].s[j].effect == "death") {
					access = false;
					break;
				}
			}

			if (access) { 
				file3 << book_data[i].title << book_data[i].avg_success_rate << endl;
			}
		}
		cout << "Appended requested information to file!" << endl;
	}

	else {
		cout << "Sorry, your input was not in the range of 1-2. Program exiting now.. ." << endl;
		exit(1);
	}	
}

/********************************************************
 * Function: void delete_info()
 * Input: None
 * Output None
 *******************************************************/
void delete_info(wizard **wizard_data, int spellbook_size, spellbook **book_data) {

	delete [] *wizard_data;
	*wizard_data = NULL;

	for (int i = 0; i < spellbook_size; i++) {
		delete [] (*book_data)[i].s;
		(*book_data)[i].s = NULL;
	}

	delete [] *book_data;
	*book_data = NULL;
}

/********************************************************
 * Function: int check_int()
 * Input: None
 * Output None
 *******************************************************/
int check_int(string input) {

	int good_i = 0;
	bool check_i;

	do {
		check_i = false;
		
		for (int i = 0; i < input.length(); i++) {
			if (!(input.at(i) >= '0' && input.at(i) <= '9')) {
				cout << "Your response wasn't an integer, please try again: ";
				getline(cin,input);
				check_i = true;
				break;
			}
		}
	} while (check_i);

	good_i = atoi(input.c_str());

return good_i;
}
