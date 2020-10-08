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
    //pinSquare = inSquare; //Another method

    void (*pvdPrintMessage)(string);
    pvdPrintMessage = &vdPrintMessage;
    //pvdPrintMessage = vdPrintMessage; //Another method

    int (*pinAdd)(int, int);
    pinAdd = &inAdd;
    //pinAdd = inAdd; //Another method

    //Test function pointer
    cout << "Square of " << i << " is " << pinSquare(i) << endl;
    //cout << "Square of " << i << " is " << (*pinSquare)(i) << endl; //Another method

    pvdPrintMessage("Test Function Pointer");
    //(*pvdPrintMessage)("Test Function Pointer"); //Another method

    cout << "Add of " << j << " and " << k << " is " << pinAdd(j, k) << endl;
    //cout << "Add of " << j << " and " << k << " is " << (*pinAdd)(j, k) << endl; //Another method

    cin.get();

    return 0;
}
