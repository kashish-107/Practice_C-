#include<iostream>
#include<atomic>
using namespace std;

class MySmartPointer
{
	int* data;
public:
	MySmartPointer(int *p=nullptr):data{p} {
	}
	int& operator *() {
		return *data;
	}
	~MySmartPointer() {
		delete data;
	}
};

/*
class refCount{
int count;
public:
refCount() : count(0){
}

void operator++()
{
count++;
}

void operator--()
{
count--;
}

~refCount(){
}
}

template<typename T>
class myOwnSharedPtr {
	public:
  myOwnSharedPtr(T* ptr){

		iptr = ptr;
	  ref_count = new refCount()
	  if(iptr)
		(*ref_count)++;
  }

  myOwnSharedPtr(myOwnSharedPtr<T>& p)
  {
	ref_count = p.ref_count;
	iptr = p.iptr;
	(*ref_count)++;
  }

  ~myOwnSharedPtr(){
	(*ref_count)--;
	if(!ref_count){
		delete iptr;
	  delete ref_Count;
	  }
  }
  private:
  T* iptr;
  refcount* ref_count;
};
*/

class MySmartSharedPointer
{
	int* data;
	static int refCount;
public:
	MySmartSharedPointer(int* p = nullptr) :data{ p } {
		refCount++;
		cout << "Param ctor" << refCount << endl;
	}

	MySmartSharedPointer(const MySmartSharedPointer& rhs)
	{
		data = rhs.data;
		refCount++;
		cout << refCount << endl;
	}

	int& operator *() {
		return *data;
	}

	~MySmartSharedPointer() {
		refCount--;
			cout << refCount << endl;
		if(refCount == 0)
		 delete data;
	}
};

int MySmartSharedPointer::refCount;

int main()
{
	int* i = new int(10);
	MySmartPointer smartObj = MySmartPointer(i);
	cout << *smartObj << endl;

	MySmartSharedPointer p(new int(19));
	MySmartSharedPointer(new int(89));

	return 0;
}
