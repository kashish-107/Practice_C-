/* How lamda works internally

[&i] (int x) { std::cout << i; }

// Above lamba is equivalent to

struct anonymous {
	int &m_i;
	anonymous(int &i) : m_i(i) {}
	inline auto operator()(int x) const //const is present if mutable is not used
	{
		std::cout << i;
	}
};
*/

/* Generic lambda
const auto l = [](auto a, auto b, auto c) {};
// is equivalent to

struct anonymous
{
	template <class T0, class T1, class T2>
	auto operator()(T0 a, T1 b, T2 c) const
	{
	}
};
*/

/* Mutable Lambda Function
[]() mutable {}

// is equivalent to
struct anonymous
{
    auto operator()()  // call operator non const
    {
    }
};
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct print
{
	void operator()(int x)
	{
		cout << x << endl;
	}
};

class Example {
public:
	Example(int i = 0) :x{ i } {

	}
	void print()
	{
		cout << "Print x: ";
		/*
		* Extra () at the end of the lambda function declaration
		* which is used to call it right thereafter decelaration.
		* Called as Immediately Invoked Function Expression (IIFE).
		*/
		[=]() {cout << x << endl; }(); //value
		[&]() {cout << x << endl; }(); //reference
		[this]() {cout << x << endl; }(); //this
		[this]() {cout << this->x << endl; }(); //this
	}
private:
	int x;
};

//Higher - Order Returning Lambda Functions
const auto less_than = [](auto i) {
	return [i](auto y) {
		return y < i;
	};
};

int main()
{
	vector<int>v{ 1,2,3 };
	for_each(v.begin(), v.end(), print()); //Using Functor
	for_each(v.begin(), v.end(), [](int x) {cout << x << endl; }); //Using Lambda

	int x = 10, y = 20;
	auto funcByReference = [&] {cout << __FUNCTION__ << " x: " << x << "," << "y: " << y << endl; }; //Capture all variable by reference
	auto funcByValue = [=] {cout << __FUNCTION__ << " x: " << x << "," << "y: " << y << endl; }; //Capture all variable by value
	funcByReference();
	funcByValue();

	auto funcReferenceAndValue = 
		[=, &x] {cout << __FUNCTION__ << " x: " << ++x << "," << "y: " << y << endl; }; //Capture x by reference & rest by value (Capture order matters)
	funcReferenceAndValue();

	/* Decelared a variable i in capture list
	* which will become a data member as a result everytime
	* we call func, i will be incremented and returned
	* */
	auto lambda_variable_decelration = [i = 0]() mutable { return ++i; };
	cout << lambda_variable_decelration() << endl;
	cout << lambda_variable_decelration() << endl;

	//Capturing member variable in lambda or this pointer
	Example e(10);
	e.print();

	//IIFE
	[] {cout << "Immediately Invoked Function Expression (IIFE)" << endl; }();

	//Generic Lambda - C++14
	const auto genericLambda = [](auto i, auto j) {cout << "Generic lambda i+j " << i + j << endl; };

	int i = 10, j = 20;
	string str1 = "Hello", str2 = "World!";
	genericLambda(i, j);
	genericLambda(str1, str2);

	static int static_x = 20;
	[] {cout << "static X " << static_x << endl; }(); //Can access static variable without capture

	//Mutable Lambda Function
	[x]() mutable {cout << "mutable labda x: " << ++x << endl; }();

	//Returning lambda function
	auto lambda_return_less_than_five = less_than(5);
	cout << lambda_return_less_than_five(4) << endl;
	cout << lambda_return_less_than_five(8) << endl;

	//Constexpr Lambda Expression - C++17
	constexpr auto sum = [](int x, int y) {return x + y; };
	constexpr int constVal = sum(10, 20);
	cout << constVal << endl;
	return 0;
}
