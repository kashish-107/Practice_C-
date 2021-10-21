/*
- C++ allows functions to be overloaded on the basis of const-ness of parameters only if the const parameter is a reference or a pointer.
- 
*/

#include<iostream>
using namespace std;

class constInFunOverloading
{
public:
        void fun() const {
                cout<<"Const fun"<<endl;
        }

        void fun() {
                cout<<"Non-const fun"<<endl;
        }
};

//The parameter ‘i’ is passed by value, so ‘i’ in fun() is a copy of ‘i’ in main(). Hence fun() cannot modify ‘i’ of main(). Therefore, it doesn’t matter whether ‘i’ is received as a const parameter or normal parameter
/*void fun(const int i)
{
    cout << "fun(const int) called ";
}
void fun(int i)
{
    cout << "fun(int ) called " ;
}*/

//When we pass by reference or pointer, we can modify the value referred or pointed, so we can have two versions of a function, one which can modify the referred or pointed value, other which can not.
void funPtr(char *a)
{
  cout <<"non-const fun() "<<a<<endl;
}
  
void funPtr(const char *a)
{
  cout <<"const fun()"<<a<<endl;
}

int main()
{

	constInFunOverloading obj;
        obj.fun();

        const constInFunOverloading* ptr = &obj;
        ptr->fun();

	funPtr("kashish");
	const char *ptrStr = "mittal";
	funPtr(ptrStr);
}
