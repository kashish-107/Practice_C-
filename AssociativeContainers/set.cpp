/*
- No duplicates
- Insertion, removal, search = O(logn)

*/

#include<iostream>
#include<set>

using namespace std;

int main()
{
	auto st = set<int>{2,1,5,4,3};
	st.insert(2);
	for(auto& i:st)
		cout<<i<<endl;
	return 0;
}

