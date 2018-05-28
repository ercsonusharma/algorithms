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


int main()
{
	int t,i,j;
	string str;
in(t);
vector<string::iterator> pre[6];
while(t--)
{
		cin>>str;
	for(string ::iterator it=str.begin();it!=str.end();)
	{
		if(*it=='%')
			pre[0].push_back(it+1);
		else if(*it=='/')
				pre[1].push_back(it+1);
		else if(*it=='*')
						pre[2].push_back(it+1);
		else if(*it=='-')
						pre[3].push_back(it+1);
		else if(*it=='+')
						pre[4].push_back(it+1);

		if(*it==')'||*it=='(')
		{
			str.erase(it);
		}
		else
			it++;
	}
	int len=str.size();


for(i=0;i<5;i++)
{
	for(j=0;j<pre[i].size();j++)
	{
		string ::iterator itt=pre[i][j];
		while((*pre[i][j]>48&&(*pre[i][j]<58))||((*pre[i][j]!=')')&&pre[i][j]!=str.end()))
			pre[i][j]++;
		str.insert(pre[i][j],')');


		itt-=2;
		cout<<*itt<<endl;
		while((*itt>48&&(*itt<58))||((*itt!='(')&&itt!=str.begin()))
		{
			if(itt==str.begin())
				break;
					itt--;
		}		str.insert(itt,'(');
		cout<<*itt<<endl;

	}
}

	cout<<str;
	str.clear();

}

return 0;
}
