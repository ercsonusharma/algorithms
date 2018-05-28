//Sonu Kumar Sharma
//CSE 2nd Year MNNIT Allahabad
//Objective:
//
//modi

//modify  for larger value of n ---but diff < 10^5

#include<bits/stdc++.h>
#define max max_length
typedef long long int ll;
typedef unsigned long long int ull;
typedef long int li;
#define fl(var,start,end) for(var=start;var<end;var++)
using namespace std;
int main()
{

	int n=100000,i,j,prime[100000];

	for(i=2;i*i<=n;i++)
	{
		if(!prime[i])
		{
		for(j=i;j<n;j+=i)
		{
			if((!(j%i))&&(j!=i))
				prime[j]=1;
		}
		}
	}

	printf("Prime:\n");
	fl(i,2,n)
	if(!prime[i])
	printf("%d ",i);


	return 0;
}
