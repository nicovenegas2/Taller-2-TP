#include "CpuAssign.h"
#include <iostream>
using namespace std;

CpuAssign::CpuAssign(int n){
	this->size = n;
	this->generateTimes();
	this->porVisitar = new Container();
	this->visitando = new Container();
	this->minCuote = 0;
}

void CpuAssign::generateTimes(){
	int **times = new int*[this->size];
	for(int i = 0; i < this->size; i++){
		times[i] = new int[this->size];
	}
	for(int i = 0; i < this->size; i++){
		for(int j = 0; j < this->size; j++){
			times[i][j] = rand() % 10;
		}
	}
	this->times = times;
}

void CpuAssign::solve(){
	
	
}