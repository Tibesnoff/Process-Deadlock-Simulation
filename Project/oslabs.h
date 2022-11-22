
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
int* BankersAlgorithm(int n, int m, processes max, processes alloc, fake_resources avail);



