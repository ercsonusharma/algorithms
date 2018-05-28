#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <cassert>
#define rf freopen("in.in", "r", stdin)
#define wf freopen("out.out", "w", stdout)
#define rep(i, s, n) for(int i=int(s); i<=int(n); ++i)
using namespace std;
const int mx = 1e5 + 10, mod = 1e9+7;

char S1[1111], S2[1111];
int D[1111][1111], L[1111][1111];
int pointer_S1[1111][26], pointer_S2[1111][26];
int n, k;

void Calc_LCS_Number()
{
	for(int i = n; i; --i)
	{
		for(int j = n; j; --j)
		{
			if(S1[i-1] == S2[j-1])
			{
				L[i][j] = L[i+1][j+1] + 1;
				D[i][j] = D[i+1][j+1];
			}
			else
			{
				L[i][j] = max(L[i+1][j], L[i][j+1]);

				if(L[i+1][j] == L[i][j])
					D[i][j] = D[i][j] + D[i+1][j];

				if(L[i][j+1] == L[i][j])
					D[i][j] = D[i][j] + D[i][j+1];

				if(L[i][j] == L[i+1][j+1])
					D[i][j] -= D[i+1][j+1];

				if(D[i][j] >= mod)
					D[i][j] = mod;
			}
		}
	}
}

void pre_process()
{
	memset(pointer_S1, -1, sizeof pointer_S1);
	memset(pointer_S2, -1, sizeof pointer_S2);

	for(int i = n; i>=0; --i)
	{
		for(int j = 0; j<26; ++j)
		{
			if(pointer_S1[i][j] == -1)
				pointer_S1[i][j] = pointer_S1[i+1][j];
			if(pointer_S2[i][j] == -1)
				pointer_S2[i][j] = pointer_S2[i+1][j];
		}

		if(i)
			pointer_S1[i-1][S1[i-1]-'a'] = i,
			pointer_S2[i-1][S2[i-1]-'a'] = i;
	}
}

string final_process()
{
	string ret = "";
	int idx_S1 = 0, idx_S2 = 0;
	L[0][0] = L[1][1] + 1;
	int cnt = 0;

	while(L[idx_S1][idx_S2] > 1)
	{
		int count = 0, new_count = 0;

		for(int letter = 0; letter<26; ++letter)
		{
			int tmp_S1 = pointer_S1[idx_S1][letter];
			int tmp_S2 = pointer_S2[idx_S2][letter];

			if(tmp_S1 == -1 || tmp_S2 == -1)
				continue;
			if(L[idx_S1][idx_S2] != L[tmp_S1][tmp_S2]+1)
				continue;

			new_count = count + D[tmp_S1][tmp_S2];
			if(new_count >= mod)
				new_count = mod;

			if(count < k && k <= new_count)
			{
				k-=count;
				ret += (char)('a' + letter);
				idx_S1 = tmp_S1;
				idx_S2 = tmp_S2;
				break;
			}

			count = new_count;
		}
	}

	return ret;
}

int main()
{
	//rf;// wf;
	ios::sync_with_stdio(0);

	cin >> n >> k;
	cin >> S1 >> S2;
	pre_process();

	for(int i = 1; i<=n+1; ++i)
		D[n+1][i] = D[i][n+1] = 1;

	Calc_LCS_Number();
	if(D[1][1] < k)
		printf("-1\n");
	else
		cout << final_process() << '\n';

	return 0;
}
