#include<iostream>
#include<vector>
#include<algorithm>
#include<memory>
using namespace std;

class IObserver;

class subject {
	int subject_val;
	vector<weak_ptr<IObserver>> list;
	void notifyAll();
public:
	subject():subject(0){
	}
	subject(int i) :subject_val{ i } {
		cout << "Intial value of subject is" << subject_val << endl;
	}
	void attach(shared_ptr<IObserver> obs) {
		list.push_back(obs);
	}
	//void detach(const IObserver& obs) {
	//	list.erase(find(list.begin(), list.end(), obs));
	//}
	void setValue(const int iValue) {
		cout << __FUNCTION__ << endl;
		subject_val = iValue;
		notifyAll();
	}
	~subject() {
		cout << __FUNCTION__ << endl;
	}
};

class IObserver {
public:
	virtual void update(int) = 0;
	virtual ~IObserver() {
		cout << __FUNCTION__ << endl;
	}
};

void subject::notifyAll() {
	cout << __FUNCTION__ << endl;
	for (auto i : list) {
		auto sPtr = i.lock();
		if (sPtr)
			sPtr->update(subject_val);
		else
			cout << "Listener is dead" << endl;
	}
}

//Listeners
class A_IObserver :public IObserver {
private:
	 void update(int newVal) override {
		cout << "A_IObserver subject value is" << newVal << endl;
	}
public:
	~A_IObserver() {
		cout << __FUNCTION__ << endl;
	}
};

class B_IObserver :public IObserver {
	void update(int newVal) override {
		cout << "B_IObserver subject value is" << newVal << endl;
	}
public:
	
	~B_IObserver() {
		cout << __FUNCTION__ << endl;
	}
};

int main() {
	unique_ptr<subject> sub = make_unique<subject>(10);
	shared_ptr<IObserver> A_Obs = make_shared<A_IObserver>();
	shared_ptr<IObserver> B_Obs = make_shared<B_IObserver>();

	sub->attach(A_Obs);
	sub->attach(B_Obs);

//	auto var = B_Obs.get();
    B_Obs.reset();            

	cout << __FUNCTION__ << endl;
	sub->setValue(20);
	sub->setValue(30);
}
