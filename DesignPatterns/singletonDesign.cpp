#include<iostream>
#include<memory>
using namespace std;

class singleton
{
public:
	static singleton* getInstance()
	{
		static singleton* _inst  = NULL;
		if(!_inst)
		{
			cout<<"Single Instance"<<endl;
			 _inst = new singleton();
		}
		return _inst;
	}

	void print()
	{
		cout<<"I am a singleton class"<<endl;
	}

private:
	singleton() = default;
	~singleton() =  default;
	singleton(singleton&) = delete;
	singleton& operator=(const singleton&) = delete;
};

int main()
{
	singleton* pInst = singleton::getInstance();
	singleton* pInst2 = singleton::getInstance();
	pInst->print();
	pInst2->print();
	return 0;
}
