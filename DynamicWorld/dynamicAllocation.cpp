/*
1. Delete should be used with New
2. Free() should be used with malloc
3. Delete & Free() both can be used with NULL pointer
4. New operator calls constructor, Malloc doesn't
5. Delete operator calls destructor, Free doesn't. So, free() should not be used for deallocating memory allocated using New
6. Use delete[] to release block of memory (dynamically allocated array)
7. New returns exact data type, while malloc return void*
8. On failure malloc return NULL whereass "new" throws std::bad_alloc exception, unless nothrow is used with new operator
9. Using nothrow with new returns a NULL pointer.
*/


#include<iostream>
#include<stdlib.h>
using namespace std;

#define BIG_NUMBER 100000000000000000000

class Toy
{
public:
	Toy() {
		cout<<"Ctor Toy"<<endl;
	}

	~Toy() {
		cout<<"Dtor Toy"<<endl;
	}
};

int main()
{
	int *ptr1 = new int(10);
	int *ptr2 = (int*)malloc(sizeof(int));
	delete ptr1;
	free(ptr2);

	//delete ptr1;  //Double free error
	//free(ptr2);  
	
	//No issues with Null pointer
	int *ptr3 = NULL;
	free(ptr3);
	
	int *ptr4 = NULL;
	delete ptr4;


	Toy *pMallocToy = (Toy*)malloc(sizeof(Toy));
	free(pMallocToy);

	Toy *pNewToy = new(nothrow) Toy[BIG_NUMBER];                  //Ctor
	if(!pNewToy) cout<<"Memory allocation failed"<<endl;
	delete[] pNewToy;					      //Dtor

	Toy *pNewToy1 = NULL;
	try
	{
		pNewToy1 = new Toy[BIG_NUMBER];                          //Exception thrown program exit
	}
	catch(...)
	{
		cout<<"Exception throw"<<endl;
	}

	delete[] pNewToy1;					      //Dtor
	return 0;
}

