/*
- lower_bound() method in C++ is used to return an iterator pointing to the first element in the range [first, last) which has a value not less than val
- If there are multiple values that are equal to val, lower_bound() returns the index of the first such value
- The elements in the range shall already be sorted or at least partitioned with respect to val
- Important - std::lower_bound() - works in O(logN) on Random Access Iterators, and O(N) on other iterators (ex. set)
	    - set:lower_bound() - has Bidirectional Iterator and cannot provide random access to its members. So unified std::lower_bound() works in O(N). 
				- specific for internal structure of std::set. It is implemented in method set::lower_bound(), which works in O(logN).
- Return Value: An iterator to the lower bound of val in the range. If all the elements in the range compare less than val, the function returns last. If all the elements in the range are larger than val, the function returns a pointer to the first element.
- Time complexity: O(logN)
*/

#include<iostream>
#include<algorithm>

int main()
{
	auto vec = std::vector<int>{1,2,3,4,5,7};
	
	std::cout<<"Vector contains\n";
	for_each(vec.begin(), vec.end(), [](int val) { std::cout<<val<<" "; });		
	
	std::cout<<"\nElement 3 exist: "<<*std::lower_bound(begin(vec), end(vec), 2);
	std::cout<<"\nElement 6 does exist- Return iterator to next greator element: "<<*(std::lower_bound(begin(vec), end(vec), 6))<<"\n";

	return 0;
}
