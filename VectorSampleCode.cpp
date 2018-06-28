//-----------------------------------------------------
// Basic Vector Example
// Date: 1/31/18
//-----------------------------------------------------


#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>

using namespace std;

int main()
{
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
