/*
1. The inline specifier makes the declarations from the nested namespace appear exactly as if they had been declared in the enclosing namespace. This means it drags out the declaration (“var” in the below example) from a nested namespace to the containing namespace.
2. This property is transitive: if a namespace N contains an inline namespace M, which in turn contains an inline namespace O, then the members of O can be used as though they were members of M or N.
3. The inline namespace mechanism is intended to support library evolution by providing a mechanism that supports a form of versioning
*/
#include<iostream>
#include"version.h"

using namespace std;
using namespace version;

namespace ns1
{
   inline namespace ns2
   {
       int var = 10;
   }
}


//"using" to get the same effect as inline
namespace ns_1
{
    namespace ns_2
    {
        namespace ns_3
        {
            int var = 20;
        }
        using namespace ns_3;
    }
     
    using namespace ns_2;
}
 
int main()
{
 	cout<<V98::f()<<endl;;
 	cout<<V99::f()<<endl;;
 	cout<<f()<<endl;
	
	cout<<ns1::var<<endl;
    	cout<<ns_1::var<<endl;
	return 0;
}
