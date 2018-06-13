/*
 * main.cpp
 *
 *  Created on: May 22, 2018
 *      Author: Nicholas
 */
#include <iostream>
#include "card.h"
#include "deck.h"
using namespace std;

int main()
{

	deck deckOfCards;
	deckOfCards.createDeck();
	deckOfCards.writeDeck();

	cout << endl << endl << "Shuffle: " << endl << endl;

	deckOfCards.shuffleDeck();
	deckOfCards.writeDeck();

	return 0;
}


