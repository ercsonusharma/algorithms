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

int dist[1000][1000];		// initialised first with infinity..... then just like adjacency matrix
//finally after calling floyd function it will contain the shortest distance b/w two vertices

vector<pair<int,int>  > vec[max];

void floyd(int n)
{
	int i,j,k;
	for(k=0;k<n;k++)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
		{
				if(dist[i][j]>dist[i][k]+dist[k][j])
							dist[i][j]=dist[i][k]+dist[k][j];

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
		fl(i,0,n)
		fl(r,0,n)
		dist[i][r]=mod;
		fl(i,0,e)
		{
			scanf("%d%d%d",&u,&v,&w);
			//vec[u].push_back(make_pair(v,w));
			//vec[v].push_back(make_pair(u,w));
			dist[u][v]=w;

		}
		floyd(n);
		printf("%d ",dist[0][6]);

	return 0;
}
