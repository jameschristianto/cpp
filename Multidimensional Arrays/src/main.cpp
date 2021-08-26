#include <iostream>

using namespace std;

int main()
{
    int rows = 3;
    int cols = 4;

    int **table = new int *[rows];

    for (int i = 0; i < rows; i++)
    {
        table[i] = new int[cols];
    }

    table[0][0] = 1;
    table[0][1] = 2;
    table[0][2] = 3;
    table[0][3] = 4;

    table[1][0] = 5;
    table[1][1] = 6;
    table[1][2] = 7;
    table[1][3] = 8;

    table[2][0] = 9;
    table[2][1] = 1;
    table[2][2] = 2;
    table[2][3] = 3;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << table[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < rows; i++)
    {
        delete[] table[i];
    }
    delete table;
    table = NULL;

    system("pause");
    return 0;
}