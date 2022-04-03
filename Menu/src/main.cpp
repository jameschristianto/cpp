#include <iostream>
#include <fstream>
#include <stack>
#include <string>
#include <map>
#include "../include/node.h"
#include "../include/util.h"
#include "../include/data.h"

using namespace std;

#define COUNT_LEVEL 10 // start from 0

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

/*void showMenu(vector<Node *> menu)
{
    for (size_t i = 0; i < menu.size(); i++)
    {
        cout << i + 1 << ". " << menu[i]->value << endl;
    }
}*/

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

int mainInstallment(Data *data){
    cout << data->menuId << endl;
    return 0;
}

int mainCardVerification(Data *data){
    cout << data->menuId << endl;
    return 0;
}

int mainOnUs(Data *data){
    cout << data->menuId << endl;
    return 0;
}

int mainOffUs(Data *data){
    cout << data->menuId << endl;
    return 0;
}

int mainPayment(Data *data){
    cout << data->menuId << endl;
    return 0;
}

int mainTopUp(Data *data){
    cout << data->menuId << endl;
    return 0;
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

void runFunction(int id, Data *data){
    auto it = menuTable.find(id);
    if (it != menuTable.end())
        it->second(data);
}

int main()
{
    Node *root = new Node("Main Menu");
    Node *temp;
    string line;
    int level;
    // vector<Node *> menu;
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

            /*switch (level)
            {
            case 0:
                root->children.push_back(new Node(trim(line)));
                index[0]++;
                index[1] = -1;
                index[2] = -1;
                break;
            case 1:
                root->children[index[0]]->children.push_back(new Node(trim(line)));
                index[1]++;
                break;
            case 2:
                root->children[index[0]]->children[index[1]]->children.push_back(new Node(trim(line)));
                index[2]++;
                break;
            default:
                break;
            }*/
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
            runFunction(data->menuId, data);
            cout << endl;
        }
    }

    /*menu = temp->children;

    while (1)
    {
        showMenu(menu);

        cout << endl
             << "Select menu : ";
        cin >> choice;

        if (choice == 0)
        {
            cout << endl;
            temp = root;
            menu = temp->children;
            continue;
        }
        else if (choice > menu.size() || choice < 1)
        {
            cout << "Invalid choice" << endl
                 << endl;
            continue;
        }

        if (temp->children[choice - 1]->children.size() != 0)
        {
            temp = temp->children[choice - 1];
            menu = temp->children;
        }
        else
            cout << temp->children[choice - 1]->value << endl
                 << endl;
    }*/

    system("pause");
    return 0;
}