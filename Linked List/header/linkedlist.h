class Node
{
public:
    int value = 0;
    Node *nextNode = nullptr;

    Node(int value);
};

void createNew(Node **node);
void insertFront(Node **node);
void insertBack(Node **node);
void insertAt(Node **node);
void eraseFront(Node **node);
void eraseBack(Node **node);
void eraseAt(Node **node);
void clear(Node **node);
void printNode(Node *node);
int getNumberOfNode(Node *node);