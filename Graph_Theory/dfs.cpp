//Sonu Kumar Sharma
//CSE 2nd Year MNNIT Allahabad
//Objective: Iterative approach/Recursive approach for Inorder Traversal

#include<bits/stdc++.h>
#define max 100000
typedef long long int ll;
typedef unsigned long long int ull;
typedef long int li;
#define fl(var,start,end) for(var=start;var<end;var++)
#define mod 1000000007
using namespace std;
vector<int> adj[max];  //sort the vector if result is expected in sorted order

//dfs recursive
bool visitedr[max];
void dfsrec(int u)
{
	if(!visitedr[u])
			{
				printf("%d ",u);
				visitedr[u]=true;
			}
	int i;
	fl(i,0,adj[u].size())
	{
		if(!visitedr[adj[u][i]])
			dfsrec(adj[u][i]);
	}

}

//dfs iterative function

void dfs(int b)
{
	bool visited[max];
	unsigned int i;
	stack<int> st;
	st.push(b);
	while(!st.empty())
	{
		int u=st.top();
		st.pop();
		if(!visited[u])
		{
			printf("%d ",u);
			visited[u]=true;
		}

		for(i=adj[u].size()-1;i>=0;--i)
		{
			int node=adj[u][i];
			if(!visited[node])
			{
				st.push(node);
			//	printf("push=%d ",node);
			}
		}
	//	printf("\n");
	}

}
int main()
{
	freopen("in.txt","r",stdin);
	/*
	 * tested on in.txt (both dfs and bfs)
	 * 10 15
0 1
0 3
1 2
2 3
1 5
5 6
2 5
3 6
1 4
4 7
5 7
5 8
6 9
7 8
8 9
	 */
	printf("Enter no. of vertices and edges respectively:\n");
	int n,i,e,r,u,v;
	scanf("%d%d",&n,&e);
	fl(i,0,e)
	{
		scanf("%d%d",&u,&v);
		adj[u].push_back(v);
	//	adj[v].push_back(u);   //comment this if graph is directed
	}

	fl(i,0,n)
	{
		sort(adj[i].begin(),adj[i].end());
	}
	dfsrec(0);  //start bfs with starting edge

	return 0;
}
