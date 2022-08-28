#include "Container.h"
#include <iostream>

class CpuAssign
{
    /*
    Estructura de datos que representa la asignacion de cpus a 
    distintas tareas para obtener un menor tiempo
    contiene la matriz de costos y 2 contenedores de nodos
    */
private:
    int **times;
    Container *visitando;
    Container *porVisitar;
    int size;
    int minCuote;


public:
    CpuAssign(int n);
    ~CpuAssign();
    int isNotNewCost(int i, int j, int** times);
    void generateTimes();
    void solve(bool print);
    int getCuote(Node* node,int start);
    int getMinArray(Node *node, int row);
    void print();
    void visit(Node *node);
};
