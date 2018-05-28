#include<stdio.h>
#define size 10
int f(int a[5])
{
        printf("%d\n",sizeof(a));// 4
        return 0;
}
int main()
{
        int a[size];
        printf("%d\n",sizeof(a));// 4*10 = 40
        f(a);	// passed as pointer..actually an address is passed
        return 0;
}

