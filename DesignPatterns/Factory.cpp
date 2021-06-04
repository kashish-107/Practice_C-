/*
1. FDP is also known as "Virtual Constructor"
	- In C++ we don't have Virtual Ctor why?
		To call Virtual function we need objects. 
*/

#include <iostream>
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
	Car() = default;

	void showProduct() const override {
		cout << "Car" << endl;
	}

	~Car() {
		cout << "Car dtor" << endl;
	}
};

class Bike :public Toy {
public:
	Bike() = default;
	void showProduct() const override {
		cout << "Bike" << endl;
	}
	~Bike() {
		cout << "Bike dtor" << endl;
	}

};

class ToyFactory {
public:
	static Toy* createToy(ToyData iType) {
		Toy* obj = nullptr;
		if (iType == ToyData::Car)
			obj = new Car();
		else if (iType == ToyData::Bike)
			obj = new Bike();
		
		return obj;
	}
};

//Client
int main() { 
	Toy* pCar = ToyFactory::createToy(ToyData::Car);
	if(pCar) pCar->showProduct();
	delete pCar;

	Toy* pBike = ToyFactory::createToy(ToyData::Bike);
	if (pBike) pBike->showProduct();
	delete pBike;

	return 0;
}

