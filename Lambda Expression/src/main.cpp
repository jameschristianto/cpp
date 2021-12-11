#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> myVec{2, 4, 15, 6, 9, 17, 31, 22, 26, 11};
    int selected;

    cout << "Number list" << endl;
    for(int i : myVec) cout << i << " ";
    cout << endl << endl;

    do
    {
        cout << "Input diveder number : ";
        cin >> selected;

        for_each(myVec.begin(), myVec.end(), [selected](int vec){
            if(vec % selected == 0) cout << vec << " ";
        });

        cout << endl << endl;
    } while (1);

    system("pause");
    return 0;
}