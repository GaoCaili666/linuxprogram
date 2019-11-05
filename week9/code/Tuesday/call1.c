#include "myhead.h"

int main() {
	int ret;
	printf("call1:pid=%d, ppid=%d\n",getpid(),getppid());
	ret=system("./test2 123 abc hello world");
	printf("after calling! ret=%d\n",ret);
	return 0;

}

