#include <iostream>
using namespace std;
void fun(int a, int b)
{
	cout << "i__i"<<endl;
}
void fun(int a, double d)
{
	cout<<"i__d"<<endl;
}
void fun(float f, double d)
{
	cout <<"f__d"<<endl;
}
void fun(int a, float f)
{
	cout<<"i__f"<<endl;
}
void fun(int a, char c)
{
	cout<<"i__c"<<endl;
}
int main()
{
	fun(2, 3.3);
	fun(2, 3);
	fun(2.3, 3);
	fun('c', 2.3);
	fun(2, 3.3f);
	fun(3, 'c');
	fun('c', 'c');
	//fun(2.3, 2.3);
	return 0;
}
