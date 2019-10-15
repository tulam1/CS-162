/********************************************************************************************************************
 * Program: zoo.cpp
 * Author: Tu Lam
 * Date: 04/29/2019
 * Description: The implementation cpp file where all the function body is in a function.
 * Input: No input.
 * Output: No output.
 *******************************************************************************************************************/

#include <iostream>
#include <string>
#include <cstdlib>
#include "zoo.h"

using namespace std;

/************************************************************
 * Function: Zoo::Zoo();
 * Input: None.
 * Output: Default constructor setting the private variables.
 ***********************************************************/
Zoo::Zoo() {

	week = 0;
	bank = 100000;
	base_food = 40;
	capacity = 20;
	bankrupt = false;
	num_monkey = 0;
	num_sea_otter = 0;
	num_meerkat = 0;
	monkey_arr = new Monkey[num_monkey];
	sea_otter_arr = new Sea_Otter[num_sea_otter];
	meerkat_arr = new Meerkat[num_meerkat];
}

/************************************************************
 * Function: Zoo::~Zoo();
 * Input: None.
 * Output: Destructor deleting the private array created.
 ***********************************************************/
Zoo::~Zoo() {

	delete [] this->monkey_arr;
	delete [] this->sea_otter_arr;
	delete [] this->meerkat_arr;

}

/************************************************************
 * Function: Zoo::Zoo(const Zoo &)
 * Input: None.
 * Output: Copy constructor for copying object.
 ***********************************************************/
Zoo::Zoo(const Zoo &old_obj) {	

	this->week = old_obj.week;
	this->bank = old_obj.bank;
	this->base_food = old_obj.base_food;
	this->capacity = old_obj.capacity;
	this->num_monkey = old_obj.num_monkey;
	this->num_sea_otter = old_obj.num_sea_otter;
	this->num_meerkat = old_obj.num_meerkat;

	this->monkey_arr = new Monkey[num_monkey];
	this->sea_otter_arr = new Sea_Otter[num_sea_otter];
	this->meerkat_arr = new Meerkat[num_meerkat];

	for (int i = 0; i < num_monkey; i++) 
		monkey_arr[i] = old_obj.monkey_arr[i];

	for (int i = 0; i < num_sea_otter; i++) 
		sea_otter_arr[i] = old_obj.sea_otter_arr[i];

	for (int i = 0; i < num_meerkat; i++) 
		meerkat_arr[i] = old_obj.meerkat_arr[i];
}

/************************************************************
 * Function: Zoo& Zoo::operator=(const Zoo &)
 * Input: None.
 * Output: Assignment Overload for copying object.
 ***********************************************************/
Zoo& Zoo::operator=(const Zoo &old_obj) {	

	if (this != &old_obj) {
		delete [] monkey_arr;
		delete [] sea_otter_arr;
		delete [] meerkat_arr;
		this->week = old_obj.week;
		this->bank = old_obj.bank;
		this->base_food = old_obj.base_food;
		this->capacity = old_obj.capacity;
		this->num_monkey = old_obj.num_monkey;
		this->num_sea_otter = old_obj.num_sea_otter;
		this->num_meerkat = old_obj.num_meerkat;

		this->monkey_arr = new Monkey[num_monkey];
		this->sea_otter_arr = new Sea_Otter[num_sea_otter];
		this->meerkat_arr = new Meerkat[num_meerkat];

		for (int i = 0; i < num_monkey; i++) 
			monkey_arr[i] = old_obj.monkey_arr[i];

		for (int i = 0; i < num_sea_otter; i++) 
			sea_otter_arr[i] = old_obj.sea_otter_arr[i];

		for (int i = 0; i < num_meerkat; i++) 
			meerkat_arr[i] = old_obj.meerkat_arr[i];
	}

return *this;
}

/*************************************************
 * Function: void Zoo::main_menu();
 * Input: None.
 * Output: Display the main menu of the game.
 ************************************************/
void Zoo::main_menu() {

	title_screen();

	while (bankrupt == false) {
		if (bank > 0) {
			++week;
			cout << endl;
			cout << "\nWeek: " << week << endl;
			cout << "Welcome to week " << week << " of the game, here is your current balance: $" << bank << endl;
			cout << "Adult Monkey: " << num_monkey << "  Babies: " << (*monkey_arr).get_babies() << endl;
			cout << "Adult Sea Otter: " << num_sea_otter << "  Babies: " << (*sea_otter_arr).get_babies() << endl;
			cout << "Adult Meerkat: " << num_meerkat << "  Babies: " << (*meerkat_arr).get_babies() << endl;

			random_events();
			revenue_collect();
			buy_animal();
			cost_deduction();
			increment_animal();
			play_again(bankrupt);
			cout << endl;
		}

		else if (bankrupt <= 0) {
			cout << "\nSorry!, you end up with no money left." << endl;
			cout << "GAME OVER!" << endl;
			bankrupt = true;
		}
	}
}

/***********************************************************
 * Function: void Zoo::play_again(bool &);
 * Input: None.
 * Output: Return true or false if players want to continue.
 **********************************************************/
void Zoo::play_again(bool &go) {

	string input;
	int end = 0;

	cout << "\nDo you want to continue playing the game?" << endl;
	cout << "(Press 1) Yes" << endl;
	cout << "(Press 0) No" << endl;
	cout << "Your Selection: ";
	getline(cin,input);
	end = check_i(input);

	while (end < 0 || end > 1) {
		cout << "You did not enter the number in the range of 0-1, please try again: ";
		getline(cin,input);
		end = check_i(input);
	}

	if (end == 0) {
		cout << "\nThank you for playing, see you again!" << endl;
		cout << "GAME OVER!" << endl;
		go = true;
	}

	else if (end == 1) {
		go = false;
	}
}

/*************************************************
 * Function: void Zoo::increment_week();
 * Input: None.
 * Output: Increment the week up to the next week.
 ************************************************/
void Zoo::increment_animal() {

	for (int i = 0; i < num_monkey; i++) {
		monkey_arr[i].increment_age(7);
	}

	for (int j = 0; j < num_sea_otter; j++) {
		sea_otter_arr[j].increment_age(7);
	}

	for (int k = 0; k < num_meerkat; k++) {
		meerkat_arr[k].increment_age(7);
	}
}

/**************************************************
 * Function: void Zoo::buy_animal(int);
 * Input: None.
 * Output: The prompt letting users to buy animals.
 *************************************************/
void Zoo::buy_animal() {

	int buy = 0, num = 0;
	string u_input, n_input;

		cout << "\nWould you like to buy an animal? If so, here is your option:" << endl;
		cout << "(Press 1) Buy Monkey(s) [Each Monkey cost $15,000]" << endl;
		cout << "(Press 2) Buy Sea Otter(s) [Each Sea Otter cost $5,000]" << endl;
		cout << "(Press 3) Buy Meerkat(s) [Each Meerkat cost $500]" << endl;
		cout << "(Press 4) No Animal" << endl;
		cout << "Your Selection: ";
		getline(cin,u_input);
		buy = check_i(u_input);

		while (buy < 1 || buy > 4) {
			cout << "You did not enter the number in the range of 1-4, please try again: ";
			getline(cin,u_input);
			buy = check_i(u_input);
		}

		if (buy == 1 || buy == 2 || buy == 3) {
			cout << "\nHow many of this animal would you like to buy? (0 - 2) ";
			getline(cin,n_input);
			num = check_i(n_input);

			while (num < 0 || num > 2) {
				cout << "You did not enter the number in the range of 0-2, please try again: ";
				getline(cin,n_input);
				num = check_i(n_input);
			}

			animal_type(buy, num);
		}
}

/**************************************************
 * Function: void Zoo::animal_type(int, int);
 * Input: None.
 * Output: Looping and adding in animals.
 *************************************************/
void Zoo::animal_type(int buy, int num) {

	for (int i = 0; i < num; i++) {
		if (buy == 1) {
			increase_capacity_monkey();
			add_monkey();
			bank -= monkey_arr[0].get_animal_cost();
		}

		else if (buy == 2) {
			increase_capacity_sea_otter();
			add_sea_otter();
			bank -= sea_otter_arr[0].get_animal_cost();
		}

		else if (buy == 3) {
			increase_capacity_meerkat();
			add_meerkat();
			bank -= meerkat_arr[0].get_animal_cost();
		}
	}
	cout << "\nYour bank total after buying the animals: " << bank << endl; 
}

/**************************************************
 * Function: void Zoo::cost_deduction();
 * Input: None.
 * Output: Calculating the cost deduction.
 *************************************************/
void Zoo::cost_deduction() {

	float percent = 0;
	float monkey_cost = 0;
	float sea_otter_cost = 0;
	float meerkat_cost = 0;
	float total_cost = 0;

	percent = (float)((rand() %51) + 75) * 0.01;
	base_food = base_food * percent;

	for (int i = 0; i < num_monkey; i++) {
		monkey_cost += monkey_arr[i].food_expense(base_food);
	}
	
	for (int j = 0; j < num_sea_otter; j++) {
		sea_otter_cost += sea_otter_arr[j].food_expense(base_food);
	}

	for (int k = 0; k < num_meerkat; k++) {
		meerkat_cost += meerkat_arr[k].food_expense(base_food);
	}

	total_cost = monkey_cost + sea_otter_cost + meerkat_cost;

	bank -= total_cost;
	cout << "\nYour total balance left after feeding the animals: " << bank << endl;
}

/*************************************************
 * Function: void Zoo::add_monkey();
 * Input: None.
 * Output: Setting up the array to add the monkey.
 ************************************************/
void Zoo::random_events() {

	int event = ((rand() %4) + 1);

	random_event_title();
	if (event == 1) {
		sick_animal();
	}

	else if (event == 2) {
		babies_populate();
	}

	else if (event == 3) {
		revenue_bonus();
	}

	else if (event == 4) {
		cout << "No special event occurs during this week." << endl;
		cout << "Enjoy the rest of the day!" << endl;
	}
}

/*************************************************
 * Function: void Zoo::add_monkey();
 * Input: None.
 * Output: Setting up the array to add the monkey.
 ************************************************/
void Zoo::add_monkey() {

	Monkey tmp[num_monkey];
	
	for (int i = 0; i < num_monkey; i++) {
		tmp[i] = monkey_arr[i];
	}

	num_monkey = num_monkey + 1; //Add an extra slot to the num_monkey
	delete [] monkey_arr;
	monkey_arr = new Monkey[num_monkey];

	for (int j = 0; j < num_monkey - 1; j++) { //-1 due to extra slot
		monkey_arr[j] = tmp[j];
	}
}

/*************************************************
 * Function: void Zoo::add_sea_otter();
 * Input: None.
 * Output: Setting up the array to add sea otter.
 ************************************************/
void Zoo::add_sea_otter() {

	Sea_Otter tmp[num_sea_otter];
	
	for (int i = 0; i < num_sea_otter; i++) {
		tmp[i] = sea_otter_arr[i];
	}

	num_sea_otter = num_sea_otter + 1; //Add an extra slot to the num_sea_otter
	delete [] sea_otter_arr;
	sea_otter_arr = new Sea_Otter[num_sea_otter];

	for (int j = 0; j < num_sea_otter - 1; j++) { //-1 due to etra slot
		sea_otter_arr[j] = tmp[j];
	}
}

/**************************************************
 * Function: void Zoo::add_meerkat();
 * Input: None.
 * Output: Setting up the array to add the meerkat.
 *************************************************/
void Zoo::add_meerkat() {

	Meerkat tmp[num_meerkat];
	
	for (int i = 0; i < num_meerkat; i++) {
		tmp[i] = meerkat_arr[i];
	}

	num_meerkat = num_meerkat + 1; //Add an extra slot to the num_monkey
	delete [] meerkat_arr;
	meerkat_arr = new Meerkat[num_meerkat];

	for (int j = 0; j < num_meerkat - 1; j++) { //-1 due to extra slot
		meerkat_arr[j] = tmp[j];
	}
}

/***************************************************************
 * Function: void Zoo::increase_capacity_monkey();
 * Input: None.
 * Output: Setting up the array to increase capacity for monkey.
 **************************************************************/
void Zoo::increase_capacity_monkey() {

	if (num_monkey >= capacity) {
		Monkey *tmp = new Monkey[capacity * 2];
		
		for (int i = 0; i < capacity; i++) {
			tmp[i] = monkey_arr[i];
		}

		delete [] monkey_arr;
		capacity *= 2;
		monkey_arr = tmp;
		delete [] tmp;
	}
}

/***************************************************************
 * Function: void Zoo::increase_capacity_sea_otter();
 * Input: None.
 * Output: Setting up the array to increase capacity for sea ot.
 **************************************************************/
void Zoo::increase_capacity_sea_otter() {

	if (num_sea_otter >= capacity) {
		Sea_Otter *tmp = new Sea_Otter[capacity * 2];
		
		for (int i = 0; i < capacity; i++) {
			tmp[i] = sea_otter_arr[i];
		}

		delete [] sea_otter_arr;
		capacity *= 2;
		sea_otter_arr = tmp;
		delete [] tmp;
	}
}

/****************************************************************
 * Function: void Zoo::increase_capacity_meerkat();
 * Input: None.
 * Output: Setting up the array to increase capacity for meerkat.
 ***************************************************************/
void Zoo::increase_capacity_meerkat() {

	if (num_meerkat >= capacity) {
		Meerkat *tmp = new Meerkat[capacity * 2];
		
		for (int i = 0; i < capacity; i++) {
			tmp[i] = meerkat_arr[i];
		}

		delete [] meerkat_arr;
		capacity *= 2;
		meerkat_arr = tmp;
		delete [] tmp;
	}
}

/*************************************************
 * Function: void Zoo::set_week(int);
 * Input: None.
 * Output: Setting up the week by incrementing it.
 ************************************************/
void Zoo::set_week(int count) {

	this->week = count;
}

/***********************************
 * Function: int Zoo::get_week();
 * Input: None.
 * Output: Return the value of week.
 **********************************/
int Zoo::get_week() {

return week;
}

/*************************************************
 * Function: void Zoo::set_bank(float);
 * Input: None.
 * Output: Setting up the bank by assign it.
 ************************************************/
void Zoo::set_bank(float bank) {

	this->bank = bank;
}

/**************************************
 * Function: float Zoo::get_bank();
 * Input: None.
 * Output: Return the value of bank.
 *************************************/
float Zoo::get_bank() {

return bank;
}


/*************************************************
 * Function: void Zoo::set_base_food(float);
 * Input: None.
 * Output: Setting up the base food by assign it.
 ************************************************/
void Zoo::set_base_food(float food) {

	this->base_food = food;
}

/*****************************************
 * Function: float Zoo::get_daily_food();
 * Input: None.
 * Output: Return the value of daily food.
 ****************************************/
float Zoo::get_base_food() {

return base_food;
}

/*****************************************
 * Function: void Zoo::sick_animal();
 * Input: None.
 * Output: Make an animal sick.
 ****************************************/
void Zoo::sick_animal() {

	int animal = 0;
	animal = ((rand() %3) + 1);

	cout << "Look like an event happen in your zoo, one of your animals are chosen to be affected with sickness." << endl;
	if (animal == 1) {
		if (num_monkey > 0) {
			cout << "Uh Oh... Look like one your Monkey got sick!" << endl;
			sick_monkey();
		}

		else if (num_monkey == 0) {
			cout << "Well, since there is no monkey in the zoo, no monkey could get sick, enjoy the rest of the day!" << endl;
		}
	}

	else if (animal == 2) {
		if (num_sea_otter > 0) {
			cout << "Uh Oh... Look like one your Sea Otter got sick!" << endl;
			sick_sea_otter();
		}

		else if (num_sea_otter == 0) {
			cout << "Well, since there is no sea otter in the zoo, no sea otter could get sick, enjoy the rest of the day!" << endl;
		}
	}

	else if (animal == 3) {
		if (num_meerkat > 0) {
			cout << "Uh Oh... Look like one your Meerkat got sick!" << endl;
			sick_meerkat();
		}

		else if (num_meerkat == 0) {
			cout << "Well, since there is no meerkat in the zoo, no meerkat could get sick, enjoy the rest of the day!" << endl;
		}
	}

	cout << "\nYour bank account after treating/no treating the sick animal: " << bank << endl;

}

/***********************************************************
 * Function: void Zoo::sick_monkey();
 * Input: None.
 * Output: Seeing if users have enough money to cure animal.
 **********************************************************/
void Zoo::sick_monkey() {

	int pick = 0;
	
	if (bank > 7500) {
		cout << "Look like you have enough money to cure the monkey, expense will be subtracted now.. ." << endl;
		bank -= 7500;
	}

	else if (bank < 7500) {
		cout << "Since you have enough money to pay for the sick monkey, the monkey will die and remove from the zoo." << endl;
		pick = (rand() %num_monkey);
		remove_monkey(pick);
	}
}

/***********************************************************
 * Function: void Zoo::sick_sea_otter();
 * Input: None.
 * Output: Seeing if users have enough money to cure animal.
 **********************************************************/
void Zoo::sick_sea_otter() {

	int pick = 0;

	if (bank > 2500) {
		cout << "Look like you have enough money to cure the sea otter, expense will be subtracted now.. ." << endl;
		bank -= 2500;
	}

	else if (bank < 2500) {
		cout << "Since you have enough money to pay for the sick sea otter, it will be remove from the zoo." << endl;
		pick = (rand() %num_sea_otter);
		remove_sea_otter(pick);
	}
}

/***********************************************************
 * Function: void Zoo::sick_meerkat();
 * Input: None.
 * Output: Seeing if users have enough money to cure animal.
 **********************************************************/
void Zoo::sick_meerkat() {

	int pick = 0;
		
	if (bank > 250) {
		cout << "Look like you have enough money to cure the sea otter, expense will be subtracted now.. ." << endl;
		bank -= 250;
	}

	else if (bank < 250) {
		cout << "Since you have enough money to pay for the sick meerkat, the meerkat will die and remove from the zoo." << endl;
		pick = (rand() %num_meerkat);
		remove_meerkat(pick);
	}
}


/***********************************************************
 * Function: void Zoo::remove_monkey();
 * Input: None.
 * Output: Removed a random monkey in the zoo.
 **********************************************************/
void Zoo::remove_monkey(int pick_m) {

	Monkey tmp[num_monkey];

	for (int i = 0; i < pick_m; i++) { //All monkeys up to the pick_m are being transfer to the array
		tmp[i] = monkey_arr[i];
	}

	for (int i = pick_m + 1; i < num_monkey; i++) { //All monkeys after the pick_m are transfer
		tmp[i-1] = monkey_arr[i];
	}

	num_monkey--; //Decrease the size
	delete [] monkey_arr;
	monkey_arr = new Monkey[num_monkey]; //Assign the new array
	
	for (int i = 0; i < num_monkey; i++) {
		monkey_arr[i] = tmp[i];
	}
}

/***********************************************************
 * Function: void Zoo::remove_sea_otter();
 * Input: None.
 * Output: Removed a random sea otter in the zoo.
 **********************************************************/
void Zoo::remove_sea_otter(int pick_s) {

	Sea_Otter tmp[num_sea_otter];

	for (int i = 0; i < pick_s; i++) { //All monkeys up to the pick_s are being transfer to the array
		tmp[i] = sea_otter_arr[i];
	}

	for (int i = pick_s + 1; i < num_sea_otter; i++) { //All monkeys after the pick_s are transfer
		tmp[i-1] = sea_otter_arr[i];
	}

	num_sea_otter--; //Decrease the size
	delete [] sea_otter_arr;
	sea_otter_arr = new Sea_Otter[num_sea_otter]; //Assign the new array
	
	for (int i = 0; i < num_sea_otter; i++) {
		sea_otter_arr[i] = tmp[i];
	}
}

/***********************************************************
 * Function: void Zoo::remove_meerkat();
 * Input: None.
 * Output: Removed a random meerkat in the zoo.
 **********************************************************/
void Zoo::remove_meerkat(int pick_me) {

	Meerkat tmp[num_meerkat];

	for (int i = 0; i < pick_me; i++) { //All monkeys up to the pick_me are being transfer to the array
		tmp[i] = meerkat_arr[i];
	}

	for (int i = pick_me + 1; i < num_meerkat; i++) { //All monkeys after the pick_me are transfer
		tmp[i-1] = meerkat_arr[i];
	}

	num_meerkat--; //Decrease the size
	delete [] meerkat_arr;
	meerkat_arr = new Meerkat[num_meerkat]; //Assign the new array
	
	for (int i = 0; i < num_meerkat; i++) {
		meerkat_arr[i] = tmp[i];
	}
}

/*****************************************
 * Function: void Zoo::babies_populate();
 * Input: None.
 * Output: Adding a baby to the zoo.
 ****************************************/
void Zoo::babies_populate() {

	int animals = 0;
	animals = ((rand() %3) + 1);

	if (animals == 1) {
		cout << "Something happen in the zoo today, look likes the Monkeys is having babies! " << endl;
		if (num_monkey > 0) {		
			add_monkey_babies();
		}

		else if (num_monkey == 0) {
			cout << "Sorry, since there is no Monkey in the zoo, there will be no baby being born." << endl; 
		}
	}

	else if (animals == 2) {
		cout << "Something happen in the zoo today, look likes the Sea Otters is having babies! " << endl;
		if (num_sea_otter > 0) {
			add_sea_otter_babies();		
		}

		else if (num_sea_otter == 0) {
			cout << "Sorry, since there is no Sea Otter in the zoo, there will be no baby being born." << endl; 
		}
	}

	else if (animals == 3) {
		cout << "Something happen in the zoo today, look likes the Meerkats is having babies! " << endl;
		if (num_meerkat > 0) {
			add_meerkat_babies();		
		}

		else if (num_meerkat == 0) {
			cout << "Sorry, since there is no Meerkat in the zoo, there will be no baby being born." << endl; 
		}
	}
}

/******************************************
 * Function: void Zoo::add_monkey_babies();
 * Input: None.
 * Output: Adding a baby Monkey to the zoo.
 *****************************************/
void Zoo::add_monkey_babies() {

	for (int i = 0; i < num_monkey; i++) {
		if (monkey_arr[i].get_age() >= 730) {
			monkey_arr[i].add_babies(1);
		}

		else if (monkey_arr[i].get_age() < 730) {
			cout << "Sorry, one of our monkey we chose randomly seem to be an adolescent or a baby" << endl;
			cout << "So there will be no babies being born." << endl;
		}
	}
}

/*********************************************
 * Function: void Zoo::add_sea_otter_babies();
 * Input: None.
 * Output: Adding a baby Sea Otter to the zoo.
 ********************************************/
void Zoo::add_sea_otter_babies() {

	for (int i = 0; i < num_sea_otter; i++) {
		if (sea_otter_arr[i].get_age() >= 730) {
			monkey_arr[i].add_babies(2);
		}

		else if (sea_otter_arr[i].get_age() < 730) {
			cout << "Sorry, one of our sea otter we chose randomly seem to be an adolescent or a baby" << endl;
			cout << "So there will be no babies being born." << endl;
		}
	}
}

/*******************************************
 * Function: void Zoo::add_meerkat_babies();
 * Input: None.
 * Output: Adding a baby Meerkat to the zoo.
 ******************************************/
void Zoo::add_meerkat_babies() {

	for (int i = 0; i < num_meerkat; i++) {
		if (meerkat_arr[i].get_age() >= 730) {
			meerkat_arr[i].add_babies(5);
		}

		else if (meerkat_arr[i].get_age() < 730) {
			cout << "Sorry, one of our meerkat we chose randomly seem to be an adolescent or a baby" << endl;
			cout << "So there will be no babies being born." << endl;
		}
	}
}

/******************************************
 * Function: void Zoo::revenue_bonus();
 * Input: None.
 * Output: Adding bonus to the revenue.
 *****************************************/
void Zoo::revenue_bonus() {

	int bonus = 0;
	int total_bonus = 0;
	bonus = ((rand() %401) + 300);

	cout << "There is a booming in the zoo attendance." << endl;
	if (num_monkey > 0) {
		cout << "You will now receive a bonus for each Monkeys ranging between $300-$700." << endl;
		bonus = bonus * num_monkey;
		total_bonus = bonus;
		bank += total_bonus;
	}

	else if (num_monkey == 0) {
		cout << "Since there is no Monkey in your zoo, there will be no bonus revenue to your bank." << endl;
	}

	cout << "Your amount after revenue: " << bank << endl;
}

/******************************************
 * Function: void Zoo::revenue_collect();
 * Input: None.
 * Output: Adding income to the bank.
 *****************************************/
void Zoo::revenue_collect() {

	float monkey_income = 0;
	float sea_otter_income = 0;
	float meerkat_income = 0;
	float total_income = 0;

	for (int i = 0; i < num_monkey; i++) {
		monkey_income += monkey_arr[i].get_income();
		if (monkey_arr[i].get_age() < 35) {
			monkey_income += (monkey_arr[i].get_income() * 2);
		}
	}

	for (int j = 0; j < num_sea_otter; j++) {
		sea_otter_income += sea_otter_arr[j].get_income();
		if (sea_otter_arr[j].get_age() < 35) {
			sea_otter_income += (sea_otter_arr[j].get_income() * 2);
		}
	}
	
	for (int k = 0; k < num_meerkat; k++) {
		meerkat_income += meerkat_arr[k].get_income();	
		if (meerkat_arr[k].get_age() < 35) {
			meerkat_income += (meerkat_arr[k].get_income() * 2);
		}		
	}

	total_income = monkey_income + sea_otter_income + meerkat_income;
	bank += total_income;

	cout << "\nYour bank after collect the incomes: " << bank << endl;
}
