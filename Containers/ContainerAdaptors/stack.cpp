#include<iostream>
#include<stack>

using namespace std;

int main()
{
	auto s_stack = stack<int>{};

	s_stack.push(6);
	s_stack.push(1);
	while(!s_stack.empty()) {
		cout<<s_stack.top()<<endl;
		s_stack.pop();
	}

	return 0;
}
