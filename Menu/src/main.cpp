#include <iostream>
#include <fstream>
#include <stack>
#include <string>
#include <map>
#include <vector>

#include "../include/node.h"
#include "../include/util.h"
#include "../include/menu.h"

using namespace std;

#define COUNT_LEVEL 10 // start from 0
#define SUCCESS 0
#define FAILURE 1

string filePathMenu = "res/menu.txt";
char symbol = 0x20; // space

int checkLevelMenu(string line)
{
    int level = 0;
    for (size_t i = 0; i < line.size(); i++)
    {
        if (line[i] == symbol)
            level++;
        else
            break;
    }
    return level;
}

void showMenu(Node *menu)
{
    string name;
    for (char c : menu->value)
    {
        name.append(1, toupper(c));
    }
    cout << name << endl;
    for (size_t i = 0; i < menu->children.size(); i++)
        cout << i + 1 << ". " << menu->children[i]->value << endl;
}

typedef std::map<uint32_t, int (*)(Data *data)> function;
function menuTable = {
    {INSTALLMENT, mainInstallment},
    {CARD_VERIFICATION, mainCardVerification},
    {ON_US, mainOnUs},
    {OFF_US, mainOffUs},
    {PAYMENT, mainPayment},
    {TOP_UP, mainTopUp},
};

int runFunction(int id, Data *data)
{
    auto it = menuTable.find(id);
    if (it != menuTable.end())
    {
        return it->second(data);
    }

    return FAILURE;
}

int main()
{
    Node *root = new Node("Main Menu");
    Node *temp;
    string line;
    int level;
    vector<int> index(COUNT_LEVEL, -1); // index level 0, index level 1, ...

    InitMenuId();

    ifstream inFile(filePathMenu);
    if (inFile.is_open())
    {
        while (getline(inFile, line))
        {
            temp = root;
            level = checkLevelMenu(line);

            for (int i = 0; i < level; i++)
            {
                temp = temp->children[index[i]];
            }
            temp->children.push_back(new Node(trim(line)));

            if (level == 0)
            {
                int indexValue = index[0] + 1;
                fill(index.begin(), index.end(), -1);
                index[0] = indexValue;
            }
            else
                index[level]++;
        }
        inFile.close();
    }
    else
        cout << "Unable to open file" << endl;

    temp = root;

    stack<Node *> menu;
    menu.push(temp);
    size_t choice;
    Data *data = (Data *)malloc(sizeof(Data));
    int result = 0;

    while (1)
    {
        showMenu(menu.top());

        cout << endl
             << "Select menu : ";
        cin >> choice;
        cout << endl;

        if (menu.size() == 1)
            data->rootMenuId = getRootMenuId(menu.top()->value);

        if (choice == 0)
        {
            if (menu.size() > 1)
            {
                menu.pop();
                temp = menu.top();
            }
            continue;
        }
        else if (choice > menu.top()->children.size() || choice < 1)
        {
            cout << "Invalid choice" << endl
                 << endl;
            continue;
        }

        if (temp->children[choice - 1]->children.size() != 0)
        {
            temp = temp->children[choice - 1];
            menu.push(temp);
        }
        else
        {
            data->menuId = getMenuId(menu.top()->children[choice - 1]->value);
            result = runFunction(data->menuId, data);
            if (result == SUCCESS)
            {
                while (menu.size() > 1)
                    menu.pop();
                temp = menu.top();
            }
            else
                cout << "Error running flow" << endl;
            cout << endl;
        }
    }

    system("pause");
    return 0;
}