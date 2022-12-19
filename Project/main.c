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
#define flag 1
#define deadlocked 0

void* runRemoval(int numberOfProcesses, int* output, processes max, processes alloc, fake_resources avail) {
    int smallestRemove = RemoveSmallestAllocated(numberOfProcesses, output, max, alloc, avail);

    printf("\n   Smallest process to remove: %d", smallestRemove);

    int largestRemove = RemoveLargestAllocated(numberOfProcesses, output, max, alloc, avail);

    printf("\n   Largest process to remove: %d", largestRemove);
}

int main(int argc, char** argv) {
    if (argc < 2) {
        fprintf(stderr, "Error: Insufficient arguments.\n");
        return -1;
    }
    int arg = atoi(argv[1]);

    int numberOfProcesses;

    if (arg == 0) {
        numberOfProcesses = 5;
        fake_resources maxResources[5] = {{3,1,4}, {2,4,1}, {3,5,4}, {2,2,2}, {5,4,3}};
        processes max = { maxResources };
        fake_resources allocResources[5] =  {{1,0,1}, {2,2,0}, {3,3,2}, {0,0,1}, {5,0,3}};
        processes alloc = { allocResources };
        fake_resources avail = {2, 1, 0};
        int* output = CheckForDeadlock(5, max, alloc, avail);

        printf(" Process Causing Deadlock: %d Deadlock?: %d ", output[deadlocked], output[flag]);

        for (int i = 0; i < numberOfProcesses; i++) {
            printf("\n  i: %d Result: %d", i, output[(i + bufferspace)]);
        }
        if (output[flag] == 0) {
            runRemoval(numberOfProcesses, output, max, alloc, avail);
        }
        
    }
    if (arg == 1) {
        numberOfProcesses = 5;
        fake_resources maxResources[5] = {{4,4,3}, {1,0,1},{3,3,2},{4,0,3},{2,1,2}};
        processes max = { maxResources };
        fake_resources allocResources[5] = {{3,4,2}, {1,0,0}, {2,2,0}, {0,0,3}, {1,1,2}};
        processes alloc = { allocResources };
        fake_resources avail = {0, 0, 1};
        int* output = CheckForDeadlock(numberOfProcesses, max, alloc, avail);

        printf(" Process Causing Deadlock: %d Deadlock?: %d ", output[deadlocked], output[flag]);

        for (int i = 0; i < numberOfProcesses; i++) {
            printf("\n  i: %d Result: %d", i, output[(i + bufferspace)]);
        }

        if (output[flag] == 0) {
            runRemoval(numberOfProcesses, output, max, alloc, avail);
        }
    }
    if (arg == 2) {
        numberOfProcesses = 3;
        fake_resources maxResources[3] = { {12,12,12}, {6,3,4}, {7,5,7} };
        processes max = { maxResources };
        fake_resources allocResources[3] = { {4,7,2}, {6,1,3}, {0,2,5} };
        processes alloc = { allocResources };
        fake_resources avail = {2,2,2};
        int* output = CheckForDeadlock(numberOfProcesses, max, alloc, avail);

        printf(" Process Causing Deadlock: %d Deadlock?: %d ", output[deadlocked], output[flag]);

        for (int i = 0; i < numberOfProcesses; i++) {
            printf("\n  i: %d Result: %d", i, output[(i + bufferspace)]);
        }

        if (output[flag] == 0) {
            runRemoval(numberOfProcesses, output, max, alloc, avail);
        }
    }
    if (arg == 3) {
        numberOfProcesses = 7;
        fake_resources maxResources[7] = { {2,2,6}, {3,2,1}, {3,3,5}, {1,4,4}, {2,3,2}, {4,3,1}, {1,2,5} };
        processes max = { maxResources };
        fake_resources allocResources[7] = { {1,1,4}, {0,2,0}, {3,3,3}, {1,2,2}, {2,0,0}, {3,2,1}, {0,0,5} };
        processes alloc = { allocResources };
        fake_resources avail = { 1,2,0 };
        int* output = CheckForDeadlock(numberOfProcesses, max, alloc, avail);

        printf(" Process Causing Deadlock: %d Deadlock?: %d ", output[deadlocked], output[flag]);

        for (int i = 0; i < numberOfProcesses; i++) {
            printf("\n  i: %d Result: %d", i, output[(i + bufferspace)]);
        }

        if (output[flag] == 0) {
            runRemoval(numberOfProcesses, output, max, alloc, avail);
        }
    }
    if (arg == 4) {
        numberOfProcesses = 7;
        fake_resources maxResources[7] = { {1, 2, 1}, {11, 8, 0}, {9, 1, 8}, {7, 8, 4}, {0, 0, 1}, {2, 0, 0}, {8, 8, 10} };
        processes max = { maxResources };
        fake_resources allocResources[7] = { {1,0,0}, {1,2,0}, {3,0,2}, {2,3,1}, {0,0,0}, {1,0,0}, {2,1,6} };
        processes alloc = { allocResources };
        fake_resources avail = { 1,2,1 };
        int* output = CheckForDeadlock(numberOfProcesses, max, alloc, avail);

        printf(" Process Causing Deadlock: %d Deadlock?: %d ", output[deadlocked], output[flag]);

        for (int i = 0; i < numberOfProcesses; i++) {
            printf("\n  i: %d Result: %d", i, output[(i + bufferspace)]);
        }

        if (output[flag] == 0) {
            runRemoval(numberOfProcesses, output, max, alloc, avail);
        }
    }
    if (arg == 5) {
        numberOfProcesses = 6;
        fake_resources maxResources[6] = { {2 ,2, 1}, {9, 9, 5}, {14, 11, 15}, {2, 1, 0}, {3, 4, 4}, {7, 4, 3}};
        processes max = { maxResources };
        fake_resources allocResources[6] = { {2, 2, 0}, {4, 5, 2}, {8, 7, 9}, {1, 0, 0}, {1, 3, 4}, {2, 3, 3} };
        processes alloc = { allocResources };
        fake_resources avail = { 0, 1, 1};
        int* output = CheckForDeadlock(numberOfProcesses, max, alloc, avail);

        printf(" Process Causing Deadlock: %d Deadlock?: %d ", output[deadlocked], output[flag]);

        for (int i = 0; i < numberOfProcesses; i++) {
            printf("\n  i: %d Result: %d", i, output[(i + bufferspace)]);
        }

        if (output[flag] == 0) {
            runRemoval(numberOfProcesses, output, max, alloc, avail);
        }
    }



    return 0;
}