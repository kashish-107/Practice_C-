#include<iostream>
#include<thread>
#include<mutex>

using namespace std;

int X = 0, Y = 0;
mutex m1, m2;

void incrementXY(int& XorY, mutex& m, const char* str)
{
	for (int i = 0; i < 5; i++) {
		m.lock();
		++XorY;
		cout << str << XorY << endl;
		m.unlock();
		this_thread::sleep_for(chrono::seconds(10));
	}
}

void consumer() {
	int useCount = 5;
	int XplusY = 0;
	while (1) {
		int lockResult = try_lock(m1, m2);
		if (lockResult == -1)
		{
			if (X && Y) {
				useCount--;
				XplusY += X + Y;
				X = 0;
				Y = 0;
				cout << "XplusY" << XplusY << endl;
			}
			m1.unlock();
			m2.unlock();
			if (useCount == 0) break;
		}
	}
}

int main()
{
	thread t1(incrementXY, std::ref(X), std::ref(m1), "X ");
	thread t2(incrementXY, std::ref(Y), std::ref(m2), "Y ");
	thread t3(consumer);

	t1.join();
	t2.join();
	t3.join();
	return 0;
}