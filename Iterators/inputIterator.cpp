/*
- Few algo that use Input iterator:
	- find
	- count
	- equal
-  They are the iterators that can be used in sequential input operations, 
where each value pointed by the iterator is read-only once and then the iterator is incremented.
- forward, bidirectional and random-access iterators are also valid input iterators.
- Uses:
	1. Single-pass algorithm (i.e. algorithms in which we can go to all the locations in the range at most once,
		 like when we have to search or find any element in the range, we go through the locations at most once)
	2. Equality / Inequality Comparison
	3. Dereferencing - using the operator * and ->
	4. Incrementable - ++A, A++
	5. Swappable
- Limitations:
	1. Only accessing, no assigning
	2. Cannot be decremented
	3. Cannot be used in multi-pass algorithms
	4. Relational Operators: (A == B allowed) but (A <= B not allowed)
	5. Can’t be used with arithmetic operators like +, – and so on

*/

#include<iostream>
//#include<iterator>
#include<vector>
#include<list>
using namespace std;

template<typename InputIterator, typename T>
InputIterator find(InputIterator first, InputIterator last, const T& val)
{
	while(first != last) {
		if(*first == val) return first;
		++first;
	}
	return last;
}


int main()
{
	auto vec = vector<int>{1,2,3,4,5};
	auto dll = list<int>{1,2,3,4,5};
	cout<<*find(vec.begin(), vec.end(), 3)<<endl;
	cout<<*find(dll.begin(), dll.end(), 3)<<endl;

	return 0;
}
