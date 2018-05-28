#include <stdio.h>
#include <stdlib.h>

int main()
{
	int* p;
	int m, i;
	/*
		size of array = m * 4 bytes
	*/
	scanf("%d", &m);
	p = (int*)malloc(sizeof(int) * m);
	/*
		p = (int*) malloc (4 * m); -- not portable
		what if size of integer is not 4?
	*/
	for(i = 0; i < m; i++)
		p[i] = i;
	for(i = 0; i < m; i++)
		printf("%d ", p[i]);
	printf("\n");
	return 0;
}
