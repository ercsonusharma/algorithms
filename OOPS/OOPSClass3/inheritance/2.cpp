#include <iostream>
using namespace std;
class Base
{
	public:
		Base() 
		{
			cout << "Base Constructor" << endl;
		}
		void fun()
		{
			cout << "fun" << endl;
		}
};
class Derived: Base
{
	public:
		Derived() 
		{
			cout << "Derived Constructor" << endl;
		}
		void fun2()
		{
			fun();
			cout << "fun2" << endl;
		}
};
int main()
{
	Derived d;
	d.fun2();
	d.fun();
	return 0;
}
