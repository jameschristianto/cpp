#include <iostream>

using namespace std;

size_t sizeAlloc = sizeof(int);
int multiple = 5;

int main()
{
    //use dynamic memory (without pointing to stact memory)
    int *ptrInt = (int *)malloc(multiple * sizeAlloc); //memory allocate
    //int *ptrInt = (int *)calloc(multiple, sizeAlloc); //continuous allocate

    if (ptrInt == NULL) {
        cout << "Memory space insufficient" << endl;
        return 0;
    }

    for (int i = 0; i < multiple; i++)
    {
        ptrInt[i] = (i * 2) + 1;
    }

    for (int i = 0; i < multiple; i++)
    {
        cout << "Value at position " << i << " is " << *(ptrInt + i) << endl;
    }

    cout << endl;

    //reallocate memory beacuse size change
    multiple = 10;
    ptrInt = (int *)realloc(ptrInt, multiple * sizeAlloc);

    for (int i = 0; i < multiple; i++)
    {
        ptrInt[i] = (i * 2) + 1;
    }

    for (int i = 0; i < multiple; i++)
    {
        cout << "Value at position " << i << " is " << *(ptrInt + i) << endl;
    }

    //free memory
    free(ptrInt);

    cout << endl;
    multiple = 5;

    //use dynamic memory with operator new
    int *ptrNewInt = new int[multiple];

    for (int i = 0; i < multiple; i++)
    {
        ptrNewInt[i] = (i * 2) + 1;
    }

    for (int i = 0; i < multiple; i++)
    {
        cout << "Value at position " << i << " is " << *(ptrNewInt + i) << endl;
    }

    //free memory
    delete[] ptrNewInt;

    system("pause");
    return 0;
}