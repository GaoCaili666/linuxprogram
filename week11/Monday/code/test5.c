#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>
#include <sys/types.h>
int main()
{
	int s1,p1,s2,p2;
	pid_t pid1,pid2;
	if( (pid1=fork()) && (pid2=fork()) < 0)
	{
		perror("failed to fork\n");
		return -1;
	}

	else if(pid1 == 0)
	{
		printf("%d :child1 running now\n",getpid());
		//while(1);
	
		printf("%d :child1 exit now\n",getpid());
		
		exit(120);
	}
	else if(pid2 == 0)
	{
		printf("%d :child2 running now\n",getpid());
		//while(1);
	
		printf("%d :child2 exit now\n",getpid());
		
		exit(130);
	}
	else
	{
		//sleep(5);
		printf("%d :parent is waiting zombie now\n",getpid());
		p1 = wait(&s1);
		p2 = wait(&s2);
		
		if(WEXITSTATUS(s1) == 130)
		{
			printf("child2 %d is exiting normally\n",p1);

		}
		if(WEXITSTATUS(s2) == 120)
		{
			printf("child1 %d is exiting normally\n",p2);

		}
		
		printf("%d :parent is exiting now\n",getpid());
	}
	exit(0);

}
