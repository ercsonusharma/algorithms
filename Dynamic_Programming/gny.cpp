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
ull dp[300][2],n,m;
ull gny(int idx,int flag,int m)
{


	if(idx>n)
	{
		if(!m)
			return 1;
		return 0;
	}
	if(dp[m][flag])
						return dp[m][flag];
	ull ans=gny(idx+1,0,m);
//	cout<<"idx="<<idx<<" ans="<<ans<<endl;

	if(flag==1)
	{
		if(m>0)
		ans+=gny(idx+1,1,m-1);
	}
	else
		ans+=gny(idx+1,1,m);

	return dp[m][flag]=ans;
}

int main()
{
int i,t,x,j;
in(t);

while(t--)
{
in(x);
in2(n,m);

printf("%d %lld\n",x,gny(1,0,m));

}
return 0;
}
