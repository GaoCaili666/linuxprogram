#include "dylib.h"
#include <stdio.h>
#include <dlfcn.h>
#include <stdlib.h>
int main()
{
	int a[10];
	void *hd;
	char *error;
	void (*f1)(),(*f2)();
	int (*f3)(),(*f4)();
	hd = dlopen("../dynamiclib/libdylib.so",RTLD_LAZY);
	if(!hd) {
		fprintf(stderr,"%s\n",dlerror());
		exit(1);
	}
	f1 = dlsym(hd,"init");
	if((error=dlerror()) != NULL) {
		fprintf(stderr,"%s\n",dlerror());
		exit(1);
	}
	f2 = dlsym(hd,"show");
	if((error=dlerror()) != NULL) {
		fprintf(stderr,"%s\n",dlerror());
		exit(1);
	}
	f3 = dlsym(hd,"max");
	if((error=dlerror()) != NULL) {
		fprintf(stderr,"%s\n",dlerror());
		exit(1);
	}
	f4 = dlsym(hd,"sum");
	if((error=dlerror()) != NULL) {
		fprintf(stderr,"%s\n",dlerror());
		exit(1);
	}

	f1(a, 10);
	f2(a, 10);
	printf("max = %d\n",f3(a, 10));
	printf("sum = %d\n",f4(a, 10));
	return 0;
}
