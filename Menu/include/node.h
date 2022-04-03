#include <vector>
#include <string>

using namespace std;

class Node
{
public:
    vector<Node *> children;
    string value;

    Node(string value);
    void print();
};