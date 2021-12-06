#include<iostream>
using namespace std;

class preOperator
{
public:
	preOperator(int i):i{i} { }
	
	preOperator& operator++() {
		cout<<"Increment Operator overloading"<<endl;
		i++;
		return *this;	
	}
	
	preOperator& operator--() {
		cout<<"Decrement Operator overloading"<<endl;
		i--;
		return *this;
	}
	void show() {
		cout<<"Value of i-"<<i<<endl;
	}
private:
	int i;
};

int main()
{
	preOperator obj(2);
	obj.show();
	(++obj).show();
	obj.show();
	--obj;
	obj.show();
	return 0;
}
