#include "Container.h"
#include <iostream>
using namespace std;

int main(){
    Container *c = new Container();
    Node *n1 = new Node(0,1,NULL,NULL);
    Node *n2 = new Node(1,2,NULL,NULL);
    Node *n3 = new Node(2,3,NULL,NULL);
    Node *n4 = new Node(3,4,NULL,NULL);
    c->add(n1);
    c->add(n2);
    c->print();
    c->add(n3);
    c->add(n4);
    c->print();
    c->pull();
    c->print();
    c->pull();
    c->pull();
    c->pull();
    c->print();
    
    return 0;
}