//Sonu Kumar Sharma
//CSE 2nd Year MNNIT Allahabad
//Objective: To find the Euler totient value of given number
//		i.e. phi(n)=?

#include<bits/stdc++.h>
#define max 1000000
typedef long long int ll;
typedef unsigned long long int ull;
typedef long int li;
#define fl(var,start,end) for(var=start;var<end;var++)
#define mod 1000000007
using namespace std;

int main()
{
	int i,n=17,ans=n,final=n;
	if(!(n%2))
		ans=(ans-ans/2);
	while(!(n%2))
		n/=2;
	for(i=3;i*i<=n;i+=2)
	{
		if(!(n%i))
				ans=(ans-ans/i);
			while(!(n%2))
				n/=i;
	}
	if(n>1)
		ans=(ans-ans/n);
	printf("phi(%d)=>%d\n",final,ans);
	return 0;
}
