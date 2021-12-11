#include <iostream>
#include <Set>
#include <iterator>

using namespace std;

void print(set<int> mySet);
void getSize(set<int> mySet);
void insert(set<int> &mySet);
void check(set<int> &mySet);
void erase(set<int> &mySet);
void eraseArea(set<int> &mySet);
void clear(set<int> &mySet);

set<int> intSet;
set<char> charSet = {'a', 'b', 'c'};

int main()
{
    int selected;

    intSet.insert(1);
    intSet.insert(7);
    intSet.insert(3);
    intSet.insert(2);
    intSet.insert(5);

    do
    {
        cout << "1. Print" << endl;
        cout << "2. Size" << endl;
        cout << "3. Insert" << endl;
        cout << "4. Check" << endl;
        cout << "5. Erase" << endl;
        cout << "6. Erase Area" << endl;
        cout << "7. Clear" << endl;
        cout << endl;

        cout << "Input command : ";
        cin >> selected;

        switch (selected)
        {
        case 1:
            print(intSet);
            break;
        case 2:
            getSize(intSet);
            break;
        case 3:
            insert(intSet);
            break;
        case 4:
            check(intSet);
            break;
        case 5:
            erase(intSet);
            break;
        case 6:
            eraseArea(intSet);
            break;
        case 7:
            clear(intSet);
            break;
        default:
            break;
        }
    } while (1);

    system("pause");
    return 0;
}

void print(set<int> mySet)
{
    cout << endl;

    if (mySet.empty()){
        cout << "Set is empty..." << endl;
        cout << endl;
        return;
    }

    //method 1
    for (auto x : mySet)
    {
        cout << x << endl;
    }

    //method 2
    //set<int>::iterator itr;
    //for (itr = mySet.begin(); itr != mySet.end(); itr++)
    //{
    //    cout << *itr << endl;
    //}

    cout << endl;
}

void getSize(set<int> mySet)
{
    cout << endl;
    cout << "Set size : " << mySet.size() << endl;
    cout << endl;
}

void insert(set<int> &mySet)
{
    int value;

    cout << endl;
    cout << "Value : ";
    cin >> value;
    cout << endl;

    intSet.insert(value);
}

void check(set<int> &mySet)
{
    int value;
    int counter = 1;

    cout << endl;
    cout << "Value : ";
    cin >> value;

    if (mySet.find(value) != mySet.end())
    {
        auto pos = mySet.find(value);

        for (auto it = mySet.begin(); it != pos; it++)
            counter++;

        cout << "Position : " << counter << endl;
    }
    else cout << "Not fount..." << endl;

    cout << endl;
}

void erase(set<int> &mySet)
{
    int value;

    cout << endl;
    cout << "Value : ";
    cin >> value;
    cout << endl;

    intSet.erase(value);
}

void eraseArea(set<int> &mySet)
{
    int positionStart, positionEnd;
    set<int>::iterator itr = mySet.begin();
    set<int>::iterator itr2 = mySet.begin();

    cout << endl;
    cout << "Position start : ";
    cin >> positionStart;
    cout << "Position end : ";
    cin >> positionEnd;
    cout << endl;

    advance(itr, positionStart - 1);
    advance(itr2, positionEnd);

    mySet.erase(itr, itr2);
}

void clear(set<int> &mySet)
{
    mySet.clear();
}