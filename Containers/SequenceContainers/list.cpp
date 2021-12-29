/*
- std::list is a doubly linked list
- not laid out contiguously in memory
- iterating a linked list will most likely generate a lot more cache misses compared to the vector
- don't need to traverse the list backwards, use std::forward_list
*/

#include<iostream>
#include<list>

using namespace std;

int main()
{
	auto dll = list<int>{1,2};
	dll.push_back(3);
	dll.push_front(4);
	for(auto& i:dll)
		cout<<i<<endl;
	return 0;
}
