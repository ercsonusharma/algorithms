#include<stdio.h> 
int main() 
{ 
	char *p[]={"softathlon","insomnia","tuxwars","webster","droidrush"}; 
	char **q[]={p+4,p+3,p+1,p,p+2}; 
	char ***r=q+1; 
	printf("%s\n",**++r);   
	printf("%s\n",*++*++r+2); 
	printf("%s\n",*r[-2]+4); 
	printf("%s\n",r[-2][-3]+2); 
	return 0; 
}
