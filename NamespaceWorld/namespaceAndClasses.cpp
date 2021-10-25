#include<iostream>
using namespace std;

namespace ns1 {
	class abc {
		int value = 300;
	public:
		void display() {
			cout<<"ns::abc::Display"<<value<<endl;
		}
	};

	class xyz;

	class mno {
	public:
		void show();	
	};
}

class ns1::xyz {
public:
	void print() {
		cout<<"ns1::xyz::Print"<<endl;
	}
};


void ns1::mno::show() {
	cout<<"ns1::mno::show()"<<endl;
}


int main()
{
	int value = 100;
	ns1::abc obj;
	obj.display();

	ns1::xyz obj1;
	obj1.print();

	ns1::mno obj2;
	obj2.show();
	return 0;
}
