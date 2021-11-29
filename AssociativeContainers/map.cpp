/*
- No duplicates
- Key value pairs
*/

#include<iostream>
#include<map>

using namespace std;

int main()
{
	auto m_map = map<int,int>{{2,4},{1,2},{2,5}};
	m_map.insert({3,7});

	for(auto& i:m_map)
		cout<<"Key:"<<i.first<<" Value:"<<i.second<<endl;

	return 0;
}
