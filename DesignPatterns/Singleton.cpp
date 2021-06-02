#include<iostream>
using namespace std;

class singleton {
public:
	static singleton* getInstance() {

		if (!_inst) {
			cout << "Create instance" << endl;
			_inst = new singleton();
		}
		cout << "Instance" << endl;
		return _inst;
	}
private:
	static singleton* _inst;
	singleton() = default;
};

singleton* singleton::_inst;

int main() {
	singleton* p = singleton::getInstance();
	singleton* p1 = singleton::getInstance();
	return 0;
}
