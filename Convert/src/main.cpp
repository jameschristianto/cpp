#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int toInt(string input)
{
    int number = 0;

    /* for(char x : input){
        //number = (number * 10) + (x - '0');
        number = (number * 10) + (x - 48);
    } */
    
    for(size_t i = 0; i < input.length(); i++){
        number += pow(10, input.length() - i - 1) * (input[i] - 48);
    }

    return number;
}

int intLenght(int input){
    int digit = 0;

    do{
        digit++;
        input /= 10;
    }while(input);

    return digit;
}

string toStr(int input){
    string number = "";
    
    do{
        number += (input % 10) + 48;
        input /= 10;
    }while(input);

    //reverse(number.begin(), number.end());

    for(size_t i = 0; i < number.length() / 2; i++){
        swap(number[i], number[number.length() - i - 1]);
    }

    return number;
}

int main()
{
    string input;

    cin >> input;

    cout << toInt(input) << endl;
    cout << toStr(toInt(input)) << endl;

    system("pause");

    return 0;
}
