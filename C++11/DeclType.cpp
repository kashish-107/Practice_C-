/*
1. Check the type of expression/entity
*/

#include <iostream>
using namespace std;

template<typename T1, typename T2>
T2 add(T1 a, T2 b) {
	return a + b;
}

template<typename T1, typename T2>
auto add_dt(T1 a, T2 b) -> decltype(a+b) {
	return a + b;
}

int main() {
	cout << add(1, 2.4) << endl; 
	cout << add(2.4, 1) << endl;

	cout << add_dt(1, 2.4) << endl;
	cout << add_dt(2.4, 1) << endl;

	int i = 33;
	decltype(i) j = i * 2;

	cout << is_same_v<decltype(i), decltype(j)> << endl;

	return 0;
}
