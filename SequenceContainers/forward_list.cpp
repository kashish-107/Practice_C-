#include<iostream>
#include<forward_list>

using namespace std;

int main()
{
	auto ll = forward_list<int>{1,2,3,4,5};
	ll.push_front(6);
	for(auto& i:ll)
		cout<<i<<endl;
	return 0;
}
