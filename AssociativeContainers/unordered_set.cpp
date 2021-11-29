#include<iostream>
#include<unordered_set>

using namespace std;

int main()
{
	auto uno_set = unordered_set<int>{2,3,4,1,2,3};
	uno_set.insert(4);
	for(auto& i:uno_set)
		cout<<i<<endl;

	return 0;
}
