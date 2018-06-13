//-----------------------------------------------------
// Card Game Program Attempt
// Date: 1/18/18
//-----------------------------------------------------

// random bull crap


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

void createDeck(card array[52]);

void shuffleDeck(card array[52]);

int dealCards(card array[52], int numPeople, person everybody[5]);

int main()
{
   srand( time( NULL ) );
   // card deck[52];
   // int numPeople = 0;
   // person people[5];
   // createDeck(deck);
   
   // shuffleDeck(deck);
   // shuffleDeck(deck);
   // shuffleDeck(deck);
   
   // numPeople = dealCards(deck,numPeople, people);

   // for (int i = 0;i<52;i++)
   //     cout << deck[i].num << " of " << deck[i].suit << endl;
   vector<int> test(2);
   test[0] = 12;
   test[1] = 69;
   cout << test[0] << "    " << test[1] << endl;
   test.erase (test.begin() + 1);
   cout << test.size() << endl;					
   test.erase (test.begin() + 0);
   cout << test.size() << endl;
   test.insert(test.begin()+ 0, 5);
   test.insert(test.begin()+ 0, 69);
   cout << test[0] << "    " << test[1] << endl;
   cout << test.size() << endl;
  return(0);
}

//----------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------

void createDeck(card array[52])
{
  string eachCard[13] = {"2","3","4","5","6","7","8","9","10","Jack",
			 "Queen","King","Ace"};
  string suits[4] = {"Hearts","Diamonds","Spades","Clubs"};
  int count = 0;
  for (int i = 0;i<52;i++)
    {
      array[i].num = eachCard[i % 13];
      array[i].suit = suits[count];
       if (eachCard[i%13] == "Ace")
	     count++;
      
    }
}

//----------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------

void shuffleDeck(card array[52])
{
  card temp[52];
  int indextemp[52];
  int randIndex;
  int count = 1;
  for (int i=0;i<52;i++)
    indextemp[i] = 53;
  for (int i=0;i<52;i++)
    {
      //temp[i].num = array[i].num;
      //temp[i].suit = array[i].suit;
      temp[i] = array[i];
    }
  for (int i=0;i<52;i++)
    {
      randIndex = rand() % 52;
      for (int j=0; j<count;j++)
	{
	  if (indextemp[j] == randIndex)
	    {
	      randIndex = rand() % 52;
	      j = 0;
	    }
	}
      array[i] = temp[randIndex];
      indextemp[i] = randIndex;
      count++;
      
	
    }
}

//----------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------

int dealCards(card array[52], int numPeople, person everybody[5])
{
   cout << "Enter the number of people who will be playing Poker: ";
   cin >> numPeople;
   cout << endl;
   
   if (numPeople > 5)
     {
       while(numPeople > 5 )
	 {
	   cout << "The maximum number of people is 5. Please enter 5 or less: ";
	   cin >> numPeople;
	   cout << endl;
	 }
     }

   for (int i = 0;i<numPeople;i++)
     {
       cout << "Please enter the name of person " << i+1 << ": ";
       cin >> everybody[i].name;
       cout << endl << "Please enter how much money " << everybody[i].name << " has: ";
       cin >> everybody[i].cash;
       cout << endl;
     }

   cout << endl << endl << "The dealer will now deal the cards." << endl;
   
   return numPeople;
}
