//Sonu Kumar Sharma
//CSE 2nd Year MNNIT Allahabad
//Objective:	DSU

#include<bits/stdc++.h>
#define max 1000000
typedef long long int ll;
typedef unsigned long long int ull;
typedef long int li;
#define fl(var,start,end) for(var=start;var<end;var++)
#define mod 1000000007
using namespace std;
vector<pair<int,int>  > vec[max];
long D[max]; //dont forget to initialise d with infinity
void dijkastra(int b)
{
	int dis,u,i;
	D[b]=0;
	priority_queue<pair<int,int> ,vector<pair<int,int> >,greater<pair<int,int> > > Q;
	Q.push(make_pair(0,b));
	while(!Q.empty())
	{
		u=Q.top().second;
		dis=Q.top().first;
		Q.pop();

		if(D[u]>=dis)
		{
			fl(i,0,vec[u].size())
		{
				int new_dist=dis+vec[u][i].second;
				int v=vec[u][i].first;
				if(D[v]>new_dist)
				{

					D[v]=new_dist;
					Q.push(make_pair(new_dist,v));
				}

		}
		}

	}

	return ;
}

int main()
{
	freopen("in.txt","r",stdin);

		printf("Enter no. of vertices and edges respectively:\n");
		int n,i,e,r,u,v,w;

		//initialise to infinity

		scanf("%d%d",&n,&e);
		fl(i,0,n+1)
				D[i]=mod;
		fl(i,0,e)
		{
			scanf("%d%d%d",&u,&v,&w);
			vec[u].push_back(make_pair(v,w));

		}
		dijkastra(0);
		printf("%d ",D[1]);

	return 0;
}
