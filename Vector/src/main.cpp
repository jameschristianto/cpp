#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> myVector);
void getSize(vector<int> myVector);
void insert(vector<int> &myVector);
void erase(vector<int> &myVector);
void eraseArea(vector<int> &myVector);
void clear(vector<int> &myVector);

vector<int> intVector;
vector<char> charVector = {'a', 'b', 'c'};

int main()
{
    int selected;

    intVector.push_back(1);
    intVector.push_back(7);
    intVector.push_back(3);
    intVector.push_back(2);
    intVector.push_back(5);

    do
    {
        cout << "1. Print" << endl;
        cout << "2. Size" << endl;
        cout << "3. Insert" << endl;
        cout << "4. Erase" << endl;
        cout << "5. Erase Area" << endl;
        cout << "5. Clear" << endl;
        cout << endl;

        cout << "Input command : ";
        cin >> selected;

        switch (selected)
        {
        case 1:
            print(intVector);
            break;
        case 2:
            getSize(intVector);
            break;
        case 3:
            insert(intVector);
            break;
        case 4:
            erase(intVector);
            break;
        case 5:
            eraseArea(intVector);
            break;
        case 6:
            clear(intVector);
            break;
        default:
            break;
        }
    } while (1);

    system("pause");
    return 0;
}

void print(vector<int> myVector)
{
    cout << endl;
    //looping vector method 1
    for (auto x : myVector)
    {
        cout << x << endl;
    }
    //looping vector method 2
    //for(vector<int>::iterator it = myVector.begin(); it != myVector.end(); it++){
    //    cout << *it << endl;
    //}
    //looping vector method 3
    //for(auto it = myVector.begin(); it != myVector.end(); it++){
    //    cout << *it << endl;
    //}
    //looping vector method 4
    //for(unsigned int i = 0; i < myVector.size(); i++){
    //    cout << myVector[i] << endl;
    //}
    cout << endl;
}

void getSize(vector<int> myVector)
{
    cout << endl;
    cout << "Vector size : " << myVector.size() << endl;
    cout << endl;
}

void insert(vector<int> &myVector)
{
    int position;
    int value;

    cout << endl;
    cout << "Position : ";
    cin >> position;
    cout << "Value : ";
    cin >> value;
    cout << endl;

    intVector.insert(myVector.begin() + position - 1, value);
}

void erase(vector<int> &myVector)
{
    int position;

    cout << endl;
    cout << "Position : ";
    cin >> position;
    cout << endl;

    intVector.erase(myVector.begin() + position - 1);
}

void eraseArea(vector<int> &myVector)
{
    int positionStart, positionEnd;

    cout << endl;
    cout << "Position start : ";
    cin >> positionStart;
    cout << "Position end : ";
    cin >> positionEnd;
    cout << endl;

    myVector.erase(myVector.begin() + positionStart - 1, myVector.begin() + positionEnd);
}

void clear(vector<int> &myVector)
{
    myVector.clear();
}