#include<stdio.h>

int main()
{
	char s[] = "Bouquets and Brickbats";
	int* p = 0;
	/*
		This is equivalent to:
			int *p;
			p = 0;
	*/
	printf("%c\n",*(&s[2]));
	printf("%s, ",s+5);
	printf("%s\n",s);
	printf("%c\n",*(s+2));
	printf("%d\n", &(*p));	
	/*
		&*&*&*p = p;
		& and * cancelled at compile time for efficiency.
		
	*/
	return 0;
}






