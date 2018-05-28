#include<cstdio>

void foo(char c)
{
   printf("From foo: char\n");
}

void foo(int i)
{
   printf("From foo: int\n");
}

int main()
{
   foo('V'); //Type of 'V' should be treated as char only otherwise we can't differentiate between the two functions.
   foo(5);
   return 0;
}
