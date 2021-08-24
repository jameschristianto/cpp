#include <iostream>
#include <vector>
#include "..\header\linkedlist.h"

using namespace std;

Node::Node(int value)
{
    this->value = value;
}

void createNew(Node **node)
{
    int numberOfNode, nodeValue;

    cout << "Input number of Node : ";
    cin >> numberOfNode;
    cout << endl;

    for (int i = 0; i < numberOfNode; i++)
    {
        cout << "Input value " << i + 1 << " : ";
        cin >> nodeValue;

        Node *newNode = new Node(nodeValue);

        if (*node == nullptr)
        {
            *node = newNode;
        }
        else
        {
            Node *tempNode = *node;
            while (tempNode->nextNode != nullptr)
                tempNode = tempNode->nextNode;
            tempNode->nextNode = newNode;
        }
    }
    cout << endl;
}

void insertFront(Node **node)
{
    int nodeValue;

    cout << "Node value : ";
    cin >> nodeValue;

    Node *newNode = new Node(nodeValue);

    newNode->nextNode = *node;
    *node = newNode;

    cout << endl;
}

void insertBack(Node **node)
{
    int nodeValue;

    cout << "Node value : ";
    cin >> nodeValue;

    Node *newNode = new Node(nodeValue);
    Node *tempNode = *node;

    while (tempNode->nextNode != nullptr)
        tempNode = tempNode->nextNode;
    tempNode->nextNode = newNode;

    cout << endl;
}

void insertAt(Node **node)
{
    int counter = 1;
    int numberOfNode = getNumberOfNode(*node);
    int nodePosition, nodeValue;

    cout << "Node position : ";
    cin >> nodePosition;
    cout << endl;

    if (nodePosition > numberOfNode + 1)
    {
        cout << "Invalid position" << endl
             << endl;
    }
    if (nodePosition == 1)
    {
        insertFront(node);
    }
    else if (nodePosition == numberOfNode + 1)
    {
        insertBack(node);
    }
    else
    {
        cout << "Node value : ";
        cin >> nodeValue;
        cout << endl;

        Node *newNode = new Node(nodeValue);
        Node *tempNode = *node;

        while (tempNode != nullptr)
        {
            ++counter;

            if (counter == nodePosition)
            {
                newNode->nextNode = tempNode->nextNode;
                tempNode->nextNode = newNode;
            }
            else
            {
                tempNode = tempNode->nextNode;
            }
        }
    }
}

void eraseFront(Node **node)
{
    Node *tempNode = *node;

    tempNode = (*node)->nextNode;
    delete[] * node;
    *node = tempNode;
}

void eraseBack(Node **node)
{
    Node *tempNode = *node;
    Node *prevNode = nullptr;

    while (tempNode->nextNode != nullptr)
    {
        prevNode = tempNode;
        tempNode = tempNode->nextNode;
    }

    prevNode->nextNode = nullptr;
    delete tempNode;
}

void eraseAt(Node **node)
{
    int counter = 1;
    int numberOfNode = getNumberOfNode(*node);
    int nodePosition;

    cout << "Node position : ";
    cin >> nodePosition;
    cout << endl;

    if (nodePosition > numberOfNode)
    {
        cout << "Invalid position" << endl
             << endl;
    }
    else if (nodePosition == 1)
    {
        eraseFront(node);
    }
    else if (nodePosition == numberOfNode)
    {
        eraseBack(node);
    }
    else
    {
        Node *tempNode = *node;
        Node *prevNode = nullptr;

        while (tempNode->nextNode != nullptr)
        {
            ++counter;
            prevNode = tempNode;
            tempNode = tempNode->nextNode;

            if (counter == nodePosition)
            {
                prevNode->nextNode = tempNode->nextNode;
                delete tempNode;
                break;
            }
        }
    }
}

void clear(Node **node)
{
    Node *tempNode = *node;

    while (*node != nullptr)
    {
        tempNode = (*node)->nextNode;
        delete[] * node;
        *node = tempNode;
    }
}

void printNode(Node *node)
{
    int counter = 0;

    while (node != nullptr)
    {
        ++counter;
        cout << "Node " << counter << " value : " << node->value << endl;
        node = node->nextNode;
    }

    if (!counter)
        cout << "There is no node" << endl;
    else
        cout << "There is " << counter << " node" << endl;
    cout << endl;
}

int getNumberOfNode(Node *node)
{
    int numberOfNode = 0;

    while (node != nullptr)
    {
        ++numberOfNode;
        node = node->nextNode;
    }

    return numberOfNode;
}