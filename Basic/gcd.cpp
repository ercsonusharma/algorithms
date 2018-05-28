#include<bits/stdc++.h>
using namespace std;
//Euclidean
//Iterative version
int gcditer(int a,int b)
{
	while(a!=b)
	{
		if(a>b)
		a=a-b;
		else
		b=b-a;
	}
	return a;
}
//Recursive Version
int gcdrec(int a,int b)
{
	if(a==b)
	return a;
	if(a>b)
	 gcdrec(a-b,b);
	else
	 gcdrec(a,b-a);
	return a;
}
//No Euclidean   Replace - with % and a!=b with b!=0
//Recursive Version
int gcdrc(int a,int b)
{
	if(b==0)
	return a;
	else if(a>b)
	return gcdrc(a%b,b);
	else
	return gcdrc(a,b%a);
	
}
//Iterative Version 
int gcditr(int a,int b)
{
	while(b!=0)
	{
		if(a>b)
		a=a%b;
		else
		b=b%a;
	}
	return a;
}
int main ()
{
	int a,b;
	freopen("in.txt","r",stdin);
	scanf("%d%d",&a,&b);
	printf("fget=%d %d\n",a,b);
	//printf("gcditr=%d\n",gcditr(7,10));
	//printf("gcdrc=%d\n",gcdrc(7,10));
	printf("gcdrec=%d\n",gcdrec(a,b));
	//printf("gcditer=%d\n",gcditer(7,10));
  return 0;
}
