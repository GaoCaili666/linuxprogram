#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
int main()
{
	int fd;
	pid_t pid1,pid2;
	int i;
	char buf[1024];
	fd = open("out.dat", O_CREAT|O_TRUNC|O_WRONLY, S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH);
	if(fd < 0)
	{
		perror("failed to open\n");
		return -1;
	}
	if( (pid1=fork()) && (pid2=fork()) < 0)
	{
		perror("failed to fork\n");
		return -1;
	}
	else if(pid1 == 0)
	{
		
		for(i=0; i<10; i++)
		{
			sprintf(buf,"%d:%d\n",getpid(),i);
			write(fd,buf,strlen(buf));
			//sleep(1);
			
		}
		
	}
	else if(pid2 == 0)
	{
		for(i=0; i<10; i++)
		{
			sprintf(buf,"%d:%d\n",getpid(),i);
			write(fd,buf,strlen(buf));
			//sleep(1);
			
		}
	}
	else
	{

		sleep(1);

	}


}
