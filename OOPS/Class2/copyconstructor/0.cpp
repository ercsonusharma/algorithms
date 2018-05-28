#include <iostream>
using namespace std;
void swap(int &a, int &b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}
int main()
{
	int p = 10, q = 20;
	cout << p << " " << q << endl;
	swap(p, q);// ease of passing -- pass by ref.
	cout << p << " " << q << endl;
	return 0;
}
