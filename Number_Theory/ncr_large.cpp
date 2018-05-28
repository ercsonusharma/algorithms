//Sonu Kumar Sharma
//CSE 2nd Year MNNIT Allahabad
//Objective:To find nCr for n<10^6 using
//			Little Fermat's Theorem i.e. a^(-1) mod m =(a^(m-2))mod m

#include<bits/stdc++.h>
#define max 1000000
typedef long long int ll;
typedef unsigned long long int ull;
typedef long int li;
#define fl(var,start,end) for(var=start;var<end;var++)
#define mod 1000000007
using namespace std;
ll fact[max],inv[max];
ull power(ll a,ll b)
{
	if(b==0)
		return 1;
	if(b%2)
	return ((a%mod)*power(a,b-1))%mod;
	else
	{
		ull temp=power(a,b/2);
		return ((temp%mod)*(temp%mod))%mod;
	}
}
int main()
{
	int i;
	//calculating factorial first %mod
	fact[0]=1;
	fl(i,1,max+1)
	{
		fact[i]=(i*fact[i-1])%mod;
	}
//	printf("fact[5]=%lld\n",fact[5]);
	//calculating inverse of max
	inv[max]=power(fact[max],mod-2)%mod;
	//with the help of inverse of max finding all other inverse
	//i.e. ((r-1)!)^(-1) = r * (r!^(-1))
	for(i=max-1;i>0;i--)
	{
		inv[i]=((i+1)*inv[i+1])%mod;
	}

	int n=10,r=2;
	//applying formula nCr

	ull ans=fact[n]%mod;
	ans=(ans*inv[n-r])%mod;
	ans=(ans*inv[r])%mod;
	printf("%dC%d=>%lld\n",n,r,ans);
	return 0;
}
