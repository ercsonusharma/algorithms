#include<iostream>  // no .h here.
#include<cstdio> 

using namespace std;  
/*
	say iostream has global variable a
	if we take a variable a in class -- it hides the variable in iostream
	namespace -- to define some variables or functions that can be used if we use the name of the namespace
	'using' keyword brings the data of the namespace into global namespace -- this is 'like' using the global variables
*/
class Basic
{
	private:	// access specifier
		int a;
	public:
		Basic()	// Constructor -- constructs the object
		/*
			-> ctor has no return type
			-> whenever an object is created, a ctor has to be called -- 				by default
			-> compiler does this for you
			-> ctor can be given a definition
			-> ctor is used to initialize the data members(variables)
			of a class
			-> What if you don't create a ctor yourself?
				-- Compiler creates a default ctor (that ctor is parameterless)
				-- If you create a ctor, compiler doesn't create the ctor by itself
				-- Be it your ctor, be it the ctor provided by compiler, it will be called on object creation
		*/
		{	
			a = 10;
			cout<<"Constructor"<<endl;
		}
		~Basic()	// Destructor
		/*
			-> Destroys the object
			-> Called automatically when the object is destroyed
			-> B was in main(). It's scope ended with main(). dtor called automatically -- because as the scope of B ended, it had to be destroyed
			-> Default dtor -- same as default dtor
			-> No arguments can ever be passed to dtor
		*/
		{
			std::cout<<"Destructor"<<std::endl;
		}
		
		int power(int a, int b) // inline definition
		{
		/*
			class k andar define krna
		*/
			int ans = 1;
			for(int i = 0; i < b; i++)
			{
				ans *= a;
			}
			return ans;
		}
		
		void getA();	//declared
};

void Basic::getA()	//defined - notice the scope resolution operator
{
/*
	Return type -- Class name -- SRO -- Function name
	Not global
*/
	cout<<a<<endl;	// Private a accessed
}

int main()
{
	int a = 20;	//local - not of Class Basic's -- Basic::a
	Basic B;
	B.getA();
	printf("%d\n", B.a);	// compilation error
	B.power(5, 4);	// Abstraction
	/*
		Even if you change the definition of power, you can call it like above. No need to bother about the implementation of power
	*/
	return 0;
}
