#include <iostream>
using namespace std;
class Base
{
		protected : void pfun()
		{
			cout << "pfun" << endl;
		}
	public:
		Base() 
		{
			cout << "Base Constructor" << endl;
		}
		void fun()
		{
			cout << "fun" << endl;
		}
		~Base() 
		{
			cout << "Base Destructor" << endl;
		}
};

class Derived: public Base	// Derived inherits Base
{
/*
	Inheritance type : pub, pri or prot.
	pub - upar wali class ki public things is class me publicly accessible hn, protected wali bhi protected hn isme, private wali b inherit hongi but accessible nhi h
	protected things are like private but they are accessible in derived class while private things are not
*/
	public:
		Derived() 
		{
			cout << "Derived Constructor" << endl;
		}
		void fun2()
		{
			fun(); 
			cout << "fun2" << endl;
			pfun();
		}
		~Derived() 
		{
			cout << "Derived Destructor" << endl;
		}
};

int main()
{
	Derived d;
	d.fun();
	d.fun2();
	return 0;
}
