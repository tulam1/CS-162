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

int main(int argc, char *argv[]) {

	int read_file1 = 0, read_file2 = 0;
	wizard wiz_info;
	
	if (argc < 3) {
		cout << "Please provide enough line command argument" << endl;
		exit(1);
	}

	fstream wizard_db;
	wizard_db.open(argv[1]);
	if (!wizard_db.is_open()) {
		cout << "File for wizards couldn't be open" << endl;
		exit(1);
	}
	wizard_db >> read_file1;
	wizard* wizard_data = create_wizard_db(read_file1);
	get_wizard_db(wizard_data, read_file1, wizard_db);
	wizard_db.close();

	fstream spellbook_db;
	spellbook_db.open(argv[2]);
	if (!spellbook_db.is_open()) {
		cout << "File for spellbooks couldn't be open" << endl;
		exit(1);
	}
	spellbook_db >> read_file2;
	spellbook* book_data = create_spellbook_db(read_file2);
	get_spellbook_db(book_data, read_file2, spellbook_db);
	spellbook_db.close();	

	title();
	wizard_login_info(wizard_data, read_file1, &wiz_info);

	if (wiz_info.position_title == "Headmaster" || wiz_info.position_title == "Teacher") {
		faculty_display(book_data, read_file2, wizard_data);
		delete_info(&wizard_data, read_file2, &book_data);
	}

	else if (wiz_info.position_title == "Student") {
		student_display(book_data, read_file2, wizard_data);
		delete_info(&wizard_data, read_file2, &book_data);
	}
	delete_info(&wizard_data, read_file2, &book_data);

return 0;
}
