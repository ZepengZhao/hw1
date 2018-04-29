/* *************************************
Ricardo Salazar, February 26, 2015

Interface of a simple Card class
************************************* */

#include <string>
#include <vector>
#include <fstream>

#ifndef CARDS_H
#define CARDS_H

using namespace std;

enum suit_t { OROS, COPAS, ESPADAS, BASTOS };

enum rank_t { AS, DOS, TRES, CUATRO, CINCO, SEIS, SIETE, SOTA = 9, CABALLO = 10, REY = 11 };

class Card {
public:
	
	Card();
	string get_spanish_suit() const;
	string get_spanish_rank() const;

	string get_english_suit() const;
	string get_english_rank() const;

	int get_rank() const;
	bool operator < (Card card2) const;

private:
	suit_t suit;
	rank_t rank;
};


class Hand {
public:
	void save_card(Card new_card);
	void hand_total(Card card);
	Hand();
	vector<Card> get_cards();
	double get_total();
	void set_total(double new_total);

private:
	std::vector<Card> cards;
	double total;
};


class Player {
public:
	
	Player(int m);
	void current_amount(Hand dealer, double bet);
	int get_money();
	Hand get_hand();
	void set_hand(vector<Card> new_cards,double total)
	{
		a_hand.get_cards() = new_cards;
		a_hand.get_total() = total;
	}
	
private:
	double money;
	Hand a_hand;
};

#endif
