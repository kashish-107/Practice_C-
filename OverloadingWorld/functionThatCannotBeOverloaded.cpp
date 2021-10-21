/*
1. Function declarations that differ only in the return type
2. Parameter declarations that differ only in a pointer * versus an array [] are equivalent
3. Two parameter declarations that differ only in their default arguments are equivalent
4. Member function declarations with the same name and the name parameter-type-list cannot be overloaded if any of them is a static member function declaration
5. Parameter declarations that differ only in that one is a function type and the other is a pointer to the same function type are equivalent.
6. Parameter declarations that differ only in the presence or absence of const and/or volatile are equivalent. That is, the const and volatile type-specifiers for each parameter type are ignored when determining which function is being declared, defined, or called
7. main() function can't be overloaded.
*/

#include<iostream>
using namespace std;


//1
int fun(int a) { return 1; }
char fun(int a) { return 'a'; }

//2
void arrFun(int a[]) {}
void arrFun(int *a) {} //redeclaration of arrFun(int *ptr)

//3
void defaultArgFun(int x, int y) {}
void defaultArgFun(int x, int y=7) {}

//4
class test
{
public:
	static void staticFun() {}
	void staticFun() {}
};

//5
void h(int ()) {}
void h(int (*)()) {} //redeclaration of h(int())

//6
int f ( int x) { return x+10; }
  
int f ( const int x) { return x+10; }


int main()
{
//	fun(1);
}
