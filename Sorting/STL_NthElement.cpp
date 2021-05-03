#include"Print.h"
#include<algorithm>

int main()
{
	vector<int> vec{ 3,2,5,6,1,3,9,7,4,8 };
	nth_element(vec.begin(), vec.end()-5, vec.end());
	PrintVector(vec);

	//nth element in partial container
	nth_element(vec.begin(), vec.begin()+1 , vec.begin() + 4);
	PrintVector(vec);
}
