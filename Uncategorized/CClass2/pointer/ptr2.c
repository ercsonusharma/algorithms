#include<stdio.h>

int main()
{
	char* a = (char*)malloc(10);
	a = 'a';
	printf("%s\n", a);
	/*
		a stores an address i.e. 97
		This address is reserved for kernel (Starting 1GB of memory space is reserved for kernel).
	*/
}
