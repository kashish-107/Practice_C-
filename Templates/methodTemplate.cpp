#include<iostream>

using namespace std;

template<typename T>
class foo
{
public:
	foo(const T& x)
		: mX{x}
	{}

	template<typename U>
	foo<T>& operator=(const U& u)
	{
		mX = static_cast<T>(u);
		return *this;
	}  
private:
	 T mX;
};

int main()
{
	foo<int> f{2};
	f = 2.5;

	return 0;
}
