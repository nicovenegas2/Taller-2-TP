#include "CpuAssign.h"
#include <iostream>
using namespace std;

int main(){
    cout << "Hello CPU" << endl;
    CpuAssign cpu(5);
    cpu.generateTimes();
    cpu.print();
    cpu.solve();
    return 0;
}