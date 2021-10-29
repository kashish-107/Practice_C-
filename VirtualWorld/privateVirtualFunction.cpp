/*
This code works because base class defines a public interface and derived class overrides it in its implementation even though derived has a private virtual function
*/

#include<iostream>
using namespace std;

class base
{
public:
	virtual ~base() {
		cout<<"Base dtor"<<endl;
	}

	virtual void show() {
		cout<<"Base show"<<endl;
	}
};

class derived : public base
{
private:
	void show() override {
		cout<<"derived show()"<<endl;
	}
};

int main()
{
	base* ptr = new derived();
	ptr->show();
	delete ptr;

	return 0;
}
