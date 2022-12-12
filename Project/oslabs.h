/*
* Created By
*	Tyler Besnoff
*	Lucas Lecler
*	2022
*
*/

#define numberOfResources 3

typedef struct {
	int RAM;
	int NET;
	int DISK;
}fake_resources;

typedef struct {
	fake_resources *resources;
}processes;

void* modifyResources(int resource, fake_resources* p, int val);
int returnResourceValue(int resource, fake_resources p);
int* CheckForDeadlock(int numberOfProcesses, processes max, processes alloc, fake_resources avail);
int RemoveSmallestAllocated(int numberOfProcesses, int deadlockedProcess, processes* max, processes* alloc, fake_resources* avail);


