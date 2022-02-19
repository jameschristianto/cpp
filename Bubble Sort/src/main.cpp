#include <iostream>
#include <vector>

using namespace std;

void bubleSort(vector<int> &vec, int n)
{
    bool isSorted;
    for (int i = 0; i < n; i++)
    {
        isSorted = true;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (vec[j] > vec[j + 1])
            {
                int temp = vec[j];
                vec[j] = vec[j + 1];
                vec[j + 1] = temp;
                isSorted = false;
            }
        }
        if (isSorted)
            break;
    }
}

int main()
{
    string input;
    vector<int> vec;

    getline(cin, input);

    string delimiter = " ";
    size_t pos = input.find(delimiter);
    input.append(delimiter);
    int count = 0;

    while (pos != string::npos)
    {
        vec.push_back(stoi(input.substr(0, pos)));
        input.erase(0, pos + delimiter.length());
        pos = input.find(delimiter);
        count++;
    }

    cout << "Total : " << count << endl;

    bubleSort(vec, count);

    for (int x : vec)
    {
        cout << x << " ";
    }
    cout << endl;

    system("pause");

    return 0;
}