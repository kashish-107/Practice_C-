#include<iostream>
#include<thread>
using namespace std;

void fun(int i)
{
	while (i-- > 0)
		cout << i << " ";
	cout << endl;
}

//Functors
class base
{
public:
	void operator() (int i) {
		while (i-- > 0)
			cout << i << " ";
		cout << endl;
	}
};

class base2 {
public:
	void run(int i) {
		while (i-- > 0)
			cout << i << " ";
		cout << endl;
	}

	static void run2(int i) {
		while (i-- > 0)
			cout << i << " ";
		cout << endl;
	}
};

int main()
{   
	//1. Function Pointer
	thread t1(fun, 10);
	

	//2. Lambda Function
	auto func2 = [](int i) {
		while (i-- > 0)
			cout << i << " ";
		cout << endl;
	};
	thread t2(func2, 20);
	/*
	  thread t2( [](int i) {
		while (i-- > 0)
			cout << i << " ";
		cout << endl; 
		}, 20);
	*/

	//3. Using Functors
	thread t3(base(), 15);

	//4. Using non-static member function
	base2 b;
	thread t4(&base2::run, &b, 18);

	//5. Using static member function
	thread t5(&base2::run2, 18);

	t1.join();
	t2.join();
	t3.join();
	t4.join();
	t5.join();

	return 0;
}
