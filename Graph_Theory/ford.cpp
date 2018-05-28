// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
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
#define  mp make_pair

int dx[] = { 1, 1, 1, 0, 0, -1, -1, -1 };
int dy[] = { 0, 1, -1, 1, -1, 1, 0, -1 };


using namespace std;
vector<int> arr;
vector<int> adj[1000];
bool visited[1000];
stack<int> st;
int sum;
int wt[1000][1000];
int parent[1000];
bool bfs(int s)
{
	queue<int> q;
	q.push(s);
	memset(parent, 0, sizeof(parent));
	memset(visited, 0, sizeof(visited));
	visited[s] = 1;
	while (!q.empty())
	{
		int u = q.front();
		q.pop();

		int i;
		inc(i, 0, adj[u].size())
		{
			int node = adj[u][i];
			if ((!visited[node])&&(wt[u][node]>0))
			{
				visited[node] = true;
				parent[node] = u;
			//	cout << "node=" << node << " weighy=" << wt[u][node] << " ";
				q.push(node);
			}
		}

	}
	if (visited['Z' - '0'])
		return true;
	else
		return false;

}
int ford()
{
	int max_flow=0;
	int i,min_flow=INT_MAX;
	int u = 'A' - '0', v = 'Z' - '0',s;
	while (bfs('A' - '0'))
	{
		//cout << "befsore";
		for (v = ('Z' - '0'); v != ('A' - '0'); v = parent[v])
		{
		//	cout << "v=" << v << " ";
			u = parent[v];
			min_flow = min(min_flow, wt[u][v]);
		}

		for (v = ('Z' - '0'); v != ('A' - '0'); v = parent[v])
		{
			u = parent[v];
			wt[u][v] -= min_flow;
			wt[v][u] += min_flow;
		}
		max_flow += min_flow;
	//	cout << "after";
	}
//	bfs('A' - '0');
	return max_flow;
}
int main()
{
	int n;
	char x, y;
	cin >> n;
	int i,p;

	inc(i, 0, n)
	{
		cin >> x >> y;

		if (wt[x-'0'][y-'0'])
		{
			cin >> p;
			wt[x - '0'][y - '0'] += p;
		}
		else
		{
			cin >> wt[x - '0'][y - '0'];

			adj[x - '0'].push_back(y - '0');
		}
	}

	cout<<ford()<<"\n";

	return 0;
}
