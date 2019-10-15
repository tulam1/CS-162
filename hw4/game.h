/******************************************************************************************
 * Program: game.h
 * Author: Tu Lam
 * Date: 05/16/2019
 * Description: The header file to implement class into the program.
 * Input: None.
 * Output: None.
 *****************************************************************************************/
 
#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <string>
#include <vector>
#include "room.h"
#include "event.h"

using namespace std;

class Game {

	private:
		vector < vector<Room> > game_map;
    	Event *bat1;
    	Event *bat2;
    	Event *pit1;
    	Event *pit2;
  		Event *wumpus;
    	Event *gold;
    	Event *player;
    	int start_x;
    	int start_y;
    	int arrow;
    	int player_x;
    	int player_y;
		int gold_x;
		int gold_y;
		int wum_x;
		int wum_y;
		int p1_x, p2_x;
		int p1_y, p2_y;
		int b1_x, b2_x;
		int b1_y, b2_y;
		bool is_gold;
		bool is_wumpus;
		bool is_pit1, is_pit2;
		bool board_games;
		bool gameplay;
		bool wumpus_dead;

	public:

   	//All of the Big 3 & Constructor
    	Game(); //Default Constructor
    	~Game(); //Destructor

		//All other functions
		void main_game(int, string);
		void set_room(int);
		void set_percept_bats();
		void set_percept_pits();
		void set_percept_wumpus();
		void set_percept_gold();
		void set_percept_player();
		void print_board_true();
		void print_board_false();
    	void moving_player();
    	void move_up();
		void move_down();
		void move_left();
		void move_right();
    	void fire_up();
		void fire_down();
		void fire_left();
		void fire_right();
    	void check_percepts();
		void event_encounter();
		void bat1_move_player();
		void bat2_move_player();
		void check_game(bool &);
		void wake_wumpus();
		void set_player_coor(int, int);
		void set_bat1_coor(int, int);
		void set_bat2_coor(int, int);
		void print_game_map();
		void intro_message();
		void player_info();
		void set_all_percepts(int);
};

#endif
