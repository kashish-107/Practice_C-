/*
- Duplicates allowed
- Sorted
*/

#include<iostream>
#include<map>

using namespace std;

int main()
{
	auto multi_map = multimap<int,int>{{2,1},{2,3},{4,5}};
	multi_map.insert({8,5});

	for(auto& i:multi_map)
		cout<<"Key:"<<i.first<<" Value:"<<i.second<<endl;

	return 0;	
}
