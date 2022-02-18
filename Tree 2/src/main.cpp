#include <iostream>

using namespace std;

class Tree
{
public:
    int value;
    Tree *right;
    Tree *left;

    Tree(int value)
    {
        this->value = value;
        right = nullptr;
        left = nullptr;
    }
};

void insert(Tree **rootNode, int value)
{
    Tree *root = *rootNode;
    if (root == nullptr)
    {
        *rootNode = new Tree(value);
        return;
    }
    if (root->value == value)
        return;
    if (value > root->value)
        insert(&(root->right), value);
    if (value < root->value)
        insert(&(root->left), value);
}

string find(Tree *rootNode, int value)
{
    string text = " at root";
    int depth = 0;
    bool isRight;

    while (rootNode != nullptr)
    {
        if (value < rootNode->value)
        {
            depth++;
            isRight = false;
            rootNode = rootNode->left;
        }
        else if (value > rootNode->value)
        {
            depth++;
            isRight = true;
            rootNode = rootNode->right;
        }
        else
        {
            if (depth == 0)
                return "Depth = " + to_string(depth) + text;
            if (isRight)
                return "Depth = " + to_string(depth) + text;
            else
                return "Depth = " + to_string(depth) + text;
        }

        if (isRight)
            text += "-right";
        else
            text += "-left";
    }

    return "Not found";
}

void print(Tree *rootNode, int space)
{
    if (rootNode == NULL)
        return;

    space++;

    print(rootNode->right, space);

    for (int i = 1; i < space; i++)
        cout << "\t";

    cout << rootNode->value << endl << endl;

    print(rootNode->left, space);
}

/* void print(Tree *rootNode, int space){
    space++;
    
    if(rootNode == nullptr) {
        for(int i = 1; i < space; i++)
            cout << "\t";
        cout << "NULL" << endl << endl;
        return;
    }
    
    print(rootNode->right, space);
    
    for(int i = 1; i < space; i++)
        cout << "\t";
        
    cout << rootNode->value << endl << endl;
    
    print(rootNode->left, space);
} */

int main()
{
    string text;
    Tree *rootNode = new Tree(10);

    insert(&rootNode, 15);
    insert(&rootNode, 4);
    insert(&rootNode, 1);
    insert(&rootNode, 23);
    insert(&rootNode, 5);
    insert(&rootNode, 12);

    print(rootNode, 0);

    cout << endl;

    cout << find(rootNode, 5) << endl << endl;

    system("pause");

    return 0;
}