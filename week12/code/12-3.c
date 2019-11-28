#include "my.h"

int main()
{
	pid_t pid1,pid2,pid3;
	int pipefd1[2];
	int pipefd2[2];
	char num[5];		//每个数字的字符串表示

	if(pipe(pipefd1) < 0)
	{
		perror("pipe failed.\n");
		return -1;
	}
	if(pipe(pipefd2) < 0)
	{
		perror("pipe failed.\n");
		return -1;
	}

	pid1 = fork();
	if(pid1 < 0)
	{
		perror("fork failed\n");
		return -1;
	}
	else if(pid1 == 0)
	{
		//子进程1
		//将0-4096写入管道
		int i;
		memset(num,0,sizeof(num));
		close(pipefd1[0]);
		for(i=0; i<=4096; i++)
		{
			sprintf(num,"%d",i);

			if(write(pipefd1[1],num,strlen(num)) != -1)
			{
				printf("child1 write %s to pipe1\n",num);
			}

		}
		close(pipefd1[1]);
		exit(0);
	}
	else
	{
		sleep(3);
		pid2 = fork();
		if(pid2 < 0)
		{
			perror("fork failed\n");
			return -1;
		}
		else if(pid2 == 0)
		{
			//子进程2
			//读出管道里面的数字并显示
			int i,n;
			memset(num,0,sizeof(num));
			close(pipefd1[1]);
			close(pipefd2[0]);
			for(i=0; i<=4096; i++)
			{
				if(i < 10)
				{
					n=1;
				}
				else if(i < 100)
				{
					n=2;
				}
				else if(i < 1000)
				{
					n=3;
				}
				else if(i < 10000)
				{
					n=4;
				}
				else
				{
					n=0;
				}
				if(read(pipefd1[0],num,n) > 0)
				{
					printf("child2 read %s from pipe1\n",num);
					if(write(pipefd2[1],num,strlen(num)) != -1)
					{
						printf("child2 write %s to pipe2\n",num);
					}
					
				}
			}
			close(pipefd2[1]);
			close(pipefd1[0]);
			exit(0);

		}
		else
		{
			sleep(3);
			pid3 = fork();
			if(pid3 < 0)
			{
				perror("fork failed\n");
				return -1;
			}
			else if(pid3 == 0)
			{
				//子进程3
				int i,n;
				int sum = 0;
				
				memset(num,0,sizeof(num));
				close(pipefd2[1]);
				for(i=0; i<=4096; i++)
				{
					if(i < 10)
					{
						n=1;
					}
					else if(i < 100)
					{
						n=2;
					}
					else if(i < 1000)
					{
						n=3;
					}
					else if(i < 10000)
					{
						n=4;
					}
					else
					{
						n=0;
					}
					if(read(pipefd2[0],num,n) > 0)
					{
						sum += atoi(num);
					}
					
				}
				printf("child3 calculation sum = %d\n",sum);
				close(pipefd2[0]);
				exit(0);
				
			}
			else
			{
				wait(NULL);
				wait(NULL);
				wait(NULL);
				return 0;
				
			}
		}

	}


}
