#include <stdio.h>
#include <stdlib.h>

struct _1
{
	char str1[20];	
};

int main()
{
	struct _1 var1,var2;
	strcpy(var1.str1,"cyber");
	
	var2 = var1;
	/*
		Content is copied as it is. Here content is the actual content of the array
		There are 2 different memory addresses for var1's str1 and var2's str1
	*/
	var2.str1[1] = 'i';
	// Only var2's array is changed.
	puts(var1.str1);
	puts(var2.str1);

	return 0;
}
