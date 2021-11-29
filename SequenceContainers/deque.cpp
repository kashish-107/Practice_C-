/*
- Can add elements to the end and the beginning of a sequence
- std::deque is usually implemented as a collection of fixed-size arrays
- all elements are not stored contiguously in memory, which is the case with vector and array
*/

#include<iostream>
#include<deque>

using namespace std;

int main()
{
	auto dq = deque<int>{};
	dq.push_back(1);
	dq.push_front(2);

	for(auto& i:dq)
		cout<<i<<endl;
	
	return 0;
}

