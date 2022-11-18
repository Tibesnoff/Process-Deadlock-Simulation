/*
* Created By
*	Tyler Besnoff
*	Lucas Lecler
*	2022
*
* 
*
*
*
*/

//Bankers Algorithm  
// Needs: Stuct of Available Resources, Allocation Matrix, Number of process, Number of resources, Max matrix, 
// Will return a struct with a resource that causes fault if flag is 0 and an int flag either 1 for passing and 0 for not passing

#include <stdio.h>
#include <stdlib.h>
#include "../oslabs.h"

int main(int argc, char* argv) {

    fake_resources = malloc(3 * sizeof(int));

    int max[5][3]={ {3, 1, 4} ,{2, 4, 1},{3, 5, 4},{2, 2, 2},{5, 4, 3} };

    int alloc[5][3]={ {1,0,1},{2,2,0},{3,3,2},{0,0,1},{5,0,3} };

    int avail[3] = { 2,1,0 };

    int* output = BankersAlgorithm(5, 3, max, alloc, avail);

    printf(" % d % d ", output[0], output[1]);

    return 1;
}

int* BankersAlgorithm(int n, int m, int max[5][3], int alloc[5][3], int avail[3]) {

    int i, j, k;

    int *finalOutput=NULL;
    finalOutput = malloc(2 * sizeof(int));

    int f[n], ans[n], ind = 0;
    for (k = 0; k < n; k++) {
        f[k] = 0;
    }
    int need[n][m];
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];
    }
    int y = 0;
    for (k = 0; k < 5; k++) {
        for (i = 0; i < n; i++) {
            if (f[i] == 0) {

                int flag = 0;
                for (j = 0; j < m; j++) {
                    if (need[i][j] > avail[j]) {
                        flag = 1;
                        break;
                    }
                }

                if (flag == 0) {
                    ans[ind++] = i;
                    for (y = 0; y < m; y++)
                        avail[y] += alloc[i][y];
                    f[i] = 1;
                }
            }
        }
    }

    int flag = 1;

    for (int i = 0; i < n; i++)
    {
        if (f[i] == 0)
        {
            flag = 0;
            finalOutput[0] = i;
            finalOutput[1] = flag;
        }
    }

    if (flag == 1) {
        finalOutput[0] = -1;
        finalOutput[1] = flag;
    }

    return finalOutput;
}

// Create Allocation Matrix, will be provided

// Create Max Matrix, will be provided



