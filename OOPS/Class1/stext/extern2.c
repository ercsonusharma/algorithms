#include <stdio.h>

int main()
{
	extern int a;		//Declaration
	int a = 10;		//Extern variables cannot be defined inside function scope. Compilation error. No linkage or internal linkage
	return 0;
}

int a = 10;

//Extern variable declaration is a promise to the compiler that there would be a definition of a global variable some place else. 
//Local variables do not qualify as fulfillments of the promise to the compiler, because they are invisible to linkers.
// Global variables are extern by default
