#include <stdio.h>

struct a
{
   char        c;
   short int   s;
};
 
struct b
{
   short int   s;
   char        c;
   int         i;
};

struct c
{
	char c;
	int a;
};
 
int main()
{
   printf("sizeof(struct a) = %d\n", sizeof(struct a));
   printf("sizeof(struct b) = %d\n", sizeof(struct b));
   printf("sizeof(struct b) = %d\n", sizeof(struct c));
   return 0;
}
