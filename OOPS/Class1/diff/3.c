#include <stdio.h>
 
int main(void)
{
    int const j = 20;
 
    int *ptr = &j; // Error or not? -- C :: No --- C++ :: Yes
    /*
    	&j == const int *
    	ptr == int *
    */
    //int *ptr = (int*) &j; // no error in C++ also as explicit typecast
 	(*ptr)++
    printf("*ptr: %d\n j:%d\n", *ptr, j);
    return 0;
}
