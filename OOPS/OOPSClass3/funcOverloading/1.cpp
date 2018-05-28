/*
	Name mangling
*/
#include <iostream>
using namespace std;
int fun(int a) {
	cout << "INT" << endl;
}
double fun(double a) {
	cout << "DOUBLE" << endl;
}
int fun(int a, int b) {
	cout << (a + b) << endl;
}
int main()
{
	fun(1);	
	fun(2.3);
	fun(1, 3);
	return 0;
}
