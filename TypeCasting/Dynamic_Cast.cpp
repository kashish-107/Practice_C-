/*
1. Dynamic casting is mainly used for safe downcasting at run time.
2. To work on dynamic_cast there must be one virtual function in the base class.
3. A dynamic_cast works only polymorphic base class because it uses this information to decide safe downcasting.
4. Downcasting: Casting a base class pointer (or reference) to a derived class pointer (or reference) is known as downcasting.
5. If we do not use the virtual function -  it generates an error message “Source type is not polymorphic”.
6. If the cast fails and new_type is a pointer type, it returns a null pointer of that type.
7. If the cast fails and new_type is a reference type, it throws an exception that matches a handler of type std::bad_cast 
and gives a warning: dynamic_cast of “Derived d1” to “class  Derived2&” can never succeed.

Note:
- A Dynamic_cast has runtime overhead because it checks object types at run time using “Run-Time Type Information“.
- If there is a surety we will never cast to wrong object then always avoid dynamic_cast and use static_cast. 
*/

#include <iostream>
#include <exception>
#include <typeinfo>
using namespace std;

class Animal
{
public:
	virtual void print() { cout << "Animal" << endl; }
};

class Cat : public Animal
{
public:
	void print() { cout << "Cat" << endl; }
};

class Loin : private Animal
{
public:
	void print() { cout << "Loin" << endl; }
};

int main()
{
	Animal* basePtr = new Cat();

	Loin* lPtr = dynamic_cast<Loin*>(basePtr);
	Cat* cPtr = dynamic_cast<Cat*>(basePtr);

	Cat c;
	Animal& a = c;

	cout << "Type Info " << typeid(*basePtr).name() << endl;
	cout << "Type Info " << typeid(a).name() << endl;

	cPtr ? cPtr->print() : cout << "Invalid cast" << endl;

	if (lPtr)
		lPtr->print();
	else
		cout << "Invalid cast" << endl;

	Animal& refPtr = Cat();
	try
	{
		Loin& lRef = dynamic_cast<Loin&>(refPtr);
	}
	catch (exception& e)
	{
		cout << e.what() << endl;
	}

	return 0;
}
