#include<iostream>
#include<algorithm>

using namespace std;

class house
{
private:
	int _num_rooms{0};
public:
	house(int val):_num_rooms{val} { cout<<"Ctor"<<endl; }
	house(const house& other) {
		cout<<"Copy ctor"<<endl;
		_num_rooms=other._num_rooms;
	}

	auto operator=(const house& other) {
		cout<<"Copy assignment"<<endl;
		_num_rooms=other._num_rooms;
		return *this;
	}

	house(house&& other) {
		cout<<"Move ctor"<<endl;
		_num_rooms=other._num_rooms;
		other._num_rooms = 0;
	}

	auto operator=(house&& other) {
		cout<<"Move assignment"<<endl;
		_num_rooms=other._num_rooms;
		other._num_rooms = 0;
	}

	int getRooms() { return _num_rooms; }
};

int main()
{
	house h1{2};
	house h2{3};
	swap(h1,h2);
	house h3 = move(h1);
	cout<<h1.getRooms()<<endl;
	cout<<h2.getRooms()<<endl;

	return 0;
}
