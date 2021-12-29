/*
- Introduced in c++14
*/

#include<iostream>

using namespace std;

template<typename T>
constexpr T pi = 3.14;

int main()
{
	cout<<pi<float><<endl;
	cout<<pi<int><<endl;

	return 0;	
}
