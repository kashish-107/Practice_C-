#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	vector<int> vec = {1,2,1,3,4,1};
	auto new_end = remove(begin(vec), end(vec), 1);
	cout<<vec.size()<<endl;
	vec.erase(new_end, vec.end());
	cout<<vec.size()<<endl;
	return 0;
}
