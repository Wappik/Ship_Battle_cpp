#pragma once
#include"ship_war.h"
#include"player.h"
#include"computer.h"
#include"game_field.h"
using namespace ship_war;

class Game {
private:
	Player player;
	Computer computer;
	Game_field field;
	int ship_cell;
	bool is_player;
	bool is_game_over;
	bool is_got;
	bool is_was;
public:
};



