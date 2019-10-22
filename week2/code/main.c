#include "uhead.h"
int main() {

	int a[UNUMBER];
	int b[UNUMBER];
	
	urand(a, b, UNUMBER);
	sysSort(a, UNUMBER);
	
	mySort(b, UNUMBER);
	
	
	return 0;


}
