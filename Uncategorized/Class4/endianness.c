#include<stdio.h>

int main()
{
	short int a = 0x0102;
	char *c = (char*)&a;
	if(*c == 0x01)
		printf("Big Endian\n");
	else
		printf("Little Endian\n");
	return 0;
}
