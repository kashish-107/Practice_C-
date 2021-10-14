#include<iostream>
#include<stdio.h>
using namespace std;

#define NUM 10

//Not work with GCC compilers
//#pragma startup func1
//#pragma exit func2

void func1();
int func2();

//For GCC compiler
void __attribute__((constructor)) func1();
int __attribute__((destructor)) func2();

void func1()
{
	printf("func1\n");
	//cout<<"func1"<<endl; //Using cout gives segmentation fault
}

int func2()
{
	printf("func2");
}

int main()
{
	cout<<NUM<<endl;
	//#undef NUM
	//cout<<NUM<<endl;
	return 0;
}

