#include <stdio.h>
#include <stdlib.h>

struct _1
{
	char *str1;	
};

int main()
{
	struct _1 var1,var2;
	var1.str1 = (char *)malloc(sizeof(20));
	/*
		str1 has the starting address of allocated memory in heap.
	*/
	strcpy(var1.str1,"cyber");
	
	var2 = var1;
	/*
		Content is copied as it is.  Here content is the address stored in str1.
		After this, str1 of var2 has the address of same allocated memory
	*/
	var2.str1[1] = 'i';
	/*
		change happens at the allocated address
	*/
	
	puts(var1.str1);
	puts(var2.str1);

	return 0;
}
