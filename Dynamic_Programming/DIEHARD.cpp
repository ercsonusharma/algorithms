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
ull dp[3005][3005];
ull dhard(int h,int a,int flag)
{
	if(h<=0||a<=0)
		return 0;
	ull ans1=0,ans2=0,ans3=0;
	if(dp[h][a]!=-1)
		return dp[h][a];
	if(flag!=0)
	ans1+=1+dhard(h+3,a+2,0);
	if(flag!=1)
	ans2+=1+dhard(h-5,a-10,1);
	if(flag!=2)
	ans3+=1+dhard(h-20,a+5,2);
	return dp[h][a]=max(ans1,max(ans2,ans3));

}
int main()
{
int i,n,arr[maxx],j;
in(n);

while(n--)
{
	inc(i,0,3005)
	inc(j,0,3005)
	dp[i][j]=-1;
in2(i,j);

printf("%lld\n",dhard(i,j,1)-1);

}
return 0;
}
