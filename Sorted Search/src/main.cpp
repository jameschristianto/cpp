#include <iostream>

using namespace std;

int findNumber(int arr[], int find, int len)
{
    int low = 0, high = len - 1, mid;

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (arr[mid] == find)
        {
            return mid;
        }
        else if (arr[mid] < find)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return -1;
}

int main()
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int len = sizeof(arr) / sizeof(arr[0]);

    int find;

    cout << "Input number to find : ";
    cin >> find;

    if (findNumber(arr, find, len) == -1)
        cout << "Not found" << endl;
    else
        cout << "Find at index " << findNumber(arr, find, len) << endl;

    system("pause");

    return 0;
}