/*
- partial_sum(first, last, b);
- partial_sum(first, last, b, myfun);

y0 = x0 
y1 = x0 + x1 
y2 = x0 + x1 + x2 
y3 = x0 + x1 + x2 + x3 
y4 = x0 + x1 + x2 + x3 + x4
*/

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int func(const int& x, const int& y)
{
	return x + y * 2;
}

int main()
{
	auto vec = vector<int>{1,2,3,4,5};
	auto vec2 = vector<int>(vec.size());
	cout<<"Default partial_sum function"<<endl;
	partial_sum(vec.begin(), vec.end(), vec2.begin());
	for_each(vec2.begin(), vec2.end(), [](const int& val) { cout<<val<<" ";});
	cout<<endl;

	cout<<"Partial_sum with user-defined function"<<endl;
	partial_sum(vec.begin(), vec.end(), vec2.begin(), func);
	for_each(vec2.begin(), vec2.end(), [](const int& val) { cout<<val<<" ";});
	cout<<endl;
	
	cout<<"Partial_sum with pre-defined function"<<endl;
	partial_sum(vec.begin(), vec.end(), vec2.begin(), std::minus<int>());
	for_each(vec2.begin(), vec2.end(), [](const int& val) { cout<<val<<" ";});
	cout<<endl;
	return 0;
}
