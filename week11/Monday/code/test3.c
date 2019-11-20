#include <stdio.h>
#include <stdlib.h>
#include <wait.h>
#include <sys/types.h>
int main()
{
	int pid,s;

	if((pid = fork()) < 0)
	{
		perror("failed to fork\n");
		return -1;
	}
	else if(pid == 0)
	{
		printf("%d :child running now\n",getpid());
		//while(1);
	
		printf("%d :child exit now\n",getpid());
		
		exit(120);
	}
	else
	{
		printf("%d :parent is waiting zombie now\n",getpid());

		while((pid=wait(&s)) != -1)
		{
			printf("%d :parent is running now\n",getpid());
			if(WIFEXITED(s))
			{
				printf("child %d is exiting normally.exit code = %d\n",pid,WEXITSTATUS(s));
			}
			else if(WIFSIGNALED(s))
			{
				printf("child %d exit by signal,signal number = %d\n",pid,WTERMSIG(s));
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
