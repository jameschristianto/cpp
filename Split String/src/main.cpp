#include <iostream>

using namespace std;

int main()
{
    string data = "My name is James";
    string word = "";

    for(auto x : data){
        if(x == ' '){
            cout << word << endl; //Print word every space
            word = "";
        }
        else word = word + x;
    }
    cout << word << endl; //Print last word

    cin.get();

    return 0;
}
