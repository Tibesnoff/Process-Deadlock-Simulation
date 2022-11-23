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
*   Process the test cases
*/

#include <stdio.h>
#include <stdlib.h>
#include "oslabs.h"
#include "Solution/Process_Deadlock.c"

int correctlyFoundDeadlock (int* expectedOutput, int* receivedOutput) {
    int error = 0; //0 for passing 
    if (expectedOutput[1] != receivedOutput[1])error = 1;
    if (error && expectedOutput[1] == 0)printf("Deadlock detection function gave: %d which means no deadlock was found\nCorrect output should be %d which means deadlock was found\n", receivedOutput[1], expectedOutput[1]);
    if (error && expectedOutput[1] == 1)printf("Deadlock detection function gave: %d which means deadlock was found\nCorrect output should be %d which means deadlock was not found\n", receivedOutput[1], expectedOutput[1]);
    if (expectedOutput[0] != receivedOutput[0])error = 2;
    if (error && expectedOutput[0] > -1)printf("Deadlock detection function claims deadlock occured with process: %d\nScenario deadlocks from process: %d\n", receivedOutput[0], expectedOutput[0]);

    return error;
}

int main(int argc, char** argv) {
    if (argc < 2) {
        fprintf(stderr, "Error: Insufficient arguments.\n");
        return -1;
    }
    int arg = atoi(argv[1]);
    int* expectedOutput = NULL;
    expectedOutput = malloc(2 * sizeof(int));

    if (arg == 0) {
        fake_resources maxResources[5] = {{3,1,4}, {2,4,1}, {3,5,4}, {2,2,2}, {5,4,3}};
        processes max = { maxResources };
        fake_resources allocResources[5] =  {{1,0,1}, {2,2,0}, {3,3,2}, {0,0,1}, {5,0,3}};
        processes alloc = { allocResources };
        fake_resources avail = {2, 1, 0};
        
        expectedOutput[0] = 4;
        expectedOutput[1] = 0;
        printf("Error Code: %d",correctlyFoundDeadlock(expectedOutput, CheckForDeadlock(5, max, alloc, avail)));
        /*int* output = CheckForDeadlock(5, max, alloc, avail);

        printf(" Process Causing Deadlock: %d Deadlock?: %d ", output[0], output[1]);*/
    }
    if (arg == 1) {
        fake_resources maxResources[5] = {{4,4,3}, {1,0,1},{3,3,2},{4,0,3},{2,1,2}};
        processes max = { maxResources };
        fake_resources allocResources[5] = {{3,4,2}, {1,0,0}, {2,2,0}, {0,0,3}, {1,1,2}};
        processes alloc = { allocResources };
        fake_resources avail = {0, 0, 1};

        expectedOutput[0] = -1;
        expectedOutput[1] = 1;
        printf("Error Code: %d", correctlyFoundDeadlock(expectedOutput, CheckForDeadlock(5, max, alloc, avail)));
       /* int* output = CheckForDeadlock(5, max, alloc, avail);

        printf(" Process Causing Deadlock: %d Deadlock?: %d ", output[0], output[1]);*/
    }
    if (arg == 2) {
        fake_resources maxResources[4] = { {4,3,4}, {1,2,2}, {1,1,0}, {8,7,6} };
        processes max = { maxResources };
        fake_resources allocResources[4] = { {2,0,1}, {1,1,0}, {0,1,0}, {4,3,3} };
        processes alloc = { allocResources };
        fake_resources avail = { 1, 1, 2 };

        expectedOutput[0] = 3;
        expectedOutput[1] = 0;
        printf("Error Code: %d", correctlyFoundDeadlock(expectedOutput, CheckForDeadlock(4, max, alloc, avail)));

        /*int* output = CheckForDeadlock(4, max, alloc, avail);

        printf("Process Causing Deadlock: %d Deadlock?: %d", output[0], output[1]);*/
    }
    if (arg == 3) {
        fake_resources maxResources[3] = {{12,12,12}, {6,3,4}, {7,5,7}};
        processes max = { maxResources };
        fake_resources allocResources[3] = { {4,7,2}, {6,1,3}, {0,2,4} };
        processes alloc = { allocResources };
        fake_resources avail = {2,2,2};

        expectedOutput[0] = -1;
        expectedOutput[1] = 1;
        printf("Error Code: %d", correctlyFoundDeadlock(expectedOutput, CheckForDeadlock(3, max, alloc, avail)));

        /*int* output = CheckForDeadlock(3, max, alloc, avail);

        printf("Process Causing Deadlock: %d Deadlock?: %d", output[0], output[1]);*/
    }
    

    return 0;
}