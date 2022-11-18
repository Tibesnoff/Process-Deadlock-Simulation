#include <stdio.h>
#include <stdlib.h>
#include "oslabs.h"
#include "Solution/Process_Deadlock.c"

int main(int argc, char** argv) {
    if (argc < 2) {
        fprintf(stderr, "Error: Insufficient arguments.\n");
        return -1;
    }
    int arg = atoi(argv[1]);

    if (arg == 0) {

        //This will deadlock
        int max[5][3] = {{3, 1, 4} ,{2, 4, 1},{3, 5, 4},{2, 2, 2},{5, 4, 3}};

        int alloc[5][3] = { {1,0,1},{2,2,0},{3,3,2},{0,0,1},{5,0,3} };

        int avail[3] = { 2,1,0 };

        int* output = BankersAlgorithm(5, 3, max, alloc, avail);

        printf(" %d %d ", output[0], output[1]);
        //end of test that deadlocks
    }
    if (arg == 1) {
        //This will not deadlock
        int max[5][3] = { {4, 4, 3} ,{1, 0, 1},{3, 3, 2},{4, 0, 3},{2, 1, 2} };

        int alloc[5][3] = { {3,4,2},{1,0,0},{2,2,0},{0,0,3},{1,1,2} };

        int avail[3] = { 0,0,1 };

        int* output = BankersAlgorithm(5, 3, max, alloc, avail);

        printf(" % d % d ", output[0], output[1]);

        //End test
    }

    return 0;
}