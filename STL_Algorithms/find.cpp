/*
- std::find uses operator==
- std::find_if uses custom comparator function
*/
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class flower
{
public:
	flower(int h):_height{h} { }
	auto operator==(const flower& f) {
		return _height==f._height;
	}
	auto getHeight() {
		return _height;
	}
private:
	int _height{0};
};

int main()
{
	auto vec_flower= vector<flower>{flower{2}, flower{3}, flower{4}};
	auto it = find(begin(vec_flower), end(vec_flower), flower{5});
	if(it != vec_flower.end())
		cout<<it->getHeight()<<endl;
	else
		cout<<"not found!"<<endl;

	auto it2 = *find(begin(vec_flower), end(vec_flower), flower{5});
	cout<<it2.getHeight()<<endl;

	auto names = vector<string>{"abc", "xyzz"};
	auto result = find_if(names.begin(), names.end(), [](const auto& val) { return val.size() == 3; });
	cout<<*result<<endl; 
	
	return 0;
}
