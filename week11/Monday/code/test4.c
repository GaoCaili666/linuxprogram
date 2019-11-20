#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>
#include <sys/types.h>
int main()
{
	int s,p;
	pid_t pid1,pid2;
	if( (pid1=fork()) && (pid2=fork()) < 0)
	{
		perror("failed to fork\n");
		return -1;
	}

	else if(pid1 == 0)
	{
		printf("%d :child1 running now\n",getpid());
		while(1);
	
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
		sleep(5);
		printf("%d :parent is waiting zombie now\n",getpid());
		
		while((p=waitpid(pid1,&s,0))!=-1)
		{
			printf("%d :parent is running now\n",getpid());
			if(WIFEXITED(s))
			{
				printf("child %d is exiting normally.exit code = %d\n",p,WEXITSTATUS(s));
			}
			else if(WIFSIGNALED(s))
			{
				printf("child %d exit by signal,signal number = %d\n",p,WTERMSIG(s));
			}
			else
			{
				printf("Not konw!\n");
			}
		}
		
		printf("%d :parent is exiting now\n",getpid());
	}
	exit(0);

}
