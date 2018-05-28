//Sonu Kumar Sharma
//CSE 2nd Year MNNIT Allahabad
//Objective:To find nCr for n<1000 using identity
//			nCr=(n-1) C r + (n-1) C (r-1)

#include<bits/stdc++.h>
#define max 1000
typedef long long int ll;
typedef unsigned long long int ull;
typedef long int li;
#define fl(var,start,end) for(var=start;var<end;var++)
#define mod 1000000007
using namespace std;
ll ncr[max][max];
int main()
{
	int i,j;
	fl(i,1,max)
	{
		ncr[i][i]=1;
		ncr[i][0]=1;
		ncr[i][1]=i;
	}

	fl(i,1,max)
	{
		fl(j,1,max)
		{
			if(!ncr[i][j])
			ncr[i][j]=(ncr[i-1][j]+ncr[i-1][j-1])%mod;
		}
	}
	fl(i,1,20)
	{
		fl(j,1,i)
	printf("%dC%d=>%lld\n",i,j,ncr[i][j]);
	}
	return 0;
}
