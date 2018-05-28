#include<stdio.h>

int main()
{
	int an_int = 0;
	void *void_pointer = &an_int;  // Line 1
	double *double_ptr = void_pointer; // Line 2
	*double_ptr = 5.6; // Line 3
	printf ("%d\n%lf\n", an_int, *double_ptr);
	return 0;
}
//void* - Generic use
//Can hold any pointer type
//Line 3 accesses 8 bytes while only 4 bytes (integer) is allocated to us - this is a vulnerability in this code.
