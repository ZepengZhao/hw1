#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "cards.h"
using namespace std;

int main() {
	Player player(100);
	Player dealer(900);
	double bet_money;
	cout << endl;
	Card deal_card;
	char ans;
	cout << "You have $" << player.get_money() << ".";
	cout << "Enter bet:";
	cin >> bet_money;
	cout << endl;
	while (player.get_money() > 0 && dealer.get_money() > 0)
	{	
		
		Hand player_cards;
		while (true)
		{

			Card new_card;
			cout << "New card:" << endl;
			cout << new_card.get_spanish_rank() << " de " << new_card.get_spanish_suit();
			cout << "(" << new_card.get_english_rank() << " of " << new_card.get_english_suit() << ").";
			player.get_hand().save_card(new_card);
			player.get_hand().hand_total(new_card);
			cout << endl;
			cout << "Your cards:" << endl;
			for (int i = 0; i < player.get_hand().get_cards().size(); i++)
			{
				cout << player.get_hand().get_cards()[i].get_spanish_rank()
					<< " de " << player.get_hand().get_cards()[i].get_spanish_suit();
				cout << "(" << player.get_hand().get_cards()[i].get_english_rank()
					<< " of " << player.get_hand().get_cards()[i].get_english_suit() << ").";
				cout << endl;
			}
			cout << endl;
			cout << "Your total is " << player.get_hand().get_total() << ".";
			if (player.get_hand().get_total() > 7.5)
				break;
			cout << "Do you want another card(y/n)?";
			cin >> ans;
			if (ans == 'n')
				break;
			
		}
		Hand dealer_cards;
		while (player.get_hand().get_total() <= 7.5&&dealer_cards.get_total() < 5.5)
		{
			Card new_card;
			cout << "New card:" << endl;
			cout << new_card.get_spanish_rank() << " de " << new_card.get_spanish_suit();
			cout << "(" << new_card.get_english_rank() << " of " << new_card.get_english_suit() << ").";
			dealer_cards.save_card(new_card);
			dealer_cards.hand_total(new_card);
			cout << endl;
			cout << "Dealer's cards:" << endl;
			for (int i = 0; i < dealer_cards.get_cards().size(); i++)
			{
				cout << dealer_cards.get_cards()[i].get_spanish_rank()
					<< " de " << dealer_cards.get_cards()[i].get_spanish_suit();
				cout << "(" << dealer_cards.get_cards()[i].get_english_rank()
					<< " of " << dealer_cards.get_cards()[i].get_english_suit() << ").";
				cout << endl;
			}
			cout << endl;
			cout << "The dealer's total is " << dealer_cards.get_total() << ".";
			cout << endl;
		}
		player.current_amount(dealer_cards, bet_money);
		cout << endl;
	}
	return 0;

}
