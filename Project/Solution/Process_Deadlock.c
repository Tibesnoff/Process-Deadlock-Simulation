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

int* CheckForDeadlock(int numberOfProcesses, int numberOfResources, processes max, processes alloc, fake_resources avail) {

    int i, j, k;

    int *finalOutput=NULL;
    finalOutput = malloc(2 * sizeof(int));

    int f[numberOfProcesses], ans[numberOfProcesses], ind = 0;
    for (k = 0; k < numberOfProcesses; k++) {
        f[k] = 0;
    }
    int need[numberOfProcesses][numberOfResources];
    for (i = 0; i < numberOfProcesses; i++) {
        for (j = 0; j < numberOfResources; j++)
            need[i][j] = returnResourceValue(j,max.resources[i]) - returnResourceValue(j, alloc.resources[i]);
    }
    int y = 0;
    for (k = 0; k < 5; k++) {
        for (i = 0; i < numberOfProcesses; i++) {
            if (f[i] == 0) {

                int flag = 0;
                for (j = 0; j < numberOfResources; j++) {
                    if (need[i][j] > returnResourceValue(j,avail)) {
                        flag = 1;
                        break;
                    }
                }

                if (flag == 0) {
                    ans[ind++] = i;
                    for (y = 0; y < numberOfResources; y++)
                        modifyResources(y, &avail, returnResourceValue(y, alloc.resources[i]));
                    f[i] = 1;
                }
            }
        }
    }

    int flag = 1;

    for (int i = 0; i < numberOfProcesses; i++)
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

int returnResourceValue(int resource, fake_resources p) {
    if (resource == 0)return p.RAM;
    if (resource == 1)return p.NET;
    return p.DISK;
}

void* modifyResources(int resource, fake_resources* p, int val) {
    if (resource == 0)(*p).RAM += val;
    if (resource == 1)(*p).NET += val;
    (*p).DISK += val;
}

// Create Allocation Matrix, will be provided

// Create Max Matrix, will be provided



