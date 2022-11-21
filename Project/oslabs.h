
typedef struct {
	int RAM;
	int NET;
	int DISK;
}fake_resources;

typedef struct {
	fake_resources resources[10];
}process;

void* modifyProcess(int resource, fake_resources* p, int val);
int returnValue(int resource, fake_resources p);
int* BankersAlgorithm(int n, int m, process max, process alloc, fake_resources avail);



