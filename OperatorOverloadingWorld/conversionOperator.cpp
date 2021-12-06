/*
- Overloaded conversion operators must be a member method
*/

#include<iostream>
using namespace std;

class Fraction
{
public:
	Fraction(int x, int y):num{x}, den{y} { }
	operator float() const {
		return (float)num/den;
	}
private:
	int num, den;
};

int main()
{
	Fraction fObj(8,3);
	float f = fObj;

	cout<<f<<endl;
	return 0;
}
