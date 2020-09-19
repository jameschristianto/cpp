#include <iostream>

using namespace std;

int n;

int inFaktorial(int n);

int main()
{
    cout << "Input number : ";
    cin >> n;
    cout << "Faktorial " << n << " is : " << inFaktorial(n) << endl;

    system("pause");

    return 0;
}

int inFaktorial(int n){
    if(n == 0) return 1;
    else return (n * inFaktorial(n - 1));
}
