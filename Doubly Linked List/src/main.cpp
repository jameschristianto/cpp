#include <iostream>

using namespace std;

class Node
{
public:
    int value = 0;
    Node *next = nullptr;
    Node *prev = nullptr;

    Node(int value)
    {
        this->value = value;
    }
};

void init(Node **head, Node **tail, int value)
{
    Node *node = new Node(value);
    *head = node;
    *tail = node;
}

int getSize(Node *node)
{
    int size = 0;
    if (node->next == nullptr)
    {
        while (node != nullptr)
        {
            size++;
            node = node->prev;
        }
    }
    else if (node->prev == nullptr)
    {
        while (node != nullptr)
        {
            size++;
            node = node->next;
        }
    }

    return size;
}

void pushBack(Node **tail, int value)
{
    Node *newNode = new Node(value);
    if (*tail == nullptr)
    {
        return;
    }
    else
    {
        newNode->prev = *tail;
        (*tail)->next = newNode;
        *tail = newNode;
    }
}

void pushFront(Node **head, int value)
{
    Node *newNode = new Node(value);
    if (*head == nullptr)
    {
        return;
    }
    else
    {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
}

void insertAt(Node **head, Node **tail, int value, int position)
{
    if (position < 0 || position > getSize(*head))
        return;
    else if (position == 0)
    {
        pushFront(head, value);
    }
    else if (position == getSize(*head))
    {   
        pushBack(tail, value);
    }
    else
    {
        Node *newNode = new Node(value);
        Node *current = *head;
        for (int i = 0; i < position - 1; i++)
        {
            current = current->next;
        }
        newNode->next = current->next;
        newNode->prev = current;
        current->next->prev = newNode;
        current->next = newNode;
    }
}

void printForward(Node *head)
{
    cout << "NULL -> ";
    while (head != nullptr)
    {
        cout << head->value << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

void printBackward(Node *tail)
{
    cout << "NULL -> ";
    while (tail != nullptr)
    {
        cout << tail->value << " -> ";
        tail = tail->prev;
    }
    cout << "NULL" << endl;
}

int main()
{
    Node *headNode = nullptr;
    Node *tailNode = nullptr;

    init(&headNode, &tailNode, 0);

    pushBack(&tailNode, 1);
    pushBack(&tailNode, 2);
    pushBack(&tailNode, 3);

    pushFront(&headNode, -1);

    insertAt(&headNode, &tailNode, 9, 5);

    printForward(headNode);
    printBackward(tailNode);

    cout << getSize(headNode) << endl;
    cout << getSize(tailNode) << endl;

    system("pause");

    return 0;
}