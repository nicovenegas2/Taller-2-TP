#include "Container.h"
#include <iostream>

class CpuAssign
{
private:
    int **times;
    Container *visitando;
    Container *porVisitar;
    int size;
    int minCuote;


public:
    CpuAssign(int n);
    ~CpuAssign();
    void generateTimes();
    void solve();
    int getCuote(int start);
};
