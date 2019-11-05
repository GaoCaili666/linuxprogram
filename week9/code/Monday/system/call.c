#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
	printf("call:pid=%d,ppid=%d\n",getpid(),getppid());
	system("/root/Desktop/linux/第9周/system/test");
	printf("after calling\n");
	return 0;
}
