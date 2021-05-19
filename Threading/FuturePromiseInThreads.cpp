#include<iostream>
#include<Thread>
#include<mutex>
#include<future>

using namespace std;

typedef unsigned long long ull;

void findOddSum(promise<ull>& OddSum, ull start, ull end)
{
	ull result = 0;
	for (int i = 0; i < end; i++)
		if (i & 1) result += i;
	OddSum.set_value(result);
}

int main()
{
	ull start = 0, end = 1900000000;
	promise < ull > oddSum;
	future<ull> oddFuture = oddSum.get_future();

	thread t1(findOddSum, move(oddSum), start, end);
	cout << "Waiting for result" << endl;

	cout << "OddSum:" << oddFuture.get();

	t1.join();
	return 0;
}