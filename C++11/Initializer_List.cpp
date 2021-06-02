/*
1. The way the initialization using std::initializer_list works is the following:
	-The compiler resolves the types of the elements in the initialization list (all elements must have the same type).
	-The compiler creates an array with the elements in the initializer list.
	-The compiler creates an std::initializer_list<T> object to wrap the previously created array.
	-The std::initializer_list<T> object is passed as an argument to the constructor.
2. An initializer list always takes precedence over other constructors where brace-initialization is used. 
If such a constructor exists for a class, it will be called when brace-initialization is performed:
3. The precedence rule applies to any function too
*/

#include<iostream>
#include<vector>
#include<string>
using namespace std;

template<typename T>
class Generic {
public:
	Generic(T i, T j)
		:v{ i,j } {
		cout << "Param ctor" << endl;
	}
	Generic(const initializer_list<T>& it) {  //Const is must
		for (const auto i : it) {
			v.push_back(i);
		}
	}
	void Print() {
		for each (T var in v)
		{
			cout << var << " ";
		}
		cout << endl;
	}
private:
	vector<T> v;
};

int main() {
	Generic<int> n = { 1,2 };
	n.Print();

	Generic<string> s = { "Hello","World" };
	s.Print();

	Generic<char> n2 = { 'H','W' };
	n2.Print();
	return 0;
}
