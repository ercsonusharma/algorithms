#include <iostream>
#define MACRO 10
using namespace std;
class A {
	int a;
	public:
		/*A() {
			cout<<"Constructor"<<endl;
		}
		void f() {
			int a = 20;
			cout << MACRO << endl;
		}*/
		A();
		void f();
};
A::A() {
	cout<<"Constructor"<<endl;
}
void A::f() {
	int a = 20;
	cout << MACRO << endl;
}
int main(){
	A a;
	a.f();
	a.f();
	a.f();
	return 0;
}
