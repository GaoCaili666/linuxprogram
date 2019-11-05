#include "myhead.h"
#include <setjmp.h>
static jmp_buf g_stack_env;

static void func1();
static void func2();

int main() {
	if(0==setjmp(g_stack_env)) {
		printf("Normal flow\n");
		func1();
	} else {
		printf("long jump flow\n");
	}
	return 0;
}

static void func1()
{
	printf("Enter func1\n");
	func2();
}
static void func2()
{
	printf("Enter func2\n");
	longjmp(g_stack_env,1);
	printf("Leave func2\n");
}
