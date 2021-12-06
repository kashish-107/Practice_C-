#include<iostream>
#include<vector>
#include<map>

using namespace std;

template<typename iterator, typename T>
bool contains(iterator begin, iterator end, const T& v)
{
	for(auto it=begin; it!=end; ++it)
		if(*it == v) return true;
	return false;
}

int main()
{
	auto vec = vector<int>{1,2,3,4,5};
	cout<<contains<vector<int>::iterator,int>(vec.begin(),vec.end(),7)<<endl;

//	auto m_map = map<int,int>{{1,2},{2,2}};
//	cout<<contains<map<int,int>::iterator,int>(m_map.begin(),m_map.end(),7)<<endl;
	return 0;
}
