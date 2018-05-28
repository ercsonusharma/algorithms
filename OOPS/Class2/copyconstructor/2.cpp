#include <iostream>
using namespace std;
class A
{
	public:
		int a;
		A(): a(5)	//Initializer list
		{	
			cout << "Constructor\n";
		}
		A(const A &b)	//Copy ctor
		{
			a = b.a;
			cout << "Copy Constructor\n";
		}
		A fun(A a)	//Notice return type
		{
			return a;
			/*
				If this a's valued is to be copied to b in main(), copy ctor has to be called from main(). But, a is out of scope after this function so this a can't be passed to copy ctor.
				That is why a tmp object is created. It has a scope such that it is accessible in fun() and main() both. You can not see a temp obj. Compiler abstracts that detail from you.
				This tmp object is returned to main and it is copied into b in main().
			*/
		}
};

int main()
{
	A a, c;
	A b = a.fun(c); //elision
	//a.fun(c); //no elision
	return 0;
}
/*
	Copy elision (Return Value Optimization - RVO)
*/
