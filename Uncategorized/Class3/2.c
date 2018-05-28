#include <stdio.h>
void print(int *arr, int m, int n)
{
    int i, j;
    for (i = 0; i < m; i++)
      for (j = 0; j < n; j++)
        printf("%d ", *((arr+i*n) + j));
}
 
int main()
{
    int arr[][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int m = 3, n = 3;
    print((int*)arr, m, n); 
	/*
		Without typecasting a warining will come, since type of arr is int (*)[3] - pointer to an array of 3 ints 
		and we are trying to send to an int* argument.
	*/
    return 0;
}
