#include <stdio.h>

struct a
{
	int a;
	char c;
}a;

int main()
{
	//int a;
	a.a = 5;
	a.c = 'd';
	printf("%d %c\n", a.a, a.c);
	return 0;
}
