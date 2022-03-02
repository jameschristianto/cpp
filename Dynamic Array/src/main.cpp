#include <iostream>
#include <cstring>

using namespace std;

void printArr(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << endl;
    }
    cout << endl;
}

void resize(int arr[], int &size, int newSize)
{
    int *newArr = new int[newSize];
    for (int i = 0; i < size; i++)
    {
        newArr[i] = arr[i];
    }
    delete[] arr;
    arr = newArr;
    size = newSize;
}

void pushBack(int arr[], int &size, int value)
{
    if (size == 0)
    {
        arr[0] = value;
        size++;
    }
    else
    {
        resize(arr, size, size + 1);
        arr[size - 1] = value;
    }
}

void popBack(int arr[] , int &size)
{
    if (size == 0)
    {
        return;
    }
    else
    {
        resize(arr, size, size - 1);
    }
}

int main()
{
    int size = 5;
    int *arr = new int[size];
    int data[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int ext[5] = {6, 7, 8, 9, 10};

    arr = data;

    printArr(arr, size);

    resize(arr, size, 10);
    
    memcpy(&arr[5], ext, sizeof(ext));

    printArr(arr, size);

    pushBack(arr, size, 11);

    printArr(arr, size);

    popBack(arr, size);

    printArr(arr, size);

    delete[] arr;
    arr = nullptr;

    system("pause");
}