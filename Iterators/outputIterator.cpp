/*
- Few Algorithm that uses Output Iterator
	- Transform
	- copy
	- move
- can assign values in a sequence, but cannot be used to access values.
- Salient Features:
	1. Single-pass algo
	2. output iterators cannot be compared for equality with another iterator
	3. Dereferencing: Output iterator can be dereferenced as an lvalue to provide the location to store the value
	4. Incrementable
	5. Swappable
- Limtations:
	1. Only assigning, no accessing
	2. Cannot be decremented
	3. Use in multi-pass algorithms: Since, it is unidirectional and can only move forward,
		therefore, such iterators cannot be used in multi-pass algorithms, 
		in which we need to move through the container multiple times
	4. Can not be used with relational operators
	5. Can’t be used with arithmetic operators like +, – and so on.
*/

#include<iostream>
#include<vector>

using namespace std;

template<typename InputIterator, typename OutputIterator>
OutputIterator myMove(InputIterator first, InputIterator last, OutputIterator result)
{
	while(first != last)	{
		*result = *first;
		++result;
		++first;
	}
	return result;
}

int main()
{
	vector<int> vec = {1,2,3,4,5};
	vector<int> result(5);
	myMove(vec.begin(), vec.end(), result.begin());
	
	for(const auto& i:result)
		cout<<i<<endl;

	return 0;
}
