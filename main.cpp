#include <iostream>
#include "MC_Estimation_12Queen.h"

int main() {
    int n = 12;
    int steps = 100;
    int nodes = 0, total = 0, i = 0;
    for (i = 1; i <= steps; i++) {
        nodes = QueenMC(n);
        total += nodes;
        if (i % 10 == 0) cout << "step: " << i << " --- numnodes = " << nodes << endl;
    }
    cout << "total nodes = " << total << endl << "avg = " << total/steps << endl;
    return 0;
}