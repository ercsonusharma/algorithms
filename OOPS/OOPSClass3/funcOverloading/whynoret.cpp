#include<iostream>

using namespace std;

int fun(int a)
{
	cout<<a<<endl;
}

double fun(int a)
{
	cout<<a<<endl;	
}

int main()
{
	int i = fun(4);
	double d = fun(4);
	//fun(3); //which one to call??
	return 0;
}

