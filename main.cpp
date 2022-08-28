#include "CpuAssign.h"
#include <iostream>
#include <ctime>
using namespace std;

int main(){
    unsigned t1, t2, t3;
    int dimension = 300;
    int i;
    CpuAssign cpu(dimension);
    for (i = 0; i < 10; i++){
        cpu.generateTimes();
        // m.print();
        t1 = clock();
        cpu.solve(false);
        t2 = clock();
        cout << "Time: " << (t2 - t1) / (double)CLOCKS_PER_SEC << endl;
        t3 += (t2 - t1);
    }
    cout <<"Dimensión: " << dimension << " How many: " << i << endl;
    cout << "Total resolve time: " << t3 / (double)CLOCKS_PER_SEC << endl;
    cout << "average time: " << t3 / (double)CLOCKS_PER_SEC / i << endl;
    return 0;

}