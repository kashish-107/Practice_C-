#include<iostream>
using namespace std;

class complex
{
public:
	complex():complex(0,0) { }
	complex(int i, int j):real{i}, imag{j} { }

	void show() {
		cout<<real<<" + i"<<imag<<endl;
	}

	complex operator+ (complex const& rhs) {
		complex res;
		res.real = real + rhs.real;
		res.imag = imag + rhs.imag;
		
		return res;
	}
private:
	int real, imag;
};

int main()
{
	complex c1(5,7);
	complex c2(10,7);
	
	complex c3 = c1+c2;
	complex c4 = c1+c2+c3;
	c1.show();
	c2.show();
	c3.show();
	c4.show();
	return 0;
}
