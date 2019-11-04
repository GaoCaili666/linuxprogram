#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int global1=0;
int global2=0;
int main()
{
	int i = 10;
	static int k = 2;
	pid_t result = fork();
	if(result < 0)
	{
		perror("创建子进程失败\n");
		exit(0);
	}
	else if(result == 0)
	{
		printf("child:pid=%d ppid=%d i=%d k=%d global1=%d global2=%d\n",getpid(),getppid(),i,k,global1,global2);
		global1=999;
		global2=1000;
		i=12;
		k=19;
		
		printf("child:pid=%d ppid=%d i=%d k=%d global1=%d global2=%d\n",getpid(),getppid(),i,k,global1,global2);
		exit(0);
	}
	else
	{
		
		sleep(1);
		printf("parent:pid=%d ppid=%d i=%d k=%d global1=%d global2=%d\n",getpid(),getppid(),i,k,global1,global2);
		
		printf("parent:pid=%d ppid=%d i=%d k=%d global1=%d global2=%d\n",getpid(),getppid(),i,k,global1,global2);
		exit(0);
	}


}
