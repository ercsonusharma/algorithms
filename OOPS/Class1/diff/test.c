#include <stdio.h>
 
int main(void)
{
    printf("%d\n", sum(10, 5.6));
    return 0;
}

int sum (int a, float b, int c) 


// C assumes all arguments of type int (since no prototype given), but when defining we give 'b' as float => error
{
    return (a+b+c);
}
