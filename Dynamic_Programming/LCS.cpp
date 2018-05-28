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
        int n,arr[100];

li dp[2][maxx];
char str1[maxx],str10[maxx];

int main()
{
instr(str1);
instr(str10);
int len1=strlen(str1),len10=strlen(str10);
int k=1,i,j;
dp[0][0]=0;

for(i=1;i<=len1;i++)
{
	for(j=1;j<=len10;j++)
	{
		if(str1[i-1]==str10[j-1])
		{
			dp[k][j]=1+dp[1-k][j-1];
		}
		else
			dp[k][j]=max(dp[1-k][j],dp[k][j-1]);
	}
	k=1-k;
}
printf("%ld\n",dp[len1%2][j-1]);
return 0;
}
