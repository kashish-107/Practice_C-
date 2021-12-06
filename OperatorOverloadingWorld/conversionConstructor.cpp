#include<iostream>
using namespace std;

class Point
{
public:
	Point(int x) : x{x}, y{0} { }

	void show() {
		cout<<x<<","<<y<<endl;
	}
private:
	int x, y;
};

int main()
{
	Point pt1(10);
	pt1.show();
	
	pt1=30;
	pt1.show();

	return 0;
}
