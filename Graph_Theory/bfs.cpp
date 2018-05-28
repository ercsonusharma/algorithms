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

//bfs function
void bfs(int b)
{
	bool visited[max];
	queue<int> q;
	unsigned int i;
	q.push(b);

	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		visited[b]=true;
		printf("%d ",u);

		/*for adjacency matrix
		 * fl(i,0,n)  //n is the  vertices with larger magnitude
		 * {
		 * 		if(adj[u][i] && (!visited[i]))
		 * 		{
		 * 		q.push(i);
		 * 		visited[i]=true;
		 * 		}
		 * }
		 * comment down the below snipet and uncomment the current one
		 */

		fl(i,0,adj[u].size())
		{
			int node=adj[u][i];
			if(!visited[node])
			{
				q.push(node);
				visited[node]=true;
			}
		}
	}

}
int main()
{
	freopen("in.txt","r",stdin);
	printf("Enter no. of vertices and edges respectively:\n");
	int n,i,e,r,u,v;
	scanf("%d%d",&n,&e);
	fl(i,0,e)
	{
		scanf("%d%d",&u,&v);
		adj[u].push_back(v);
		adj[v].push_back(u);   //comment this if graph is directed
	}
	bfs(0);  //start bfs with starting edge

	return 0;
}
