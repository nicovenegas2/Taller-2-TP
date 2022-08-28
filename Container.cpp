#include "Container.h"
#include <iostream>
using namespace std;



Container::Container() // Constructor
{
    this->head = NULL;
    this->count = 0;
}

void Container::add(Node *node){ // Agrega un nodo al inicio del contenedor
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

Node* Container::pull() // Extrae el primer nodo del contenedor
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

Node *Container::getHead() // Obtiene el primer nodo del contenedor
{
    return this->head;
}

void Container::clear() // Limpia el contenedor
{
    this->head = NULL;
    this->count = 0;
}

void Container::swap(Container *container) // Intercambia los contenedores
{
    Node *temp = this->head;
    int tempCount = this->count;
    this->head = container->head;
    container->head = temp;
    tempCount = container->count;
    container->count = this->count;
    this->count = tempCount;
}

void Container::print(){ // Imprime los costos de los nodos del contenedor
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


bool Container::isEmpty(){ // Verifica si el contenedor esta vacio
    return this->count == 0;
}

void Container::markWaitNodes(){ // Marca los nodos que estan esperando
    if (this->head == NULL){
        return;
    }
    Node *temp = this->head;
    while(temp != NULL){
        temp->markWait();
        temp = temp->getNext();
    }
}


