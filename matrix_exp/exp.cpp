//#include"stdafx.h"

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mod2 1000000006

void multiply(ll a[][2], ll b[][2])
{
	ll t[2][2],i,j,k;
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 2; j++)
		{
			ll add = 0;
			for (k = 0; k < 2; k++)
			{
				add += (a[i][k] * b[k][j])%mod2;
			}
			t[i][j] = add%mod2;
		}

	}
	for (i = 0; i < 2; i++)
		for (j = 0; j < 2; j++)
			a[i][j] = t[i][j];


}



ll power(ll M[][2], ll n)
{
	ll F[][2] = { {1,1},{1,0} };

	if (n == 1)
		return  (M[0][0]+M[0][1])%mod2;		//multiply with initial value


	power(M, n / 2);
	multiply(M, M);

	if (n & 1)
	{
		multiply(M, F);
	}
	return (M[0][1]+M[0][0])%mod2;			//multiply with intial value of F(0) and F(1)
				//since F(0)=0 and F(1)=1 we need to answer only 1 i.e. M[0][1];





}


ll findn(ll n)
{

	ll F[][2] = { {1,1},{1,0} };
	if (n == 0)
		return 0;
	return power(F, n);

}

vector<pair<ll,ll> > nfib,sfib;


void gen()
{

	ll a = 1, b = 1,c=2,l_b=2;
	ll count = 0;
	ll r_a=0, r_b=0;
	while (count < 9 * 100000000)
	{
		if ((c - l_b)>1)
		{
			nfib.push_back(make_pair(l_b+1, c-1));
			r_a = r_b;
			count += (c - l_b - 1);
			r_b += count;
			sfib.push_back(make_pair(r_a+1, r_b));
		}

		c = a + b;
		a = b;
		l_b = b;
		b = c;
		//printf("c=%d ", c);

	}
//	for (a = 0; a < nfib.size(); a++)
	//	cout << nfib[a].first << " " << nfib[a].second << " sib="<<sfib[a].first<<" "<<sfib[a].second<<"\n";
	//cout << "size=" << nfib.size();
}


int main()
{
	gen();

	int n, t, i, j;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%lld", &n);
		n--;
		printf("%lld\n", findn(n));
	}

	return 0;
}

/*Code after re-reading
[ f(n+2) f(n+1)] =  [1 1]  [ f(n+1) f(n)  ]
[ f(n+1) f(n)  ]    [1 0]* [ f(n)  f(n-1) ]
 -----R[]-----------C[]-------M[]----------
after recurrence relation;
matrix C will be multiplied N-1 times to obtain Nth recurrence.
and atlast resultant will be multiplied with M[] to get matrix R.
R[0][0] stores our result.

*/

#include <iostream>
using namespace std;

void multiply(int M[][2],int N[][2])
{
	int x=M[0][0]*N[0][0]+M[0][1]*N[1][0];
	int y=M[0][0]*N[0][1]+M[0][1]*N[1][1];
	int xx=M[1][0]*N[0][0]+M[1][1]*N[1][0];
	int yy=M[1][0]*N[0][1]+M[1][1]*N[1][1];
	M[0][0]=x,M[0][1]=y;
	M[1][0]=xx,M[1][1]=yy;
	
}
void power(int M[2][2],int n)
{
	
	if(n==1)
	return ;
	int F[2][2]={{1,1},{1,0}};
	power(M,n/2);
	multiply(M,M);
	if(n&1)
	multiply(M,F);
	
}

int getn(int n)
{
	int M[2][2]={{1,1},{1,0}};
	int F[2][2]={{1,1},{1,0}};
	power(F,n);
	multiply(M,F);
	return M[0][0];
	
}

int main() {
	
	cout<<getn(10);
	// your code goes here
	return 0;
}
