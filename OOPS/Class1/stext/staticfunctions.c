#include<stdio.h>
//Compile with stfuncusage.c
static void fun()  //change to static - gives error
{
/*
	On making fun static:
	Scope : This file
	Visibility : This file
	Linkage : internal -- linker will search for fun() in the symtab of this program only i.e. search internally
	But, by default fun is extern and will have external linkage
	External linkage : Linker will search for this fun in all the symbol tables available -- i.e. search for this externally
*/
	printf("Hello\n");
}
