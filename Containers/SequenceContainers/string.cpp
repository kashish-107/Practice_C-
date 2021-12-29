/*
- std::string is a typedef for std::basic_string<char>
- utilize something called small-size optimization, which means that they do not allocate any dynamic memory if the size of the string is small
*/

#include<iostream>
#include<string>

using namespace std;

int main()
{
	auto str = string{"ABC"};
	cout<<str<<endl;
	
	return 0;
}
