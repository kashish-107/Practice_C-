/*
Notes:
1. lvalue - An object that occupies some identifiable location in memmory
		  - Can get address of object and assign it to pointer (Address is identifiable)
		  - lvalue can be used to create ravlue --> int i = 1; int x = i + 2;

2. rvalue - Any object that is not a lvalue
		  - Does not have any identifiable address
		  - Temporary, don't exist after one line
		  - rvalue can be modifiable - in case of userdefined datatype

3. lvalue reference - const lvalue reference can be assigned to a rvalue (const int& cr = 10;).
					  Shortcut of 2 steps operation - a) lvalue is created first b) reference is init with lvalue.
					- lvalue can be assigned to lvalue reference
					- can return lvalue from functions

4. rvalue reference - int&& r = 10;
*/

#include<iostream>
using namespace std;

class abc {
	int i;
public:
	abc(int i=0):i{i}{
	}
	void addOne() {
		cout << i + 1 << endl;
	}
};

int sum(int i, int j)
{
	return i + j;
}

int square(int& s)
{
	return s * s;
}

//Workaround to get ravlue as argument
int square(const int& s)
{
	return s * s;
}

int myGlobal;
int& fun()
{
	return myGlobal; //return lvalue
}

int main()
{
	int i;              //i is lvalue, can get address of i assign it to pointer
	int* p = &i;

	int j = i + 2;      //j is lvalue and i+2 is rvalue
	//int* p1 = &(i + 2); //Error - i+2 is rvalue
	//2 = i;              //Error

	int x = sum(3, 4);  //x is lvalue & sum() is rvalue;

	//Reference (or lvalue reference)
	int ii;
	int& r = ii;        //lvalue reference
	//int& r1 = 10;        //Error


	const int& cr = 10; //Works

	int side = 10;
	square(side);  //Works - side is lvalue
	square(20);    //Error - 20 is rvalue

	//Function returning lvalue
	fun() = 50;

	abc(2); //ravlue

	abc obj = abc(4); //obj is lvalue but abc(4) is rvalue (temporary object) 

	//rvalue can be modifiable - in case of userdefined data type
	abc(5).addOne();

	int&& rv = 90;
	cout << ++rv << endl;

	return 0;
}
