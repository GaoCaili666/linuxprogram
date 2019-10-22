#include "uhead.h"

void sysSort(int * a, int n) {
	struct timeval tv1, tv2;
	struct timezone tz;
	gettimeofday(&tv1, &tz);
	qsort(a, n, sizeof(int), compar);
	gettimeofday(&tv2, &tz);

	FILE * fp;
	int i;
	fp = fopen("sort1.dat", "w");
	for(i = 0; i < n; i++) {
		fprintf(fp, "%d\n", a[i]);
	}
	fprintf(fp, "排序耗时：%d微秒\n", tv2.tv_usec-tv1.tv_usec);
	fclose(fp);
}

void mySort(int * a, int n) {
	struct timeval tv1, tv2;
	struct timezone tz;
	gettimeofday(&tv1, &tz);
	bubbleSort(a, n);
	gettimeofday(&tv2, &tz);

	FILE * fp;
	int i;
	fp = fopen("sort2.dat", "w");
	for(i = 0; i < n; i++) {
		fprintf(fp, "%d\n", a[i]);
	}
	fprintf(fp, "排序耗时：%d微秒\n", tv2.tv_usec-tv1.tv_usec);
	fclose(fp);
}



int compar(const void *a, const void * b) {
	int *aa = (int *) a, *bb = (int *) b;
	if(*aa > *bb) return 1;
	if(*aa == *bb) return 0;
	if(*aa < *bb) return -1;	
}

void bubbleSort (int * arr, int len) {
    int temp;
    int i, j;
    for (i=0; i<len-1; i++) 
        for (j=0; j<len-1-i; j++) { 
            if (arr[j] > arr[j+1]) { 
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
}







