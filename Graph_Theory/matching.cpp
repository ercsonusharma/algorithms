
#include<bits/stdc++.h>
using namespace std;

#ifdef ONLINE_JUDGE
#define gc getchar_unlocked
#else
#define gc  getchar
#endif

template<class T>

T readint()
{
	T n;
	char ch = gc();
	while (!(ch>47 && ch<58))
		ch = gc();
	while (ch>47 && ch<58)
	{
		n = n * 10 + ch - '0';
		ch = gc();
	}
	return n;
}


int const add = 50001;
int  matchR[1000000], visited[1000005];
vector<int> adj[100005];




bool bpm(int i,int cons)
{
	for (int j = 0; j < adj[i].size(); j++)
	{
		if (visited[adj[i][j]]!=cons)
		{
			visited[adj[i][j]] = cons;
			//node.push(adj[i][j]);
			if ((matchR[adj[i][j]] == -1) || (bpm(matchR[adj[i][j]],cons)) )
			{
				//matchL[i] = adj[i][j];
				matchR[adj[i][j]] = i;
				return true;
			}
		}
	}
	return false;

}
int main()
{
	//cout << "Welcome back to spoj\n";

	int n, m, e,i,j,u,v;
	scanf("%d%d%d", &n, &m, &e);
	//n = readint<int>();
	//m = readint<int>();
	//e = readint <int>();

	for (i = 0; i < e; i++)
	{
	//	u = readint<int>();
		//v = readint<int>();

		scanf("%d%d", &u, &v);
		v +=n;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	int ans = 0;
	//
//	memset(matchL, -1, sizeof(matchL));
	memset(matchR, -1, sizeof(matchR));

	for (i = 1; i <= n; i++)
	{
		if (bpm(i,2*n+i+m))
		{
			ans++;
		}
	}
	printf("%d\n", ans);


	return 0;
}

//Embeded A+  50+20+15
//SC A+  56+19+15
//WNS A  47+14.5+13
//SE A   42+16+17
//CA A  45+15+15
//DBMS
