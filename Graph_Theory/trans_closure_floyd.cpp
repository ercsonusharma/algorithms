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

int dist[1000][1000];		// initialised  just like adjacency matrix else with 0
//finally after calling floyd function it will contain 1 b/w two vertices if a path exists else 0

vector<pair<int,int>  > vec[max];

void transitive_closure(int n)
{
	int i,j,k;
	for(k=0;k<n;k++)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
		{
				dist[i][j]=(dist[i][j] || (dist[i][k] && dist[k][j] ));
		}
		}
	}
}

int main()
{
	freopen("in.txt","r",stdin);

		printf("Enter no. of vertices and edges respectively:\n");
		int n,i,e,r,u,v,w;

		//initialise to infinity

		scanf("%d%d",&n,&e);

		fl(i,0,e)
		{
			scanf("%d%d%d",&u,&v,&w);
			//vec[u].push_back(make_pair(v,w));
			//vec[v].push_back(make_pair(u,w));
			dist[u][v]=w;

		}
		transitive_closure(n);
		printf("%d ",dist[0][3]);

	return 0;
}
