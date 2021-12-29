#include<iostream>
#include<unordered_map>

using namespace std;

int main()
{
	auto uno_multimap = unordered_multimap<int, int>{{1,1},{2,2},{1,2},{2,1}};
	uno_multimap.insert({3,2});
	for(auto& i:uno_multimap)
		cout<<"Key:"<<i.first<<" Value:"<<i.second<<endl;
	return 0;
}
