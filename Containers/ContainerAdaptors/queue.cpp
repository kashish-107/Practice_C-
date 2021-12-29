#include<iostream>
#include<queue>
using namespace std;

int main()
{
	auto q_queue = queue<int>{};
	q_queue.push(1);
	q_queue.push(2);
	q_queue.push(3);
	
	cout<<q_queue.front()<<endl;
	cout<<q_queue.back()<<endl;

	return 0;
}
