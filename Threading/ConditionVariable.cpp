#include<iostream>
#include<thread>
#include<mutex>
using namespace std;

mutex m;
condition_variable cv;
int balance = 0;

void addMoney(int iMoney) {
	lock_guard<mutex> lg(m);
	balance += iMoney;
	cout << "New balance " << balance << endl;
	cv.notify_one();
}

void withdrawMoney(int iMoney) {
	unique_lock<mutex> ul(m);
	cout << __FUNCTION__ << endl;
	cv.wait(ul, []() { return balance != 0; });
		balance -= iMoney;
		cout << "Remaning balance " << balance << endl;
}

int main() {
	thread t1(withdrawMoney, 200);
	thread t2(addMoney, 500);

	t1.join();
	t2.join();
	
	return 0;
}