#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
	auto vec1 = vector<int>{1,2,3,4,5};
	auto vec2 = vector<int>{};
	vec2.resize(vec1.size());
	for(auto& i:vec1)
		cout<<i<<" ";
	cout<<endl;
	copy(vec1.begin(), vec1.end(), vec2.begin());
	for(auto& i:vec2)
		cout<<i<<" ";
	cout<<endl;
	return 0;
}

