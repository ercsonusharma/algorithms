#include <stdio.h>

int main()
{
	int arr[3];
	int i;
	printf("%p %p %p\n", arr, arr + 1, &i);
	for(i = 2; i >= -1; i--)
	{
		arr[i] = 0;
		printf("Hello\n");
	}
	return 0;
}
