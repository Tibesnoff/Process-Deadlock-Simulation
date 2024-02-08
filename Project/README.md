# Process-Deadlock-Simulation
This is a student created simulation to process through deadlock. 
This is created by Tyler Besnoff and Lucas Lecler with help from 
Dr.Thomas Schmidt.

Source code is given along with hopefully an autograder at some point.
A student takes the given function headings and codes the functions 
so that main runs correctly without deadlock.

Functions student needs to complete

* void* modifyResources(int resource, fake_resources* p, int val);
* int returnResourceValue(int resource, fake_resources p);
* int* checkForDeadlock(int numberOfProcesses, processes max, processes alloc, fake_resources avail);
* int removeSmallestAllocated(int numberOfProcesses, int* deadlockedResult, processes max, processes alloc, fake_resources avail);
* int removeLargestAllocated(int numberOfProcesses, int* deadlockedResult, processes max, processes alloc, fake_resources avail);

modifyResources: Modifies a resource of a given process

returnResourceValue: Returns the value of a resource of a given process

checkForDeadlock: This function is to check if a given scenario runs into deadlock
                  Function will return a int* with length bufferspace + numberOfProcesses where the first int is the process that causes deadlock, the second int being                   the deadlock flag and the remaining ints corresponding to 1 if the corresponding process can complete and 0 if it can't
                    *Process causing deadlock will start at 0 for the first process
                    *Process causing deadlock will show as -1 if the flag is showing no deadlock
                    *Flag will be set to 0 for deadlock and 1 for no deadlock
                    *Make sure avail array is copied and use the copy in this algorithm
                   
removeSmallestAllocated: This function finds, and removes the process with the smallest allocated total of resources that can satisfy the first process that       
                         causeses a deadlock
                         Returns an int showing which process was removed starting with 0 and going to number of processes
                         
removeSmallestAllocated: This function finds, and removes the process with the smallest allocated total of resources that can satisfy the first process that         
                         causeses a deadlock
                         Returns an int showing which process was removed starting with 0 and going to number of processes
