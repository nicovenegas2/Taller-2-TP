#include "Node.h"
#include <iostream>
using namespace std;

Node::Node(){
    this->array = NULL;
    this->cost = 0;
    this->prev = NULL;
    this->next = NULL;
    this->size = 0;
}

Node::Node(int size, int cost, Node *prev, Node *next){
    this->array = new int[size];
    this->cost = cost;
    this->prev = prev;
    this->size = size;
    this->next = next;
}

Node::Node(Node *node){
    this->array = new int[node->size];
    this->cost = node->cost;
    this->prev = node->prev;
    this->size = node->size;
    this->next = node->next;
    for(int i = 0; i < this->size; i++){
        this->array[i] = node->array[i];
    }
}

Node::Node(int size){
    this->array = new int[size];
    this->size = size;
    this->cost = 0;
    this->prev = NULL;
    this->next = NULL;
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