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

        char str[100];
        int dp[1000][1000];
        int lps(int l,int r)
        {
        	if(l>r)
        		return 0;
        	if(l==r)
        		return 1;
        	if(dp[l][r])
        		return dp[l][r];

        	if(str[l]==str[r]&&(r-l==1))
        	        return 2;
        	int ans=lps(l+1,r);
        	if(str[l]==str[r])
        	       return 2+lps(l+1,r-1);

        	else

        		ans=max(ans,lps(l,r-1));
        	return dp[l][r]=ans;
        }
int main()
{

	instr(str);
	cout<<lps(0,strlen(str)-1);

return 0;
}
