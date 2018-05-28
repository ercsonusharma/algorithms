#include <iostream>
using namespace std;
class Base
{
	public:
		int a;
		void fun()
		{
			cout << "fun" << endl;
		}
};

class Derived: protected Base  
{
	public:
		int a;
		void fun2()
		{
			fun();
			cout << "fun2" << endl;
			cout << Derived :: a << " " << Base :: a << endl;
		}
};

class Derived2 : public Derived
{	
	public: 
		void fun3()
		{
			fun();
			cout << "fun3" << endl;
		}
	
};
int main()
{
	Derived d;
	Derived2 d2;
	d.fun2();
	d2.fun3();
	return 0;
}
