#include "my.h"
#define NUM_THREADS 200
void hello(void *t)
{
	pthread_t my_tid;
	struct info *data = (struct info *)(t);
	int sum=0;
	int i;
	for(i=1; i<=(data->n); i++)
	{
		sum += i;
	}
	my_tid=pthread_self();
	printf("\tThread %d: my tid is %lx,Hello world\n",data->no,my_tid);
	printf("\tThread %d: sum 1 to %d is %d\n",data->no,data->n,sum);
}

int main()
{
	pthread_t tid;
	struct info a[NUM_THREADS];
	int rv,t;
	for(t=0; t<NUM_THREADS; t++)
	{
		a[t].no = t;
		a[t].n = 100*(t+1);
		rv = pthread_create(&tid,NULL,(void*(*)())hello,(void*)&a[t]);
		if(rv!=0)
		{
			printf("thread create failed\n");
			return -1;
		}
		printf("create thread %lx\n",tid);

	}
	printf("Good bye!\n");
	pthread_exit(NULL);

}
