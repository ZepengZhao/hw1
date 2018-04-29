#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "cards.h"
using namespace std;

// Global constants (if any)


// Non member functions declarations (if any)


// Non member functions implementations (if any)


// Stub for main
int main() {
	Player player(100);
	Player dealer(900);
	double bet_money;

	Card deal_card;
	char ans;
	cout << "You have $" << player.get_money() << ".";
	cout << "Enter bet:";
	cin >> bet_money;
	cout << endl;
	return 0;
}
