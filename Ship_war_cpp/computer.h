#pragma once
#include"ship_war.h"

class Computer {
private:

	Point computer_coords;
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

public:

	Computer() {
		setMaxShipSize(4);
		this->s = new Ship[this->max_ship_size];
		generationShips();
		placementShip();
	}

	Computer(int max_ship_size) {
		setMaxShipSize(max_ship_size);
		this->s = new Ship[this->max_ship_size];
		generationShips();
		placementShip();
	}

	void setComputer(int max_ship_size) {
		setMaxShipSize(max_ship_size);
		this->s = new Ship[this->max_ship_size];
		generationShips();
		placementShip();
	}

	void setMaxShipSize(int max_ship_size) {
		this->max_ship_size = (max_ship_size != 0) ? abs(max_ship_size) : 4;
	}

	Point getComputerCoords() {
		return computer_coords;
	}

	Point creatingShot() {
		computer_coords.x = rand() % 10 + 2;
		computer_coords.y = rand() % 10 + 3;
		return computer_coords;
	}

};
