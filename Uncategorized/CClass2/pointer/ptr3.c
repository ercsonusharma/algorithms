#include<stdio.h>
int main()
{
	char *name="ITCENTRE";
	name++;//reaches T (or has address of T at this point)
	printf("%s\n",++name);//reaches C
	++name;//reaches E
	if(name[-2]=='T') // name[-2] is equivalent to *(name - 2)
		printf("%c YES\n",name[-2]);
	else
		printf("NO\n");
	return 0;
}
