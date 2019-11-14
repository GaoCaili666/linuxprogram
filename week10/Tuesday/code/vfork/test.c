#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int g=10;
char a[1000]={0};
int main()
{
	pid_t pid;
	int i;
	static int k=20;
	
	printf("test:pid=%d\n&g=%p\n&a=%p\n&k=%p\n",getpid(),&g,&a,&k);
	for(i=0; i<10; i++)
	{
		printf("test:g=%d,k=%d\n",g++,k++);
	}
	return 0;

}
