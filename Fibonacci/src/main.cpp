#include <iostream>

using namespace std;

int n;

int inFibonacci(int n);

int main()
{
    cout << "Input number : ";
    cin >> n;

    if(n >= 0){
        cout << "Number " << n << " is : " << inFibonacci(n - 1) << endl; //n - 1 because start from 0
    }
    else cout << "Please input number >= 0" << endl;

    system("pause"); //Pause

    return 0;
}

int inFibonacci(int n){
    if(n == 0 || n == 1) return n;
    else return (inFibonacci(n - 1) + inFibonacci(n - 2));
}
