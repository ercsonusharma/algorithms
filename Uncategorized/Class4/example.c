#include<stdio.h>

int main()
{
	char s[]="Hi Cyberquest";
	int i=4;
	char ch;
	ch=s[i++];	printf("%c\n",ch);
	ch=++i[s];	printf("%c\n",ch);
	ch=++i[s];	printf("%c\n",ch);
	ch=i++[s];	printf("%c\n",ch); 
	ch=s[++i];	printf("%c\n",ch);
	ch=i[s]++;	printf("%c\n",ch);
	ch=i[s];	printf("%c\n",ch);
	return 0;
}

