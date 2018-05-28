#include <stdio.h>

union a
{
	int i; 
	char c;
	//Address of both i and c will be same
}b;

int main()
{
	union a s;
	s.i = 0;
	s.c = 'a';
	printf("%d %c\n", s.i, s.c); //The output will be different for Little and Big Endian machines
	printf("%d\n", sizeof(s));
	return 0;
}
