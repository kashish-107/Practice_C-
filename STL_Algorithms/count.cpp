#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

auto equal_case_insensitive = [](const auto& val)
{
	return [&val](const string& str) {
		if(str.size() != val.size()) return false;

		auto eq_lower = [](char a, char b) {
			return tolower(a) == tolower(b);
		};
		return equal(str.begin(), str.end(), val.begin(), eq_lower);
	};
};

int main()
{
	auto names = vector<string>{"abc","xyz","ABC"};
	auto result = count_if(names.begin(), names.end(), equal_case_insensitive(string{"abc"}));
	cout<<result<<endl;
	
	return 0;
}
