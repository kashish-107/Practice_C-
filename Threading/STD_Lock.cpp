#include<iostream>
#include<thread>
#include<mutex>

using namespace std;

mutex m1;
mutex m2;

void thread1()
{
	lock(m1, m2);
		cout << __FUNCTION__ << endl;
		m2.unlock();
		m1.unlock();
}

void thread2()
{
	lock(m1, m2);
		cout << __FUNCTION__ << endl;
		m2.unlock();
		m1.unlock();
}

int main()
{
	thread t1(thread1);
	thread t2(thread2);

	cout << t1.get_id() << endl;

	t1.join();
	t2.join();

	cout << t1.get_id() << endl;

	return 0;
}