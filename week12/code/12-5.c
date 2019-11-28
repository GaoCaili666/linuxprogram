#include "my.h"
void sighandler(int signo);
int main(void)
{
	int fds[2];
	if(signal(SIGPIPE,sighandler) == SIG_ERR)
	{
		fprintf(stderr,"signal error (%s)\n",strerror(errno));
		exit(EXIT_FAILURE);
	}
	if(pipe(fds) == -1)
	{
		fprintf(stderr,"create pipe failed(%s)\n",strerror(errno));
		exit(EXIT_FAILURE);
	}
	pid_t pid;
	pid = fork();
	if(pid == -1)
	{
		fprintf(stderr,"fork error (%s)\n",strerror(errno));
		exit(EXIT_FAILURE);
	}
	else if(pid == 0)
	{
		fprintf(stdout,"[CHILD ] I will close the last read end of pipe.pid=%d,ppid=%d\n",getpid(),getppid());
		sleep(100);	//方便到/proc下观察	
		close(fds[0]);//子进程关闭读取端文件描述符
		
		exit(EXIT_SUCCESS);
	}
	else
	{
		sleep(120);	  //方便到/proc下观察
		close(fds[0]);//父进程关闭读取端文件描述符
		

		int ret;
		ret = write(fds[1],"hello",5);
		if(ret == -1)
		{
			fprintf(stderr,"[PARENT] write error(%s)\n",strerror(errno));
		}
		return 0;
	}
}

void sighandler(int signo)
{
	printf("[PARENT] catch a SIGPIPE signal and signum = %d\n",signo);
}




