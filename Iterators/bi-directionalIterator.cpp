/*
- Few algo that use bi-directional Iterators
	- reverse
	- reverse_copy
	- next_permutation
- Used to access the sequence of elements in a range in both directions
- Container that support bi-directional Iterators: (if we declare normal iterators for them, and then those will be bidirectional iterators)
	- Map, multimap
	- Set, multiset
	- List(DLL)
- Random-access iterators are also valid bidirectional iterators
- Salient Features
	1. Like Forward_Iterators, They can also be used in multi-pass algorithms.
		- multi-pass algorithms- algorithm which involves processing the container several times in various passes
	2. Equality / Inequality Comparison - Allowed (A == B, A != B)
	3. Dereferencing - Allowed same as forward iterator
	4. Incrementable
	5. Decrementable
	6. Swappable
- Limitations:
	- Relational Operators: Can be used with equality (==, !=) but can not be used with other relational operators (<=)
	- Can’t be used with arithmetic operators like +, – and so on (Ex. List)
	- Bidirectional iterators doesnot support offset dereference operator ([ ]), which is used for random-access
*/

#include<iostream>
#include<vector>
#include<algorithm> //itr_swap
using namespace std;

template<typename Bidirectional, typename OutputIterator>
void reverseCopy(Bidirectional first, Bidirectional last, OutputIterator output)
{	
	while(first != last) {
		*(output++) = *(--last);
	}
}

template<typename Bidirectional>
void myReverse(Bidirectional first, Bidirectional last)
{
	while((first != last) && (first != --last)) {
		swap(*first,*last);
		++first;
	}
}

int main()
{
	auto vec = vector<int>{1,2,3,4,5};
	vector<int> res(5);

	reverseCopy(vec.begin(), vec.end(), res.begin());
	for(const auto i:res) {
		cout<<i<<endl;
	}

	cout<<"myReverse"<<endl;
	myReverse(vec.begin(), vec.end());
	for(const auto i:vec) {
		cout<<i<<endl;
	}

	return 0;
}
