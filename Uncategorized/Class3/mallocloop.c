#include<stdio.h>
#include<stdlib.h>

int main()
{
/*
	int *p[size]; -- size must be a constant here -- wrong declrn
	int *p = (int *) malloc (sizeof (int) * m * n); -- not accessible as p[i][j]
	int arr[m][n]; -- error bcz var length arr.
*/
	int m = 3, n = 4, i, j;
	int** p = (int**)malloc(sizeof(int*) * m);
	for(i = 0; i < m; i++)
		p[i] = (int*)malloc(sizeof(int) * n);
		
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
