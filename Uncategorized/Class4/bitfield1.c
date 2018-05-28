#include<stdio.h>

struct bitfield
{
	signed int :3;
	signed int a:3;
	signed int :0;
	/*int a;
	int :0;*/
}bf;

int main()
{
	printf("%d\n", sizeof(struct bitfield));
	return 0;
}
