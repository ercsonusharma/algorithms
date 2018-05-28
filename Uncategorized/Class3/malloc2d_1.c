#include <stdio.h>
#include <stdlib.h>

int main()
{
	int *q, **p;
	int m, n, i, j;
	scanf("%d %d", &m, &n);
	q = (int*) malloc(m * n * sizeof(int));
	p = (int**) malloc(m * sizeof(int*));
	/*
		*(*(p + i) + j)
	*/
	for(i = 0; i < m; i++)
		p[i] = (n * i) + q;
		
	for(i = 0; i < m; i++)
		for(j = 0; j < n; j++)
			p[i][j] = j + i * n;
			
	for(i = 0; i < m; i++)
	{
		for(j = 0; j < n; j++)
			printf("%3d ", p[i][j]);
		printf("\n");
	}
	return 0;
}
