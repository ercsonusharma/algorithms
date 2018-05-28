#include<iostream>

using namespace std;

int main()
{
	int *i = new int;
	int *j = new int(5);
	int *k = new int[5];
	
	cout << *i << endl;
	cout << *j << endl;
	
	for (int c = 0; c < 5; c++)
		k[c] = 1;
	for (int c = 0; c < 5; c++)
		cout << k[c] << endl;
	delete i;
	delete j;
	delete[] k;
	return 0;
}
