/*
 * card.h
 *
 *  Created on: May 22, 2018
 *      Author: Nicholas
 */

#ifndef CARD_H_
#define CARD_H_

#include <string>
using namespace std;

enum suit
{
	hearts,
	clubs,
	diamonds,
	spades,
	empty
};

class card
{
	public:
		suit Suit;
		int value;
		string display;


		card();
		virtual ~card();

		void setSuit(suit suitValue) {Suit = suitValue;};
		void setSuit(int suitValue);
		void setValue(int cardValue) {value = cardValue;};

		suit getSuit() {return Suit;};
		int getValue() {return value;};

};


//Function definitions -------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------

card::card()
{
	Suit = empty;
	value = 0;
	display = NULL;

}

card::~card()
{
	// TODO Auto-generated destructor stub
}

void card::setSuit(int suitValue)
{
	if (suitValue == 0)
	{
		Suit = hearts;
	}
	else if (suitValue == 1)
	{
		Suit = clubs;
	}
	else if (suitValue == 2)
	{
		Suit = diamonds;
	}
	else if (suitValue == 3)
	{
		Suit = spades;
	}
	return;
}

#endif /* CARD_H_ */
