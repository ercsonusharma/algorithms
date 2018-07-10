// Google Kickstart 
//https://code.google.com/codejam/contest/4384486/dashboard

#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <stdlib.h>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <iomanip>
#include <bitset>
#include <math.h>
using namespace std;

int visit[1003], isCycle[1003], parent[1003], level[1003];
vector<int> X[1003];

void markCycle(int i, int goal)
{
	if(isCycle[i])
		return;
	
	isCycle[i] = 1;
	
	if(i == goal)
		return;
	
	markCycle(parent[i], goal);
}

void dfs(int i, int par)
{
	visit[i] = 1;
	parent[i] = par;
	
	for(int j=0; j<X[i].size(); j++)
	{
		if(X[i][j] == par)
			continue;
		
		if(visit[ X[i][j] ])
			markCycle(i, X[i][j]);
		else
			dfs(X[i][j], i);
	}
}

void func(int i, int par, int lvl)
{
	level[i] = lvl;
	
	for(int j=0; j<X[i].size(); j++)
	{
		if(X[i][j] == par || isCycle[ X[i][j] ])
			continue;
		
		func(X[i][j], i, lvl+1);
	}
}

int main()
{
	int T;
	scanf("%d", &T);
	
	for(int test=1; test<=T; test++)
	{
		printf("Case #%d: ", test);
		
		int N;
		scanf("%d", &N);
		
		for(int i=1; i<=N; i++)
		{
			X[i].clear();
			visit[i] = 0, isCycle[i] = 0;
		}
		
		for(int i=1; i<=N; i++)
		{
			int x, y;
			scanf("%d %d", &x, &y);
			
			X[x].push_back(y);
			X[y].push_back(x);
		}
		
		dfs(1, 0);
		
		for(int i=1; i<=N; i++)
		{
			if(isCycle[i])
				func(i, i, 0);
		}
		
		for(int i=1; i<=N; i++)
			printf("%d ", level[i]);
		printf("\n");
	}
	
	return 0;
}
