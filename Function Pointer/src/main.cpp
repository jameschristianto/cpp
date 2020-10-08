#include <iostream>

using namespace std;

int i = 5;
int j = 7, k = 9;

int inSquare(int x){
    return x * x;
}

void vdPrintMessage(string y){
    cout << "Respon Message is " << y << endl;
}

int inAdd(int a, int b){
    return a + b;
}

int main()
{
    //Make function pointer
    int (*pinSquare)(int);
    pinSquare = &inSquare;

    void (*pvdPrintMessage)(string);
    pvdPrintMessage = &vdPrintMessage;

    int (*pinAdd)(int, int);
    pinAdd = &inAdd;

    //Test function pointer
    cout << "Square of " << i << " is " << pinSquare(i) << endl;

    pvdPrintMessage("Test Function Pointer");

    cout << "Add of " << j << " and " << k << " is " << pinAdd(j, k) << endl;

    cin.get();

    return 0;
}
