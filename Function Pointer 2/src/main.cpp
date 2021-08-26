#include <iostream>
#include <vector>

using namespace std;

typedef bool (*funcPtr)(int, int);

bool ascendingCompare(int a, int b)
{
    return a < b;
}

bool descendingCompare(int a, int b)
{
    return a > b;
}

void Sorting(vector<int> &myVector, funcPtr myFunc)
{
    for (unsigned int startIndex = 0; startIndex < myVector.size(); startIndex++)
    {
        for (unsigned int currentIndex = startIndex + 1; currentIndex < myVector.size(); currentIndex++)
        {
            if (myFunc(myVector[currentIndex], myVector[startIndex]))
                swap(myVector[currentIndex], myVector[startIndex]);
        }
    }
}

void printVector(vector<int> myVector)
{
    for (unsigned int i = 0; i < myVector.size(); i++)
    {
        cout << myVector[i] << endl;
    }
}

int main()
{
    vector<int> myNumber = {7, 4, 1, 3, 6, 5, 9, 2};

    //ascending
    funcPtr ptrFunc = ascendingCompare;
    Sorting(myNumber, ptrFunc);
    printVector(myNumber);

    cout << endl;
    
    //descending
    ptrFunc = descendingCompare;
    Sorting(myNumber, ptrFunc);
    printVector(myNumber);

    system("pause");
    return 0;
}