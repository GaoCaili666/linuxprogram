#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int g=10;
int main()
{
	int s=20;
	static int k=30;
	pid_t pid=vfork();
	if(pid<0)
	{
		perror("fork failed\n");
	}
	else if(pid==0)
	{
		printf("child pid=%d\n&g=%p &s=%p &k=%p\n",getpid(),&g,&s,&k);
		//sleep(2);		
		while(g!=100)
			printf("waiting for g=100\n");
		_exit(0);
		
	}
	g=100;
	//sleep(2);
	printf("parent pid=%d\n&g=%p &s=%p &k=%p\n",getpid(),&g,&s,&k);
	printf("parent after g=%d,s=%d,k=%d\n",g,s,k);
	return 0;

}
