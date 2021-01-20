#include <iostream>
#include <string.h>

using namespace std;

int number = 10;
string text = "james";

void *vdInput;
int *intPtr;
string *strPtr;

int main()
{
    vdInput = &number;
    intPtr = (int *)vdInput;
    cout << "Value int   : " << *intPtr << endl;
    cout << "Address int : " << intPtr << endl;

    vdInput = &text;
    strPtr = (string *)vdInput;
    cout << "Value string   : " << *strPtr << endl;
    cout << "Address string : " << strPtr << endl;

    system("pause");

    return 0;
}
