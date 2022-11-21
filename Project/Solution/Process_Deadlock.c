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
//#include "../oslabs.h"

int* BankersAlgorithm(int n, int m, process max, process alloc, fake_resources avail) {

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
            need[i][j] = returnValue(j,max.resources[i]) - returnValue(j, alloc.resources[i]);
    }
    int y = 0;
    for (k = 0; k < 5; k++) {
        for (i = 0; i < n; i++) {
            if (f[i] == 0) {

                int flag = 0;
                for (j = 0; j < m; j++) {
                    if (need[i][j] > returnValue(j,avail)) {
                        flag = 1;
                        break;
                    }
                }

                if (flag == 0) {
                    ans[ind++] = i;
                    for (y = 0; y < m; y++)
                        modifyProcess(y, &avail, returnValue(y, alloc.resources[i]));
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
            finalOutput[0] = i; //This will show processes starting with 0 as the first process
            finalOutput[1] = flag;
        }
    }

    if (flag == 1) {
        finalOutput[0] = -1;
        finalOutput[1] = flag;
    }

    return finalOutput;
}

int returnValue(int resource, fake_resources p) {
    if (resource == 0)return p.RAM;
    if (resource == 1)return p.NET;
    return p.DISK;
}

void* modifyProcess(int resource, fake_resources* p, int val) {
    if (resource == 0)(*p).RAM += val;
    if (resource == 1)(*p).NET += val;
    (*p).DISK += val;
}

// Create Allocation Matrix, will be provided

// Create Max Matrix, will be provided



