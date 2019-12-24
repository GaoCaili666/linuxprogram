#include "my.h"

pthread_rwlock_t rwlock;
int g = 0;
void* fun(void* param)
{
	int i;
	pthread_rwlock_rdlock(&rwlock);		//保证4个线程同时在这里开始，读请求之间无需同步
										//当前是读锁时，其他读锁请求执行，写锁阻塞
	for(i = 0 ; i < LOOP; i++ )
	{
		g++;
	}
	pthread_rwlock_unlock(&rwlock);
	return NULL;
}
int main(int argc ,char* argv[])
{
	pthread_t tid[NUM];

	int i, ret;
	ret = pthread_rwlock_init(&rwlock,NULL);
	if(ret)
	{
		perror("init rw lock failed\n");
		exit(1);
	}
	pthread_rwlock_wrlock(&rwlock);		//写请求锁住读请求和其他写请求
	for(i = 0 ; i < NUM ; i++)
	{
		ret = pthread_create(&tid[i],NULL,fun,NULL);
		if(ret != 0)
		{
			perror("create thread failed\n");
			exit(2);
		}
	}
	pthread_rwlock_unlock(&rwlock);
	for(i = 0 ; i < NUM; i++)
	{
		pthread_join(tid[i],NULL);
	}
	pthread_rwlock_destroy(&rwlock);
	printf("thread num : %d\n",NUM);
	printf("loops per thread : %d\n",LOOP);
	printf("expect result : %d\n",LOOP*NUM);
	printf("actual result : %d\n",g);
	exit(0);
}
