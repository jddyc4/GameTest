/*
 * deck.h
 *
 *  Created on: May 22, 2018
 *      Author: Nicholas
 */

#ifndef DECK_H_
#define DECK_H_

#include <iostream>
#include <cstdlib>
#include <time.h>
#include "card.h"

using namespace std;

class deck
{
	public:
		card* Deck;
		int size;

		deck();
		virtual ~deck();

		void createDeck();
		void writeDeck();
		void shuffleDeck();
		void deleteDeck() {delete Deck;};

};


//Function definitions --------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------

deck::deck()
{
	Deck = NULL;
	size = 0;
}

deck::~deck()
{
	delete Deck;
}

void deck::createDeck()
{
	size = 52;
	Deck = new card[size];

	for (int i=0; i < size; i++)
	{
		Deck[i].setSuit(i % 4);
		Deck[i].setValue((i % 13)+1);
	}

	return;
}

void deck::writeDeck()
{
	for (int i = 0; i < size; i++)
	{
		cout << "Suit: " << Deck[i].getSuit() << " Value: " << Deck[i].getValue();
		cout << endl;
	}
	return;
}

void deck::shuffleDeck()
{
	srand(time(NULL));
	card temp[52];
	int order[52];
	int used[52];
	int counter = 0;
	int randNum = 0;

	while (counter < 52)
	{
		randNum = rand() % 52;
		if (used[randNum] != 1)
		{
			used[randNum] = 1;
			order[counter] = randNum;
			counter++;
		}
	}

	for (int i = 0; i < 52; i++)
	{
		temp[i] = Deck[order[i]];
	}

	for (int i = 0; i < 52; i++)
	{
		Deck[i] = temp[i];
	}

	return;
}


#endif /* DECK_H_ */
