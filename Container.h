#include "Node.h"

class Container
{
    /*
    Estructura de datos que representa un contenedor de nodos
    */

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
    void markWaitNodes();

private:
    Node *head;
    int count;
};