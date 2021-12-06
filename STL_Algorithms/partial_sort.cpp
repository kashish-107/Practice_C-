#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
	vector<int> vec{2,3,1,4,5,3};
	partial_sort(vec.begin(), vec.begin()+3, vec.end());
	
	for(auto& i:vec)
		cout<<i<<endl;

	return 0;
}

