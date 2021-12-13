/*
- Returns an iterator pointing to the first element in the range [first, last) that is greater than value
- Elements should be sorted/at least partitioned
- Return type : An iterator to the upper bound of val in the range. If all the element in the range compare less than val, the function returns last.
- 
*/

#include<iostream>
#include<algorithm>

using namespace std;
int main()
{
	vector<int> vec{1,2,3,4,5,7};
	
	cout<<"Elements are: "<<endl;
	for_each(vec.begin(), vec.end(), [](int val){ cout<<val<<" "; });
	
	cout<<"\nElement present: "<<*upper_bound(vec.begin(), vec.end(), 3);
	cout<<"\nElement not present: "<<*upper_bound(vec.begin(), vec.end(), 6);
	cout<<endl;
	return 0;
}
