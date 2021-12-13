/*
- Few algo that uses Forward Iterator:
	- replace
	- search
	- lower_bound
- Combination of input as well as output iterators. It provides support to the functionality of both of them
- Bidirectional and random-access iterators are also valid forward iterators
- Uses:
	1. Can be used in multi-pass algorithms:
		Performing operations on a forward iterator that is dereferenceable never makes its iterator value non-dereferenceable, 
		as a result this enables algorithms that use this category of iterators to use multiple copies of an iterator to pass more than once by the same iterator values
	2. Equality / Inequality Comparison - A == B, A != B (Allowed)
	3. Dereferencing: Because an input iterator can be dereferenced,
			using the operator * and -> as an rvalue and an output iterator can be dereferenced as an lvalue, 
			so forward iterators can be used for both the purposes
	4. Incrementable
	5. Swappable
- Limitations:
	1. Cannot be decremented
	2. Relational Operators:  can only be used with equality operator (==). 
	3. Arithmetic Operators - Not allowed
	4. Forward iterators do not support offset dereference operator ([ ])
*/


#include<iostream>
#include<vector>

using namespace std;

template<typename ForwardIterator, typename T>
void myReplace(ForwardIterator first,
			  ForwardIterator last,
			  const T& old_Value,
			  const T& new_value)
{
	while(first != last) {
		if(*first == old_Value)
			*first = new_value;
		++first;
	}

}

int main()
{
	auto vec = vector<int>{1,2,3,2,5};
	myReplace(vec.begin(), vec.end(), 2, 0);
	
	for(const auto i:vec) {
		cout<<i<<endl;
	}
}
