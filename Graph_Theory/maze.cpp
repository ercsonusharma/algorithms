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
		#define ii pair<int,int>
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
        ll d[200][200];
       bool visited[200][200];
       int dx[]={1,1,1,0,0,-1,-1,-1};
       int dy[]={0,1,-1,1,-1,1,0,-1};
       int n,m;

       int isvalid(int x,int y)
       {
    	   if(x>=0&&y>=0&&x<n&&y<m)
    		   return 1;
    	   return 0;
       }
void solve(int x,int y)
{
	queue<ii> q;
	q.push(make_pair(x,y));
	visited[x][y]=true;
	int xx,yy,i;
	while(!q.empty())
	{
		xx=q.front().first;
		yy=q.front().second;
		q.pop();

		if(!visited[xx][yy])
		{
			inc(i,0,8)
		{
			if(isvalid(xx+dx[i],yy+dy[i]))
			{
				q.push(make_pair(xx+dx[i],yy+dy[i]));
				visited[xx+dx[i]][yy+dy[i]]=true;
			}
		}
		}

	}
}
int main()
{
	int t,i,j;
	in(t);
	char str[200][200];
	while(t--)
	{

		in2(n,m);
		inc(i,0,n)
		instr(str[i]);



	}
return 0;
}
