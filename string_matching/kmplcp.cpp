#include<bits/stdc++.h>
using namespace std;

int lcp[1000006];
string str,temp,text;
void kmplcp(int n)
{
	int j=0,i;
	for(i=1;i<n;)
	{
		if(str[i]==str[j])
		{
			lcp[i]=j+1;
			j++;i++;
		}
		else
		{
			if(j!=0)
			{
				j=lcp[j-1];
			}
			else
			{
				lcp[i]=0;
				i++;
			}
		}
	}


}

void kmp()
{
	int i=0,j=0;
	while(i<str.size()&&j<text.size())
	{
		if(str[i]==text[j])
			i++,j++;
		else
		{
			if(j!=0)
				j=lcp[j-1];
			else
				i++;
		}
	}

}

