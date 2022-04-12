#include "CpuAssign.h"
#include <iostream>
#include <algorithm>
#include <random>
using namespace std;

CpuAssign::CpuAssign(int n){
	this->size = n;
	this->generateTimes();
	this->porVisitar = new Container();
	this->visitando = new Container();
	this->minCuote = 0;
}

void CpuAssign::generateTimes(){
	srand48(time(NULL));
	int **times = new int*[this->size];
	for(int i = 0; i < this->size; i++){
		times[i] = new int[this->size];
	}
	for(int i = 0; i < this->size; i++){
		for(int j = 0; j < this->size; j++){
			times[i][j] = (int) (drand48() * 10);
		}
	}
	this->times = times;
}

CpuAssign::~CpuAssign(){
	for(int i = 0; i < this->size; i++){
		delete[] this->times[i];
	}
	delete[] this->times;
}

int CpuAssign::getMinArray(Node *node, int row){ // ya entrega el minimo de un arreglo solo visitando los availables
	int pointer = node->getAvailablePointer();
	int indexMin = node->getAvailables()[pointer]; // indice que contiene el valor minimo
	int min = this->times[row][indexMin]; // minimo
	int indexPos = pointer; // indice del available que contiene el indice del minimo
	for(int i = pointer; i < this->size; i++){
		if (this->times[row][node->getAvailables()[i]] < min){
			min = this->times[row][node->getAvailables()[i]];
			indexMin = node->getAvailables()[i];
			indexPos = i;
		}
	}
	return min;

}

// int CpuAssign::getCuote(Node* node,int start, int posValue){
// 	int cuote = 0;
// 	int *array = node->getData();
// 	array[start] = posValue;
// 	for(int i = start + 1; i < this->size; i++){                       O(n^4)
// 		for(int j = 0; j < this->size; j++){
// 			if(find(array, array + this->size, j)){
// 				cuote += this->times[i][j];
// 			}
// 		}
// 	}
// }

int CpuAssign::getCuote(Node* node,int start){
	int cuote = 0;	
	for(int i = start + 1; i < this->size; i++){
		cuote += this->getMinArray(node, i);
	}

	return cuote;
}

void CpuAssign::visit(Node *nodeVisit){
	Node *node = new Node(nodeVisit);
	int pointer = node->getAvailablePointer();
	int *availables = node->getAvailables();
	for(int i = pointer; i < this->size; i++){
		int posValue = availables[i];
		int cuote = this->getCuote(node, posValue);
		if(cuote < this->minCuote){
			this->minCuote = cuote;
			this->porVisitar->clear();
			this->porVisitar->add(node);
		}else if(cuote == this->minCuote){
			this->porVisitar->add(node);
		}
	}
}

void CpuAssign::solve(){
	Node *node = new Node(this->size);
	this->visit(node);
	cout << "hola" << endl;
	while(!this->porVisitar->isEmpty()){
		while(!this->visitando->isEmpty()){
		Node *node = this->visitando->pull();
		this->visit(node);
		}
		this->visitando->swap(this->porVisitar);
	}
	node->printData();

}

void CpuAssign::print(){
	for(int i = 0; i < this->size; i++){
		for(int j = 0; j < this->size; j++){
			cout << this->times[i][j] << " ";
		}
		cout << endl;
	}
}