#include <iostream>

using namespace std;

int n;

int recursiveFibonacci(int n);
int iterativeFibonacci(int n);
int enhanceIterativeFibonacci(int n);

int main()
{
    while (1)
    {
        cout << "Input number : ";
        cin >> n;

        if (n >= 0)
        {
            cout << "Number " << n << " is : " << recursiveFibonacci(n) << endl; // n - 1 for start from 0
            cout << "Number " << n << " is : " << iterativeFibonacci(n) << endl;
            cout << "Number " << n << " is : " << enhanceIterativeFibonacci(n) << endl;
        }
        else
            cout << "Please input number >= 0" << endl;
        cout << endl;
    }

    system("pause"); // Pause

    return 0;
}

int recursiveFibonacci(int n)
{
    if (n == 0 || n == 1)
        return n;
    else
        return (recursiveFibonacci(n - 1) + recursiveFibonacci(n - 2));
}

int iterativeFibonacci(int n)
{
    int fibonacci[n + 2];

    fibonacci[0] = 0;
    fibonacci[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
    }

    return fibonacci[n];
}

int enhanceIterativeFibonacci(int n)
{
    int a = 0, b = 1, c;

    for (int i = 2; i <= n; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }

    return c;
}