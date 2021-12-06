#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	auto names = vector<string>{"xyzz", "abc"};
	auto desc_func = [](const string& a, const string& b) {
				return a.size()>b.size();
			};
	sort(names.begin(), names.end(), desc_func);

	for(auto& i:names)
		cout<<i<<endl;
	
	return 0;
}
