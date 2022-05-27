#pragma once
#include<iostream>
#include<string>
#include<cmath>
#include"ship_war.h"
using namespace std;


class Player {
private:

	string input_player;
	Point input_player_coords;
	Ship_war_field field;
	int max_ship_size;
	Ship* s;

	void generationShips() {
		for (int i = 0; i < this->max_ship_size; i++) {
			s[i].setSize(i + 1);
			s[i].setCount(this->max_ship_size - i);
		}
	}

	void placementShip() {
		int time_start = int(time(0));
		int end_time = 1;
		for (int i = this->max_ship_size - 1; i >= 0; i--) {
			s[i].arrange(this->field);
		}
		if ((int(time(0)) - time_start) > end_time) {
			this->field.clean();
			placementShip();
		}
	}

	string getRidOfExcess() {
		string b = "";
		for (auto& i : input_player) {
			if ((int(i) > 47 && int(i) < 58) ||
				(int(i) > 64 && int(i) < 75) ||
				(int(i) > 96 && int(i) < 107)) {
				b += i;
			}
		}
		return b;
	}

	bool correctInputPlayer() {
		if (input_player.size() < 4 && input_player.size() > 1) {
			if ((input_player.size() == 3 && !isdigit(input_player[0]) && 
				input_player[1] == '1' && input_player[2] == '0') ||
				(input_player.size() == 2 && !isdigit(input_player[0]) && 
				isdigit(input_player[1]) && input_player[1] != '0')) {
				return true;
			}
		}
		return false;
	}

public:

	Player() {
		setMaxShipSize(4);
		this->s = new Ship[this->max_ship_size];
		generationShips();
		placementShip();
	}

	Player(int max_ship_size) {
		setMaxShipSize(max_ship_size);
		this->s = new Ship[this->max_ship_size];
		generationShips();
		placementShip();
	}

	void setPlayer(int max_ship_size) {
		setMaxShipSize(max_ship_size);
		this->s = new Ship[this->max_ship_size];
		generationShips();
		placementShip();
	}

	void setMaxShipSize(int max_ship_size) {
		this->max_ship_size = (max_ship_size != 0) ? abs(max_ship_size) : 4;
	}

	Point getInputPlayerCoords() {
		return input_player_coords;
	}

	Ship_war_field getField() {
		return field;
	}

	Point inputPlayer() {
		do {
			cout << "You: ";
			getline(cin, input_player);
			input_player = getRidOfExcess();
			if (correctInputPlayer()) {
				cout << input_player << endl;
				//input_player_coords.x = int(input_player[0]) - 64 + 13;
				input_player_coords.y = int(input_player[0]) - ((int(input_player[0]) > 64 && int(input_player[0]) < 75) ? 64 : 96) + 13;
				input_player_coords.x = ((input_player[1] == '1' && input_player[2] == '0') ? 10 : int(input_player[1]) - 48) + 1;
				break;
			}
			else {
				cout << "Try again." << endl;
			}
		} while (!correctInputPlayer());
		return input_player_coords;
	}
};
