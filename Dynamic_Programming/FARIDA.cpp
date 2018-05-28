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
      int far(int idx,int flag)
      {
    	  if(idx==n)
    		  return 0;
    	  int ans=far(idx+1,0);
    	  if(flag==0)
    	  {
    		  ans=max(ans,arr[idx]+far(idx+1,1));
    		  printf("idx=%d ans=%d\n",idx,ans);
    	  }
    	  return ans;
      }

int main()
{

	int i;
in(n);
inc(i,0,n)
{
	in(arr[i]);
}
cout<<far(0,0);
return 0;
}
