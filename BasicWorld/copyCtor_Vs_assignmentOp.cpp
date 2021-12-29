#include<iostream>
#include<memory>
using namespace std;

class test
{
public:
	test() {
		ptr = nullptr;	
	}
	test(int i) {
		ptr= new int(i);
	}

	test(const test& obj) {
		cout<<"Copy ctor"<<endl;
		ptr = new int(0);
		*ptr=*(obj.ptr);
	}

	void show() {
		cout<<"Value="<<*ptr<<endl;
	}

	void updateVal() {
		*ptr=20;
	}
	
	test& operator= (const test& obj) {
		cout<<"Assignment operator"<<endl;
		if(!ptr) 
			ptr = new int(0);
		*ptr = *(obj.ptr);
		return *this;
	}

	~test() {
		cout<<"Dtor"<<endl;
		delete ptr;
	}
private:
	int* ptr;
};

int main()
{
	test t1(10);
	test t2 = t1;
	t1.show();
	t2.show();

	test t3;
	t3 = t2;
	t3.updateVal();
	t2.show();	
	return 0;
}

