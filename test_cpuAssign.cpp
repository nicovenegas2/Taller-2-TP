#include "CpuAssign.h"
#include <iostream>
using namespace std;

int main(){
    unsigned t1, t2;
    cout << "Hello CPU" << endl;
    CpuAssign cpu(00);
    cout << "despues de generar cpu" << endl;
    cpu.generateTimes();
    cout << "despues de generar times" << endl;
    cpu.print();
    cout << "------------------------------------" << endl;
    t1 = clock();
    cpu.solve(true);
    t2 = clock();
    cout << "Time: " << (t2 - t1) / (double)CLOCKS_PER_SEC << endl;
    return 0;
}