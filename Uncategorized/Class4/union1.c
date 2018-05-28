/*
	Swap two bytes of a short int using union.
*/

#include <stdio.h>

union swap
{
	char c[2];
	short int a;
}s;

int main()
{
	int temp;
	s.a = 280; //0x0118
	temp = s.c[0];
	s.c[0] = s.c[1];
	s.c[1] = temp;
	printf("%d %#x\n", s.a, s.a);
	return 0;
}
