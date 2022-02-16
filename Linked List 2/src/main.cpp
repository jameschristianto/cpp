#include <iostream>

using namespace std;

class Node
{
public:
    int value = 0;
    Node *next = nullptr;

    Node(int value)
    {
        this->value = value;
    }
};

int getSize(Node *node)
{
    int size = 0;
    while (node != nullptr)
    {
        size++;
        node = node->next;
    }
    return size;
}

void pushBack(Node **node, int value)
{
    Node *newNode = new Node(value);
    if (*node == nullptr)
    {
        *node = newNode;
    }
    else
    {
        Node *current = *node;
        while (current->next != nullptr)
            current = current->next;
        current->next = newNode;
    }
}

void pushFront(Node **node, int value)
{
    Node *newNode = new Node(value);
    if (*node == nullptr)
    {
        *node = newNode;
    }
    else
    {
        newNode->next = *node;
        *node = newNode;
    }
}

void insertAt(Node **node, int value, int position)
{
    if (position < 0 || position > getSize(*node))
        return;
    else if (position == 0)
    {
        pushFront(node, value);
    }
    else
    {
        Node *newNode = new Node(value);
        Node *current = *node;
        for (int i = 0; i < position - 1; i++)
        {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

void printNode(Node *node)
{
    while (node != nullptr)
    {
        cout << node->value << " -> ";
        node = node->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    Node *rootNode = new Node(0);

    pushBack(&rootNode, 1);
    pushBack(&rootNode, 2);
    pushBack(&rootNode, 3);

    pushFront(&rootNode, -1);

    printNode(rootNode);

    insertAt(&rootNode, 9, 4);

    printNode(rootNode);

    system("pause");

    return 0;
}