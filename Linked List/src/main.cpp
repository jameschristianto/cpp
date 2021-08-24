#include <iostream>
#include <vector>
#include "..\header\linkedlist.h"

using namespace std;

Node::Node(int value){
    this->value = value;
}

Node *rootNode = nullptr;
int menuSelected;

int main()
{
    cout << "1. Create new" << endl;
    cout << "2. Insert front" << endl;
    cout << "3. Insert back" << endl;
    cout << "4. Insert at" << endl;
    cout << "5. Erase front" << endl;
    cout << "6. Erase back" << endl;
    cout << "7. Erase at" << endl;
    cout << "8. Clear" << endl;
    cout << "9. Print" << endl;
    cout << endl;

    while (1)
    {
        cout << "Choose option above : ";
        cin >> menuSelected;
        cout << endl;

        switch (menuSelected)
        {
        case 1:
            clear(&rootNode);
            createNew(&rootNode);
            break;
        case 2:
            insertFront(&rootNode);
            break;
        case 3:
            insertBack(&rootNode);
            break;
        case 4:
            insertAt(&rootNode);
            break;
        case 5:
            eraseFront(&rootNode);
            break;
        case 6:
            eraseBack(&rootNode);
            break;
        case 7:
            eraseAt(&rootNode);
            break;
        case 8:
            clear(&rootNode);
            break;
        case 9:
            printNode(rootNode);
            break;
        default:
            break;
        }
    }

    cin.get();
    return 0;
}