#include<iostream>
#include<memory>
using namespace std;

class base
{
public:
	virtual ~base() {
		cout<<"Base dtor"<<endl;
	}
	virtual void display() = 0;
	static unique_ptr<base> create(int id);
};

class derived1 : public base
{
public:
	void display() override {
		cout<<"derived1 display"<<endl;
	}
	
	~derived1() {
		cout<<"Derived1 dtor"<<endl;
	}
};

class derived2 : public base
{
public:
	void display() override {
		cout<<"derived2 display"<<endl;
	}
	
	~derived2() {
		cout<<"Derived2 dtor"<<endl;
	}
};

class user
{
public:
	user():pBase(nullptr) {
		pBase = make_unique<derived1>();
	}
	
	void action() {
		pBase->display();
	}
		
private:
	unique_ptr<base> pBase;
};

unique_ptr<base> base::create(int id)
{
	if(id == 1)
		return make_unique<derived1>();
	else if(id == 2)
		return make_unique<derived2>();
	return nullptr;
}

int main()
{
	user u;
	u.action();

	unique_ptr<base> ptr = base::create(2);
	ptr->display();

	return 0;
}
