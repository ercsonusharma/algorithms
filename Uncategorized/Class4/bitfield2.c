#include <stdio.h>

struct s
{
	int a:4;
	char b:5;
	int c:7;
	unsigned f1:1;
	unsigned f2:24;
	unsigned :3;
	int :3;
	int :0;
	unsigned f3:6;
	unsigned :0; 
	unsigned f4:8;
}x;

int main()
{
	printf("%d\n",sizeof(x));
}
