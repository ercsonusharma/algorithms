/*
	Change the behaviour of an operator w.r.t a class as per your 		wish
*/
#include <iostream>
using namespace std;
class loc 
{
	int longitude, latitude;
	public:
		loc() {		}
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
		loc operator+(loc op2);
};

// Overload + for loc.
loc loc::operator+(loc op2)	// ob1 and ob2 unchanged
{
	loc temp;
	temp.longitude = op2.longitude + this -> longitude;
	temp.latitude = op2.latitude + latitude;
	return temp;
}

int main()
{
	loc ob1(10, 20), ob2( 5, 30);
	ob1 = ob1 + ob2;	// Equivalent to ob1.operator+(ob2)
	ob1.show();
	return 0;
}
