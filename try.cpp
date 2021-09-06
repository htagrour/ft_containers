// C++ function for illustration
// map::lower_bound() function
#include <map>
#include <iostream>
using namespace std;
int main()
{
 
    // initialize container
    map<int, int> mp;
 
    // insert elements in random order
    mp.insert({ 2, 30 });
    mp.insert({ 1, 10 });
    mp.insert({ 5, 50 });
    mp.insert({ 4, 40 });
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        cout << (*it).first << " " <<
                              (*it).second << endl;
    }
 
    // when 2 is present
    int i = 3;
    auto it = mp.lower_bound(i);
    cout << "The lower bound of key "<< i<< " is ";
    cout << (*it).first << " " << (*it).second << endl;
    return 0;
}