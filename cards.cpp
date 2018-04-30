#include "cards.h"
#include <cstdlib>
#include <iostream>


Card::Card() {
	int r = 1 + rand() % 4;
	switch (r) {
	case 1: suit = OROS; break;
	case 2: suit = COPAS; break;
	case 3: suit = ESPADAS; break;
	case 4: suit = BASTOS; break;
	default: break;
	}

	r = 1 + rand() % 10;
	switch (r) {
	case  1: rank = AS; break;
	case  2: rank = DOS; break;
	case  3: rank = TRES; break;
	case  4: rank = CUATRO; break;
	case  5: rank = CINCO; break;
	case  6: rank = SEIS; break;
	case  7: rank = SIETE; break;
	case  8: rank = SOTA; break;
	case  9: rank = CABALLO; break;
	case 10: rank = REY; break;
	default: break;
	}
}

string Card::get_spanish_suit() const {
	string suitName;
	switch (suit) {
	case OROS:
		suitName = "oros";
		break;
	case COPAS:
		suitName = "copas";
		break;
	case ESPADAS:
		suitName = "espadas";
		break;
	case BASTOS:
		suitName = "bastos";
		break;
	default: break;
	}
	return suitName;
}


string Card::get_spanish_rank() const {
	string rankName;
	switch (rank) {
	case AS:
		rankName = "As";
		break;
	case DOS:
		rankName = "Dos";
		break;
	case TRES:
		rankName = "Tres";
		break;
	case CUATRO:
		rankName = "Cuatro";
		break;
	case CINCO:
		rankName = "Cinco";
		break;
	case SEIS:
		rankName = "Seis";
		break;
	case SIETE:
		rankName = "Siete";
		break;
	case SOTA:
		rankName = "Sota";
		break;
	case CABALLO:
		rankName = "Caballo";
		break;
	case REY:
		rankName = "Rey";
		break;
	default: break;
	}
	return rankName;
}


string Card::get_english_suit() const {
	string suitName;
	switch (suit) {
	case OROS:
		suitName = "coins";
		break;
	case COPAS:
		suitName = "cups";
		break;
	case ESPADAS:
		suitName = "spades";
		break;
	case BASTOS:
		suitName = "sword";
		break;
	default: break;
	}
	return suitName;
}

string Card::get_english_rank() const {
	string rankName;
	switch (rank) {
	case AS:
		rankName = "Ace";
		break;
	case DOS:
		rankName = "Two";
		break;
	case TRES:
		rankName = "Three";
		break;
	case CUATRO:
		rankName = "Four";
		break;
	case CINCO:
		rankName = "Five";
		break;
	case SEIS:
		rankName = "Six";
		break;
	case SIETE:
		rankName = "Seven";
		break;
	case SOTA:
		rankName = "Jack";
		break;
	case CABALLO:
		rankName = "Knight";
		break;
	case REY:
		rankName = "King";
		break;
	default: break;
	}
	return rankName;
}



int Card::get_rank() const {
	return static_cast<int>(rank) + 1;
}


bool Card::operator < (Card card2) const {
	return rank < card2.rank;
}

Hand::Hand()
{
	total = 0;
}

void Hand::save_card(Card new_card)
{
	cards.push_back(new_card);
}

void Hand::hand_total(Card card)
{
	if (1 <= card.get_rank() && card.get_rank() <= 7)
		total += card.get_rank();
	if (10 <= card.get_rank() && card.get_rank() <= 12)
		total += 0.5;
}

vector<Card> Hand::get_cards()
{
	return cards;
}

double Hand::get_total()
{
	return total;
}

Player::Player(int m)
{
	money = m;
}

int Hand::compare(Hand hand2)
{
	if (total >7.5)
	{
		return -1;

	}
	else if (total = 7.5&&hand2.get_total() <= 7.5&&hand2.get_total() > total)
	{
		return -1;
	}
	else if (hand2.get_total() <= 7.5&&hand2.get_total() <= 7.5&&hand2.get_total() == total)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

void Hand::set_total(double new_total)
{
	total = new_total;
}


int Player::get_money()
{
	return money;
}