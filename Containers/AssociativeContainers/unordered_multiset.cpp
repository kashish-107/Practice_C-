#include<iostream>
#include<unordered_set>

using namespace std;

int main()
{
	auto uno_multiset = unordered_multiset<int>{1,2,1,2,3,4,3};
	uno_multiset.insert(4);

	for(auto& i:uno_multiset)
		cout<<i<<endl;
}
