// ConsoleApplication3.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll power(ll a, ll b, ll mod)
{
	if (!b)
		return 1;
	else if (b & 1)
		return (a*power(a,b - 1,mod))%mod;
	else
	{
		ll temp = power(a,b / 2,mod)%mod;
		return (temp*temp)%mod;
	}
}


ll arr[50];
vector<ll> a, b;
void powerset(int x,int y,vector<ll>& vec)
{
	int i, j, k=0;
	ll sum = 0;
	int len = 1 << (y - x+1);
	for (i = 0; i < (len); i++)
	{
		sum = 0;
		for (j = 0; j < (y - x + 1); j++)
		{
			if (i&(1 << j))
			{
				sum += arr[j+x];
			}
		}
		vec.push_back(sum);
	}
}

ll mitm(int x, int y,int n)
{
	int i, j, k;
	ll ans = 0;
	/*
	for (i = 0; i < a.size(); i++)
		cout << a[i] << " ";
	cout << "\n";
	for (i = 0; i < b.size(); i++)
		cout << b[i] << " ";
		*/

	sort(b.begin(), b.end());
	for (i = 0; i < a.size(); i++)
	{
		ll ub = y - a[i];
		ll lb = x - a[i];
		ans += upper_bound(b.begin(), b.end(), ub) - lower_bound(b.begin(), b.end(), lb);

	}
	return ans;
}

int main()
{
	int n,i,j,k;
	ll x, y;
	scanf("%d%lld%lld", &n, &x, &y);
	for (i = 0; i < n; i++)
		scanf("%lld", arr + i);

	powerset(0, n / 2, a);
	powerset((n / 2) + 1, n-1, b);
	cout << mitm(x, y, n) << "\n";
	return 0;
}
