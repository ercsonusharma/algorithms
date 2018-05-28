#include <iostream>
using namespace std;
class myclass {
	int a, b;
	public:
		/* 
			A friend function has access to all private and protected members of the class of which it is a friend
			Data hiding not violated
			Friend fn has no this pointer
		*/
		//friend int sum(myclass x);// not inherited
		void set(int i, int j);
};

void myclass::set(int i, int j)
{
	a = i;
	b = j;
}

int sum(myclass x) 
{
	return x.a + x.b;
}

int main()
{
	myclass n;
	n.set(3, 4);
	sum(n);
	cout << sum(n) << endl;
	return 0;
}
