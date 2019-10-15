/*****************************************************************************************************************************
 * Program: hunt_wumpus.cpp
 * Author: Tu Lam
 * Date: 05/16/2019
 * Description: The game where user trying to navigate the map and use best judgment to fetch the gold and return back safely.
 * Input: User input their size for the board games and the control movement to navigate through the room.
 * Output: Given the user hint, and user try the bet to navigate the room and find the gold and exit.
 ****************************************************************************************************************************/

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <vector>
#include "game.h"

using namespace std;

int main(int argc, char* argv[]) {

	int grid = 0;
	string check;
	Game g;
	srand(time(NULL));

	try {
		grid = atoi(argv[1]);
		check = (argv[2]);

		if (grid < 4) {
			throw grid;
		}

		cout << "_______________" << endl;
		cout << "Hunt the Wumpus" << endl;
		cout << "---------------" << endl;
		g.main_game(grid, check);

	} catch (int grid_check) {
		cout << "\nSORRY! Error." << endl;
		cout << "The grid size you give needs to be larger than 4, program will quit now.. ." << endl;
		cout << "Your grid size is: " << grid_check << endl;
		cout << endl;
		exit(1);
		}

return 0;
}
