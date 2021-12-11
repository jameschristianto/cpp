#include <iostream>
#include <ctime>

using namespace std;

int main()
{
    int startTime = clock();

    for (int i = 1; i <= 100; i++)
    {
        cout << i << endl;
    }

    int endTime = clock();

    cout << "Execution time : " << (endTime - startTime)/double(CLOCKS_PER_SEC) << endl;

    system("pause");
    return 0;
}