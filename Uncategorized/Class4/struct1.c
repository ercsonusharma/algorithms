#include <stdio.h>

struct a
{
	int p;
	char q;
}b;

int main()
{
	struct a s = {4, 'c'};
	b.p = 5;
	b.q = 'd';
	printf("%d %c\n", b.p, b.q);
	printf("%d %c\n", s.p, s.q);
	return 0;
}
