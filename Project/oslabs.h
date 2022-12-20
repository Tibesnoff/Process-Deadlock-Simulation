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

//Headers to complete
void* modifyResources(int resource, fake_resources* p, int val);
int returnResourceValue(int resource, fake_resources p);
int* CheckForDeadlock(int numberOfProcesses, processes max, processes alloc, fake_resources avail);
int RemoveSmallestAllocated(int numberOfProcesses, int* deadlockedResult, processes max, processes alloc, fake_resources avail);
int RemoveLargestAllocated(int numberOfProcesses, int* deadlockedResult, processes max, processes alloc, fake_resources avail);


