/*
Virtual functions are invoked when you have a pointer/reference to an instance of a class.
Static functions aren't tied to a particular instance, they're tied to a class. 
C++ doesn't have pointers-to-class, so there is no scenario in which you could invoke a static function virtually.
*/

#include<iostream>
using namespace std;

class base
{
public:
	static virtual void print() {
	}

	virtual ~base() {
	}
};


int main()
{
	return 0;
}
