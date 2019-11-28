#include "my.h"
int main() {
	pid_t r;

	int pipefd[2];
	int count = 0;
	char buf[1] = {'c'};
	
	if(pipe(pipefd) < 0)
	{
		perror("pipe failed.\n");
		return -1;
	}
	r = fork();
	if(r < 0)
	{
		perror("fork failed.\n");
		return -1;
	}
	else if(r==0)
	{
		sleep(5);
		exit(0);
	}
	else
	{
		
		close(pipefd[0]);
		while(write(pipefd[1],buf,1) != -1)
		{
			count++;
			printf("count = %d\n",count);
		}
		close(pipefd[1]);
		
		return 0;
	}

}
