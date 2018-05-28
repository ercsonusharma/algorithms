#include <stdio.h>

int main ()
{
	extern int a;		//Declaration
	printf("%d\n", a);	//No definition found => Linker Error
	return 0;
}
