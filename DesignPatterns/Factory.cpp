/*
1. FDP is also known as "Virtual Constructor"
	- In C++ we don't have Virtual Ctor why?
		To call Virtual function we need objects. 
*/

#include <iostream>
#include <memory>
using namespace std;

enum class ToyData { Car, Bike };

class Toy {
protected:
	int data;
public:
	virtual void showProduct() const = 0;
	virtual ~Toy() {
	};
};

class Car :public Toy {
public:
	Car() {
		cout << __FUNCTION__ << endl;
	}

	void showProduct() const override {
		cout << "Car" << endl;
	}

	~Car() {
		cout << "Car dtor" << endl;
	}
};

class Bike :public Toy {
public:
	Bike() {
		cout << __FUNCTION__ << endl;
	}
	void showProduct() const override {
		cout << "Bike" << endl;
	}
	~Bike() {
		cout << "Bike dtor" << endl;
	}

};

class ToyFactory {
public:
	static unique_ptr<Toy> createToy(ToyData iType) {
		unique_ptr<Toy> obj = nullptr;
		if (iType == ToyData::Car)
			obj = make_unique<Car>();
		else if (iType == ToyData::Bike)
			obj = make_unique<Bike>();
		
		return obj;
	}
};

//Client
int main() { 
	unique_ptr<Toy> pCar = ToyFactory::createToy(ToyData::Car);
	if (pCar) pCar->showProduct();

	unique_ptr<Toy> pBike = ToyFactory::createToy(ToyData::Bike);
	if (pBike) pBike->showProduct();
	return 0;
}

