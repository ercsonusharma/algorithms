#include <iostream>
using namespace std;
class loc {
	int longitude, latitude;
	public:
	loc() {       }
	loc(int lg, int lt) 
	{
		longitude = lg;
		latitude = lt;
	}
	void show() 
	{
		cout << longitude << " ";
		cout << latitude << "\n";
	}
	
	loc operator + (int op2)
	{
		loc temp;
		temp.longitude = longitude + op2;
		temp.latitude = latitude + op2;
		return temp;
	}
	friend loc operator+(int op1, loc op2);
};

loc operator+(int op1, loc op2)
{
	loc temp;
	temp.longitude = op1 + op2.longitude;
	temp.latitude = op1 + op2.latitude;
	return temp;
}

int main()
{
	int a, b;
	b = a + b;
	loc ob1, ob2(5, 30), ob3;
	ob1 = ob2 + 10; 		// Called as ob1.operator+(int)
	ob3 = 10 + ob2;	// Trying to call as int.operator+(ob2)
	ob1.show();
	return 0;
}
