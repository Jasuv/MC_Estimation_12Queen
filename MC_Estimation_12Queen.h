#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <random>

#ifndef MC_ESTIMATION_12QUEEN_H
#define MC_ESTIMATION_12QUEEN_H

using namespace std;

// return a random node from prom_children
int randomNode(int* prom_children, int size);
/*
randNum = generate a randnum [1-n]
if prom_children[randNum] == 0 randomize again
return randNum
*/

// return is position promising
bool promising(int* col, int k, int i); 
/*
for j = 1 to k-1
    if ((col[j] = i) // checks vertically
        or (|col[j]-i| = |j-k|)) // checks horizontally/diagonally
        return false
return true
*/

// uses Monte Carlo's algorithm to estimate the number of nodes in n-Queens problem
int QueenMC(int n);
/*
numnodes = 1; m = 1; mprod = 1; i=0; // ith row of chessboard
while (m != 0 && i != n) {
    mprod = mprod * m;
    numnodes = numnodes + mprod * n; // Number of children t is n in n-Queens
    i++;
    // compute promising nodes in level i
    m = 0;
    prom_children = ⊘ ;     // Initialize set of promising nodes
    for (j = 1; j <= n; j++) {
        col[i] = j;. // keep tracks of placement of i th queens
        if (promising (i, j)) { // Determine promising children
            m++;
        prom_children = prom_children ∪ {j};
        }
    }
    if (m != 0) {
        j = random selection from prom_children;
        col[i] = j;
    }
}// end while loop
return numnodes;
*/
#endif