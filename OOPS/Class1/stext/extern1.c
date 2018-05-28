#include <stdio.h>

int main ()
{
	extern int a;	//external linkage -- declrn -- no mem. assigned
	printf ("%d\n", a);	// No error
	return 0;
}

int a = 10;	// Linker will search for a here
