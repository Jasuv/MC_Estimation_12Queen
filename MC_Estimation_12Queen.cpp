#include "MC_Estimation_12Queen.h"

int randomNode(int* prom_children, int size) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<mt19937::result_type> dist(1, size);
    int randNum = dist(gen);
    while (prom_children[randNum] == 0) randNum = dist(gen);
    return randNum;
}

bool promising(int* col, int k, int i) {
    for (int j = 1; j < k; j++) {
        if ((col[j] == i) || (abs(col[j]-i) == abs(j-k))) {
            return false;
        }
    }
    return true;
}

int QueenMC(int n) {
    int* col = new int[n+1]();
    int i = 0, j = 1; 
    int numnodes = 1, m = 1, mprod = 1;
    while ((m != 0) && (i != n)) {
        mprod *= m;
        numnodes += (mprod * n);
        i++;
        m = 0;
        int* prom_children = new int[n+1]();
        for (j = 1; j <= n; j++) {
            col[i] = j;
            if (promising (col, i, j)) {
                m++;
                prom_children[j] = 1;
            }
        }
        if (m != 0) {
            j = randomNode(prom_children, n);
            col[i] = j;
        }
        delete[] prom_children;
    }
    delete[] col;
    return numnodes;
}