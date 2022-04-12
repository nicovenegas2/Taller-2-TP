#include "Container.h"
#include <iostream>
using namespace std;



Container::Container(/* args */)
{
    this->head = NULL;
    this->count = 0;
}

void Container::add(Node *node){
    if(this->head == NULL){
        this->head = node;
    }else{
        Node * temp = this->head;
        temp->setPrev(node);
        this->head = node;
        this->head->setNext(temp);    
    }
    this->count++;
}

Node* Container::pull()
{
    if( count == 0){
        return NULL;
    }
    else if (count == 1){
        Node * temp = this->head;
        this->head = NULL;
        this->count--;
        return temp;
    }
    else if(count > 1){
        Node * temp = this->head;
        temp = temp->getNext();
        this->head = temp;
        this->count--;
        temp->setPrev(NULL);
        return temp;
        this->count--;
    }
}

Node *Container::getHead()
{
    return this->head;
}

void Container::clear()
{
    this->head = NULL;
    this->count = 0;
}

void Container::swap(Container *container)
{
    Node *temp = this->head;
    this->head = container->head;
    container->head = temp;
}

void Container::print(){
    if (this->head == NULL){
        cout << "Container is empty" << endl;
    }else {
        Node *temp = this->head;
        while(temp != NULL){
            cout << temp->getCost() << "-->";
            temp = temp->getNext();
        }
        cout << endl;
    }
}


bool Container::isEmpty(){
    return this->count == 0;
}




