#include<iostream>
using namespace std;

class postOperator
{
public:
	postOperator operator++(int) {
		cout<<"Post increment"<<endl;
		postOperator temp = *this;
		++i;
		return temp;
	}
	
	postOperator operator--(int) {
		cout<<"Post decrement"<<endl;
		postOperator temp = *this;
		--i;
		return temp;
	}

	void show() {
		cout<<"Val of i-"<<i<<endl;
	}
private:
	int i=5;
};

int main()
{
	postOperator obj;
	obj.show();
	(obj++).show();
	obj.show();
	obj--;
	obj.show();
	
	return 0;
}
