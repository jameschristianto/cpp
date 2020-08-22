#include <iostream>
#include <math.h>

#define PI 3.14159265358979323846 //Change this value according to the value that you want to use

using namespace std;

double setDigit(int n);

int main()
{
    int inDigits;

    cout << "Enter how many digits you want : ";
    cin >> inDigits;
    cout << setDigit(inDigits) << endl;

    return 0;
}

double setDigit(int n){
    return round(PI * pow(10, n)) / pow(10, n);
}
