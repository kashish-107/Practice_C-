/*
- Rearranges the list in such a way such that the element at the nth position is the one which should be at that position if we sort the list
- It does not sort the list, just that all the elements, which precede the nth element are not greater than it, and all the elements which succeed it are not less than it
- Return Value: Since, return type is void, so it doesnot return any value.
- It has two versions:
	1. Comparing elements using “<"
	2. By comparing using a pre-defined function
- Where can we apply std::nth_element() ?
	- first n smallest numbers, but they may or maynot be ordered
	- first n largest numbers, by just changing the Binary Function passed as argument in std::nth_element
	- find the median of the elements given
- Time Complexity of std::nth_element(): O(n), with n being the distance between first and the last.
*/

#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
	auto vec = vector<int>{2,1,3,4,5};
	nth_element(vec.begin(), vec.begin()+3, vec.end());

	for(auto& i:vec)
		cout<<i<<endl;

	cout<<"nth_Element with lambda function"<<endl;
	nth_element(vec.begin(), vec.begin()+3, vec.end(), [](int a, int b) { return a>b; });

	for(auto& i:vec)
		cout<<i<<endl;

	return 0;
}

