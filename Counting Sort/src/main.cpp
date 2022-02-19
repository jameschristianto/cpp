#include <iostream>
#include <vector>

using namespace std;

void countingSort(vector<int> &vec, int n)
{
    int max = vec[0];
    for(auto &i : vec){
        if(max < i) max = i;
    }
    vector<int> temp(max + 1);
    for(int i = 0; i  < n; i++){
        temp[vec[i]]++;
    }
    int index = 0;
    for(int i = 0; i <= max; i++){
        while(temp[i] > 0){
            vec[index++] = i;
            temp[i]--;
        }
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

    countingSort(vec, count);

    for (int x : vec)
    {
        cout << x << " ";
    }
    
    cout << endl;

    system("pause");

    return 0;
}