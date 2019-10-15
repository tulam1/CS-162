/******************************************************************************************************
 * Program: game.cpp
 * Author: Tu Lam
 * Date: 05/16/2019
 * Description: The implementation file to implement all the body function from class into the program.
 * Input: None.
 * Output: None.
 *****************************************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include "room.h"
#include "game.h"
#include "bat.h"
#include "pit.h"
#include "player.h"
#include "gold.h"
#include "wumpus.h"

using namespace std;

/*********************************************************
 * Function: Game::Game();
 * Input: None.
 * Output: Constructor to assign the variable with values.
 ********************************************************/
Game::Game() {

	bat1 = new Bat;
	bat2 = new Bat;
	pit1 = new Pit;
	pit2 = new Pit;
	wumpus = new Wumpus;
	gold = new Gold;
	player = new Player;
	start_x = 0, start_y = 0;
	arrow = 3;
	player_x = 0, player_y = 0;
	gold_x = 0, gold_y = 0;
	wum_x = 0, wum_y = 0;
	p1_x = 0, p1_y = 0;
	p2_x = 0, p2_y = 0;
	b1_x = 0, b1_y = 0;
	b2_x = 0, b2_y = 0;
	is_gold = false;
	is_wumpus = false;
	is_pit1 = false;
	is_pit2 = false;
	gameplay = true;
	wumpus_dead = false;
}

/*********************************************************
 * Function: Game::~Game();
 * Input: None.
 * Output: Destructor to delete the variable with value.
 ********************************************************/
Game::~Game() {

	if (bat1 != NULL)
		delete bat1;

	if (bat2 != NULL)
		delete bat2;

	if (pit1 != NULL)
		delete pit1;

	if (pit2 != NULL)
		delete pit2;

	if (wumpus != NULL)
		delete wumpus;

	if (gold != NULL)
		delete gold;

	if (player != NULL)
		delete player;	
}

/******************************************************
 * Function: void Game::main_game(int, string);
 * Input: None.
 * Output: Setting up the game and printing the board.
 *****************************************************/
void Game::main_game(int size, string debug) {

	intro_message();
	set_all_percepts(size);

	do {
		player_info();
		cout << "\nPercept Hint(s)" << endl;
		cout << "---------------" << endl;
		check_percepts();

		if (debug == "true" || debug == "True") {
			print_board_true();
			board_games = true;
		}

		else if (debug == "false" || debug == "False") {
			print_board_false();
			board_games = false;
		}

		moving_player();
		event_encounter();
	} while (gameplay == true);
}

/********************************************************
 * Function: void Game::set_room(int);
 * Input: None.
 * Output: Setting up the room based on the command line.
 *******************************************************/
void Game::set_room(int grid) {

	for (int i = 0; i < grid; i++) {
		vector <Room> row;
		for (int j = 0; j < grid; j++) {
			Room empty;
			row.push_back(empty);
		}
		game_map.push_back(row);
	}
}

/********************************************************
 * Function: void Game::print_board_true();
 * Input: None.
 * Output: Printing the board based on debug mode.
 *******************************************************/
void Game::print_board_true() {

	for (unsigned int i = 0; i < game_map.size(); i++) {
		for (unsigned int j = 0; j < game_map.size(); j++) {
			cout << "[ ";
			Event *room = game_map[i][j].get_event_ptr();
			if (room == NULL) {
				cout << " ";
			}

			else {
			cout << room->get_id();
			}
			cout << " ]";
		}
		cout << endl;
	}
}

/********************************************************
 * Function: void Game::print_board_false();
 * Input: None.
 * Output: Printing the board based on debug mode.
 *******************************************************/
void Game::print_board_false() {

	for (unsigned int i = 0; i < game_map.size(); i++) {
		for (unsigned int j = 0; j < game_map.size(); j++) {
			cout << "[ ";
			Event *room = game_map[i][j].get_event_ptr();
			if (room == NULL) {
				cout << " ";
			}

			else if (room->get_id() == '*') {
				cout << room->get_id();
			}

			else {
				cout << " ";
			}
			cout << " ]";
		}
		cout << endl;
	}
}

/********************************************************
 * Function: void Game::set_percept_bats();
 * Input: None.
 * Output: Setting the percept to the board.
 *******************************************************/
void Game::set_percept_bats() {

	int x = 0, y = 0;

	x = rand() %game_map.size();
	y = rand() %game_map.size();


	while (game_map[y][x].get_event_ptr() != NULL) {
		x = rand() %game_map.size();
		y = rand() %game_map.size();
	}

	game_map[y][x].set_event_ptr(bat1);
	b1_x = x;
	b1_y = y;

	x = rand() %game_map.size();
	y = rand() %game_map.size();

	while (game_map[y][x].get_event_ptr() != NULL) {
		x = rand() %game_map.size();
		y = rand() %game_map.size();
	}

	game_map[y][x].set_event_ptr(bat2);
	b2_x = x;
	b2_y = y;

}

/********************************************************
 * Function: void Game::set_percept_pits();
 * Input: None.
 * Output: Setting the percept to the board.
 *******************************************************/
void Game::set_percept_pits() {

	int x = 0, y = 0;

	x = rand() %game_map.size();
	y = rand() %game_map.size();

	while (game_map[y][x].get_event_ptr() != NULL) {
		x = rand() %game_map.size();
		y = rand() %game_map.size();
	}

	game_map[y][x].set_event_ptr(pit1);
	p1_x = x;
	p2_y = y;

	x = rand() %game_map.size();
	y = rand() %game_map.size();
	
	while (game_map[y][x].get_event_ptr() != NULL) {
		x = rand() %game_map.size();
		y = rand() %game_map.size();
	}

	game_map[y][x].set_event_ptr(pit2);
	p2_x = x;
	p2_y = y;
}

/********************************************************
 * Function: void Game::set_percept_wumpus();
 * Input: None.
 * Output: Setting the percept to the board.
 *******************************************************/
void Game::set_percept_wumpus() {

	int x = 0, y = 0;

	x = rand() %game_map.size();
	y = rand() %game_map.size();

	while (game_map[y][x].get_event_ptr() != NULL) {
		x = rand() %game_map.size();
		y = rand() %game_map.size();
	}

	game_map[y][x].set_event_ptr(wumpus);

	wum_x = x;
	wum_y = y;
}

/********************************************************
 * Function: void Game::set_percept_gold();
 * Input: None.
 * Output: Setting the percept to the board.
 *******************************************************/
void Game::set_percept_gold() {

	int x = 0, y = 0;

	x = rand() %game_map.size();
	y = rand() %game_map.size();

	while (game_map[y][x].get_event_ptr() != NULL) {
		x = rand() %game_map.size();
		y = rand() %game_map.size();
	}

	game_map[y][x].set_event_ptr(gold);

	gold_x = x;
	gold_y = y;
}

/********************************************************
 * Function: void Game::set_percept_player();
 * Input: None.
 * Output: Setting the percept to the board.
 *******************************************************/
void Game::set_percept_player() {

	int x = 0, y = 0;

	x = rand() %game_map.size();
	y = rand() %game_map.size();

	while (game_map[y][x].get_event_ptr() != NULL) {
		x = rand() %game_map.size();
		y = rand() %game_map.size();
	}

	game_map[y][x].set_event_ptr(player);

	start_x = x;
	start_y = y;

	player_x = start_x;
	player_y = start_y;
}

/********************************************************
 * Function: void Game::set_all_percepts(int);
 * Input: None.
 * Output: A function to have all the set functions in.
 *******************************************************/
void Game::set_all_percepts(int grid_size) {

	set_room(grid_size);
	set_percept_bats();
	set_percept_pits();
	set_percept_gold();
	set_percept_wumpus();
	set_percept_player();
}

/********************************************************
 * Function: void Game::moving_player();
 * Input: None.
 * Output: A function to move the player around the map.
 *******************************************************/
void Game::moving_player() {
	
	string move;

	cout << "\nPlayer Movement" << endl;
	cout << "---------------" << endl;
	cout << "Which the direction do you want to move? or Would you like to fire an arrow?" << endl;
	cout << "Movement: Press [W]-North, [A]-West, [S]-South, [D]-East" << endl;
	cout << "Fire Arrow: [ W], [ A], [ S], [ D]" << endl;
	cout << "Your Selection: ";
	getline(cin,move);

	if (move == "w" || move == "W") {
		move_up();
	}

	else if (move == "a" || move == "A") {
		move_left();
	}

	else if (move == "s" || move == "S") {
		move_down();
	}

	else if (move == "d" || move == "D") {
		move_right();
	}

	else if (move == " w" || move == " W") {
		fire_up();
	}

	else if (move == " a" || move == " A") {
		fire_left();
	}

	else if (move == " s" || move == " S") {
		fire_down();
	}

	else if (move == " d" || move == " D") {
		fire_right();
	}

	else {
		cout << "Sorry invalid input. Please enter again." << endl;
		cout << endl;
		print_game_map();
		moving_player();
	}
}

/********************************************************
 * Function: void Game::move_up();
 * Input: None.
 * Output: A function to move the player up the array.
 *******************************************************/
void Game::move_up() {

	if (player_y > 0) {
		Event *up = game_map[player_y][player_x].get_event_ptr();
		game_map[player_y - 1][player_x].set_event_ptr(up);
		game_map[player_y][player_x].set_event_ptr(NULL);

		this->player_y = player_y - 1;
	}

	else {
		cout << "Sorry invalid move. The move you attempt to make seem to be out of bound. Please try again." << endl;
		cout << endl;
		print_game_map();
		moving_player();
	}
}

/********************************************************
 * Function: void Game::move_down();
 * Input: None.
 * Output: A function to move the player up the array.
 *******************************************************/
void Game::move_down() {

	if (player_y < game_map.size()) {
		Event *down = game_map[player_y][player_x].get_event_ptr();
		game_map[player_y + 1][player_x].set_event_ptr(down);
		game_map[player_y][player_x].set_event_ptr(NULL);

		this->player_y = player_y + 1;
	}

	else {
		cout << "Sorry invalid move. The move you attempt to make seem to be out of bound. Please try again." << endl;
		cout << endl;
		print_game_map();
		moving_player();
	}
}

/********************************************************
 * Function: void Game::move_left();
 * Input: None.
 * Output: A function to move the player up the array.
 *******************************************************/
void Game::move_left() {

	if (player_x > 0) {
		Event *left = game_map[player_y][player_x].get_event_ptr();
		game_map[player_y][player_x - 1].set_event_ptr(left);
		game_map[player_y][player_x].set_event_ptr(NULL);

		this->player_x = player_x - 1;
	}

	else {
		cout << "Sorry invalid move. The move you attempt to make seem to be out of bound. Please try again." << endl;
		cout << endl;
		print_game_map();
		moving_player();
	}
}

/********************************************************
 * Function: void Game::move_right();
 * Input: None.
 * Output: A function to move the player up the array.
 *******************************************************/
void Game::move_right() {

	if (player_x < game_map.size()) {
		Event *right = game_map[player_y][player_x].get_event_ptr();
		game_map[player_y][player_x + 1].set_event_ptr(right);
		game_map[player_y][player_x].set_event_ptr(NULL);

		this->player_x = player_x + 1;
	}

	else {
		cout << "Sorry invalid move. The move you attempt to make seem to be out of bound. Please try again." << endl;
		cout << endl;
		print_game_map();
		moving_player();
	}
}

/***********************************************************
 * Function: void Game::fire_up();
 * Input: None.
 * Output: A function to fire arrow the upward in the array.
 **********************************************************/
void Game::fire_up() {

	int tmp_x = 0;
	int tmp_y = 0;

	tmp_x = player_x;
	tmp_y = player_y;

	if (arrow > 0) {
		for (int i = 0; i < 3; i++) {
			if ((tmp_y - 1) >= 0) {
				tmp_y = tmp_y - 1;
			}

			else {
				cout << "\nLook like the arrow have hit a wall" << endl;
				break;
			}

			if (game_map[tmp_y][tmp_x].get_event_ptr() == game_map[wum_y][wum_x].get_event_ptr()) {
				cout << "\nYou kill the Wumpus" << endl;
				is_wumpus = false;
				game_map[wum_y][wum_x].set_event_ptr(NULL);
				wumpus_dead = true;
				break;
			}
		}
		arrow = arrow - 1;
		if (wumpus_dead == false) {
			cout << "\nYou fire an arrow and it didn't hit anything." << endl;
			wake_wumpus();
		}
	}

	else if (arrow == 0) {
		cout << "Sorry you can't fire anymore arrow, try again" << endl;
		cout << endl;
		print_game_map();
		moving_player();
	}
}

/*************************************************************
 * Function: void Game::fire_down();
 * Input: None.
 * Output: A function to fire arrow the downward in the array.
 ************************************************************/
void Game::fire_down() {

	int tmp_x = 0;
	int tmp_y = 0;

	tmp_x = player_x;
	tmp_y = player_y;

	if (arrow > 0) {
		for (int i = 0; i < 3; i++) {
			if ((tmp_y + 1) < game_map.size()) {
				tmp_y = tmp_y + 1;
			}

			else {
				cout << "\nLook like the arrow have hit a wall." << endl;
				break;
			}

			if (game_map[tmp_y][tmp_x].get_event_ptr() == game_map[wum_y][wum_x].get_event_ptr()) {
				cout << "\nYou kill the Wumpus" << endl;
				is_wumpus = false;
				game_map[wum_y][wum_x].set_event_ptr(NULL);
				wumpus_dead = true;
				break;
			}
		}
		arrow = arrow - 1;
		if (wumpus_dead == false) {
			cout << "\nYou fire an arrow and it didn't hit anything." << endl;
			wake_wumpus();
		}
	}

	else if (arrow == 0) {
		cout << "Sorry you can't fire anymore arrow, try again." << endl;
		cout << endl;
		print_game_map();
		moving_player();
	}
}

/*************************************************************
 * Function: void Game::fire_left();
 * Input: None.
 * Output: A function to fire arrow to the left in the array.
 ************************************************************/
void Game::fire_left() {

	int tmp_x = 0;
	int tmp_y = 0;

	tmp_x = player_x;
	tmp_y = player_y;

	if (arrow > 0) {
		for (int i = 0; i < 3; i++) {
			if ((tmp_x - 1) >= 0) {
				tmp_x = tmp_x - 1;
			}

			else {
				cout << "\nLook like the arrow have hit a wall." << endl;
				break;
			}

			if (game_map[tmp_y][tmp_x].get_event_ptr() == game_map[wum_y][wum_x].get_event_ptr()) {
				cout << "\nYou kill the Wumpus, Congratulation!" << endl;
				is_wumpus = false;
				game_map[wum_y][wum_x].set_event_ptr(NULL);
				wumpus_dead = true;
				break;
			}
		}
		arrow = arrow - 1;
		if (wumpus_dead == false) {
			cout << "\nYou fire an arrow and it didn't hit anything." << endl;
			wake_wumpus();
		}
	}

	else if (arrow == 0) {
		cout << "Sorry you can't fire anymore arrow, try again." << endl;
		cout << endl;
		print_game_map();
		moving_player();
	}
}

/*************************************************************
 * Function: void Game::fire_right();
 * Input: None.
 * Output: A function to fire arrow to the right in the array.
 ************************************************************/
void Game::fire_right() {

	int tmp_x = 0;
	int tmp_y = 0;

	tmp_x = player_x;
	tmp_y = player_y;

	if (arrow > 0) {
		for (int i = 0; i < 3; i++) {
			if ((tmp_x + 1) < game_map.size()) {
				tmp_x = tmp_x + 1;
			}

			else {
				cout << "\nLook like the arrow have hit a wall." << endl;
				break;
			}

			if (game_map[tmp_y][tmp_x].get_event_ptr() == game_map[wum_y][wum_x].get_event_ptr()) {
				cout << "\nYou kill the Wumpus, Congratulation!" << endl;
				is_wumpus = false;
				game_map[wum_y][wum_x].set_event_ptr(NULL);
				wumpus_dead = true;
				break;
			}
		}
		arrow = arrow - 1;
		if (wumpus_dead == false) {
			cout << "\nYou fire an arrow and it didn't hit anything." << endl;
			wake_wumpus();
		}
	}

	else if (arrow == 0) {
		cout << "Sorry you can't fire anymore arrow, try again." << endl;
		cout << endl;
		print_game_map();
		moving_player();
	}
}

/************************************************************
 * Function: void Game::check_percepts();
 * Input: None.
 * Output: A function to check percepts of the adjacent room.
 ***********************************************************/
void Game::check_percepts() {

	if (player_y > 0) {
		if (game_map[player_y - 1][player_x].get_event_ptr() != NULL) {
			game_map[player_y - 1][player_x].get_event_ptr()->percept();
		}
	}

	if (player_y < game_map.size() - 1) {
		if (game_map[player_y + 1][player_x].get_event_ptr() != NULL) {
			game_map[player_y + 1][player_x].get_event_ptr()->percept();
		}	
	}

	if (player_x > 0) {
		if (game_map[player_y][player_x - 1].get_event_ptr() != NULL) {
			game_map[player_y][player_x - 1].get_event_ptr()->percept();
		}
	}

	if (player_x < game_map.size() - 1) {
		if (game_map[player_y][player_x + 1].get_event_ptr() != NULL) {
			game_map[player_y][player_x + 1].get_event_ptr()->percept();
		}	
	}
}

/*******************************************************************************
 * Function: void Game::event_encounter();
 * Input: None.
 * Output: A function to make the event happen if player enter the room with it.
 ******************************************************************************/
void Game::event_encounter() {

	if ((game_map[player_y][player_x].get_event_ptr() == game_map[gold_y][gold_x].get_event_ptr()) && is_gold == false) {
		cout << "\nYou found the gold and you automatically pick it up!" << endl;
		cout << "Now time to get out of here!" << endl;
		is_gold = true;
	}

	else if ((game_map[player_y][player_x].get_event_ptr() == game_map[wum_y][wum_x].get_event_ptr()) && wumpus_dead == false) {
		cout << "\nYou walk into the Wumpus. You have now waken it up." << endl;
		cout << "Wumpus eats you after it was disrupted from it sleep." << endl;
		is_wumpus = true;
	}

	else if ((game_map[player_y][player_x].get_event_ptr() == game_map[p1_y][p1_x].get_event_ptr()) && is_pit1 == false) {
		cout << "\nYou have accidently walk into the bottomless pit." << endl;
		cout << "You perish after falling into the pit." << endl;
		is_pit1 = true;
	}

	else if ((game_map[player_y][player_x].get_event_ptr() == game_map[p2_y][p2_x].get_event_ptr()) && is_pit2 == false) {
		cout << "\nYou have accidently walk into the bottomless pit." << endl;
		cout << "You perish after falling into the pit." << endl;
		is_pit2 = true;
	}

	else if (game_map[player_y][player_x].get_event_ptr() == game_map[b1_y][b1_x].get_event_ptr()) {
		bat1_move_player();
	}

	else if (game_map[player_y][player_x].get_event_ptr() == game_map[b2_y][b2_x].get_event_ptr()) {
		bat2_move_player();
	}

	check_game(gameplay);
}
/***********************************************************
 * Function: void Game::bat1_move_player();
 * Input: None.
 * Output: A function to move player if player land on bat1.
 **********************************************************/
void Game::bat1_move_player() {
	
	int x = 0, y = 0;

	x = rand() %game_map.size();
	y = rand() %game_map.size();

	cout << "\nYou walk in on the super bats, they are mad and start carrying you to the different room." << endl;
	game_map[player_y][player_x].set_event_ptr(NULL);

	if (game_map[y][x].get_event_ptr() == NULL) {
		player_x = x;
		player_y = y;
		game_map[player_y][player_x].set_event_ptr(player);
		print_game_map();
		set_bat1_coor(x,y);			
	}

	else if (game_map[y][x].get_event_ptr() == game_map[wum_y][wum_x].get_event_ptr()) {
		set_player_coor(x,y);
	}

	else if (game_map[y][x].get_event_ptr() == game_map[p1_y][p1_x].get_event_ptr()) {
		set_player_coor(x,y);
	}

	else if (game_map[y][x].get_event_ptr() == game_map[p2_y][p2_x].get_event_ptr()) {
		set_player_coor(x,y);
	}

	else if (game_map[y][x].get_event_ptr() == game_map[gold_y][gold_x].get_event_ptr()) {
		set_player_coor(x,y);
		print_game_map();
		set_bat1_coor(x,y);
	}

	else if (game_map[y][x].get_event_ptr() == game_map[b2_y][b2_x].get_event_ptr()) {
		b1_x = x;
		b1_y = y;
		game_map[b1_y][b1_x].set_event_ptr(bat1);

		x = rand() %game_map.size();
		y = rand() %game_map.size();
		set_player_coor(x,y);
		print_game_map();
		set_bat2_coor(x,y);
	}
}

/***********************************************************
 * Function: void Game::bat2_move_player();
 * Input: None.
 * Output: A function to move player if player land on bat2.
 **********************************************************/
void Game::bat2_move_player() {
	
	int x = 0, y = 0;

	x = rand() %game_map.size();
	y = rand() %game_map.size();

	cout << "\nYou walk in on the super bats, they are mad and start carrying you to the different room." << endl;
	game_map[player_y][player_x].set_event_ptr(NULL);

	if (game_map[y][x].get_event_ptr() == NULL) {
		player_x = x;
		player_y = y;
		game_map[player_y][player_x].set_event_ptr(player);
		print_game_map();
		set_bat2_coor(x,y);			
	}

	else if (game_map[y][x].get_event_ptr() == game_map[wum_y][wum_x].get_event_ptr()) {
		set_player_coor(x,y);
	}

	else if (game_map[y][x].get_event_ptr() == game_map[p1_y][p1_x].get_event_ptr()) {
		set_player_coor(x,y);
	}

	else if (game_map[y][x].get_event_ptr() == game_map[p2_y][p2_x].get_event_ptr()) {
		set_player_coor(x,y);
	}

	else if (game_map[y][x].get_event_ptr() == game_map[gold_y][gold_x].get_event_ptr()) {
		set_player_coor(x,y);
		print_game_map();
		set_bat2_coor(x,y);
	}

	else if (game_map[y][x].get_event_ptr() == game_map[b1_y][b1_x].get_event_ptr()) {
		b1_x = x;
		b1_y = y;
		game_map[b2_y][b2_x].set_event_ptr(bat2);

		x = rand() %game_map.size();
		y = rand() %game_map.size();
		set_player_coor(x,y);
		print_game_map();
		set_bat1_coor(x,y);
	}
}

/**********************************************************************
 * Function: void Game::wake_wumpus();
 * Input: None.
 * Output: A function to set wumpus to a new location depend on random.
 *********************************************************************/
void Game::wake_wumpus() {

	int x = 0, y = 0, random = 0;

	random = ((rand() %100) + 1);
	cout << "\nUh Oh... Since you miss, there's a 75% chance that the Wumpus could move to different room" << endl;

	if (random >= 1 || random <= 75) {
		cout << "Look like the Wumpus woke up and decided to move. Relocating... .. ." << endl;
		x = rand() %game_map.size();
		y = rand() %game_map.size();

		while (game_map[y][x].get_event_ptr() != NULL) {
			x = rand() %game_map.size();
			y = rand() %game_map.size();
		}
			
		game_map[wum_y][wum_x].set_event_ptr(NULL);
		wum_x = x;
		wum_y = y;
		game_map[wum_y][wum_x].set_event_ptr(wumpus);
	}

	else if (random >= 76 || random <= 100) {
		cout << "Your in luck, look like the Wumpus didn't wake up and stay in it original position." << endl;
	}
}

/****************************************************************
 * Function: void Game::set_player_coor(int, int);
 * Input: None.
 * Output: A function to set player new location and check event.
 ***************************************************************/
void Game::set_player_coor(int x, int y) {

	player_x = x;
	player_y = y;
	game_map[player_y][player_x].set_event_ptr(player);
	event_encounter();
}

/****************************************************************
 * Function: void Game::set_bat1_coor(int, int);
 * Input: None.
 * Output: A function to set bat1 new location.
 ***************************************************************/
void Game::set_bat1_coor(int x, int y) {
	
	b1_x = x;
	b1_y = y;

	while ((game_map[b1_y][b1_x].get_event_ptr() != NULL) && gameplay == true) {
		moving_player();
	}
	game_map[b1_y][b1_x].set_event_ptr(bat1);
}

/****************************************************************
 * Function: void Game::set_bat2_coor(int, int);
 * Input: None.
 * Output: A function to set bat1 new location.
 ***************************************************************/
void Game::set_bat2_coor(int x, int y) {
	
	b2_x = x;
	b2_y = y;

	while ((game_map[b2_y][b2_x].get_event_ptr() != NULL) && gameplay == true) {
		moving_player();
	}
	game_map[b2_y][b2_x].set_event_ptr(bat2);
}

/******************************************
 * Function: void Game::print_game_map();
 * Input: None.
 * Output: A function to print out the map.
 *****************************************/
void Game::print_game_map() {

	if (board_games == true) {
		print_board_true();
	}	
		
	else if (board_games == false) {
		print_board_false();
	}
}

/*******************************************************************************
 * Function: void Game::check_game(bool &);
 * Input: None.
 * Output: A function to see if the player have won or lose the game.
 ******************************************************************************/
void Game::check_game(bool &check_it) {

	if (is_gold == true && (game_map[player_y][player_x].get_event_ptr() == game_map[start_y][start_x].get_event_ptr())) {
		cout << endl;
		print_game_map();
		cout << "\nCONGRATULATION!!!" << endl;
		cout << "You Won the Game." << endl;
		cout << "Thank you for playing." << endl;
		check_it = false;
		cout << endl;
	}

	else if (is_wumpus == true) {
		cout << endl;
		print_game_map();
		cout << "\nGAME OVER!!!" << endl;
		cout << "You Lose." << endl;
		cout << "Thank you for playing." << endl;
		check_it = false;
		cout << endl;
	}

	else if (is_pit1 == true) {
		cout << endl;
		print_game_map();
		cout << "\nGAME OVER!!!" << endl;
		cout << "You Lose." << endl;
		cout << "Thank you for playing." << endl;
		check_it = false;
		cout << endl;
	}

	else if (is_pit2 == true) {
		cout << endl;
		print_game_map();
		cout << "\nGAME OVER!!!" << endl;
		cout << "You Lose." << endl;
		cout << "Thank you for playing." << endl;
		check_it = false;
		cout << endl;
	}

	else {

	}
}

/********************************************************
 * Function: void Game::intro_message();
 * Input: None.
 * Output: Display the game introduction message.
 *******************************************************/
void Game::intro_message() {

	cout << endl;
	cout << "Welcome to the Hunt the Wumpus game!" << endl;
	cout << "A map have been randomize for you based on your grid size input." << endl;
	cout << "----------------------------------------------------------------" << endl;
	cout << endl;
	cout << "Game loading... .. . Enjoy!" << endl;
	cout << endl;
}

/********************************************************
 * Function: void Game::player_info();
 * Input: None.
 * Output: Display the user number of arrow left.
 *******************************************************/
void Game::player_info() {

	cout << "\n_____________" << endl;
	cout << "Player's Info" << endl;
	cout << "-------------" << endl;
	cout << "Player's Arrow: " << arrow << endl;
	cout << endl;
}
