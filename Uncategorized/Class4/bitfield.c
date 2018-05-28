#include<stdio.h>

struct bitfield
{
	signed int a:1;
	signed int b:32;
	unsigned c:32;
	//float d:4;  // Bit fields can only be taken for integer types (chat, short, int, long int, long long int - signed and unsigned)
	//char e:5;
}bf;

int main()
{
	bf.a = 1; //Signed numbers are stored in 2s complement form.
	bf.b = 6;
	bf.c = 6;
	printf("%d\n", sizeof(struct bitfield));
	printf("%d %d %u\n", bf.a, bf.b, bf.c);
	return 0;
}
