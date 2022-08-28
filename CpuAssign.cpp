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
	this->minCuote = 1000000;
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
	int pos;
	for(int i = pointer; i < this->size; i++){
		pos = node->getAvailables()[i];
		if (this->times[row][pos] < min){
			min = this->times[row][pos];

		}
	}
	return min;
}

int CpuAssign::getCuote(Node* node,int start){ //entrega la aproximacion para un nodo desde un inicio
	int cuote = 0;
	int pos;
	for(int i=0; i<start; i++){
		pos = node->getData()[i];
		cuote += this->times[start][pos];
	}
	for(int i = start; i < this->size; i++){
		cuote += this->getMinArray(node, i);
	}
	return cuote;
}


// visita un nodo y marca todas las posibles combinaciones para la proxima asignacion
// se obtiene la menor cuota y se descartan las posibles combinaciones que no cumplan con la cuota minima
void CpuAssign::visit(Node *nodeVisit){
	Node *node = nodeVisit;
	int pointer = node->getAvailablePointer();
	int *availables = node->getAvailables();
	int cuote = 0;
	for (int i = pointer; i < this->size; i++)
	{
		node->markAvailable(i);
		node->setCost(this->getCuote(node, pointer));
		// cout << "cuote: " << node->getCost() << endl;
		// cout << "cuote min: " << this->minCuote << endl;
		cuote = node->getCost();
		if (cuote < this->minCuote){
			this->minCuote = cuote;
			this->porVisitar->clear();
			this->porVisitar->add(new Node(node, i));
		}
		else if (cuote == this->minCuote){
			this->porVisitar->add(new Node(node, i));
		}
		node->unmarkAvailable();
	}
}


// solucionar el problema de asignacion de cpu
void CpuAssign::solve(bool print){
	Node *node = new Node(this->size);
	Node *nodeVisit;
	this->visit(node);
	while(!this->porVisitar->isEmpty()){

		this->visitando->swap(this->porVisitar);
		this->porVisitar->clear();
		this->visitando->markWaitNodes();
		this->minCuote = 10000000; // nos aseguramos de guardar la primera por anchura

		while(!this->visitando->isEmpty()){
		nodeVisit = this->visitando->pull();
		this->visit(nodeVisit);
		}
		nodeVisit->printData();
	}
	cout << "cuote: " << nodeVisit->getCost()  << endl;
	if(print){
		for (int i = 0; i < this->size; i++){
			cout << "Cpu " << i << ": " << nodeVisit->getData()[i] << endl;
		}
	}
	

}


// imprimir el arreglo de costos
void CpuAssign::print(){
	for(int i = 0; i < this->size; i++){
		for(int j = 0; j < this->size; j++){
			cout << this->times[i][j] << " ";
		}
		cout << endl;
	}
}



/*
* Check if the cost is already in the matrix row from the left of j
*/
int CpuAssign::isNotNewCost(int i, int j, int** times) {
    for (int k = 0; k < j; k++) {
        if (times[i][j] == times[i][k]) {
            return 1;
        }
    }
    return 0;
}

/* Generate a random cost matrix with values between 1 and N
   with no repetition by row.
*/
void CpuAssign::generateTimes() {
	srand(time(NULL));

    // this allows this method to be reentrant
    int **times = new int*[this->size];
    times = new int*[size];
    for (int i = 0; i < size; i++) {
        times[i] = new int[size];
    }
    // generating a random cost matrix with 1/5 of possible repetition by column
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            times[i][j] = 1+rand() % (size+size/5+1);
            while (isNotNewCost(i, j, times)) {
                times[i][j] = 1+rand() % (size+size/5+1);
            }
        }
    }

    // overrriding 1/5 of the matrix by the number N/5 without repetition by row
    int k = 0;
    while(k<size/5) {
        int i = rand() % size;
        int j = rand() % size;
        int backup=times[i][j];
        times[i][j]=size/5;
        if (!isNotNewCost(i, j, times)) {
            //cout << i << " " << j << endl;
            k++;
        } else {
            times[i][j]=backup;
        }
    }
	this->times = times;
}
