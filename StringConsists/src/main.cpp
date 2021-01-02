#include <iostream>
#include <string>

using namespace std;

int main()
{
    string input;
    unsigned int i;
    int res = 0;

    cout << "Input your name : ";
    cin >> input;

    for(i = 0; i < input.length(); i++){
        if(!((input[i] <= 'z' && input[i] >= 'a') || (input[i] <= 'Z' && input[i] >= 'A') || input[i] == ' ')){
            res = 1;
            break;
        }
    }

    if(res == 0) cout << "Valid name" << endl;
    else cout << "Invalid name" << endl;

    system("pause");

    return 0;
}
