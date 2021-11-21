#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <utility> //make_pair

using namespace std;

string filePath = "assets/file.txt";

void findValue(map<int, string> &myMap);
void print(map<int, string> myMap);
void getSize(map<int, string> myMap);
void insert(map<int, string> &myMap);
void erase(map<int, string> &myMap);
void clear(map<int, string> &myMap);

int main()
{
    map<int, string> myMap;
    pair<int, string> myPair;

    int key;
    string value;

    string line;
    ifstream inFile(filePath);

    int select;

    if (inFile.is_open())
    {
        cout << "File opened..." << endl;
        while (getline(inFile, line))
        {
            //cout << "ID : " << line.substr(0, line.find(":"));
            //cout << " , Value : " << line.substr(line.find(":") + 1) << endl;

            key = stoi(line.substr(0, line.find(":")));
            value = line.substr(line.find(":") + 1);

            //method 1
            myMap.insert({key, value});

            //method 2
            //myMap.insert(make_pair(key, value));

            //method 3
            //myMap[key] = value;
        }
        inFile.close();
    }
    else
        cout << "Unable to open file..." << endl;

    do
    {
        cout << "1. Print" << endl;
        cout << "2. Find" << endl;
        cout << "3. Size" << endl;
        cout << "4. Insert" << endl;
        cout << "5. Erase" << endl;
        cout << "6. Clear" << endl;
        cout << endl;

        cout << "Select command : ";
        cin >> select;

        switch (select)
        {
        case 1:
            print(myMap);
            break;
        case 2:
            findValue(myMap);
            break;
        case 3:
            getSize(myMap);
            break;
        case 4:
            insert(myMap);
            break;
        case 5:
            erase(myMap);
            break;
        case 6:
            clear(myMap);
            break;
        default:
            break;
        }
    } while (1);

    system("pause");
    return 0;
}

void findValue(map<int, string> &myMap)
{
    int selectKey;

    cout << endl;
    cout << "Input key : ";
    cin >> selectKey;

    if (myMap.find(selectKey) != myMap.end())
    {
        cout << "Value of key " << selectKey << " : " << myMap.find(selectKey)->second << endl;
        cout << endl;
        return;
    }

    cout << "Key not found..." << endl;
    cout << endl;
}

void print(map<int, string> myMap)
{
    map<int, string>::iterator itr;

    cout << endl;

    if (!myMap.empty())
    {
        for (itr = myMap.begin(); itr != myMap.end(); ++itr)
        {
            cout << itr->first << " -> " << itr->second << endl;
        }
    }
    else
        cout << "No data found..." << endl;

    cout << endl;
}

void getSize(map<int, string> myMap)
{
    cout << endl;
    cout << "There is " << myMap.size() << " data" << endl;
    cout << endl;
}

void insert(map<int, string> &myMap)
{
    int key;
    string value;

    cout << endl;
    cout << "Input key : ";
    cin >> key;
    cout << "Input value : ";
    cin >> value;

    if (myMap.find(key) == myMap.end())
        myMap.insert({key, value});
    else
        myMap.find(key)->second = value;

    cout << endl;
}
void erase(map<int, string> &myMap)
{
    int key;
    string value;
    map<int, string>::iterator itr;

    cout << endl;
    cout << "Input key : ";
    cin >> key;

    //method 1
    myMap.erase(key);

    //method 2
    //itr = myMap.find(key);
    //myMap.erase(itr);

    cout << endl;
}

void clear(map<int, string> &myMap)
{
    myMap.clear();
    cout << endl;
}