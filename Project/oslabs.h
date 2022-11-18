/*struct fake_resources {
	int RAM;
	int Disk;
	int Net;
};

int getResource(int num, struct fake_resources resources){
	if (num == 0)return resources.RAM;
	if (num == 1)return resources.Disk;
	if (num == 2)return resources.Net;
};

int setResource()*/

int* fake_resources;

int* BankersAlgorithm(int n, int m, int max[5][3], int alloc[5][3], int avail[3]);