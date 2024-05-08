#include "MC_Estimation_12Queen.h"

int randomNode(int* prom_children, int size) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<mt19937::result_type> dist(1, size);
    return dist(gen);
}

bool promising(int* col, int i) {
    int j;
    for (j = 1; j < i; j++) {
        if ((col[i] == col[j]) || (abs(col[i]-col[j]) == abs(i-j))) {
            return false;
        }
    }
    return true;
}

int QueenMC(int n) {
    int* col = new int[n+1]();
    int i = 0, j = 0; 
    int numnodes = 1, m = 1, mprod = 1;
    while ((m != 0) && (i != n)) {
        mprod *= m;
        numnodes += (mprod * n);
        i++;
        // compute the promising nodes in level i
        m = 0;
        int* prom_children = new int[n+1]();
        for (j = 1; j <= n; j++) {
            col[i] = j;
            if (promising (col, i)) {
                m++;
                prom_children[j] = 1;
            }
        }
        if (m != 0) {
            j = randomNode(prom_children, n);
            while (prom_children[j] == 0) j = randomNode(prom_children, n);
            col[i] = j;
        }
        delete[] prom_children;
    }
    delete[] col;
    return numnodes;
}