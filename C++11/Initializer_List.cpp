#include<iostream>
#include<vector>
#include<string>
using namespace std;

template<typename T>
class Generic {
public:
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
	Generic<int> n = { 1,2,3,4,5 };
	n.Print();

	Generic<string> s = { "Hello","World","!!" };
	s.Print();

	Generic<char> n2 = { 'H','W','|' };
	n2.Print();
	return 0;
}
