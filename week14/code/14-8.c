#include "my.h"
int i=0;

int fun(void *d)
{
	i++;
	printf("tid=%p i=%d\n",pthread_self(),i);
	return 0;
}

int main()
{
	pthread_t tid;
	int ret,i;
	for(i=0; i<4; i++)
	{
		ret=pthread_create(&tid,NULL,(void*(*)())fun,NULL);
		if(ret != 0)
		{
			perror("failed!\n");
			return -1;
		}
	}
	//这个循环好像没有实际用处
	for(i=0; i<4; i++)
		pthread_detach(tid);
	sleep(10);
	printf("main done!\n");
	return 0;
}
