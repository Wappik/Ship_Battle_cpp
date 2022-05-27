#pragma once
#include<iostream>
#include<random>
#include<ctime>
#include<cmath>
using namespace std;

class Ship_war_field {
private:

	const int lines = 13;
	const int columns = 14;
	char field_copy[13][14] = { {' ', ' ', '|', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', '|'},
								{'-', '-', '+', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '+'},
								{'1', ' ', '|', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '|'},
								{'2', ' ', '|', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '|'},
								{'3', ' ', '|', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '|'},
								{'4', ' ', '|', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '|'},
								{'5', ' ', '|', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '|'},
								{'6', ' ', '|', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '|'},
								{'7', ' ', '|', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '|'},
								{'8', ' ', '|', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '|'},
								{'9', ' ', '|', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '|'},
								{'1', '0', '|', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '|'},
								{'-', '-', '+', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '+'},
	};

public:

	char field_main[13][14];

	Ship_war_field() {
		clean();
	}

	void clean() {
		for (int i = 0; i < lines; i++) {
			for (int j = 0; j < columns; j++) {
				field_main[i][j] = field_copy[i][j];
			}
		}
	}

	void print() {
		for (int i = 0; i < lines; i++) {
			for (int j = 0; j < columns; j++) {
				cout << field_main[i][j] << ' ';
			}
			cout << endl;
		}
	}
};

struct Point {
	int x;
	int y;
};

class Ship {

private:
	int size;
	int count;
	bool side;

public:

	Ship() {
		setSize(1);
		setCount(5);
	}

	Ship(int size, int count) {
		setSize(size);
		setCount(count);
	}

	void setSize(int size) {
		this->size = (size != 0) ? abs(size) : 1;
	}

	void setCount(int count) {
		this->count = (count != 0) ? abs(count) : 1;
	}

	void arrange(Ship_war_field& field) {
		Point coord;
		bool Check_side = true;
		int time_start = int(time(0));
		int end_time = 1;
		srand(int(time(0)));
		for (int i = 0; i < count; i++) {
			do {
				side = ((rand() % 2) != 0) ? true : false;
				coord.x = rand() % 10 + 2;
				coord.y = rand() % 10 + 3;
				Point check_coord = coord;
				if (side) {
					for (int j = 0; j <= size; j++) {
						if (!checkBorders(check_coord, field) ||
							!((int(coord.x) + size - 1) < 12)) {
							Check_side = true;
							break;
						}
						else {
							Check_side = false;
						}
						check_coord.x += 1;
					}
				}
				else {
					for (int j = 0; j <= size; j++) {
						if (!checkBorders(check_coord, field) ||
							!((int(coord.y) + size - 1) < 13)) {
							Check_side = true;
							break;
						}
						else {
							Check_side = false;
						}
						check_coord.y += 1;
					}
				}

				if ((time(0) - time_start) > end_time) {
					break;
				}
			} while (Check_side);

			if (side) {
				for (int j = 0; j < size; j++) {
					field.field_main[coord.x][coord.y] = '#';
					coord.x += 1;
				}
			}
			else {
				for (int j = 0; j < size; j++) {
					field.field_main[coord.x][coord.y] = '#';
					coord.y += 1;
				}
			}
		}
	}

	bool checkBorders(Point point, Ship_war_field field) {
		if (field.field_main[point.x][point.y] != '#' &&
			field.field_main[point.x + 1][point.y] != '#' &&
			field.field_main[point.x][point.y + 1] != '#' &&
			field.field_main[point.x + 1][point.y + 1] != '#' &&
			field.field_main[point.x - 1][point.y] != '#' &&
			field.field_main[point.x][point.y - 1] != '#' &&
			field.field_main[point.x - 1][point.y - 1] != '#' &&
			field.field_main[point.x - 1][point.y + 1] != '#' &&
			field.field_main[point.x + 1][point.y - 1] != '#'
			) return true;
		return false;
	}
};
