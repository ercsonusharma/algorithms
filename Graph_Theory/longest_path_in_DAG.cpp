
//output-longest path in a given DAG

#include<bits/stdc++.h>
using namespace std;

bool visited[1000005];
vector<pair<int,int> > adj[100005];
stack<int> ver;
void dfs(int v)
{
	visited[v] = true;

	int i;
	for (i = 0; i < adj[v].size(); i++)
	{
		if (!visited[adj[v][i].first])
			dfs(adj[v][i].first);
	}
	ver.push(v);

}

int d[100005];

int main()
{
	//cout << "Welcome back to spoj\n";

	int n, m, i, v, u,c;
	scanf("%d", &n);
	for (i = 0; i < n-1; i++)
	{
		scanf("%d%d%d",&u,&v,&c);
		adj[u].push_back(make_pair(v,c));
	}

	//topological ordering
	for (i = 1; i <= n; i++)
	{
		if((!adj[i].empty())&&(!visited[i]))
		dfs(i);
	}



	/*
	while (!ver.empty())
		cout << ver.top()<<"\n",ver.pop();
		*/


	memset(visited, 0, sizeof(visited));
	for (i = 0; i <= n; i++)
		d[i] = -INT_MAX;

	v = ver.top();
	d[v] = 0;
	while (!ver.empty())
	{
		v = ver.top();
		ver.pop();

		for (i = 0; i < adj[v].size(); i++)
		{
			if (d[adj[v][i].first] < d[v] + adj[v][i].second)
				d[adj[v][i].first] = d[v] + adj[v][i].second;
		}

	}
	int mx = 0;
	for (i = 0; i <= n; i++)
		if (d[i] > mx)
			mx = d[i];

	cout << mx << "\n";


	return 0;
}

