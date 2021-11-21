#include <iostream>

using namespace std;

int main()
{
    int selected;

    do
    {
        cout << "Input command : ";
        cin >> selected;

        switch (selected)
        {
        case 1:
            goto __STATEMENT_1__;
            break;
        case 2:
            goto __STATEMENT_2__;
            break;
        case 3:
            goto __STATEMENT_3__;
            break;
        default:
            break;
        }

    __STATEMENT_1__:
        cout << "Statement 1" << endl;

    __STATEMENT_2__:
        cout << "Statement 2" << endl;
        continue;

    __STATEMENT_3__:
        cout << "Statement 3" << endl;

    } while (1);

    system("pause");
    return 0;
}