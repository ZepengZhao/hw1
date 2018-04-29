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
	Card deal_card;
	char ans;
	while (player.get_money() > 0 && dealer.get_money() > 0)
	{	
		cout << "You have $" << player.get_money() << ".";
		cout << "Enter bet:";
		cin >> bet_money;
		Hand player_cards;
		while (true)
		{
			Card new_card;
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
			
		}
		Hand dealer_cards;
		while (player_cards.get_total() <= 7.5&&dealer_cards.get_total() < 5.5)
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
		
		if (player_cards.compare(dealer_cards) > 0)
		{
			cout << "You win " << bet_money;
			player.set_money(player.get_money() + bet_money);
			dealer.set_money(player.get_money() - bet_money);
		}
		else if (player_cards.compare(dealer_cards) == 0)
		{
			cout << "Draw";
		}
		else
		{	
			cout << "You lose " << bet_money;
			player.set_money(player.get_money() - bet_money);
			dealer.set_money(player.get_money() + bet_money);
		}

		cout << endl;
	}
	return 0;

}
