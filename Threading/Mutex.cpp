#include<iostream>
#include<thread>
#include<mutex>
using namespace std;

int value = 0;
mutex m;
mutex m2;

int count1 = 0;

void add() {
	m.lock();
	++value;
	m.unlock();
}

void increment() {
	for (int i = 0; i < 100000; i++)
	{
		if (m2.try_lock()) {
			++count1;
			m2.unlock();
		}
	}
}

int main()
{
	thread t1(add);
	thread t2(add);

	thread t3(increment);
	thread t4(increment);

	t1.join();
	t2.join();
	t3.join();
	t4.join();

	cout << value << endl;
	cout << count1 << endl;

	return 0;
}
