// ConsoleApplication1.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include<bits/stdc++.h>
using namespace std;
#define MAX 200015
#define MOD1  1000000007
#define MOD2 1000000006
#define MOD3 500000003
#define MOD4 2
#define MOD5 41
#define MOD6 1681
#define MOD7 148721



#define ll long long

ll a_2[MAX][2], b_41[MAX][2], c_148721[MAX];

long long power(long long a, long long b, long long mod)
{
	if (!b)
		return 1;
	if (b & 1)
		return a*power(a, b - 1, mod)%mod;
	else
	{
		long long temp = power(a, (b>>1LL), mod)%mod;
		return (temp*temp) % mod;
	}
}

ll inverse_iterative(ll a, ll mod)
{
	int i = 1;
	while (1)
	{
		if ((a*i) % mod == 1)
			return i;
		i++;
	}
}

ll inversemod(ll a,ll mod)
{
	return power(a, mod - 2, mod);
}
long long crt2(long long n1, long long n2, long long m1, long long m2)
{
	ll mod = m1*m2;
	ll a1 = m2;
	ll a2 = m1;
	ll alpha1 = inversemod(a1, m1);
	ll alpha2 = inversemod(a2, m2);
	return ((a1*n1*(alpha1)) % mod + (a2*(alpha2)*n2) % mod)%mod;

}
ll crt3(ll x1, ll x2, ll x3, ll m1, ll m2, ll m3)
{
	ll mod = m1*m2*m3;
	ll a1 = m2*m3;
	ll alpha1 = inversemod(a1, m1);
	ll a2 = m1*m3;
	ll alpha2 = inverse_iterative(a2, m2);
	ll a3 = m1*m2;
	ll alpha3 = inversemod(a3, m3);
	//cout << "invers1" << alpha1 << " " << alpha2 << " " << alpha3<<" ";
	//cout << "a =" << a1 << " " << a2 << " " << a3 << " ";

	return (((a1*x1*alpha1) % mod) + ((a2*(alpha2)*x2) % mod) +((a3*x3*alpha3) % mod)) % mod;

}


int main()
{

	//cout << power(297442, 1679, 1681);

	int i, t;
	ll a, b, n;
	a_2[0][0] = 1; a_2[0][1] = 1;
	b_41[0][0] = 1; b_41[0][1] = 0;
	c_148721[0] = 1;
	/*


	#define MOD1  1000000007
	#define MOD2 1000000006
	#define MOD3 500000003
	#define MOD4 2
	#define MOD5 41
	#define MOD6 1681
	#define MOD7 148721

	*/
	ll t1, t2, t3, t5, t4, t6,t7;

	for (i = 1; i < MAX; i++)
	{
		a_2[i][0] = (i*a_2[i - 1][0]) % 2;
		a_2[i][1] = (i*a_2[i - 1][1]) % MOD3;


		c_148721[i] = (i*c_148721[i - 1]) % MOD7;

		t = i;
		b_41[i][1] = b_41[i - 1][1];
		while ((t % 41)==0) { t /= 41; b_41[i][1]++; }
		b_41[i][0] = (t*b_41[i - 1][0]) % MOD6;
	}



	scanf("%d", &t);
	while (t--)
	{
		scanf("%lld%lld%lld", &a, &b, &n);
		if (a == 0 && b == 0)
		{
			printf("1\n"); continue;
		}

		t1 = (a_2[2 * n][0] * power(a_2[n][0], 0, 2))%MOD4;
		t1 = (t1*power(a_2[n][0], 0, 2)) % MOD4;


		//cout << "t1=" << t1 << "\n";

		t3 = (c_148721[2 * n] * power(c_148721[n], MOD7-2, MOD7)) % MOD7;
		t3 = (t3*power(c_148721[n], MOD7-2, MOD7)) % MOD7;


	//	cout << "t3=" << t3 << "\n";
		t2 = (b_41[2 * n][0] * inverse_iterative(b_41[n][0], MOD6)) % MOD6;
		t2 = (t2 * inverse_iterative(b_41[n][0], MOD6)) % MOD6;
		t2 = (t2*power(41, b_41[2 * n][1] - 2 * b_41[n][1], MOD6)) % MOD6;

		//cout << "t2=" << t2 << "\n";

		t4 = crt3(t1, t2, t3,MOD4,MOD6,MOD7);


		//cout << "t4=" << t4 << "\n";
		t5 = power(b, 0, 2);
		t6 = power(b, t4, MOD3);

		t7 = crt2(t5, t6,MOD4,MOD3);

		t1 = power(a, t7, MOD1);
		printf("%lld\n", t1);


	}


	return 0;
}
