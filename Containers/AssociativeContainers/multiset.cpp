/*
- Duplicates allowed
- Sorted
*/

#include<iostream>
#include<set>

using namespace std;

int main()
{
	auto multi_set = multiset<int>{2,1,2,3,4,5};
	multi_set.insert(5);

	for(auto& i:multi_set)
		cout<<" Value:"<<i<<endl;

	return 0;	
}
