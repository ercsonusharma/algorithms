#include<stdio.h>
//Fibonnaci Sequence
int f[51];
//Recursive Version    *********
//Never********Ever ***********Ever 
int Fiborec(int n)   //However it is optimised using recursion with memoisation but it takes space of array[51]
{
	if(n<2)
	return n;
	if(f[n]!=0)
	return f[n];
	else
	f[n]=(Fiborec(n-1)+Fiborec(n-2));
	return f[n];
	
}
//******Again**********use recursive method
//Iterative method
void Fibiter(int n)
{
	int a=0,b=1,c,i=2;
	printf("\t0\t1");
	while(i<=n)
	{
		c=a+b;
		a=b;
		b=c;
		printf("\t%d",b);
	i++;
}
}
int main()
{
	
	printf("%d",Fiborec(40));
	Fibiter(40);
;	return 0;
}
