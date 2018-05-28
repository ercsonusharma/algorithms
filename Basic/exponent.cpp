#include<stdio.h>
//Power of a to the b in O(log(b))
//Recursive Version
int poweritr(int a,int b)
{
	int p=1,temp;
	if(b==0)
	return 1;
	if(b%2==0)
	{
			temp=poweritr(a,b/2);
		return temp*temp;
	}
	else
	{
		return a*poweritr(a,b-1);
	}
}
//Modular Exponentiation
int powerrec(int a,int b,int k)
{
	int temp;
	if(b==0)
	return 1;
	if(b%2==0)
	{
		temp=powerrec(a,b/2,k);
		return ((temp%k)*(temp%k)%k);
	}
	else
	return ((a%k)*(powerrec(a,b-1,k))%k);
}
int main ()
{

	printf("powrec=%d\n",powerrec(3,9,111111));
//	printf("powiter=%d\n",poweritr(2,10));
  return 0;
}
