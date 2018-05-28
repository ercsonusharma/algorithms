#include<stdio.h>
int  foo() // Unspecified parameters
{
	printf("foo\n");
}          
int bar(void)      // No parameters
{
	printf("bar\n");
}
int main()
{
	foo(0);         // Valid C, invalid C++
	foo(1, 2);      // Valid C, invalid C++
	bar();          // Okay in both C and C++
	bar(1);         // Error in both C and C++	
	return 0;
}
