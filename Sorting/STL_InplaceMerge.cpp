#include"../Print.h"
#include<algorithm>
#include<numeric>

int main()
{
	vector<int> vec1(5);
	iota(vec1.begin(), vec1.end(), 5);

	vector<int> vec2(4);
	iota(vec2.begin(), vec2.end(), 4);

	vector<int> vec3;
	copy(vec1.begin(), vec1.end(), back_inserter(vec3));
	copy(vec2.begin(), vec2.end(), back_inserter(vec3));

	inplace_merge(vec3.begin(), vec3.begin() + 5, vec3.end());

	PrintVector(vec3);

	return 0;
}