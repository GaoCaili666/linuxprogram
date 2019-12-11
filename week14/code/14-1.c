#include "my.h"

void *threadfun(void *arg)
{
	printf("thread pid = %d\n",getpid());
}

int main()
{
	pthread_t tid;
	int error;
	error = pthread_create(&tid, NULL,&threadfun, NULL);
	if(error != 0)
	{
		printf("thread create failed!\n");
		return -1;
	}
	printf("main thread is ended! %d\n",getpid());
	pthread_join(tid,NULL);
	return 0;
}
