#include<stdio.h>
#include<math.h>
//factor of a number occurs in pair such that a*b=n when a=b; a*a=n;=>a=sqrt(n)
//If we cannot find a factor of a number less than sqrt(n) then it is guaranteed that one cannot find a factor 
//after that
int isprime(int a)
{
	int i;
	for(i=2;i*i<=a;i++)   //avoid using sqrt function rather than use i*i<=a
	{
		if(a%i==0)
		return 0;
	}
	return 1;
}
int main()
{
	if(isprime(1069))
	printf("Yes\n");
	else
	printf("No\n");
	
}
