#include<stdio.h>

int main()
{
	char a[]={'A','C','E','G'}; 
	//string == character array with \0 at the end.
	char *ppp=&a[0];
	*ppp++;				//equivalent to *(ppp++)
	/* 
		Read operator precedence from Dennis Ritchie - Section 2.12(Chapter 2)
	*/
	printf("%c\n",*++ppp);
	printf ("%c\n",--*ppp);//array modified
	printf("%s\n", a);
	return 0;
}
