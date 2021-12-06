#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
	auto vec = vector<int>{1,2,3,4,5};
	auto squared_vec = vector<int>{};
	auto square_fun = [](int v) { return v*v; };

	//Pre-allocated space otherwise crash
	squared_vec.resize(vec.size());
	transform(vec.begin(), vec.end(), squared_vec.begin(), square_fun);

	for(auto& i:squared_vec)
		cout<<i<<" ";
	cout<<endl;

	//Use std::back_inserter if container is not pre-allocated
	auto squared_vec_2 = vector<int>{};
	transform(vec.begin(), vec.end(), back_inserter(squared_vec_2), square_fun);

	for(auto& i:squared_vec_2)
		cout<<i<<" ";
	cout<<endl;

	
	return 0;
}
