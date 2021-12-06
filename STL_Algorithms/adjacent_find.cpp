#include<iostream>
#include<vector>
#include<algorithm>
#include<type_traits>

using namespace std;

template<typename Iterator>
auto contains_duplicates(Iterator first, Iterator last)
{
	using valueType = decay_t<decltype(*first)>;
	auto c = vector<valueType>(first, last);
	sort(c.begin(), c.end());
	return (adjacent_find(c.begin(), c.end()) != c.end());
}

int main()
{
	auto vec = vector<int>{1,3,1,2,3,4};
	auto vec_2 = vector<int>{1,3};
	using itr = vector<int>::iterator;
	cout<<contains_duplicates<itr>(vec.begin(), vec.end())<<endl;
	cout<<contains_duplicates<itr>(vec_2.begin(), vec_2.end())<<endl;

	return 0;
}
