#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void show(int * a, int n)
{
	int i;
	for(i = 0; i < n; i++)
	{
		printf("%4d:  %4d\n", i, a[i]);
	}

}
void init(int * a, int n)
{
	int i;
	srand((int)time(NULL));

	for(i=0;i<n;i++) {
		a[i]=1+(int)(1000.0*rand()/(RAND_MAX+1.0));
	}

}
