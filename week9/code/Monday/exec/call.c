#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
	char* argv[4] = {"./test","hello","world",NULL};
	printf("call:pid=%d,ppid=%d\n",getpid(),getppid());
	//system("/root/Desktop/linux/第9周/exec/test");
	execl("/root/Desktop/linux/第9周/exec/test","test","hello","world",NULL);

	
	execvp("test",argv)
	printf("after calling\n");
	return 0;
}
