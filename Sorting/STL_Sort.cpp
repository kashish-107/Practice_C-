#include"../Print.h"
#include"../Point.h"
#include<algorithm>

using namespace std;

bool Cmp(int x, int y)
{
	return x < y;
}

int main()
{
	vector<int> vec{ 2,4,7,8,9,4 };

	//Standard
	sort(vec.begin(), vec.end());
	PrintVector(vec);

	//With own Comparator function
	sort(vec.begin(), vec.end(), Cmp);
	PrintVector(vec);

	//User defined
	vector<Point> vecPoint{ {1.2f, 3.4f}, {5.2f, 4.6f} };
	sort(vecPoint.begin(), vecPoint.end(), greater<>());
    PrintVector(vecPoint);
	
	//Lamda function
	sort(vecPoint.begin(), vecPoint.end(), [](Point& p1, Point& p2) { return (p1.x + p1.y) < (p2.x + p2.y); });
	PrintVector(vecPoint);

	//Is_sorted
	is_sorted(vec.begin(), vec.end()) ? cout << "Sorted" : cout << "Not sorted";

	cout << endl;
	
	return 0;
}
