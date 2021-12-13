/*
- This function can be used if we want to use both std::lower_bound and std::upper_bound at the same time, as its first pointer will be same as std::lower_bound and its second pointer will be same as std::upper_bound
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	vector<int> vec = {3,5,7,7,7,9,10,10};
	
	pair<vector<int>::iterator, vector<int>::iterator> ip;
	
	ip = equal_range(vec.begin(), vec.end(), 10);
	
	cout<<*(ip.first)<<endl;
	cout<<*(ip.second)<<endl;

	ip = equal_range(vec.begin(), vec.end(), 11);
	cout<<*(ip.first)<<endl;
	cout<<*(ip.second)<<endl;
	return 0;		
}
