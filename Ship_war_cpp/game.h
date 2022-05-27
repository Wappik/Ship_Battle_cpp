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
		this->is_player = true;
		this->is_game_over = false;
		this->is_got = false;
		this->is_was = false;
	}

	Game(int max_ship_size) {
		setMaxShipSize(max_ship_size);
		this->player.setPlayer(this->max_ship_size);
		this->computer.setComputer(this->max_ship_size);
		this->is_player = true;
		this->is_game_over = false;
		this->is_got = false;
		this->is_was = false;
	}

	void setMaxShipSize(int max_ship_size) {
		this->max_ship_size = (max_ship_size != 0) ? abs(max_ship_size) : 4;
	}

	void startGame() {
		Ship_war_field field_player = player.getField();
		
		for (int i = 2; i < 12; i++) {
			for (int j = 3; j < 13; j++) {
				field.field_main[i][j] = field_player.field_main[i][j];
			}
		}
		/*
		Ship_war_field field_computer = computer.getField();

		for (int i = 2; i < 13; i++) {
			for (int j = 3; j < 14; j++) {
				field.field_main[i][j + 11] = field_computer.field_main[i][j];
			}
		}
		*/
	}


	bool endGame(Ship_war_field field_computer) {
		ship_cell = 0;
		if (is_player) {
			for (int i = 2; i < 12; i++) {
				for (int j = 3; j < 13; j++) {
					if (field.field_main[i][j] == '#') {
						ship_cell++;
					}
				}
			}
			if (ship_cell < 1) {
				return true;
			}
			else {
				return false;
			}
		}
		else {
			for (int i = 2; i < 12; i++) {
				for (int j = 3; j < 13; j++) {
					if (field_computer.field_main[i][j] == '#') {
						ship_cell++;
					}
				}
			}
			if (ship_cell < 1) {
				return true;
			}
			else {
				return false;
			}
		}
	}

	void playGame() {
		startGame();
		Point coords;
		Ship_war_field field_computer = computer.getField();
		while (!endGame(field_computer)) {
			if (is_player) {
				do {
					system("cls");
					field.print();
					coords = player.inputPlayer();
					if (field_computer.field_main[coords.x][coords.y - 11] == '#') {
						is_got = true;
						is_was = false;

						field_computer.field_main[coords.x][coords.y - 11] = 'X';
						field.field_main[coords.x][coords.y] = '+';

					}
					else if (field_computer.field_main[coords.x][coords.y - 11] == '+' ||
							 field_computer.field_main[coords.x][coords.y - 11] == 'X') {
						is_got = false;
						is_was = true;
					}
					else {
						is_got = false;
						is_was = false;

						field_computer.field_main[coords.x][coords.y - 11] = 'X';
						field.field_main[coords.x][coords.y] = 'X';
					}
					system("cls");
					field.print();
				} while (is_got || is_was);
				if (endGame(field_computer)) {
					cout << "Victory" << endl;
					break;
				}
				is_player = false;
			}
			else {
				do {
					coords = computer.creatingShot();
					if (field.field_main[coords.x][coords.y] == '#') {
						is_got = true;
						is_was = false;

						field.field_main[coords.x][coords.y] = '+';
					}
					else if (field.field_main[coords.x][coords.y] == '+' ||
							 field.field_main[coords.x][coords.y] == 'X') {
						is_got = false;
						is_was = true;
					}
					else {
						is_got = false;
						is_was = false;

						field.field_main[coords.x][coords.y] = 'X';
					}
				} while (is_got || is_was);
				if (endGame(field_computer)) {
					cout << "Loss" << endl;
					break;
				}
				is_player = true;
			}
		}
	}

};



