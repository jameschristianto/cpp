#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <iterator>

using namespace std;

int main()
{
    string word;
    string myString = "hellow world";
    stringstream ss(myString);
    map<string, int> myMap;
    map<string, int>::iterator itr;
    int x, y;
    char z;

    cout << "Stringstream = " << ss.str() << endl;

    ss.clear();

    myString = "one two one two three four one";
    ss << myString;

    cout << "Stringstream = " << ss.str() << endl;
    cout << endl;

    //parsing every word
    while (ss >> word)
        cout << word << endl;
    cout << endl;

    ss.clear();
    ss << myString;

    //count every word
    while (ss >> word)
        myMap[word]++;

    for (itr = myMap.begin(); itr != myMap.end(); itr++)
        cout << itr->first << " -> " << itr->second << endl;
    cout << endl;

    ss.clear();

    ss << 100 << '+' << 200;
    ss >> x >> z >> y;

    cout << x << endl;
    cout << y << endl;
    cout << z << endl;

    system("pause");
    return 0;
}