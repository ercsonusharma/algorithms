#include <stdio.h>
int main()
{
   void *vptr;
   int *iptr = vptr; //Errro in C++, fine in C. Need to typecast explicitly in C++
   return 0;
}



