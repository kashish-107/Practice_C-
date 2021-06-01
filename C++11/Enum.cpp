/*
* Use enum when we are dealing with some limited set of values
1. Enum 
	- Full scope where it is declared
	- Duplicates are not allowed
	- can compare enum type with integer
	- can compare value of 2 different enums
2. Enum Class 
	- No problem with scope -  We can not access value without enum classname 
	- Can create duplicates with enum class
	- Con not compare enum type with integer
	- Can't compare value of 2 different enums
*/

#include<iostream>
using namespace std;

enum color1 {red, green, blue};
//enum color {red, green, blue, alpha};    //Error redefinition
//int red = 10;						     //Error redefinition

enum class color2 {red1, green1, blue1};
//int red1 = 5;                            //No error with enum class

void fun(int i)
{
	switch (i)
	{
	case red:   cout << "Red"     << endl; break;
	case green: cout << "Green"   << endl; break;
	case blue:  cout << "blue"    << endl; break;
	default:    cout << "Default" << endl; break;
	}
}

//void fun1(int i)   // Doesn't work with g++
void fun1(color2 i)
{
	switch (i)
	{
	case color2::red1:   cout << "Red1"     << endl; break;
	case color2::green1: cout << "Green1"   << endl; break;
	case color2::blue1:  cout << "blue1"    << endl; break;
	default:             cout << "Default"  << endl; break;
	}
}

int main() {
	cout << sizeof(color2) << endl;
	fun(2);
	//fun1(1); //Error - Doesn't work with g++
	fun1(color2::red1);
	return 0;
}
