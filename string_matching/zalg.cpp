//#include"stdafx.h"


//(z[idx]) z-algo keeps the no. of characters matched with the pattern (from 0...length of pattern)
//thereafter(imp) the certain index (index=> idx in  z[idx] )
//e.g. original pattern= abababc  (str)
//for z[4]=2 since only two characters matches with the original pattern i.e. ab

//kmplcp keeps the no. of characters matched till now(imp) with the original pattern
//e.g. original pattern= abababc (str)
//for lcp[4]=3 and lcp[5]=4
//lcp[4]=3 tells that 3 characters have matched till index 4 ie. abc with the oringinal pattern

//because it is used for sliding window so it keeps the index to thereafter which the matching
//is to be started with the text to reduce the complexity ,here lcp[5]=4 where 4 is the index where again
//we have to start our searching from with the text


#include<bits/stdc++.h>
using namespace std;

int z[1000006];
char str[1000005],temp[1000005];
void z_algo(int n)
{


	int L, R;

	L = R = 0;
	int i;

	for (i = 0; i < n; i++)
		str[i] = temp[n - i - 1];
	str[i] = '\0';

	z[0] = n;
	for (i = 1; i < n; i++)
	{
		if (i>R)
		{
			L = R = i;
			while (R < n&&str[R - L] == str[R])
				R++;
			z[i] = R - L;
			R--;
		}
		else
		{
			int k = i - L;
			if (z[k] < R - i + 1)
			{
				z[i] = z[k];
			}
			else
			{
				L = i;
				while (R < n&&str[R - L] == str[R])
					R++;
				z[i] = R - L;
				R--;
			}
		}
	}
}


int main()
{
	int i,t,q,n;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%s", temp);
		n = strlen(temp);
		z_algo(n);
		scanf("%d", &q);
		while (q--)
		{
			scanf("%d", &i);
			printf("%d\n", z[n - i]);
		}

	}


	return 0;
}
