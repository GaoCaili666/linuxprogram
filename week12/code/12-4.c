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
		fprintf(stdout,"[CHILD ] I will close the last read end of pipe \n");
		close(fds[0]);//子进程关闭读取端文件描述符
		exit(EXIT_SUCCESS);
	}
	else
	{
		close(fds[0]);//父进程关闭读取端文件描述符
		sleep(1);//确保子进程也将读取端关闭

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




