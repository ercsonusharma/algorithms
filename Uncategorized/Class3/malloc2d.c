#include <stdio.h>
#include <stdlib.h>

int main()
{
	int** p;
	int m, n, i, j;
	scanf("%d %d", &m, &n);
	p = (int**) malloc(m * sizeof(int*) + m * n * sizeof(int));
	
	for(i = 0; i < m; i++)
		p[i] = (int*)(p + m) + (n * i);
		
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
