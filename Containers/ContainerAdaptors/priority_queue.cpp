/*
- Priority queue offers constant time lookup of the element with the highest priority
- Priority is defined using the less than operator of the elements
- Insert and delete both run in logarithmic time.
- By deault its a max heap
*/

#include<iostream>
#include<queue>

using namespace std;

int main()
{
	//Max heap
	cout<<"Max heap:"<<endl;
	auto maxheap = priority_queue<int>{};
	maxheap.push(4);
	maxheap.push(5);
	maxheap.push(1);
	maxheap.push(2);

	while(!maxheap.empty()) {
		cout<<maxheap.top()<<endl;
		maxheap.pop();
	}

	//Min heap
	cout<<"Min heap:"<<endl;
	auto minheap = priority_queue<int, vector<int>, greater<int>>{};
	minheap.push(4);
	minheap.push(1);
	minheap.push(3);
	minheap.push(2);

	while(!minheap.empty()) {
		cout<<minheap.top()<<endl;
		minheap.pop();
	}

	return 0;
}
