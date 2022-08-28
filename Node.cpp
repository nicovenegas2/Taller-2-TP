#include "Node.h"
#include <iostream>
#include "string.h"
using namespace std;

Node::Node(){
    this->array = NULL;
    this->toMark = -1;
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
    this->toMark = -1;
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
    this->toMark = -1;
    this->cost = node->cost;
    // this->prev = node->prev;
    this->size = node->size;
    // this->next = node->next;
    this->availablePointer = node->availablePointer;
    this->availables = new int[node->size];
    memcpy(this->array, node->array, node->size * sizeof(int));
    memcpy(this->availables, node->availables, node->size * sizeof(int));
}

Node::Node(Node *node, int toMark){
    this->array = new int[node->size];
    this->toMark = -1;
    this->cost = node->cost;
    // this->prev = node->prev;
    this->size = node->size;
    // this->next = node->next;
    this->availablePointer = node->availablePointer;
    this->availables = new int[node->size];
    this->toMark = toMark;
    this->array = node->array;
    this->availables = node->availables;
}

Node::Node(int size){
    this->array = new int[size];
    this->availablePointer = 0;
    this->availables = new int[size];
    this->size = size;
    this->cost = 0;
    this->prev = NULL;
    this->next = NULL;
    this->clear();
    // cout << "size: " << size << endl;
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
    this->toMark = -1;
    this->prev = NULL;
    this->next = NULL;
    this->availablePointer = 0;
    for(int i = 0; i < this->size; i++){
        this->array[i] = -1;
        this->availables[i] = i;
    }
}

void Node::markAvailable(int index){
    if(this->availablePointer == this->size){
        cout << "Error: availablePointer is out of bound" << endl;
        return;
    }else{
        int pointer = this->availablePointer;
        this->array[pointer] = this->availables[index];
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

void Node::printData(){
    for(int i = 0; i < this->size; i++){
        cout << this->array[i] << " ";
    }
    cout << endl;
}

void Node::changeData(int data, int index){
    this->array[index] = data;
}

void Node::printAvailable(){
    for(int i = 0; i < this->size; i++){
        if(this->availablePointer == i){
            cout << "|" << this->availables[i] << "| ";
        }else {
            cout << this->availables[i] << " ";
        }
        
    }
    cout << "Pointer: " << this->availablePointer << endl;
    cout << endl;
}

void Node::unmarkAvailable(){
    this->array[this->availablePointer] = -1;
    this->availablePointer--;
}

void Node::markWait(){
    if(this->toMark != -1){
        int *arrayTemp = new int[this->size];
        int *availablesTemp = new int[this->size];
        memcpy(arrayTemp, this->array, this->size * sizeof(int));
        this->array = arrayTemp;
        
        memcpy(availablesTemp, this->availables, this->size * sizeof(int));
        this->availables = availablesTemp;
        this->markAvailable(this->toMark);
        this->toMark = -1;
    }
}