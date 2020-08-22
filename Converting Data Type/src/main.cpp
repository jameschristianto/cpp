#include <iostream>
#include <iomanip>

using namespace std;

//Interger Variable
short shortVar = 1;
short shortVar2;
int intVar = 2;
int intVar2;
long longVar = 3;
long longVar2;

//Decimal Variable
float floatVar = 1.1;
float floatVar2;
double doubleVar = 2.2;
double doubleVar2;

//Character Variable
char charVar = 'A';
char charVar2;
const char *constcharVar = "B";
const char *constcharVar2;
string stringVar = "C";
string stringVar2;

//Prototype or function declaration
void vdDataTypeSize();
void vdConvertpartone();
void vdconvertparttwo();
void vdconvertpartthree();
void vdconvertpartfour();

int main()
{
    vdDataTypeSize(); //Data type size
    vdConvertpartone(); //Integer conversion
    vdconvertparttwo(); //Decimal conversion
    vdconvertpartthree(); //Character conversion
    vdconvertpartfour();

    cin.get(); //Avoid window command prompt close directly

    return 0;
}

void vdDataTypeSize(){
    cout << "Size Short : " << sizeof(short) << " byte" << endl;
    cout << "Size Int   : " << sizeof(int) << " byte" << endl;
    cout << "Size Long  : " << sizeof(long) << " byte" << endl;
    cout << endl;

    cout << "Size Float : " << sizeof(float) << " byte" << endl;
    cout << "Size Double: " << sizeof(double) << " byte" << endl;
    cout << endl;

    cout << "Size Char      : " << sizeof(char) << " byte" << endl;
    cout << "Size Const Char: " << sizeof(const char*) << " byte" << endl;
    cout << "Size String    : " << sizeof(string) << " byte" << endl;
    cout << endl;
}

void vdConvertpartone(){
    //Short to int
    intVar2 = shortVar;
    cout << "Short to Int   : " << intVar2 << endl;
    cout << "size : " << sizeof(intVar2) << " byte" << endl;

    //Short to long
    longVar2 = shortVar;
    cout << "Short to Long  : " << longVar2 << endl;
    cout << "size : " << sizeof(longVar2) << " byte" << endl;

    //Int to short
    shortVar2 = intVar;
    cout << "Int to Short   : " << shortVar2 << endl;
    cout << "size : " << sizeof(shortVar2) << " byte" << endl;

    //Int to long
    longVar2 = intVar;
    cout << "Int to Long    : " << longVar2 << endl;
    cout << "size : " << sizeof(longVar2) << " byte" << endl;

    //Long to short
    shortVar2 = longVar;
    cout << "Long to Short  : " << shortVar2 << endl;
    cout << "size : " << sizeof(shortVar2) << " byte" << endl;

    //Long to int
    intVar2 = longVar;
    cout << "Long to Int    : " << intVar2 << endl;
    cout << "size : " << sizeof(intVar2) << " byte" << endl;
    cout << endl;
}

void vdconvertparttwo(){
    //Float to double
    doubleVar2 = floatVar;
    cout << "Float to Double    : " << doubleVar2 << endl;
    cout << "size : " << sizeof(doubleVar2) << " byte" << endl;

    //Double to float
    floatVar2 = doubleVar;
    cout << "Double to Float    : " << floatVar2 << endl;
    cout << "size : " << sizeof(floatVar2) << " byte" << endl;
    cout << endl;
}

void vdconvertpartthree(){
    //Char to const char
    constcharVar2 = &charVar;
    cout << "Char to Const Char     : " << constcharVar2 << endl;
    cout << "size : " << sizeof(constcharVar2) << " byte" << endl;

    //Char to string
    stringVar2 = charVar;
    cout << "Char to String         : " << stringVar2 << endl;
    cout << "size : " << sizeof(stringVar2) << " byte" << endl;

    //Const char to char
    charVar2 = constcharVar[0];
    cout << "Const Char to Char     : " << charVar2 << endl;
    cout << "size : " << sizeof(charVar2) << " byte" << endl;

    //Const char to string
    stringVar2 = constcharVar;
    cout << "Const Char to String   : " << stringVar2 << endl;
    cout << "size : " << sizeof(stringVar2) << " byte" << endl;

    //Sting to char
    charVar2 = stringVar[0];
    cout << "String to Char         : " << charVar2 << endl;
    cout << "size : " << sizeof(charVar2) << " byte" << endl;

    //String to const char
    constcharVar2 = stringVar.c_str();
    cout << "String to Const Char   : " << constcharVar2 << endl;
    cout << "size : " << sizeof(constcharVar2) << " byte" << endl;
    cout << endl;
}

void vdconvertpartfour(){
    //Short to float
    floatVar2 = (float)shortVar/4; //Casting to float (Using divided operation to see float result)
    cout << "Short to Float     : " << floatVar2 << endl;
    cout << "size : " << sizeof(floatVar2) << " byte" << endl;

    //Double to int
    intVar2 = doubleVar; //Rounding down if covert to integer directly, using round function to round properly
    cout << "Double to Int      : " << intVar2 << endl;
    cout << "size : " << sizeof(intVar2) << " byte" << endl;
}
