#include <iostream>
#include <vector>

using namespace std;

void insertionSort(vector<int> &vec, int n)
{
    for(int i = 1; i < n; i++){
        int key = vec[i];
        int j = i - 1;
        while(j >= 0 && vec[j] > key){
            vec[j + 1] = vec[j];
            j--;
        }
        vec[j + 1] = key;
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

    insertionSort(vec, count);

    for (int x : vec)
    {
        cout << x << " ";
    }
    
    cout << endl;

    system("pause");

    return 0;
}