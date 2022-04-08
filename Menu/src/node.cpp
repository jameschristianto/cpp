#include <iostream>

#include "../include/node.h"

Node::Node(string value)
{
    this->value = value;
}

void Node::print()
{
    for (size_t i = 0; i < children.size(); i++)
    {
        cout << i + 1 << ". " << children[i]->value << endl;
    }
}