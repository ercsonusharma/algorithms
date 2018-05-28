#include<stdio.h>
//For factorial calcualtion
//recursive Version
int factrec(int a)
{
	if(a==0)
	return 1;
	return (a*factrec(a-1));
	
}
//Iterative Version
int factiter(int a)
{
	int p=1;
	while(a>1)
	{
		p=p*a;
		--a;
	}
	return p;
}
int main()
{
	printf("factrec=%d",factrec(5));
	printf("factiter=%d",factiter(1));
	
}
