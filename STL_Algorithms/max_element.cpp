/*
- std::max_element uses operator<
*/
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class tower
{
public:
	tower(int h):_height{h} { }
	auto operator<(const tower& other) {
		return _height<other._height;
	}
	auto getHeight() {
		return _height;
	}
private:
	int _height{-1};
};

int main()
{
	auto tower_vec = vector<tower>{tower{1}, tower{3}, tower{2}};
	auto it = max_element(tower_vec.begin(), tower_vec.end());
	if(it != tower_vec.end()) cout<<it->getHeight()<<endl;
	else cout<<"Empty"<<endl;

	return 0;
}
