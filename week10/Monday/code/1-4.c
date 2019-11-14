#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int glob = 88;
int main(void)
{
	int var;
	var = 99;
	pid_t pid;
	if ((pid = vfork()) < 0) {
		printf("vfork error");
		exit(-1);
	}
	else if (pid == 0) { /* 子进程*/
		var++;
		glob++;
		printf("child:pid=%d, glob=%d, var=%d\n",getpid(), glob, var);
		return 0;
		
	}
	printf("parent:pid=%d, glob=%d, var=%d\n",getpid(), glob, var);
	return 0;
}
