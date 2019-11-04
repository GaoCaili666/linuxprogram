#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
	printf("test:pid=%d,ppid=%d\n",getpid(),getppid());
	
	return 0;
}
