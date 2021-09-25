#include"../HelperHeaders/Print.h"
#include<algorithm>
#include<numeric>

int main()
{
	vector<int> vec(10);
	iota(vec.begin(), vec.end(), 10);
	random_shuffle(vec.begin(), vec.end());
	PrintVector(vec);

	sort_heap(vec.begin(), vec.end());
	PrintVector(vec);

	return 0;
}
