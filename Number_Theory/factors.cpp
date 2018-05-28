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

int divisors[1000005];
void noofdivisors()
{
	int i,j;
	for (i = 2; i*i <= 1000006; i++)
	{

		for (j = 2 * i; j <= 1000006; j += i)
		{
			if (i*i<=j)
			divisors[j]++;
			if (i*i < j)
				divisors[j]++;

		}
	}
}
bool prime[500];
void genprime()
{
	int i,j;
	for (i = 2; i*i <= 300; i++)
	{
		if (!prime[i])
		{
			for (j = 2 * i; j < 300; j += i)
				prime[j] = true;

		}
	}
}
bool isproduct[500];
void product()
{
	int i,j;
	for (i = 2; i < 250; i++)
	{
		if (!prime[i])
		{

			for (j = 3; j < 250; j++)
			{
				if ((i*j<250)&&(j != i)&&(!prime[j]))
				{
					isproduct[i*j] = true;
				}

			}
		}
	}
}
int main()
{
	noofdivisors();
	genprime();
	product();
	int i,maxx=0,c=0;

	//for (i = 0; i < 250;i++)
	//if (isproduct[i])
		//cout << i << " ";

	for (i = 2; i <= 1000006; i++)
	{
		divisors[i]+=2;
		if (isproduct[divisors[i]])
		{
			c++;
			if (!(c % 9))
				printf("%d\n", i);
		}
	}

	return 0;
}

