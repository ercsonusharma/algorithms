#include <stdio.h>

int main(void)
{
   int a[5] = { 1, 2, 3, 4, 5 };
   int *ptr = (&a + 1);
   /*
	   Type of &a is int (*)[5]
	   Pointer to an array of 5 integers
	   Therefore, &a + 1 will be incremented by 20 bytes (i.e. by the size of the array)
   */
   printf("%d %d\n", *(a + 1), *(ptr - 1));  // type of ptr is int* so ptr - 1 decrements by 4 bytes(size of integer).

   return 0;
}
