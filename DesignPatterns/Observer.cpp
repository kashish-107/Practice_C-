#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class subject {
	int subject_val;
	vector<class observer*> list;
	void notifyAll();
public:
	subject():subject(0){}
	subject(int i) :subject_val{ i } {
		cout << "Intial value of subject is" << subject_val << endl;
	}
	void attach(observer*);
	void detach(observer* obs) {
		
		list.erase(find(list.begin(), list.end(), obs));
	}
	void setValue(const int);

	~subject() {
		cout << __FUNCTION__ << endl;
	}

};

void subject::attach(observer* obs){
	list.push_back(obs);
}

void subject::setValue(const int iValue) {
	subject_val = iValue;
	notifyAll();
}


class observer {
	subject* pSubject;
public:
	observer(subject* iSub) {
		pSubject = iSub;
		pSubject->attach(this);
	}
	virtual void update(int) = 0;
	virtual ~observer() {
		pSubject->detach(this);
		cout << __FUNCTION__ << endl;
	}
};

void subject::notifyAll() {
	for (auto i : list)
		i->update(subject_val);
}

class A_observer :public observer {
	void update(int) override;
public:
	A_observer(subject*);

	~A_observer() {
		cout << __FUNCTION__ << endl;
	}
};

A_observer::A_observer(subject* sub) : observer{ sub } {
}
void A_observer::update(int newVal) {
	cout << "A_observer subject value is" << newVal << endl;
}

class B_observer :public observer {
	void update(int) override;
public:
	B_observer(subject*);
	
	~B_observer() {
		cout << __FUNCTION__ << endl;
	}
};

void B_observer::update(int newVal) {
	cout << "B_observer subject value is" << newVal << endl;
}

B_observer::B_observer(subject* sub) : observer{ sub } {
}

int main() {
	subject* sub = new subject(10);
	observer* A_Obs = new A_observer(sub);
	observer* B_Obs = new B_observer(sub);

	sub->setValue(20);
	delete B_Obs;

	//B_Obs.detach();
	sub->setValue(30);

	delete A_Obs;
	
	delete sub;
}
