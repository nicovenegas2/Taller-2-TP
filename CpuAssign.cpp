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

int CpuAssign::getMinArray(Node *node, int row){
	int min = this->times[row][0];
	for(int i = node->getAvailablePointer(); i < this->size; i++){
		if (min > this->times[row][node->getAvailables()[i]]){
			min = this->times[row][i];
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



void CpuAssign::solve(){
	
	
}

void CpuAssign::print(){
	for(int i = 0; i < this->size; i++){
		for(int j = 0; j < this->size; j++){
			cout << this->times[i][j] << " ";
		}
		cout << endl;
	}
}