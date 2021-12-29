/*
- Alias templates allow you to create synonyms for templates
- Can help to abstract small type difference for different products
*/

#include<iostream>
#include<array>

using namespace std;

template<size_t N> //NTTP
using CharArray =
#ifdef PRODUCT_A 
	array<char, N>;
#else
	array<char, 10>; 
#endif
	
int main()
{
	CharArray<10> ar{};
	return 0;
}

