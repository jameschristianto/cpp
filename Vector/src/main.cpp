#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> intVector;
    vector<char> charVector = {'a', 'b', 'c'};

    //add value to vector (pop_back for delete last value vector)
    intVector.push_back(1);
    intVector.push_back(2);
    intVector.push_back(3);
    intVector.push_back(4);
    intVector.push_back(5);

    //vector size
    cout << "size vector integer : " << intVector.size() << endl;
    cout << "size vector char : " << charVector.size() << endl;

    cout << endl;

    //looping vector method 1
    for(auto x : intVector){
        cout << x << endl;
    }

    cout << endl;

    //erase vector
    intVector.erase(intVector.begin() + 1);

    //looping vector method 2
    for(vector<int>::iterator it = intVector.begin(); it != intVector.end(); it++){
        cout << *it << endl;
    }

    cout << endl;

    //insert vector
    intVector.insert(intVector.end() - 1, 6);
    for(vector<int>::iterator it = intVector.begin(); it != intVector.end(); it++){
        cout << *it << endl;
    }

    cout << endl;

    //looping vector method 3
    for(auto it = charVector.begin(); it != charVector.end(); it++){
        cout << *it << endl;
    }

    cout << endl;

    //erase vector area
    charVector.erase(charVector.begin(), charVector.begin() + 2);

    //looping vector method 4
    for(unsigned int i = 0; i < charVector.size(); i++){
        cout << charVector[i] << endl;
    }

    cout << endl;

    //clear vector
    intVector.clear();
    charVector.clear();
    cout << "size vector integer : " << intVector.size() << endl;
    cout << "size vector char : " << charVector.size() << endl;

    cin.get();
    return 0;
}
