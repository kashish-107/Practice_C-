#include<iostream>
#include<memory>
using namespace std;

class base
{
public:
	virtual void print(int x = 10) {
		cout<<"Base x "<<x<<endl;
	}

	virtual void show(int y = 7) {
		cout<<"Base y "<<y<<endl;
	}

	virtual ~base() {
	}
};

class derived : public base
{
public:
	virtual void print(int x = 15) override {
		cout<<"derived x "<<x<<endl;
	}
	
	virtual void show(int y) override {
		cout<<"derived y "<<y<<endl;
	}	
};

int main()
{
	unique_ptr<base> pD = make_unique<derived>();
	pD->print();

	unique_ptr<derived> pD2 = make_unique<derived>();
	pD2->print();

	unique_ptr<base>pShow = make_unique<derived>();
	pShow->show();

	unique_ptr<derived>pShow2 = make_unique<derived>();
	//pShow2->show();  //Error
	return 0;
}
