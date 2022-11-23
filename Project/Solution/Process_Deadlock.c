/*
* Created By
*	Tyler Besnoff
*	Lucas Lecler
*	2022
*
*
*/

#include <stdio.h>
#include <stdlib.h>

/*
* Check for deadlock
*   This function is to check if a given scenario runs into deadlock
*   Function will return a int* of two ints where the first int is the process that causes deadlock and the second int is the flag
*       *Process causing deadlock will start at 0 for the first process
*       *Process causing deadlock will show as -1 if the flag is showing no deadlock
*       *Flag will be set to 0 for deadlock and 1 for no deadlock
* 
*/
int* CheckForDeadlock(int numberOfProcesses, processes max, processes alloc, fake_resources avail) {

    int i, j, k;

    int *finalOutput=NULL;
    finalOutput = malloc(2 * sizeof(int));

    int flagArr[numberOfProcesses], ans[numberOfProcesses], ind = 0;
    for (k = 0; k < numberOfProcesses; k++) {
        flagArr[k] = 0;
    }
    int need[numberOfProcesses][numberOfResources];
    for (i = 0; i < numberOfProcesses; i++) {
        for (j = 0; j < numberOfResources; j++)
            need[i][j] = returnResourceValue(j,max.resources[i]) - returnResourceValue(j, alloc.resources[i]);
    }
    int y = 0;
    for (k = 0; k < 5; k++) {
        for (i = 0; i < numberOfProcesses; i++) {
            if (flagArr[i] == 0) {

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
                    flagArr[i] = 1;
                }
            }
        }
    }

    int flag = 1;

    for (int i = 0; i < numberOfProcesses; i++)
    {
        if (flagArr[i] == 0)
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



