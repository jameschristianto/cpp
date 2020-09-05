#include <iostream>
#include <cmath>

using namespace std;

int inOne;
int inTwo = 0;
int inThree = 5;
int inFour = 15;
int inFive = 125;

char buff[10];

int getLength(int n);

int main()
{
    //Variable
    cout << "Variable one   : " << endl;
    cout << "Variable two   : " << inTwo << endl;
    cout << "Variable three : " << inThree << endl;
    cout << "Variable four  : " << inFour << endl;
    cout << "Variable five  : " << inFive << endl << endl;

    //Using Log and trunc
    cout << "Using Logarithm and Trunc" << endl;
    cout << trunc(log10(inOne + 1)) << endl; //For empty variable
    cout << trunc(log10(inTwo + 1)) + 1 << endl; //remove plus 1 after ceil for got zero value
    cout << trunc(log10(inThree)) + 1 << endl;
    cout << trunc(log10(inFour)) + 1 << endl;
    cout << trunc(log10(inFive)) + 1 << endl << endl;

    //Using Log and ceil
    cout << "Using Logarithm and Ceil" << endl;
    cout << ceil(log10(inOne + 1)) << endl; //For empty variable
    cout << ceil(log10(inTwo + 1)) + 1 << endl; //Remove plus 1 after ceil for got zero value
    cout << ceil(log10(inThree)) << endl;
    cout << ceil(log10(inFour)) << endl;
    cout << ceil(log10(inFive)) << endl << endl;

    //Using sprintf
    cout << "Using Sprintf" << endl;
    cout << sprintf(buff, "%d", inOne) - 1 << endl; //For empty variable
    cout << sprintf(buff, "%d", inTwo) << endl; //minus 1 for got zero value
    cout << sprintf(buff, "%d", inThree) << endl;
    cout << sprintf(buff, "%d", inFour) << endl;
    cout << sprintf(buff, "%d", inFive) << endl << endl;

    //Using string
    cout << "Using String" << endl;
    string srOne = to_string(inOne);
    cout << srOne.length() - 1 << endl; //For empty variable
    string srTwo = to_string(inTwo);
    cout << srTwo.length() << endl; //Minus 1 for got zero value
    string srThree = to_string(inThree);
    cout << srThree.length() << endl;
    string srFour = to_string(inFour);
    cout << srFour.length() << endl;
    string srFive = to_string(inFive);
    cout << srFive.length() << endl << endl;

    //Using math
    cout << "Using Math" << endl;
    cout << getLength(inOne) << endl;
    cout << getLength(inTwo) + 1 << endl; //Remove plus 1 for got zero value
    cout << getLength(inThree) << endl;
    cout << getLength(inFour) << endl;
    cout << getLength(inFive) << endl;

    cin.get();

    return 0;
}

int getLength(int n){
    int inLength = 0;

    while(n != 0){
        inLength++;
        n /= 10;
    }

    return inLength;
}
