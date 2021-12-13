/*
-  ‘fill’ function assigns the value ‘val’ to all the elements in the range [begin, end)
- 
*/

#include<iostream>
#include<algorithm>
#include<set>

using namespace std;

int main()
{
	auto vec= vector<int>{1,2,3,4,5};
	auto s = set<int>{2,3,5,8};
	fill(vec.begin(), vec.end(), 4);
	//fill(s.begin(), s.end(), 4); //Error
	for_each(vec.begin(), vec.end(), [](int val) { cout<<val<<" "; });
	cout<<endl;

	return 0;
}
