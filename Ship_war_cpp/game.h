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
		setMaxShipSize(4);
		this->player.setPlayer(max_ship_size);
		this->computer.setComputer(max_ship_size);
	}

	Game(int max_ship_size) {
		setMaxShipSize(max_ship_size);
		this->player.setPlayer(this->max_ship_size);
		this->computer.setComputer(this->max_ship_size);
	}

	void setMaxShipSize(int max_ship_size) {
		this->max_ship_size = (max_ship_size != 0) ? abs(max_ship_size) : 4;
	}


};



