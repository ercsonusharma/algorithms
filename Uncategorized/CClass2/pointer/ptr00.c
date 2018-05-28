//pointer arithmetic
#include<stdio.h>

int main()
{
	int a[]={11,2,3,4,5,6};
	printf("%d\n",(&a[3]-&a[0]));
	printf ("%d\n", *(a + 3));
	/*
	12/4 = 3 (divide by 4 because we want to find how many integers are between these two addresses).
	if a = 1000, a + 3 = 1012
	&a[3] = (a + 3)
	a[3] = *(a + 3)
	3[a] = *(3 + a)
	*/
	return 0;
}





