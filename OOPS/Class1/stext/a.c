#include <stdio.h>

int main()
{
	int c = 9;
	int i,j;
	(i,j)=c;
	printf("%d\n", j);
	return 0;
}
/*
The comma operator in C always results in an r-value even if its right operand is an l-value, 
while in C++ the comma operator will result in an l-value. This means that certain expressions are valid in C++ but not in C
*/
