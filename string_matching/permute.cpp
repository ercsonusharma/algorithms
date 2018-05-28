

//#include "stdafx.h"
#include<bits/stdc++.h>
using namespace std;

#define ll long long
int c = 0;
string a = "sonu";

void permute( string::iterator s,string::iterator idx)
{
	if (idx == s)
	{
		c++;
		cout << a << " "; return;
	}

	for (string::iterator j = idx; j !=s; j++)
	{
		iter_swap(j, idx);
		permute(s, idx + 1);
		iter_swap(j, idx);
	}

}

int main()
{


	ll ans = 0;
	sort(a.begin(), a.end());

	/*cout << is_permutation(a.begin(), a.end(), string("sonu").begin());

	while (next_permutation(a.begin(), a.end()))
	{
		ans++;
		cout << a << "\n";
	}
	*/
	permute(a.end(),a.begin());

	cout << c;

	return 0;
}

