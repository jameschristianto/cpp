#include <iostream>
#include <map>
#include <string>
#include <fstream>

using namespace std;

map<string, int> menuId;
map<string, int> rootMenuId;
string filePathMap = "res/map.txt";
string delimiter = "=";

void InitMenuId()
{
    string line;
    string menuName;
    int id;
    bool isRoot;

    ifstream inFile(filePathMap);
    if (inFile.is_open())
    {
        while (getline(inFile, line))
        {
            if (line == "main menu")
            {
                isRoot = true;
                continue;
            }
            else if (line == "sub menu")
            {
                isRoot = false;
                continue;
            }
            else if (line.empty())
            {
                continue;
            }
            else
            {
                menuName = line.substr(0, line.find(delimiter));
                id = stoi(line.substr(line.find(delimiter) + 1));
            }

            if (isRoot)
                rootMenuId.insert({menuName, id});
            else
                menuId.insert({menuName, id});
        }
        inFile.close();
    }
    else
        cout << "Unable to open file" << endl;
}

int getMenuId(string menuName)
{
    return menuId[menuName];
};

int getRootMenuId(string menuName)
{
    return rootMenuId[menuName];
};

void runFlow(int id)
{
}