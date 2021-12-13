/*
- Fills default values in container
- Linear in n: Assigns a value to each element.
*/

#include<iostream>
#include<algorithm>

using namespace std;

void printVec(const vector<int>& vec)
{
	for(auto i:vec)
		cout<<i<<" ";
	cout<<endl;
}

int main()
{
	vector<int> vec = {1,2,3,4,5};
	fill_n(vec.begin()+2, 3, 7);
	printVec(vec);

	return 0;
}
