#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
static void callback1()
{
	printf("--------callback1--------\n");
}
static void callback2()
{
	printf("--------callback2--------\n");
}
static void __attribute__((constructor)) before_main()
{
	printf("--------constructor--------\n");
}
static void __attribute__((destructor)) after_main()
{
	printf("--------desstructor--------\n");
}
int main()
{
	atexit(callback1);
	atexit(callback2);
	FILE * fp;
	char buf[]={"test data from full buffer"};
	if((fp = fopen("test.txt","w")) == NULL)
	{
		perror("failed to open\n");
		return -1;
	}
	if(fputs(buf,fp) == EOF)
	{
		perror("failed to fputs\n");
		return -1;
	}
	printf("printf: data from line buffer");
	//exit(0);
	//_exit(0);
	return 0;

}
