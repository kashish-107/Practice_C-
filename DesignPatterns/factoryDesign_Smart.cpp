#include<iostream>
#include<memory>
using namespace std;

enum ToyType { 
	TT_Car, TT_Bike 
};

class Toy
{
	public:
	virtual void printToy() = 0;
	static unique_ptr<Toy> createToy(ToyType iType);
	virtual ~Toy() {
		cout<<"Toy destroyed"<<endl;
	}
};

class Car : public Toy
{
	public:
	void printToy() override {
		cout<<"I am a Car"<<endl;
	}
	
	~Car()
	{
		cout<<"Car destroyed"<<endl;
	}
};

class Bike : public Toy
{
	public:
	void printToy() override {
		cout<<"I am a Bike"<<endl;
	}

	~Bike()
	{
		cout<<"Bike destroyed"<<endl;
	}
};

unique_ptr<Toy> Toy::createToy(ToyType iType)
{
	if(iType == TT_Car) return make_unique<Car>();
	else if(iType == TT_Bike) return make_unique<Bike>();
	else return NULL;
}


class Client
{
public:
	
	Client(ToyType iType)
	{
		pToy = Toy::createToy(iType);
	}

	unique_ptr<Toy> getToy()
	{
		return move(pToy);
	}

	~Client()
	{
		cout<<"Dtor Client"<<endl;
	}

private:
	unique_ptr<Toy> pToy;
};

int main()
{
	ToyType toyToCreate = TT_Car;
	unique_ptr<Toy> toyObj =  Toy::createToy(toyToCreate);
	toyObj->printToy();

	toyToCreate = TT_Bike;
	toyObj = Toy::createToy(toyToCreate);	
	toyObj->printToy();

	unique_ptr<Client> c = make_unique<Client>(toyToCreate);
	unique_ptr<Toy> pToy = c->getToy();
	pToy->printToy();
	return 0;
}
