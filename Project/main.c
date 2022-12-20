/*
* Created By
*	Tyler Besnoff
*	Lucas Lecler
*	2022
*/

#include <stdio.h>
#include <stdlib.h>
#include "oslabs.h"
#include "Solution/Process_Deadlock.c"
#define flag 1
#define deadlocked 0
int correctlyRemovedSmallest(int smallestExpected, int smallestReceived);
int correctlyRemovedLargest(int largestExpected, int largestReceived);

int numberOfProcesses;
int smallestExpected = -1;
int largestExpected = -1;
int error = 0; //Zero means the scenaro passed; Any other number means it failed somewhere


int callRemovalFunctions(int smallestExpected, int largestExpected, int numberOfProcesses, int* output, processes max, processes alloc, fake_resources avail) {
    error = 0;

    int smallestRemove = removeSmallestAllocated(numberOfProcesses, output, max, alloc, avail);
    int smallestRemoveExpected = smallestExpected;

    printf("\nSmallest process to remove: %d", smallestRemove);
    error = correctlyRemovedSmallest(smallestExpected, smallestRemove);

    int largestRemove = removeLargestAllocated(numberOfProcesses, output, max, alloc, avail);
    int largestRemoveExpected = largestExpected;

    printf("\nLargest process to remove: %d", largestRemove);
    error = correctlyRemovedLargest(largestExpected, largestRemove);

    return error;
}

int correctlyRemovedSmallest(int smallestExpected, int smallestReceived) {
    error = 0; 

    if (smallestExpected == smallestReceived)printf("\nYou have correctly removed the smallest process\n");
    else {
        error = 1;
        printf("\nYou did not remove the smallest process\nYou removed process %d   The smallest process is %d\n", smallestReceived, smallestExpected);
    }

    return error;
}

int correctlyRemovedLargest(int largestExpected, int largestReceived) {
    int error = 0;

    if (largestExpected == largestReceived)printf("\nYou have correctly removed the largest process\n");
    else {
        error = 1;
        printf("\nYou did not remove the largest process\nYou removed process %d   The largest process is %d\n", largestReceived, largestExpected);
    }

    return error;
}


int correctlyFoundDeadlock(int* expectedOutput, int* receivedOutput) {
    error = 0;

    if (expectedOutput[1] != receivedOutput[1])error = 1;
    if (error && expectedOutput[1] == 0)printf("\n\nDeadlock detection function gave: %d which means no deadlock was found\nCorrect output should be %d which means deadlock was found\n", receivedOutput[1], expectedOutput[1]);
    else if (error && expectedOutput[1] == 1)printf("\n\nDeadlock detection function gave: %d which means deadlock was found\nCorrect output should be %d which means deadlock was not found\n", receivedOutput[1], expectedOutput[1]);
    else printf("\n\nDeadlock detection function correctly figured out if deadlock occured\n");

    if (expectedOutput[0] != receivedOutput[0])error = 2;
    if (error > 1 && expectedOutput[0] > -1)printf("\nDeadlock detection function claims deadlock occured with process: %d\nScenario deadlocks from process: %d\n", receivedOutput[0], expectedOutput[0]);
    else printf("\nDeadlock detection function correctly found what process causes deadlock\n");

    for (int i = bufferspace; i < numberOfProcesses+bufferspace; i++) {
        if (receivedOutput[i] != expectedOutput[i]) {
            error = 1;
            if (expectedOutput[i] == 0)printf("\nProcess %d should not be completed (=1)\n", (i - bufferspace));
            else if (expectedOutput[i] == 1)printf("\nProcess %d should be completed (=0)\n", (i - bufferspace));
            else printf("\nIllegal number should be a 1 or 0 for process %d\n", (i - bufferspace));
        }
    }

    return error;
}

int testFunctions(int* output, int* outputExpected, int smallestExpected, int largestExpected, int numberOfProcesses, processes max, processes alloc, fake_resources avail) {
    error = 0;
    
    printf("\n*********************************************");
    printf("\n*%-1sProcess Causing Deadlock:%2d Deadlock?: %-3d*", "", output[deadlocked], output[flag]);

    for (int i = 0; i < numberOfProcesses; i++) {
        printf("\n*%-3sProcess %d Result: %-22d*", "", i, output[(i + bufferspace)]);
    }

    printf("\n*********************************************");

    error = correctlyFoundDeadlock(outputExpected, output);

    if (output[flag] == 0) {
        if (error == 0)error = callRemovalFunctions(smallestExpected, largestExpected, numberOfProcesses, output, max, alloc, avail);
        else callRemovalFunctions(smallestExpected, largestExpected, numberOfProcesses, output, max, alloc, avail);
    }

    return error;
}

void* resetTestData() {
    smallestExpected = -1;
    largestExpected = -1;
    error = 0;
}

int main(int argc, char** argv) {
    if (argc < 2) {
        fprintf(stderr, "Error: Insufficient arguments.\n");
        return -1;
    }
    int arg = atoi(argv[1]);

    if (arg == 0) {
        resetTestData();

        numberOfProcesses = 5;
        smallestExpected = 4;
        largestExpected = 4;

        fake_resources maxResources[5] = {{3,1,4}, {2,4,1}, {3,5,4}, {2,2,2}, {5,4,3}};
        processes max = { maxResources };
        fake_resources allocResources[5] =  {{1,0,1}, {2,2,0}, {3,3,2}, {0,0,1}, {5,0,3}};
        processes alloc = { allocResources };
        fake_resources avail = {2, 1, 0};

        int* output = checkForDeadlock(numberOfProcesses, max, alloc, avail);
        int* outputExpected = NULL;
        outputExpected = malloc((numberOfProcesses + bufferspace) * sizeof(int));
        outputExpected[0] = 0;
        outputExpected[1] = 0;
        outputExpected[2] = 0;
        outputExpected[3] = 0;
        outputExpected[4] = 0;
        outputExpected[5] = 0;
        outputExpected[6] = 0;
        outputExpected[7] = 0;

        if (testFunctions(output, outputExpected, smallestExpected, largestExpected, numberOfProcesses, max, alloc, avail)==0)printf("\nPassed test 1\n");
    }
    if (arg == 1) {
        resetTestData();

        numberOfProcesses = 5;
        smallestExpected = 4;
        largestExpected = 4;

        fake_resources maxResources[5] = {{4,4,3}, {1,0,1},{3,3,2},{4,0,3},{2,1,2}};
        processes max = { maxResources };
        fake_resources allocResources[5] = {{3,4,2}, {1,0,0}, {2,2,0}, {0,0,3}, {1,1,2}};
        processes alloc = { allocResources };
        fake_resources avail = {0, 0, 1};
        int* output = checkForDeadlock(numberOfProcesses, max, alloc, avail);
        int* outputExpected = NULL;
        outputExpected = malloc((numberOfProcesses + bufferspace) * sizeof(int));
        outputExpected[0] = -1;
        outputExpected[1] = 1;
        outputExpected[2] = 1;
        outputExpected[3] = 1;
        outputExpected[4] = 1;
        outputExpected[5] = 1;
        outputExpected[6] = 1;
        outputExpected[7] = 1;

        if (testFunctions(output, outputExpected, smallestExpected, largestExpected, numberOfProcesses, max, alloc, avail) == 0)printf("\nPassed test 2\n");
    }
    if (arg == 2) {
        resetTestData();

        numberOfProcesses = 3;
        smallestExpected = -1;
        largestExpected = -1;

        fake_resources maxResources[3] = { {12,12,12}, {6,3,4}, {7,5,7} };
        processes max = { maxResources };
        fake_resources allocResources[3] = { {4,7,2}, {6,1,3}, {0,2,5} };
        processes alloc = { allocResources };
        fake_resources avail = {2,2,2};
        int* output = checkForDeadlock(numberOfProcesses, max, alloc, avail);
        int* outputExpected = NULL;
        outputExpected = malloc((numberOfProcesses + bufferspace) * sizeof(int));
        outputExpected[0] = -1;
        outputExpected[1] = 1;
        outputExpected[2] = 1;
        outputExpected[3] = 1;
        outputExpected[4] = 1;

        if (testFunctions(output, outputExpected, smallestExpected, largestExpected, numberOfProcesses, max, alloc, avail) == 0)printf("\nPassed test 3\n");
    }
    if (arg == 3) {
        resetTestData();

        numberOfProcesses = 7;
        smallestExpected = -1;
        largestExpected = -1;

        fake_resources maxResources[7] = { {2,2,6}, {3,2,1}, {3,3,5}, {1,4,4}, {2,3,2}, {4,3,1}, {1,2,5} };
        processes max = { maxResources };
        fake_resources allocResources[7] = { {1,1,4}, {0,2,0}, {3,3,3}, {1,2,2}, {2,0,0}, {3,2,1}, {0,0,5} };
        processes alloc = { allocResources };
        fake_resources avail = { 1,2,0 };
        int* output = checkForDeadlock(numberOfProcesses, max, alloc, avail);
        int* outputExpected = NULL;
        outputExpected = malloc((numberOfProcesses + bufferspace) * sizeof(int));
        outputExpected[0] = -1;
        outputExpected[1] = 1;
        outputExpected[2] = 1;
        outputExpected[3] = 1;
        outputExpected[4] = 1;
        outputExpected[5] = 1;
        outputExpected[6] = 1;
        outputExpected[7] = 1;
        outputExpected[8] = 1;

        if (testFunctions(output, outputExpected, smallestExpected, largestExpected, numberOfProcesses, max, alloc, avail) == 0)printf("\nPassed test 4\n");
    }
    if (arg == 4) {
        resetTestData();

        numberOfProcesses = 7;
        smallestExpected = -1;
        largestExpected = -1;

        fake_resources maxResources[7] = { {1, 2, 1}, {11, 8, 0}, {9, 1, 8}, {7, 8, 4}, {0, 0, 1}, {2, 0, 0}, {8, 8, 10} };
        processes max = { maxResources };
        fake_resources allocResources[7] = { {1,0,0}, {1,2,0}, {3,0,2}, {2,3,1}, {0,0,0}, {1,0,0}, {2,1,6} };
        processes alloc = { allocResources };
        fake_resources avail = { 1,2,1 };
        int* output = checkForDeadlock(numberOfProcesses, max, alloc, avail);
        int* outputExpected = NULL;
        outputExpected = malloc((numberOfProcesses + bufferspace) * sizeof(int));
        outputExpected[0] = 1;
        outputExpected[1] = 0;
        outputExpected[2] = 1;
        outputExpected[3] = 0;
        outputExpected[4] = 0;
        outputExpected[5] = 0;
        outputExpected[6] = 1;
        outputExpected[7] = 1;
        outputExpected[8] = 0;

        if (testFunctions(output, outputExpected, smallestExpected, largestExpected, numberOfProcesses, max, alloc, avail) == 0)printf("\nPassed test 5\n");
    }
    if (arg == 5) {
        resetTestData();

        numberOfProcesses = 6;
        smallestExpected = 5;
        largestExpected = 2;

        fake_resources maxResources[6] = { {2 ,2, 1}, {9, 9, 5}, {14, 11, 15}, {2, 1, 0}, {3, 4, 4}, {7, 4, 3}};
        processes max = { maxResources };
        fake_resources allocResources[6] = { {2, 2, 0}, {4, 5, 2}, {8, 7, 9}, {1, 0, 0}, {1, 3, 4}, {2, 3, 3} };
        processes alloc = { allocResources };
        fake_resources avail = { 0, 1, 1};
        int* output = checkForDeadlock(numberOfProcesses, max, alloc, avail);
        int* outputExpected = NULL;
        outputExpected = malloc((numberOfProcesses + bufferspace) * sizeof(int));
        outputExpected[0] = 1;
        outputExpected[1] = 0;
        outputExpected[2] = 1;
        outputExpected[3] = 0;
        outputExpected[4] = 0;
        outputExpected[5] = 1;
        outputExpected[6] = 1;
        outputExpected[7] = 0;

        if (testFunctions(output, outputExpected, smallestExpected, largestExpected, numberOfProcesses, max, alloc, avail) == 0)printf("\nPassed test 6\n");
    }

    return 0;
}