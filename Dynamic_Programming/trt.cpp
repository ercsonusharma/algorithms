//Sonu Kumar Sharma
//CSE 2nd Year MNNIT Allahabad
//Objective:


		#include<bits/stdc++.h>
        #define maxx 250010
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
ull dp[2005][2005],n;
ll arr[maxx];

ll trt(int l,int r,int cnt)
{
	if(l>r)
		return 0;
	if(dp[l][r])
		return dp[l][r];
	if(l==r)
		return cnt*arr[l];
	ll ans=arr[l]*cnt+trt(l+1,r,cnt+1);
	ans=max(ans,arr[r]*cnt+trt(l,r-1,cnt+1));
	return dp[l][r]=ans;

}
int main()
{
int i,t,x,j;

in(n);
inc(i,0,n)
inll(arr[i]);

printf("%lld\n",trt(0,n-1,1));


return 0;
}
