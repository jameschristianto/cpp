#include <iostream>
#define COUNT 10

using namespace std;

class Tree
{
private:
    int value;

public:
    class Tree *right;
    class Tree *left;
    Tree(int value);
    ~Tree();
    void insertValue(int value);
    void printTree();
    int getValue();
};

Tree::Tree(int value)
{
    this->value = value;
    right = nullptr;
    left = nullptr;
}

Tree::~Tree()
{
    // do nohing
}

void Tree::insertValue(int value)
{
    if (value > this->value)
    {
        if (right == nullptr)
        {
            right = new Tree(value);
        }
        else
        {
            right->insertValue(value);
        }
    }
    else
    {
        if (left == nullptr)
        {
            left = new Tree(value);
        }
        else
        {
            left->insertValue(value);
        }
    }
}

void Tree::printTree()
{
    if (left != nullptr)
    {
        left->printTree();
    }
    cout << value << endl;
    if (right != nullptr)
    {
        right->printTree();
    }
}

int Tree::getValue()
{
    return value;
}

void print(Tree *root, int space)
{
    if (root == NULL)
    {
        for (int i = COUNT; i < space + COUNT; i++)
            cout << " ";
        cout << "NULL" << endl;
        return;
    }

    space += COUNT;

    print(root->right, space);

    cout << endl;
    for (int i = COUNT; i < space; i++)
        cout << " ";
    cout << root->getValue() << "\n";

    print(root->left, space);
}

int main()
{
    Tree *rootNode = new Tree(10);

    rootNode->insertValue(5);
    rootNode->insertValue(12);
    rootNode->insertValue(3);
    rootNode->insertValue(11);

    print(rootNode, 0);

    cout << endl;

    system("pause");
    
    return 0;
}