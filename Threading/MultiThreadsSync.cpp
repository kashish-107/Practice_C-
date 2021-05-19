#include<iostream>
#include<thread>
#include<mutex>

using namespace std;

mutex m;
condition_variable cv1;
condition_variable cv2;
condition_variable cv3;

bool toStart1 = true;
bool toStart2 = false;
bool toStart3 = false;

void thread1()
{
	int i = 100;
	while (i--) 
	{
		unique_lock<mutex> ul(m);
		//cv1.wait(ul, []() {return toStart1; });
		cv1.wait(ul);
		toStart1 = false;
		toStart2 = true;
		cout << "Thread 1" << endl;
		ul.unlock();
		//cv1.notify_all();
		//cv2.notify_one();
	}
}

void thread2()
{
	int i = 100;
	while (i--) {
		unique_lock<mutex> ul(m);
		//cv1.wait(ul, []() {return toStart2; });
		cv2.wait(ul);
		toStart2 = false;
		toStart3 = true;
		cout << "Thread 2" << endl;
		ul.unlock();
		//cv1.notify_all();
		cv3.notify_one();
	}
}

void thread3()
{
	cv1.notify_one();
	int i = 100;
	while (i--) {
		unique_lock<mutex> ul(m);
		//cv1.wait(ul, []() {return toStart3; });
		cv3.wait(ul);
		toStart3 = false;
		toStart1 = true;
		cout << "Thread 3" << endl;
		ul.unlock();
		//cv1.notify_all();
		cv1.notify_one();
	}
}

int main()
{
	thread t1(thread1);
	//thread t2(thread2);
	//thread t3(thread3);

	

	t1.join();
	//t2.join();
	//t3.join();

	return 0;
}