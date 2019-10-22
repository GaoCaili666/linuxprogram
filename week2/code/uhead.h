#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <fcntl.h>
#include <string.h>

#define UNUMBER 1000

struct arg {
	float ave;
	int sum;

};
void showFile(char *);
void show(int *, int);
void urand(int *, int *, int);
void writeFile(int *, int *, int, char *);


struct arg operator(int *, int);

void sysSort(int *, int);
void mySort(int *, int);
int compar(const void *, const void *);
void bubbleSort (int *, int);



