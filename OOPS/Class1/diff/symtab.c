#include <stdio.h>

int main ()
{
	const int a = 1;
	/*
		In C -- a gets memory
		In C++ -- a doesn't get memory here
	*/
	/*
		a is entered into SYMTAB and directly REPLACED from SYMTAB
	*/
	int *ptr = (int *)&a;
	/*
		Forefully taking the address of a
		So, in C++ -- memory will be assigned here
	*/
	(*ptr)++;		// a is changed here
	if (a == 1)	// a is replaced directly from SYMTAB
	{
		printf ("C++\n");
	}
	else
	{
		printf ("C\n");
	}
	return 0;
}
