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

	Hand player_cards;
	while (true)
	{

		Card new_card;
		//Hand player_cards;
		cout << "New card:" << endl;
		cout << new_card.get_spanish_rank() << " de " << new_card.get_spanish_suit();
		cout << "(" << new_card.get_english_rank() << " of " << new_card.get_english_suit() << ").";
		player_cards.save_card(new_card);
		player_cards.hand_total(new_card);
		cout << endl;
		cout << "Your cards:" << endl;
		for (int i = 0; i < player_cards.get_cards().size(); i++)
		{
			cout << player_cards.get_cards()[i].get_spanish_rank()
				<< " de " << player_cards.get_cards()[i].get_spanish_suit();
			cout << "(" << player_cards.get_cards()[i].get_english_rank()
				<< " of " << player_cards.get_cards()[i].get_english_suit() << ").";
			cout << endl;
		}
		cout << endl;
		cout << "Your total is " << player_cards.get_total() << ".";
		if (player_cards.get_total() > 7.5)
			break;
		cout << "Do you want another card(y/n)?";
		cin >> ans;
		if (ans == 'n')
			break;
		//cout << "New card:";
		//cout << new_card.get_spanish_rank() << " de " << new_card.get_spanish_suit();
		//cout << "(" << new_card.get_spanish_rank() << " of " << new_card.get_spanish_suit() << ").";
	}
	Hand dealer_cards;


	return 0;

}
