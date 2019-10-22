#include "uhead.h"
void showFile(char * filename)
{
	int fd, nbytes;
	char buf[21];
	fd = open(filename, O_RDONLY);
	if(fd<0) {
		exit(1);
	}
	while((nbytes=read(fd, buf, 20))>0) {
		buf[nbytes] = '\0';
		printf("%s",buf);
	}
	close(fd);
}
void show(int * a, int n)
{

	int i;
	for(i=0; i<n; i++) {
		printf("a[%d]=%d\n", i, a[i]);

	}
}

void urand(int * a, int * b, int n)
{
	int i;
	srand((int)time(NULL));
	for(i=0;i<n;i++) {
		a[i]=1+(int)(1000.0*rand()/(RAND_MAX+1.0));
	}
	for(i=0;i<n;i++) {
		b[i]=1+(int)(1000.0*rand()/(RAND_MAX+1.0));
	}
	writeFile(a, b, n, "randdata.dat");
}
void writeFile(int * a, int * b, int n, char * filename) {
	struct arg ta;
	ta=operator(a, n);
	struct arg tb;
	tb=operator(b, n);
	
	FILE * fp;
	int i;
	fp = fopen(filename, "w");
	for(i = 0; i < n; i++) {
		fprintf(fp, "%d\n", a[i]);
	}
	fprintf(fp, "sum=%d, ave=%f\n", ta.sum, ta.ave);
	
	for(i = 0; i < n; i++) {
		fprintf(fp, "%d\n", b[i]);
	}
	fprintf(fp, "sum=%d, ave=%f\n", tb.sum, tb.ave);
	fclose(fp);
}




