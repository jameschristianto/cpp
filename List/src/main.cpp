#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <iterator>

using namespace std;

int myArray[] = {5, 3, 4, 1, 2};
list<int> copyList(myArray, myArray + 5);

list<int> myList = {2, 5, 1, 9, 6, 3};

void print(list<int> myList);
void getSize(list<int> myList);
void insert(list<int> &myList);
void pushBack(list<int> &myList);
void pushFront(list<int> &myList);
void popBack(list<int> &myList);
void popFront(list<int> &myList);
void sort(list<int> &myList);
void erase(list<int> &myList); // delete value based on position
void remove(list<int> &myList); // delete value
void clear(list<int> &myList); // delete all

int main()
{
    int select;

    do
    {
        cout << "1. Print" << endl;
        cout << "2. Size" << endl;
        cout << "3. Insert" << endl;
        cout << "4. Push Back" << endl;
        cout << "5. Push Front" << endl;
        cout << "6. Pop Back" << endl;
        cout << "7. Pop Front" << endl;
        cout << "8. Sort" << endl;
        cout << "9. Erase" << endl;
        cout << "10. Remove" << endl;
        cout << "11. Clear" << endl;
        cout << endl;

        cout << "Select command : ";
        cin >> select;

        switch (select)
        {
        case 1:
            print(myList);
            break;
        case 2:
            getSize(myList);
            break;
        case 3:
            insert(myList);
            break;
        case 4:
            pushBack(myList);
            break;
        case 5:
            pushFront(myList);
            break;
        case 6:
            popBack(myList);
            break;
        case 7:
            popFront(myList);
            break;
        case 8:
            sort(myList);
            break;
        case 9:
            erase(myList);
            break;
        case 10:
            remove(myList);
            break;
        case 11:
            clear(myList);
            break;
        default:
            break;
        }
    } while (1);

    system("pause");
    return 0;
}

void print(list<int> myList)
{
    list<int>::iterator itr;

    cout << endl;

    if (!myList.empty())
    {
        for (itr = myList.begin(); itr != myList.end(); ++itr)
        {
            cout << *itr << endl;
        }
    }
    else
        cout << "No data found..." << endl;

    cout << endl;
}

void getSize(list<int> myList)
{
    cout << endl;
    cout << "There is " << myList.size() << " data" << endl;
    cout << endl;
}

void insert(list<int> &myList)
{
    int position;
    int value;
    list<int>::iterator itr = myList.begin();

    cout << endl;
    cout << "Input position : ";
    cin >> position;
    cout << "Input value : ";
    cin >> value;

    advance(itr, position - 1);

    myList.insert(itr, value);

    cout << endl;
}

void pushBack(list<int> &myList)
{
    int value;

    cout << endl;
    cout << "Input value : ";
    cin >> value;

    myList.push_back(value);

    cout << endl;
}

void pushFront(list<int> &myList)
{
    int value;

    cout << endl;
    cout << "Input value : ";
    cin >> value;

    myList.push_front(value);

    cout << endl;
}

void popBack(list<int> &myList)
{
    myList.pop_back();

    cout << endl;
}

void popFront(list<int> &myList)
{
    myList.pop_front();

    cout << endl;
}

void sort(list<int> &myList)
{
    myList.sort();
    cout << endl;
}

void erase(list<int> &myList)
{
    int position;
    list<int>::iterator itr = myList.begin();

    cout << endl;
    cout << "Input position : ";
    cin >> position;

    advance(itr, position - 1);

    myList.erase(itr);

    cout << endl;
}

void remove(list<int> &myList)
{
    int value;
    list<int>::iterator itr = myList.begin();

    cout << endl;
    cout << "Input value : ";
    cin >> value;

    myList.remove(value);

    cout << endl;
}

void clear(list<int> &myList)
{
    myList.clear();
    cout << endl;
}