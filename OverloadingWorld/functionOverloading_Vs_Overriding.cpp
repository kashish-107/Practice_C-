/*
1. Overriding of functions occurs when one class is inherited from another class. Overloading can occur without inheritance. 
2. Overloaded functions must differ in function signature ie either number of parameters or type of parameters should differ. In overriding, function signatures must be same.
3. Overridden functions are in different scopes; whereas overloaded functions are in same scope.
4. Overriding is needed when derived class function has to do some added or different job than the base class function. Overloading is used to have same name functions which behave differently depending upon parameters passed to them.

How function overloading works:
	- Exact match:- (Function name and Parameter)
	- If a not exact match is found:–
            ->Char, Unsigned char, and short are promoted to an int.
            ->Float is promoted to double
	-If no match found:
            ->C++ tries to find a match through the standard conversion.
	-Else error :(

Important:
	-  return type doesn’t play anyrole in function overloading.
*/

#include<iostream>
#include<memory>
using namespace std;

void funOverloading(int i) {
	cout<<i<<endl;
}

void funOverloading(float f) {
	cout<<f<<endl;
}


class base 
{
public:
	virtual void display() {
		cout<<"I am in base"<<endl;	
	}
};

class funOverriding : public base
{
public:
	void display() override  {
		cout<<"funOverriding"<<endl;
	}
};


int main()
{
	funOverloading(6);
	//funOverloading(9.7); //error
	funOverloading(9.7f);
	
	unique_ptr<base> bp = make_unique<funOverriding>();
	bp->display();
	
	return 0;
}
