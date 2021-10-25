/*
1) A class is abstract if it has at least one pure virtual function. 
2) We can have pointers and references of abstract class type. 
3) If we do not override the pure virtual function in derived class, then derived class also becomes abstract class. 
4) An abstract class can have constructors.
5) We cannot create objects of abstract classes.
*/

#include<iostream>
#include<memory>
#include<string>
using namespace std;

class animal
{
protected:
	string _name;
public:
	animal(string iName): _name(iName) {
		cout<<"Animal ctor"<<endl;
	}

	virtual void speak() = 0;

	virtual ~animal() {
		cout<<"Animal dtor"<<endl;
	}
};

//Pure virtual function defination
void animal::speak() {
	cout<<"I am animal."<<endl;
}

class cat : public animal
{
public:
	cat(string iName):animal(iName) {
		cout<<"Cat ctor"<<endl;
	}

	void speak() override {
		animal::speak();
		cout<<"My name is "<<_name \
		    <<". I speak Meow!"<<endl;
	}
	
	~cat() {
		cout<<"Cat dtor"<<endl;
	}
};

int main()
{
	unique_ptr<animal> pCat = make_unique<cat>("Kitty");
	pCat->speak();
	return 0;
}


