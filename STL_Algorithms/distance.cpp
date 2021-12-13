/*
- Find the total no. of elements between the two iterators
- Returns: The number of elements between first and last.
- Time Complexity: Constant for random-access iterators and O(n) for all other iterators.
*/

#include<iostream>
#include<algorithm>

using namespace std;
int main()
{
	auto vec = vector<int>{1,2,3,4,5};
	cout<<"No. of elements: "<<distance(vec.begin(), vec.end())<<endl;
	cout<<"Calculating in reverse order: "<<distance(vec.end(), vec.begin())<<endl;
	return 0;
}
