#include "Node.h"

class Container
{
private:
    /* data */

public:
    Container(/* args */);
    ~Container();
    void add(Node *node);
    Node* pull();
    void clear();
    void swap(Container *container);
    Node *getHead();
    void print();
    bool isEmpty();

private:
    Node *head;
    int count;
};