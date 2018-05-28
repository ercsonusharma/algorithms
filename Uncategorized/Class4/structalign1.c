#include <stdio.h>

struct b
{
	char c;
	int a;
	char d;
};

struct c
{
	char c;
	char d;
	int a;
};

int main()
{  
   printf("sizeof(struct b) = %d\n", sizeof(struct b));
   printf("sizeof(struct c) = %d\n", sizeof(struct c));
   return 0;
}
