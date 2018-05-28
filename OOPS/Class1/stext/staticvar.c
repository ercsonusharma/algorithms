#include<stdio.h>

void fun()
{
	static int i = 1;
	printf("%d\n", i++);
	if(i < 5)
		fun();
}

int main()
{
	fun();
	return 0;
}
