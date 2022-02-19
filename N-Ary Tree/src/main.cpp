#include <iostream>
#include <vector>

using namespace std;

class Tree
{
public:
    int value;
    vector<Tree *> children;

    Tree(int value)
    {
        this->value = value;
        children.empty();
    }
};

void insert(Tree **rootNode, int parentValue, int childValue)
{
    Tree *node = *rootNode;
    if (node == nullptr)
    {
        node = new Tree(parentValue);
        return;
    }

    if (node->value == parentValue)
    {
        Tree *child = new Tree(childValue);
        node->children.push_back(child);
        return;
    }

    for (unsigned int i = 0; i < node->children.size(); i++)
    {
        insert(&node->children[i], parentValue, childValue);
    }
}

void print(Tree *rootNode)
{
    if (rootNode == nullptr)
        return;

    cout << rootNode->value << ": ";

    if (rootNode->children.empty())
    {
        cout << "NULL" << endl;
        return;
    }
    else
    {
        for (unsigned int i = 0; i < rootNode->children.size(); i++)
        {
            cout << rootNode->children[i]->value << " ";
        }
    }
    cout << endl;

    for (unsigned int i = 0; i < rootNode->children.size(); i++)
    {
        print(rootNode->children[i]);
    }
}

int depth(Tree *rootNode, int value)
{
    if (rootNode == nullptr)
        return -1;

    if (rootNode->value == value)
        return 0;

    int maxDepth = -1;
    for (unsigned int i = 0; i < rootNode->children.size(); i++)
    {
        maxDepth = max(maxDepth, depth(rootNode->children[i], value));
    }

    return maxDepth;
}

int main()
{
    Tree *rootNode = new Tree(1);
    insert(&rootNode, 1, 2);
    insert(&rootNode, 1, 3);
    insert(&rootNode, 1, 4);
    insert(&rootNode, 2, 5);
    insert(&rootNode, 2, 6);
    insert(&rootNode, 3, 7);
    insert(&rootNode, 3, 8);
    insert(&rootNode, 4, 9);
    insert(&rootNode, 4, 10);

    print(rootNode);

    cout << "Depth value : " << depth(rootNode, 7) << endl;

    system("pause");

    return 0;
}