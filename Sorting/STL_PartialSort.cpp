#include"..\Print.h"
#include<algorithm>

bool ownGreaterCmp(int x, int y)
{
	return x > y;
}

int main()
{
	vector<int> vec{ 3,6,4,8,2,6 };
	partial_sort(vec.begin(), vec.begin() + 4, vec.end());
	PrintVector(vec);

	//Using own comparator 
	partial_sort(vec.begin(), vec.begin() + 4, vec.end(), ownGreaterCmp);
	PrintVector(vec);

	auto lambda = [](int x, int y) { return x < y; };
	//Using Lambda
	partial_sort(vec.begin(), vec.begin() + 4, vec.end(), lambda);
	PrintVector(vec);

	//Is_sorted
	is_sorted(vec.begin(), vec.begin()) ? cout << "Sorted" : cout << "Not sorted";
	cout << endl;

	is_sorted(vec.begin(), vec.begin() + 4) ? cout << "Sorted" : cout << "Not sorted";
	cout << endl;

	return 0;
}
