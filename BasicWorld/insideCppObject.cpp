/*
- Size of below class will be 4 because all methods are a separate entity which operates on the object by using implicit this pointer.
*/
#include<iostream>
using namespace std;

class thing 
{
public:
	void show() { cout<<i<<endl; }
private:
	int i=10; 
};

/* Compiler treat it like
class thing
{
 int i=0;
};

void thing::show(thing* this)
{
	std::cout.operator<<(this->i).operator<<(std::endl);
}
*/

int main()
{
	thing t;
	t.show();
	return 0;
}
