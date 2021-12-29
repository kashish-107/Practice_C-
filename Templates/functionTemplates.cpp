/*
- We write a generic function that can be used for different data types.
*/

#include<iostream>

using namespace std;

template<typename T>
T increment(T x) {
	return x+1;
}

template<typename T>
T sum(T start, T end, T step) {
	T res=start;
	while((start+=step)<end) res+=start;
	return res;
}

int main()
{
	cout<<increment(1)<<endl;
	cout<<increment(1.2)<<endl;
	cout<<increment('a')<<endl;
	
	cout<<sum(1,10,1)<<endl;
	return 0;
}

