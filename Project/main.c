#include <stdio.h>
#include <stdlib.h>
#include "oslabs.h"

int main(int argc, char** argv) {
    if (argc < 2) {
        fprintf(stderr, "Error: Insufficient arguments.\n");
        return -1;
    }
    int arg = atoi(argv[1]);

    //This here is a test which will be deleted when actual code is done. Test ends at next comment
    struct fake_resources R1;

    R1.Disk = 1;
    R1.Net = 1;
    R1.RAM = 1;

    printf("arg: %d\nDisk: %d\nNet: %d\nRAM: %d\n", arg, R1.Disk, R1.Net, R1.RAM);
    //End test

    return 0;
}