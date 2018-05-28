
#include"stdafx.h"
#include <bits/stdc++.h>
using namespace std;
long arr[105][105];
int main() {
	long long n, m, x;
	cin >> n >> m;
	int i, j;
	vector<long long> cityw, sum;
	
	for (i = 0; i < m; i++)
	{
		int xx = 0;
		x = 0;
		for (j = 0; j < n; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j]>x)
			{
				x = arr[i][j];
				xx = j;
			}
			if (!i)
				sum.push_back(arr[i][j]);
			else
				sum[j] += arr[i][j];

		}
		cityw.push_back(xx);
	}
	int xx = 0; x = 0;
	for (i = 0; i < cityw.size(); i++)
	{
		if (sum[cityw[i]]>x)

		{
			xx = cityw[i] + 1;
			x = sum[cityw[i]];
		}
	}

	cout << xx << "\n";
	return 0;
}