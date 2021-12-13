/*
- function returns the sum of all the values lying in a range
- accumulate(first, last, sum)
- accumulate(first, last, sum, myfun); 
	- sum :  initial value of the sum
- return val - sum of given range
*/

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

auto func = [](const int& x, const int& y) {
	return x*y;
};

int main()
{
	int sum{0};
	auto vec = vector<int>{1,2,3,4,5};
	
	cout<<"Simple accumulate function"<<endl;
	cout<<"Total= "<<accumulate(vec.begin(), vec.end(), sum)<<endl;

	cout<<"Accumulate function with pre-defined function"<<endl;
	cout<<"Total= "<<accumulate(vec.begin(), vec.end(), sum, std::minus<int>{})<<endl;

	cout<<"Accumulate function with user-defined function"<<endl;
	sum=1;
	cout<<"Product of adjacent element= "<<accumulate(vec.begin(), vec.end(), sum, func)<<endl;

	return 0;
}
