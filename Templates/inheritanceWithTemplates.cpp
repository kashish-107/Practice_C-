/*
- Class templates or classes can inherit from each other in any combination
- Restriction: In derived class methods and attributes of base class are not automatically available
- Three possible solution:
	- To qualify the method class by this pointer
	- Make the name known by "using base<T>::fun"
	- Call the method of base class directly
*/

#include<iostream>

using namespace std;

template<typename T>
class base {
public:
	void fun() {
		cout<<"base fun"<<endl;
	}
};

template<typename T>
class derived : public base<T>
{
public:
	void dfun()
	{
		//not work if deriving from class template - can be solved with "using"
		//fun();
		this->fun();
		base<T>::fun();
	}
};

int main()
{
	derived<int> d{};
	d.dfun();

	return 0;
}
