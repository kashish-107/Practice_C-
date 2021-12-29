/*
- No duplicates
- Random order
*/

#include<iostream>
#include<unordered_map>

using namespace std;

int main()
{
	unordered_map<int,int> uno_map = {{1,2}, {1,3}, {2,3}};
	uno_map.insert({2,4});

	for(auto& i:uno_map)
		cout<<"Key:"<<i.first<<" Value:"<<i.second<<endl;

	return 0;
}
