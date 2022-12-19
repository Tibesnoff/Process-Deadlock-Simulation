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
* Remove Smallest Allocated
*   This function finds, and removes the process with the smallest allocated total of resources that can satisfy the first process that causeses a deadlock
*   Returns which process was removed
*/
int RemoveSmallestAllocated(int numberOfProcesses, int* deadlockedResult, processes max, processes alloc, fake_resources avail) {
    fake_resources availcp;
    availcp.RAM = avail.RAM;
    availcp.NET = avail.NET;
    availcp.DISK = avail.DISK;
    int deadlockedProcess = deadlockedResult[0];
    fake_resources need = { (max.resources[deadlockedProcess].RAM - alloc.resources[deadlockedProcess].RAM), (max.resources[deadlockedProcess].NET - alloc.resources[deadlockedProcess].NET), (max.resources[deadlockedProcess].DISK - alloc.resources[deadlockedProcess].DISK) };
    int pToRemove = -1;
    int smallestResourceTotal = 1000;
    for (int i = 0; i < numberOfProcesses; i++) {
        if (deadlockedResult[i + bufferspace] == 1) {
            availcp.RAM += alloc.resources[i].RAM;
            availcp.NET += alloc.resources[i].NET;
            availcp.DISK += alloc.resources[i].DISK;
        }
    }
    for (int i = 0; i < numberOfProcesses; i++) {
        if (i == deadlockedProcess)continue;
        if (deadlockedResult[i + bufferspace] == 1) continue;
        int resourceTotal = alloc.resources[i].RAM + alloc.resources[i].NET + alloc.resources[i].DISK;
        if ((resourceTotal < smallestResourceTotal)) {
            if (((alloc.resources[i].RAM + availcp.RAM) >= need.RAM) && ((alloc.resources[i].NET + availcp.NET) >= need.NET) && ((alloc.resources[i].DISK + availcp.DISK) >= need.DISK)) {
                smallestResourceTotal = resourceTotal;
                pToRemove = i;
            }
        }
    }

    return pToRemove;
}


/*
* Remove largest Allocated
*   This function finds, and removes the process with the smallest allocation total of resources based off its max resources needed that can satisfy the process that deadlocks
*   Returns which process was removed
*/
int RemoveLargestAllocated(int numberOfProcesses, int* deadlockedResult, processes max, processes alloc, fake_resources avail) {
    fake_resources availcp;
    availcp.RAM = avail.RAM;
    availcp.NET = avail.NET;
    availcp.DISK = avail.DISK;
    int deadlockedProcess = deadlockedResult[0];
    fake_resources need = { (max.resources[deadlockedProcess].RAM - alloc.resources[deadlockedProcess].RAM), (max.resources[deadlockedProcess].NET - alloc.resources[deadlockedProcess].NET), (max.resources[deadlockedProcess].DISK - alloc.resources[deadlockedProcess].DISK) };
    int pToRemove = -1;
    int largestResourceTotal = 0;
    for (int i = 0; i < numberOfProcesses; i++) {
        if (deadlockedResult[i + bufferspace] == 1) {
            availcp.RAM += alloc.resources[i].RAM;
            availcp.NET += alloc.resources[i].NET;
            availcp.DISK += alloc.resources[i].DISK;
        }
    }
    for (int i = 0; i < numberOfProcesses; i++) {
        if (i == deadlockedProcess)continue;
        if (deadlockedResult[i + bufferspace] == 1) continue;
        int resourceTotal = alloc.resources[i].RAM + alloc.resources[i].NET + alloc.resources[i].DISK;
        if ((resourceTotal > largestResourceTotal)) {
            if (((alloc.resources[i].RAM + availcp.RAM) >= need.RAM) && ((alloc.resources[i].NET + availcp.NET) >= need.NET) && ((alloc.resources[i].DISK + availcp.DISK) >= need.DISK)) {
                largestResourceTotal = resourceTotal;
                pToRemove = i;
            }
        }
    }

    return pToRemove;
}

/*
* Check for deadlock
*   This function is to check if a given scenario runs into deadlock
*   Function will return a int* of two ints where the first int is the process that causes deadlock and the second int is the flag
*       *Process causing deadlock will start at 0 for the first process
*       *Process causing deadlock will show as -1 if the flag is showing no deadlock
*       *Flag will be set to 0 for deadlock and 1 for no deadlock
*       *Make sure avail array is copied and use the copy in this algorithm
* 
*/
int* CheckForDeadlock(int numberOfProcesses, processes max, processes alloc, fake_resources avail) {

    fake_resources availcp;
    availcp.RAM = avail.RAM;
    availcp.NET = avail.NET;
    availcp.DISK = avail.DISK;

    int i, j, k;

    int* finalOutput = NULL;
    finalOutput = malloc((bufferspace + numberOfProcesses) * sizeof(int));

    for (k = 0; k < (numberOfProcesses+2); k++) {
        finalOutput[k] = 0;
    }
    int need[numberOfProcesses][numberOfResources];
    for (i = 0; i < numberOfProcesses; i++) {
        for (j = 0; j < numberOfResources; j++)
            need[i][j] = returnResourceValue(j, max.resources[i]) - returnResourceValue(j, alloc.resources[i]);
    }

    int y = 0;
    for (k = 0; k < numberOfProcesses; k++) {
        for (i = 0; i < numberOfProcesses; i++) {
            if (finalOutput[i+bufferspace] == 0) {

                int flag = 1;
                for (j = 0; j < numberOfResources; j++) {
                    if (need[i][j] > returnResourceValue(j, availcp)) {
                        flag = 0;
                        break;
                    }
                }

                if (flag == 1) {
                    for (y = 0; y < numberOfResources; y++)modifyResources(y, &availcp, returnResourceValue(y, alloc.resources[i]));
                    finalOutput[i+bufferspace] = 1;
                }
            }
        }
    }


    int flag = 1;

    for (int i = 0; i < numberOfProcesses; i++)
    {

        if (finalOutput[i+bufferspace] == 0)
        {
            flag = 0;
            finalOutput[0] = i;
            finalOutput[1] = flag;
            break;
        }
    }

    if (flag == 1) {
        finalOutput[0] = -1;
        finalOutput[1] = flag;
    }

    return finalOutput; // finalOutput [0==deadlocked, 1==flag, flagArr[]]
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



