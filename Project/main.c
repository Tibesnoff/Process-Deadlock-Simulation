#include <stdio.h>
#include <stdlib.h>
#include "oslabs.h"

int main(int argc, char* argv) {
    if (argc < 2) {
        fprintf(stderr, "Error: Insufficient arguments.\n");
        return -1;
    }
    int arg = atoi(argv[1]);

    return 0;
}