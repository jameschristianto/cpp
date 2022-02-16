#include <iostream>

using namespace std;

unsigned int factorial(unsigned int number)
{
    if (number == 0)
        return 1;
    else
        return number * factorial(number - 1);
}

unsigned int permutation(unsigned int n, unsigned int k)
{
    return factorial(n) / factorial(n - k);
}

unsigned int combination(unsigned int n, unsigned int k)
{
    return factorial(n) / (factorial(k) * factorial(n - k));
}

int main()
{
    unsigned int input, n, k;

    while (1)
    {
        cout << "Please choose : " << endl;
        cout << "1. Permutation" << endl;
        cout << "2. Combination" << endl;

        cout << endl
             << "Your choice : ";
        cin >> input;

        switch (input)
        {
        case 1:
            cout << "Input n : ";
            cin >> n;
            cout << "Input k : ";
            cin >> k;
            if(n >= k) cout << "Result : " << permutation(n, k) << endl << endl;
            else cout << "Result : error" << endl << endl;
            break;
        case 2:
            cout << "Input n : ";
            cin >> n;
            cout << "Input k : ";
            cin >> k;
            if(n >= k) cout << "Result : " << combination(n, k) << endl << endl;
            else cout << "Result : error" << endl << endl;
            break;
        default:
            break;
        }
    }
    
    system("pause");

    return 0;
}