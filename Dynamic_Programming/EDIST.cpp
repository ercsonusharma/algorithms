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
		#ifdef ONLINE_JUDGE
		#define gc getchar_unlocked
		#else
		#define gc  getchar
		#endif
        using namespace std;
        template<class T>

		T readint()
        {
        	T n;
        	char ch=gc();
        	while(!(ch>47&&ch<58))
        		ch=gc();
        	while(ch>47&&ch<58)
        	{
        		n=n*10+ch-'0';
        		ch=gc();
        	}
        	return n;
        }

        char str1[2005],str2[2005];
        int dp[2005][2005];

        int edit(int l,int r)
        {
        	if(l==0&&r==0)
        		return 0;
        	if(l==0)
        		return r;
        	if(r==0)
        		return l;
        	if(dp[l][r])
        		return dp[l][r];


        		return dp[l][r]=min((str1[l-1]!=str2[r-1])+edit(l-1,r-1),min(1+edit(l-1,r),1+edit(l,r-1)));


        }

int main()
{
	int t;
	in(t);
	while(t--)
	{
		memset(dp,0,sizeof(dp));
instr(str1);
instr(str2);
int l=strlen(str1);
int r=strlen(str2);

printf("%d\n",edit(l,r));

	}
return 0;
}
