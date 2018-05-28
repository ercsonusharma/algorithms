

//strongly connected components in digraph
#include<bits/stdc++.h>
using namespace std;

bool visited[1000005];
vector<int> adj[100005],new_adj[100005];
stack<int> ver;
void dfs(int v)
{
	visited[v] = true;

	int i;
	for (i = 0; i < adj[v].size(); i++)
	{
		if (!visited[adj[v][i]])
			dfs(adj[v][i]);
	}
	ver.push(v);

}



void dfs2(int v)
{
	visited[v] = true;
	int i;
	cout << v << " ";
	for (i = 0; i <new_adj[v].size(); i++)
	{
		if (!visited[new_adj[v][i]])
			dfs2(new_adj[v][i]);
	}


}

int main()
{
	//cout << "Welcome back to spoj\n";

	int n, m, i, v, u;
	cin >> n >> m;
	for (i = 0; i < m; i++)
	{
		cin >> u >> v;
		adj[u].push_back(v);
	}

	//topological ordering
	for (i = 1; i <= n; i++)
	{
		if(!visited[i])
		dfs(i);
	}


	/*

	while (!ver.empty())
		cout << ver.top()<<"\n",ver.pop();

		*/

	//transpose of graph
	for (i = 1; i <= n; i++)
	{

		for (int j = 0; j < adj[i].size(); j++)
			new_adj[adj[i][j]].push_back(i);

	}

	//work on new_adj graph

	memset(visited, 0, sizeof(visited));

	while (!ver.empty())
	{
		v = ver.top();
		ver.pop();

		if (!visited[v])
		{
			dfs2(v);
			cout << "\n";
		}
	}
	return 0;
}

