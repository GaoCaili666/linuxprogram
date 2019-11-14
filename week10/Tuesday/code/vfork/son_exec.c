#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int g=100;
int main()
{
	pid_t pid;
	int i=888;
	static int k=777;
	pid=vfork();
	int s;
	if(pid<0)
	{
		perror("fork failed!\n");
		exit(-1);
	}
	else if(pid == 0)
	{
		printf("child is runing!\n");
		printf("child: g=%d i=%d k=%d\n",g,i,k);
		execl("./test","test",NULL);
		printf("child after execl!\n");
		_exit(12);
	}
	else
	{
		wait(&s);
		printf("parent is runing! exit = %d\n",WEXITSTATUS(s));
		printf("parent: g=%d i=%d k=%d\n",g,i,k);
		printf("parent will finish!\n");
		return 0;
	}
}



