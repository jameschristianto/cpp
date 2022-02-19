#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <vector>

using namespace std;

class Hash
{
public:
    list<pair<int, string>> table;

    void print();
};

void Hash::print()
{
    for (auto it = table.begin(); it != table.end(); it++)
    {
        cout << it->first << " " << it->second << endl;
    }
}

string filePath = "assets/file.txt";

int main()
{
    string line;
    vector<string> value;
    vector<int> id;
    ifstream inFile(filePath);
    pair<int, string> p;
    Hash hash;

    if (inFile.is_open())
    {
        cout << "File opened..." << endl;
        while (getline(inFile, line))
        {
            cout << "ID : " << line.substr(0, line.find(":"));
            id.push_back(stoi(line.substr(0, line.find(":"))));
            cout << " , Value : " << line.substr(line.find(":")) << endl;
            value.push_back(line.substr(line.find(":")));
        }
        inFile.close();
    }
    else
    {
        cout << "Unable to open file..." << endl;
        goto end;
    }

    cout << endl;

    for (size_t i = 0; i < id.size(); i++)
    {
        p.first = id[i];
        p.second = value[i];
        hash.table.push_back(p);
    }

    hash.print();

end:
    system("pause");
    return 0;
}