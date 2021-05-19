#include<iostream>
#include<thread>
#include<mutex>
#include<deque>

using namespace std;

deque<int> buffer;
condition_variable cv;
mutex m;

#define MAX_BUFFER_SIZE 20;

void producer(int iInput)
{
	while (iInput)
	{
		unique_lock<mutex> ulock(m);
		cv.wait(ulock, []() {return buffer.size() < MAX_BUFFER_SIZE; });
		cout << "producer " << iInput << endl;
		buffer.push_back(iInput);;
		iInput--;
		if (buffer.size() >= 20)
		{
			cout << "Buffer full" << endl;
			ulock.unlock();
			cv.notify_one();
		}
	}
}

void consumer()
{
	while (1) {
		unique_lock<mutex> ulock(m);
		 cv.wait(ulock, []() { return (!buffer.empty()); });
			cout << "consumer " << buffer.front() << endl;
			buffer.pop_front();
			if (buffer.empty())
			{
				ulock.unlock();
				cv.notify_one();
			}
	}
}


int main()
{
	thread t1(producer, 100);
	thread t2(consumer);

	t1.join();
	t2.join();

	return 0;
}
