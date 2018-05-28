#include<stdio.h>
int a = 5;
void fun(){
	printf("%d\n", a);
}
void gun(){
	printf("%d\n", a + 5);
}
int main(){
	fun();
	gun();
	printf("%d\n", a); 
	/*
		main can access a while we only wanted fun and gun to be able to access it. 
		See cpp's solution to this 'data-hiding' problem in datahidingencaps.cpp
	*/
	return 0;	
}
