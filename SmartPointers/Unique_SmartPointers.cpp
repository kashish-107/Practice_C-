#include<iostream>
#include<memory>

using namespace std;

class abc {
	int x;
public:
	abc(int x):x{x} {
	}

	int getX() { 
		return x; 
	}

	~abc() {
		cout << "abc dtor"<<endl;
	}
};

class Product {
public:
	void print() {
		cout << __FUNCTION__ << endl;
	}
	~Product() {
		cout << __FUNCTION__ << endl;
	}
};

auto cusDeleter = [](Product* iProd) {
	cout << "I am a custom deleter" << endl;
	delete iProd;
};

class Factory {
public:
	static unique_ptr<Product, decltype(cusDeleter)> createProduct() {
		cout << __FUNCTION__ << endl;
		unique_ptr<Product, decltype(cusDeleter)>iProd(new Product,cusDeleter);
		return iProd;
	}
};

int main()
{
	unique_ptr<abc> p(new abc(15));
	unique_ptr<abc> p2 = make_unique<abc>(34);

	//p = p2;		//Fail : We can not copy ownership
	//p2 = move(p); //p with point to nullptr

	//Move
	unique_ptr<abc> p3 = move(p);
	//cout << p->getX() << endl; //p with point to nullptr
	cout << p3->getX() << endl;
	cout << (*p2).getX() << endl;

	//Get
	abc* ptr = p3.get();
	cout << p3->getX() << endl;

	//Release
	abc* ptr1 = p3.release(); //p3 will point to nullptr
	//cout << p3->getX() << endl;
	delete ptr1;

	//Reset
	abc* test = new abc(78);
	p2.reset(test); //Will delete the current holding object
	//cout << p2->getX();

	//unique_ptr<Product> pProd = Factory::createProduct();
	auto pProd = Factory::createProduct();
	return 0;
}
