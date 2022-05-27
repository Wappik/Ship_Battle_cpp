#pragma once
#include"ship_war.h"
#include"player.h"
#include"computer.h"
#include"game_field.h"

class Game {
private:

	Player player;
	Computer computer;
	Game_field field;
	int ship_cell;
	int max_ship_size;
	bool is_player;
	bool is_game_over;
	bool is_got;
	bool is_was;

public:

	Game() {
		
	}

	Game(int max_ship_size) {

	}


};



