#include <iostream>

using namespace std;

//std::function<double (double,double)> func; //another method for declare function pointer
typedef void (*ptrPrintMessage)();
ptrPrintMessage Prt;

void printMessage(){
    cout << "this is message" << endl;
}

void callMessage(ptrPrintMessage Prt){
    Prt();
    cout << "this is another message" << endl;
}

int main()
{
    callMessage(printMessage);

    cin.get();

    return 0;
}
