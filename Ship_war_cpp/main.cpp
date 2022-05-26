#include<iostream>
#include<random>
#include<ctime>
#include<cmath>
#include<string>
#include"ship_war.h"
#include"game_field.h"
using namespace std;
using namespace ship_war;

string getRidOfExcess(string a) {
	string b = "";
	for (auto& i : a) {
		if ((int(i) > 47 && int(i) < 58) ||
			(int(i) > 64 && int(i) < 75) ||
			(int(i) > 96 && int(i) < 107)) {
			if (int(i) > 96 && int(i) < 107) {
				b += char(int(i) - 32);
			}
			else {
				b += i;
			}
		}
	}
	return b;
}

bool correctInputPlayer(string a) {
	if (a.size() < 4 && a.size() > 1) {
		if ((a.size() == 3 && !isdigit(a[0]) && a[1] == '1' && a[2] == '0') ||
			(a.size() == 2 && !isdigit(a[0]) && isdigit(a[1]) && a[1] != '0')) {
			return true;
		}
	}
	return false;
}

int main() {
	setlocale(0, "rus");
	Point point;
	string a;

	do {
		getline(cin, a);
		a = getRidOfExcess(a);
		cout << a << endl;
		if (correctInputPlayer(a)) {
			point.x = int(a[0]) - 64;
			point.y = (a[1] == '1' && a[2] == '0') ? 10 : int(a[1]) - 48;
			break;
		}
		else {
			cout << "¬ведите значение заново." << endl;
		}
	} while (!correctInputPlayer(a));

	
	return 0;
}