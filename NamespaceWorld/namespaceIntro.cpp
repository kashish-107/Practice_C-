/*
Namespaces allow us to group named entities that otherwise would have global scope into narrower scopes, giving them namespace scope. This allows organizing the elements of programs into different logical scopes referred to by names.
*/

#include<iostream>
#include"foo.h"
using namespace std;
using namespace foo;

namespace mySpace {
	int value =100;
}

namespace mySpace {
	int value1 = 300;
	int fun() {
		return 107;
	}
}

using namespace mySpace;

// Nested namespace
namespace out
{
  int val = 5; 
  namespace in
  {
      int val2 = val;    
  }
}

namespace name1 
{
    namespace name2 
    {
         namespace name3 
         {
             int var = 42;
         }
    }
}
  
// Aliasing 
namespace alias = name1::name2::name3;

int main()
{
	int value =200;
	cout<<"value: "<<value<<endl;
	cout<<"mySpace value: "<<mySpace::value<<endl;
	cout<<"mySpace value1: "<<mySpace::value1<<endl;

	cout<<"Nested namespace: "<<out::in::val2<<endl;
	cout<<"Aliasing var = "<<alias::var<<endl;
	cout<<"Header namespace = "<<foo::fooFun()<<endl;
	
	cout<<"Using directive foo = "<<fooFun()<<endl;
	cout<<"Using directive = "<<fun()<<endl;
	return 0;
}
