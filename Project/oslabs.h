/*
* Created By
*	Tyler Besnoff
*	Lucas Lecler
*	2022
*/

//Magic number definitions
#define numberOfResources 3
#define bufferspace 2

//Structs
typedef struct {
	int RAM;
	int NET;
	int DISK;
}fake_resources;

typedef struct {
	fake_resources *resources;
}processes;

//Helper functions
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

//Headers to complete
void* modifyResources(int resource, fake_resources* p, int val);
int returnResourceValue(int resource, fake_resources p);
int* CheckForDeadlock(int numberOfProcesses, processes max, processes alloc, fake_resources avail);
int RemoveSmallestAllocated(int numberOfProcesses, int* deadlockedResult, processes max, processes alloc, fake_resources avail);
int RemoveLargestAllocated(int numberOfProcesses, int* deadlockedResult, processes max, processes alloc, fake_resources avail);


