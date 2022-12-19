/*
* Created By
*	Tyler Besnoff
*	Lucas Lecler
*	2022
*
*Completed
*   Check for deadlock
*
*Still needed
*   Function to process given scenario
*   Satisfy lowest needed resources with ending smallest resource process that can give resources to the first process
*   Satisfy lowest needed resources with ending highest resource process that can give resources to the first process
*/

#include <stdio.h>
#include <stdlib.h>
#include "oslabs.h"
#include "Solution/Process_Deadlock.c"

void* callRemoveTests(int* output, int numberOfProcesses, int deadlockedProcess, processes max, processes alloc, fake_resources avail) {
    printf("\n Call to Remove Smallest Allocated - Removed process: %d", RemoveSmallestAllocated(numberOfProcesses, deadlockedProcess, &max, &alloc, &avail));

    output = CheckForDeadlock(numberOfProcesses-1, max, alloc, avail);

    printf(" Process Causing Deadlock: %d Deadlock?: %d ", output[0], output[1]);

    printf("\n Call to Remove Largest Allocated - Removed process: %d", RemoveLargestAllocated(numberOfProcesses, deadlockedProcess, &max, &alloc, &avail));

    output = CheckForDeadlock(numberOfProcesses-1, max, alloc, avail);

    printf(" Process Causing Deadlock: %d Deadlock?: %d ", output[0], output[1]);
}

int main(int argc, char** argv) {
    if (argc < 2) {
        fprintf(stderr, "Error: Insufficient arguments.\n");
        return -1;
    }
    int arg = atoi(argv[1]);

    if (arg == 0) {
        fake_resources maxResources[5] = {{3,1,4}, {2,4,1}, {3,5,4}, {2,2,2}, {5,4,3}};
        processes max = { maxResources };
        fake_resources allocResources[5] =  {{1,0,1}, {2,2,0}, {3,3,2}, {0,0,1}, {5,0,3}};
        processes alloc = { allocResources };
        fake_resources avail = {2, 1, 0};
        int* output = CheckForDeadlock(5, max, alloc, avail);

        printf(" Process Causing Deadlock: %d Deadlock?: %d ", output[0], output[1]);

        if (output[1] == 0) {
            callRemoveTests(output, 5, output[0], max, alloc, avail);
        }
        
    }
    if (arg == 1) {
        fake_resources maxResources[5] = {{4,4,3}, {1,0,1},{3,3,2},{4,0,3},{2,1,2}};
        processes max = { maxResources };
        fake_resources allocResources[5] = {{3,4,2}, {1,0,0}, {2,2,0}, {0,0,3}, {1,1,2}};
        processes alloc = { allocResources };
        fake_resources avail = {0, 0, 1};
        int* output = CheckForDeadlock(5, max, alloc, avail);

        printf(" Process Causing Deadlock: %d Deadlock?: %d ", output[0], output[1]);

        if (output[1] == 0) {
            callRemoveTests(output, 5, output[0], max, alloc, avail);
        }
    }
    if (arg == 2) {
        fake_resources maxResources[3] = { {12,12,12}, {6,3,4}, {7,5,7} };
        processes max = { maxResources };
        fake_resources allocResources[3] = { {4,7,2}, {6,1,3}, {0,2,5} };
        processes alloc = { allocResources };
        fake_resources avail = {2,2,2};
        int* output = CheckForDeadlock(3, max, alloc, avail);

        printf("Process Causing Deadlock: %d Deadlock?: %d", output[0], output[1]);

        if (output[1] == 0) {
            callRemoveTests(output, 5, output[0], max, alloc, avail);
        }
    }
    if (arg == 3) {
        fake_resources maxResources[7] = { {2,2,6}, {3,2,1}, {3,3,5}, {1,4,4}, {2,3,2}, {4,3,1}, {1,2,5} };
        processes max = { maxResources };
        fake_resources allocResources[7] = { {1,1,4}, {0,2,0}, {3,3,3}, {1,2,2}, {2,0,0}, {3,2,1}, {0,0,5} };
        processes alloc = { allocResources };
        fake_resources avail = { 1,2,0 };
        int* output = CheckForDeadlock(7, max, alloc, avail);

        printf("Process Causing Deadlock: %d Deadlock?: %d", output[0], output[1]);

        if (output[1] == 0) {
            callRemoveTests(output, 5, output[0], max, alloc, avail);
        }
    }
    

    return 0;
}