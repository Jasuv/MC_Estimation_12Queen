#include <iostream>
#include "MC_Estimation_12Queen.h"

int main() {
    int n = 12;
    int steps = 100;
    int ret = 0, tot = 0, i = 0;
    for (i = 1; i <= steps; i++) {
        ret = QueenMC(n);
        tot += ret;
        if (i % 10 == 0) cout << "step: " << i << " --- numnodes = " << ret << endl;
    }
    cout << "tot = " << tot << " --- avg = " << tot/steps << endl;
    return 0;
}