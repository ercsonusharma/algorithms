//Spoj DQUERY


#include<bits/stdc++.h>
using namespace std;
#define maxx 1000005
#define ll long long

int arr[maxx],print[maxx];
vector<pair<int, pair<int,int> > > block[500];
vector<pair<int,pair<int,int> > > query;

bool cmpf(pair<int,pair< int,int> >&a, pair<int, pair<int,int> >&b)
{
	return a.second.first < b.second.first;
}
int freq[10 * maxx], ans;
inline void addfreq(int pos,int count)
{
	freq[arr[pos]]++;
	if (freq[arr[pos]] == 1)
		ans++;

}

inline void removefreq(int pos, int count)
{
	freq[arr[pos]]--;
	if (freq[arr[pos]]==0)
		ans--;

}
int main()
{
	int n,i,q,j;
	scanf("%d", &n);

	for (i = 0; i < n; i++)
		scanf("%d", arr + i);

	scanf("%d", &q);
	int u, v;
	for (i = 0; i < q;i++)
	{

		scanf("%d%d", &u, &v);
		query.push_back(make_pair(u-1,make_pair(v-1,i)));
	}
	sort(query.begin(), query.end());
	int sqrtn = sqrt(n);

	int k = 0;
	for (i = 0,j=0; i*i <= n; i++)
	{
		for (; j < ((i + 1)*sqrtn) && (j<n); j++)
		{
			while (k<query.size()&&(query[k].first <= j))
				block[i].push_back(query[k]),k++;
		}

	}
	for (i = 0; i*i <= n; i++)
		sort(block[i].begin(), block[i].end(), cmpf);



	int currentL = 0, currentR = 0;
	ans = 0;
	for (i = 0; i*i <= n; i++)
	{
		for (j = 0; j < block[i].size(); j++)
		{
			int l = block[i][j].first;
			int r = block[i][j].second.first;

			while (currentL < l)
			{
				removefreq(currentL, 3), currentL++;
			}
			while (currentL > l)
			{
				addfreq(currentL - 1, 3), currentL--;
			}
			while (currentR <= r)
			{
				addfreq(currentR, 3), currentR++;
			}
			while (currentR > r + 1)
			{
				removefreq(currentR - 1, 3), currentR--;
			}
			print[block[i][j].second.second] = ans;
		}

	}
	for (i = 0; i < q; i++)
		printf("%d\n", print[i]);

	return 0;
}


