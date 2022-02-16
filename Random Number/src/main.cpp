#include <iostream>
#include <ctime>

using namespace std;

int main()
{
    int number;
    int max = 10;

    srand(time(NULL));

    number = rand() % max; // start from 0 to max - 1

    cout << number << endl;

    number = rand() % (max + 1); // start from 1 to max

    cout << number << endl;

    system("pause");
    return 0;
}