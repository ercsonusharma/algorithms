//Sonu Kumar Sharma
//CSE 2nd Year MNNIT Allahabad
//Objective:


		#include<bits/stdc++.h>
        #define maxx 100005
        typedef long long int ll;
        typedef unsigned long long int ull;
        typedef long int li;
        #define inc(var,start,end) for(var=start;var<end;++var)
		#define dec(var,start,end) for(var=start;var>end;--var)
		#define in(a) scanf("%d",&a);
		#define in2(a,b) scanf("%d%d",&a,&b);
		#define f(a) scanf("%f",&a);
		#define f2(a) scanf("%f%f",&a,&b);
		#define instr(a) scanf("%s",a);
		#define inll(a) scanf("%lld",&a);
		#define in2ll(a,b) scanf("%lld%lld",&a,&b);
		#define fl(a) scanf("%lf",&a);
		#define f2l(a) scanf("%lf%lf",&a,&b);
		#define instr(a) scanf("%s",a);
        #define mod 1000000007
        using namespace std;
        int n,arr[100];

int b[maxx],dp[maxx];

int main()
{

	int i,j;
in(n);
inc(i,1,n+1)
{
	in(b[i]);
}

int lb;
dp[0]=0;
inc(i,1,n+1)
{
	lb=0;
	inc(j,1,i+1)
		{
		lb=max(lb,b[j]+dp[i-j]);
		}
	dp[i]=lb;
}
inc(i,0,n+1)
cout<<dp[i]<<endl;
return 0;
}
