#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
	vector<int> vec={1,2,1,2,3,4,3,4};
	sort(vec.begin(), vec.end());
	//Unique works with sorted containers
	vector<int>::iterator it = unique(begin(vec), end(vec));
	cout<<vec.size()<<endl;	
	
	vec.erase(it, vec.end());
	cout<<vec.size()<<endl;	
	return 0;
}
