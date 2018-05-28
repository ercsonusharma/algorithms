#include <iostream>
using namespace std;

class A{
public:
    friend void fun(A a)
    {
    	std::cout << "Im here" << std::endl;
    }
};

int main()
{
	A a;
	//a.fun(a);
	fun(a);
	return 0;
}
