#include "my.h"
#define NUM_THREADS 4
long interval[NUM_THREADS];
void hello(void *t)
{
	struct timeval tv1, tv2;	//记录开始结束时间

	pthread_t my_tid;
	struct info *data = (struct info *)(t);
	int sum=0;
	int i;
	gettimeofday(&tv1, NULL);
	for(i=1; i<=(data->n); i++)
	{
		sum += i;
	}
	gettimeofday(&tv2, NULL);
	interval[data->no] = tv2.tv_usec-tv1.tv_usec;
	printf("\tThread %d: consume time is %ld毫秒\n",data->no,interval[data->no]);

	my_tid=pthread_self();
	printf("\tThread %d: my tid is %lx,Hello world\n",data->no,my_tid);
	printf("\tThread %d: sum 1 to %d is %d\n",data->no,data->n,sum);
	pthread_exit((void*)&interval[data->no]);
}

int main()
{
	pthread_t tid[NUM_THREADS];
	struct info a[NUM_THREADS];
	int rv,t;
	long * inval;	//时间间隔
	for(t=0; t<NUM_THREADS; t++)
	{
		a[t].no = t;
		a[t].n = 10000*(t+1);
		rv = pthread_create(&tid[t],NULL,(void*(*)())hello,(void*)&a[t]);
		if(rv!=0)
		{
			printf("thread create failed\n");
			return -1;
		}
		printf("create thread %lx\n",tid[t]);

	}
	for(t=0; t<NUM_THREADS; t++)
	{
		pthread_join(tid[t],(void**)&inval);
		
		printf("Thread %d: consume time is %ld毫秒\n",t,*inval);
	}
	printf("Good bye!\n");
	pthread_exit(NULL);

}
