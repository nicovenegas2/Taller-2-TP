#include "Node.h"
#include <iostream>
using namespace std;

Node::Node(){
    this->array = NULL;
    this->cost = 0;
    this->prev = NULL;
    this->next = NULL;
    this->size = 0;
    this->availables = NULL;
    this->availablePointer = 0;
    this->clear();
}

Node::Node(int size, int cost, Node *prev, Node *next){
    this->array = new int[size];
    this->availablePointer = 0;
    this->availables = new int[size];
    this->cost = cost;
    this->prev = prev;
    this->size = size;
    this->next = next;
    this->clear();
}

Node::Node(Node *node){
    this->array = new int[node->size];
    this->cost = node->cost;
    this->prev = node->prev;
    this->size = node->size;
    this->next = node->next;
    this->availablePointer = node->availablePointer;
    this->availables = new int[node->size];
    for(int i = 0; i < this->size; i++){
        this->array[i] = node->array[i];
    }
    for(int i = 0; i < this->size; i++){
        this->availables[i] = node->availables[i];
    }
}

Node::Node(int size){
    this->array = new int[size];
    this->size = size;
    this->cost = 0;
    this->prev = NULL;
    this->next = NULL;
    this->clear();
}

int *Node::getData(){
    return this->array;
}

int Node::getCost(){
    return this->cost;
}

void Node::setPrev(Node *prev){
    this->prev = prev;
}

void Node::setCost(int cost){
    this->cost = cost;
}

void Node::setNext(Node *next){
    this->next = next;
}

Node *Node::getPrev(){
    return this->prev;
}

Node *Node::getNext(){
    return this->next;
}

void Node::clear(){
    this->cost = 0;
    this->prev = NULL;
    this->next = NULL;
    this->availablePointer = 0;
    for(int i = 0; i < this->size; i++){
        this->array[i] = -1;
    }
    for (int j = 0; j < this->size; j++)
    {
        this->availables[j] = j;
    }
}

void Node::markAvailable(int index){
    if(this->availablePointer == this->size){
        cout << "Error: availablePointer is out of bound" << endl;
        return;
    }else{
        int temp = this->availables[index];
        this->availables[index] = this->availables[this->availablePointer];
        this->availables[this->availablePointer] = temp;
        this->availablePointer++;
    }
}

int Node::getAvailablePointer(){
    return this->availablePointer;
}

int *Node::getAvailables(){
    return this->availables;
}