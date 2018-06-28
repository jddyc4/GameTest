//-----------------------------------------------------
// Card Game Program Attempt
// Date: 1/18/18
//-----------------------------------------------------


#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>

using namespace std;

struct card {
  string num;
  string suit;
};

struct person {
  card hand[2];
  int cash;
  string name;
};

void createDeck(vector<card>& array);

void shuffleDeck(vector<card>& array);

void dealCards(vector<card>& array, vector<person>& everybody);

int main()
{
   srand( time( NULL ) );
   vector<card> deck;
   int numPeople = 0;
   vector<person> players;

   card test;
   
   createDeck(deck);
   
   shuffleDeck(deck);
   shuffleDeck(deck);
   shuffleDeck(deck);
   
   dealCards(deck, players);
   
   for (int i = 0; i<players.size();i++)
     {
       cout << players[i].name << " has the cards " << players[i].hand[0].num << " of ";
       cout << players[i].hand[0].suit << " and " << players[i].hand[1].num;
       cout << " of " << players[i].hand[1].suit << "." << endl;
     }
   // for (int i = 0;i<deck.size();i++)
   //     cout << deck[i].num << " of " << deck[i].suit << endl;
  return(0);
}

//----------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------

void createDeck(vector<card>& array)
{
  string eachCard[13] = {"2","3","4","5","6","7","8","9","10","Jack",
			 "Queen","King","Ace"};
  string suits[4] = {"Hearts","Diamonds","Spades","Clubs"};
  int count = 0;
  card temp;
  temp.num = "0";
  temp.suit = "empty";
  for (int i = 0;i<52;i++)
    {
      temp.num = eachCard[i % 13];
      temp.suit = suits[count];
      if (eachCard[i%13] == "Ace")
	 count++;
      array.insert(array.begin() + i, temp);
    }
}

//----------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------

void shuffleDeck(vector<card>& array)
{
  vector<card> temp(52);
  card cardAdd;
  int randIndex;
  int count = 1;
  for (int i=0;i<52;i++)
      temp[i] = array[i];
  array.resize(0);
  for (int i=0;i<52;i++)
    {
      randIndex = rand() % temp.size();
      cardAdd.num = temp[randIndex].num;
      cardAdd.suit = temp[randIndex].suit;
      array.insert(array.begin() + i, cardAdd);
      temp.erase(temp.begin() + randIndex);
    }
}

// //----------------------------------------------------------------------------------------
// //----------------------------------------------------------------------------------------

void dealCards(vector<card>& array, vector<person>& everybody)
{
  int numPeople;
  person temp;
  int counter = 0;
  cout << "Enter the number of people who will be playing Poker: ";
  cin >> numPeople;
  cout << endl;
   
  if (numPeople > 5 || numPeople <= 0)
    {
      while(numPeople > 5 || numPeople <= 0)
	{
	  cout << "The maximum number of people is 5. The minimum number is 1. Please enter a";
          cout << "number between 5 and 0: ";
	  cin >> numPeople;
	  cout << endl;
	}
    }
  
  for (int i = 0;i<numPeople;i++)
    {
      cout << "Please enter the name of person " << i+1 << ": ";
      cin >> temp.name;
      cout << endl << "Please enter how much money " << temp.name << " has: ";
      cin >> temp.cash;
      cout << endl;
      everybody.insert(everybody.begin() + i, temp);
    }
  
  cout << endl << endl << "The dealer will now deal the cards." << endl;

  for (int i = 0; i<everybody.size()*2; i++)
    {
      everybody[i%everybody.size()].hand[counter] = array[array.size() - 1];
      array.erase(array.begin() + (array.size() - 1));
      if (i == everybody.size()-1)
	counter = 1;
    }
}
