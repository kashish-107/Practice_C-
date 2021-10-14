nclude<iostream>
using namespace std;

enum ToyType { 
	TT_Car, TT_Bike 
};

class Toy
{
	public:
	virtual void printToy() = 0;
	static Toy* createToy(ToyType iType);
	virtual ~Toy() {
		cout<<"Toy destroyed"<<endl;
	}
};

class Car : public Toy
{
	public:
	void printToy() {
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
	void printToy() {
		cout<<"I am a Bike"<<endl;
	}

	~Bike()
	{
		cout<<"Bike destroyed"<<endl;
	}
};

Toy* Toy::createToy(ToyType iType)
{
	if(iType == TT_Car) return new Car();
	else if(iType == TT_Bike) return new Bike();
	else return NULL;
}


class Client
{
public:
	
	Client(ToyType iType)
	{
		pToy = Toy::createToy(iType);
	}

	Toy* getToy()
	{
		return pToy;
	}

	~Client()
	{
		cout<<"Dtor Client"<<endl;
		if(pToy) delete pToy;
	}

private:
	Toy* pToy;
};

int main()
{
	ToyType toyToCreate = TT_Car;
	Toy* toyObj =  Toy::createToy(toyToCreate);
	if(toyObj) 
	{
		toyObj->printToy();
		delete toyObj;
	}

	toyToCreate = TT_Bike;
	toyObj = Toy::createToy(toyToCreate);
	
	if(toyObj) 
	{
		toyObj->printToy();
		delete toyObj;
	}

	Client *c = new Client(toyToCreate);
	Toy* pToy = c->getToy();
	pToy->printToy();
	delete c;
	return 0;
}
