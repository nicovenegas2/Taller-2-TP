#include "Node.h"

class Container
{
private:
    /* data */

public:
    Container(/* args */);
    ~Container();
    void add(Node *node);
    Node* pull(Node *node);
    void clear();
    void swap(Container *container);
    Node *getHead();
    void print();

private:
    Node *head;
    int count;
};