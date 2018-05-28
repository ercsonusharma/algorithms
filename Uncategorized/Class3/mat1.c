#include <stdio.h>

int mat[2][3][4];
int main() 
{ 
	printf("%u\n", mat);	//1000
	printf("%u\n",&mat+1);
	/*
		&mat = int(*)[2][3][4]
		mat = int(*)[3][4]
		*mat = int(*)[4]
		**mat = int(*)
		***mat = int
	*/ 
	printf("%u\n",*(*mat+2)+3); 
	printf("%u\n",mat[0][1]+2); 
	return 0;   
} 
