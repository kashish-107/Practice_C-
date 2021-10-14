/*
1. To control destruction of object we make destructor private
2. With destructor private, object creation on stack is not possible
3. Only dynamic allocation is possible (Our responsibility to delete the object. So, scmpilier doesn't bother)
4. Create friend function of a class to delete objects
5. Can't allocate array of objects using new[] with private destructor
	- It's because of exceptions, the array version of new[] has to go and call the destructor on elements that have been previously allocated when an exception propagates to ensure exception safety. The single element new does not need to do that. If allocation fails, it just fails, no need to destroy anything.
*/

#include<iostream>
using namespace std;

class LiveOnlyOnHeap
{
public:
	LiveOnlyOnHeap() {
		cout<<"Ctor"<<endl;
	}
	
	friend void ReleaseMemory(LiveOnlyOnHeap*);
private:
	~LiveOnlyOnHeap() {
		cout<<"Dtor"<<endl;
	}
};

void ReleaseMemory(LiveOnlyOnHeap* ptr)
{
	delete ptr;
}

class Test
{
public:
	
	Test() {
		cout<<"Ctor"<<endl;
		static int count = 0;
		++count;
		
		if(count == 4)
			throw 1;
	}

	~Test() {
		cout<<"Dtor"<<endl;
	}
};

int main()
{
	//LiveOnlyOnHeap stackObj;
	
	LiveOnlyOnHeap* heapObj = new(nothrow) LiveOnlyOnHeap;
	ReleaseMemory(heapObj);
	
	//LiveOnlyOnHeap* mallocObjArr = (LiveOnlyOnHeap*)malloc(sizeof(LiveOnlyOnHeap)*4);
	//LiveOnlyOnHeap* heapObjArr = new LiveOnlyOnHeap[5];
	//heapObjArr->ReleaseMemory();
	//delete[] heapObjArr;

	try {
		Test* testPtr = new Test[4];
	}
	catch(...)
	{
		cout<<"Exception thrown"<<endl;
	}
	return 0;
}
