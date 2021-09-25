#include<iostream>
using namespace std;

int main()
{
	const int i = 10;
	const int* p = &i;
	int* temp = const_cast<int*>(p);
	*temp = 19; //error
	int j = 10;
	cout << i << " " << *temp << endl;
	return 0;
}
