/*
- Precedence = Initialization_list ctor > Regular ctor > Aggregate Initialization
- To uniformly initialize objects regardless of their type, use the brace-initialization form {} 
that can be used for both direct initialization and copy initialization. When used with brace initialization, 
these are called direct list and copy list initialization.
- Narrowing conversion checks - int i{1.2} 
*/

#include <iostream>
#include <vector>
#include <map>
using namespace std;

class A {
public:
	int i;
	int j;

	A(int i, int j)
		:i{ i }, j{ j }{
		cout << "A Regular ctor" << endl;
	}
};

class B {
	int arr[3];
public:
	B(int i, int j, int k)
		:arr{ i, j, k} {               //Initialization of an array data member of a class
		cout << "B Regular ctor" << endl;
	}

	void print() {
		int i = 0;
		while (i < 3)
			cout << arr[i++] << " ";
		cout << endl;
	}
};

B fun(B b)
{
	cout << "In fun" << endl;
	b.print();
	return{ 2,3,4 };           //Implicitly initialize objects to return
}

int main() {

	string s1("test");   // direct initialization 
	string s2 = "test";  // copy initialization

	//Standard containers
	std::vector<int> v{ 1, 2, 3 };
	std::map<int, std::string> m{ {1, "one"}, { 2, "two" } };

	//Arrays:
	int arr1[3]{ 1, 2, 3 };

	//Built in types
	int i{ 42 };

	int x(1.2);                          // No Narrowing conversion check
	//int k{ 1.2 };						 // error - Narrowing conversion
	int k1{ static_cast<int>(1.2) };     // have to implicity cast it
	double d{ 1.2 };

	//Initialize Dynamically allocated arrays
	int* pointer = new int[5]{ 10, 20, 30, 40, 50 };

	//User-defined types:

	//Aggregate Initialization
	A a{1, 2};              // direct list initialization 
	A a1 = {1, 2};           // copy list initialization

	//Regular ctor
	B b{ 1,2,3 };
	b.print();

	B b1 = fun({ 3,4,5 });    //Implicitly initialize function parameter
	b1.print();

	return 0;
}
