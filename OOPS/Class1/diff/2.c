#include<stdio.h>
int main()
{
   foo();
   return 0;
}
/*
	Undeclared function:
		Return type int
		Any no. of arguments
*/ 
int foo()	
{
   printf("Hello\n");
   return 0;
}
