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

using namespace std;

//This is all the struct for the program to help out the sorting and login
struct wizard {

	string name;
	int id;
	string password;
	string position_title;
	string beard_length;	
};

struct spellbook {

	string title;
	string author;
	int num_pages;
	int edition;
	int num_spells;
	float avg_success_rate;
	struct spell *s;
};

struct spell {

	string name;
	float success_rate;
	string effect;
};

//This is where all the function prototype are being declare
wizard* create_wizard_db(int wizard_size);
void get_wizard_db(wizard *wizard_data, int read_file1, fstream &wizard_db);
spellbook* create_spellbook_db(int spellbook_size);
void get_spellbook_db(spellbook *book_data, int read_file2, fstream &spellbook_db);
spell* create_spell_db(int spell_size);
void get_spell_db(spell *spell_data, int spell_size, fstream &spellbook_db);
void avg_calculation(spell *spell_data, int spell_size, spellbook &book_data);
void title();
void wizard_login_info(wizard *wizard_data, int wizard_size, wizard *wiz_info);
void wizard_login_print(wizard *wizard_data, int enter_id, int wizard_size, string password_i);
void faculty_display(spellbook *book_data, int spellbook_size, wizard *wizard_data);
void student_display(spellbook *book_data, int spellbook_size, wizard *wizard_data);
void faculty_print_pages(spellbook *book_data, int spellbook_size);
void student_print_pages(spellbook *book_data, int spellbook_size);
void faculty_print_effect(spellbook *book_data, int spellbook_size);
void student_print_effect(spellbook *book_data, int spellbook_size);
void faculty_print_avg(spellbook *book_data, int spellbook_size);
void student_print_avg(spellbook *book_data, int spellbook_size);
void delete_info(wizard **wizard_data, int spellbook_size, spellbook **book_data); 
int check_int(string input);

